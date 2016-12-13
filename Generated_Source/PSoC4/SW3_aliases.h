/*******************************************************************************
* File Name: SW3.h  
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

#if !defined(CY_PINS_SW3_ALIASES_H) /* Pins SW3_ALIASES_H */
#define CY_PINS_SW3_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define SW3_0			(SW3__0__PC)
#define SW3_0_PS		(SW3__0__PS)
#define SW3_0_PC		(SW3__0__PC)
#define SW3_0_DR		(SW3__0__DR)
#define SW3_0_SHIFT	(SW3__0__SHIFT)
#define SW3_0_INTR	((uint16)((uint16)0x0003u << (SW3__0__SHIFT*2u)))

#define SW3_1			(SW3__1__PC)
#define SW3_1_PS		(SW3__1__PS)
#define SW3_1_PC		(SW3__1__PC)
#define SW3_1_DR		(SW3__1__DR)
#define SW3_1_SHIFT	(SW3__1__SHIFT)
#define SW3_1_INTR	((uint16)((uint16)0x0003u << (SW3__1__SHIFT*2u)))

#define SW3_2			(SW3__2__PC)
#define SW3_2_PS		(SW3__2__PS)
#define SW3_2_PC		(SW3__2__PC)
#define SW3_2_DR		(SW3__2__DR)
#define SW3_2_SHIFT	(SW3__2__SHIFT)
#define SW3_2_INTR	((uint16)((uint16)0x0003u << (SW3__2__SHIFT*2u)))

#define SW3_3			(SW3__3__PC)
#define SW3_3_PS		(SW3__3__PS)
#define SW3_3_PC		(SW3__3__PC)
#define SW3_3_DR		(SW3__3__DR)
#define SW3_3_SHIFT	(SW3__3__SHIFT)
#define SW3_3_INTR	((uint16)((uint16)0x0003u << (SW3__3__SHIFT*2u)))

#define SW3_INTR_ALL	 ((uint16)(SW3_0_INTR| SW3_1_INTR| SW3_2_INTR| SW3_3_INTR))
#define SW3_BIT_0			(SW3__BIT_0__PC)
#define SW3_BIT_0_PS		(SW3__BIT_0__PS)
#define SW3_BIT_0_PC		(SW3__BIT_0__PC)
#define SW3_BIT_0_DR		(SW3__BIT_0__DR)
#define SW3_BIT_0_SHIFT	(SW3__BIT_0__SHIFT)
#define SW3_BIT_0_INTR	((uint16)((uint16)0x0003u << (SW3__0__SHIFT*2u)))

#define SW3_BIT_1			(SW3__BIT_1__PC)
#define SW3_BIT_1_PS		(SW3__BIT_1__PS)
#define SW3_BIT_1_PC		(SW3__BIT_1__PC)
#define SW3_BIT_1_DR		(SW3__BIT_1__DR)
#define SW3_BIT_1_SHIFT	(SW3__BIT_1__SHIFT)
#define SW3_BIT_1_INTR	((uint16)((uint16)0x0003u << (SW3__1__SHIFT*2u)))

#define SW3_BIT_2			(SW3__BIT_2__PC)
#define SW3_BIT_2_PS		(SW3__BIT_2__PS)
#define SW3_BIT_2_PC		(SW3__BIT_2__PC)
#define SW3_BIT_2_DR		(SW3__BIT_2__DR)
#define SW3_BIT_2_SHIFT	(SW3__BIT_2__SHIFT)
#define SW3_BIT_2_INTR	((uint16)((uint16)0x0003u << (SW3__2__SHIFT*2u)))

#define SW3_BIT_3			(SW3__BIT_3__PC)
#define SW3_BIT_3_PS		(SW3__BIT_3__PS)
#define SW3_BIT_3_PC		(SW3__BIT_3__PC)
#define SW3_BIT_3_DR		(SW3__BIT_3__DR)
#define SW3_BIT_3_SHIFT	(SW3__BIT_3__SHIFT)
#define SW3_BIT_3_INTR	((uint16)((uint16)0x0003u << (SW3__3__SHIFT*2u)))


#endif /* End Pins SW3_ALIASES_H */


/* [] END OF FILE */
