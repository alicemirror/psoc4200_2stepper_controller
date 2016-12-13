/* ========================================
 *
 * The following firmware was developed by Cypress Semiconductor
 * This work is licensed under a Creative Commons Attribution 3.0 Unported License.
 * 
 * http://creativecommons.org/licenses/by/3.0/deed.en_US
 * 
 * You are free to:
 * -To Share — to copy, distribute and transmit the work 
 * -To Remix — to adapt the work 
 * -To make commercial use of the work
 *
*/
#include <device.h>
#include <global.h>
#include <systemInit.h>
#include <inputScan.h>
#include <Move.h>
#include <INTERNAL_STEP.h>
#include <INTERNAL_STEP_1.h>
#define PH1 3204 //run
#define PH2 4800 //p
#define PH3 8000 //run
#define PH4 9600 //p
#define PH5 16000 //run
#define PH6 17600 //p
#define PH7 24000 //run
#define PH8 27200 //p
#define PH9 28800 //run
#define PH10 32000 //p
#define PH11 33600 //run
#define PH12 36800 //p

void main() {
    uint16 i[2];

    uint8 l_previousStepPulse;
    uint8 l_stepPulse;
    uint8 jm;
    
    i[0] = 0;
    i[1] = 0;
    
    systemInit();

    while(1) {

        if(END_STOP_1_Read()) 
            STATUS_LED_1_Write(0x00);
        else
            STATUS_LED_1_Write(0x01);

        if(END_STOP_2_Read()) 
            STATUS_LED_2_Write(0x00);
        else
            STATUS_LED_2_Write(0x01);
        
        
        // Loop on two motors
        for(jm = 1; jm <= 2; jm++) {
            // Assign local variables to for the current motor
            if(jm == 1) {
                l_previousStepPulse = previousStepPulse;
                l_stepPulse = stepPulse;
            }
            else {
                l_previousStepPulse = previousStepPulse1;
                l_stepPulse = stepPulse1;
            }

            // Process stepping
            inputScan(jm);
            
            if (l_previousStepPulse == 0 && l_stepPulse == 1){
      			if (i[jm - 1] < PH1){
                    if(jm == 1) dirReg = 0; else dirReg1 = 0;
              		Move(jm);
              		i[jm - 1]++;
      			} // i < PH1
      			else if (PH1 <= i[jm - 1] && i[jm - 1] < PH2){
       				i[jm - 1]++;
      			} // PH1 <= i < PH2
      			else if (PH2 <= i[jm - 1] && i[jm - 1] < PH3){
                    if(jm == 1) dirReg = 1; else dirReg1 = 1;
       				Move(jm);
       				i[jm - 1]++;
      			} // PH2 <= i < PH3
    			else if (PH3 <= i[jm - 1] && i[jm - 1]< PH4){
    				i[jm - 1]++;
    			} // PH3 <= i < PH4
      			else if (PH4 <= i[jm - 1] && i[jm - 1] < PH5){
    				if (i[jm - 1] == PH4){
                        if(jm == 1) {                        
            				INTERNAL_STEP_WritePeriod(2000);
            				INTERNAL_STEP_WriteCompare(1000);
                        } // motor 1
                        else {
            				INTERNAL_STEP_1_WritePeriod(2000);
            				INTERNAL_STEP_1_WriteCompare(1000);
                        } // motor 2
                    } // PH4
                    if(jm == 1) dirReg = 0; else dirReg1 = 0;
       				Move(jm);
       				i[jm - 1]++;
      			} // PH4 <= i < PH5
      			else if (PH5 <= i[jm - 1] && i[jm - 1] < PH6){
       				i[jm - 1]++;
      			} // PH5 <= i < PH6
      			else if (PH6 <= i[jm - 1] && i[jm - 1] < PH7){
                    if(jm == 1) dirReg = 1; else dirReg1 = 1;
       				Move(jm);		
       				i[jm - 1]++;
      			} // PH6 <= i < PH7
      			else if (PH7 <= i[jm - 1] && i[jm - 1] < PH8){
       				i[jm - 1]++;
      			} // PH7 <= i < PH8
      			else if (PH8 <= i[jm - 1] && i[jm - 1] < PH9){
    				if (i[jm - 1] == PH8){
                        if(jm == 1) {                        
            				INTERNAL_STEP_WritePeriod(4000);
            				INTERNAL_STEP_WriteCompare(2000);
                        } // motor 1
                        else {
            				INTERNAL_STEP_1_WritePeriod(4000);
            				INTERNAL_STEP_1_WriteCompare(2000);
                        } // motor 2 
                    } // PH8
                    if(jm == 1) dirReg = 0; else dirReg1 = 0;
       				Move(jm);
       				i[jm - 1]++;
      			} // PH8 <= i < PH9
      			else if (PH9 <= i[jm - 1] && i[jm - 1] < PH10){
       				i[jm - 1]++;
      			} // PH9 <= i < PH10
      			else if (PH10 <= i[jm - 1] && i[jm - 1] < PH11){
                    if(jm == 1) dirReg = 1; else dirReg1 = 1;
    				Move(jm);
    				i[jm - 1]++;
      			} // PH10 <= i < PH11
      			else if (PH11 <= i[jm - 1] && i[jm - 1] < PH12){
       				i[jm - 1]++;
      			} // PH11 <= i < PH12
      			else {
                    if(jm == 1) dirReg = 1; else dirReg1 = 1;
       				Move(jm);
//                    i[jm - 1] = 0;
      			} // None of the previous cases
    		} // l_previousStepPulse == 0 && l_stepPulse == 1
    		else{
    		}
    	} // Loop on two motors
    } // Forever loop
}
