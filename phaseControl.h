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
#include <DIR_OUT_A.h>
#include <DIR_OUT_B.h>
#include <DIR_REG.h>
#include <DIR_OUT_A_1.h>
#include <DIR_OUT_B_1.h>
#include <DIR_REG_1.h>
extern uint8 phase;
extern uint8 currentStepA;
extern uint8 currentStepB;
extern uint8 dirReg;

extern uint8 phase1;
extern uint8 currentStepA1;
extern uint8 currentStepB1;
extern uint8 dirReg1;

void phaseControl(uint8 currentphase, uint8 motor);
void phaseMove(uint8 motor);
