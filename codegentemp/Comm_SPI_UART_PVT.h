/***************************************************************************//**
* \file Comm_SPI_UART_PVT.h
* \version 3.20
*
* \brief
*  This private file provides constants and parameter values for the
*  SCB Component in SPI and UART modes.
*  Please do not use this file or its content in your project.
*
* Note:
*
********************************************************************************
* \copyright
* Copyright 2013-2016, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_SPI_UART_PVT_Comm_H)
#define CY_SCB_SPI_UART_PVT_Comm_H

#include "Comm_SPI_UART.h"


/***************************************
*     Internal Global Vars
***************************************/

#if (Comm_INTERNAL_RX_SW_BUFFER_CONST)
    extern volatile uint32  Comm_rxBufferHead;
    extern volatile uint32  Comm_rxBufferTail;
    
    /**
    * \addtogroup group_globals
    * @{
    */
    
    /** Sets when internal software receive buffer overflow
     *  was occurred.
    */  
    extern volatile uint8   Comm_rxBufferOverflow;
    /** @} globals */
#endif /* (Comm_INTERNAL_RX_SW_BUFFER_CONST) */

#if (Comm_INTERNAL_TX_SW_BUFFER_CONST)
    extern volatile uint32  Comm_txBufferHead;
    extern volatile uint32  Comm_txBufferTail;
#endif /* (Comm_INTERNAL_TX_SW_BUFFER_CONST) */

#if (Comm_INTERNAL_RX_SW_BUFFER)
    extern volatile uint8 Comm_rxBufferInternal[Comm_INTERNAL_RX_BUFFER_SIZE];
#endif /* (Comm_INTERNAL_RX_SW_BUFFER) */

#if (Comm_INTERNAL_TX_SW_BUFFER)
    extern volatile uint8 Comm_txBufferInternal[Comm_TX_BUFFER_SIZE];
#endif /* (Comm_INTERNAL_TX_SW_BUFFER) */


/***************************************
*     Private Function Prototypes
***************************************/

void Comm_SpiPostEnable(void);
void Comm_SpiStop(void);

#if (Comm_SCB_MODE_SPI_CONST_CFG)
    void Comm_SpiInit(void);
#endif /* (Comm_SCB_MODE_SPI_CONST_CFG) */

#if (Comm_SPI_WAKE_ENABLE_CONST)
    void Comm_SpiSaveConfig(void);
    void Comm_SpiRestoreConfig(void);
#endif /* (Comm_SPI_WAKE_ENABLE_CONST) */

void Comm_UartPostEnable(void);
void Comm_UartStop(void);

#if (Comm_SCB_MODE_UART_CONST_CFG)
    void Comm_UartInit(void);
#endif /* (Comm_SCB_MODE_UART_CONST_CFG) */

#if (Comm_UART_WAKE_ENABLE_CONST)
    void Comm_UartSaveConfig(void);
    void Comm_UartRestoreConfig(void);
#endif /* (Comm_UART_WAKE_ENABLE_CONST) */


/***************************************
*         UART API Constants
***************************************/

/* UART RX and TX position to be used in Comm_SetPins() */
#define Comm_UART_RX_PIN_ENABLE    (Comm_UART_RX)
#define Comm_UART_TX_PIN_ENABLE    (Comm_UART_TX)

/* UART RTS and CTS position to be used in  Comm_SetPins() */
#define Comm_UART_RTS_PIN_ENABLE    (0x10u)
#define Comm_UART_CTS_PIN_ENABLE    (0x20u)


/***************************************
* The following code is DEPRECATED and
* must not be used.
***************************************/

/* Interrupt processing */
#define Comm_SpiUartEnableIntRx(intSourceMask)  Comm_SetRxInterruptMode(intSourceMask)
#define Comm_SpiUartEnableIntTx(intSourceMask)  Comm_SetTxInterruptMode(intSourceMask)
uint32  Comm_SpiUartDisableIntRx(void);
uint32  Comm_SpiUartDisableIntTx(void);


#endif /* (CY_SCB_SPI_UART_PVT_Comm_H) */


/* [] END OF FILE */
