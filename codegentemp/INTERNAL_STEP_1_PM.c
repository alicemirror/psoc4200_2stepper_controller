/*******************************************************************************
* File Name: INTERNAL_STEP_1_PM.c
* Version 3.30
*
* Description:
*  This file provides the power management source code to API for the
*  PWM.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "INTERNAL_STEP_1.h"

static INTERNAL_STEP_1_backupStruct INTERNAL_STEP_1_backup;


/*******************************************************************************
* Function Name: INTERNAL_STEP_1_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  INTERNAL_STEP_1_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void INTERNAL_STEP_1_SaveConfig(void) 
{

    #if(!INTERNAL_STEP_1_UsingFixedFunction)
        #if(!INTERNAL_STEP_1_PWMModeIsCenterAligned)
            INTERNAL_STEP_1_backup.PWMPeriod = INTERNAL_STEP_1_ReadPeriod();
        #endif /* (!INTERNAL_STEP_1_PWMModeIsCenterAligned) */
        INTERNAL_STEP_1_backup.PWMUdb = INTERNAL_STEP_1_ReadCounter();
        #if (INTERNAL_STEP_1_UseStatus)
            INTERNAL_STEP_1_backup.InterruptMaskValue = INTERNAL_STEP_1_STATUS_MASK;
        #endif /* (INTERNAL_STEP_1_UseStatus) */

        #if(INTERNAL_STEP_1_DeadBandMode == INTERNAL_STEP_1__B_PWM__DBM_256_CLOCKS || \
            INTERNAL_STEP_1_DeadBandMode == INTERNAL_STEP_1__B_PWM__DBM_2_4_CLOCKS)
            INTERNAL_STEP_1_backup.PWMdeadBandValue = INTERNAL_STEP_1_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(INTERNAL_STEP_1_KillModeMinTime)
             INTERNAL_STEP_1_backup.PWMKillCounterPeriod = INTERNAL_STEP_1_ReadKillTime();
        #endif /* (INTERNAL_STEP_1_KillModeMinTime) */

        #if(INTERNAL_STEP_1_UseControl)
            INTERNAL_STEP_1_backup.PWMControlRegister = INTERNAL_STEP_1_ReadControlRegister();
        #endif /* (INTERNAL_STEP_1_UseControl) */
    #endif  /* (!INTERNAL_STEP_1_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: INTERNAL_STEP_1_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  INTERNAL_STEP_1_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void INTERNAL_STEP_1_RestoreConfig(void) 
{
        #if(!INTERNAL_STEP_1_UsingFixedFunction)
            #if(!INTERNAL_STEP_1_PWMModeIsCenterAligned)
                INTERNAL_STEP_1_WritePeriod(INTERNAL_STEP_1_backup.PWMPeriod);
            #endif /* (!INTERNAL_STEP_1_PWMModeIsCenterAligned) */

            INTERNAL_STEP_1_WriteCounter(INTERNAL_STEP_1_backup.PWMUdb);

            #if (INTERNAL_STEP_1_UseStatus)
                INTERNAL_STEP_1_STATUS_MASK = INTERNAL_STEP_1_backup.InterruptMaskValue;
            #endif /* (INTERNAL_STEP_1_UseStatus) */

            #if(INTERNAL_STEP_1_DeadBandMode == INTERNAL_STEP_1__B_PWM__DBM_256_CLOCKS || \
                INTERNAL_STEP_1_DeadBandMode == INTERNAL_STEP_1__B_PWM__DBM_2_4_CLOCKS)
                INTERNAL_STEP_1_WriteDeadTime(INTERNAL_STEP_1_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(INTERNAL_STEP_1_KillModeMinTime)
                INTERNAL_STEP_1_WriteKillTime(INTERNAL_STEP_1_backup.PWMKillCounterPeriod);
            #endif /* (INTERNAL_STEP_1_KillModeMinTime) */

            #if(INTERNAL_STEP_1_UseControl)
                INTERNAL_STEP_1_WriteControlRegister(INTERNAL_STEP_1_backup.PWMControlRegister);
            #endif /* (INTERNAL_STEP_1_UseControl) */
        #endif  /* (!INTERNAL_STEP_1_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: INTERNAL_STEP_1_Sleep
********************************************************************************
*
* Summary:
*  Disables block's operation and saves the user configuration. Should be called
*  just prior to entering sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  INTERNAL_STEP_1_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void INTERNAL_STEP_1_Sleep(void) 
{
    #if(INTERNAL_STEP_1_UseControl)
        if(INTERNAL_STEP_1_CTRL_ENABLE == (INTERNAL_STEP_1_CONTROL & INTERNAL_STEP_1_CTRL_ENABLE))
        {
            /*Component is enabled */
            INTERNAL_STEP_1_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            INTERNAL_STEP_1_backup.PWMEnableState = 0u;
        }
    #endif /* (INTERNAL_STEP_1_UseControl) */

    /* Stop component */
    INTERNAL_STEP_1_Stop();

    /* Save registers configuration */
    INTERNAL_STEP_1_SaveConfig();
}


/*******************************************************************************
* Function Name: INTERNAL_STEP_1_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration. Should be called just after
*  awaking from sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  INTERNAL_STEP_1_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void INTERNAL_STEP_1_Wakeup(void) 
{
     /* Restore registers values */
    INTERNAL_STEP_1_RestoreConfig();

    if(INTERNAL_STEP_1_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        INTERNAL_STEP_1_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
