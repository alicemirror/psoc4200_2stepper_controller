/***************************************************************************//**
* \file Comm_SPI_BOOT.c
* \version 3.20
*
* \brief
*  This file provides the source code of the bootloader communication APIs
*  for the SCB Component SPI mode.
*
* Note:
*
********************************************************************************
* \copyright
* Copyright 2013-2016, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "Comm_BOOT.h"
#include "Comm_SPI_UART.h"

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (Comm_SPI_BTLDR_COMM_ENABLED)

/*******************************************************************************
* Function Name: Comm_SpiCyBtldrCommStart
****************************************************************************//**
*
*  Starts the SPI component.
*
*******************************************************************************/
void Comm_SpiCyBtldrCommStart(void)
{
    Comm_Start();
}


/*******************************************************************************
* Function Name: Comm_SpiCyBtldrCommStop
****************************************************************************//**
*
*  Disables the SPI component.
*
*******************************************************************************/
void Comm_SpiCyBtldrCommStop(void)
{
    Comm_Stop();
}


/*******************************************************************************
* Function Name: Comm_SpiCyBtldrCommReset
****************************************************************************//**
*
*  Resets the receive and transmit communication buffers.
*
*******************************************************************************/
void Comm_SpiCyBtldrCommReset(void)
{
    /* Clear RX and TX buffers */
    Comm_SpiUartClearRxBuffer();
    Comm_SpiUartClearTxBuffer();
}


/*******************************************************************************
* Function Name: Comm_SpiCyBtldrCommRead
****************************************************************************//**
*
*  Allows the caller to read data from the bootloader host (the host writes the
*  data). The function handles polling to allow a block of data to be completely
*  received from the host device.
*
*  \param pData: Pointer to storage for the block of data to be read from the
*   bootloader host
*  \param size: Number of bytes to be read.
*  \param count: Pointer to the variable to write the number of bytes actually
*   read.
*  \param timeOut: Number of units in 10 ms to wait before returning
*   because of a timeout.
*
* \return
*  Returns CYRET_SUCCESS if no problem was encountered or returns the value
*  that best describes the problem. For more information refer to the
*  "Return Codes" section of the System Reference Guide.
*
*******************************************************************************/
cystatus Comm_SpiCyBtldrCommRead(uint8 pData[], uint16 size, uint16 * count, uint8 timeOut)
{
    cystatus status;
    uint32 byteCount;
    uint32 timeoutMs;
    uint32 i;

    status = CYRET_BAD_PARAM;

    if ((NULL != pData) && (size > 0u))
    {
        status = CYRET_TIMEOUT;
        timeoutMs = ((uint32) 10u * timeOut); /* Convert from 10mS check to 1mS checks */

        /* Wait with timeout 1mS for packet start */
        byteCount = 0u;
        do
        {
            /* Check packet start */
            if (0u != Comm_SpiUartGetRxBufferSize())
            {
                /* Wait for packet end */
                do
                {
                    byteCount = Comm_SpiUartGetRxBufferSize();
                    CyDelayUs(Comm_SPI_BYTE_TO_BYTE);
                }
                while (byteCount != Comm_SpiUartGetRxBufferSize());

                /* Disable data reception into RX FIFO */
                Comm_RX_FIFO_CTRL_REG |= Comm_RX_FIFO_CTRL_FREEZE;

                byteCount = Comm_BYTES_TO_COPY(byteCount, size);
                *count = (uint16) byteCount;
                status = CYRET_SUCCESS;

                break;
            }

            CyDelay(Comm_WAIT_1_MS);
            --timeoutMs;
        }
        while (0u != timeoutMs);

        /* Get data from the RX buffer into bootloader buffer */
        for (i = 0u; i < byteCount; ++i)
        {
            pData[i] = (uint8) Comm_SpiUartReadRxData();
        }
    }

    return (status);
}


/*******************************************************************************
* Function Name: Comm_SpiCyBtldrCommWrite
****************************************************************************//**
*
*  Allows the caller to read data from the bootloader host (the host writes the
*  data). The function handles polling to allow a block of data to be completely
*  received from the host device.
*
*  \param pData: Pointer to the block of data to be written to the bootloader
*   host.
*  \param size: Number of bytes to be written.
*  \param count: Pointer to the variable to write the number of bytes actually
*   written.
*  \param timeOut: Number of units in 10 ms to wait before returning
*   because of a timeout.
*
*  \return
*   Returns CYRET_SUCCESS if no problem was encountered or returns the value
*   that best describes the problem. For more information refer to the
*   "Return Codes" section of the System Reference Guide.
*
*******************************************************************************/
cystatus Comm_SpiCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut)
{
    cystatus status;
    uint32 timeoutMs;

    status = CYRET_BAD_PARAM;

    if ((NULL != pData) && (size > 0u))
    {
        status = CYRET_TIMEOUT;
        timeoutMs = ((uint32) 10u * timeOut); /* Convert from 10mS check to 1mS checks */

        /* Put data into TX buffer */
        Comm_SpiUartPutArray(pData, (uint32) size);

        /* Wait with timeout 1mS for packet end */
        do
        {
            /* Check for packet end */
            if ((0u == Comm_SpiUartGetTxBufferSize()) &&
                (0u == (Comm_SPI_STATUS_REG & Comm_SPI_STATUS_BUS_BUSY)) &&
                (0u == (Comm_TX_FIFO_STATUS_REG & Comm_TX_FIFO_SR_VALID)))
            {
                *count = size;
                status = CYRET_SUCCESS;

                break;
            }

            CyDelay(Comm_WAIT_1_MS);
            --timeoutMs;
        }
        while (0u != timeoutMs);

        /* Enable data reception into RX FIFO */
        Comm_SpiUartClearRxBuffer();
        Comm_RX_FIFO_CTRL_REG &= (uint32) ~Comm_RX_FIFO_CTRL_FREEZE;
    }

    return (status);
}

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (Comm_SPI_BTLDR_COMM_ENABLED) */


/* [] END OF FILE */
