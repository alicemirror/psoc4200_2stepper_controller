/*******************************************************************************
* File Name: .h
* Version 1.0
*
* Description:
*  This file provides private constants and parameter values for the I2C
*  component.
*
* Note:
*
********************************************************************************
* Copyright 2012, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_I2C_PVT_SCB_1_H)
#define CY_SCB_I2C_PVT_SCB_1_H

#include "SCB_1_I2C.h"

extern volatile uint8 SCB_1_state;          /* Current state of I2C FSM         */
extern volatile uint8 SCB_1_wakeupSource;   /* Defines if I2C was wakeup source */

/* Master variables */
#if(SCB_1_I2C_MASTER_CONST)
    extern volatile uint16 SCB_1_mstrStatus;        /* Master Status byte            */
    extern volatile uint8  SCB_1_mstrControl;       /* Master Control byte           */

    /* Transmit buffer variables */
    extern volatile uint8 * SCB_1_mstrRdBufPtr;     /* Pointer to Master Read buffer  */
    extern volatile uint32  SCB_1_mstrRdBufSize;    /* Master Read buffer size        */
    extern volatile uint32  SCB_1_mstrRdBufIndex;   /* Master Read buffer Index       */

    /* Receive buffer variables */
    extern volatile uint8 * SCB_1_mstrWrBufPtr;     /* Pointer to Master Write buffer */
    extern volatile uint32  SCB_1_mstrWrBufSize;    /* Master Write buffer size       */
    extern volatile uint32  SCB_1_mstrWrBufIndex;   /* Master Write buffer Index      */
#endif /* (SCB_1_I2C_MASTER_CONST) */

#if(SCB_1_I2C_SLAVE_CONST)
    extern volatile uint8 SCB_1_slStatus;       /* Slave Status                */

    /* Transmit buffer variables */
    extern volatile uint8 * SCB_1_slRdBufPtr;   /* Pointer to Transmit buffer  */
    extern volatile uint32  SCB_1_slRdBufSize;  /* Slave Transmit buffer size  */
    extern volatile uint32  SCB_1_slRdBufIndex; /* Slave Transmit buffer Index */

    /* Receive buffer variables */
    extern volatile uint8 * SCB_1_slWrBufPtr;   /* Pointer to Receive buffer   */
    extern volatile uint32  SCB_1_slWrBufSize;  /* Slave Receive buffer size   */
    extern volatile uint32  SCB_1_slWrBufIndex; /* Slave Receive buffer Index  */
    extern volatile uint32  SCB_1_slOverFlowCount;  /* Slave Transmit Overflow counter */
#endif /* (SCB_1_I2C_SLAVE_CONST) */

#endif /* (CY_SCB_I2C_PVT_SCB_1_H) */


/* [] END OF FILE */
