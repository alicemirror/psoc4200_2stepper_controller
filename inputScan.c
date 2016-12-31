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

#include <inputScan.h>

void inputScan(uint8 motor) {
    
    if(motor == 1) {
        // Motor 1
        if (STEP_INPUT_SOURCE_1_Read() == 0){
            previousStepPulse  = stepPulse;
            stepPulse = STEP_INPUT_1_Read(); // rising edge, reserved for potential glith
        }
        else{
            previousStepPulse = stepPulse;
            stepPulse = INTERNAL_STEP_OUT_1_Read();
        }
        if (DIR_INPUT_SOURCE_1_Read()== 0){
            dirReg = DIR_INPUT_1_Read();
            
        }
        else{
            dirReg = 0;
        }
    } // Motor 1
    else {
        // Motor 2
        if (STEP_INPUT_SOURCE_2_Read() == 0){
            previousStepPulse1 = stepPulse1;
            stepPulse1 = STEP_INPUT_2_Read(); // rising edge, reserved for potential glith
        }
        else{
            previousStepPulse1 = stepPulse1;
            stepPulse1 = INTERNAL_STEP_OUT_2_Read();
        }
        if (DIR_INPUT_SOURCE_2_Read()== 0){
            dirReg1 = DIR_INPUT_2_Read();
            
        }
        else{
            dirReg1 = 0;
        }
    }
}