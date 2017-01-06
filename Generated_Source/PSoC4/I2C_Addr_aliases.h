/*******************************************************************************
* File Name: I2C_Addr.h  
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

#if !defined(CY_PINS_I2C_Addr_ALIASES_H) /* Pins I2C_Addr_ALIASES_H */
#define CY_PINS_I2C_Addr_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define I2C_Addr_0			(I2C_Addr__0__PC)
#define I2C_Addr_0_PS		(I2C_Addr__0__PS)
#define I2C_Addr_0_PC		(I2C_Addr__0__PC)
#define I2C_Addr_0_DR		(I2C_Addr__0__DR)
#define I2C_Addr_0_SHIFT	(I2C_Addr__0__SHIFT)
#define I2C_Addr_0_INTR	((uint16)((uint16)0x0003u << (I2C_Addr__0__SHIFT*2u)))

#define I2C_Addr_1			(I2C_Addr__1__PC)
#define I2C_Addr_1_PS		(I2C_Addr__1__PS)
#define I2C_Addr_1_PC		(I2C_Addr__1__PC)
#define I2C_Addr_1_DR		(I2C_Addr__1__DR)
#define I2C_Addr_1_SHIFT	(I2C_Addr__1__SHIFT)
#define I2C_Addr_1_INTR	((uint16)((uint16)0x0003u << (I2C_Addr__1__SHIFT*2u)))

#define I2C_Addr_2			(I2C_Addr__2__PC)
#define I2C_Addr_2_PS		(I2C_Addr__2__PS)
#define I2C_Addr_2_PC		(I2C_Addr__2__PC)
#define I2C_Addr_2_DR		(I2C_Addr__2__DR)
#define I2C_Addr_2_SHIFT	(I2C_Addr__2__SHIFT)
#define I2C_Addr_2_INTR	((uint16)((uint16)0x0003u << (I2C_Addr__2__SHIFT*2u)))

#define I2C_Addr_3			(I2C_Addr__3__PC)
#define I2C_Addr_3_PS		(I2C_Addr__3__PS)
#define I2C_Addr_3_PC		(I2C_Addr__3__PC)
#define I2C_Addr_3_DR		(I2C_Addr__3__DR)
#define I2C_Addr_3_SHIFT	(I2C_Addr__3__SHIFT)
#define I2C_Addr_3_INTR	((uint16)((uint16)0x0003u << (I2C_Addr__3__SHIFT*2u)))

#define I2C_Addr_4			(I2C_Addr__4__PC)
#define I2C_Addr_4_PS		(I2C_Addr__4__PS)
#define I2C_Addr_4_PC		(I2C_Addr__4__PC)
#define I2C_Addr_4_DR		(I2C_Addr__4__DR)
#define I2C_Addr_4_SHIFT	(I2C_Addr__4__SHIFT)
#define I2C_Addr_4_INTR	((uint16)((uint16)0x0003u << (I2C_Addr__4__SHIFT*2u)))

#define I2C_Addr_5			(I2C_Addr__5__PC)
#define I2C_Addr_5_PS		(I2C_Addr__5__PS)
#define I2C_Addr_5_PC		(I2C_Addr__5__PC)
#define I2C_Addr_5_DR		(I2C_Addr__5__DR)
#define I2C_Addr_5_SHIFT	(I2C_Addr__5__SHIFT)
#define I2C_Addr_5_INTR	((uint16)((uint16)0x0003u << (I2C_Addr__5__SHIFT*2u)))

#define I2C_Addr_INTR_ALL	 ((uint16)(I2C_Addr_0_INTR| I2C_Addr_1_INTR| I2C_Addr_2_INTR| I2C_Addr_3_INTR| I2C_Addr_4_INTR| I2C_Addr_5_INTR))


#endif /* End Pins I2C_Addr_ALIASES_H */


/* [] END OF FILE */
