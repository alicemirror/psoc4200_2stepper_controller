/*******************************************************************************
* File Name: SensA_pos.c  
* Version 1.90
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "SensA_pos.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        SensA_pos_PC =   (SensA_pos_PC & \
                                (uint32)(~(uint32)(SensA_pos_DRIVE_MODE_IND_MASK << (SensA_pos_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (SensA_pos_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: SensA_pos_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None 
*  
*******************************************************************************/
void SensA_pos_Write(uint8 value) 
{
    uint8 drVal = (uint8)(SensA_pos_DR & (uint8)(~SensA_pos_MASK));
    drVal = (drVal | ((uint8)(value << SensA_pos_SHIFT) & SensA_pos_MASK));
    SensA_pos_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: SensA_pos_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to this drive mode.
*
* Return: 
*  None
*
*******************************************************************************/
void SensA_pos_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(SensA_pos__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: SensA_pos_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro SensA_pos_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 SensA_pos_Read(void) 
{
    return (uint8)((SensA_pos_PS & SensA_pos_MASK) >> SensA_pos_SHIFT);
}


/*******************************************************************************
* Function Name: SensA_pos_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 SensA_pos_ReadDataReg(void) 
{
    return (uint8)((SensA_pos_DR & SensA_pos_MASK) >> SensA_pos_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(SensA_pos_INTSTAT) 

    /*******************************************************************************
    * Function Name: SensA_pos_ClearInterrupt
    ********************************************************************************
    *
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 SensA_pos_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(SensA_pos_INTSTAT & SensA_pos_MASK);
		SensA_pos_INTSTAT = maskedStatus;
        return maskedStatus >> SensA_pos_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
