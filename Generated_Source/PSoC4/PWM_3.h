/*******************************************************************************
* File Name: PWM_3.h
* Version 1.0
*
* Description:
*  This file provides constants and parameter values for the PWM_3
*  component.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_TCPWM_PWM_3_H)
#define CY_TCPWM_PWM_3_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cyLib.h"


/***************************************
*   Conditional Compilation Parameters
****************************************/

/* TCPWM */
#define PWM_3_CONFIG                            (7u)

/* Quad */
/* Parameters */
#define PWM_3_QUAD_ENCODING_MODES            (0u)

/* Signal modes */
#define PWM_3_QUAD_INDEX_SIGNAL_MODE         (0u)
#define PWM_3_QUAD_PHIA_SIGNAL_MODE          (3u)
#define PWM_3_QUAD_PHIB_SIGNAL_MODE          (3u)
#define PWM_3_QUAD_STOP_SIGNAL_MODE          (0u)

/* Signal present */
#define PWM_3_QUAD_INDEX_SIGNAL_PRESENT      (1u)
#define PWM_3_QUAD_STOP_SIGNAL_PRESENT       (1u)

/* Interrupt Mask */
#define PWM_3_QUAD_INTERRUPT_MASK              (1u)

/* Timer/Counter */
/* Parameters */
#define PWM_3_TC_RUN_MODE                    (0u)
#define PWM_3_TC_COUNTER_MODE                (0u)
#define PWM_3_TC_COMP_CAP_MODE               (2u)
#define PWM_3_TC_PRESCALER                    (0u)

/* Signal modes */
#define PWM_3_TC_RELOAD_SIGNAL_MODE          (0u)
#define PWM_3_TC_COUNT_SIGNAL_MODE           (0u)
#define PWM_3_TC_START_SIGNAL_MODE           (0u)
#define PWM_3_TC_STOP_SIGNAL_MODE            (0u)
#define PWM_3_TC_CAPTURE_SIGNAL_MODE         (0u)

/* Signal present */
#define PWM_3_TC_RELOAD_SIGNAL_PRESENT       (1u)
#define PWM_3_TC_COUNT_SIGNAL_PRESENT        (1u)
#define PWM_3_TC_START_SIGNAL_PRESENT        (1u)
#define PWM_3_TC_STOP_SIGNAL_PRESENT         (1u)
#define PWM_3_TC_CAPTURE_SIGNAL_PRESENT      (1u)

/* Interrupt Mask */
#define PWM_3_TC_INTERRUPT_MASK              (1u)

/* PWM */
/* Parameters */
#define PWM_3_PWM_KILL_EVENT                    (0u)
#define PWM_3_PWM_STOP_EVENT                    (0u)
#define PWM_3_PWM_MODE                        (4u)
#define PWM_3_PWM_OUT_N_INVERT                  (0u)
#define PWM_3_PWM_OUT_INVERT                  (0u)
#define PWM_3_PWM_ALIGN                          (0u)
#define PWM_3_PWM_RUN_MODE                   (0u)

#define PWM_3_PWM_DEAD_TIME_CYCLE             (0u)
#define PWM_3_PWM_PRESCALER                    (0u)

/* Signal modes */
#define PWM_3_PWM_RELOAD_SIGNAL_MODE         (0u)
#define PWM_3_PWM_COUNT_SIGNAL_MODE          (0u)
#define PWM_3_PWM_START_SIGNAL_MODE          (0u)
#define PWM_3_PWM_STOP_SIGNAL_MODE           (0u)
#define PWM_3_PWM_SWITCH_SIGNAL_MODE         (0u)

/* Signal present */
#define PWM_3_PWM_RELOAD_SIGNAL_PRESENT      (0u)
#define PWM_3_PWM_COUNT_SIGNAL_PRESENT       (0u)
#define PWM_3_PWM_START_SIGNAL_PRESENT       (0u)
#define PWM_3_PWM_STOP_SIGNAL_PRESENT        (0u)
#define PWM_3_PWM_SWITCH_SIGNAL_PRESENT      (0u)

/* Interrupt Mask */
#define PWM_3_PWM_INTERRUPT_MASK              (1u)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter */
#define PWM_3_TC_PERIOD_VALUE                (65535u)
#define PWM_3_TC_COMPARE_VALUE                (65535u)
#define PWM_3_TC_COMPARE_BUF_VALUE            (65535u)
#define PWM_3_TC_COMPARE_SWAP                 (0u)

/* PWM */
#define PWM_3_PWM_PERIOD_VALUE               (5000u)
#define PWM_3_PWM_PERIOD_BUF_VALUE           (65535u)
#define PWM_3_PWM_PERIOD_SWAP                (0u)
#define PWM_3_PWM_COMPARE_VALUE              (2500u)
#define PWM_3_PWM_COMPARE_BUF_VALUE          (65535u)
#define PWM_3_PWM_COMPARE_SWAP               (0u)


/***************************************
*       Type defines
***************************************/

#define PWM_3_FALSE                          (0x0u)
#define PWM_3_TRUE                           (0x1u)


/***************************************
*       Enum Types
***************************************/

/* TCPWM set modes */
#define PWM_3_MODE_TIMER_COMPARE             (0x0u) << (24u)
#define PWM_3_MODE_TIMER_CAPTURE             (0x2u) << (24u)
#define PWM_3_MODE_QUAD                      (0x3u) << (24u)
#define PWM_3_MODE_PWM                       (0x4u) << (24u)
#define PWM_3_MODE_PWM_DT                    (0x5u) << (24u)
#define PWM_3_MODE_PWM_PR                    (0x6u) << (24u)

/* Prescaler */
#define PWM_3_PRESCALE_DIVBY1                (0x0u) << (8u)
#define PWM_3_PRESCALE_DIVBY2                (0x1u) << (8u)
#define PWM_3_PRESCALE_DIVBY4                (0x2u) << (8u)
#define PWM_3_PRESCALE_DIVBY8                (0x3u) << (8u)
#define PWM_3_PRESCALE_DIVBY16               (0x4u) << (8u)
#define PWM_3_PRESCALE_DIVBY32               (0x5u) << (8u)
#define PWM_3_PRESCALE_DIVBY64               (0x6u) << (8u)
#define PWM_3_PRESCALE_DIVBY128              (0x7u) << (8u)

/* One Shot */
#define PWM_3_CONTROL_ONESHOT                (18u)

/* Sync Kill */
#define PWM_3_CONTROL_PWM_SYNC_KILL            (2u)

/* Stop Kill */
#define PWM_3_CONTROL_PWM_STOP_KILL            (3u)

/* Command operations without condition */
#define PWM_3_CMD_CAPTURE                    (0u)
#define PWM_3_CMD_RELOAD                     (8u)
#define PWM_3_CMD_STOP                       (16u)
#define PWM_3_CMD_START                      (24u)

/* PWM Mode */
#define PWM_3_CC_MATCH_SET                   (0x0u)
#define PWM_3_CC_MATCH_CLEAR                 (0x1u)
#define PWM_3_CC_MATCH_INVERT                (0x2u)
#define PWM_3_CC_MATCH_NO_CHANGE             (0x3u)
#define PWM_3_OVERLOW_SET                    (0x0u)
#define PWM_3_OVERLOW_CLEAR                  (0x4u)
#define PWM_3_OVERLOW_INVERT                 (0x8u)
#define PWM_3_OVERLOW_NO_CHANGE              (0xCu)
#define PWM_3_UNDERFLOW_SET                  (0x0u)
#define PWM_3_UNDERFLOW_CLEAR                (0x10u)
#define PWM_3_UNDERFLOW_INVERT               (0x20u)
#define PWM_3_UNDERFLOW_NO_CHANGE            (0x30u)
#define PWM_3_PWM_MODE_LEFT                  (0x0u)
#define PWM_3_PWM_MODE_RIGHT                 (0x10000u)
#define PWM_3_PWM_MODE_CENTER                (0x20000u)
#define PWM_3_PWM_MODE_ASYM                  (0x30000u)

/* PWM output invert */
#define PWM_3_INVERT_LINE                    (0x1u) << (20u)
#define PWM_3_INVERT_LINE_N                  (0x1u) << (21u)

/* Quad Mode */
#define PWM_3_MODE_X1                        (0x0u) << (20u)
#define PWM_3_MODE_X2                        (0x1u) << (20u)
#define PWM_3_MODE_X4                        (0x2u) << (20u)

/* Interrupt mask */
#define PWM_3_INTR_MASK_TC                   (0x1u)
#define PWM_3_INTR_MASK_CC_MATCH             (0x1u) << (1u)

/* Counter modes */
#define PWM_3_COUNT_UP                       (0x0u)<< (16u)
#define PWM_3_COUNT_DOWN                     (0x1u)<< (16u)
#define PWM_3_COUNT_UPDOWN0                  (0x2u)<< (16u)
#define PWM_3_COUNT_UPDOWN1                  (0x3u)<< (16u)

/* Trigger modes */
#define PWM_3_TRIG_RISING                    (0x0u)
#define PWM_3_TRIG_FALLING                   (0x1u)
#define PWM_3_TRIG_BOTH                      (0x2u)
#define PWM_3_TRIG_LEVEL                     (0x3u)

/* Status */
#define PWM_3_STATUS_DOWN                    (0x1u)
#define PWM_3_STATUS_RUNNING                 (0x2u)

/* Customizer types */
#define PWM_3_TIMER                          (0x1u)
#define PWM_3_QUAD                           (0x3u)
#define PWM_3_PWM_SEL                        (0x7u)
#define PWM_3_UNCONFIG                       (0x8u)

#define PWM_3_PWM                            (0x4u)
#define PWM_3_PWM_DT                         (0x5u)
#define PWM_3_PWM_PR                         (0x6u)

#define PWM_3_PWM_LEFT                       (0x0u)
#define PWM_3_PWM_RIGHT                      (0x1u)
#define PWM_3_PWM_CENTER                     (0x2u)
#define PWM_3_PWM_ASYM                       (0x3u)


/***************************************
*        Function Prototypes
****************************************/

void PWM_3_Init(void);
void PWM_3_Enable(void);
void PWM_3_Start(void);
void PWM_3_Stop(void);
void PWM_3_SetMode(uint32 mode);
void PWM_3_SetPrescaler(uint32 prescaler);
void PWM_3_TriggerCommand(uint32 mask, uint32 command);
void PWM_3_SetOneShot(uint32 oneShotEnable);
void PWM_3_SetPWMMode(uint32 modeMask);
void PWM_3_SetPWMSyncKill(uint32 syncKillEnable);
void PWM_3_SetPWMStopOnKill(uint32 stopOnKillEnable);
void PWM_3_SetPWMDeadTime(uint32 deadTime);
void PWM_3_SetPWMInvert(uint32 mask);
void PWM_3_SetQDMode(uint32 qdmode);
void PWM_3_SetInterruptMode(uint32 interruptMask);
uint32 PWM_3_GetInterruptSourceMasked(void);
uint32 PWM_3_GetInterruptSource(void);
void PWM_3_ClearInterrupt(uint32 interruptMask);
void PWM_3_SetInterrupt(uint32 interruptMask);
void PWM_3_WriteCounter(uint32 count);
uint32 PWM_3_ReadCounter(void);
void PWM_3_SetCounterMode(uint32 counterMode);
void PWM_3_SetPeriodSwap(uint32 swapEnable);
void PWM_3_SetCompareSwap(uint32 swapEnable);
uint32 PWM_3_ReadCapture(void);
uint32 PWM_3_ReadCaptureBuf(void);
void PWM_3_WritePeriod(uint32 period);
uint32 PWM_3_ReadPeriod(void);
void PWM_3_WritePeriodBuf(uint32 periodbuf);
uint32 PWM_3_ReadPeriodBuf(void);
void PWM_3_WriteCompare(uint32 compare);
uint32 PWM_3_ReadCompare(void);
void PWM_3_WriteCompareBuf(uint32 comparebuf);
uint32 PWM_3_ReadCompareBuf(void);
void PWM_3_SetCaptureMode(uint32 triggerMode);
void PWM_3_SetReloadMode(uint32 triggerMode);
void PWM_3_SetStartMode(uint32 triggerMode);
void PWM_3_SetStopMode(uint32 triggerMode);
void PWM_3_SetCountMode(uint32 triggerMode);
uint32 PWM_3_ReadStatus(void);


/***************************************
*             Registers
***************************************/

#define PWM_3_BLOCK_CONTROL_REG    (*(reg32 *) PWM_3_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define PWM_3_BLOCK_CONTROL_PTR    ( (reg32 *) PWM_3_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define PWM_3_COMMAND_REG          (*(reg32 *) PWM_3_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define PWM_3_COMMAND_PTR          ( (reg32 *) PWM_3_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define PWM_3_INTRRUPT_CAUSE_REG   (*(reg32 *) PWM_3_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define PWM_3_INTRRUPT_CAUSE_PTR   ( (reg32 *) PWM_3_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define PWM_3_CONTROL_REG          (*(reg32 *) PWM_3_cy_m0s8_tcpwm_1__CTRL )
#define PWM_3_CONTROL_PTR          ( (reg32 *) PWM_3_cy_m0s8_tcpwm_1__CTRL )
#define PWM_3_STATUS_REG           (*(reg32 *) PWM_3_cy_m0s8_tcpwm_1__STATUS )
#define PWM_3_STATUS_PTR           ( (reg32 *) PWM_3_cy_m0s8_tcpwm_1__STATUS )
#define PWM_3_COUNTER_REG          (*(reg32 *) PWM_3_cy_m0s8_tcpwm_1__COUNTER )
#define PWM_3_COUNTER_PTR          ( (reg32 *) PWM_3_cy_m0s8_tcpwm_1__COUNTER )
#define PWM_3_COMP_CAP_REG         (*(reg32 *) PWM_3_cy_m0s8_tcpwm_1__CC )
#define PWM_3_COMP_CAP_PTR         ( (reg32 *) PWM_3_cy_m0s8_tcpwm_1__CC )
#define PWM_3_COMP_CAP_BUF_REG     (*(reg32 *) PWM_3_cy_m0s8_tcpwm_1__CC_BUFF )
#define PWM_3_COMP_CAP_BUF_PTR     ( (reg32 *) PWM_3_cy_m0s8_tcpwm_1__CC_BUFF )
#define PWM_3_PERIOD_REG           (*(reg32 *) PWM_3_cy_m0s8_tcpwm_1__PERIOD )
#define PWM_3_PERIOD_PTR           ( (reg32 *) PWM_3_cy_m0s8_tcpwm_1__PERIOD )
#define PWM_3_PERIOD_BUF_REG       (*(reg32 *) PWM_3_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define PWM_3_PERIOD_BUF_PTR       ( (reg32 *) PWM_3_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define PWM_3_TRIG_CONTROL0_REG    (*(reg32 *) PWM_3_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define PWM_3_TRIG_CONTROL0_PTR    ( (reg32 *) PWM_3_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define PWM_3_TRIG_CONTROL1_REG    (*(reg32 *) PWM_3_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define PWM_3_TRIG_CONTROL1_PTR    ( (reg32 *) PWM_3_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define PWM_3_TRIG_CONTROL2_REG    (*(reg32 *) PWM_3_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define PWM_3_TRIG_CONTROL2_PTR    ( (reg32 *) PWM_3_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define PWM_3_INTERRUPT_REQ_REG    (*(reg32 *) PWM_3_cy_m0s8_tcpwm_1__INTR )
#define PWM_3_INTERRUPT_REQ_PTR    ( (reg32 *) PWM_3_cy_m0s8_tcpwm_1__INTR )
#define PWM_3_INTERRUPT_SET_REG    (*(reg32 *) PWM_3_cy_m0s8_tcpwm_1__INTR_SET )
#define PWM_3_INTERRUPT_SET_PTR    ( (reg32 *) PWM_3_cy_m0s8_tcpwm_1__INTR_SET )
#define PWM_3_INTERRUPT_MASK_REG   (*(reg32 *) PWM_3_cy_m0s8_tcpwm_1__INTR_MASK )
#define PWM_3_INTERRUPT_MASK_PTR   ( (reg32 *) PWM_3_cy_m0s8_tcpwm_1__INTR_MASK )
#define PWM_3_INTERRUPT_MASKED_REG (*(reg32 *) PWM_3_cy_m0s8_tcpwm_1__INTR_MASKED )
#define PWM_3_INTERRUPT_MASKED_PTR ( (reg32 *) PWM_3_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Register Constants
***************************************/

/* Mask */
#define PWM_3_MASK                 (PWM_3_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Constants for default control register */
#define PWM_3_CONTROL_RELOAD_CC              (0u)
#define PWM_3_CONTROL_RELOAD_PERIOD            (1u)
#define PWM_3_CONTROL_PWM_SYNC_KILL            (2u)
#define PWM_3_CONTROL_PWM_STOP_KILL            (3u)
#define PWM_3_CONTROL_PRESCALER              (8u)
#define PWM_3_CONTROL_UPDOWN                 (16u)
#define PWM_3_CONTROL_ONESHOT                (18u)
#define PWM_3_CONTROL_QUAD_MODE              (20u)
#define PWM_3_CONTROL_INV_OUT                (20u)
#define PWM_3_CONTROL_INV_COMPL_OUT          (21u)
#define PWM_3_CONTROL_MODE                   (24u)

/* Input signal constants for trigger control register 1 */
#define PWM_3_CAPTURE_SIGNAL                 (0x0u)
#define PWM_3_COUNT_SIGNAL                   (0x2u)
#define PWM_3_RELOAD_SIGNAL                  (0x4u)
#define PWM_3_STOP_SIGNAL                    (0x6u)
#define PWM_3_START_SIGNAL                   (0x8u)

/* Mask constants for trigger control register 1 */
#define PWM_3_CAPTURE_MASK                   ~(PWM_3_2X_REG_MASK << (0x0u))
#define PWM_3_COUNT_MASK                     ~(PWM_3_2X_REG_MASK << (0x2u))
#define PWM_3_RELOAD_MASK                    ~(PWM_3_2X_REG_MASK << (0x4u))
#define PWM_3_STOP_MASK                      ~(PWM_3_2X_REG_MASK << (0x6u))
#define PWM_3_START_MASK                     ~(PWM_3_2X_REG_MASK << (0x8u))

/* MASK */
#define PWM_3_1X_REG_MASK                    (0x1u)
#define PWM_3_2X_REG_MASK                    (0x3u)
#define PWM_3_3X_REG_MASK                    (0x7u)
#define PWM_3_4X_REG_MASK                    (0xFu)
#define PWM_3_8X_REG_MASK                    (0xFFu)

/* Mask constants for control register */
#define PWM_3_CONTROL_RELOAD_CC_MASK         ~(PWM_3_1X_REG_MASK)
#define PWM_3_CONTROL_RELOAD_PERIOD_MASK        ~(PWM_3_1X_REG_MASK << (1u))
#define PWM_3_CONTROL_PWM_SYNC_KILL_MASK        ~(PWM_3_1X_REG_MASK << (2u))
#define PWM_3_CONTROL_PWM_STOP_KILL_MASK        ~(PWM_3_1X_REG_MASK << (3u))
#define PWM_3_CONTROL_PRESCALER_MASK         ~(PWM_3_8X_REG_MASK << (8u))
#define PWM_3_CONTROL_UPDOWN_MASK            ~(PWM_3_2X_REG_MASK << (16u))
#define PWM_3_CONTROL_ONESHOT_MASK           ~(PWM_3_1X_REG_MASK << (18u))
#define PWM_3_CONTROL_QUAD_MODE_MASK         ~(PWM_3_2X_REG_MASK << (20u))
#define PWM_3_CONTROL_INV_OUT_MASK           ~(PWM_3_2X_REG_MASK << (20u))
#define PWM_3_CONTROL_MODE_MASK              ~(PWM_3_3X_REG_MASK << (24u))

/* Status register definitions */
#define PWM_3_COUNTDOWN_STATUS               (1u)
#define PWM_3_RUNNING_STATUS                 (30u)


#endif /* End CY_TCPWM_PWM_3_H */

/* [] END OF FILE */
