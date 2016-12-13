/*******************************************************************************
* File Name: END_STOP_2.h  
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

#if !defined(CY_PINS_END_STOP_2_ALIASES_H) /* Pins END_STOP_2_ALIASES_H */
#define CY_PINS_END_STOP_2_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define END_STOP_2_0			(END_STOP_2__0__PC)
#define END_STOP_2_0_PS		(END_STOP_2__0__PS)
#define END_STOP_2_0_PC		(END_STOP_2__0__PC)
#define END_STOP_2_0_DR		(END_STOP_2__0__DR)
#define END_STOP_2_0_SHIFT	(END_STOP_2__0__SHIFT)
#define END_STOP_2_0_INTR	((uint16)((uint16)0x0003u << (END_STOP_2__0__SHIFT*2u)))

#define END_STOP_2_INTR_ALL	 ((uint16)(END_STOP_2_0_INTR))
#define END_STOP_2_M2			(END_STOP_2__M2__PC)
#define END_STOP_2_M2_PS		(END_STOP_2__M2__PS)
#define END_STOP_2_M2_PC		(END_STOP_2__M2__PC)
#define END_STOP_2_M2_DR		(END_STOP_2__M2__DR)
#define END_STOP_2_M2_SHIFT	(END_STOP_2__M2__SHIFT)
#define END_STOP_2_M2_INTR	((uint16)((uint16)0x0003u << (END_STOP_2__0__SHIFT*2u)))


#endif /* End Pins END_STOP_2_ALIASES_H */


/* [] END OF FILE */
