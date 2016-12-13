/*******************************************************************************
* File Name: PWM_3_PM.c
* Version 1.0
*
* Description:
*  This file provides source code of Interrupt Service Routine (ISR)
*  for PWM_3 component.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "PWM_3.h"


/*******************************************************************************
* Function Name: PWM_3_SetInterruptMode
********************************************************************************
*
* Summary:
*  Sets the interrupt mask to control which interrupt
*  requests generate the interrupt signal.
*
* Parameters:
*   interruptMask: Mask of bits to be enabled
*   Values:
*     - PWM_3_INTR_MASK_TC - Terminal count mask
*     - PWM_3_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void PWM_3_SetInterruptMode(uint32 interruptMask)
{
    PWM_3_INTERRUPT_MASK_REG =  interruptMask;
}


/*******************************************************************************
* Function Name: PWM_3_GetInterruptSourceMasked
********************************************************************************
*
* Summary:
*  Gets the interrupt requests masked by the interrupt mask.
*
* Parameters:
*   None
*
* Return:
*  Masked interrupt source
*   Values:
*     - PWM_3_INTR_MASK_TC - Terminal count mask
*     - PWM_3_INTR_MASK_CC_MATCH - Compare count / capture mask
*
*******************************************************************************/
uint32 PWM_3_GetInterruptSourceMasked(void)
{
    return PWM_3_INTERRUPT_MASKED_REG;
}


/*******************************************************************************
* Function Name: PWM_3_GetInterruptSource
********************************************************************************
*
* Summary:
*  Gets the interrupt requests (without masking).
*
* Parameters:
*  None
*
* Return:
*  Interrupt request value
*   Values:
*     - PWM_3_INTR_MASK_TC - Terminal count mask
*     - PWM_3_INTR_MASK_CC_MATCH - Compare count / capture mask
*
*******************************************************************************/
uint32 PWM_3_GetInterruptSource(void)
{
    return PWM_3_INTERRUPT_REQ_REG;
}


/*******************************************************************************
* Function Name: PWM_3_ClearInterrupt
********************************************************************************
*
* Summary:
*  Clears the interrupt request.
*
* Parameters:
*   interruptMask: Mask of interrupts to clear
*   Values:
*     - INTR_MASK_TC - Terminal count mask
*     - INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void PWM_3_ClearInterrupt(uint32 interruptMask)
{
    PWM_3_INTERRUPT_REQ_REG = interruptMask;
}


/*******************************************************************************
* Function Name: PWM_3_SetInterrupt
********************************************************************************
*
* Summary:
*  Sets a software interrupt request.
*
* Parameters:
*   interruptMask: Mask of interrupts to set
*   Values:
*     - PWM_3_INTR_MASK_TC - Terminal count mask
*     - PWM_3_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void PWM_3_SetInterrupt(uint32 interruptMask)
{
    PWM_3_INTERRUPT_SET_REG = interruptMask;
}

/* [] END OF FILE */
