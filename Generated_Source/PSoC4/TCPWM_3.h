/*******************************************************************************
* File Name: TCPWM_3.h
* Version 2.10
*
* Description:
*  This file provides constants and parameter values for the TCPWM_3
*  component.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_TCPWM_TCPWM_3_H)
#define CY_TCPWM_TCPWM_3_H


#include "CyLib.h"
#include "cytypes.h"
#include "cyfitter.h"


/*******************************************************************************
* Internal Type defines
*******************************************************************************/

/* Structure to save state before go to sleep */
typedef struct
{
    uint8  enableState;
} TCPWM_3_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  TCPWM_3_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define TCPWM_3_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)
#define TCPWM_3_CY_TCPWM_4000                  (CY_PSOC4_4000)

/* TCPWM Configuration */
#define TCPWM_3_CONFIG                         (7lu)

/* Quad Mode */
/* Parameters */
#define TCPWM_3_QUAD_ENCODING_MODES            (0lu)
#define TCPWM_3_QUAD_AUTO_START                (0lu)

/* Signal modes */
#define TCPWM_3_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define TCPWM_3_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define TCPWM_3_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define TCPWM_3_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define TCPWM_3_QUAD_INDEX_SIGNAL_PRESENT      (1lu)
#define TCPWM_3_QUAD_STOP_SIGNAL_PRESENT       (1lu)

/* Interrupt Mask */
#define TCPWM_3_QUAD_INTERRUPT_MASK            (1lu)

/* Timer/Counter Mode */
/* Parameters */
#define TCPWM_3_TC_RUN_MODE                    (0lu)
#define TCPWM_3_TC_COUNTER_MODE                (0lu)
#define TCPWM_3_TC_COMP_CAP_MODE               (2lu)
#define TCPWM_3_TC_PRESCALER                   (0lu)

/* Signal modes */
#define TCPWM_3_TC_RELOAD_SIGNAL_MODE          (0lu)
#define TCPWM_3_TC_COUNT_SIGNAL_MODE           (0lu)
#define TCPWM_3_TC_START_SIGNAL_MODE           (0lu)
#define TCPWM_3_TC_STOP_SIGNAL_MODE            (0lu)
#define TCPWM_3_TC_CAPTURE_SIGNAL_MODE         (0lu)

/* Signal present */
#define TCPWM_3_TC_RELOAD_SIGNAL_PRESENT       (1lu)
#define TCPWM_3_TC_COUNT_SIGNAL_PRESENT        (1lu)
#define TCPWM_3_TC_START_SIGNAL_PRESENT        (1lu)
#define TCPWM_3_TC_STOP_SIGNAL_PRESENT         (1lu)
#define TCPWM_3_TC_CAPTURE_SIGNAL_PRESENT      (1lu)

/* Interrupt Mask */
#define TCPWM_3_TC_INTERRUPT_MASK              (1lu)

/* PWM Mode */
/* Parameters */
#define TCPWM_3_PWM_KILL_EVENT                 (0lu)
#define TCPWM_3_PWM_STOP_EVENT                 (0lu)
#define TCPWM_3_PWM_MODE                       (4lu)
#define TCPWM_3_PWM_OUT_N_INVERT               (0lu)
#define TCPWM_3_PWM_OUT_INVERT                 (0lu)
#define TCPWM_3_PWM_ALIGN                      (0lu)
#define TCPWM_3_PWM_RUN_MODE                   (0lu)
#define TCPWM_3_PWM_DEAD_TIME_CYCLE            (0lu)
#define TCPWM_3_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define TCPWM_3_PWM_RELOAD_SIGNAL_MODE         (3lu)
#define TCPWM_3_PWM_COUNT_SIGNAL_MODE          (3lu)
#define TCPWM_3_PWM_START_SIGNAL_MODE          (3lu)
#define TCPWM_3_PWM_STOP_SIGNAL_MODE           (3lu)
#define TCPWM_3_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define TCPWM_3_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define TCPWM_3_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define TCPWM_3_PWM_START_SIGNAL_PRESENT       (0lu)
#define TCPWM_3_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define TCPWM_3_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define TCPWM_3_PWM_INTERRUPT_MASK             (1lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define TCPWM_3_TC_PERIOD_VALUE                (65535lu)
#define TCPWM_3_TC_COMPARE_VALUE               (65535lu)
#define TCPWM_3_TC_COMPARE_BUF_VALUE           (65535lu)
#define TCPWM_3_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define TCPWM_3_PWM_PERIOD_VALUE               (255lu)
#define TCPWM_3_PWM_PERIOD_BUF_VALUE           (65535lu)
#define TCPWM_3_PWM_PERIOD_SWAP                (0lu)
#define TCPWM_3_PWM_COMPARE_VALUE              (0lu)
#define TCPWM_3_PWM_COMPARE_BUF_VALUE          (65535lu)
#define TCPWM_3_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define TCPWM_3__LEFT 0
#define TCPWM_3__RIGHT 1
#define TCPWM_3__CENTER 2
#define TCPWM_3__ASYMMETRIC 3

#define TCPWM_3__X1 0
#define TCPWM_3__X2 1
#define TCPWM_3__X4 2

#define TCPWM_3__PWM 4
#define TCPWM_3__PWM_DT 5
#define TCPWM_3__PWM_PR 6

#define TCPWM_3__INVERSE 1
#define TCPWM_3__DIRECT 0

#define TCPWM_3__CAPTURE 2
#define TCPWM_3__COMPARE 0

#define TCPWM_3__TRIG_LEVEL 3
#define TCPWM_3__TRIG_RISING 0
#define TCPWM_3__TRIG_FALLING 1
#define TCPWM_3__TRIG_BOTH 2

#define TCPWM_3__INTR_MASK_TC 1
#define TCPWM_3__INTR_MASK_CC_MATCH 2
#define TCPWM_3__INTR_MASK_NONE 0
#define TCPWM_3__INTR_MASK_TC_CC 3

#define TCPWM_3__UNCONFIG 8
#define TCPWM_3__TIMER 1
#define TCPWM_3__QUAD 3
#define TCPWM_3__PWM_SEL 7

#define TCPWM_3__COUNT_UP 0
#define TCPWM_3__COUNT_DOWN 1
#define TCPWM_3__COUNT_UPDOWN0 2
#define TCPWM_3__COUNT_UPDOWN1 3


/* Prescaler */
#define TCPWM_3_PRESCALE_DIVBY1                ((uint32)(0u << TCPWM_3_PRESCALER_SHIFT))
#define TCPWM_3_PRESCALE_DIVBY2                ((uint32)(1u << TCPWM_3_PRESCALER_SHIFT))
#define TCPWM_3_PRESCALE_DIVBY4                ((uint32)(2u << TCPWM_3_PRESCALER_SHIFT))
#define TCPWM_3_PRESCALE_DIVBY8                ((uint32)(3u << TCPWM_3_PRESCALER_SHIFT))
#define TCPWM_3_PRESCALE_DIVBY16               ((uint32)(4u << TCPWM_3_PRESCALER_SHIFT))
#define TCPWM_3_PRESCALE_DIVBY32               ((uint32)(5u << TCPWM_3_PRESCALER_SHIFT))
#define TCPWM_3_PRESCALE_DIVBY64               ((uint32)(6u << TCPWM_3_PRESCALER_SHIFT))
#define TCPWM_3_PRESCALE_DIVBY128              ((uint32)(7u << TCPWM_3_PRESCALER_SHIFT))

/* TCPWM set modes */
#define TCPWM_3_MODE_TIMER_COMPARE             ((uint32)(TCPWM_3__COMPARE         <<  \
                                                                  TCPWM_3_MODE_SHIFT))
#define TCPWM_3_MODE_TIMER_CAPTURE             ((uint32)(TCPWM_3__CAPTURE         <<  \
                                                                  TCPWM_3_MODE_SHIFT))
#define TCPWM_3_MODE_QUAD                      ((uint32)(TCPWM_3__QUAD            <<  \
                                                                  TCPWM_3_MODE_SHIFT))
#define TCPWM_3_MODE_PWM                       ((uint32)(TCPWM_3__PWM             <<  \
                                                                  TCPWM_3_MODE_SHIFT))
#define TCPWM_3_MODE_PWM_DT                    ((uint32)(TCPWM_3__PWM_DT          <<  \
                                                                  TCPWM_3_MODE_SHIFT))
#define TCPWM_3_MODE_PWM_PR                    ((uint32)(TCPWM_3__PWM_PR          <<  \
                                                                  TCPWM_3_MODE_SHIFT))

/* Quad Modes */
#define TCPWM_3_MODE_X1                        ((uint32)(TCPWM_3__X1              <<  \
                                                                  TCPWM_3_QUAD_MODE_SHIFT))
#define TCPWM_3_MODE_X2                        ((uint32)(TCPWM_3__X2              <<  \
                                                                  TCPWM_3_QUAD_MODE_SHIFT))
#define TCPWM_3_MODE_X4                        ((uint32)(TCPWM_3__X4              <<  \
                                                                  TCPWM_3_QUAD_MODE_SHIFT))

/* Counter modes */
#define TCPWM_3_COUNT_UP                       ((uint32)(TCPWM_3__COUNT_UP        <<  \
                                                                  TCPWM_3_UPDOWN_SHIFT))
#define TCPWM_3_COUNT_DOWN                     ((uint32)(TCPWM_3__COUNT_DOWN      <<  \
                                                                  TCPWM_3_UPDOWN_SHIFT))
#define TCPWM_3_COUNT_UPDOWN0                  ((uint32)(TCPWM_3__COUNT_UPDOWN0   <<  \
                                                                  TCPWM_3_UPDOWN_SHIFT))
#define TCPWM_3_COUNT_UPDOWN1                  ((uint32)(TCPWM_3__COUNT_UPDOWN1   <<  \
                                                                  TCPWM_3_UPDOWN_SHIFT))

/* PWM output invert */
#define TCPWM_3_INVERT_LINE                    ((uint32)(TCPWM_3__INVERSE         <<  \
                                                                  TCPWM_3_INV_OUT_SHIFT))
#define TCPWM_3_INVERT_LINE_N                  ((uint32)(TCPWM_3__INVERSE         <<  \
                                                                  TCPWM_3_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define TCPWM_3_TRIG_RISING                    ((uint32)TCPWM_3__TRIG_RISING)
#define TCPWM_3_TRIG_FALLING                   ((uint32)TCPWM_3__TRIG_FALLING)
#define TCPWM_3_TRIG_BOTH                      ((uint32)TCPWM_3__TRIG_BOTH)
#define TCPWM_3_TRIG_LEVEL                     ((uint32)TCPWM_3__TRIG_LEVEL)

/* Interrupt mask */
#define TCPWM_3_INTR_MASK_TC                   ((uint32)TCPWM_3__INTR_MASK_TC)
#define TCPWM_3_INTR_MASK_CC_MATCH             ((uint32)TCPWM_3__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define TCPWM_3_CC_MATCH_SET                   (0x00u)
#define TCPWM_3_CC_MATCH_CLEAR                 (0x01u)
#define TCPWM_3_CC_MATCH_INVERT                (0x02u)
#define TCPWM_3_CC_MATCH_NO_CHANGE             (0x03u)
#define TCPWM_3_OVERLOW_SET                    (0x00u)
#define TCPWM_3_OVERLOW_CLEAR                  (0x04u)
#define TCPWM_3_OVERLOW_INVERT                 (0x08u)
#define TCPWM_3_OVERLOW_NO_CHANGE              (0x0Cu)
#define TCPWM_3_UNDERFLOW_SET                  (0x00u)
#define TCPWM_3_UNDERFLOW_CLEAR                (0x10u)
#define TCPWM_3_UNDERFLOW_INVERT               (0x20u)
#define TCPWM_3_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define TCPWM_3_PWM_MODE_LEFT                  (TCPWM_3_CC_MATCH_CLEAR        |   \
                                                         TCPWM_3_OVERLOW_SET           |   \
                                                         TCPWM_3_UNDERFLOW_NO_CHANGE)
#define TCPWM_3_PWM_MODE_RIGHT                 (TCPWM_3_CC_MATCH_SET          |   \
                                                         TCPWM_3_OVERLOW_NO_CHANGE     |   \
                                                         TCPWM_3_UNDERFLOW_CLEAR)
#define TCPWM_3_PWM_MODE_ASYM                  (TCPWM_3_CC_MATCH_INVERT       |   \
                                                         TCPWM_3_OVERLOW_SET           |   \
                                                         TCPWM_3_UNDERFLOW_CLEAR)

#if (TCPWM_3_CY_TCPWM_V2)
    #if(TCPWM_3_CY_TCPWM_4000)
        #define TCPWM_3_PWM_MODE_CENTER                (TCPWM_3_CC_MATCH_INVERT       |   \
                                                                 TCPWM_3_OVERLOW_NO_CHANGE     |   \
                                                                 TCPWM_3_UNDERFLOW_CLEAR)
    #else
        #define TCPWM_3_PWM_MODE_CENTER                (TCPWM_3_CC_MATCH_INVERT       |   \
                                                                 TCPWM_3_OVERLOW_SET           |   \
                                                                 TCPWM_3_UNDERFLOW_CLEAR)
    #endif /* (TCPWM_3_CY_TCPWM_4000) */
#else
    #define TCPWM_3_PWM_MODE_CENTER                (TCPWM_3_CC_MATCH_INVERT       |   \
                                                             TCPWM_3_OVERLOW_NO_CHANGE     |   \
                                                             TCPWM_3_UNDERFLOW_CLEAR)
#endif /* (TCPWM_3_CY_TCPWM_NEW) */

/* Command operations without condition */
#define TCPWM_3_CMD_CAPTURE                    (0u)
#define TCPWM_3_CMD_RELOAD                     (8u)
#define TCPWM_3_CMD_STOP                       (16u)
#define TCPWM_3_CMD_START                      (24u)

/* Status */
#define TCPWM_3_STATUS_DOWN                    (1u)
#define TCPWM_3_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   TCPWM_3_Init(void);
void   TCPWM_3_Enable(void);
void   TCPWM_3_Start(void);
void   TCPWM_3_Stop(void);

void   TCPWM_3_SetMode(uint32 mode);
void   TCPWM_3_SetCounterMode(uint32 counterMode);
void   TCPWM_3_SetPWMMode(uint32 modeMask);
void   TCPWM_3_SetQDMode(uint32 qdMode);

void   TCPWM_3_SetPrescaler(uint32 prescaler);
void   TCPWM_3_TriggerCommand(uint32 mask, uint32 command);
void   TCPWM_3_SetOneShot(uint32 oneShotEnable);
uint32 TCPWM_3_ReadStatus(void);

void   TCPWM_3_SetPWMSyncKill(uint32 syncKillEnable);
void   TCPWM_3_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   TCPWM_3_SetPWMDeadTime(uint32 deadTime);
void   TCPWM_3_SetPWMInvert(uint32 mask);

void   TCPWM_3_SetInterruptMode(uint32 interruptMask);
uint32 TCPWM_3_GetInterruptSourceMasked(void);
uint32 TCPWM_3_GetInterruptSource(void);
void   TCPWM_3_ClearInterrupt(uint32 interruptMask);
void   TCPWM_3_SetInterrupt(uint32 interruptMask);

void   TCPWM_3_WriteCounter(uint32 count);
uint32 TCPWM_3_ReadCounter(void);

uint32 TCPWM_3_ReadCapture(void);
uint32 TCPWM_3_ReadCaptureBuf(void);

void   TCPWM_3_WritePeriod(uint32 period);
uint32 TCPWM_3_ReadPeriod(void);
void   TCPWM_3_WritePeriodBuf(uint32 periodBuf);
uint32 TCPWM_3_ReadPeriodBuf(void);

void   TCPWM_3_WriteCompare(uint32 compare);
uint32 TCPWM_3_ReadCompare(void);
void   TCPWM_3_WriteCompareBuf(uint32 compareBuf);
uint32 TCPWM_3_ReadCompareBuf(void);

void   TCPWM_3_SetPeriodSwap(uint32 swapEnable);
void   TCPWM_3_SetCompareSwap(uint32 swapEnable);

void   TCPWM_3_SetCaptureMode(uint32 triggerMode);
void   TCPWM_3_SetReloadMode(uint32 triggerMode);
void   TCPWM_3_SetStartMode(uint32 triggerMode);
void   TCPWM_3_SetStopMode(uint32 triggerMode);
void   TCPWM_3_SetCountMode(uint32 triggerMode);

void   TCPWM_3_SaveConfig(void);
void   TCPWM_3_RestoreConfig(void);
void   TCPWM_3_Sleep(void);
void   TCPWM_3_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define TCPWM_3_BLOCK_CONTROL_REG              (*(reg32 *) TCPWM_3_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define TCPWM_3_BLOCK_CONTROL_PTR              ( (reg32 *) TCPWM_3_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define TCPWM_3_COMMAND_REG                    (*(reg32 *) TCPWM_3_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define TCPWM_3_COMMAND_PTR                    ( (reg32 *) TCPWM_3_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define TCPWM_3_INTRRUPT_CAUSE_REG             (*(reg32 *) TCPWM_3_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define TCPWM_3_INTRRUPT_CAUSE_PTR             ( (reg32 *) TCPWM_3_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define TCPWM_3_CONTROL_REG                    (*(reg32 *) TCPWM_3_cy_m0s8_tcpwm_1__CTRL )
#define TCPWM_3_CONTROL_PTR                    ( (reg32 *) TCPWM_3_cy_m0s8_tcpwm_1__CTRL )
#define TCPWM_3_STATUS_REG                     (*(reg32 *) TCPWM_3_cy_m0s8_tcpwm_1__STATUS )
#define TCPWM_3_STATUS_PTR                     ( (reg32 *) TCPWM_3_cy_m0s8_tcpwm_1__STATUS )
#define TCPWM_3_COUNTER_REG                    (*(reg32 *) TCPWM_3_cy_m0s8_tcpwm_1__COUNTER )
#define TCPWM_3_COUNTER_PTR                    ( (reg32 *) TCPWM_3_cy_m0s8_tcpwm_1__COUNTER )
#define TCPWM_3_COMP_CAP_REG                   (*(reg32 *) TCPWM_3_cy_m0s8_tcpwm_1__CC )
#define TCPWM_3_COMP_CAP_PTR                   ( (reg32 *) TCPWM_3_cy_m0s8_tcpwm_1__CC )
#define TCPWM_3_COMP_CAP_BUF_REG               (*(reg32 *) TCPWM_3_cy_m0s8_tcpwm_1__CC_BUFF )
#define TCPWM_3_COMP_CAP_BUF_PTR               ( (reg32 *) TCPWM_3_cy_m0s8_tcpwm_1__CC_BUFF )
#define TCPWM_3_PERIOD_REG                     (*(reg32 *) TCPWM_3_cy_m0s8_tcpwm_1__PERIOD )
#define TCPWM_3_PERIOD_PTR                     ( (reg32 *) TCPWM_3_cy_m0s8_tcpwm_1__PERIOD )
#define TCPWM_3_PERIOD_BUF_REG                 (*(reg32 *) TCPWM_3_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define TCPWM_3_PERIOD_BUF_PTR                 ( (reg32 *) TCPWM_3_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define TCPWM_3_TRIG_CONTROL0_REG              (*(reg32 *) TCPWM_3_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define TCPWM_3_TRIG_CONTROL0_PTR              ( (reg32 *) TCPWM_3_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define TCPWM_3_TRIG_CONTROL1_REG              (*(reg32 *) TCPWM_3_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define TCPWM_3_TRIG_CONTROL1_PTR              ( (reg32 *) TCPWM_3_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define TCPWM_3_TRIG_CONTROL2_REG              (*(reg32 *) TCPWM_3_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define TCPWM_3_TRIG_CONTROL2_PTR              ( (reg32 *) TCPWM_3_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define TCPWM_3_INTERRUPT_REQ_REG              (*(reg32 *) TCPWM_3_cy_m0s8_tcpwm_1__INTR )
#define TCPWM_3_INTERRUPT_REQ_PTR              ( (reg32 *) TCPWM_3_cy_m0s8_tcpwm_1__INTR )
#define TCPWM_3_INTERRUPT_SET_REG              (*(reg32 *) TCPWM_3_cy_m0s8_tcpwm_1__INTR_SET )
#define TCPWM_3_INTERRUPT_SET_PTR              ( (reg32 *) TCPWM_3_cy_m0s8_tcpwm_1__INTR_SET )
#define TCPWM_3_INTERRUPT_MASK_REG             (*(reg32 *) TCPWM_3_cy_m0s8_tcpwm_1__INTR_MASK )
#define TCPWM_3_INTERRUPT_MASK_PTR             ( (reg32 *) TCPWM_3_cy_m0s8_tcpwm_1__INTR_MASK )
#define TCPWM_3_INTERRUPT_MASKED_REG           (*(reg32 *) TCPWM_3_cy_m0s8_tcpwm_1__INTR_MASKED )
#define TCPWM_3_INTERRUPT_MASKED_PTR           ( (reg32 *) TCPWM_3_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define TCPWM_3_MASK                           ((uint32)TCPWM_3_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define TCPWM_3_RELOAD_CC_SHIFT                (0u)
#define TCPWM_3_RELOAD_PERIOD_SHIFT            (1u)
#define TCPWM_3_PWM_SYNC_KILL_SHIFT            (2u)
#define TCPWM_3_PWM_STOP_KILL_SHIFT            (3u)
#define TCPWM_3_PRESCALER_SHIFT                (8u)
#define TCPWM_3_UPDOWN_SHIFT                   (16u)
#define TCPWM_3_ONESHOT_SHIFT                  (18u)
#define TCPWM_3_QUAD_MODE_SHIFT                (20u)
#define TCPWM_3_INV_OUT_SHIFT                  (20u)
#define TCPWM_3_INV_COMPL_OUT_SHIFT            (21u)
#define TCPWM_3_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define TCPWM_3_RELOAD_CC_MASK                 ((uint32)(TCPWM_3_1BIT_MASK        <<  \
                                                                            TCPWM_3_RELOAD_CC_SHIFT))
#define TCPWM_3_RELOAD_PERIOD_MASK             ((uint32)(TCPWM_3_1BIT_MASK        <<  \
                                                                            TCPWM_3_RELOAD_PERIOD_SHIFT))
#define TCPWM_3_PWM_SYNC_KILL_MASK             ((uint32)(TCPWM_3_1BIT_MASK        <<  \
                                                                            TCPWM_3_PWM_SYNC_KILL_SHIFT))
#define TCPWM_3_PWM_STOP_KILL_MASK             ((uint32)(TCPWM_3_1BIT_MASK        <<  \
                                                                            TCPWM_3_PWM_STOP_KILL_SHIFT))
#define TCPWM_3_PRESCALER_MASK                 ((uint32)(TCPWM_3_8BIT_MASK        <<  \
                                                                            TCPWM_3_PRESCALER_SHIFT))
#define TCPWM_3_UPDOWN_MASK                    ((uint32)(TCPWM_3_2BIT_MASK        <<  \
                                                                            TCPWM_3_UPDOWN_SHIFT))
#define TCPWM_3_ONESHOT_MASK                   ((uint32)(TCPWM_3_1BIT_MASK        <<  \
                                                                            TCPWM_3_ONESHOT_SHIFT))
#define TCPWM_3_QUAD_MODE_MASK                 ((uint32)(TCPWM_3_3BIT_MASK        <<  \
                                                                            TCPWM_3_QUAD_MODE_SHIFT))
#define TCPWM_3_INV_OUT_MASK                   ((uint32)(TCPWM_3_2BIT_MASK        <<  \
                                                                            TCPWM_3_INV_OUT_SHIFT))
#define TCPWM_3_MODE_MASK                      ((uint32)(TCPWM_3_3BIT_MASK        <<  \
                                                                            TCPWM_3_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define TCPWM_3_CAPTURE_SHIFT                  (0u)
#define TCPWM_3_COUNT_SHIFT                    (2u)
#define TCPWM_3_RELOAD_SHIFT                   (4u)
#define TCPWM_3_STOP_SHIFT                     (6u)
#define TCPWM_3_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define TCPWM_3_CAPTURE_MASK                   ((uint32)(TCPWM_3_2BIT_MASK        <<  \
                                                                  TCPWM_3_CAPTURE_SHIFT))
#define TCPWM_3_COUNT_MASK                     ((uint32)(TCPWM_3_2BIT_MASK        <<  \
                                                                  TCPWM_3_COUNT_SHIFT))
#define TCPWM_3_RELOAD_MASK                    ((uint32)(TCPWM_3_2BIT_MASK        <<  \
                                                                  TCPWM_3_RELOAD_SHIFT))
#define TCPWM_3_STOP_MASK                      ((uint32)(TCPWM_3_2BIT_MASK        <<  \
                                                                  TCPWM_3_STOP_SHIFT))
#define TCPWM_3_START_MASK                     ((uint32)(TCPWM_3_2BIT_MASK        <<  \
                                                                  TCPWM_3_START_SHIFT))

/* MASK */
#define TCPWM_3_1BIT_MASK                      ((uint32)0x01u)
#define TCPWM_3_2BIT_MASK                      ((uint32)0x03u)
#define TCPWM_3_3BIT_MASK                      ((uint32)0x07u)
#define TCPWM_3_6BIT_MASK                      ((uint32)0x3Fu)
#define TCPWM_3_8BIT_MASK                      ((uint32)0xFFu)
#define TCPWM_3_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define TCPWM_3_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define TCPWM_3_CTRL_QUAD_BASE_CONFIG                                                          \
        (((uint32)(TCPWM_3_QUAD_ENCODING_MODES     << TCPWM_3_QUAD_MODE_SHIFT))       |\
         ((uint32)(TCPWM_3_CONFIG                  << TCPWM_3_MODE_SHIFT)))

#define TCPWM_3_CTRL_PWM_BASE_CONFIG                                                           \
        (((uint32)(TCPWM_3_PWM_STOP_EVENT          << TCPWM_3_PWM_STOP_KILL_SHIFT))   |\
         ((uint32)(TCPWM_3_PWM_OUT_INVERT          << TCPWM_3_INV_OUT_SHIFT))         |\
         ((uint32)(TCPWM_3_PWM_OUT_N_INVERT        << TCPWM_3_INV_COMPL_OUT_SHIFT))   |\
         ((uint32)(TCPWM_3_PWM_MODE                << TCPWM_3_MODE_SHIFT)))

#define TCPWM_3_CTRL_PWM_RUN_MODE                                                              \
            ((uint32)(TCPWM_3_PWM_RUN_MODE         << TCPWM_3_ONESHOT_SHIFT))
            
#define TCPWM_3_CTRL_PWM_ALIGN                                                                 \
            ((uint32)(TCPWM_3_PWM_ALIGN            << TCPWM_3_UPDOWN_SHIFT))

#define TCPWM_3_CTRL_PWM_KILL_EVENT                                                            \
             ((uint32)(TCPWM_3_PWM_KILL_EVENT      << TCPWM_3_PWM_SYNC_KILL_SHIFT))

#define TCPWM_3_CTRL_PWM_DEAD_TIME_CYCLE                                                       \
            ((uint32)(TCPWM_3_PWM_DEAD_TIME_CYCLE  << TCPWM_3_PRESCALER_SHIFT))

#define TCPWM_3_CTRL_PWM_PRESCALER                                                             \
            ((uint32)(TCPWM_3_PWM_PRESCALER        << TCPWM_3_PRESCALER_SHIFT))

#define TCPWM_3_CTRL_TIMER_BASE_CONFIG                                                         \
        (((uint32)(TCPWM_3_TC_PRESCALER            << TCPWM_3_PRESCALER_SHIFT))       |\
         ((uint32)(TCPWM_3_TC_COUNTER_MODE         << TCPWM_3_UPDOWN_SHIFT))          |\
         ((uint32)(TCPWM_3_TC_RUN_MODE             << TCPWM_3_ONESHOT_SHIFT))         |\
         ((uint32)(TCPWM_3_TC_COMP_CAP_MODE        << TCPWM_3_MODE_SHIFT)))
        
#define TCPWM_3_QUAD_SIGNALS_MODES                                                             \
        (((uint32)(TCPWM_3_QUAD_PHIA_SIGNAL_MODE   << TCPWM_3_COUNT_SHIFT))           |\
         ((uint32)(TCPWM_3_QUAD_INDEX_SIGNAL_MODE  << TCPWM_3_RELOAD_SHIFT))          |\
         ((uint32)(TCPWM_3_QUAD_STOP_SIGNAL_MODE   << TCPWM_3_STOP_SHIFT))            |\
         ((uint32)(TCPWM_3_QUAD_PHIB_SIGNAL_MODE   << TCPWM_3_START_SHIFT)))

#define TCPWM_3_PWM_SIGNALS_MODES                                                              \
        (((uint32)(TCPWM_3_PWM_SWITCH_SIGNAL_MODE  << TCPWM_3_CAPTURE_SHIFT))         |\
         ((uint32)(TCPWM_3_PWM_COUNT_SIGNAL_MODE   << TCPWM_3_COUNT_SHIFT))           |\
         ((uint32)(TCPWM_3_PWM_RELOAD_SIGNAL_MODE  << TCPWM_3_RELOAD_SHIFT))          |\
         ((uint32)(TCPWM_3_PWM_STOP_SIGNAL_MODE    << TCPWM_3_STOP_SHIFT))            |\
         ((uint32)(TCPWM_3_PWM_START_SIGNAL_MODE   << TCPWM_3_START_SHIFT)))

#define TCPWM_3_TIMER_SIGNALS_MODES                                                            \
        (((uint32)(TCPWM_3_TC_CAPTURE_SIGNAL_MODE  << TCPWM_3_CAPTURE_SHIFT))         |\
         ((uint32)(TCPWM_3_TC_COUNT_SIGNAL_MODE    << TCPWM_3_COUNT_SHIFT))           |\
         ((uint32)(TCPWM_3_TC_RELOAD_SIGNAL_MODE   << TCPWM_3_RELOAD_SHIFT))          |\
         ((uint32)(TCPWM_3_TC_STOP_SIGNAL_MODE     << TCPWM_3_STOP_SHIFT))            |\
         ((uint32)(TCPWM_3_TC_START_SIGNAL_MODE    << TCPWM_3_START_SHIFT)))
        
#define TCPWM_3_TIMER_UPDOWN_CNT_USED                                                          \
                ((TCPWM_3__COUNT_UPDOWN0 == TCPWM_3_TC_COUNTER_MODE)                  ||\
                 (TCPWM_3__COUNT_UPDOWN1 == TCPWM_3_TC_COUNTER_MODE))

#define TCPWM_3_PWM_UPDOWN_CNT_USED                                                            \
                ((TCPWM_3__CENTER == TCPWM_3_PWM_ALIGN)                               ||\
                 (TCPWM_3__ASYMMETRIC == TCPWM_3_PWM_ALIGN))               
        
#define TCPWM_3_PWM_PR_INIT_VALUE              (1u)
#define TCPWM_3_QUAD_PERIOD_INIT_VALUE         (0x8000u)



#endif /* End CY_TCPWM_TCPWM_3_H */

/* [] END OF FILE */
