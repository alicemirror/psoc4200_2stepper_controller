/*******************************************************************************
* File Name: INTERNAL_STEP_PM.c
* Version 1.0
*
* Description:
*  This file provides source code of Interrupt Service Routine (ISR)
*  for INTERNAL_STEP component.
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

#include "INTERNAL_STEP.h"


/*******************************************************************************
* Function Name: INTERNAL_STEP_SetInterruptMode
********************************************************************************
*
* Summary:
*  Sets the interrupt mask to control which interrupt
*  requests generate the interrupt signal.
*
* Parameters:
*   interruptMask: Mask of bits to be enabled
*   Values:
*     - INTERNAL_STEP_INTR_MASK_TC - Terminal count mask
*     - INTERNAL_STEP_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void INTERNAL_STEP_SetInterruptMode(uint32 interruptMask)
{
    INTERNAL_STEP_INTERRUPT_MASK_REG =  interruptMask;
}


/*******************************************************************************
* Function Name: INTERNAL_STEP_GetInterruptSourceMasked
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
*     - INTERNAL_STEP_INTR_MASK_TC - Terminal count mask
*     - INTERNAL_STEP_INTR_MASK_CC_MATCH - Compare count / capture mask
*
*******************************************************************************/
uint32 INTERNAL_STEP_GetInterruptSourceMasked(void)
{
    return INTERNAL_STEP_INTERRUPT_MASKED_REG;
}


/*******************************************************************************
* Function Name: INTERNAL_STEP_GetInterruptSource
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
*     - INTERNAL_STEP_INTR_MASK_TC - Terminal count mask
*     - INTERNAL_STEP_INTR_MASK_CC_MATCH - Compare count / capture mask
*
*******************************************************************************/
uint32 INTERNAL_STEP_GetInterruptSource(void)
{
    return INTERNAL_STEP_INTERRUPT_REQ_REG;
}


/*******************************************************************************
* Function Name: INTERNAL_STEP_ClearInterrupt
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
void INTERNAL_STEP_ClearInterrupt(uint32 interruptMask)
{
    INTERNAL_STEP_INTERRUPT_REQ_REG = interruptMask;
}


/*******************************************************************************
* Function Name: INTERNAL_STEP_SetInterrupt
********************************************************************************
*
* Summary:
*  Sets a software interrupt request.
*
* Parameters:
*   interruptMask: Mask of interrupts to set
*   Values:
*     - INTERNAL_STEP_INTR_MASK_TC - Terminal count mask
*     - INTERNAL_STEP_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void INTERNAL_STEP_SetInterrupt(uint32 interruptMask)
{
    INTERNAL_STEP_INTERRUPT_SET_REG = interruptMask;
}

/* [] END OF FILE */
