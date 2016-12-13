/*******************************************************************************
* File Name: PWM_3.c
* Version 1.0
*
* Description:
*  This file provides the source code to the API for the PWM_3 
*  component
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

#include "PWM_3.h"

uint8 PWM_3_initVar = 0u;


/*******************************************************************************
* Function Name: PWM_3_Init
********************************************************************************
*
* Summary:
*  Initialize/Restore default PWM_3 configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PWM_3_Init(void)
{

    /* Set values from custimizer to CTRL */
    /* Quad */
    #if (PWM_3_CONFIG == PWM_3_QUAD)
        PWM_3_CONTROL_REG =
        ((PWM_3_QUAD_ENCODING_MODES << PWM_3_CONTROL_QUAD_MODE) |
        (PWM_3_CONFIG  << PWM_3_CONTROL_MODE));
    #endif  /* End (PWM_3_CONFIG == PWM_3_QUAD) */

    /* PWM */
    #if (PWM_3_CONFIG == PWM_3_PWM_SEL)
        PWM_3_CONTROL_REG =
        ((PWM_3_PWM_STOP_EVENT << PWM_3_CONTROL_PWM_STOP_KILL) |
        (PWM_3_PWM_OUT_INVERT << PWM_3_CONTROL_INV_OUT)|
        (PWM_3_PWM_MODE << PWM_3_CONTROL_MODE));

        #if (PWM_3_PWM_MODE != PWM_3_PWM_PR)
            PWM_3_CONTROL_REG |=
            ((PWM_3_PWM_ALIGN << PWM_3_CONTROL_UPDOWN) |
            (PWM_3_PWM_KILL_EVENT << PWM_3_CONTROL_PWM_SYNC_KILL));
        #else
            PWM_3_CONTROL_REG |= PWM_3_PWM_RUN_MODE << PWM_3_CONTROL_ONESHOT;
            PWM_3_WriteCounter(0x1);
        #endif  /* End (PWM_3_PWM_MODE != PWM_3_PWM_PR) */


        #if (PWM_3_PWM_MODE == PWM_3_PWM_DT)
            PWM_3_CONTROL_REG |=
            ((PWM_3_PWM_DEAD_TIME_CYCLE << PWM_3_CONTROL_PRESCALER) |
            (PWM_3_PWM_OUT_N_INVERT << PWM_3_CONTROL_INV_COMPL_OUT));
        #elif (PWM_3_PWM_MODE == PWM_3_PWM)
            PWM_3_CONTROL_REG |= PWM_3_PWM_PRESCALER << PWM_3_CONTROL_PRESCALER;
        #endif  /* End (PWM_3_PWM_MODE == PWM_3_PWM_DT) */

    #endif  /* End (PWM_3_CONFIG == PWM_3_PWM_SEL) */

    /* Timer/Counter */
    #if (PWM_3_CONFIG == PWM_3_TIMER)
        PWM_3_CONTROL_REG =
        ((PWM_3_TC_PRESCALER << PWM_3_CONTROL_PRESCALER)  |
        (PWM_3_TC_COUNTER_MODE << PWM_3_CONTROL_UPDOWN) |
        (PWM_3_TC_RUN_MODE << PWM_3_CONTROL_ONESHOT) |
        (PWM_3_TC_COMP_CAP_MODE  << PWM_3_CONTROL_MODE));
    #endif  /* End (PWM_3_CONFIG == PWM_3_TIMER) */

    /* Set values from custimizer to CTRL1 */
    /* Quad */
    #if (PWM_3_CONFIG == PWM_3_QUAD)
        PWM_3_TRIG_CONTROL1_REG  =
        ((PWM_3_QUAD_PHIA_SIGNAL_MODE << PWM_3_COUNT_SIGNAL) |
        (PWM_3_QUAD_INDEX_SIGNAL_MODE << PWM_3_RELOAD_SIGNAL) |
        (PWM_3_QUAD_STOP_SIGNAL_MODE << PWM_3_STOP_SIGNAL) |
        (PWM_3_QUAD_PHIB_SIGNAL_MODE << PWM_3_START_SIGNAL));
    #endif  /* End (PWM_3_CONFIG == PWM_3_QUAD) */

    /* PWM */
    #if (PWM_3_CONFIG == PWM_3_PWM_SEL)
        PWM_3_TRIG_CONTROL1_REG  =
        ((PWM_3_PWM_SWITCH_SIGNAL_MODE << PWM_3_CAPTURE_SIGNAL) |
        (PWM_3_PWM_COUNT_SIGNAL_MODE << PWM_3_COUNT_SIGNAL) |
        (PWM_3_PWM_RELOAD_SIGNAL_MODE << PWM_3_RELOAD_SIGNAL) |
        (PWM_3_PWM_STOP_SIGNAL_MODE << PWM_3_STOP_SIGNAL) |
        (PWM_3_PWM_START_SIGNAL_MODE << PWM_3_START_SIGNAL));
    #endif  /* End (PWM_3_CONFIG == PWM_3_PWM_SEL) */

    /* Timer/Counter */
    #if (PWM_3_CONFIG == PWM_3_TIMER)
        PWM_3_TRIG_CONTROL1_REG  =
        ((PWM_3_TC_CAPTURE_SIGNAL_MODE << PWM_3_CAPTURE_SIGNAL) |
        (PWM_3_TC_COUNT_SIGNAL_MODE << PWM_3_COUNT_SIGNAL) |
        (PWM_3_TC_RELOAD_SIGNAL_MODE << PWM_3_RELOAD_SIGNAL) |
        (PWM_3_TC_STOP_SIGNAL_MODE << PWM_3_STOP_SIGNAL) |
        (PWM_3_TC_START_SIGNAL_MODE << PWM_3_START_SIGNAL));
    #endif  /* End (PWM_3_CONFIG == PWM_3_TIMER) */

    /* Set values from custimizer to INTR */
    /* Quad */
    #if (PWM_3_CONFIG == PWM_3_QUAD)
        PWM_3_INTERRUPT_MASK_REG  = PWM_3_QUAD_INTERRUPT_MASK;
    #endif  /* End (PWM_3_CONFIG == PWM_3_QUAD) */

    /* PWM */
    #if (PWM_3_CONFIG == PWM_3_PWM_SEL)
        PWM_3_INTERRUPT_MASK_REG  = PWM_3_PWM_INTERRUPT_MASK;
    #endif  /* End (PWM_3_CONFIG == PWM_3_PWM_SEL) */

    /* Timer/Counter */
    #if (PWM_3_CONFIG == PWM_3_TIMER)
        PWM_3_INTERRUPT_MASK_REG  = PWM_3_TC_INTERRUPT_MASK;
    #endif  /* End (PWM_3_CONFIG == PWM_3_TIMER) */

    /* Set Period from custimizer */
    /* PWM */
    #if (PWM_3_CONFIG == PWM_3_PWM_SEL)
        PWM_3_WritePeriod(PWM_3_PWM_PERIOD_VALUE );
    #endif  /* End (PWM_3_CONFIG == PWM_3_PWM_SEL) */

    /* Timer/Counter */
    #if (PWM_3_CONFIG == PWM_3_TIMER)
        PWM_3_WritePeriod(PWM_3_TC_PERIOD_VALUE );
    #endif  /* End (PWM_3_CONFIG == PWM_3_TIMER) */

    /* Timer/Counter */
    #if ((PWM_3_CONFIG == PWM_3_TIMER)&&(PWM_3_TC_COMP_CAP_MODE \
                                  == PWM_3_COMPARE_MODE))
        PWM_3_WriteCompare(PWM_3_TC_COMPARE_VALUE);

        if (1u == PWM_3_TC_COMPARE_SWAP)
        {
            PWM_3_SetCompareSwap(1u);
            PWM_3_WriteCompareBuf(PWM_3_TC_COMPARE_BUF_VALUE);
        }
    #endif  /* End ((PWM_3_CONFIG == PWM_3_TIMER)&&(PWM_3_COMP_CAP_MODE \
                                             == PWM_3_COMPARE_MODE)) */

    /* PWM */
    #if (PWM_3_CONFIG == PWM_3_PWM_SEL)
        PWM_3_WriteCompare(PWM_3_PWM_COMPARE_VALUE);

        if (1u == PWM_3_PWM_COMPARE_SWAP)
        {
            PWM_3_SetCompareSwap(1u);
            PWM_3_WriteCompareBuf(PWM_3_PWM_COMPARE_BUF_VALUE);
        }

        if (1u == PWM_3_PWM_PERIOD_SWAP)
        {
            PWM_3_SetPeriodSwap(1u);
            PWM_3_WritePeriodBuf(PWM_3_PWM_PERIOD_BUF_VALUE);
        }

        /* Set values from custimizer to CTRL2 */
        #if (PWM_3_PWM_MODE != PWM_3_PWM_PR)
            if ( PWM_3_PWM_LEFT == PWM_3_PWM_ALIGN)
            {
                PWM_3_TRIG_CONTROL2_REG =
                (PWM_3_CC_MATCH_CLEAR | PWM_3_OVERLOW_SET |
                PWM_3_UNDERFLOW_NO_CHANGE);

            }
            if ( PWM_3_PWM_RIGHT == PWM_3_PWM_ALIGN)
            {
                PWM_3_TRIG_CONTROL2_REG =
                (PWM_3_CC_MATCH_SET | PWM_3_OVERLOW_NO_CHANGE  |
                PWM_3_UNDERFLOW_CLEAR );

            }
            if ( PWM_3_PWM_CENTER == PWM_3_PWM_ALIGN)
            {
                PWM_3_TRIG_CONTROL2_REG =
                (PWM_3_CC_MATCH_INVERT  | PWM_3_OVERLOW_NO_CHANGE |
                PWM_3_UNDERFLOW_NO_CHANGE);

            }
            if ( PWM_3_PWM_ASYM == PWM_3_PWM_ALIGN)
            {
                PWM_3_TRIG_CONTROL2_REG =
                (PWM_3_CC_MATCH_INVERT  | PWM_3_OVERLOW_INVERT  |
                PWM_3_UNDERFLOW_INVERT );
            }
        #else
            PWM_3_TRIG_CONTROL2_REG =
            (PWM_3_CC_MATCH_NO_CHANGE | PWM_3_OVERLOW_NO_CHANGE  |
            PWM_3_UNDERFLOW_NO_CHANGE);

        #endif  /* End (PWM_3_PWM_MODE != PWM_3_PWM_PR) */
    #endif  /* End (PWM_3_PWM == PWM_3_PWM_MODE) */
}


/*******************************************************************************
* Function Name: PWM_3_Enable
********************************************************************************
*
* Summary:
*  Enables the PWM_3.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PWM_3_Enable(void)
{
    uint8 enableInterrupts;

    /* Change Control reg for PWM_3 state, need to be safety */
    enableInterrupts = CyEnterCriticalSection();

    /* Enable PWM_3 */
    PWM_3_BLOCK_CONTROL_REG |= PWM_3_MASK;

    /* Control reg setting are done */
    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PWM_3_Start
********************************************************************************
*
* Summary:
*  Initialize the PWM_3 with default customizer
*  values when called the first time and enables the PWM_3.
*  For subsequent calls the configuration is left unchanged and the component is
*  just enabled.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_3_initVar: global variable is used to indicate initial
*  configuration of this component.  The variable is initialized to zero and set
*  to 1 the first time PWM_3_Start() is called. This allows
*  enable/disable component without re-initialization in all subsequent calls
*  to the PWM_3_Start() routine.
*
*******************************************************************************/
void PWM_3_Start(void)

{
    /* Writes seed value and ponynom value provided from customizer */
    if (0u == PWM_3_initVar)
    {
        PWM_3_Init();
        PWM_3_initVar = 1u;
    }

    PWM_3_Enable();
}


/*******************************************************************************
* Function Name: PWM_3_Stop
********************************************************************************
*
* Summary:
*  Disables the PWM_3.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PWM_3_Stop(void)
{
    uint8 enableInterrupts;

    /* Change Control reg for PWM_3 state, need to be safety */
    enableInterrupts = CyEnterCriticalSection();

    /* Disable PWM_3 */
    PWM_3_BLOCK_CONTROL_REG &= ~PWM_3_MASK;

    /* Control reg setting are done */
    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PWM_3_SetMode
********************************************************************************
*
* Summary:
*  Sets the operation mode of the PWM_3. This function is used when
*  configured as a generic PWM_3 and the actual mode of operation is
*  set at runtime. The mode must be set while the component is disabled.
*
* Parameters:
*  mode: Mode for the PWM_3 to operate in
*   Values:
*         - PWM_3_MODE_TIMER_COMPARE - Timer / Counter with
*                                                 compare capability
*         - PWM_3_MODE_TIMER_CAPTURE - Timer / Counter with
*                                                 capture capability
*         - PWM_3_MODE_QUAD - Quadrature decoder
*         - PWM_3_MODE_PWM - PWM
*         - PWM_3_MODE_PWM_DT - PWM with dead time
*         - PWM_3_MODE_PWM_PR - PWM with pseudo random capability
*
* Return:
*  None
*
*******************************************************************************/
void PWM_3_SetMode(uint32 mode)
{
    uint8 enableInterrupts;

    /* Change command reg bits, need to be safety */
    enableInterrupts = CyEnterCriticalSection();

    /* Clear value on CTRL */
    PWM_3_CONTROL_REG &= PWM_3_CONTROL_MODE_MASK;

    /* Set value to CTRL */
    PWM_3_CONTROL_REG |= mode;

    /* Control reg setting are done */
    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PWM_3_SetQDMode
********************************************************************************
*
* Summary:
*  Sets the the Quadrature Decoder to one of 3 supported modes.
*  Is functionality is only applicable to Quadrature Decoder operation.
*
* Parameters:
*  qdmode: Quadrature Decoder mode
*   Values:
*         - PWM_3_MODE_X1 - Counts on phi 1 rising
*         - PWM_3_MODE_X2 - Counts on both edges of phi1 (2x faster)
*         - PWM_3_MODE_X4 - Counts on both edges of phi1 and phi2
*                                        (4x faster)
*
* Return:
*  None
*
*******************************************************************************/
void PWM_3_SetQDMode(uint32 qdmode)
{
    uint8 enableInterrupts;

    /* Change command reg bits, need to be safety */
    enableInterrupts = CyEnterCriticalSection();

    /* Clear value on CTRL */
    PWM_3_CONTROL_REG &= PWM_3_CONTROL_QUAD_MODE_MASK;

    /* Set value to CTRL */
    PWM_3_CONTROL_REG |= qdmode;

    /* Control reg setting are done */
    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PWM_3_SetPrescaler
********************************************************************************
*
* Summary:
*  Sets the prescaler value that is applied to the clock input.  Not applicable
*  to PWM with dead time mode or Quadrature Decoder mode.
*
* Parameters:
*  prescaler: Prescaler divider value
*   Values:
*         - PWM_3_PRESCALE_DIVBY1 - Divide by 1 (no prescaling)
*         - PWM_3_PRESCALE_DIVBY2 - Divide by 2
*         - PWM_3_PRESCALE_DIVBY4 - Divide by 4
*         - PWM_3_PRESCALE_DIVBY8 - Divide by 8
*         - PWM_3_PRESCALE_DIVBY16 - Divide by 16
*         - PWM_3_PRESCALE_DIVBY32 - Divide by 32
*         - PWM_3_PRESCALE_DIVBY64 - Divide by 64
*         - PWM_3_PRESCALE_DIVBY128 - Divide by 128
*
* Return:
*  None
*
*******************************************************************************/
void PWM_3_SetPrescaler(uint32 prescaler)
{
    uint8 enableInterrupts;

    /* Change command reg bits, need to be safety */
    enableInterrupts = CyEnterCriticalSection();

    /* Clear value on CTRL */
    PWM_3_CONTROL_REG &= PWM_3_CONTROL_PRESCALER_MASK;

    /* Set value to CTRL */
    PWM_3_CONTROL_REG |= prescaler;

    /* Control reg setting are done */
    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PWM_3_SetOneShot
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the PWM_3 runs
*  continuously or stops when terminal count is reached.  By default the
*  PWM_3 operates in continuous mode.
*
* Parameters:
*  oneShotEnable
*   Values:
*     - 0 - Continuous
*     - 1 - Enable One Shot
*
* Return:
*  None
*
*******************************************************************************/
void PWM_3_SetOneShot(uint32 oneShotEnable)
{
    uint8 enableInterrupts;

    /* Change command reg bits, need to be safety */
    enableInterrupts = CyEnterCriticalSection();

    /* Clear value on CTRL */
    PWM_3_CONTROL_REG &= PWM_3_CONTROL_ONESHOT_MASK;

    /* Set value to CTRL */
    PWM_3_CONTROL_REG |= (oneShotEnable << PWM_3_CONTROL_ONESHOT);

    /* Control reg setting are done */
    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PWM_3_SetPWMMode
********************************************************************************
*
* Summary:
*  Writes the control register that determines what mode of operation the PWM
*  output lines are driven in.  There is a setting for what to do on a
*  comparison match (CC_MATCH), on an overflow (OVERFLOW) and on an underflow
*  (UNDERFLOW).  The value for each of the 3 must be ORed together to form the
*  mode.
*
* Parameters:
*  modeMask: Combination of the 3 mode settings.  Mask must include a value for
*  each of the 3 or use one of the preconfigured PWM settings.
*   Values:
*     - CC_MATCH_SET - Set on comparison match
*     - CC_MATCH_CLEAR - Clear on comparison match
*     - CC_MATCH_INVERT - Invert on comparison match
*     - CC_MATCH_NO_CHANGE - No change on comparison match
*     - OVERLOW_SET - Set on overflow
*     - OVERLOW_CLEAR - Clear on overflow
*     - OVERLOW_INVERT - Invert on overflow
*     - OVERLOW_NO_CHANGE - No change on overflow
*     - UNDERFLOW_SET - Set on underflow
*     - UNDERFLOW_CLEAR - Clear on underflow
*     - UNDERFLOW_INVERT - Invert on underflow
*     - UNDERFLOW_NO_CHANGE - No change on underflow
*     - PWM_MODE_LEFT - Setting for left aligned PWM.  Should be combined
*                       with up counting mode
*     - PWM_MODE_RIGHT - Setting for right aligned PWM.  Should be combined
*                        with down counting mode
*     - PWM_MODE_CENTER - Setting for center aligned PWM.  Should be combined
*                         with up/down 0 mode
*     - PWM_MODE_ASYM - Setting for asymmetric PWM.  Should be combined
*                       with up/down 1 mode
*
* Return:
*  None
*
*******************************************************************************/
void PWM_3_SetPWMMode(uint32 modeMask)
{
    uint8 enableInterrupts;

    /* Change command reg bits, need to be safety */
    enableInterrupts = CyEnterCriticalSection();

    /* Clear value on CTRL */
    PWM_3_CONTROL_REG &= PWM_3_CONTROL_UPDOWN_MASK;

    /* Set value to CTRL */
    PWM_3_CONTROL_REG |= (modeMask & (0x30000u));

    /* Set value to CTRL2 */
    PWM_3_TRIG_CONTROL2_REG = ((0x3F) & modeMask);

    /* Control reg setting are done */
    CyExitCriticalSection(enableInterrupts);
}



/*******************************************************************************
* Function Name: PWM_3_SetPWMSyncKill
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the PWM kill signal (stop input)
*  causes an asynchronous or synchronous kill operation.  By default the kill
*  operation is asynchronous.  This functionality is only applicable to PWM and
*  PWM with dead time. modes.
*
*  For Synchronous mode the kill signal disables both the line and line_n
*  signals until the next terminal count.
*
*  For Asynchronous mode the kill signal disables both the line and line_n
*  signals when the kill signal is present.  This mode should only be used
*  when the kill signal (stop input) is configured in pass through mode
*  (Level sensitive signal).

*
* Parameters:
*  syncKillEnable
*   Values:
*     - 0 - Asynchronous
*     - 1 - Synchronous
*
* Return:
*  None
*
*******************************************************************************/
void PWM_3_SetPWMSyncKill(uint32 syncKillEnable)
{
    uint8 enableInterrupts;

    /* Change command reg bits, need to be safety */
    enableInterrupts = CyEnterCriticalSection();

    /* Clear value on CTRL */
    PWM_3_CONTROL_REG &= PWM_3_CONTROL_PWM_SYNC_KILL_MASK;

    /* Set value to CTRL */
    PWM_3_CONTROL_REG |= (syncKillEnable << PWM_3_CONTROL_PWM_SYNC_KILL);

    /* Control reg setting are done */
    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PWM_3_SetPWMStopOnKill
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the PWM kill signal (stop input)
*  causes the PWM counter to stop.  By default the kill operation does not stop
*  the counter.  This functionality is only applicable to the three PWM modes.

*
* Parameters:
*  stopOnKillEnable
*   Values:
*     - 0 - Don't stop
*     - 1 - Stop
*
* Return:
*  None
*
*******************************************************************************/
void PWM_3_SetPWMStopOnKill(uint32 stopOnKillEnable)
{
    uint8 enableInterrupts;

    /* Change command reg bits, need to be safety */
    enableInterrupts = CyEnterCriticalSection();

    /* Clear value on CTRL */
    PWM_3_CONTROL_REG &= PWM_3_CONTROL_PWM_STOP_KILL_MASK;

    /* Set value to CTRL */
    PWM_3_CONTROL_REG |= (stopOnKillEnable << PWM_3_CONTROL_PWM_STOP_KILL);

    /* Control reg setting are done */
    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PWM_3_SetPWMDeadTime
********************************************************************************
*
* Summary:
*  Writes the dead time control value.  This value delays the rising edge of
*  both the line and line_n signals the designated number of cycles resulting
*  in both signals being inactive for that many cycles.  This functionality is
*  only applicable to the PWM in dead time mode.

*
* Parameters:
*  Dead time to insert
*   Values: 0 to 255
*
* Return:
*  None
*
*******************************************************************************/
void PWM_3_SetPWMDeadTime(uint32 deadTime)
{
    uint8 enableInterrupts;

    /* Change command reg bits, need to be safety */
    enableInterrupts = CyEnterCriticalSection();

    /* Clear value on CTRL */
    PWM_3_CONTROL_REG &= PWM_3_CONTROL_PRESCALER_MASK;

    /* Set value to CTRL */
    PWM_3_CONTROL_REG |= deadTime << (8u);

    /* Control reg setting are done */
    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PWM_3_SetPWMInvert
********************************************************************************
*
* Summary:
*  Writes the bits that control whether the line and line_n outputs are
*  inverted from their normal output values.  This functionality is only
*  applicable to the three PWM modes.
*
* Parameters:
*  mask: Mask of outputs to invert.
*   Values:
*         - PWM_3_INVERT_LINE - Inverts the line output
*         - PWM_3_INVERT_LINE_N - Inverts the line_n output
*
* Return:
*  None
*
*******************************************************************************/
void PWM_3_SetPWMInvert(uint32 mask)
{
    uint8 enableInterrupts;

    /* Change command reg bits, need to be safety */
    enableInterrupts = CyEnterCriticalSection();

    /* Clear value on CTRL */
    PWM_3_CONTROL_REG &= PWM_3_CONTROL_INV_OUT_MASK;

    /* Set value to CTRL */
    PWM_3_CONTROL_REG |= mask;

    /* Control reg setting are done */
    CyExitCriticalSection(enableInterrupts);
}



/*******************************************************************************
* Function Name: PWM_3_WriteCounter
********************************************************************************
*
* Summary:
*  Writes a new 16bit counter value directly into the counter register, thus
*  setting the counter (not the period) to the value written. It is not
*  advised to write to this field when the counter is running.
*
* Parameters:
*  count: value to write
*
* Return:
*  None
*
*******************************************************************************/
void PWM_3_WriteCounter(uint32 count)
{
    PWM_3_COUNTER_REG = count;
}


/*******************************************************************************
* Function Name: PWM_3_ReadCounter
********************************************************************************
*
* Summary:
*  Reads the current current counter value.
*
* Parameters:
*  None
*
* Return:
*  Current counter value
*
*******************************************************************************/
uint32 PWM_3_ReadCounter(void)
{
    return (PWM_3_COUNTER_REG);
}


/*******************************************************************************
* Function Name: PWM_3_SetCounterMode
********************************************************************************
*
* Summary:
*  Sets the counter mode.  Applicable to all modes except Quadrature Decoder
*  and PWM with pseudo random output.
*
* Parameters:
*  counterMode: Enumerated couner type values
*   Values:
*     - PWM_3_COUNT_UP - Counts up
*     - PWM_3_COUNT_DOWN - Counts down
*     - PWM_3_COUNT_UPDOWN0 - Counts up and down. Terminal count
*                       generated when counter reaches 0
*     - PWM_3_COUNT_UPDOWN1 - Counts up and down. Terminal count
*                       generated both when counter reaches 0 and period
*
* Return:
*  None
*
*******************************************************************************/
void PWM_3_SetCounterMode(uint32 CounterMode)
{
    uint8 enableInterrupts;

    /* Change command reg bits, need to be safety */
    enableInterrupts = CyEnterCriticalSection();

    /* Clear value on CTRL */
    PWM_3_CONTROL_REG &= PWM_3_CONTROL_UPDOWN_MASK;

    /* Set value to CTRL */
    PWM_3_CONTROL_REG |= CounterMode;

    /* Control reg setting are done */
    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PWM_3_WritePeriod
********************************************************************************
*
* Summary:
*  Writes the 16 bit period register with the new period value.
*  To cause the counter to count for N cycles this register should be written
*  with N-1 (counts from 0 to period inclusive).
*
* Parameters:
*  period: Period value
*
* Return:
*  None
*
*******************************************************************************/
void PWM_3_WritePeriod(uint32 period)
{
    PWM_3_PERIOD_REG = period;
}


/*******************************************************************************
* Function Name: PWM_3_ReadPeriod
********************************************************************************
*
* Summary:
*  Reads the 16 bit period register.
*
* Parameters:
*  None
*
* Return:
*  Period value
*
*******************************************************************************/
uint32 PWM_3_ReadPeriod(void)
{
    return (PWM_3_PERIOD_REG);
}


/*******************************************************************************
* Function Name: PWM_3_SetCompareSwap
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the compare registers are
*  swapped. When enabled in Timer/Counter mode(without capture) the swap occurs
*  at a TC event. In PWM mode the swap occurs at the next TC event following
*  a hardware switch event.
*
* Parameters:
*  swapEnable
*   Values:
*     - 0 - Disable swap
*     - 1 - Enable swap
*
* Return:
*  None
*
*******************************************************************************/
void PWM_3_SetCompareSwap(uint32 swapEnable)
{
    uint8 enableInterrupts;

    /* Change command reg bits, need to be safety */
    enableInterrupts = CyEnterCriticalSection();

    /* Clear value on CTRL */
    PWM_3_CONTROL_REG &= PWM_3_CONTROL_RELOAD_CC_MASK;

    /* Set value on CTRL */
    PWM_3_CONTROL_REG |= (swapEnable << PWM_3_CONTROL_RELOAD_CC);

    /* Control reg setting are done */
    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PWM_3_WritePeriodBuf
********************************************************************************
*
* Summary:
*  Writes the 16 bit period buf register with the new period value.
*
* Parameters:
*  period: Period value
*
* Return:
*  None
*
*******************************************************************************/
void PWM_3_WritePeriodBuf(uint32 period)
{
    PWM_3_PERIOD_BUF_REG = period;
}


/*******************************************************************************
* Function Name: PWM_3_ReadPeriodBuf
********************************************************************************
*
* Summary:
*  Reads the 16 bit period buf register.
*
* Parameters:
*  None
*
* Return:
*  Period value
*
*******************************************************************************/
uint32 PWM_3_ReadPeriodBuf(void)
{
    return (PWM_3_PERIOD_BUF_REG);
}


/*******************************************************************************
* Function Name: PWM_3_SetPeriodSwap
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the period registers are
*  swapped. When enabled in Timer/Counter mode the swap occurs at a TC event.
*  In PWM mode the swap occurs at the next TC event following a hardware switch
*  event.
*
* Parameters:
*  swapEnable
*   Values:
*     - 0 - Disable swap
*     - 1 - Enable swap
*
* Return:
*  None
*
*******************************************************************************/
void PWM_3_SetPeriodSwap(uint32 swapEnable)
{
    uint8 enableInterrupts;

    /* Change command reg bits, need to be safety */
    enableInterrupts = CyEnterCriticalSection();

    /* Clear value on CTRL */
    PWM_3_CONTROL_REG &= PWM_3_CONTROL_RELOAD_PERIOD_MASK;

    /* Set value on CTRL */
    PWM_3_CONTROL_REG |= (swapEnable << PWM_3_CONTROL_RELOAD_PERIOD);

    /* Control reg setting are done */
    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PWM_3_WriteCompare
********************************************************************************
*
* Summary:
*  Writes the 16 bit compare register with the new compare value. Not
*  applicable for Timer/Counter with Capture or in Quadrature Decoder modes.
*
* Parameters:
*  compare: Compare value
*
* Return:
*  None
*
*******************************************************************************/
void PWM_3_WriteCompare(uint32 compare)
{
    PWM_3_COMP_CAP_REG = compare;
}


/*******************************************************************************
* Function Name: PWM_3_ReadCompare
********************************************************************************
*
* Summary:
*  Reads the compare register. Not applicable for Timer/Counter with Capture
*  or in Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Compare value
*
*******************************************************************************/
uint32 PWM_3_ReadCompare(void)
{
    return (PWM_3_COMP_CAP_REG);
}


/*******************************************************************************
* Function Name: PWM_3_WriteCompareBuf
********************************************************************************
*
* Summary:
*  Writes the 16 bit compare buffer register with the new compare value. Not
*  applicable for Timer/Counter with Capture or in Quadrature Decoder modes.
*
* Parameters:
*  comparebuf: Compare value
*
* Return:
*  None
*
*******************************************************************************/
void PWM_3_WriteCompareBuf(uint32 comparebuf)
{
   PWM_3_COMP_CAP_BUF_REG = comparebuf;
}


/*******************************************************************************
* Function Name: PWM_3_ReadCompareBuf
********************************************************************************
*
* Summary:
*  Reads the compare buffer register. Not applicable for Timer/Counter with
*  Capture or in Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Compare buffer value
*
*******************************************************************************/
uint32 PWM_3_ReadCompareBuf(void)
{
    return (PWM_3_COMP_CAP_BUF_REG);
}


/*******************************************************************************
* Function Name: PWM_3_ReadCapture
********************************************************************************
*
* Summary:
*  Reads the captured counter value. This API is applicable only for
*  Timer/Counter with capture mode and Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Capture value
*
*******************************************************************************/
uint32 PWM_3_ReadCapture(void)
{
    return (PWM_3_COMP_CAP_REG);
}


/*******************************************************************************
* Function Name: PWM_3_ReadCaptureBuf
********************************************************************************
*
* Summary:
*  Reads the capture buffer register. This API is applicable only for
*  Timer/Counter with capture mode and Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Capture buffer value
*
*******************************************************************************/
uint32 PWM_3_ReadCaptureBuf(void)
{
    return (PWM_3_COMP_CAP_BUF_REG);
}


/*******************************************************************************
* Function Name: PWM_3_SetCaptureMode
********************************************************************************
*
* Summary:
*  Sets the capture trigger mode. For PWM mode this is the switch input.
*  This input is not applicable to the Timer/Counter without Capture and
*  Quadrature Decoder modes.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - PWM_3_TRIG_LEVEL - Level
*     - PWM_3_TRIG_RISING - Rising edge
*     - PWM_3_TRIG_FALLING - Falling edge
*     - PWM_3_TRIG_BOTH - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void PWM_3_SetCaptureMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    /* Change command reg bits, need to be safety */
    enableInterrupts = CyEnterCriticalSection();

    /* Clear values on TRIG_CONTROL1 */
    PWM_3_TRIG_CONTROL1_REG &= PWM_3_CAPTURE_MASK;

    /* Set values to TRIG_CONTROL1 */
    PWM_3_TRIG_CONTROL1_REG |= (triggerMode << PWM_3_CAPTURE_SIGNAL);

    /* Control reg setting are done */
    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PWM_3_SetReloadMode
********************************************************************************
*
* Summary:
*  Sets the reload trigger mode. For Quadrature Decoder mode this is the index
*  input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - PWM_3_TRIG_LEVEL - Level
*     - PWM_3_TRIG_RISING - Rising edge
*     - PWM_3_TRIG_FALLING - Falling edge
*     - PWM_3_TRIG_BOTH - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void PWM_3_SetReloadMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    /* Change command reg bits, need to be safety */
    enableInterrupts = CyEnterCriticalSection();

    /* Clear values on TRIG_CONTROL1 */
    PWM_3_TRIG_CONTROL1_REG &= PWM_3_RELOAD_MASK;

    /* Set values to TRIG_CONTROL1 */
    PWM_3_TRIG_CONTROL1_REG |= (triggerMode << PWM_3_RELOAD_SIGNAL);

    /* Control reg setting are done */
    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PWM_3_SetStartMode
********************************************************************************
*
* Summary:
*  Sets the start trigger mode. For Quadrature Decoder mode this is the
*  phiB input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - PWM_3_TRIG_LEVEL - Level
*     - PWM_3_TRIG_RISING - Rising edge
*     - PWM_3_TRIG_FALLING - Falling edge
*     - PWM_3_TRIG_BOTH - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void PWM_3_SetStartMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    /* Change command reg bits, need to be safety */
    enableInterrupts = CyEnterCriticalSection();

    /* Clear values on TRIG_CONTROL1 */
    PWM_3_TRIG_CONTROL1_REG &= PWM_3_START_MASK;

    /* Set values to TRIG_CONTROL1 */
    PWM_3_TRIG_CONTROL1_REG |= (triggerMode << PWM_3_START_SIGNAL);

    /* Control reg setting are done */
    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PWM_3_SetStopMode
********************************************************************************
*
* Summary:
*  Sets the stop trigger mode. For PWM mode this is the kill input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - PWM_3_TRIG_LEVEL - Level
*     - PWM_3_TRIG_RISING - Rising edge
*     - PWM_3_TRIG_FALLING - Falling edge
*     - PWM_3_TRIG_BOTH - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void PWM_3_SetStopMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    /* Change command reg bits, need to be safety */
    enableInterrupts = CyEnterCriticalSection();

    /* Clear values on TRIG_CONTROL1 */
    PWM_3_TRIG_CONTROL1_REG &= PWM_3_STOP_MASK;

    /* Set values to TRIG_CONTROL1 */
    PWM_3_TRIG_CONTROL1_REG |= (triggerMode << PWM_3_STOP_SIGNAL);

    /* Control reg setting are done */
    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PWM_3_SetCountMode
********************************************************************************
*
* Summary:
*  Sets the count trigger mode. For Quadrature Decoder mode this is the phiA
*  input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - PWM_3_TRIG_LEVEL - Level
*     - PWM_3_TRIG_RISING - Rising edge
*     - PWM_3_TRIG_FALLING - Falling edge
*     - PWM_3_TRIG_BOTH - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void PWM_3_SetCountMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    /* Change command reg bits, need to be safety */
    enableInterrupts = CyEnterCriticalSection();

    /* Clear values on TRIG_CONTROL1 */
    PWM_3_TRIG_CONTROL1_REG &= PWM_3_COUNT_MASK;

    /* Set values to TRIG_CONTROL1 */
    PWM_3_TRIG_CONTROL1_REG |= (triggerMode << PWM_3_COUNT_SIGNAL);

    /* Control reg setting are done */
    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PWM_3_TriggerCommand
********************************************************************************
*
* Summary:
*  Triggers the designated command to occur on the designated TCPWM instances.
*  The mask can be used to apply this command simultaneously to more than one
*  instance.  This allows multiple TCPWM instances to be synchronized.
*
* Parameters:
*  mask: Combination of mask bits for each instance of the TCPWM that the
*        command should apply to.  This function from one instance can be used
*        to apply the command to any of the instances in the design.
*        The mask value for a specific instance is available with the MASK
*        define.
*  command: Enumerated command values. Capture command only applicable for
*           Timer/Counter with Capture and PWM modes.
*   Values:
*     - PWM_3_CMD_CAPTURE - Trigger Capture command
*     - PWM_3_CMD_RELOAD - Trigger Reload command
*     - PWM_3_CMD_STOP - Trigger Stop command
*     - PWM_3_CMD_START - Trigger Start command
*
* Return:
*  None
*
*******************************************************************************/
void PWM_3_TriggerCommand(uint32 mask, uint32 command)
{
    uint8 enableInterrupts;

    /* Change command reg for set command, need to be safety */
    enableInterrupts = CyEnterCriticalSection();

    PWM_3_COMMAND_REG = mask << command;

    /* Command reg setting are done */
    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PWM_3_ReadStatus
********************************************************************************
*
* Summary:
*  Reads the status of the PWM_3.
*
* Parameters:
*  None
*
* Return:
*  Status
*   Values:
*     - PWM_3_STATUS_DOWN - Set if counting down
*     - PWM_3_STATUS_RUNNING - Set if counter is running
*
*******************************************************************************/
uint32 PWM_3_ReadStatus(void)
{
    return ((PWM_3_STATUS_REG >> PWM_3_RUNNING_STATUS) |
            (PWM_3_STATUS_REG & PWM_3_COUNTDOWN_STATUS));
}

/* [] END OF FILE */
