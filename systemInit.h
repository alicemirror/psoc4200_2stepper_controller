/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
//[] END OF FILE
#include <CYLIB.H>
#include <Clock_PWM_MAIN_1.h>
#include <Clock_PWM_MAIN_2.h>

extern uint8 currentStepA; // current step level of channel A
extern uint8 currentStepB; // current step level of channel B
extern uint8 currentStepA1; // current step level of channel A
extern uint8 currentStepB1; // current step level of channel B
extern uint8 divider; // divider value of step moter driver 2, 4, 8 ,16
extern uint8 divider1; // divider value of step moter driver 2, 4, 8 ,16
extern uint8 previousDivider; // divider value of step moter driver 2, 4, 8 ,16
extern uint8 previousDivider1; // divider value of step moter driver 2, 4, 8 ,16
extern uint8 FullScale;
extern uint8 FullScale1;
extern uint8 step;
extern uint8 step1;
extern uint8 phase;
extern uint8 phase1;
extern uint8 pwmA;
extern uint8 pwmB;
extern uint8 pwmA1;
extern uint8 pwmB1;
extern uint8 dirReg;
extern uint8 dirReg1;
extern const uint8 sineTable [];
void systemInit ();
