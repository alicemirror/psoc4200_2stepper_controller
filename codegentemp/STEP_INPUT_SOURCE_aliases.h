/*******************************************************************************
* File Name: STEP_INPUT_SOURCE.h  
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

#if !defined(CY_PINS_STEP_INPUT_SOURCE_ALIASES_H) /* Pins STEP_INPUT_SOURCE_ALIASES_H */
#define CY_PINS_STEP_INPUT_SOURCE_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define STEP_INPUT_SOURCE_0			(STEP_INPUT_SOURCE__0__PC)
#define STEP_INPUT_SOURCE_0_PS		(STEP_INPUT_SOURCE__0__PS)
#define STEP_INPUT_SOURCE_0_PC		(STEP_INPUT_SOURCE__0__PC)
#define STEP_INPUT_SOURCE_0_DR		(STEP_INPUT_SOURCE__0__DR)
#define STEP_INPUT_SOURCE_0_SHIFT	(STEP_INPUT_SOURCE__0__SHIFT)
#define STEP_INPUT_SOURCE_0_INTR	((uint16)((uint16)0x0003u << (STEP_INPUT_SOURCE__0__SHIFT*2u)))

#define STEP_INPUT_SOURCE_INTR_ALL	 ((uint16)(STEP_INPUT_SOURCE_0_INTR))


#endif /* End Pins STEP_INPUT_SOURCE_ALIASES_H */


/* [] END OF FILE */
