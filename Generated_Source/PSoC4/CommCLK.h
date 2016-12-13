/*******************************************************************************
* File Name: CommCLK.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_CommCLK_H)
#define CY_CLOCK_CommCLK_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void CommCLK_StartEx(uint32 alignClkDiv);
#define CommCLK_Start() \
    CommCLK_StartEx(CommCLK__PA_DIV_ID)

#else

void CommCLK_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void CommCLK_Stop(void);

void CommCLK_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 CommCLK_GetDividerRegister(void);
uint8  CommCLK_GetFractionalDividerRegister(void);

#define CommCLK_Enable()                         CommCLK_Start()
#define CommCLK_Disable()                        CommCLK_Stop()
#define CommCLK_SetDividerRegister(clkDivider, reset)  \
    CommCLK_SetFractionalDividerRegister((clkDivider), 0u)
#define CommCLK_SetDivider(clkDivider)           CommCLK_SetDividerRegister((clkDivider), 1u)
#define CommCLK_SetDividerValue(clkDivider)      CommCLK_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define CommCLK_DIV_ID     CommCLK__DIV_ID

#define CommCLK_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define CommCLK_CTRL_REG   (*(reg32 *)CommCLK__CTRL_REGISTER)
#define CommCLK_DIV_REG    (*(reg32 *)CommCLK__DIV_REGISTER)

#define CommCLK_CMD_DIV_SHIFT          (0u)
#define CommCLK_CMD_PA_DIV_SHIFT       (8u)
#define CommCLK_CMD_DISABLE_SHIFT      (30u)
#define CommCLK_CMD_ENABLE_SHIFT       (31u)

#define CommCLK_CMD_DISABLE_MASK       ((uint32)((uint32)1u << CommCLK_CMD_DISABLE_SHIFT))
#define CommCLK_CMD_ENABLE_MASK        ((uint32)((uint32)1u << CommCLK_CMD_ENABLE_SHIFT))

#define CommCLK_DIV_FRAC_MASK  (0x000000F8u)
#define CommCLK_DIV_FRAC_SHIFT (3u)
#define CommCLK_DIV_INT_MASK   (0xFFFFFF00u)
#define CommCLK_DIV_INT_SHIFT  (8u)

#else 

#define CommCLK_DIV_REG        (*(reg32 *)CommCLK__REGISTER)
#define CommCLK_ENABLE_REG     CommCLK_DIV_REG
#define CommCLK_DIV_FRAC_MASK  CommCLK__FRAC_MASK
#define CommCLK_DIV_FRAC_SHIFT (16u)
#define CommCLK_DIV_INT_MASK   CommCLK__DIVIDER_MASK
#define CommCLK_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_CommCLK_H) */

/* [] END OF FILE */
