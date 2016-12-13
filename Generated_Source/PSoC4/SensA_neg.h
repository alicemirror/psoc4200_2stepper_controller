/*******************************************************************************
* File Name: SensA_neg.h  
* Version 1.90
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_SensA_neg_H) /* Pins SensA_neg_H */
#define CY_PINS_SensA_neg_H

#include "cytypes.h"
#include "cyfitter.h"
#include "SensA_neg_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    SensA_neg_Write(uint8 value) ;
void    SensA_neg_SetDriveMode(uint8 mode) ;
uint8   SensA_neg_ReadDataReg(void) ;
uint8   SensA_neg_Read(void) ;
uint8   SensA_neg_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define SensA_neg_DRIVE_MODE_BITS        (3)
#define SensA_neg_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - SensA_neg_DRIVE_MODE_BITS))
#define SensA_neg_DRIVE_MODE_SHIFT       (0x00u)
#define SensA_neg_DRIVE_MODE_MASK        (0x07u << SensA_neg_DRIVE_MODE_SHIFT)

#define SensA_neg_DM_ALG_HIZ         (0x00u << SensA_neg_DRIVE_MODE_SHIFT)
#define SensA_neg_DM_DIG_HIZ         (0x01u << SensA_neg_DRIVE_MODE_SHIFT)
#define SensA_neg_DM_RES_UP          (0x02u << SensA_neg_DRIVE_MODE_SHIFT)
#define SensA_neg_DM_RES_DWN         (0x03u << SensA_neg_DRIVE_MODE_SHIFT)
#define SensA_neg_DM_OD_LO           (0x04u << SensA_neg_DRIVE_MODE_SHIFT)
#define SensA_neg_DM_OD_HI           (0x05u << SensA_neg_DRIVE_MODE_SHIFT)
#define SensA_neg_DM_STRONG          (0x06u << SensA_neg_DRIVE_MODE_SHIFT)
#define SensA_neg_DM_RES_UPDWN       (0x07u << SensA_neg_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define SensA_neg_MASK               SensA_neg__MASK
#define SensA_neg_SHIFT              SensA_neg__SHIFT
#define SensA_neg_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SensA_neg_PS                     (* (reg32 *) SensA_neg__PS)
/* Port Configuration */
#define SensA_neg_PC                     (* (reg32 *) SensA_neg__PC)
/* Data Register */
#define SensA_neg_DR                     (* (reg32 *) SensA_neg__DR)
/* Input Buffer Disable Override */
#define SensA_neg_INP_DIS                (* (reg32 *) SensA_neg__PC2)


#if defined(SensA_neg__INTSTAT)  /* Interrupt Registers */

    #define SensA_neg_INTSTAT                (* (reg32 *) SensA_neg__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins SensA_neg_H */


/* [] END OF FILE */
