/*******************************************************************************
* File Name: STATUS_LED_2.h  
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

#if !defined(CY_PINS_STATUS_LED_2_ALIASES_H) /* Pins STATUS_LED_2_ALIASES_H */
#define CY_PINS_STATUS_LED_2_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define STATUS_LED_2_0			(STATUS_LED_2__0__PC)
#define STATUS_LED_2_0_PS		(STATUS_LED_2__0__PS)
#define STATUS_LED_2_0_PC		(STATUS_LED_2__0__PC)
#define STATUS_LED_2_0_DR		(STATUS_LED_2__0__DR)
#define STATUS_LED_2_0_SHIFT	(STATUS_LED_2__0__SHIFT)
#define STATUS_LED_2_0_INTR	((uint16)((uint16)0x0003u << (STATUS_LED_2__0__SHIFT*2u)))

#define STATUS_LED_2_INTR_ALL	 ((uint16)(STATUS_LED_2_0_INTR))
#define STATUS_LED_2_M2			(STATUS_LED_2__M2__PC)
#define STATUS_LED_2_M2_PS		(STATUS_LED_2__M2__PS)
#define STATUS_LED_2_M2_PC		(STATUS_LED_2__M2__PC)
#define STATUS_LED_2_M2_DR		(STATUS_LED_2__M2__DR)
#define STATUS_LED_2_M2_SHIFT	(STATUS_LED_2__M2__SHIFT)
#define STATUS_LED_2_M2_INTR	((uint16)((uint16)0x0003u << (STATUS_LED_2__0__SHIFT*2u)))


#endif /* End Pins STATUS_LED_2_ALIASES_H */


/* [] END OF FILE */
