/***************************************************************************//**
* \file Comm_SPI_UART.c
* \version 3.20
*
* \brief
*  This file provides the source code to the API for the SCB Component in
*  SPI and UART modes.
*
* Note:
*
*******************************************************************************
* \copyright
* Copyright 2013-2016, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "Comm_PVT.h"
#include "Comm_SPI_UART_PVT.h"

/***************************************
*        SPI/UART Private Vars
***************************************/

#if(Comm_INTERNAL_RX_SW_BUFFER_CONST)
    /* Start index to put data into the software receive buffer.*/
    volatile uint32 Comm_rxBufferHead;
    /* Start index to get data from the software receive buffer.*/
    volatile uint32 Comm_rxBufferTail;
    /**
    * \addtogroup group_globals
    * \{
    */
    /** Sets when internal software receive buffer overflow
    *  was occurred.
    */
    volatile uint8  Comm_rxBufferOverflow;
    /** \} globals */
#endif /* (Comm_INTERNAL_RX_SW_BUFFER_CONST) */

#if(Comm_INTERNAL_TX_SW_BUFFER_CONST)
    /* Start index to put data into the software transmit buffer.*/
    volatile uint32 Comm_txBufferHead;
    /* Start index to get data from the software transmit buffer.*/
    volatile uint32 Comm_txBufferTail;
#endif /* (Comm_INTERNAL_TX_SW_BUFFER_CONST) */

#if(Comm_INTERNAL_RX_SW_BUFFER)
    /* Add one element to the buffer to receive full packet. One byte in receive buffer is always empty */
    volatile uint8 Comm_rxBufferInternal[Comm_INTERNAL_RX_BUFFER_SIZE];
#endif /* (Comm_INTERNAL_RX_SW_BUFFER) */

#if(Comm_INTERNAL_TX_SW_BUFFER)
    volatile uint8 Comm_txBufferInternal[Comm_TX_BUFFER_SIZE];
#endif /* (Comm_INTERNAL_TX_SW_BUFFER) */


#if(Comm_RX_DIRECTION)
    /*******************************************************************************
    * Function Name: Comm_SpiUartReadRxData
    ****************************************************************************//**
    *
    *  Retrieves the next data element from the receive buffer.
    *   - RX software buffer is disabled: Returns data element retrieved from
    *     RX FIFO. Undefined data will be returned if the RX FIFO is empty.
    *   - RX software buffer is enabled: Returns data element from the software
    *     receive buffer. Zero value is returned if the software receive buffer
    *     is empty.
    *
    * \return
    *  Next data element from the receive buffer. 
    *  The amount of data bits to be received depends on RX data bits selection 
    *  (the data bit counting starts from LSB of return value).
    *
    * \globalvars
    *  Comm_rxBufferHead - the start index to put data into the 
    *  software receive buffer.
    *  Comm_rxBufferTail - the start index to get data from the 
    *  software receive buffer.
    *
    *******************************************************************************/
    uint32 Comm_SpiUartReadRxData(void)
    {
        uint32 rxData = 0u;

    #if (Comm_INTERNAL_RX_SW_BUFFER_CONST)
        uint32 locTail;
    #endif /* (Comm_INTERNAL_RX_SW_BUFFER_CONST) */

        if (Comm_CHECK_RX_SW_BUFFER)
        {
            if (Comm_rxBufferHead != Comm_rxBufferTail)
            {
                /* There is data in RX software buffer */

                /* Calculate index to read from */
                locTail = (Comm_rxBufferTail + 1u);

                if (Comm_INTERNAL_RX_BUFFER_SIZE == locTail)
                {
                    locTail = 0u;
                }

                /* Get data from RX software buffer */
                rxData = Comm_GetWordFromRxBuffer(locTail);

                /* Change index in the buffer */
                Comm_rxBufferTail = locTail;

                if (Comm_CHECK_UART_RTS_CONTROL_FLOW)
                {
                    /* Check if RX Not Empty is disabled in the interrupt */
                    if (0u == (Comm_INTR_RX_MASK_REG & Comm_INTR_RX_NOT_EMPTY))
                    {
                        /* Enable RX Not Empty interrupt source to continue
                        * receiving data into software buffer.
                        */
                        Comm_INTR_RX_MASK_REG |= Comm_INTR_RX_NOT_EMPTY;
                    }
                }
                

            }
        }
        else
        {
            /* Read data from RX FIFO */
            rxData = Comm_RX_FIFO_RD_REG;
        }
        

        return (rxData);
    }


    /*******************************************************************************
    * Function Name: Comm_SpiUartGetRxBufferSize
    ****************************************************************************//**
    *
    *  Returns the number of received data elements in the receive buffer.
    *   - RX software buffer disabled: returns the number of used entries in
    *     RX FIFO.
    *   - RX software buffer enabled: returns the number of elements which were
    *     placed in the receive buffer. This does not include the hardware RX FIFO.
    *
    * \return
    *  Number of received data elements.
    *
    * \globalvars
    *  Comm_rxBufferHead - the start index to put data into the 
    *  software receive buffer.
    *  Comm_rxBufferTail - the start index to get data from the 
    *  software receive buffer.
    *
    *******************************************************************************/
    uint32 Comm_SpiUartGetRxBufferSize(void)
    {
        uint32 size;
    #if (Comm_INTERNAL_RX_SW_BUFFER_CONST)
        uint32 locHead;
    #endif /* (Comm_INTERNAL_RX_SW_BUFFER_CONST) */

        if (Comm_CHECK_RX_SW_BUFFER)
        {
            locHead = Comm_rxBufferHead;

            if(locHead >= Comm_rxBufferTail)
            {
                size = (locHead - Comm_rxBufferTail);
            }
            else
            {
                size = (locHead + (Comm_INTERNAL_RX_BUFFER_SIZE - Comm_rxBufferTail));
            }
        }
        else
        {
            size = Comm_GET_RX_FIFO_ENTRIES;
        }
        

        return (size);
    }


    /*******************************************************************************
    * Function Name: Comm_SpiUartClearRxBuffer
    ****************************************************************************//**
    *
    *  Clears the receive buffer and RX FIFO.
    *
    * \globalvars
    *  Comm_rxBufferHead - the start index to put data into the 
    *  software receive buffer.
    *  Comm_rxBufferTail - the start index to get data from the 
    *  software receive buffer.
    *
    *******************************************************************************/
    void Comm_SpiUartClearRxBuffer(void)
    {
        if (Comm_CHECK_RX_SW_BUFFER)
        {
            /* Lock from component interruption */
            Comm_DisableInt();

            /* Flush RX software buffer */
            Comm_rxBufferHead = Comm_rxBufferTail;
            Comm_rxBufferOverflow = 0u;

            Comm_CLEAR_RX_FIFO;
            Comm_ClearRxInterruptSource(Comm_INTR_RX_ALL);

            if (Comm_CHECK_UART_RTS_CONTROL_FLOW)
            {
                /* Enable RX Not Empty interrupt source to continue receiving
                * data into software buffer.
                */
                Comm_INTR_RX_MASK_REG |= Comm_INTR_RX_NOT_EMPTY;
            }
            
            
            /* Release lock */
            Comm_EnableInt();
        }
        else
        {
            Comm_CLEAR_RX_FIFO;
        }
        
    }

#endif /* (Comm_RX_DIRECTION) */


#if(Comm_TX_DIRECTION)
    /*******************************************************************************
    * Function Name: Comm_SpiUartWriteTxData
    ****************************************************************************//**
    *
    *  Places a data entry into the transmit buffer to be sent at the next available
    *  bus time.
    *  This function is blocking and waits until there is space available to put the
    *  requested data in the transmit buffer.
    *
    *  \param txDataByte: the data to be transmitted.
    *   The amount of data bits to be transmitted depends on TX data bits selection 
    *   (the data bit counting starts from LSB of txDataByte).
    *
    * \globalvars
    *  Comm_txBufferHead - the start index to put data into the 
    *  software transmit buffer.
    *  Comm_txBufferTail - start index to get data from the software
    *  transmit buffer.
    *
    *******************************************************************************/
    void Comm_SpiUartWriteTxData(uint32 txData)
    {
    #if (Comm_INTERNAL_TX_SW_BUFFER_CONST)
        uint32 locHead;
    #endif /* (Comm_INTERNAL_TX_SW_BUFFER_CONST) */

        if (Comm_CHECK_TX_SW_BUFFER)
        {
            /* Put data directly into the TX FIFO */
            if ((Comm_txBufferHead == Comm_txBufferTail) &&
                (Comm_SPI_UART_FIFO_SIZE != Comm_GET_TX_FIFO_ENTRIES))
            {
                /* TX software buffer is empty: put data directly in TX FIFO */
                Comm_TX_FIFO_WR_REG = txData;
            }
            /* Put data into TX software buffer */
            else
            {
                /* Head index to put data */
                locHead = (Comm_txBufferHead + 1u);

                /* Adjust TX software buffer index */
                if (Comm_TX_BUFFER_SIZE == locHead)
                {
                    locHead = 0u;
                }

                /* Wait for space in TX software buffer */
                while (locHead == Comm_txBufferTail)
                {
                }

                /* TX software buffer has at least one room */

                /* Clear old status of INTR_TX_NOT_FULL. It sets at the end of transfer when TX FIFO is empty. */
                Comm_ClearTxInterruptSource(Comm_INTR_TX_NOT_FULL);

                Comm_PutWordInTxBuffer(locHead, txData);

                Comm_txBufferHead = locHead;

                /* Check if TX Not Full is disabled in interrupt */
                if (0u == (Comm_INTR_TX_MASK_REG & Comm_INTR_TX_NOT_FULL))
                {
                    /* Enable TX Not Full interrupt source to transmit from software buffer */
                    Comm_INTR_TX_MASK_REG |= (uint32) Comm_INTR_TX_NOT_FULL;
                }
            }
        }
        else
        {
            /* Wait until TX FIFO has space to put data element */
            while (Comm_SPI_UART_FIFO_SIZE == Comm_GET_TX_FIFO_ENTRIES)
            {
            }

            Comm_TX_FIFO_WR_REG = txData;
        }
        
    }


    /*******************************************************************************
    * Function Name: Comm_SpiUartPutArray
    ****************************************************************************//**
    *
    *  Places an array of data into the transmit buffer to be sent.
    *  This function is blocking and waits until there is a space available to put
    *  all the requested data in the transmit buffer. The array size can be greater
    *  than transmit buffer size.
    *
    * \param wrBuf: pointer to an array of data to be placed in transmit buffer. 
    *  The width of the data to be transmitted depends on TX data width selection 
    *  (the data bit counting starts from LSB for each array element).
    * \param count: number of data elements to be placed in the transmit buffer.
    *
    * \globalvars
    *  Comm_txBufferHead - the start index to put data into the 
    *  software transmit buffer.
    *  Comm_txBufferTail - start index to get data from the software
    *  transmit buffer.
    *
    *******************************************************************************/
    void Comm_SpiUartPutArray(const uint8 wrBuf[], uint32 count)
    {
        uint32 i;

        for (i=0u; i < count; i++)
        {
            Comm_SpiUartWriteTxData((uint32) wrBuf[i]);
        }
    }


    /*******************************************************************************
    * Function Name: Comm_SpiUartGetTxBufferSize
    ****************************************************************************//**
    *
    *  Returns the number of elements currently in the transmit buffer.
    *   - TX software buffer is disabled: returns the number of used entries in
    *     TX FIFO.
    *   - TX software buffer is enabled: returns the number of elements currently
    *     used in the transmit buffer. This number does not include used entries in
    *     the TX FIFO. The transmit buffer size is zero until the TX FIFO is
    *     not full.
    *
    * \return
    *  Number of data elements ready to transmit.
    *
    * \globalvars
    *  Comm_txBufferHead - the start index to put data into the 
    *  software transmit buffer.
    *  Comm_txBufferTail - start index to get data from the software
    *  transmit buffer.
    *
    *******************************************************************************/
    uint32 Comm_SpiUartGetTxBufferSize(void)
    {
        uint32 size;
    #if (Comm_INTERNAL_TX_SW_BUFFER_CONST)
        uint32 locTail;
    #endif /* (Comm_INTERNAL_TX_SW_BUFFER_CONST) */

        if (Comm_CHECK_TX_SW_BUFFER)
        {
            /* Get current Tail index */
            locTail = Comm_txBufferTail;

            if (Comm_txBufferHead >= locTail)
            {
                size = (Comm_txBufferHead - locTail);
            }
            else
            {
                size = (Comm_txBufferHead + (Comm_TX_BUFFER_SIZE - locTail));
            }
        }
        else
        {
            size = Comm_GET_TX_FIFO_ENTRIES;
        }
        

        return (size);
    }


    /*******************************************************************************
    * Function Name: Comm_SpiUartClearTxBuffer
    ****************************************************************************//**
    *
    *  Clears the transmit buffer and TX FIFO.
    *
    * \globalvars
    *  Comm_txBufferHead - the start index to put data into the 
    *  software transmit buffer.
    *  Comm_txBufferTail - start index to get data from the software
    *  transmit buffer.
    *
    *******************************************************************************/
    void Comm_SpiUartClearTxBuffer(void)
    {
        if (Comm_CHECK_TX_SW_BUFFER)
        {
            /* Lock from component interruption */
            Comm_DisableInt();

            /* Flush TX software buffer */
            Comm_txBufferHead = Comm_txBufferTail;

            Comm_INTR_TX_MASK_REG &= (uint32) ~Comm_INTR_TX_NOT_FULL;
            Comm_CLEAR_TX_FIFO;
            Comm_ClearTxInterruptSource(Comm_INTR_TX_ALL);

            /* Release lock */
            Comm_EnableInt();
        }
        else
        {
            Comm_CLEAR_TX_FIFO;
        }
        
    }

#endif /* (Comm_TX_DIRECTION) */


/*******************************************************************************
* Function Name: Comm_SpiUartDisableIntRx
****************************************************************************//**
*
*  Disables the RX interrupt sources.
*
*  \return
*   Returns the RX interrupt sources enabled before the function call.
*
*******************************************************************************/
uint32 Comm_SpiUartDisableIntRx(void)
{
    uint32 intSource;

    intSource = Comm_GetRxInterruptMode();

    Comm_SetRxInterruptMode(Comm_NO_INTR_SOURCES);

    return (intSource);
}


/*******************************************************************************
* Function Name: Comm_SpiUartDisableIntTx
****************************************************************************//**
*
*  Disables TX interrupt sources.
*
*  \return
*   Returns TX interrupt sources enabled before function call.
*
*******************************************************************************/
uint32 Comm_SpiUartDisableIntTx(void)
{
    uint32 intSourceMask;

    intSourceMask = Comm_GetTxInterruptMode();

    Comm_SetTxInterruptMode(Comm_NO_INTR_SOURCES);

    return (intSourceMask);
}


#if(Comm_SCB_MODE_UNCONFIG_CONST_CFG)
    /*******************************************************************************
    * Function Name: Comm_PutWordInRxBuffer
    ****************************************************************************//**
    *
    *  Stores a byte/word into the RX buffer.
    *  Only available in the Unconfigured operation mode.
    *
    *  \param index:      index to store data byte/word in the RX buffer.
    *  \param rxDataByte: byte/word to store.
    *
    *******************************************************************************/
    void Comm_PutWordInRxBuffer(uint32 idx, uint32 rxDataByte)
    {
        /* Put data in buffer */
        if (Comm_ONE_BYTE_WIDTH == Comm_rxDataBits)
        {
            Comm_rxBuffer[idx] = ((uint8) rxDataByte);
        }
        else
        {
            Comm_rxBuffer[(uint32)(idx << 1u)]      = LO8(LO16(rxDataByte));
            Comm_rxBuffer[(uint32)(idx << 1u) + 1u] = HI8(LO16(rxDataByte));
        }
    }


    /*******************************************************************************
    * Function Name: Comm_GetWordFromRxBuffer
    ****************************************************************************//**
    *
    *  Reads byte/word from RX buffer.
    *  Only available in the Unconfigured operation mode.
    *
    *  \return
    *   Returns byte/word read from RX buffer.
    *
    *******************************************************************************/
    uint32 Comm_GetWordFromRxBuffer(uint32 idx)
    {
        uint32 value;

        if (Comm_ONE_BYTE_WIDTH == Comm_rxDataBits)
        {
            value = Comm_rxBuffer[idx];
        }
        else
        {
            value  = (uint32) Comm_rxBuffer[(uint32)(idx << 1u)];
            value |= (uint32) ((uint32)Comm_rxBuffer[(uint32)(idx << 1u) + 1u] << 8u);
        }

        return (value);
    }


    /*******************************************************************************
    * Function Name: Comm_PutWordInTxBuffer
    ****************************************************************************//**
    *
    *  Stores byte/word into the TX buffer.
    *  Only available in the Unconfigured operation mode.
    *
    *  \param idx:        index to store data byte/word in the TX buffer.
    *  \param txDataByte: byte/word to store.
    *
    *******************************************************************************/
    void Comm_PutWordInTxBuffer(uint32 idx, uint32 txDataByte)
    {
        /* Put data in buffer */
        if (Comm_ONE_BYTE_WIDTH == Comm_txDataBits)
        {
            Comm_txBuffer[idx] = ((uint8) txDataByte);
        }
        else
        {
            Comm_txBuffer[(uint32)(idx << 1u)]      = LO8(LO16(txDataByte));
            Comm_txBuffer[(uint32)(idx << 1u) + 1u] = HI8(LO16(txDataByte));
        }
    }


    /*******************************************************************************
    * Function Name: Comm_GetWordFromTxBuffer
    ****************************************************************************//**
    *
    *  Reads byte/word from the TX buffer.
    *  Only available in the Unconfigured operation mode.
    *
    *  \param idx: index to get data byte/word from the TX buffer.
    *
    *  \return
    *   Returns byte/word read from the TX buffer.
    *
    *******************************************************************************/
    uint32 Comm_GetWordFromTxBuffer(uint32 idx)
    {
        uint32 value;

        if (Comm_ONE_BYTE_WIDTH == Comm_txDataBits)
        {
            value = (uint32) Comm_txBuffer[idx];
        }
        else
        {
            value  = (uint32) Comm_txBuffer[(uint32)(idx << 1u)];
            value |= (uint32) ((uint32) Comm_txBuffer[(uint32)(idx << 1u) + 1u] << 8u);
        }

        return (value);
    }

#endif /* (Comm_SCB_MODE_UNCONFIG_CONST_CFG) */


/* [] END OF FILE */
