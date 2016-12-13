/***************************************************************************//**
* \file .h
* \version 3.20
*
* \brief
*  This private file provides constants and parameter values for the
*  SCB Component in I2C mode.
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

#if !defined(CY_SCB_I2C_PVT_Comm_H)
#define CY_SCB_I2C_PVT_Comm_H

#include "Comm_I2C.h"


/***************************************
*     Private Global Vars
***************************************/

extern volatile uint8 Comm_state; /* Current state of I2C FSM */

#if(Comm_I2C_SLAVE_CONST)
    extern volatile uint8 Comm_slStatus;          /* Slave Status */

    /* Receive buffer variables */
    extern volatile uint8 * Comm_slWrBufPtr;      /* Pointer to Receive buffer  */
    extern volatile uint32  Comm_slWrBufSize;     /* Slave Receive buffer size  */
    extern volatile uint32  Comm_slWrBufIndex;    /* Slave Receive buffer Index */

    /* Transmit buffer variables */
    extern volatile uint8 * Comm_slRdBufPtr;      /* Pointer to Transmit buffer  */
    extern volatile uint32  Comm_slRdBufSize;     /* Slave Transmit buffer size  */
    extern volatile uint32  Comm_slRdBufIndex;    /* Slave Transmit buffer Index */
    extern volatile uint32  Comm_slRdBufIndexTmp; /* Slave Transmit buffer Index Tmp */
    extern volatile uint8   Comm_slOverFlowCount; /* Slave Transmit Overflow counter */
#endif /* (Comm_I2C_SLAVE_CONST) */

#if(Comm_I2C_MASTER_CONST)
    extern volatile uint16 Comm_mstrStatus;      /* Master Status byte  */
    extern volatile uint8  Comm_mstrControl;     /* Master Control byte */

    /* Receive buffer variables */
    extern volatile uint8 * Comm_mstrRdBufPtr;   /* Pointer to Master Read buffer */
    extern volatile uint32  Comm_mstrRdBufSize;  /* Master Read buffer size       */
    extern volatile uint32  Comm_mstrRdBufIndex; /* Master Read buffer Index      */

    /* Transmit buffer variables */
    extern volatile uint8 * Comm_mstrWrBufPtr;   /* Pointer to Master Write buffer */
    extern volatile uint32  Comm_mstrWrBufSize;  /* Master Write buffer size       */
    extern volatile uint32  Comm_mstrWrBufIndex; /* Master Write buffer Index      */
    extern volatile uint32  Comm_mstrWrBufIndexTmp; /* Master Write buffer Index Tmp */
#endif /* (Comm_I2C_MASTER_CONST) */

#if (Comm_I2C_CUSTOM_ADDRESS_HANDLER_CONST)
    extern uint32 (*Comm_customAddressHandler) (void);
#endif /* (Comm_I2C_CUSTOM_ADDRESS_HANDLER_CONST) */

/***************************************
*     Private Function Prototypes
***************************************/

#if(Comm_SCB_MODE_I2C_CONST_CFG)
    void Comm_I2CInit(void);
#endif /* (Comm_SCB_MODE_I2C_CONST_CFG) */

void Comm_I2CStop(void);
void Comm_I2CSaveConfig(void);
void Comm_I2CRestoreConfig(void);

#if(Comm_I2C_MASTER_CONST)
    void Comm_I2CReStartGeneration(void);
#endif /* (Comm_I2C_MASTER_CONST) */

#endif /* (CY_SCB_I2C_PVT_Comm_H) */


/* [] END OF FILE */
