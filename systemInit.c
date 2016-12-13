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

#include <systemInit.h>
#include <DIR_INPUT.h>
#include <DIR_INPUT_SOURCE.h>
#include <TCPWM_1.h>
#include <TCPWM_2.h>
#include <TCPWM_3.h>
#include <TCPWM_4.h>
#include <INTERNAL_STEP.h>
#include <INTERNAL_STEP_1.h>

void systemInit (){
    currentStepA = 0;
    currentStepB = 16;
    divider = 16;
    previousDivider = 16;
    FullScale = 16;
    step = 1;
    currentStepA1 = 0;
    currentStepB1 = 16;
    divider1 = 16;
    previousDivider1 = 16;
    FullScale1 = 16;
    step1 = 1;
    
    // Main motor
    pwmA = sineTable[0];
    pwmB = sineTable[FullScale];
    if (dirReg == 0 ){
        phase = 0;
    }
    else{
        phase = 2;
    }
    
    TCPWM_1_WriteCompare(pwmA);
    TCPWM_2_WriteCompare(pwmB);
    Clock_PWM_MAIN_Start(); 

    TCPWM_1_Start();
	TCPWM_2_Start();
	TCPWM_1_TriggerCommand (TCPWM_1_MASK, TCPWM_1_CMD_START);
	TCPWM_2_TriggerCommand (TCPWM_2_MASK, TCPWM_2_CMD_START);	
	
    INTERNAL_STEP_Start();

    // Motor + 1
    pwmA1 = sineTable[0];
    pwmB1 = sineTable[FullScale1];
    if (dirReg1 == 0 ){
        phase1 = 0;
    }
    else{
        phase1 = 2;
    }
    
    TCPWM_3_WriteCompare(pwmA1);
    TCPWM_4_WriteCompare(pwmB1);
    Clock_PWM_MAIN_1_Start(); 

    TCPWM_3_Start();
	TCPWM_4_Start();
	TCPWM_3_TriggerCommand (TCPWM_3_MASK, TCPWM_3_CMD_START);
	TCPWM_4_TriggerCommand (TCPWM_4_MASK, TCPWM_4_CMD_START);	
	
    INTERNAL_STEP_1_Start();
}