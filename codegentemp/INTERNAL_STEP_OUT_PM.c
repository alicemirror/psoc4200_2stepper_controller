/*******************************************************************************
* File Name: INTERNAL_STEP_OUT.c  
* Version 2.20
*
* Description:
*  This file contains APIs to set up the Pins component for low power modes.
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "INTERNAL_STEP_OUT.h"

static INTERNAL_STEP_OUT_BACKUP_STRUCT  INTERNAL_STEP_OUT_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: INTERNAL_STEP_OUT_Sleep
****************************************************************************//**
*
* \brief Stores the pin configuration and prepares the pin for entering chip 
*  deep-sleep/hibernate modes. This function must be called for SIO and USBIO
*  pins. It is not essential if using GPIO or GPIO_OVT pins.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None 
*  
* \sideeffect
*  For SIO pins, this function configures the pin input threshold to CMOS and
*  drive level to Vddio. This is needed for SIO pins when in device 
*  deep-sleep/hibernate modes.
*
* \funcusage
*  \snippet INTERNAL_STEP_OUT_SUT.c usage_INTERNAL_STEP_OUT_Sleep_Wakeup
*******************************************************************************/
void INTERNAL_STEP_OUT_Sleep(void)
{
    #if defined(INTERNAL_STEP_OUT__PC)
        INTERNAL_STEP_OUT_backup.pcState = INTERNAL_STEP_OUT_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            INTERNAL_STEP_OUT_backup.usbState = INTERNAL_STEP_OUT_CR1_REG;
            INTERNAL_STEP_OUT_USB_POWER_REG |= INTERNAL_STEP_OUT_USBIO_ENTER_SLEEP;
            INTERNAL_STEP_OUT_CR1_REG &= INTERNAL_STEP_OUT_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(INTERNAL_STEP_OUT__SIO)
        INTERNAL_STEP_OUT_backup.sioState = INTERNAL_STEP_OUT_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        INTERNAL_STEP_OUT_SIO_REG &= (uint32)(~INTERNAL_STEP_OUT_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: INTERNAL_STEP_OUT_Wakeup
****************************************************************************//**
*
* \brief Restores the pin configuration that was saved during Pin_Sleep().
*
* For USBIO pins, the wakeup is only triggered for falling edge interrupts.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None
*  
* \funcusage
*  Refer to INTERNAL_STEP_OUT_Sleep() for an example usage.
*******************************************************************************/
void INTERNAL_STEP_OUT_Wakeup(void)
{
    #if defined(INTERNAL_STEP_OUT__PC)
        INTERNAL_STEP_OUT_PC = INTERNAL_STEP_OUT_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            INTERNAL_STEP_OUT_USB_POWER_REG &= INTERNAL_STEP_OUT_USBIO_EXIT_SLEEP_PH1;
            INTERNAL_STEP_OUT_CR1_REG = INTERNAL_STEP_OUT_backup.usbState;
            INTERNAL_STEP_OUT_USB_POWER_REG &= INTERNAL_STEP_OUT_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(INTERNAL_STEP_OUT__SIO)
        INTERNAL_STEP_OUT_SIO_REG = INTERNAL_STEP_OUT_backup.sioState;
    #endif
}


/* [] END OF FILE */
