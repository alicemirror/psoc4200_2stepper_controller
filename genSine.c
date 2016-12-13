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

#include <genSine.h>
uint8 genSine(uint8 position, uint8 motor) {
	uint8 index;
    
    if(motor == 1) {
    	if(position > FullScale) {
    		index = (FullScale - position + FullScale);			
    	}
    	else {	
    			index = position;
    	}
        return sineTable[index];
    } // Motor 1
    else {
        // Motor 2
    	if(position > FullScale1) {
    		index = (FullScale1 - position + FullScale1);			
    	}
    	else {	
    			index = position;
    	}
        return sineTable[index];
    } // Motor 2
}