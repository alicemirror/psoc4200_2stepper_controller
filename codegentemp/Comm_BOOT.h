/***************************************************************************//**
* \file Comm_BOOT.h
* \version 3.20
*
* \brief
*  This file provides constants and parameter values of the bootloader
*  communication APIs for the SCB Component.
*
* Note:
*
********************************************************************************
* \copyright
* Copyright 2014-2016, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_BOOT_Comm_H)
#define CY_SCB_BOOT_Comm_H

#include "Comm_PVT.h"

#if (Comm_SCB_MODE_I2C_INC)
    #include "Comm_I2C.h"
#endif /* (Comm_SCB_MODE_I2C_INC) */

#if (Comm_SCB_MODE_EZI2C_INC)
    #include "Comm_EZI2C.h"
#endif /* (Comm_SCB_MODE_EZI2C_INC) */

#if (Comm_SCB_MODE_SPI_INC || Comm_SCB_MODE_UART_INC)
    #include "Comm_SPI_UART.h"
#endif /* (Comm_SCB_MODE_SPI_INC || Comm_SCB_MODE_UART_INC) */


/***************************************
*  Conditional Compilation Parameters
****************************************/

/* Bootloader communication interface enable */
#define Comm_BTLDR_COMM_ENABLED ((CYDEV_BOOTLOADER_IO_COMP == CyBtldr_Comm) || \
                                             (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_Custom_Interface))

/* Enable I2C bootloader communication */
#if (Comm_SCB_MODE_I2C_INC)
    #define Comm_I2C_BTLDR_COMM_ENABLED     (Comm_BTLDR_COMM_ENABLED && \
                                                            (Comm_SCB_MODE_UNCONFIG_CONST_CFG || \
                                                             Comm_I2C_SLAVE_CONST))
#else
     #define Comm_I2C_BTLDR_COMM_ENABLED    (0u)
#endif /* (Comm_SCB_MODE_I2C_INC) */

/* EZI2C does not support bootloader communication. Provide empty APIs */
#if (Comm_SCB_MODE_EZI2C_INC)
    #define Comm_EZI2C_BTLDR_COMM_ENABLED   (Comm_BTLDR_COMM_ENABLED && \
                                                         Comm_SCB_MODE_UNCONFIG_CONST_CFG)
#else
    #define Comm_EZI2C_BTLDR_COMM_ENABLED   (0u)
#endif /* (Comm_EZI2C_BTLDR_COMM_ENABLED) */

/* Enable SPI bootloader communication */
#if (Comm_SCB_MODE_SPI_INC)
    #define Comm_SPI_BTLDR_COMM_ENABLED     (Comm_BTLDR_COMM_ENABLED && \
                                                            (Comm_SCB_MODE_UNCONFIG_CONST_CFG || \
                                                             Comm_SPI_SLAVE_CONST))
#else
        #define Comm_SPI_BTLDR_COMM_ENABLED (0u)
#endif /* (Comm_SPI_BTLDR_COMM_ENABLED) */

/* Enable UART bootloader communication */
#if (Comm_SCB_MODE_UART_INC)
       #define Comm_UART_BTLDR_COMM_ENABLED    (Comm_BTLDR_COMM_ENABLED && \
                                                            (Comm_SCB_MODE_UNCONFIG_CONST_CFG || \
                                                             (Comm_UART_RX_DIRECTION && \
                                                              Comm_UART_TX_DIRECTION)))
#else
     #define Comm_UART_BTLDR_COMM_ENABLED   (0u)
#endif /* (Comm_UART_BTLDR_COMM_ENABLED) */

/* Enable bootloader communication */
#define Comm_BTLDR_COMM_MODE_ENABLED    (Comm_I2C_BTLDR_COMM_ENABLED   || \
                                                     Comm_SPI_BTLDR_COMM_ENABLED   || \
                                                     Comm_EZI2C_BTLDR_COMM_ENABLED || \
                                                     Comm_UART_BTLDR_COMM_ENABLED)


/***************************************
*        Function Prototypes
***************************************/

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (Comm_I2C_BTLDR_COMM_ENABLED)
    /* I2C Bootloader physical layer functions */
    void Comm_I2CCyBtldrCommStart(void);
    void Comm_I2CCyBtldrCommStop (void);
    void Comm_I2CCyBtldrCommReset(void);
    cystatus Comm_I2CCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus Comm_I2CCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

    /* Map I2C specific bootloader communication APIs to SCB specific APIs */
    #if (Comm_SCB_MODE_I2C_CONST_CFG)
        #define Comm_CyBtldrCommStart   Comm_I2CCyBtldrCommStart
        #define Comm_CyBtldrCommStop    Comm_I2CCyBtldrCommStop
        #define Comm_CyBtldrCommReset   Comm_I2CCyBtldrCommReset
        #define Comm_CyBtldrCommRead    Comm_I2CCyBtldrCommRead
        #define Comm_CyBtldrCommWrite   Comm_I2CCyBtldrCommWrite
    #endif /* (Comm_SCB_MODE_I2C_CONST_CFG) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (Comm_I2C_BTLDR_COMM_ENABLED) */


#if defined(CYDEV_BOOTLOADER_IO_COMP) && (Comm_EZI2C_BTLDR_COMM_ENABLED)
    /* Bootloader physical layer functions */
    void Comm_EzI2CCyBtldrCommStart(void);
    void Comm_EzI2CCyBtldrCommStop (void);
    void Comm_EzI2CCyBtldrCommReset(void);
    cystatus Comm_EzI2CCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus Comm_EzI2CCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

    /* Map EZI2C specific bootloader communication APIs to SCB specific APIs */
    #if (Comm_SCB_MODE_EZI2C_CONST_CFG)
        #define Comm_CyBtldrCommStart   Comm_EzI2CCyBtldrCommStart
        #define Comm_CyBtldrCommStop    Comm_EzI2CCyBtldrCommStop
        #define Comm_CyBtldrCommReset   Comm_EzI2CCyBtldrCommReset
        #define Comm_CyBtldrCommRead    Comm_EzI2CCyBtldrCommRead
        #define Comm_CyBtldrCommWrite   Comm_EzI2CCyBtldrCommWrite
    #endif /* (Comm_SCB_MODE_EZI2C_CONST_CFG) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (Comm_EZI2C_BTLDR_COMM_ENABLED) */

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (Comm_SPI_BTLDR_COMM_ENABLED)
    /* SPI Bootloader physical layer functions */
    void Comm_SpiCyBtldrCommStart(void);
    void Comm_SpiCyBtldrCommStop (void);
    void Comm_SpiCyBtldrCommReset(void);
    cystatus Comm_SpiCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus Comm_SpiCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

    /* Map SPI specific bootloader communication APIs to SCB specific APIs */
    #if (Comm_SCB_MODE_SPI_CONST_CFG)
        #define Comm_CyBtldrCommStart   Comm_SpiCyBtldrCommStart
        #define Comm_CyBtldrCommStop    Comm_SpiCyBtldrCommStop
        #define Comm_CyBtldrCommReset   Comm_SpiCyBtldrCommReset
        #define Comm_CyBtldrCommRead    Comm_SpiCyBtldrCommRead
        #define Comm_CyBtldrCommWrite   Comm_SpiCyBtldrCommWrite
    #endif /* (Comm_SCB_MODE_SPI_CONST_CFG) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (Comm_SPI_BTLDR_COMM_ENABLED) */

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (Comm_UART_BTLDR_COMM_ENABLED)
    /* UART Bootloader physical layer functions */
    void Comm_UartCyBtldrCommStart(void);
    void Comm_UartCyBtldrCommStop (void);
    void Comm_UartCyBtldrCommReset(void);
    cystatus Comm_UartCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus Comm_UartCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

    /* Map UART specific bootloader communication APIs to SCB specific APIs */
    #if (Comm_SCB_MODE_UART_CONST_CFG)
        #define Comm_CyBtldrCommStart   Comm_UartCyBtldrCommStart
        #define Comm_CyBtldrCommStop    Comm_UartCyBtldrCommStop
        #define Comm_CyBtldrCommReset   Comm_UartCyBtldrCommReset
        #define Comm_CyBtldrCommRead    Comm_UartCyBtldrCommRead
        #define Comm_CyBtldrCommWrite   Comm_UartCyBtldrCommWrite
    #endif /* (Comm_SCB_MODE_UART_CONST_CFG) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (Comm_UART_BTLDR_COMM_ENABLED) */

/**
* \addtogroup group_bootloader
* @{
*/

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (Comm_BTLDR_COMM_ENABLED)
    #if (Comm_SCB_MODE_UNCONFIG_CONST_CFG)
        /* Bootloader physical layer functions */
        void Comm_CyBtldrCommStart(void);
        void Comm_CyBtldrCommStop (void);
        void Comm_CyBtldrCommReset(void);
        cystatus Comm_CyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
        cystatus Comm_CyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    #endif /* (Comm_SCB_MODE_UNCONFIG_CONST_CFG) */

    /* Map SCB specific bootloader communication APIs to common APIs */
    #if (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_Comm)
        #define CyBtldrCommStart    Comm_CyBtldrCommStart
        #define CyBtldrCommStop     Comm_CyBtldrCommStop
        #define CyBtldrCommReset    Comm_CyBtldrCommReset
        #define CyBtldrCommWrite    Comm_CyBtldrCommWrite
        #define CyBtldrCommRead     Comm_CyBtldrCommRead
    #endif /* (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_Comm) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (Comm_BTLDR_COMM_ENABLED) */

/** @} group_bootloader */

/***************************************
*           API Constants
***************************************/

/* Timeout unit in milliseconds */
#define Comm_WAIT_1_MS  (1u)

/* Return number of bytes to copy into bootloader buffer */
#define Comm_BYTES_TO_COPY(actBufSize, bufSize) \
                            ( ((uint32)(actBufSize) < (uint32)(bufSize)) ? \
                                ((uint32) (actBufSize)) : ((uint32) (bufSize)) )

/* Size of Read/Write buffers for I2C bootloader  */
#define Comm_I2C_BTLDR_SIZEOF_READ_BUFFER   (64u)
#define Comm_I2C_BTLDR_SIZEOF_WRITE_BUFFER  (64u)

/* Byte to byte time interval: calculated basing on current component
* data rate configuration, can be defined in project if required.
*/
#ifndef Comm_SPI_BYTE_TO_BYTE
    #define Comm_SPI_BYTE_TO_BYTE   (160u)
#endif

/* Byte to byte time interval: calculated basing on current component
* baud rate configuration, can be defined in the project if required.
*/
#ifndef Comm_UART_BYTE_TO_BYTE
    #define Comm_UART_BYTE_TO_BYTE  (2500u)
#endif /* Comm_UART_BYTE_TO_BYTE */

#endif /* (CY_SCB_BOOT_Comm_H) */


/* [] END OF FILE */
