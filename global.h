/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 
 This header file is for global definition
 
 *
 * ========================================
*/
#define OUTPUTLEVEL 127
#include <CYLIB.H>
uint8 currentStepA; // current step level of channel A, main motor
uint8 currentStepB; // current step level of channel B, main motor
uint8 currentStepA1; // current step level of channel A, motor +1
uint8 currentStepB1; // current step level of channel B, motor +1

uint8 divider; // divider value of step moter driver 2, 4, 8 ,16
uint8 divider1; // divider value of step moter driver 2, 4, 8 ,16
uint8 step; //step length
uint8 step1; //step length
uint8 previousDivider; // in case have various divider in the future
uint8 previousDivider1; // in case have various divider in the future
uint8 FullScale; // step from 0 to 1/4 waveform
uint8 FullScale1; // step from 0 to 1/4 waveform
uint8 phase; //current phase of driver 0, 1, 2, 3
uint8 phase1; //current phase of driver 0, 1, 2, 3
uint8 stepPulse;
uint8 stepPulse1;
uint8 previousStepPulse;
uint8 previousStepPulse1;
uint8 dirReg;// direction
uint8 dirReg1;// direction

uint8 pwmA; // determine the duty cycle (comes from sine table value here)
uint8 pwmB; // determine the duty cycle (comes from sine table value here)
uint8 pwmA1; // determine the duty cycle (comes from sine table value here)
uint8 pwmB1; // determine the duty cycle (comes from sine table value here)

const uint8 sineTable [17] = {100, 115, 130, 145, 159, 173, 186, 198, 210, 220, 229, 237, 243, 248, 252, 254, 255};
