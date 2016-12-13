/*******************************************************************************
* File Name: PWM2_Sine.h
* Version 1.0
*
* Description:
*  This file provides constants and parameter values for the PWM2_Sine
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

#if !defined(CY_TCPWM_PWM2_Sine_H)
#define CY_TCPWM_PWM2_Sine_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cyLib.h"


/***************************************
*   Conditional Compilation Parameters
****************************************/

/* TCPWM */
#define PWM2_Sine_CONFIG                            (7u)

/* Quad */
/* Parameters */
#define PWM2_Sine_QUAD_ENCODING_MODES            (0u)

/* Signal modes */
#define PWM2_Sine_QUAD_INDEX_SIGNAL_MODE         (0u)
#define PWM2_Sine_QUAD_PHIA_SIGNAL_MODE          (3u)
#define PWM2_Sine_QUAD_PHIB_SIGNAL_MODE          (3u)
#define PWM2_Sine_QUAD_STOP_SIGNAL_MODE          (0u)

/* Signal present */
#define PWM2_Sine_QUAD_INDEX_SIGNAL_PRESENT      (1u)
#define PWM2_Sine_QUAD_STOP_SIGNAL_PRESENT       (1u)

/* Interrupt Mask */
#define PWM2_Sine_QUAD_INTERRUPT_MASK              (1u)

/* Timer/Counter */
/* Parameters */
#define PWM2_Sine_TC_RUN_MODE                    (0u)
#define PWM2_Sine_TC_COUNTER_MODE                (0u)
#define PWM2_Sine_TC_COMP_CAP_MODE               (2u)
#define PWM2_Sine_TC_PRESCALER                    (0u)

/* Signal modes */
#define PWM2_Sine_TC_RELOAD_SIGNAL_MODE          (0u)
#define PWM2_Sine_TC_COUNT_SIGNAL_MODE           (0u)
#define PWM2_Sine_TC_START_SIGNAL_MODE           (0u)
#define PWM2_Sine_TC_STOP_SIGNAL_MODE            (0u)
#define PWM2_Sine_TC_CAPTURE_SIGNAL_MODE         (0u)

/* Signal present */
#define PWM2_Sine_TC_RELOAD_SIGNAL_PRESENT       (1u)
#define PWM2_Sine_TC_COUNT_SIGNAL_PRESENT        (1u)
#define PWM2_Sine_TC_START_SIGNAL_PRESENT        (1u)
#define PWM2_Sine_TC_STOP_SIGNAL_PRESENT         (1u)
#define PWM2_Sine_TC_CAPTURE_SIGNAL_PRESENT      (1u)

/* Interrupt Mask */
#define PWM2_Sine_TC_INTERRUPT_MASK              (1u)

/* PWM */
/* Parameters */
#define PWM2_Sine_PWM_KILL_EVENT                    (0u)
#define PWM2_Sine_PWM_STOP_EVENT                    (0u)
#define PWM2_Sine_PWM_MODE                        (4u)
#define PWM2_Sine_PWM_OUT_N_INVERT                  (0u)
#define PWM2_Sine_PWM_OUT_INVERT                  (0u)
#define PWM2_Sine_PWM_ALIGN                          (3u)
#define PWM2_Sine_PWM_RUN_MODE                   (0u)

#define PWM2_Sine_PWM_DEAD_TIME_CYCLE             (0u)
#define PWM2_Sine_PWM_PRESCALER                    (0u)

/* Signal modes */
#define PWM2_Sine_PWM_RELOAD_SIGNAL_MODE         (0u)
#define PWM2_Sine_PWM_COUNT_SIGNAL_MODE          (0u)
#define PWM2_Sine_PWM_START_SIGNAL_MODE          (0u)
#define PWM2_Sine_PWM_STOP_SIGNAL_MODE           (0u)
#define PWM2_Sine_PWM_SWITCH_SIGNAL_MODE         (0u)

/* Signal present */
#define PWM2_Sine_PWM_RELOAD_SIGNAL_PRESENT      (0u)
#define PWM2_Sine_PWM_COUNT_SIGNAL_PRESENT       (0u)
#define PWM2_Sine_PWM_START_SIGNAL_PRESENT       (0u)
#define PWM2_Sine_PWM_STOP_SIGNAL_PRESENT        (0u)
#define PWM2_Sine_PWM_SWITCH_SIGNAL_PRESENT      (0u)

/* Interrupt Mask */
#define PWM2_Sine_PWM_INTERRUPT_MASK              (1u)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter */
#define PWM2_Sine_TC_PERIOD_VALUE                (65535u)
#define PWM2_Sine_TC_COMPARE_VALUE                (65535u)
#define PWM2_Sine_TC_COMPARE_BUF_VALUE            (65535u)
#define PWM2_Sine_TC_COMPARE_SWAP                 (0u)

/* PWM */
#define PWM2_Sine_PWM_PERIOD_VALUE               (255u)
#define PWM2_Sine_PWM_PERIOD_BUF_VALUE           (65535u)
#define PWM2_Sine_PWM_PERIOD_SWAP                (0u)
#define PWM2_Sine_PWM_COMPARE_VALUE              (254u)
#define PWM2_Sine_PWM_COMPARE_BUF_VALUE          (65535u)
#define PWM2_Sine_PWM_COMPARE_SWAP               (0u)


/***************************************
*       Type defines
***************************************/

#define PWM2_Sine_FALSE                          (0x0u)
#define PWM2_Sine_TRUE                           (0x1u)


/***************************************
*       Enum Types
***************************************/

/* TCPWM set modes */
#define PWM2_Sine_MODE_TIMER_COMPARE             (0x0u) << (24u)
#define PWM2_Sine_MODE_TIMER_CAPTURE             (0x2u) << (24u)
#define PWM2_Sine_MODE_QUAD                      (0x3u) << (24u)
#define PWM2_Sine_MODE_PWM                       (0x4u) << (24u)
#define PWM2_Sine_MODE_PWM_DT                    (0x5u) << (24u)
#define PWM2_Sine_MODE_PWM_PR                    (0x6u) << (24u)

/* Prescaler */
#define PWM2_Sine_PRESCALE_DIVBY1                (0x0u) << (8u)
#define PWM2_Sine_PRESCALE_DIVBY2                (0x1u) << (8u)
#define PWM2_Sine_PRESCALE_DIVBY4                (0x2u) << (8u)
#define PWM2_Sine_PRESCALE_DIVBY8                (0x3u) << (8u)
#define PWM2_Sine_PRESCALE_DIVBY16               (0x4u) << (8u)
#define PWM2_Sine_PRESCALE_DIVBY32               (0x5u) << (8u)
#define PWM2_Sine_PRESCALE_DIVBY64               (0x6u) << (8u)
#define PWM2_Sine_PRESCALE_DIVBY128              (0x7u) << (8u)

/* One Shot */
#define PWM2_Sine_CONTROL_ONESHOT                (18u)

/* Sync Kill */
#define PWM2_Sine_CONTROL_PWM_SYNC_KILL            (2u)

/* Stop Kill */
#define PWM2_Sine_CONTROL_PWM_STOP_KILL            (3u)

/* Command operations without condition */
#define PWM2_Sine_CMD_CAPTURE                    (0u)
#define PWM2_Sine_CMD_RELOAD                     (8u)
#define PWM2_Sine_CMD_STOP                       (16u)
#define PWM2_Sine_CMD_START                      (24u)

/* PWM Mode */
#define PWM2_Sine_CC_MATCH_SET                   (0x0u)
#define PWM2_Sine_CC_MATCH_CLEAR                 (0x1u)
#define PWM2_Sine_CC_MATCH_INVERT                (0x2u)
#define PWM2_Sine_CC_MATCH_NO_CHANGE             (0x3u)
#define PWM2_Sine_OVERLOW_SET                    (0x0u)
#define PWM2_Sine_OVERLOW_CLEAR                  (0x4u)
#define PWM2_Sine_OVERLOW_INVERT                 (0x8u)
#define PWM2_Sine_OVERLOW_NO_CHANGE              (0xCu)
#define PWM2_Sine_UNDERFLOW_SET                  (0x0u)
#define PWM2_Sine_UNDERFLOW_CLEAR                (0x10u)
#define PWM2_Sine_UNDERFLOW_INVERT               (0x20u)
#define PWM2_Sine_UNDERFLOW_NO_CHANGE            (0x30u)
#define PWM2_Sine_PWM_MODE_LEFT                  (0x0u)
#define PWM2_Sine_PWM_MODE_RIGHT                 (0x10000u)
#define PWM2_Sine_PWM_MODE_CENTER                (0x20000u)
#define PWM2_Sine_PWM_MODE_ASYM                  (0x30000u)

/* PWM output invert */
#define PWM2_Sine_INVERT_LINE                    (0x1u) << (20u)
#define PWM2_Sine_INVERT_LINE_N                  (0x1u) << (21u)

/* Quad Mode */
#define PWM2_Sine_MODE_X1                        (0x0u) << (20u)
#define PWM2_Sine_MODE_X2                        (0x1u) << (20u)
#define PWM2_Sine_MODE_X4                        (0x2u) << (20u)

/* Interrupt mask */
#define PWM2_Sine_INTR_MASK_TC                   (0x1u)
#define PWM2_Sine_INTR_MASK_CC_MATCH             (0x1u) << (1u)

/* Counter modes */
#define PWM2_Sine_COUNT_UP                       (0x0u)<< (16u)
#define PWM2_Sine_COUNT_DOWN                     (0x1u)<< (16u)
#define PWM2_Sine_COUNT_UPDOWN0                  (0x2u)<< (16u)
#define PWM2_Sine_COUNT_UPDOWN1                  (0x3u)<< (16u)

/* Trigger modes */
#define PWM2_Sine_TRIG_RISING                    (0x0u)
#define PWM2_Sine_TRIG_FALLING                   (0x1u)
#define PWM2_Sine_TRIG_BOTH                      (0x2u)
#define PWM2_Sine_TRIG_LEVEL                     (0x3u)

/* Status */
#define PWM2_Sine_STATUS_DOWN                    (0x1u)
#define PWM2_Sine_STATUS_RUNNING                 (0x2u)

/* Customizer types */
#define PWM2_Sine_TIMER                          (0x1u)
#define PWM2_Sine_QUAD                           (0x3u)
#define PWM2_Sine_PWM_SEL                        (0x7u)
#define PWM2_Sine_UNCONFIG                       (0x8u)

#define PWM2_Sine_PWM                            (0x4u)
#define PWM2_Sine_PWM_DT                         (0x5u)
#define PWM2_Sine_PWM_PR                         (0x6u)

#define PWM2_Sine_PWM_LEFT                       (0x0u)
#define PWM2_Sine_PWM_RIGHT                      (0x1u)
#define PWM2_Sine_PWM_CENTER                     (0x2u)
#define PWM2_Sine_PWM_ASYM                       (0x3u)


/***************************************
*        Function Prototypes
****************************************/

void PWM2_Sine_Init(void);
void PWM2_Sine_Enable(void);
void PWM2_Sine_Start(void);
void PWM2_Sine_Stop(void);
void PWM2_Sine_SetMode(uint32 mode);
void PWM2_Sine_SetPrescaler(uint32 prescaler);
void PWM2_Sine_TriggerCommand(uint32 mask, uint32 command);
void PWM2_Sine_SetOneShot(uint32 oneShotEnable);
void PWM2_Sine_SetPWMMode(uint32 modeMask);
void PWM2_Sine_SetPWMSyncKill(uint32 syncKillEnable);
void PWM2_Sine_SetPWMStopOnKill(uint32 stopOnKillEnable);
void PWM2_Sine_SetPWMDeadTime(uint32 deadTime);
void PWM2_Sine_SetPWMInvert(uint32 mask);
void PWM2_Sine_SetQDMode(uint32 qdmode);
void PWM2_Sine_SetInterruptMode(uint32 interruptMask);
uint32 PWM2_Sine_GetInterruptSourceMasked(void);
uint32 PWM2_Sine_GetInterruptSource(void);
void PWM2_Sine_ClearInterrupt(uint32 interruptMask);
void PWM2_Sine_SetInterrupt(uint32 interruptMask);
void PWM2_Sine_WriteCounter(uint32 count);
uint32 PWM2_Sine_ReadCounter(void);
void PWM2_Sine_SetCounterMode(uint32 counterMode);
void PWM2_Sine_SetPeriodSwap(uint32 swapEnable);
void PWM2_Sine_SetCompareSwap(uint32 swapEnable);
uint32 PWM2_Sine_ReadCapture(void);
uint32 PWM2_Sine_ReadCaptureBuf(void);
void PWM2_Sine_WritePeriod(uint32 period);
uint32 PWM2_Sine_ReadPeriod(void);
void PWM2_Sine_WritePeriodBuf(uint32 periodbuf);
uint32 PWM2_Sine_ReadPeriodBuf(void);
void PWM2_Sine_WriteCompare(uint32 compare);
uint32 PWM2_Sine_ReadCompare(void);
void PWM2_Sine_WriteCompareBuf(uint32 comparebuf);
uint32 PWM2_Sine_ReadCompareBuf(void);
void PWM2_Sine_SetCaptureMode(uint32 triggerMode);
void PWM2_Sine_SetReloadMode(uint32 triggerMode);
void PWM2_Sine_SetStartMode(uint32 triggerMode);
void PWM2_Sine_SetStopMode(uint32 triggerMode);
void PWM2_Sine_SetCountMode(uint32 triggerMode);
uint32 PWM2_Sine_ReadStatus(void);


/***************************************
*             Registers
***************************************/

#define PWM2_Sine_BLOCK_CONTROL_REG    (*(reg32 *) PWM2_Sine_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define PWM2_Sine_BLOCK_CONTROL_PTR    ( (reg32 *) PWM2_Sine_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define PWM2_Sine_COMMAND_REG          (*(reg32 *) PWM2_Sine_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define PWM2_Sine_COMMAND_PTR          ( (reg32 *) PWM2_Sine_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define PWM2_Sine_INTRRUPT_CAUSE_REG   (*(reg32 *) PWM2_Sine_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define PWM2_Sine_INTRRUPT_CAUSE_PTR   ( (reg32 *) PWM2_Sine_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define PWM2_Sine_CONTROL_REG          (*(reg32 *) PWM2_Sine_cy_m0s8_tcpwm_1__CTRL )
#define PWM2_Sine_CONTROL_PTR          ( (reg32 *) PWM2_Sine_cy_m0s8_tcpwm_1__CTRL )
#define PWM2_Sine_STATUS_REG           (*(reg32 *) PWM2_Sine_cy_m0s8_tcpwm_1__STATUS )
#define PWM2_Sine_STATUS_PTR           ( (reg32 *) PWM2_Sine_cy_m0s8_tcpwm_1__STATUS )
#define PWM2_Sine_COUNTER_REG          (*(reg32 *) PWM2_Sine_cy_m0s8_tcpwm_1__COUNTER )
#define PWM2_Sine_COUNTER_PTR          ( (reg32 *) PWM2_Sine_cy_m0s8_tcpwm_1__COUNTER )
#define PWM2_Sine_COMP_CAP_REG         (*(reg32 *) PWM2_Sine_cy_m0s8_tcpwm_1__CC )
#define PWM2_Sine_COMP_CAP_PTR         ( (reg32 *) PWM2_Sine_cy_m0s8_tcpwm_1__CC )
#define PWM2_Sine_COMP_CAP_BUF_REG     (*(reg32 *) PWM2_Sine_cy_m0s8_tcpwm_1__CC_BUFF )
#define PWM2_Sine_COMP_CAP_BUF_PTR     ( (reg32 *) PWM2_Sine_cy_m0s8_tcpwm_1__CC_BUFF )
#define PWM2_Sine_PERIOD_REG           (*(reg32 *) PWM2_Sine_cy_m0s8_tcpwm_1__PERIOD )
#define PWM2_Sine_PERIOD_PTR           ( (reg32 *) PWM2_Sine_cy_m0s8_tcpwm_1__PERIOD )
#define PWM2_Sine_PERIOD_BUF_REG       (*(reg32 *) PWM2_Sine_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define PWM2_Sine_PERIOD_BUF_PTR       ( (reg32 *) PWM2_Sine_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define PWM2_Sine_TRIG_CONTROL0_REG    (*(reg32 *) PWM2_Sine_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define PWM2_Sine_TRIG_CONTROL0_PTR    ( (reg32 *) PWM2_Sine_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define PWM2_Sine_TRIG_CONTROL1_REG    (*(reg32 *) PWM2_Sine_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define PWM2_Sine_TRIG_CONTROL1_PTR    ( (reg32 *) PWM2_Sine_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define PWM2_Sine_TRIG_CONTROL2_REG    (*(reg32 *) PWM2_Sine_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define PWM2_Sine_TRIG_CONTROL2_PTR    ( (reg32 *) PWM2_Sine_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define PWM2_Sine_INTERRUPT_REQ_REG    (*(reg32 *) PWM2_Sine_cy_m0s8_tcpwm_1__INTR )
#define PWM2_Sine_INTERRUPT_REQ_PTR    ( (reg32 *) PWM2_Sine_cy_m0s8_tcpwm_1__INTR )
#define PWM2_Sine_INTERRUPT_SET_REG    (*(reg32 *) PWM2_Sine_cy_m0s8_tcpwm_1__INTR_SET )
#define PWM2_Sine_INTERRUPT_SET_PTR    ( (reg32 *) PWM2_Sine_cy_m0s8_tcpwm_1__INTR_SET )
#define PWM2_Sine_INTERRUPT_MASK_REG   (*(reg32 *) PWM2_Sine_cy_m0s8_tcpwm_1__INTR_MASK )
#define PWM2_Sine_INTERRUPT_MASK_PTR   ( (reg32 *) PWM2_Sine_cy_m0s8_tcpwm_1__INTR_MASK )
#define PWM2_Sine_INTERRUPT_MASKED_REG (*(reg32 *) PWM2_Sine_cy_m0s8_tcpwm_1__INTR_MASKED )
#define PWM2_Sine_INTERRUPT_MASKED_PTR ( (reg32 *) PWM2_Sine_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Register Constants
***************************************/

/* Mask */
#define PWM2_Sine_MASK                 (PWM2_Sine_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Constants for default control register */
#define PWM2_Sine_CONTROL_RELOAD_CC              (0u)
#define PWM2_Sine_CONTROL_RELOAD_PERIOD            (1u)
#define PWM2_Sine_CONTROL_PWM_SYNC_KILL            (2u)
#define PWM2_Sine_CONTROL_PWM_STOP_KILL            (3u)
#define PWM2_Sine_CONTROL_PRESCALER              (8u)
#define PWM2_Sine_CONTROL_UPDOWN                 (16u)
#define PWM2_Sine_CONTROL_ONESHOT                (18u)
#define PWM2_Sine_CONTROL_QUAD_MODE              (20u)
#define PWM2_Sine_CONTROL_INV_OUT                (20u)
#define PWM2_Sine_CONTROL_INV_COMPL_OUT          (21u)
#define PWM2_Sine_CONTROL_MODE                   (24u)

/* Input signal constants for trigger control register 1 */
#define PWM2_Sine_CAPTURE_SIGNAL                 (0x0u)
#define PWM2_Sine_COUNT_SIGNAL                   (0x2u)
#define PWM2_Sine_RELOAD_SIGNAL                  (0x4u)
#define PWM2_Sine_STOP_SIGNAL                    (0x6u)
#define PWM2_Sine_START_SIGNAL                   (0x8u)

/* Mask constants for trigger control register 1 */
#define PWM2_Sine_CAPTURE_MASK                   ~(PWM2_Sine_2X_REG_MASK << (0x0u))
#define PWM2_Sine_COUNT_MASK                     ~(PWM2_Sine_2X_REG_MASK << (0x2u))
#define PWM2_Sine_RELOAD_MASK                    ~(PWM2_Sine_2X_REG_MASK << (0x4u))
#define PWM2_Sine_STOP_MASK                      ~(PWM2_Sine_2X_REG_MASK << (0x6u))
#define PWM2_Sine_START_MASK                     ~(PWM2_Sine_2X_REG_MASK << (0x8u))

/* MASK */
#define PWM2_Sine_1X_REG_MASK                    (0x1u)
#define PWM2_Sine_2X_REG_MASK                    (0x3u)
#define PWM2_Sine_3X_REG_MASK                    (0x7u)
#define PWM2_Sine_4X_REG_MASK                    (0xFu)
#define PWM2_Sine_8X_REG_MASK                    (0xFFu)

/* Mask constants for control register */
#define PWM2_Sine_CONTROL_RELOAD_CC_MASK         ~(PWM2_Sine_1X_REG_MASK)
#define PWM2_Sine_CONTROL_RELOAD_PERIOD_MASK        ~(PWM2_Sine_1X_REG_MASK << (1u))
#define PWM2_Sine_CONTROL_PWM_SYNC_KILL_MASK        ~(PWM2_Sine_1X_REG_MASK << (2u))
#define PWM2_Sine_CONTROL_PWM_STOP_KILL_MASK        ~(PWM2_Sine_1X_REG_MASK << (3u))
#define PWM2_Sine_CONTROL_PRESCALER_MASK         ~(PWM2_Sine_8X_REG_MASK << (8u))
#define PWM2_Sine_CONTROL_UPDOWN_MASK            ~(PWM2_Sine_2X_REG_MASK << (16u))
#define PWM2_Sine_CONTROL_ONESHOT_MASK           ~(PWM2_Sine_1X_REG_MASK << (18u))
#define PWM2_Sine_CONTROL_QUAD_MODE_MASK         ~(PWM2_Sine_2X_REG_MASK << (20u))
#define PWM2_Sine_CONTROL_INV_OUT_MASK           ~(PWM2_Sine_2X_REG_MASK << (20u))
#define PWM2_Sine_CONTROL_MODE_MASK              ~(PWM2_Sine_3X_REG_MASK << (24u))

/* Status register definitions */
#define PWM2_Sine_COUNTDOWN_STATUS               (1u)
#define PWM2_Sine_RUNNING_STATUS                 (30u)


#endif /* End CY_TCPWM_PWM2_Sine_H */

/* [] END OF FILE */
