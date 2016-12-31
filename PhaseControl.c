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

/* [] END OF FILE */
#include <phaseControl.h>

void phaseControl (uint8 currentphase, uint8 motor){
    
    if(motor == 1)
        DIR_REG_1_Write (currentphase);
    else
        DIR_REG_2_Write (currentphase);
}

void phaseMove(uint8 motor){
    
    if(motor == 1) {
        if((currentStepA == 0)||(currentStepB == 0)) {
    		if(dirReg == 0) { //Clockwise 
    			switch(phase) {
    				case 0:
    					phase = 2;
    				break;
    				case 1:
    					phase = 0;
    				break;
    				case 2:
    					phase = 3;
    				break;
    				case 3:
    					phase = 1;
    				break;
    				default:
    				break;
    			} // Clocwise phase setting
    		} // direction register = 0
    		else { // Counterclockwise
    			switch(phase) {
    				case 0:
    					phase = 1;
    				break;
    				case 1:
    					phase = 3;
    				break;
    				case 2:
    					phase = 0;
    				break;
    				case 3:
    					phase = 2;
    				break;
    				default:
    				break;
    			} // Counterclockwise phase setting
    		} // direction register not 0
    	} // Current step A or B = 0
    } // Motor = 1
    else {
        if((currentStepA1 == 0)||(currentStepB1 == 0)) {
    		if(dirReg1 == 0) { //Clockwise 
    			switch(phase1) {
    				case 0:
    					phase1 = 2;
    				break;
    				case 1:
    					phase1 = 0;
    				break;
    				case 2:
    					phase1 = 3;
    				break;
    				case 3:
    					phase1 = 1;
    				break;
    				default:
    				break;
    			} // Clocwise phase setting
    		} // direction register = 0
    		else { // Counterclockwise
    			switch(phase1) {
    				case 0:
    					phase1 = 1;
    				break;
    				case 1:
    					phase1 = 3;
    				break;
    				case 2:
    					phase1 = 0;
    				break;
    				case 3:
    					phase1 = 2;
    				break;
    				default:
    				break;
    			} // Counterclockwise phase setting
    		} // direction register not 0
    	} // Current step A or B = 0
    } // Motor = 2
}