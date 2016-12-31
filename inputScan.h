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
#include <CYlIB.h>
#include <DIR_INPUT_1.h>
#include <DIR_INPUT_2.h>
#include <DIR_INPUT_SOURCE_1.h>
#include <DIR_INPUT_SOURCE_2.h>
#include <INTERNAL_STEP_OUT_1.h>
#include <INTERNAL_STEP_OUT_2.h>
#include <STEP_INPUT_SOURCE_1.h>
#include <STEP_INPUT_SOURCE_2.h>
#include <STEP_INPUT_1.h>
#include <STEP_INPUT_2.h>

extern uint8 stepPulse;
extern uint8 previousStepPulse;
uint8 dirReg;

extern uint8 stepPulse1;
extern uint8 previousStepPulse1;
uint8 dirReg1;

void inputScan(uint8 motor);
