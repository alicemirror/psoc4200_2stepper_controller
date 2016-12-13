/*******************************************************************************
* File Name: INTERNAL_STEP_PM.c
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

#include "INTERNAL_STEP.h"

static INTERNAL_STEP_backupStruct INTERNAL_STEP_backup;


/*******************************************************************************
* Function Name: INTERNAL_STEP_SaveConfig
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
*  INTERNAL_STEP_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void INTERNAL_STEP_SaveConfig(void) 
{

    #if(!INTERNAL_STEP_UsingFixedFunction)
        #if(!INTERNAL_STEP_PWMModeIsCenterAligned)
            INTERNAL_STEP_backup.PWMPeriod = INTERNAL_STEP_ReadPeriod();
        #endif /* (!INTERNAL_STEP_PWMModeIsCenterAligned) */
        INTERNAL_STEP_backup.PWMUdb = INTERNAL_STEP_ReadCounter();
        #if (INTERNAL_STEP_UseStatus)
            INTERNAL_STEP_backup.InterruptMaskValue = INTERNAL_STEP_STATUS_MASK;
        #endif /* (INTERNAL_STEP_UseStatus) */

        #if(INTERNAL_STEP_DeadBandMode == INTERNAL_STEP__B_PWM__DBM_256_CLOCKS || \
            INTERNAL_STEP_DeadBandMode == INTERNAL_STEP__B_PWM__DBM_2_4_CLOCKS)
            INTERNAL_STEP_backup.PWMdeadBandValue = INTERNAL_STEP_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(INTERNAL_STEP_KillModeMinTime)
             INTERNAL_STEP_backup.PWMKillCounterPeriod = INTERNAL_STEP_ReadKillTime();
        #endif /* (INTERNAL_STEP_KillModeMinTime) */

        #if(INTERNAL_STEP_UseControl)
            INTERNAL_STEP_backup.PWMControlRegister = INTERNAL_STEP_ReadControlRegister();
        #endif /* (INTERNAL_STEP_UseControl) */
    #endif  /* (!INTERNAL_STEP_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: INTERNAL_STEP_RestoreConfig
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
*  INTERNAL_STEP_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void INTERNAL_STEP_RestoreConfig(void) 
{
        #if(!INTERNAL_STEP_UsingFixedFunction)
            #if(!INTERNAL_STEP_PWMModeIsCenterAligned)
                INTERNAL_STEP_WritePeriod(INTERNAL_STEP_backup.PWMPeriod);
            #endif /* (!INTERNAL_STEP_PWMModeIsCenterAligned) */

            INTERNAL_STEP_WriteCounter(INTERNAL_STEP_backup.PWMUdb);

            #if (INTERNAL_STEP_UseStatus)
                INTERNAL_STEP_STATUS_MASK = INTERNAL_STEP_backup.InterruptMaskValue;
            #endif /* (INTERNAL_STEP_UseStatus) */

            #if(INTERNAL_STEP_DeadBandMode == INTERNAL_STEP__B_PWM__DBM_256_CLOCKS || \
                INTERNAL_STEP_DeadBandMode == INTERNAL_STEP__B_PWM__DBM_2_4_CLOCKS)
                INTERNAL_STEP_WriteDeadTime(INTERNAL_STEP_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(INTERNAL_STEP_KillModeMinTime)
                INTERNAL_STEP_WriteKillTime(INTERNAL_STEP_backup.PWMKillCounterPeriod);
            #endif /* (INTERNAL_STEP_KillModeMinTime) */

            #if(INTERNAL_STEP_UseControl)
                INTERNAL_STEP_WriteControlRegister(INTERNAL_STEP_backup.PWMControlRegister);
            #endif /* (INTERNAL_STEP_UseControl) */
        #endif  /* (!INTERNAL_STEP_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: INTERNAL_STEP_Sleep
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
*  INTERNAL_STEP_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void INTERNAL_STEP_Sleep(void) 
{
    #if(INTERNAL_STEP_UseControl)
        if(INTERNAL_STEP_CTRL_ENABLE == (INTERNAL_STEP_CONTROL & INTERNAL_STEP_CTRL_ENABLE))
        {
            /*Component is enabled */
            INTERNAL_STEP_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            INTERNAL_STEP_backup.PWMEnableState = 0u;
        }
    #endif /* (INTERNAL_STEP_UseControl) */

    /* Stop component */
    INTERNAL_STEP_Stop();

    /* Save registers configuration */
    INTERNAL_STEP_SaveConfig();
}


/*******************************************************************************
* Function Name: INTERNAL_STEP_Wakeup
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
*  INTERNAL_STEP_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void INTERNAL_STEP_Wakeup(void) 
{
     /* Restore registers values */
    INTERNAL_STEP_RestoreConfig();

    if(INTERNAL_STEP_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        INTERNAL_STEP_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
