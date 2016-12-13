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

#if !defined(I2C_LCD_1_H)
#define I2C_LCD_1_H

#include <device.h>

/*******************************************************************************
* Various defines for Newhaven Display LCD
*******************************************************************************/
#define I2C_LCD_1_ADDRESS                 0x3Cu //0x3Au

#define I2C_LCD_1_COMMAND_SEND            0x80u /* Command send opcode: 0x00u-- send more opcodes; 0x80 -- send one opcode */
#define I2C_LCD_1_DATA_SEND               0x40u /* Data send opcode */



#define I2C_LCD_1_CURSOR_HOME             0x02u

#define I2C_LCD_1_FUNCTION_SET_STANDARD   0x38u //0x34u  /* Select Standard Instruction set, 2x16 display */
#define I2C_LCD_1_FUNCTION_SET_EXTENDED   0x3Cu //0x35u  /* Select Extended Instruction set, 2x16 display */
//#define I2C_LCD_1_SCREEN_CONF             	  0x02u  /* Split screen configuration  */
//#define I2C_LCD_1_DISP_CONF			  0x04u  /* LCD Module format: left to right column, and top to bottom rows  */
//#define I2C_LCD_1_ICON_CTL				  0x08u  /* Icon mode not supported. Disable all icon enable settings */
//#define I2C_LCD_1_VLCD_SET                       0xA0u  /* Set LCD bias voltage to 4.38 V since LCD module datasheet recommends 4.4 V */
#define I2C_LCD_1_ENTRY_MODE_SET          0x06u  /* RAM Address increments by one and no display shift */
#define I2C_LCD_1_DISPLAY_CTL             0x0Cu  /* Display on , Cursor off, Character blink off */
#define I2C_LCD_1_CLEAR_DISPLAY           0x01u  /* Clears LCD display */
#define I2C_LCD_1_DISPLAY_ON              0x0Cu
#define I2C_LCD_1_DISPLAY_OFF             0x08u
#define I2C_LCD_1_ROW_0_START             0x80u
#define I2C_LCD_1_ROW_1_START             0xC0u

#define I2C_LCD_1_CHARACTER_SET_S_MASK    0x80
#define I2C_LCD_1_BUSY_FLAG_MASK          0x80 /* Mask value for the busy flag bit */

#define  I2C_LCD_1_NUMBER_OF_REMAINDERS   (0x05u)
#define  I2C_LCD_1_TEN                    (0x0Au)

/* Other constants */
#define I2C_LCD_1_BYTE_UPPER_NIBBLE_SHIFT   (0x04u)
#define I2C_LCD_1_BYTE_LOWER_NIBBLE_MASK    (0x0Fu)
#define I2C_LCD_1_U16_UPPER_BYTE_SHIFT      (0x08u)
#define I2C_LCD_1_U16_LOWER_BYTE_MASK       (0xFFu)

void I2C_LCD_1_Start          (void);
void I2C_LCD_1_Stop          (void);
void I2C_LCD_1_PrintString    (char *pch);
void I2C_LCD_1_PutChar        (char ch);
void I2C_LCD_1_Position       (uint8 row, uint8 column);
void I2C_LCD_1_ClearDisplay   (void);
void I2C_LCD_1_IsReady        (void);

void I2C_LCD_1_WriteControl(uint8 cmd);
void I2C_LCD_1_WriteData(uint8 dataByte);

void I2C_LCD_1_PrintHexUint16(uint16 value);
void I2C_LCD_1_PrintHexUint8(uint8 value);
void I2C_LCD_1_PrintDecUint16    (uint16 value);
#define I2C_LCD_1_PrintNumber(x)       I2C_LCD_1_PrintDecUint16(x)
#define I2C_LCD_1_PrintInt8(x)         I2C_LCD_1_PrintHexUint8(x)
#define I2C_LCD_1_PrintInt16(x)        I2C_LCD_1_PrintHexUint16(x)

/* Clear Macro */
#define I2C_LCD_1_ClearDisplay() {I2C_LCD_1_WriteControl(I2C_LCD_1_CLEAR_DISPLAY);CyDelay(1);}

/* Off Macro */
#define I2C_LCD_1_DisplayOff() I2C_LCD_1_WriteControl(I2C_LCD_1_DISPLAY_OFF) 

/* On Macro */
#define I2C_LCD_1_DisplayOn() I2C_LCD_1_WriteControl(I2C_LCD_1_DISPLAY_ON)

#endif
//[] END OF FILE
