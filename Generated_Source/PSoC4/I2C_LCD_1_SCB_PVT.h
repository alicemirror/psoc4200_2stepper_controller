/*******************************************************************************
* File Name: .h
* Version 1.0
*
* Description:
*  This private file provides constants and parameter values for the
*  SCB Component in I2C mode.
*  Please do not use this file or its content in your project.
*
* Note:
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_PVT_I2C_LCD_1_SCB_H)
#define CY_SCB_PVT_I2C_LCD_1_SCB_H

#include "I2C_LCD_1_SCB.h"


/***************************************
*     Private Function Prototypes
***************************************/

#if(I2C_LCD_1_SCB_SCB_MODE_UNCONFIG_CONST_CFG)
    extern void I2C_LCD_1_SCB_SetPins(uint32 mode, uint32 subMode, uint32 UartTxRx);
#endif /* (I2C_LCD_1_SCB_SCB_MODE_UNCONFIG_CONST_CFG) */

#endif /* (CY_SCB_PVT_I2C_LCD_1_SCB_H) */


/* [] END OF FILE */
