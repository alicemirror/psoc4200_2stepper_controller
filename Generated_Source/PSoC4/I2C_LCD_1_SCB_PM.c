/*******************************************************************************
* File Name: I2C_LCD_1_SCB_PM.c
* Version 1.0
*
* Description:
*  This file provides the source code to the Power Management support for
*  the SCB Component.
*
* Note:
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "I2C_LCD_1_SCB.h"

#if(I2C_LCD_1_SCB_SCB_MODE_I2C_INC)
    #include "I2C_LCD_1_SCB_I2C_PVT.h"
#endif /* (I2C_LCD_1_SCB_SCB_MODE_I2C_INC) */

#if(I2C_LCD_1_SCB_SCB_MODE_SPI_INC || I2C_LCD_1_SCB_SCB_MODE_UART_INC)
    #include "I2C_LCD_1_SCB_SPI_UART_PVT.h"
#endif /* (I2C_LCD_1_SCB_SCB_MODE_SPI_INC || I2C_LCD_1_SCB_SCB_MODE_UART_INC) */

#if(I2C_LCD_1_SCB_SCB_MODE_EZBUF_I2C_INC || I2C_LCD_1_SCB_SCB_MODE_EZBUF_SPI_INC)
    #include "I2C_LCD_1_SCB_EZBUF_MODE_PVT.h"
#endif /* (I2C_LCD_1_SCB_SCB_MODE_EZBUF_I2C_INC || I2C_LCD_1_SCB_SCB_MODE_EZBUF_SPI_INC) */


/***************************************
*   Backup Structure declaration
***************************************/

I2C_LCD_1_SCB_BACKUP_STRUCT I2C_LCD_1_SCB_backup =
{
    0u, /* enableState */
};


/*******************************************************************************
* Function Name: I2C_LCD_1_SCB_Sleep
********************************************************************************
*
* Summary:
*  Calls SaveConfig function fucntion for selected mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void I2C_LCD_1_SCB_Sleep(void)
{
    I2C_LCD_1_SCB_backup.enableState = (uint8) I2C_LCD_1_SCB_GET_CTRL_ENABLED;

    #if(I2C_LCD_1_SCB_SCB_MODE_UNCONFIG_CONST_CFG)

        if(I2C_LCD_1_SCB_SCB_MODE_I2C_RUNTM_CFG)
        {
            I2C_LCD_1_SCB_I2CSaveConfig();
        }
        else if(I2C_LCD_1_SCB_SCB_MODE_SPI_RUNTM_CFG)
        {
            I2C_LCD_1_SCB_SpiSaveConfig();
        }
        else if(I2C_LCD_1_SCB_SCB_MODE_UART_RUNTM_CFG)
        {
            I2C_LCD_1_SCB_UartSaveConfig();
        }
        else if(I2C_LCD_1_SCB_SCB_MODE_EZBUF_I2C_RUNTM_CFG)
        {
            I2C_LCD_1_SCB_EzBufI2CSaveConfig();
        }
        else if(I2C_LCD_1_SCB_SCB_MODE_EZBUF_SPI_RUNTM_CFG)
        {
            I2C_LCD_1_SCB_EzBufSpiSaveConfig();
        }
        else
        {
            /* Unknown mode: do nothing */
        }

    #elif(I2C_LCD_1_SCB_SCB_MODE_I2C_CONST_CFG)
        I2C_LCD_1_SCB_I2CSaveConfig();

    #elif(I2C_LCD_1_SCB_SCB_MODE_SPI_CONST_CFG)
        I2C_LCD_1_SCB_SpiSaveConfig();

    #elif(I2C_LCD_1_SCB_SCB_MODE_UART_CONST_CFG)
        I2C_LCD_1_SCB_UartSaveConfig();

    #elif(I2C_LCD_1_SCB_SCB_MODE_EZBUF_I2C_CONST_CFG)
        I2C_LCD_1_SCB_EzBufI2CSaveConfig();

    #elif(I2C_LCD_1_SCB_SCB_MODE_EZBUF_SPI_CONST_CFG)
        I2C_LCD_1_SCB_EzBufSpiSaveConfig();

    #else
        /* Do nothing */

    #endif /* (I2C_LCD_1_SCB_SCB_MODE_UNCONFIG_CONST_CFG) */

    if(0u != I2C_LCD_1_SCB_backup.enableState)
    {
        I2C_LCD_1_SCB_Stop();
    }
}


/*******************************************************************************
* Function Name: I2C_LCD_1_SCB_Wakeup
********************************************************************************
*
* Summary:
*  Calls RestoreConfig function fucntion for selected mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void I2C_LCD_1_SCB_Wakeup(void)
{
    #if(I2C_LCD_1_SCB_SCB_MODE_UNCONFIG_CONST_CFG)

        if(I2C_LCD_1_SCB_SCB_MODE_I2C_RUNTM_CFG)
        {
            I2C_LCD_1_SCB_I2CRestoreConfig();
        }
        else if(I2C_LCD_1_SCB_SCB_MODE_SPI_RUNTM_CFG)
        {
            I2C_LCD_1_SCB_SpiRestoreConfig();
        }
        else if(I2C_LCD_1_SCB_SCB_MODE_UART_RUNTM_CFG)
        {
            I2C_LCD_1_SCB_UartRestoreConfig();
        }
        else if(I2C_LCD_1_SCB_SCB_MODE_EZBUF_I2C_RUNTM_CFG)
        {
            I2C_LCD_1_SCB_EzBufI2CRestoreConfig();
        }
        else if(I2C_LCD_1_SCB_SCB_MODE_EZBUF_SPI_RUNTM_CFG)
        {
            I2C_LCD_1_SCB_EzBufSpiRestoreConfig();
        }
        else
        {
            /* Unknown mode: do nothing */
        }

    #elif(I2C_LCD_1_SCB_SCB_MODE_I2C_CONST_CFG)
        I2C_LCD_1_SCB_I2CRestoreConfig();

    #elif(I2C_LCD_1_SCB_SCB_MODE_SPI_CONST_CFG)
        I2C_LCD_1_SCB_SpiRestoreConfig();

    #elif(I2C_LCD_1_SCB_SCB_MODE_UART_CONST_CFG)
        I2C_LCD_1_SCB_UartRestoreConfig();

    #elif(I2C_LCD_1_SCB_SCB_MODE_EZBUF_I2C_CONST_CFG)
        I2C_LCD_1_SCB_EzBufI2CRestoreConfig();

    #elif(I2C_LCD_1_SCB_SCB_MODE_EZBUF_SPI_CONST_CFG)
        I2C_LCD_1_SCB_EzBufSpiRestoreConfig();

    #else
        /* Do nothing */

    #endif /* (I2C_LCD_1_SCB_SCB_MODE_UNCONFIG_CONST_CFG) */

    if(0u != I2C_LCD_1_SCB_backup.enableState)
    {
        I2C_LCD_1_SCB_Enable();
    }
}


/* [] END OF FILE */
