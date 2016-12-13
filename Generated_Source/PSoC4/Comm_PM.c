/***************************************************************************//**
* \file Comm_PM.c
* \version 3.20
*
* \brief
*  This file provides the source code to the Power Management support for
*  the SCB Component.
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

#include "Comm.h"
#include "Comm_PVT.h"

#if(Comm_SCB_MODE_I2C_INC)
    #include "Comm_I2C_PVT.h"
#endif /* (Comm_SCB_MODE_I2C_INC) */

#if(Comm_SCB_MODE_EZI2C_INC)
    #include "Comm_EZI2C_PVT.h"
#endif /* (Comm_SCB_MODE_EZI2C_INC) */

#if(Comm_SCB_MODE_SPI_INC || Comm_SCB_MODE_UART_INC)
    #include "Comm_SPI_UART_PVT.h"
#endif /* (Comm_SCB_MODE_SPI_INC || Comm_SCB_MODE_UART_INC) */


/***************************************
*   Backup Structure declaration
***************************************/

#if(Comm_SCB_MODE_UNCONFIG_CONST_CFG || \
   (Comm_SCB_MODE_I2C_CONST_CFG   && (!Comm_I2C_WAKE_ENABLE_CONST))   || \
   (Comm_SCB_MODE_EZI2C_CONST_CFG && (!Comm_EZI2C_WAKE_ENABLE_CONST)) || \
   (Comm_SCB_MODE_SPI_CONST_CFG   && (!Comm_SPI_WAKE_ENABLE_CONST))   || \
   (Comm_SCB_MODE_UART_CONST_CFG  && (!Comm_UART_WAKE_ENABLE_CONST)))

    Comm_BACKUP_STRUCT Comm_backup =
    {
        0u, /* enableState */
    };
#endif


/*******************************************************************************
* Function Name: Comm_Sleep
****************************************************************************//**
*
*  Prepares the Comm component to enter Deep Sleep.
*  The “Enable wakeup from Deep Sleep Mode” selection has an influence on this 
*  function implementation:
*  - Checked: configures the component to be wakeup source from Deep Sleep.
*  - Unchecked: stores the current component state (enabled or disabled) and 
*    disables the component. See SCB_Stop() function for details about component 
*    disabling.
*
*  Call the Comm_Sleep() function before calling the 
*  CyPmSysDeepSleep() function. 
*  Refer to the PSoC Creator System Reference Guide for more information about 
*  power management functions and Low power section of this document for the 
*  selected mode.
*
*  This function should not be called before entering Sleep.
*
*******************************************************************************/
void Comm_Sleep(void)
{
#if(Comm_SCB_MODE_UNCONFIG_CONST_CFG)

    if(Comm_SCB_WAKE_ENABLE_CHECK)
    {
        if(Comm_SCB_MODE_I2C_RUNTM_CFG)
        {
            Comm_I2CSaveConfig();
        }
        else if(Comm_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            Comm_EzI2CSaveConfig();
        }
    #if(!Comm_CY_SCBIP_V1)
        else if(Comm_SCB_MODE_SPI_RUNTM_CFG)
        {
            Comm_SpiSaveConfig();
        }
        else if(Comm_SCB_MODE_UART_RUNTM_CFG)
        {
            Comm_UartSaveConfig();
        }
    #endif /* (!Comm_CY_SCBIP_V1) */
        else
        {
            /* Unknown mode */
        }
    }
    else
    {
        Comm_backup.enableState = (uint8) Comm_GET_CTRL_ENABLED;

        if(0u != Comm_backup.enableState)
        {
            Comm_Stop();
        }
    }

#else

    #if (Comm_SCB_MODE_I2C_CONST_CFG && Comm_I2C_WAKE_ENABLE_CONST)
        Comm_I2CSaveConfig();

    #elif (Comm_SCB_MODE_EZI2C_CONST_CFG && Comm_EZI2C_WAKE_ENABLE_CONST)
        Comm_EzI2CSaveConfig();

    #elif (Comm_SCB_MODE_SPI_CONST_CFG && Comm_SPI_WAKE_ENABLE_CONST)
        Comm_SpiSaveConfig();

    #elif (Comm_SCB_MODE_UART_CONST_CFG && Comm_UART_WAKE_ENABLE_CONST)
        Comm_UartSaveConfig();

    #else

        Comm_backup.enableState = (uint8) Comm_GET_CTRL_ENABLED;

        if(0u != Comm_backup.enableState)
        {
            Comm_Stop();
        }

    #endif /* defined (Comm_SCB_MODE_I2C_CONST_CFG) && (Comm_I2C_WAKE_ENABLE_CONST) */

#endif /* (Comm_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: Comm_Wakeup
****************************************************************************//**
*
*  Prepares the Comm component for Active mode operation after 
*  Deep Sleep.
*  The “Enable wakeup from Deep Sleep Mode” selection has influence on this 
*  function implementation:
*  - Checked: restores the component Active mode configuration.
*  - Unchecked: enables the component if it was enabled before enter Deep Sleep.
*
*  This function should not be called after exiting Sleep.
*
*  \sideeffect
*   Calling the Comm_Wakeup() function without first calling the 
*   Comm_Sleep() function may produce unexpected behavior.
*
*******************************************************************************/
void Comm_Wakeup(void)
{
#if(Comm_SCB_MODE_UNCONFIG_CONST_CFG)

    if(Comm_SCB_WAKE_ENABLE_CHECK)
    {
        if(Comm_SCB_MODE_I2C_RUNTM_CFG)
        {
            Comm_I2CRestoreConfig();
        }
        else if(Comm_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            Comm_EzI2CRestoreConfig();
        }
    #if(!Comm_CY_SCBIP_V1)
        else if(Comm_SCB_MODE_SPI_RUNTM_CFG)
        {
            Comm_SpiRestoreConfig();
        }
        else if(Comm_SCB_MODE_UART_RUNTM_CFG)
        {
            Comm_UartRestoreConfig();
        }
    #endif /* (!Comm_CY_SCBIP_V1) */
        else
        {
            /* Unknown mode */
        }
    }
    else
    {
        if(0u != Comm_backup.enableState)
        {
            Comm_Enable();
        }
    }

#else

    #if (Comm_SCB_MODE_I2C_CONST_CFG  && Comm_I2C_WAKE_ENABLE_CONST)
        Comm_I2CRestoreConfig();

    #elif (Comm_SCB_MODE_EZI2C_CONST_CFG && Comm_EZI2C_WAKE_ENABLE_CONST)
        Comm_EzI2CRestoreConfig();

    #elif (Comm_SCB_MODE_SPI_CONST_CFG && Comm_SPI_WAKE_ENABLE_CONST)
        Comm_SpiRestoreConfig();

    #elif (Comm_SCB_MODE_UART_CONST_CFG && Comm_UART_WAKE_ENABLE_CONST)
        Comm_UartRestoreConfig();

    #else

        if(0u != Comm_backup.enableState)
        {
            Comm_Enable();
        }

    #endif /* (Comm_I2C_WAKE_ENABLE_CONST) */

#endif /* (Comm_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/* [] END OF FILE */
