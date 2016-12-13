/*******************************************************************************
* File Name: END_STOP_1.h  
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

#if !defined(CY_PINS_END_STOP_1_ALIASES_H) /* Pins END_STOP_1_ALIASES_H */
#define CY_PINS_END_STOP_1_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define END_STOP_1_0			(END_STOP_1__0__PC)
#define END_STOP_1_0_PS		(END_STOP_1__0__PS)
#define END_STOP_1_0_PC		(END_STOP_1__0__PC)
#define END_STOP_1_0_DR		(END_STOP_1__0__DR)
#define END_STOP_1_0_SHIFT	(END_STOP_1__0__SHIFT)
#define END_STOP_1_0_INTR	((uint16)((uint16)0x0003u << (END_STOP_1__0__SHIFT*2u)))

#define END_STOP_1_INTR_ALL	 ((uint16)(END_STOP_1_0_INTR))
#define END_STOP_1_M1			(END_STOP_1__M1__PC)
#define END_STOP_1_M1_PS		(END_STOP_1__M1__PS)
#define END_STOP_1_M1_PC		(END_STOP_1__M1__PC)
#define END_STOP_1_M1_DR		(END_STOP_1__M1__DR)
#define END_STOP_1_M1_SHIFT	(END_STOP_1__M1__SHIFT)
#define END_STOP_1_M1_INTR	((uint16)((uint16)0x0003u << (END_STOP_1__0__SHIFT*2u)))


#endif /* End Pins END_STOP_1_ALIASES_H */


/* [] END OF FILE */
