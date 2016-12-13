/*******************************************************************************
* File Name: MODE_SWITCH.c  
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
#include "MODE_SWITCH.h"

static MODE_SWITCH_BACKUP_STRUCT  MODE_SWITCH_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: MODE_SWITCH_Sleep
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
*  \snippet MODE_SWITCH_SUT.c usage_MODE_SWITCH_Sleep_Wakeup
*******************************************************************************/
void MODE_SWITCH_Sleep(void)
{
    #if defined(MODE_SWITCH__PC)
        MODE_SWITCH_backup.pcState = MODE_SWITCH_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            MODE_SWITCH_backup.usbState = MODE_SWITCH_CR1_REG;
            MODE_SWITCH_USB_POWER_REG |= MODE_SWITCH_USBIO_ENTER_SLEEP;
            MODE_SWITCH_CR1_REG &= MODE_SWITCH_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(MODE_SWITCH__SIO)
        MODE_SWITCH_backup.sioState = MODE_SWITCH_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        MODE_SWITCH_SIO_REG &= (uint32)(~MODE_SWITCH_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: MODE_SWITCH_Wakeup
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
*  Refer to MODE_SWITCH_Sleep() for an example usage.
*******************************************************************************/
void MODE_SWITCH_Wakeup(void)
{
    #if defined(MODE_SWITCH__PC)
        MODE_SWITCH_PC = MODE_SWITCH_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            MODE_SWITCH_USB_POWER_REG &= MODE_SWITCH_USBIO_EXIT_SLEEP_PH1;
            MODE_SWITCH_CR1_REG = MODE_SWITCH_backup.usbState;
            MODE_SWITCH_USB_POWER_REG &= MODE_SWITCH_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(MODE_SWITCH__SIO)
        MODE_SWITCH_SIO_REG = MODE_SWITCH_backup.sioState;
    #endif
}


/* [] END OF FILE */
