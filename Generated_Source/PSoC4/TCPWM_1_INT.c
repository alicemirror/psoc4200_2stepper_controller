/*******************************************************************************
* File Name: TCPWM_1_PM.c
* Version 1.0
*
* Description:
*  This file provides source code of Interrupt Service Routine (ISR)
*  for TCPWM_1 component.
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

#include "TCPWM_1.h"


/*******************************************************************************
* Function Name: TCPWM_1_SetInterruptMode
********************************************************************************
*
* Summary:
*  Sets the interrupt mask to control which interrupt
*  requests generate the interrupt signal.
*
* Parameters:
*   interruptMask: Mask of bits to be enabled
*   Values:
*     - TCPWM_1_INTR_MASK_TC - Terminal count mask
*     - TCPWM_1_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void TCPWM_1_SetInterruptMode(uint32 interruptMask)
{
    TCPWM_1_INTERRUPT_MASK_REG =  interruptMask;
}


/*******************************************************************************
* Function Name: TCPWM_1_GetInterruptSourceMasked
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
*     - TCPWM_1_INTR_MASK_TC - Terminal count mask
*     - TCPWM_1_INTR_MASK_CC_MATCH - Compare count / capture mask
*
*******************************************************************************/
uint32 TCPWM_1_GetInterruptSourceMasked(void)
{
    return TCPWM_1_INTERRUPT_MASKED_REG;
}


/*******************************************************************************
* Function Name: TCPWM_1_GetInterruptSource
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
*     - TCPWM_1_INTR_MASK_TC - Terminal count mask
*     - TCPWM_1_INTR_MASK_CC_MATCH - Compare count / capture mask
*
*******************************************************************************/
uint32 TCPWM_1_GetInterruptSource(void)
{
    return TCPWM_1_INTERRUPT_REQ_REG;
}


/*******************************************************************************
* Function Name: TCPWM_1_ClearInterrupt
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
void TCPWM_1_ClearInterrupt(uint32 interruptMask)
{
    TCPWM_1_INTERRUPT_REQ_REG = interruptMask;
}


/*******************************************************************************
* Function Name: TCPWM_1_SetInterrupt
********************************************************************************
*
* Summary:
*  Sets a software interrupt request.
*
* Parameters:
*   interruptMask: Mask of interrupts to set
*   Values:
*     - TCPWM_1_INTR_MASK_TC - Terminal count mask
*     - TCPWM_1_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void TCPWM_1_SetInterrupt(uint32 interruptMask)
{
    TCPWM_1_INTERRUPT_SET_REG = interruptMask;
}

/* [] END OF FILE */
