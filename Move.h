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

#include <CYLIB.h>
#include <phaseControl.h>
extern uint8 currentStepA;
extern uint8 currentStepB;
extern uint8 divider;
extern uint8 previousDivider;
extern uint8 FullScale;
extern uint8 phase;
extern uint8 step;
extern uint8 dirReg;

extern uint8 currentStepA1;
extern uint8 currentStepB1;
extern uint8 divider1;
extern uint8 previousDivider1;
extern uint8 FullScale1;
extern uint8 phase1;
extern uint8 step1;
extern uint8 dirReg1;

void Move (uint8 motor);
