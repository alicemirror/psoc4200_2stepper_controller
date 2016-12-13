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
#include <Move.h>
#include <TCPWM_1.h>
#include <TCPWM_2.h>
#include <TCPWM_3.h>
#include <TCPWM_4.h>
#include <genSine.h>
void Move(uint8 motor) {
    
    if(motor == 1) {
        if(divider != previousDivider) {
        //reset the step is the divider number is changed
    		switch(divider) {
    			case 2:
    			    step = 8;
    			    FullScale = 16;
    			break;
    		    case 4:
    			    step = 4;
    			    FullScale = 16;
    			break;
    			case 8:
    				step = 2;
    				FullScale = 16;
    			break;
    			case 16:
    				step = 1;
    				FullScale = 16;
    			break;
    			default:
    			break;
            } // Step settings
            currentStepA = 0;
            // CHA and CHB have 90 degree phase delay
    	    if(currentStepA < FullScale) {
    		    currentStepB = currentStepA + FullScale;
    	    } // Step A smaller than FullScale
    	    else if(currentStepA >= FullScale) {
    			currentStepB = currentStepA - FullScale;
    	    } // stap A greater than FullScale
        } // Divider changed (!= previous divider)
        else { // nomal operation
        //The total step is 2 times to the fullscale
    	    phaseMove(motor);
        	phaseControl(phase, motor);
        	if(dirReg == 1) { //Clockwise 
    			if (currentStepA < (FullScale-step+FullScale)) {
    				currentStepA = currentStepA +step;
    			}
    			else {
    				currentStepA = 0;
    			}
    		} // Clockwise direction
            else { // Counterclockwise
    			if (currentStepA>=step) {
    				currentStepA = currentStepA - step;
    			}
    			else {
    				currentStepA = FullScale-step+FullScale;
    			}
    		} // Counterclockwise direction
        } // Divider unchanged, normal operation
    	
    	if(currentStepA < FullScale) {
    		currentStepB = currentStepA + FullScale;
    	} // Step A smaller than FulLScale
    	else if(currentStepA >= FullScale) {
    		currentStepB = currentStepA - FullScale;
    	} // Step A greater than FullScale

        // Pwm write on motor
        TCPWM_1_WriteCompare(genSine(currentStepA, motor));
        TCPWM_2_WriteCompare(genSine(currentStepB, motor));
    } // Motor 1
    else { // Motor 2
        if(divider1 != previousDivider1) {
        //reset the step is the divider number is changed
    		switch(divider1) {
    			case 2:
    			    step1 = 8;
    			    FullScale1 = 16;
    			break;
    		    case 4:
    			    step1 = 4;
    			    FullScale1 = 16;
    			break;
    			case 8:
    				step1 = 2;
    				FullScale1 = 16;
    			break;
    			case 16:
    				step1 = 1;
    				FullScale1 = 16;
    			break;
    			default:
    			break;
            } // Step settings
            currentStepA1 = 0;
            // CHA and CHB have 90 degree phase delay
    	    if(currentStepA1 < FullScale1) {
    		    currentStepB1 = currentStepA1 + FullScale1;
    	    } // Step A smaller than FullScale
    	    else if(currentStepA1 >= FullScale1) {
    			currentStepB1 = currentStepA1 - FullScale1;
    	    } // stap A greater than FullScale
        } // Divider changed (!= previous divider)
        else { // nomal operation
        //The total step is 2 times to the fullscale
    	    phaseMove(motor);
        	phaseControl(phase1, motor);
        	if(dirReg1 == 1) { //Clockwise 
    			if (currentStepA1 < (FullScale1 - step1 + FullScale1)) {
    				currentStepA1 = currentStepA1 + step1;
    			}
    			else {
    				currentStepA1 = 0;
    			}
    		} // Clockwise direction
            else { // Counterclockwise
    			if (currentStepA1 >= step1) {
    				currentStepA1 = currentStepA1 - step1;
    			}
    			else {
    				currentStepA1 = FullScale1 - step1 + FullScale1;
    			}
    		} // Counterclockwise direction
        } // Divider unchanged, normal operation
    	
    	if(currentStepA1 < FullScale1) {
    		currentStepB1 = currentStepA1 + FullScale1;
    	} // Step A smaller than FulLScale
    	else if(currentStepA1 >= FullScale1) {
    		currentStepB1 = currentStepA1 - FullScale1;
    	} // Step A greater than FullScale

        // Pwm write on motor
        TCPWM_3_WriteCompare(genSine(currentStepA1, motor));
        TCPWM_4_WriteCompare(genSine(currentStepB1, motor));
    } // Motor 2
}