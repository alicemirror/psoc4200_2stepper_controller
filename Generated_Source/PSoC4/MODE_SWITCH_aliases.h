/*******************************************************************************
* File Name: MODE_SWITCH.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_MODE_SWITCH_ALIASES_H) /* Pins MODE_SWITCH_ALIASES_H */
#define CY_PINS_MODE_SWITCH_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define MODE_SWITCH_0			(MODE_SWITCH__0__PC)
#define MODE_SWITCH_0_PS		(MODE_SWITCH__0__PS)
#define MODE_SWITCH_0_PC		(MODE_SWITCH__0__PC)
#define MODE_SWITCH_0_DR		(MODE_SWITCH__0__DR)
#define MODE_SWITCH_0_SHIFT	(MODE_SWITCH__0__SHIFT)
#define MODE_SWITCH_0_INTR	((uint16)((uint16)0x0003u << (MODE_SWITCH__0__SHIFT*2u)))

#define MODE_SWITCH_INTR_ALL	 ((uint16)(MODE_SWITCH_0_INTR))


#endif /* End Pins MODE_SWITCH_ALIASES_H */


/* [] END OF FILE */
