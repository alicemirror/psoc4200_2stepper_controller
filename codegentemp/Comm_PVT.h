/***************************************************************************//**
* \file .h
* \version 3.20
*
* \brief
*  This private file provides constants and parameter values for the
*  SCB Component.
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

#if !defined(CY_SCB_PVT_Comm_H)
#define CY_SCB_PVT_Comm_H

#include "Comm.h"


/***************************************
*     Private Function Prototypes
***************************************/

/* APIs to service INTR_I2C_EC register */
#define Comm_SetI2CExtClkInterruptMode(interruptMask) Comm_WRITE_INTR_I2C_EC_MASK(interruptMask)
#define Comm_ClearI2CExtClkInterruptSource(interruptMask) Comm_CLEAR_INTR_I2C_EC(interruptMask)
#define Comm_GetI2CExtClkInterruptSource()                (Comm_INTR_I2C_EC_REG)
#define Comm_GetI2CExtClkInterruptMode()                  (Comm_INTR_I2C_EC_MASK_REG)
#define Comm_GetI2CExtClkInterruptSourceMasked()          (Comm_INTR_I2C_EC_MASKED_REG)

#if (!Comm_CY_SCBIP_V1)
    /* APIs to service INTR_SPI_EC register */
    #define Comm_SetSpiExtClkInterruptMode(interruptMask) \
                                                                Comm_WRITE_INTR_SPI_EC_MASK(interruptMask)
    #define Comm_ClearSpiExtClkInterruptSource(interruptMask) \
                                                                Comm_CLEAR_INTR_SPI_EC(interruptMask)
    #define Comm_GetExtSpiClkInterruptSource()                 (Comm_INTR_SPI_EC_REG)
    #define Comm_GetExtSpiClkInterruptMode()                   (Comm_INTR_SPI_EC_MASK_REG)
    #define Comm_GetExtSpiClkInterruptSourceMasked()           (Comm_INTR_SPI_EC_MASKED_REG)
#endif /* (!Comm_CY_SCBIP_V1) */

#if(Comm_SCB_MODE_UNCONFIG_CONST_CFG)
    extern void Comm_SetPins(uint32 mode, uint32 subMode, uint32 uartEnableMask);
#endif /* (Comm_SCB_MODE_UNCONFIG_CONST_CFG) */


/***************************************
*     Vars with External Linkage
***************************************/

#if (Comm_SCB_IRQ_INTERNAL)
#if !defined (CY_REMOVE_Comm_CUSTOM_INTR_HANDLER)
    extern cyisraddress Comm_customIntrHandler;
#endif /* !defined (CY_REMOVE_Comm_CUSTOM_INTR_HANDLER) */
#endif /* (Comm_SCB_IRQ_INTERNAL) */

extern Comm_BACKUP_STRUCT Comm_backup;

#if(Comm_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Common configuration variables */
    extern uint8 Comm_scbMode;
    extern uint8 Comm_scbEnableWake;
    extern uint8 Comm_scbEnableIntr;

    /* I2C configuration variables */
    extern uint8 Comm_mode;
    extern uint8 Comm_acceptAddr;

    /* SPI/UART configuration variables */
    extern volatile uint8 * Comm_rxBuffer;
    extern uint8   Comm_rxDataBits;
    extern uint32  Comm_rxBufferSize;

    extern volatile uint8 * Comm_txBuffer;
    extern uint8   Comm_txDataBits;
    extern uint32  Comm_txBufferSize;

    /* EZI2C configuration variables */
    extern uint8 Comm_numberOfAddr;
    extern uint8 Comm_subAddrSize;
#endif /* (Comm_SCB_MODE_UNCONFIG_CONST_CFG) */

#if (! (Comm_SCB_MODE_I2C_CONST_CFG || \
        Comm_SCB_MODE_EZI2C_CONST_CFG))
    extern uint16 Comm_IntrTxMask;
#endif /* (! (Comm_SCB_MODE_I2C_CONST_CFG || \
              Comm_SCB_MODE_EZI2C_CONST_CFG)) */


/***************************************
*        Conditional Macro
****************************************/

#if(Comm_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Defines run time operation mode */
    #define Comm_SCB_MODE_I2C_RUNTM_CFG     (Comm_SCB_MODE_I2C      == Comm_scbMode)
    #define Comm_SCB_MODE_SPI_RUNTM_CFG     (Comm_SCB_MODE_SPI      == Comm_scbMode)
    #define Comm_SCB_MODE_UART_RUNTM_CFG    (Comm_SCB_MODE_UART     == Comm_scbMode)
    #define Comm_SCB_MODE_EZI2C_RUNTM_CFG   (Comm_SCB_MODE_EZI2C    == Comm_scbMode)
    #define Comm_SCB_MODE_UNCONFIG_RUNTM_CFG \
                                                        (Comm_SCB_MODE_UNCONFIG == Comm_scbMode)

    /* Defines wakeup enable */
    #define Comm_SCB_WAKE_ENABLE_CHECK       (0u != Comm_scbEnableWake)
#endif /* (Comm_SCB_MODE_UNCONFIG_CONST_CFG) */

/* Defines maximum number of SCB pins */
#if (!Comm_CY_SCBIP_V1)
    #define Comm_SCB_PINS_NUMBER    (7u)
#else
    #define Comm_SCB_PINS_NUMBER    (2u)
#endif /* (!Comm_CY_SCBIP_V1) */

#endif /* (CY_SCB_PVT_Comm_H) */


/* [] END OF FILE */
