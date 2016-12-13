/*******************************************************************************
* File Name: SCB_1_PM.c
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

#include "SCB_1.h"

SCB_1_BACKUP_STRUCT SCB_1_backup =
{
    0u, /* enableState */
};


/*******************************************************************************
* Function Name: SCB_1_Sleep
********************************************************************************
*
* Summary:
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void SCB_1_Sleep(void)
{
    SCB_1_backup.enableState = (uint8) SCB_1_GET_CTRL_ENABLED;

    #if(SCB_1_SCB_MODE_UNCFG_CONST_CFG)

        if(SCB_1_SCB_MODE_I2C_RUNTM_CFG)
        {
            SCB_1_I2CSaveConfig();
        }
        else if(SCB_1_SCB_MODE_SPI_RUNTM_CFG)
        {
            SCB_1_SpiSaveConfig();
        }
        else if(SCB_1_SCB_MODE_UART_RUNTM_CFG)
        {
            SCB_1_UartSaveConfig();
        }
        else if(SCB_1_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            SCB_1_EzI2CSaveConfig();
        }
        else if(SCB_1_SCB_MODE_EZSPI_RUNTM_CFG)
        {
            SCB_1_EzSpiSaveConfig();
        }
        else
        {
            /* Unknown mode: do nothing */
        }

    #else

        #if(SCB_1_SCB_MODE_I2C_CONST_CFG)
            SCB_1_I2CSaveConfig();

        #elif(SCB_1_SCB_MODE_SPI_CONST_CFG)
            SCB_1_SpiSaveConfig();

        #elif(SCB_1_SCB_MODE_UART_CONST_CFG)
            SCB_1_UartSaveConfig();

        #elif(SCB_1_SCB_MODE_EZI2C_CONST_CFG)
            SCB_1_EzI2CSaveConfig();

        #else
            SCB_1_EzSpiSaveConfig();

        #endif /* (SCB_1_SCB_MODE_I2C_CONST_CFG) */

    #endif /* (SCB_1_SCB_MODE_UNCFG_CONST_CFG) */


    if(0u != SCB_1_backup.enableState)
    {
        SCB_1_Stop();
    }
}


/*******************************************************************************
* Function Name: SCB_1_Wakeup
********************************************************************************
*
* Summary:
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void SCB_1_Wakeup(void)
{
    #if(SCB_1_SCB_MODE_UNCFG_CONST_CFG)

        if(SCB_1_SCB_MODE_I2C_RUNTM_CFG)
        {
            SCB_1_I2CRestoreConfig();
        }
        else if(SCB_1_SCB_MODE_SPI_RUNTM_CFG)
        {
            SCB_1_SpiRestoreConfig();
        }
        else if(SCB_1_SCB_MODE_UART_RUNTM_CFG)
        {
            SCB_1_UartRestoreConfig();
        }
        else if(SCB_1_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            SCB_1_EzI2CRestoreConfig();
        }
        else if(SCB_1_SCB_MODE_EZSPI_RUNTM_CFG)
        {
            SCB_1_EzSpiRestoreConfig();
        }
        else
        {
            /* Unknown mode: do nothing */
        }

    #else

        #if(SCB_1_SCB_MODE_I2C_CONST_CFG)
            SCB_1_I2CRestoreConfig();

        #elif(SCB_1_SCB_MODE_SPI_CONST_CFG)
            SCB_1_SpiRestoreConfig();

        #elif(SCB_1_SCB_MODE_UART_CONST_CFG)
            SCB_1_UartRestoreConfig();

        #elif(SCB_1_SCB_MODE_EZI2C_CONST_CFG)
            SCB_1_EzI2CRestoreConfig();

        #else
            SCB_1_EzSpiRestoreConfig();

        #endif /* (SCB_1_SCB_MODE_I2C_CONST_CFG) */

    #endif /* (SCB_1_SCB_MODE_UNCFG_CONST_CFG) */

    if(0u != SCB_1_backup.enableState)
    {
        SCB_1_Enable();
    }
}


/* [] END OF FILE */
