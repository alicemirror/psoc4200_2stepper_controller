/*******************************************************************************
* File Name: SCB_1_I2C_INT.c
* Version 1.0
*
* Description:
*
*
********************************************************************************
* Copyright 2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "SCB_1_I2C_PVT.h"


/*******************************************************************************
* Function Name: SCB_1_ISR
********************************************************************************
*
* Summary:
*  Handle Interrupt Service Routine.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
CY_ISR(SCB_1_I2C_ISR)
{
    uint32 diffCount;
    uint32 endTransfer;
    
    #if(SCB_1_I2C_ACCEPT_ADDR_CONST)
        uint32 address;   
    #endif /*SCB_1_I2C_ACCEPT_ADDR_CONST */
    
    endTransfer = 0u; /* No END of TRANSFER on interrupt entry */

    /* Call customer routine if registered */
    if(NULL != SCB_1_customIntrHandler)
    {
        SCB_1_customIntrHandler();
    }


    #if(SCB_1_I2C_SLAVE)
    {
        /* INTR_SLAVE_I2C_BUS_ERROR */
        /* Unexpected Start or Stop condition was occurred on the bus: set flag to notify error condition.
        */
        if(SCB_1_CHECK_INTR_SLAVE_MASKED(SCB_1_INTR_SLAVE_I2C_BUS_ERROR))
        {
            if(SCB_1_CHECK_I2C_FSM_RD)
            {
                 /* TX direction: master reads from slave */
                SCB_1_slStatus &= ~SCB_1_I2C_SSTAT_RD_BUSY;
                SCB_1_slStatus |=  SCB_1_I2C_SSTAT_RD_ERR;
            }
            else
            {
                /* RX direction: master writes into slave */
                SCB_1_slStatus &= ~SCB_1_I2C_SSTAT_WR_BUSY;
                SCB_1_slStatus |=  SCB_1_I2C_SSTAT_WR_ERR;
            }
            
            SCB_1_state = SCB_1_I2C_FSM_EXIT_IDLE;
        }
    }
    #endif

    #if(SCB_1_I2C_MASTER)
    {
        /* INTR_MASTER_I2C_BUS_ERROR */
        /* Unexpected Start or Stop condition was occurred on the bus: complete transaction.
         * The interrupt is cleared by in the I2C_FSM_EXIT_IDLE state */
        if(SCB_1_CHECK_INTR_MASTER_MASKED(SCB_1_INTR_MASTER_I2C_BUS_ERROR))
        {
            SCB_1_mstrStatus |= (SCB_1_I2C_MSTAT_ERR_XFER |
                                            SCB_1_I2C_MSTAT_ERR_BUS_ERROR);

            endTransfer = SCB_1_CMPLT_ANY_TRANSFER;
        }


        #if(SCB_1_I2C_MULTI_MASTER)
        {
            /* INTR_MASTER_I2C_ARB_LOST */
            /* MultiMaster lost arbitrage while transaction: complete transaction or pass control the slave FSM.
             * The interrupt is cleared by in the I2C_FSM_EXIT_IDLE state OR before go to the slave FSM.
             */
            if(SCB_1_CHECK_INTR_MASTER_MASKED(SCB_1_INTR_MASTER_I2C_ARB_LOST))
            {
                SCB_1_mstrStatus |= (SCB_1_I2C_MSTAT_ERR_XFER |
                                                SCB_1_I2C_MSTAT_ERR_ARB_LOST);

                endTransfer = SCB_1_CMPLT_ANY_TRANSFER;
            }
        }
        #endif

        #if(SCB_1_I2C_MULTI_MASTER_SLAVE)
        {
            /* I2C_MASTER_CMD_M_START_ON_IDLE */
            /* MultiMaster-Slave does not generate start, because Slave was addressed earlier:
             * pass control the slave FSM.
             */
            if(SCB_1_CHECK_I2C_MASTER_CMD(SCB_1_I2C_MASTER_CMD_M_START_ON_IDLE))
            {
                SCB_1_I2C_MASTER_CLEAR_START;

                SCB_1_mstrStatus |= (SCB_1_I2C_MSTAT_ERR_XFER |
                                                SCB_1_I2C_MSTAT_ERR_START_ABORT);

                endTransfer = SCB_1_CMPLT_ANY_TRANSFER;
            }
        }
        #endif

        /* Error handling common part: set completion flag of transcation and pass control to
        *  I2C_FSM_EXIT_IDLE - to complete transcation OR
           I2C_FSM_IDLE      - to process incomming transcation as slave.
        */
        if(0u != endTransfer)
        {
            SCB_1_mstrStatus |= SCB_1_GET_I2C_MSTAT_CMPLT;
            SCB_1_state       = SCB_1_I2C_FSM_EXIT_IDLE;

            #if(SCB_1_I2C_MULTI_MASTER_SLAVE)
            {
                /* Pass control to the slave */
                if(SCB_1_CHECK_INTR_SLAVE_MASKED(SCB_1_INTR_SLAVE_I2C_ADDR_MATCH))
                {
                    SCB_1_ClearMasterInterruptSource(SCB_1_INTR_MASTER_ALL);

                    SCB_1_state = SCB_1_I2C_FSM_IDLE;
                }
            }
            #endif
        }

    } /* (SCB_1_I2C_MASTER) */
    #endif

    /* Any Master operation starts from: ADDR_RD/WR state as the master generates traffic on the bus
     * Any Slave operation starts from : IDLE state as slave always waiting actions from the master */


    /* FSM Master */
    if(SCB_1_CHECK_I2C_FSM_MASTER)
    {
        #if(SCB_1_I2C_MASTER)
        {
            /* INTR_MASTER_I2C_STOP */
            /* Stop condition was generated by the master: end of transction.
             * Set completion flags to notify API.
             */
            if(SCB_1_CHECK_INTR_MASTER_MASKED(SCB_1_INTR_MASTER_I2C_STOP))
            {
                SCB_1_ClearMasterInterruptSource(SCB_1_INTR_MASTER_I2C_STOP);

                SCB_1_mstrStatus |= SCB_1_GET_I2C_MSTAT_CMPLT;
                SCB_1_state       = SCB_1_I2C_FSM_IDLE;
            }
            else
            {
                if(SCB_1_CHECK_I2C_FSM_ADDR) /* Address stage */
                {
                    /* INTR_MASTER_I2C_NACK */
                    /* Master send address but it was NACKed by the slave: complete transaction
                     */
                    if(SCB_1_CHECK_INTR_MASTER_MASKED(SCB_1_INTR_MASTER_I2C_NACK))
                    {
                        SCB_1_ClearMasterInterruptSource(SCB_1_INTR_MASTER_I2C_NACK);

                        SCB_1_mstrStatus |= (SCB_1_I2C_MSTAT_ERR_XFER |
                                                        SCB_1_I2C_MSTAT_ERR_ADDR_NAK);

                        endTransfer = SCB_1_CMPLT_ANY_TRANSFER;
                    }
                    /* INTR_TX_UNDERFLOW */
                    /* The address byte was sent:
                     * TX direction: the clock is stretched after ACK phase, because TX FIFO is EMPTY. The TX EMPTY
                                     clean all TX interrupt sources.
                     * RX direction: the 1st byte is receiving, but there is no ACK permision, clock is
                                     stretched after 1 byte will be received.
                     */
                    else
                    {
                        if(SCB_1_CHECK_I2C_FSM_RD) /* Reading */
                        {
                            SCB_1_state = SCB_1_I2C_FSM_MSTR_RD_DATA;
                        }
                        else /* Writing */
                        {
                            SCB_1_state = SCB_1_I2C_FSM_MSTR_WR_DATA;
                            SCB_1_SetTxInterruptMode(SCB_1_INTR_TX_EMPTY);
                        }
                    }
                }

                if(SCB_1_CHECK_I2C_FSM_DATA) /* Data phase */
                {
                    if(SCB_1_CHECK_I2C_FSM_RD) /* Reading */
                    {
                        /* INTR_RX_FULL */
                        /* RX direction: master received 8 bytes, the 9th byte is receiving.
                         * Get data from RX FIFO and decide whether to ACK or NACK following bytes.
                         */
                        if(SCB_1_CHECK_INTR_RX_MASKED(SCB_1_INTR_RX_FULL))
                        {
                            /* Calculate difference */
                            diffCount =  SCB_1_mstrRdBufSize -
                                        (SCB_1_mstrRdBufIndex + SCB_1_GET_RX_FIFO_ENTRIES);

                            /* Proceed transaction or end it when RX FIFO become FULL again */
                            if(diffCount > SCB_1_FIFO_SIZE)
                            {
                                diffCount = SCB_1_FIFO_SIZE;
                            }
                            else
                            {
                                if(0u == diffCount)
                                {
                                    SCB_1_DISABLE_MASTER_AUTO_DATA_ACK;

                                    diffCount   = SCB_1_FIFO_SIZE;
                                    endTransfer = SCB_1_CMPLT_ANY_TRANSFER;
                                }
                            }

                            for(;(0u != diffCount);diffCount--)
                            {
                                SCB_1_mstrRdBufPtr[SCB_1_mstrRdBufIndex] = (uint8) SCB_1_RX_FIFO_RD_REG;
                                SCB_1_mstrRdBufIndex++;
                            }
                        }
                        /* INTR_RX_NOT_EMPTY */
                        /* RX direction: master received one data byte need to ACK or NACK. The last byte is stored
                         * and NACKed by the master. The NACK and Stop is generated by one command generate Stop.
                         */
                        else if(SCB_1_CHECK_INTR_RX_MASKED(SCB_1_INTR_RX_NOT_EMPTY))
                        {
                            /* Put data in the component buffer */
                            SCB_1_mstrRdBufPtr[SCB_1_mstrRdBufIndex] = (uint8) SCB_1_RX_FIFO_RD_REG;
                            SCB_1_mstrRdBufIndex++;

                            if(SCB_1_mstrRdBufIndex < SCB_1_mstrRdBufSize)
                            {
                                SCB_1_I2C_MASTER_GENERATE_ACK;
                            }
                            else
                            {
                               endTransfer = SCB_1_CMPLT_ANY_TRANSFER;
                            }
                        }
                        else
                        {
                            ; /* Does nothing */
                        }

                        SCB_1_ClearRxInterruptSource(SCB_1_INTR_RX_ALL);
                    }
                    else /* Writing */
                    {
                        /* INTR_MASTER_I2C_NACK */
                        /* Master writes data to the slave and NACK was received: not all bytes were written to the
                         * slave from TX FIFO. Revert index if there is data in TX FIFO and pass control to complete
                         * transfer.
                         */
                        if(SCB_1_CHECK_INTR_MASTER_MASKED(SCB_1_INTR_MASTER_I2C_NACK))
                        {
                            SCB_1_ClearMasterInterruptSource(SCB_1_INTR_MASTER_I2C_NACK);

                            /* Rollback the write buffer index: the NACKed bytes remains in the shifter */
                            SCB_1_mstrWrBufIndex -= (SCB_1_GET_TX_FIFO_ENTRIES +
                                                                SCB_1_GET_TX_FIFO_SR_VALID);

                            SCB_1_mstrStatus |= (SCB_1_I2C_MSTAT_ERR_XFER |
                                                            SCB_1_I2C_MSTAT_ERR_SHORT_XFER);

                            SCB_1_CLEAR_TX_FIFO;

                            endTransfer = SCB_1_CMPLT_ANY_TRANSFER;
                        }
                        /* INTR_TX_EMPTY */
                        /* TX direction: the TX FIFO is EMPTY, the data from buffer need be put there.
                         * When there is no data in the component buffer, underflow interrupt is enabled
                         * to catch when all data will be transfered */
                        else if(SCB_1_CHECK_INTR_TX_MASKED(SCB_1_INTR_TX_EMPTY))
                        {
                            while(SCB_1_FIFO_SIZE != SCB_1_GET_TX_FIFO_ENTRIES)
                            {
                                if(SCB_1_mstrWrBufIndex < SCB_1_mstrWrBufSize)
                                {
                                    /* Put data into TX FIFO */
                                    SCB_1_TX_FIFO_WR_REG = (uint32) SCB_1_mstrWrBufPtr[SCB_1_mstrWrBufIndex];
                                    SCB_1_mstrWrBufIndex++;
                                }
                                else
                                {
                                    break; /* No more data to put */
                                }
                            }

                            if(SCB_1_mstrWrBufIndex == SCB_1_mstrWrBufSize)
                            {
                                SCB_1_SetTxInterruptMode(SCB_1_INTR_TX_UNDERFLOW);
                            }

                            SCB_1_ClearTxInterruptSource(SCB_1_INTR_TX_ALL);
                        }
                        /* INTR_TX_UNDERFLOW */
                        /* TX direction: all data from TX FIFO was transfered to the slave. The transaction
                         * need to be completed.
                         */
                        else if(SCB_1_CHECK_INTR_TX_MASKED(SCB_1_INTR_TX_UNDERFLOW))
                        {
                            endTransfer = SCB_1_CMPLT_ANY_TRANSFER;
                        }
                        else
                        {
                            ; /* Does nothing */
                        }
                    }
                }

                if(0u != endTransfer) /* Complete transfer */
                {
                    /* Disable data processing interrupts: Them should be CLEARED */
                    SCB_1_SetRxInterruptMode(~SCB_1_INTR_RX_ALL);
                    SCB_1_SetTxInterruptMode(~SCB_1_INTR_TX_ALL);

                    if(SCB_1_CHECK_I2C_MODE_NO_STOP(SCB_1_mstrControl))
                    {
                        /* On-going transaction is suspend: the ReStart is generated by API request */
                        SCB_1_mstrStatus |= (SCB_1_I2C_MSTAT_XFER_HALT |
                                                        SCB_1_GET_I2C_MSTAT_CMPLT);

                        SCB_1_state = SCB_1_I2C_FSM_MSTR_HALT;
                    }
                    else
                    {
                        /* Complete transaction: exclude data processing state and generate Stop.
                         * The completion status will be set after Stop generation.
                         * Specail case is read: because NACK and Stop is genered. The lost arbitration
                         * could occur while NACK generation (other master still reading and ACK is generated) */
                        SCB_1_I2C_MASTER_GENERATE_STOP;
                    }
                }
            }

        } /* (SCB_1_I2C_MASTER) */
        #endif

    } /* (SCB_1_CHECK_I2C_FSM_MASTER) */


    /* FSM Slave */
    else if(SCB_1_CHECK_I2C_FSM_SLAVE)
    {
        #if(SCB_1_I2C_SLAVE)
        {
            /* INTR_SLAVE_NACK */
            /* The master completes reading the slave: the approprite flags have to be set.
             * The TX FIFO cleared after overflow condition is set.
             */
            if(SCB_1_CHECK_INTR_SLAVE_MASKED(SCB_1_INTR_SLAVE_I2C_NACK))
            {
                SCB_1_ClearSlaveInterruptSource(SCB_1_INTR_SLAVE_I2C_NACK);

                /* All entries that remain in TX FIFO max value is 9: 8 bytes TX FIFO + 1 bytes TX SR */
                diffCount = (SCB_1_GET_TX_FIFO_ENTRIES + SCB_1_GET_TX_FIFO_SR_VALID);

                if(SCB_1_slOverFlowCount > diffCount) /* Overflow */
                {
                    SCB_1_slStatus |= SCB_1_I2C_SSTAT_RD_ERR_OVFL;
                }
                else /* No Overflow */
                {
                    /* Roll-back the index */
                    SCB_1_slRdBufIndex -= (diffCount - SCB_1_slOverFlowCount);
                }

                /* Clean-up TX FIFO */
                SCB_1_SetTxInterruptMode(~SCB_1_INTR_TX_ALL);
                SCB_1_slOverFlowCount = 0u;
                SCB_1_CLEAR_TX_FIFO;

                /* Complete master reading */
                SCB_1_slStatus &= ~SCB_1_I2C_SSTAT_RD_BUSY;
                SCB_1_slStatus |=  SCB_1_I2C_SSTAT_RD_CMPLT;
                SCB_1_state     =  SCB_1_I2C_FSM_IDLE;
            }


            /* INTR_SLAVE_I2C_WRITE_STOP */
            /* The master completes writing to slave: the approprite flags have to be set.
             * The RX FIFO contains 1-8 bytes from previous transcation which need to be read.
             * There is possibility that RX FIFO contains address, it needs to leave it there.
             */
            if(SCB_1_CHECK_INTR_SLAVE_MASKED(SCB_1_INTR_SLAVE_I2C_WRITE_STOP))
            {
                SCB_1_ClearSlaveInterruptSource(SCB_1_INTR_SLAVE_I2C_WRITE_STOP);

                SCB_1_DISABLE_SLAVE_AUTO_DATA;

                while(0u != SCB_1_GET_RX_FIFO_ENTRIES)
                {
                    #if(SCB_1_I2C_ACCEPT_ADDR)
                    {
                        if((1u == SCB_1_GET_RX_FIFO_ENTRIES) &&
                           (SCB_1_CHECK_INTR_SLAVE_MASKED(SCB_1_INTR_SLAVE_I2C_ADDR_MATCH)))
                        {
                            break; /* Leave address in RX FIFO */
                        }
                    }
                    #endif

                    /* Put data in the component buffer */
                    SCB_1_slWrBufPtr[SCB_1_slWrBufIndex] = (uint8) SCB_1_RX_FIFO_RD_REG;
                    SCB_1_slWrBufIndex++;
                }

                if(SCB_1_CHECK_INTR_RX(SCB_1_INTR_RX_OVERFLOW))
                {
                    SCB_1_slStatus |= SCB_1_I2C_SSTAT_WR_ERR_OVFL;
                }

                /* Complete master writing */
                SCB_1_slStatus &= ~SCB_1_I2C_SSTAT_WR_BUSY;
                SCB_1_slStatus |=  SCB_1_I2C_SSTAT_WR_CMPLT;
                SCB_1_state     =  SCB_1_I2C_FSM_IDLE;
            }


            /* INTR_SLAVE_I2C_ADDR_MATCH */
            /* The address match event starts the slave operation: after leaving the
             * TX or RX direction has to chosen.
             * The wakeup interrupt must be cleared only after address match is set.
             */
            if(SCB_1_CHECK_INTR_SLAVE_MASKED(SCB_1_INTR_SLAVE_I2C_ADDR_MATCH))
            {
                #if(SCB_1_I2C_ACCEPT_ADDR) /* Address in RX FIFO */
                {
                    address  = SCB_1_RX_FIFO_RD_REG;
                    if(0u != address) {/* Suppress compiler warning */}
                }
                #endif

                if(SCB_1_CHECK_I2C_STATUS(SCB_1_I2C_STATUS_S_READ))
                /* TX direction: master reads from slave */
                {
                    SCB_1_SetTxInterruptMode(SCB_1_INTR_TX_EMPTY);

                    /* Start master reading */
                    SCB_1_slStatus |= SCB_1_I2C_SSTAT_RD_BUSY;
                    SCB_1_state     = SCB_1_I2C_FSM_SL_RD;
                }
                else /* RX direction: master writes into slave */
                {
                    SCB_1_ClearRxInterruptSource(SCB_1_INTR_RX_ALL);

                    /* Calculate available buffer size */
                    diffCount = (SCB_1_slWrBufSize - SCB_1_slWrBufIndex);

                    if(diffCount < SCB_1_FIFO_SIZE) /* Receive data: byte-by-byte */
                    {
                        SCB_1_SetRxInterruptMode(SCB_1_INTR_RX_NOT_EMPTY);
                    }
                    else /* Receive data: into RX FIFO */
                    {
                        if(diffCount == SCB_1_FIFO_SIZE)
                        {
                            /* NACK when RX FIFO become FULL */
                            SCB_1_ENABLE_SLAVE_AUTO_DATA;
                        }
                        else
                        {
                            /* Stretch clock when RX FIFO becomes FULL */
                            SCB_1_ENABLE_SLAVE_AUTO_DATA_ACK;
                            SCB_1_SetRxInterruptMode(SCB_1_INTR_RX_FULL);
                        }
                    }

                    /* Start master reading */
                    SCB_1_slStatus |= SCB_1_I2C_SSTAT_WR_BUSY;
                    SCB_1_state     = SCB_1_I2C_FSM_SL_WR;
                }

                /* The preparation complete: ACK the address */
                SCB_1_I2C_SLAVE_GENERATE_ACK;

                SCB_1_ClearI2CExtClkInterruptSource(SCB_1_INTR_I2C_EC_WAKE_UP);
                SCB_1_ClearSlaveInterruptSource(SCB_1_INTR_SLAVE_ALL);
            }

            /* SCB_1_INTR_RX_FULL */
            /* Get data from RX FIFO and decide whether to ACK or NACK following bytes
             */
            if(SCB_1_CHECK_INTR_RX_MASKED(SCB_1_INTR_RX_FULL))
            {
                /* Calculate available buffer size take to account that RX FIFO is FULL */
                diffCount =  SCB_1_slWrBufSize -
                            (SCB_1_slWrBufIndex + SCB_1_FIFO_SIZE);

                if(diffCount > SCB_1_FIFO_SIZE) /* Proceed transaction */
                {
                    diffCount = SCB_1_FIFO_SIZE;
                    endTransfer = 0u;
                }
                else /* End when FIFO becomes FULL again */
                {
                    endTransfer = 1u;
                }

                for(;(0u != diffCount);diffCount--)
                {
                    /* Put data in the component buffer */
                    SCB_1_slWrBufPtr[SCB_1_slWrBufIndex] = (uint8) SCB_1_RX_FIFO_RD_REG;
                    SCB_1_slWrBufIndex++;
                }

                if(0u != endTransfer) /* End transfer sending NACK */
                {
                    SCB_1_ENABLE_SLAVE_AUTO_DATA_NACK;

                    /* The INTR_RX_FULL comes earlier that INTR_SLAVE_I2C_STOP: disable all RX interrupt sources */
                    SCB_1_SetRxInterruptMode(~SCB_1_INTR_RX_ALL);
                }

                SCB_1_ClearRxInterruptSource(SCB_1_INTR_RX_FULL);
            }
            /* SCB_1_INTR_RX_NOT_EMPTY */
            /* The buffer size is less than 8: it requires processing in byte-by-byte mode.
             */
            else if(SCB_1_CHECK_INTR_RX_MASKED(SCB_1_INTR_RX_NOT_EMPTY))
            {
                diffCount = SCB_1_RX_FIFO_RD_REG; /* Get byte from RX FIFO */

                if(SCB_1_slWrBufIndex < SCB_1_slWrBufSize)
                {
                    SCB_1_I2C_SLAVE_GENERATE_ACK;

                    /* Put data into component buffer */
                    SCB_1_slWrBufPtr[SCB_1_slWrBufIndex] = (uint8) diffCount;
                    SCB_1_slWrBufIndex++;
                }
                else /* Overflow: there is no space in the component buffer */
                {
                    SCB_1_I2C_SLAVE_GENERATE_NACK;

                    SCB_1_slStatus |= SCB_1_I2C_SSTAT_WR_ERR_OVFL;
                }

                SCB_1_ClearRxInterruptSource(SCB_1_INTR_RX_NOT_EMPTY);
            }


            /* SCB_1_INTR_TX_EMPTY */
            /* Master reads slave: provide data to read or 0xFF in case end of the buffer
             * The overflow condition must be captured, but not set until the end of transaction.
             * There is possibility of false overflow due of TX FIFO utilization.
             */
            if(SCB_1_CHECK_INTR_TX_MASKED(SCB_1_INTR_TX_EMPTY))
            {
                while(SCB_1_FIFO_SIZE != SCB_1_GET_TX_FIFO_ENTRIES)
                {
                    if(SCB_1_slRdBufIndex < SCB_1_slRdBufSize) /* Data from buffer */
                    {
                        SCB_1_TX_FIFO_WR_REG = (uint32) SCB_1_slRdBufPtr[SCB_1_slRdBufIndex];
                        SCB_1_slRdBufIndex++;
                    }
                    else  /* Probably Overflow */
                    {
                        SCB_1_TX_FIFO_WR_REG = SCB_1_I2C_SLAVE_OVFL_RETURN;
                        SCB_1_slOverFlowCount++;
                    }
                }

                SCB_1_ClearTxInterruptSource(SCB_1_INTR_TX_EMPTY);
            }

        }  /* (SCB_1_I2C_SLAVE) */
        #endif
    }


    /* FSM EXIT */
    /* Sources to get here is errors while opearations:
     * INTR_SLAVE_I2C_BUS_ERROR, INTR_MASTER_I2C_BUS_ERROR, INTR_MASTER_I2C_ARB_LOST
     */
    else
    {
        /* CLEAN-UP the slave and master after: LOST ARB or BUS ERROR */
        
        /* Disable auto NACK before clear the FIFOs */
        SCB_1_DISABLE_SLAVE_AUTO_DATA_ACK;
        SCB_1_DISABLE_MASTER_AUTO_DATA_ACK;
        
        /* Clear RX FIFO */
        #if(SCB_1_I2C_SLAVE && SCB_1_I2C_ACCEPT_ADDR)
        {
            while(0u != SCB_1_GET_RX_FIFO_ENTRIES)
            {
                if((1u == SCB_1_GET_RX_FIFO_ENTRIES) &&
                   (SCB_1_CHECK_INTR_SLAVE_MASKED(SCB_1_INTR_SLAVE_I2C_ADDR_MATCH)))
                {
                    break; /* Leave address in RX FIFO */
                }
            
                SCB_1_RX_FIFO_RD_REG; /* Clear FIFO by reading */
            }
        }
        #else
        {
            SCB_1_CLEAR_RX_FIFO;
        }
        #endif
        
        
        SCB_1_CLEAR_TX_FIFO;


        SCB_1_SetRxInterruptMode(~SCB_1_INTR_RX_ALL);
        SCB_1_SetTxInterruptMode(~SCB_1_INTR_TX_ALL);

        SCB_1_ClearTxInterruptSource(SCB_1_INTR_RX_ALL);
        SCB_1_ClearRxInterruptSource(SCB_1_INTR_TX_ALL);
        SCB_1_ClearMasterInterruptSource(SCB_1_INTR_MASTER_ALL);
        SCB_1_ClearSlaveInterruptSource (SCB_1_INTR_SLAVE_ALL);

        SCB_1_state = SCB_1_I2C_FSM_IDLE;
    }
}


/* [] END OF FILE */
