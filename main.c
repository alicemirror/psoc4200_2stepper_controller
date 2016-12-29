/**
@file main.c
@brief main loop and initialization functions

Based on the dual stepper controller developer by Cypress Semiconductor

@author Enrico Miglino <balearicdynamics@gmail.com>
@date Dec 2016
@license Creative Commons Attribution 3.0 
*/
#include <device.h>
#include <global.h>
#include <systemInit.h>
#include <inputScan.h>
#include <Move.h>
#include <INTERNAL_STEP.h>
#include <INTERNAL_STEP_1.h>

// Stepper constants
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

// End-stop interrupt constants
#define NESTED_ISR          (1u) ///< Nested Interrupt Service Routine
#define DEFAULT_PRIORITY    (3u) ///< Default interrupt priority
#define HIGHER_PRIORITY     (2u) ///< Higher interrupt priority

// Led states
#define LIGHT_OFF           (0u) ///< End-stop LED status 
#define LIGHT_ON            (1u) ///< End-stop LED status 
// EndStop switches IDs
#define END_STOP_MOTOR1 1   ///< EndStop switch ID for motor 1
#define END_STOP_MOTOR2 2   ///< EndStop switch ID for motor 2

/* Interrupt prototypes */
CY_ISR_PROTO(GPIOIsrHandler);
CY_ISR_PROTO(NestedIsrHandler);

//! Main application. Initialization and infinite loop
int main() {
    uint16 i[2];
    uint8 l_previousStepPulse;
    uint8 l_stepPulse;
    uint8 jm;
    
    i[0] = 0;
    i[1] = 0;

    /* Set initial state (off) for LED */
    STATUS_LED_1_Write(LIGHT_OFF);
    STATUS_LED_2_Write(LIGHT_OFF);

    /* Sets up the GPIO interrupt and enables it */
    isr_GPIO_StartEx(GPIOIsrHandler);

    /* Changes initial priority for the GPIO interrupt */
    isr_GPIO_SetPriority(DEFAULT_PRIORITY);

    /* Sets up the nested interrupt, sets priority and enables it */
//    CyIntSetVector(NESTED_ISR,NestedIsrHandler);
//    CyIntSetPriority(NESTED_ISR,HIGHER_PRIORITY);
//    CyIntEnable(NESTED_ISR);

    /* Enable global interrupts */
    CyGlobalIntEnable;

    systemInit();

    // Intinite loop
    while(1) {

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

/**
* The interrupt service routine for the GPIO 
*  Clears a pending Interrupt.
*  Clears a pin Interrupt.
*  Blinks the LED with the LED_Isr pin.
*  Calls nested interrupt.
*/
CY_ISR(GPIOIsrHandler)
{
    /* Clear pending Interrupt */
    isr_GPIO_ClearPending();
    
    /* Clear pin Interrupt */
    Pin_Sw_ClearInterrupt();
    
    /* Turn On the LED corresponding to the end-stop */
    if(Pin_Sw_Read() == END_STOP_MOTOR1)
        STATUS_LED_1_Write(LIGHT_ON);
    if(Pin_Sw_Read() == END_STOP_MOTOR2)
        STATUS_LED_2_Write(LIGHT_ON);

    // Testing only - will be replaced by the motor stop procedure
    CyDelay(250);

    /* Turn Off the LEDs */
    STATUS_LED_1_Write(LIGHT_OFF);
    STATUS_LED_2_Write(LIGHT_OFF);
}
