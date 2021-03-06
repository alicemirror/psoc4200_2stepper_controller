/*******************************************************************************
* File Name: INTERNAL_STEP_OUT_1.h  
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

#if !defined(CY_PINS_INTERNAL_STEP_OUT_1_ALIASES_H) /* Pins INTERNAL_STEP_OUT_1_ALIASES_H */
#define CY_PINS_INTERNAL_STEP_OUT_1_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define INTERNAL_STEP_OUT_1_0			(INTERNAL_STEP_OUT_1__0__PC)
#define INTERNAL_STEP_OUT_1_0_PS		(INTERNAL_STEP_OUT_1__0__PS)
#define INTERNAL_STEP_OUT_1_0_PC		(INTERNAL_STEP_OUT_1__0__PC)
#define INTERNAL_STEP_OUT_1_0_DR		(INTERNAL_STEP_OUT_1__0__DR)
#define INTERNAL_STEP_OUT_1_0_SHIFT	(INTERNAL_STEP_OUT_1__0__SHIFT)
#define INTERNAL_STEP_OUT_1_0_INTR	((uint16)((uint16)0x0003u << (INTERNAL_STEP_OUT_1__0__SHIFT*2u)))

#define INTERNAL_STEP_OUT_1_INTR_ALL	 ((uint16)(INTERNAL_STEP_OUT_1_0_INTR))


#endif /* End Pins INTERNAL_STEP_OUT_1_ALIASES_H */


/* [] END OF FILE */
