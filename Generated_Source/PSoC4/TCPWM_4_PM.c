/*******************************************************************************
* File Name: TCPWM_4_PM.c
* Version 2.10
*
* Description:
*  This file contains the setup, control, and status commands to support
*  the component operations in the low power mode.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "TCPWM_4.h"

static TCPWM_4_BACKUP_STRUCT TCPWM_4_backup;


/*******************************************************************************
* Function Name: TCPWM_4_SaveConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to save here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void TCPWM_4_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: TCPWM_4_Sleep
********************************************************************************
*
* Summary:
*  Stops the component operation and saves the user configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void TCPWM_4_Sleep(void)
{
    if(0u != (TCPWM_4_BLOCK_CONTROL_REG & TCPWM_4_MASK))
    {
        TCPWM_4_backup.enableState = 1u;
    }
    else
    {
        TCPWM_4_backup.enableState = 0u;
    }

    TCPWM_4_Stop();
    TCPWM_4_SaveConfig();
}


/*******************************************************************************
* Function Name: TCPWM_4_RestoreConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to restore here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void TCPWM_4_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: TCPWM_4_Wakeup
********************************************************************************
*
* Summary:
*  Restores the user configuration and restores the enable state.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void TCPWM_4_Wakeup(void)
{
    TCPWM_4_RestoreConfig();

    if(0u != TCPWM_4_backup.enableState)
    {
        TCPWM_4_Enable();
    }
}


/* [] END OF FILE */
