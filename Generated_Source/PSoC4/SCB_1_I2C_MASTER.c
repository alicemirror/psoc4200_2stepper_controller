/*******************************************************************************
* File Name: SCB_1_I2C_MASTER.c
* Version 1.0
*
* Description:
*
*
*******************************************************************************
* Copyright 2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "SCB_1_I2C_PVT.h"


#if(SCB_1_I2C_MASTER_CONST)

/**********************************
*      System variables
**********************************/

/* Master variables */
volatile uint16 SCB_1_mstrStatus;        /* Master Status byte            */
volatile uint8  SCB_1_mstrControl;       /* Master Control byte           */

/* Transmit buffer variables */
volatile uint8 * SCB_1_mstrRdBufPtr;     /* Pointer to Master Read buffer  */
volatile uint32  SCB_1_mstrRdBufSize;    /* Master Read buffer size        */
volatile uint32  SCB_1_mstrRdBufIndex;   /* Master Read buffer Index       */

/* Receive buffer variables */
volatile uint8 * SCB_1_mstrWrBufPtr;     /* Pointer to Master Write buffer */
volatile uint32  SCB_1_mstrWrBufSize;    /* Master Write buffer size       */
volatile uint32  SCB_1_mstrWrBufIndex;   /* Master Write buffer Index      */


/*******************************************************************************
* Function Name: SCB_1_I2CMasterWriteBuf
********************************************************************************
*
* Summary:
*  Automatically writes an entire buffer of data to a slave device. Once the
*  data transfer is initiated by this function, further data transfer is handled
*  by the included ISR in byte by byte mode.
*
* Parameters:
*  slaveAddr: 7-bit slave address.
*  xferData:  Pointer to buffer of data to be sent.
*  cnt:       Size of buffer to send.
*  mode:      Transfer mode defines: start or restart condition generation at
*             begin of the transfer and complete the transfer or halt before
*             generating a stop.
*
* Return:
*  Status error - zero means no errors.
*
* Side Effects:
*  The included ISR will start transfer after start or restart condition will
*  be generated.
*
* Global variables:
*  SCB_1_mstrStatus  - used to store current status of I2C Master.
*  SCB_1_state       - used to store current state of software FSM.
*  SCB_1_mstrControl - used to control master end of transaction with
*  or without the Stop generation.
*  SCB_1_mstrWrBufPtr - used to store pointer to master write buffer.
*  SCB_1_mstrWrBufIndex - used to current index within master write
*  buffer.
*  SCB_1_mstrWrBufSize - used to store master write buffer size.
*
*******************************************************************************/
uint32 SCB_1_I2CMasterWriteBuf(uint32 slaveAddress, uint8 * wrData, uint32 cnt, uint32 mode)
{
    uint32 errStatus;

    errStatus = SCB_1_I2C_MSTR_NOT_READY;

    if(NULL != wrData)  /* Check buffer pointer */
    {
        /* Check FSM state and bus before generate Start/ReStart condition */
        if(SCB_1_CHECK_I2C_FSM_IDLE)
        {
            SCB_1_SCB_IRQ_Disable();

            /* Check the bus state */
            errStatus = SCB_1_CHECK_I2C_STATUS(SCB_1_I2C_STATUS_BUS_BUSY) ?
                            SCB_1_I2C_MSTR_BUS_BUSY : SCB_1_I2C_MSTR_NO_ERROR;
        }
        else if(SCB_1_CHECK_I2C_FSM_HALT)
        {
            SCB_1_mstrStatus &= ~SCB_1_I2C_MSTAT_XFER_HALT;
                              errStatus  =  SCB_1_I2C_MSTR_NO_ERROR;
        }
        else
        {
            /* Unexpected FSM state: exit */
        }
    }


    /* Check if the Master is ready to start  */
    if(SCB_1_I2C_MSTR_NO_ERROR == errStatus) /* No error proceed */
    {
        /* Setup write transcation */
        SCB_1_state = SCB_1_I2C_FSM_MSTR_WR_ADDR;
        SCB_1_mstrWrBufIndex = 0ul;
        SCB_1_mstrWrBufSize  = cnt;
        SCB_1_mstrWrBufPtr   = (volatile uint8 *) wrData;
        SCB_1_mstrControl    = mode;

        slaveAddress = SCB_1_GET_I2C_8BIT_ADDRESS(slaveAddress);

        SCB_1_mstrStatus &= ((uint32) ~SCB_1_I2C_MSTAT_WR_CMPLT);

        SCB_1_ClearMasterInterruptSource(SCB_1_INTR_MASTER_ALL);

        /* The TX and RX FIFO have to be EMPTY */

        /* Generate Start or ReStart */
        if(SCB_1_CHECK_I2C_MODE_RESTART(mode))
        {
            SCB_1_I2C_MASTER_GENERATE_RESTART;
            SCB_1_TX_FIFO_WR_REG = slaveAddress;
        }
        else
        {
            SCB_1_TX_FIFO_WR_REG = slaveAddress;
            SCB_1_I2C_MASTER_GENERATE_START;
        }

         /* Catch when address will be sent */
        SCB_1_ClearTxInterruptSource(SCB_1_INTR_TX_UNDERFLOW);
        SCB_1_SetTxInterruptMode(SCB_1_INTR_TX_UNDERFLOW);
    }

    SCB_1_SCB_IRQ_Enable();

    return(errStatus);
}


/*******************************************************************************
* Function Name: SCB_1_I2CMasterReadBuf
********************************************************************************
*
* Summary:
*  Automatically writes an entire buffer of data to a slave device. Once the
*  data transfer is initiated by this function, further data transfer is handled
*  by the included ISR in byte by byte mode.
*
* Parameters:
*  slaveAddr: 7-bit slave address.
*  xferData:  Pointer to buffer where to put data from slave.
*  cnt:       Size of buffer to read.
*  mode:      Transfer mode defines: start or restart condition generation at
*             begin of the transfer and complete the transfer or halt before
*             generating a stop.
*
* Return:
*  Status error - zero means no errors.
*
* Side Effects:
*  The included ISR will start transfer after start or restart condition will
*  be generated.
*
* Global variables:
*  SCB_1_mstrStatus  - used to store current status of I2C Master.
*  SCB_1_state       - used to store current state of software FSM.
*  SCB_1_mstrControl - used to control master end of transaction with
*  or without the Stop generation.
*  SCB_1_mstrRdBufPtr - used to store pointer to master write buffer.
*  SCB_1_mstrRdBufIndex - used to current index within master write
*  buffer.
*  SCB_1_mstrRdBufSize - used to store master write buffer size.
*
*******************************************************************************/
uint32 SCB_1_I2CMasterReadBuf(uint32 slaveAddress, uint8 * rdData, uint32 cnt, uint32 mode)
{
    uint32 errStatus;

    errStatus = SCB_1_I2C_MSTR_NOT_READY;

    if(NULL != rdData)
    {
        /* Check FSM state and bus before generate Start/ReStart condition */
        if(SCB_1_CHECK_I2C_FSM_IDLE)
        {
            SCB_1_SCB_IRQ_Disable();

            /* Check the bus state */
            errStatus = SCB_1_CHECK_I2C_STATUS(SCB_1_I2C_STATUS_BUS_BUSY) ?
                            SCB_1_I2C_MSTR_BUS_BUSY : SCB_1_I2C_MSTR_NO_ERROR;
        }
        else if(SCB_1_CHECK_I2C_FSM_HALT)
        {
            SCB_1_mstrStatus &= ((uint32) ~SCB_1_I2C_MSTAT_XFER_HALT);
                              errStatus  =  SCB_1_I2C_MSTR_NO_ERROR;
        }
        else
        {
            /* Unexpected FSM state: exit */
        }
    }

    /* Check the Master ready to proceed */
    if(SCB_1_I2C_MSTR_NO_ERROR == errStatus) /* No error proceed */
    {
        /* Setup read transfer */
        SCB_1_state = SCB_1_I2C_FSM_MSTR_RD_ADDR;
        SCB_1_mstrRdBufIndex = 0ul;
        SCB_1_mstrRdBufSize  = cnt;
        SCB_1_mstrRdBufPtr   = (volatile uint8 *) rdData;
        SCB_1_mstrControl    = mode;

        slaveAddress = (SCB_1_GET_I2C_8BIT_ADDRESS(slaveAddress) | SCB_1_I2C_READ_FLAG);

        SCB_1_mstrStatus &= ((uint32) ~SCB_1_I2C_MSTAT_RD_CMPLT);

        SCB_1_ClearMasterInterruptSource(SCB_1_INTR_MASTER_ALL);

        /* The TX and RX FIFO have to be EMPTY */

        /* Generate Start or ReStart */
        if(SCB_1_CHECK_I2C_MODE_RESTART(mode))
        {
            SCB_1_I2C_MASTER_GENERATE_RESTART;
            SCB_1_TX_FIFO_WR_REG = (slaveAddress);
        }
        else
        {
            SCB_1_TX_FIFO_WR_REG = (slaveAddress);
            SCB_1_I2C_MASTER_GENERATE_START;
        }

        /* Prepare reaing */
        if(SCB_1_mstrRdBufSize < SCB_1_I2C_FIFO_SIZE) /* Reading byte-by-byte */
        {
            SCB_1_SetRxInterruptMode(SCB_1_INTR_RX_NOT_EMPTY);
        }
        else /* Reading use RX FIFO */
        {
            SCB_1_ENABLE_MASTER_AUTO_DATA_ACK;
            SCB_1_SetRxInterruptMode(SCB_1_INTR_RX_FULL);
        }
    }

    SCB_1_SCB_IRQ_Enable();

    return(errStatus);
}


/*******************************************************************************
* Function Name: SCB_1_I2CMasterSendStart
********************************************************************************
*
* Summary:
*  Generates Start condition and sends slave address with read/write bit.
*
* Parameters:
*  slaveAddress:  7-bit slave address.
*  R_nW:          Zero, send write command, non-zero send read command.
*
* Return:
*  Status error - zero means no errors.
*
* Side Effects:
*  This function is entered without a 'byte complete' bit set in the I2C_CSR
*  register. It does not exit until it will be set.
*
* Global variables:
*  SCB_1_state - used to store current state of software FSM.
*
*******************************************************************************/
uint32 SCB_1_I2CMasterSendStart(uint32 slaveAddress, uint32 R_nW)
{
    uint32 errStatus;

    errStatus = SCB_1_I2C_MSTR_NOT_READY;

    /* Check FSM state before generate Start condition */
    if(SCB_1_CHECK_I2C_FSM_IDLE)
    {
        /* If bus is free, generate Start condition */
        if(SCB_1_CHECK_I2C_STATUS(SCB_1_I2C_STATUS_BUS_BUSY))
        {
            errStatus = SCB_1_I2C_MSTR_BUS_BUSY;
        }
        else
        {
            SCB_1_SCB_IRQ_Disable(); /* Disable interrupt: the manual APIs don't require it */

            slaveAddress = SCB_1_GET_I2C_8BIT_ADDRESS(slaveAddress);

            if(0u == R_nW) /* Write direction */
            {
                SCB_1_state = SCB_1_I2C_FSM_MSTR_WR_DATA;
            }
            else /* Read direction */
            {
                SCB_1_state = SCB_1_I2C_FSM_MSTR_RD_DATA;
                         slaveAddress |= SCB_1_I2C_READ_FLAG;
            }

            /* The TX and RX FIFO have to be EMPTY */

            SCB_1_TX_FIFO_WR_REG = slaveAddress; /* Put address in TX FIFO */
            SCB_1_ClearMasterInterruptSource(SCB_1_INTR_MASTER_ALL);

            SCB_1_I2C_MASTER_GENERATE_START;


            while(!SCB_1_CHECK_INTR_MASTER(SCB_1_INTR_MASTER_I2C_ACK  |
                                                      SCB_1_INTR_MASTER_I2C_NACK |
                                                      SCB_1_INTR_MASTER_I2C_ARB_LOST))
            {
                /* Wait until address will be transfered */
            }

            /* Check results of address phase */
            if(SCB_1_CHECK_INTR_MASTER(SCB_1_INTR_MASTER_I2C_ACK))
            {
                errStatus = SCB_1_I2C_MSTR_NO_ERROR;
            }
            else if(SCB_1_CHECK_INTR_MASTER(SCB_1_INTR_MASTER_I2C_NACK))
            {
                errStatus = SCB_1_I2C_MSTR_ERR_LB_NAK;
            }
            else /* INTR_MASTER_I2C_ARB_LOST  */
            {
                SCB_1_state = SCB_1_I2C_FSM_IDLE;
                             errStatus = SCB_1_I2C_MSTR_ERR_ARB_LOST;
            }

            SCB_1_ClearMasterInterruptSource(SCB_1_INTR_MASTER_I2C_ACK  |
                                                        SCB_1_INTR_MASTER_I2C_NACK |
                                                        SCB_1_INTR_MASTER_I2C_ARB_LOST);
        }
    }

    return(errStatus);
}


/*******************************************************************************
* Function Name: SCB_1_I2CMasterSendRestart
********************************************************************************
*
* Summary:
*  Generates ReStart condition and sends slave address with read/write bit.
*
* Parameters:
*  slaveAddress:  7-bit slave address.
*  R_nW:          Zero, send write command, non-zero send read command.
*
* Return:
*  Status error - zero means no errors.
*
* Side Effects:
*  This function is entered without a 'byte complete' bit set in the I2C_CSR
*  register. It does not exit until it will be set.
*
* Global variables:
*  SCB_1_state - used to store current state of software FSM.
*
*******************************************************************************/
uint32 SCB_1_I2CMasterSendRestart(uint32 slaveAddress, uint32 R_nW)
{
    uint32 errStatus;

    errStatus = SCB_1_I2C_MSTR_NOT_READY;

    /* Check FSM state before generate ReStart condition */
    if(SCB_1_CHECK_I2C_MASTER_ACTIVE)
    {
        slaveAddress = SCB_1_GET_I2C_8BIT_ADDRESS(slaveAddress);

        if(0u == R_nW) /* Write direction */
        {
            SCB_1_state = SCB_1_I2C_FSM_MSTR_WR_DATA;
        }
        else  /* Read direction */
        {
            SCB_1_state  = SCB_1_I2C_FSM_MSTR_RD_DATA;
                      slaveAddress |= SCB_1_I2C_READ_FLAG;
        }

        /* The TX and RX FIFO have to be EMPTY */

        /* Clean-up interrupt status */
        SCB_1_ClearMasterInterruptSource(SCB_1_INTR_MASTER_ALL);

        /* Generates a START - the restart should be set first and then address need to be put,
         * Because on write the the byte in TX FIFO treated as DATA byte. ReStart will not be generated */
        SCB_1_I2C_MASTER_GENERATE_RESTART;

        while(SCB_1_CHECK_I2C_MASTER_CMD(SCB_1_I2C_MASTER_CMD_M_START))
        {
            /* Wait until ReStart will be generated */
        }

        /* Put address into TX FIFO */
        SCB_1_TX_FIFO_WR_REG = slaveAddress;

        /* Wait for the address to be transfered */
        while(!SCB_1_CHECK_INTR_MASTER(SCB_1_INTR_MASTER_I2C_ACK  |
                                                  SCB_1_INTR_MASTER_I2C_NACK |
                                                  SCB_1_INTR_MASTER_I2C_ARB_LOST))
        {
            /* Wait until address will be transfered */
        }

        /* Check results of address phase */
        if(SCB_1_CHECK_INTR_MASTER(SCB_1_INTR_MASTER_I2C_ACK))
        {
            errStatus = SCB_1_I2C_MSTR_NO_ERROR;
        }
        else if(SCB_1_CHECK_INTR_MASTER(SCB_1_INTR_MASTER_I2C_NACK))
        {
             errStatus = SCB_1_I2C_MSTR_ERR_LB_NAK;
        }
        else /* INTR_MASTER_I2C_ARB_LOST */
        {
            SCB_1_state = SCB_1_I2C_FSM_IDLE;
                         errStatus = SCB_1_I2C_MSTR_ERR_ARB_LOST;
        }

        /* Clean-up interrupt status */
        SCB_1_ClearMasterInterruptSource(SCB_1_INTR_MASTER_I2C_ACK  |
                                                    SCB_1_INTR_MASTER_I2C_NACK |
                                                    SCB_1_INTR_MASTER_I2C_ARB_LOST);
    }

    return(errStatus);
}


/*******************************************************************************
* Function Name: SCB_1_I2CMasterSendStop
********************************************************************************
*
* Summary:
*  Generates I2C Stop condition on bus. Function do nothing if Start or Restart
*  condition was failed before call this function.
*
* Parameters:
*  None
*
* Return:
*  Status error - zero means no errors.
*
* Side Effects:
*  The Stop generation is required to complete transaction.
*  This function does not wait while Stop condition will be generated.
*
* Global variables:
*  SCB_1_state - used to store current state of software FSM.
*
*******************************************************************************/
uint32 SCB_1_I2CMasterSendStop(void)
{
    uint32 errStatus;

    errStatus = SCB_1_I2C_MSTR_NOT_READY;

    /* Check FSM state before generate Stop condition */
    if(SCB_1_CHECK_I2C_MASTER_ACTIVE)
    {
        SCB_1_I2C_MASTER_GENERATE_STOP;

        /* Wait NACK and Stop generation: but while NACK generation the lost arbitrage is possible */
        while(!SCB_1_CHECK_INTR_MASTER(SCB_1_INTR_MASTER_I2C_STOP |
                                                  SCB_1_INTR_MASTER_I2C_ARB_LOST))
        {
            /* Wait until Stop will be generated */
        }


        /* Check what was actually generated */
        if(SCB_1_CHECK_INTR_MASTER(SCB_1_INTR_MASTER_I2C_STOP))
        {
            errStatus = SCB_1_I2C_MSTR_NO_ERROR;
        }
        else /* SCB_1_INTR_MASTER_I2C_ARB_LOST */
        {
            errStatus = SCB_1_I2C_MSTR_ERR_ARB_LOST;
        }

        SCB_1_state = SCB_1_I2C_FSM_IDLE;

        /* Clean-up interrupt status */
        /* NACK is not captured by end of read: valid only for TX direction */
        SCB_1_ClearMasterInterruptSource(SCB_1_INTR_MASTER_I2C_STOP |
                                                    SCB_1_INTR_MASTER_I2C_ARB_LOST);
    }

    return(errStatus);
}


/*******************************************************************************
* Function Name: SCB_1_I2CMasterWriteByte
********************************************************************************
*
* Summary:
*  Sends one byte to a slave. A valid Start or ReStart condition must be
*  generated before this call this function. Function do nothing if Start or
*  Restart condition was failed before call this function.
*
* Parameters:
*  data:  The data byte to send to the slave.
*
* Return:
*  Status error - zero means no errors.
*
* Side Effects:
*  This function is entered without a 'byte complete' bit set in the I2C_CSR
*  register. It does not exit until it will be set.
*
* Global variables:
*  SCB_1_state - used to store current state of software FSM.
*
*******************************************************************************/
uint32 SCB_1_I2CMasterWriteByte(uint32 theByte)
{
    uint32 errStatus;

    errStatus = SCB_1_I2C_MSTR_NOT_READY;

    /* Check FSM state before write byte */
    if(SCB_1_CHECK_I2C_MASTER_ACTIVE)
    {
        SCB_1_TX_FIFO_WR_REG = theByte;

        while(!SCB_1_CHECK_INTR_MASTER(SCB_1_INTR_MASTER_I2C_ACK  |
                                                  SCB_1_INTR_MASTER_I2C_NACK |
                                                  SCB_1_INTR_MASTER_I2C_ARB_LOST))
        {
            /* Wait unitl byte will be transfered */
        }

        /* Check results after byte was sent */
        if(SCB_1_CHECK_INTR_MASTER(SCB_1_INTR_MASTER_I2C_ACK))
        {
            SCB_1_state = SCB_1_I2C_FSM_MSTR_HALT;
                         errStatus = SCB_1_I2C_MSTR_NO_ERROR;
        }
        else if(SCB_1_CHECK_INTR_MASTER(SCB_1_INTR_MASTER_I2C_NACK))
        {
            SCB_1_state = SCB_1_I2C_FSM_MSTR_HALT;
                         errStatus = SCB_1_I2C_MSTR_ERR_LB_NAK;
        }
        else /* INTR_MASTER_I2C_ARB_LOST */
        {
            SCB_1_state = SCB_1_I2C_FSM_IDLE;
                         errStatus = SCB_1_I2C_MSTR_ERR_ARB_LOST;
        }

        /* Clean-up interrupt status */
        SCB_1_ClearMasterInterruptSource(SCB_1_INTR_MASTER_I2C_ACK  |
                                                    SCB_1_INTR_MASTER_I2C_NACK |
                                                    SCB_1_INTR_MASTER_I2C_ARB_LOST);
    }

    return(errStatus);
}


/*******************************************************************************
* Function Name: SCB_1_I2CMasterReadByte
********************************************************************************
*
* Summary:
*  Reads one byte from a slave and ACK or NACK the transfer. A valid Start or
*  ReStart condition must be generated before this call this function. Function
*  do nothing if Start or Restart condition was failed before call this
*  function.
*
* Parameters:
*  acknNack:  Zero, response with NACK, if non-zero response with ACK.
*
* Return:
*  Byte read from slave.
*
* Side Effects:
*  This function is entered without a 'byte complete' bit set in the I2C_CSR
*  register. It does not exit until it will be set.
*
* Global variables:
*  SCB_1_state - used to store current state of software FSM.
*
*******************************************************************************/
uint32 SCB_1_I2CMasterReadByte(uint32 ackNack)
{
    uint32 theByte;

    theByte = 0u;

    /* Check FSM state before read byte */
    if(SCB_1_CHECK_I2C_MASTER_ACTIVE)
    {
        while(0u == SCB_1_CHECK_INTR_RX(SCB_1_INTR_RX_NOT_EMPTY))
        {
            /* Wait until byte will be received */
        }

        theByte = SCB_1_RX_FIFO_RD_REG;

        SCB_1_ClearRxInterruptSource(SCB_1_INTR_RX_NOT_EMPTY);

        /* ACK  - generates directly by master CMD.
         * NACK - does nothing. The NACK and STOP are generated by MasterSendStop() */
        if(0u == ackNack)  /* Do ACK */
        {
            SCB_1_I2C_MASTER_GENERATE_ACK;
        }
        else /* Do nothing */
        {
            SCB_1_state = SCB_1_I2C_FSM_MSTR_HALT;
        }
    }

    return(theByte);
}


/*******************************************************************************
* Function Name: SCB_1_I2CMasterGetReadBufSize
********************************************************************************
*
* Summary:
*  Returns the amount of bytes that has been transferred with an
*  I2C_MasterReadBuf command.
*
* Parameters:
*  None
*
* Return:
*  Byte count of transfer. If the transfer is not yet complete, it will return
*  the byte count transferred so far.
*
* Global variables:
*  SCB_1_mstrRdBufIndex - used to current index within master read
*  buffer.
*
*******************************************************************************/
uint32 SCB_1_I2CMasterGetReadBufSize(void)
{
    return(SCB_1_mstrRdBufIndex);
}


/*******************************************************************************
* Function Name: SCB_1_I2CMasterGetWriteBufSize
********************************************************************************
*
* Summary:
*  Returns the amount of bytes that has been transferred with an
*  I2C_MasterWriteBuf command.
*
* Parameters:
*  None
*
* Return:
*  Byte count of transfer. If the transfer is not yet complete, it will return
*  the byte count transferred so far.
*
* Global variables:
*  SCB_1_mstrWrBufIndex - used to current index within master write
*  buffer.
*
*******************************************************************************/
uint32 SCB_1_I2CMasterGetWriteBufSize(void)
{
    return(SCB_1_mstrWrBufIndex);
}


/*******************************************************************************
* Function Name: SCB_1_I2CMasterClearReadBuf
********************************************************************************
*
* Summary:
*  Resets the read buffer pointer back to the first byte in the buffer.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  SCB_1_mstrRdBufIndex - used to current index within master read
*   buffer.
*  SCB_1_mstrStatus - used to store current status of I2C Master.
*
*******************************************************************************/
void SCB_1_I2CMasterClearReadBuf(void)
{
    SCB_1_mstrRdBufIndex = 0u;
    SCB_1_mstrStatus    &= ((uint32) ~SCB_1_I2C_MSTAT_RD_CMPLT);
}


/*******************************************************************************
* Function Name: SCB_1_I2CMasterClearWriteBuf
********************************************************************************
*
* Summary:
*  Resets the write buffer pointer back to the first byte in the buffer.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  SCB_1_mstrRdBufIndex - used to current index within master read
*   buffer.
*  SCB_1_mstrStatus - used to store current status of I2C Master.
*
*******************************************************************************/
void SCB_1_I2CMasterClearWriteBuf(void)
{
    SCB_1_mstrWrBufIndex = 0u;
    SCB_1_mstrStatus    &= ((uint32) ~SCB_1_I2C_MSTAT_WR_CMPLT);
}


/*******************************************************************************
* Function Name: SCB_1_I2CMasterStatus
********************************************************************************
*
* Summary:
*  Returns the master's communication status.
*
* Parameters:
*  None
*
* Return:
*  Current status of I2C master.
*
* Global variables:
*  SCB_1_mstrStatus - used to store current status of I2C Master.
*
*******************************************************************************/
uint32 SCB_1_I2CMasterStatus(void)
{
    uint32 status;

    status = SCB_1_mstrStatus;

    if(SCB_1_CHECK_I2C_MASTER_ACTIVE)
    {
        /* Add status of master pending tranaction: MSTAT_XFER_INP */
        status |= SCB_1_I2C_MSTAT_XFER_INP;
    }

    return(status);
}


/*******************************************************************************
* Function Name: SCB_1_I2CMasterClearStatus
********************************************************************************
*
* Summary:
*  Clears all status flags and returns the master status.
*
* Parameters:
*  None
*
* Return:
*  Current status of I2C master.
*
* Global variables:
*  SCB_1_mstrStatus - used to store current status of I2C Master.
*
*******************************************************************************/
uint32 SCB_1_I2CMasterClearStatus(void)
{
    uint32 status;

    /* Read and clear master status */
    status = SCB_1_mstrStatus;
    SCB_1_mstrStatus = SCB_1_I2C_MSTAT_CLEAR;

    return(status);
}

#endif /* (SCB_1_I2C_MASTER_CONST) */


/* [] END OF FILE */
