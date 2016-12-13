/*******************************************************************************
* File Name: SCB_1_I2C_BOOT.c
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

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (SCB_1_I2C_BTLDR_COMM_ENABLED)


/***************************************
*    Bootloader Variables
***************************************/

/* Writes to this buffer */
static uint8 SCB_1_slReadBuf[SCB_1_I2C_BTLDR_SIZEOF_READ_BUFFER];

/* Reads from this buffer */
static uint8 SCB_1_slWriteBuf[SCB_1_I2C_BTLDR_SIZEOF_WRITE_BUFFER];


/*******************************************************************************
* Function Name: SCB_1_I2CCyBtldrCommStart
********************************************************************************
*
* Summary:
*  Starts the communication component and enables the interrupt.
*  The read buffer initial state is full and the read always is 0xFFu.
*  The write buffer is clear and ready to receive a commmand.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void SCB_1_I2CCyBtldrCommStart(void)
{
    SCB_1_I2CSlaveInitWriteBuf(SCB_1_slWriteBuf, SCB_1_I2C_BTLDR_SIZEOF_WRITE_BUFFER);
    SCB_1_I2CSlaveInitReadBuf (SCB_1_slReadBuf, 0u);

    SCB_1_Start();
}


/*******************************************************************************
* Function Name: SCB_1_CyBtldrCommStop
********************************************************************************
*
* Summary:
*  Disables the communication component and disables the interrupt.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void SCB_1_I2CCyBtldrCommStop(void)
{
    SCB_1_Stop();
}


/*******************************************************************************
* Function Name: SCB_1_CyBtldrCommReset
********************************************************************************
*
* Summary:
*  Set buffers to the initial state and reset the statuses.
*  The read buffer initial state is full and the read always is 0xFFu.
*  The write buffer is clear and ready to receive a commmand.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  SCB_1_slRdBufIndex - used to store current index within slave
*  read buffer.
*
*******************************************************************************/
void SCB_1_I2CCyBtldrCommReset(void)
{
    /* Make the Read buffer full */
    SCB_1_slRdBufSize = 0u;

    /* Reset Write buffer and Read buffer */
    SCB_1_slRdBufIndex = 0u;
    SCB_1_slWrBufIndex = 0u;

    /* Clear read and write status */
    SCB_1_slStatus = 0u;
}


/*******************************************************************************
* Function Name: SCB_1_CyBtldrCommRead
********************************************************************************
*
* Summary:
*  Receives the command from the Host.
*  All bytes are received by the I2C ISR and stored in internal I2C buffer. The
*  function checks status with timeout to detemine the end of transfer and
*  then copy data to bootloader buffer.
*  After exist this function the I2C ISR is able to receive more data.
*
* Parameters:
*  pData:    pointer to data buffer to store command.
*  Size:     maximum number of bytes which could to be passed back.
*  Count:    actual size of data was received.
*  TimeOut:  timeout value in tries of 10uS.
*
* Return:
*  Status of receive operation.
*
* Global variables:
*  SCB_1_slWriteBuf - used to store received command.
*
*******************************************************************************/
cystatus SCB_1_I2CCyBtldrCommRead(uint8 pData[], uint16 size, uint16 * count, uint8 timeOut)
{
    cystatus status;
    uint32 timeoutMs;

    status = CYRET_BAD_PARAM;

    if((NULL != pData) && (size > 0u))
    {
        status = CYRET_TIMEOUT;
        timeoutMs = ((uint32) 10u * timeOut); /* Convert from 10mS check to 1mS checks */

        while(0u != timeoutMs) /* Wait for Command from the host */
        {
            /* Check if the host complete write */
            if(0u != (SCB_1_I2C_SSTAT_WR_CMPLT & SCB_1_slStatus))
            {
                /* How many bytes the host has been written */

                /* Copy to command from I2C to bootloader buffer */
                (void) memcpy((void *) pData, (void *) SCB_1_slWriteBuf,
                                                SCB_1_I2C_MIN_UINT16(SCB_1_slWrBufIndex, size));

                /* Clear I2C write buffer and status */
                SCB_1_slStatus     = 0u;
                SCB_1_slWrBufIndex = 0u;

                status = CYRET_SUCCESS;
                break;
            }

            CyDelay(SCB_1_WAIT_1_MS);
            timeoutMs--;
        }
    }

    return(status);
}


/*******************************************************************************
* Function Name: SCB_1_CyBtldrCommWrite
********************************************************************************
*
* Summary:
*  Transmits the status of executed command to the Host.
*  The function updates the I2C read buffer with response and realeases it to
*  the host. All reads return 0xFF till the buffer will be released. All bytes
*  are transfered by the I2C ISR.
*  The function waits with timeout till all bytes will be read.
*  After exist this function the reads return 0xFF.
*
* Parameters:
*  pData:    pointer to data buffer with response command.
*  Size:     number of bytes required to be transmitted.
*  Count:    actual size of data was transmitted.
*  TimeOut:  timeout value in tries of 10uS.
*
* Return:
*  Status of transmit operation.
*
* Global variables:
*  SCB_1_slReadBuf - used to store response.
*  SCB_1_slRdBufIndex - used to store current index within slave
*  read buffer.
*
*******************************************************************************/
cystatus SCB_1_I2CCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut)
{
    cystatus status;
    uint32 timeoutMs;

    status = CYRET_BAD_PARAM;

    if((NULL != pData) && (size > 0u))
    {
        status = CYRET_TIMEOUT;
        timeoutMs = ((uint32) 10u * timeOut); /* Convert from 10mS checks to 1mS checks */

        /* Copy to response from bootloader to I2C buffer */
        (void) memcpy((void *) SCB_1_slReadBuf, (void *) pData, size);
        *count = size; /* Buffer was copied to I2C buffer */

         /* The buffer is free to be read */
        SCB_1_slRdBufSize = ((uint32) size);

        /* Wait till response will be read */
        while(0u != timeoutMs)
        {
            /* The condition (slRdBufIndex == size) could trigger faster, because of TX FIFO fills in advance.
             * The transcation waits for the Stop and when all bytes from buffer will be transmitted,
             * inculdes buffer overflow. 
             */
            if((SCB_1_slRdBufIndex == (uint32) size) &&
               (0u == (SCB_1_I2C_SSTAT_RD_BUSY & SCB_1_slStatus)))
            {
                SCB_1_slRdBufSize  = 0u;
                SCB_1_slRdBufIndex = 0u;

                status = CYRET_SUCCESS;
                break;
            }

             CyDelay(SCB_1_WAIT_1_MS);
            timeoutMs--;
        }
    }

    return(status);
}

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (SCB_1_I2C_BTLDR_COMM_ENABLED) */


/* [] END OF FILE */
