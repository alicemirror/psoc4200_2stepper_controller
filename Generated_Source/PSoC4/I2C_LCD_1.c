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
#include <device.h>
#include "I2C_LCD_1.h"

void I2C_LCD_1_WriteToSlave(uint8 address, uint8* abWriteBuffer, uint8 bLength);
void I2C_LCD_1_ReadFromSlave(uint8 address, uint8 *abReadBuffer, uint8 bLength);

char8 const CYCODE I2C_LCD_1_hex[16u] = "0123456789ABCDEF";


/*******************************************************************************
* Function Name: I2C_LCD_1_PutChar
********************************************************************************
* Summary:
*   Write one character on to LCD display
*
* Parameters:
*  txdata - character to write to LCD
*
* Return:
*  void
*
* Notes
*  Sets the appropriate character mask bit before writing the actual character to the 
*  LCD. The LCD used with the kit is a 'S' character set display
*******************************************************************************/
void I2C_LCD_1_PutChar(char txdata)
{	
	uint8 dataBuffer[2];
	
	I2C_LCD_1_IsReady(); /* Wait till the LCD is ready */
	
	/* Send the data command and the actual data modified per the character set */
    dataBuffer[0] = I2C_LCD_1_DATA_SEND;
    dataBuffer[1] = txdata;//I2C_LCD_1_CHARACTER_SET_S_MASK ^ txdata;
    I2C_LCD_1_WriteToSlave(I2C_LCD_1_ADDRESS, &dataBuffer[0], sizeof(dataBuffer));
}

/*******************************************************************************
* Function Name: I2C_LCD_1_WriteData
********************************************************************************
*
* Summary:
*  Writes a data byte to the buffer 
*
* Parameters:
*  dataByte = data to send
*
* Return:
*  No character mask is applied on data to be sent. Use I2C_LCD_1_PutChar()
*  if character mask should be applied to the data before transmitting.
*******************************************************************************/
void I2C_LCD_1_WriteData(uint8 dataByte) 
{
    uint8 dataBuffer[2];
	
	I2C_LCD_1_IsReady(); /* Wait till the LCD is ready */
	
	/* Send the data command and the actual data */
    dataBuffer[0] = I2C_LCD_1_DATA_SEND;
    dataBuffer[1] = dataByte;
    I2C_LCD_1_WriteToSlave(I2C_LCD_1_ADDRESS, &dataBuffer[0], sizeof(dataBuffer));    
}

/*******************************************************************************
* Function Name: I2C_LCD_1_WriteControl
********************************************************************************
*
* Summary:
*  Sends a command (with a "command" prefix) to LCD
*
* Parameters:
*  cmd = command to send
*
* Return:
*  void
*******************************************************************************/
void I2C_LCD_1_WriteControl(uint8 cmd) 
{
    uint8 cmdBuffer[2];
	
	I2C_LCD_1_IsReady();   /* Wait till the LCD is ready */
    
	/* Send the command prefix and the actual command */
    cmdBuffer[0] = I2C_LCD_1_COMMAND_SEND;
    cmdBuffer[1] = cmd;
    I2C_LCD_1_WriteToSlave(I2C_LCD_1_ADDRESS, &cmdBuffer[0], sizeof(cmdBuffer));
}

/*******************************************************************************
* Function Name: I2C_LCD_1_Start
********************************************************************************
*
* Summary:
*  Initialize the LCD by configuring the LCD module through I2C
*
* Parameters:
*  void
*
* Return:
*  void
*******************************************************************************/
void I2C_LCD_1_Start(void)
{
	/* Reset the LCD module by asserting reset pin high for 1 ms */
	//I2C_LCD_1_Reset_Write(0x01);
	//CyDelay(1);
	//I2C_LCD_1_Reset_Write(0x00);								
	
	/* Start the I2C block */
	I2C_LCD_1_SCB_Start();		
	CyDelay(100);


	/* Initialization sequence for the LCD module */
#if 0	
	/* Choose Extended Instruction set */
	I2C_LCD_1_WriteControl(I2C_LCD_1_FUNCTION_SET_EXTENDED);
	/* Screen Configuration */
	I2C_LCD_1_WriteControl(I2C_LCD_1_SCREEN_CONF);
	/* Display Configuration */
	I2C_LCD_1_WriteControl(I2C_LCD_1_DISP_CONF);
	/* Icon mode configuration */
	I2C_LCD_1_WriteControl(I2C_LCD_1_ICON_CTL);
	/* Internal LCD Bias voltage configuration */
	I2C_LCD_1_WriteControl(I2C_LCD_1_VLCD_SET);
	/* Choose Standard Instruction set */
	I2C_LCD_1_WriteControl(I2C_LCD_1_FUNCTION_SET_STANDARD);
	/* Cursor shift direction */
	I2C_LCD_1_WriteControl(I2C_LCD_1_ENTRY_MODE_SET);
	/* Power the display */
	I2C_LCD_1_WriteControl(I2C_LCD_1_DISPLAY_CTL);
	/* Clear the LCD display */
	I2C_LCD_1_WriteControl(I2C_LCD_1_CLEAR_DISPLAY);
#endif	

#if 1
	/* Choose Standard Instruction set */
	I2C_LCD_1_WriteControl(I2C_LCD_1_FUNCTION_SET_STANDARD);
	CyDelayUs(100);
	/* Cursor shift direction */
	I2C_LCD_1_WriteControl(I2C_LCD_1_ENTRY_MODE_SET);
	CyDelayUs(100);	
	/* Power the display */
	I2C_LCD_1_WriteControl(I2C_LCD_1_DISPLAY_CTL);
	CyDelayUs(100);
	/* Clear the LCD display */
	I2C_LCD_1_WriteControl(I2C_LCD_1_CLEAR_DISPLAY);
	CyDelay(1);	
#endif
}

/*******************************************************************************
* Function Name: I2C_LCD_1_Stop
********************************************************************************
*
* Summary:
*  Turns off the display of the LCD screen.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void I2C_LCD_1_Stop() 
{
    /* Calls LCD Off Macro */
    I2C_LCD_1_DisplayOff();
}

/*******************************************************************************
* Function Name: I2C_LCD_1_Position
********************************************************************************
*
* Summary:
*  Moves active cursor location to a point specified by the input arguments
*
* Parameters:
*  row:     Row of LCD module to be written
*  column:  Column of LCD module to be written
*
* Return:
*  void
*******************************************************************************/
void I2C_LCD_1_Position(uint8 row, uint8 column)
{
    switch (row)
    {
        case 0:
             I2C_LCD_1_WriteControl(I2C_LCD_1_ROW_0_START + column);
            break;
        case 1:
             I2C_LCD_1_WriteControl(I2C_LCD_1_ROW_1_START + column);
            break;

        default:
		    /* if default case is hit, invalid row argument was passed.*/
            break;
    }
}

/*******************************************************************************
* Function Name: I2C_LCD_1_PrintString
********************************************************************************
*
* Summary:
*  Prints the parameter string on the LCD screen starting from the currently 
*  set cursor position
*
* Parameters:
*  pch - Pointer to the string which should be displayed on the LCD
*
* Return:
*  void
*******************************************************************************/
void I2C_LCD_1_PrintString(char *pch)
{

	/* Until null is reached, print next character */
    while (*pch != 0)
    {
        I2C_LCD_1_PutChar(*pch);
        ++pch;
    }
}

/*******************************************************************************
* Function Name: I2C_LCD_1_PrintDecUint16
********************************************************************************
*
* Summary:
*  Print an uint16 value as a left-justified decimal value.
*
* Parameters:
*  value:  The 16-bit value to be printed out as ASCII characters.
*
* Return:
*  None.
*
*******************************************************************************/
void I2C_LCD_1_PrintDecUint16(uint16 value)
{
        char8 number[I2C_LCD_1_NUMBER_OF_REMAINDERS];
        char8 temp[I2C_LCD_1_NUMBER_OF_REMAINDERS];

        uint8 index = 0u;
        uint8 numDigits = 0u;


        /* Load these in reverse order */
        while(value >= I2C_LCD_1_TEN)
        {
            temp[index] = (value % I2C_LCD_1_TEN) + '0';
            value /= I2C_LCD_1_TEN;
            index++;
        }

        temp[index] = (value % I2C_LCD_1_TEN) + '0';
        numDigits = index;

        /* While index is greater than or equal to zero */
        while (index != 0xFFu)
        {
            number[numDigits - index] = temp[index];
            index--;
        }

        /* Null Termination */
        number[numDigits + 1u] = (char8) 0;

        /* Print out number */
        I2C_LCD_1_PrintString(number);
}

/*******************************************************************************
*  Function Name: I2C_LCD_1_PrintHexUint8
********************************************************************************
*
* Summary:
*  Print a byte as two ASCII characters.
*
* Parameters:
*  value:  The byte to be printed out as ASCII characters.
*
* Return:
*  None.
*
*******************************************************************************/
void I2C_LCD_1_PrintHexUint8(uint8 value) 
{
    I2C_LCD_1_PutChar((char8) I2C_LCD_1_hex[value >> I2C_LCD_1_BYTE_UPPER_NIBBLE_SHIFT]);
    I2C_LCD_1_PutChar((char8) I2C_LCD_1_hex[value & I2C_LCD_1_BYTE_LOWER_NIBBLE_MASK]);
}

/*******************************************************************************
*  Function Name: I2C_LCD_1_PrintHexUint16
********************************************************************************
*
* Summary:
*  Print a uint16 as four ASCII characters.
*
* Parameters:
*  value:   The uint16 to be printed out as ASCII characters.
*
* Return:
*  None.
*
*******************************************************************************/
void I2C_LCD_1_PrintHexUint16(uint16 value) 
{
    I2C_LCD_1_PrintHexUint8(value >> I2C_LCD_1_U16_UPPER_BYTE_SHIFT);
    I2C_LCD_1_PrintHexUint8(value & I2C_LCD_1_U16_LOWER_BYTE_MASK);
}
	
/*******************************************************************************
* Function Name: I2C_LCD_1_IsReady
********************************************************************************
*
* Summary:
*  Polls LCD until the ready bit is set.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Note:
*  Polls the status by checking th BF (busy flag) bit in the control register
*
*******************************************************************************/
void I2C_LCD_1_IsReady(void)
{
	
#if 0
    uint8 dataBuffer;
	
	/* Write 1-byte to slave to select the control register */
	dataBuffer = I2C_LCD_1_COMMAND_SEND;			
	I2C_LCD_1_WriteToSlave(I2C_LCD_1_ADDRESS, &dataBuffer, 1);
    	
	do
	{		
		/* Read the control register content */		
		I2C_LCD_1_ReadFromSlave(I2C_LCD_1_ADDRESS, &dataBuffer, 1);
		/* Repeat loop till the busy flag is cleared in the control register  */
	}while((dataBuffer & I2C_LCD_1_BUSY_FLAG_MASK) == I2C_LCD_1_BUSY_FLAG_MASK);
#endif

	CyDelayUs(20);
}

/*******************************************************************************
* Function Name: I2C_LCD_1_WriteToSlave
********************************************************************************
* Summary:
*        Writes data to the I2C slave device
*
* Parameters:
*  address - address of the I2C slave being addressed
*  abWriteBuffer - buffer which contains the data to be written
*  bLength - length of the data to be written
* 
* Return:
*  None
*
* Note:
*  Exits the function if the write is successful, otherwise keeps trying 
*  (blocking call)
*
*******************************************************************************/
void I2C_LCD_1_WriteToSlave(uint8 address, uint8* abWriteBuffer, uint8 bLength)
{
    uint8 status;
    
    /* Wait for pending transfer, if any, to complete */
    while (I2C_LCD_1_SCB_I2CMasterStatus() & I2C_LCD_1_SCB_I2C_MSTAT_XFER_INP);    
	
    do
    {
        do
        {
            /* clear any previous status */
            I2C_LCD_1_SCB_I2CMasterClearStatus(); 
            
            /* write data to the slave */
            status = I2C_LCD_1_SCB_I2CMasterWriteBuf(address, abWriteBuffer, bLength, I2C_LCD_1_SCB_I2C_MODE_COMPLETE_XFER);
			
			/* Check if the start condition was generated properly. Else, resend again */  
			
        }while(status != I2C_LCD_1_SCB_I2C_MSTR_NO_ERROR);       
        
        /* wait till write operation is complete or an error flag is set */
        while ((I2C_LCD_1_SCB_I2CMasterStatus() & (I2C_LCD_1_SCB_I2C_MSTAT_WR_CMPLT | I2C_LCD_1_SCB_I2C_MSTAT_ERR_MASK)) == 0);
		
		/* Repeat until the entire write transfer has been successfully completed  */
    
    }while(I2C_LCD_1_SCB_I2CMasterStatus()!= I2C_LCD_1_SCB_I2C_MSTAT_WR_CMPLT);
    
    /* clear any previous status */
    I2C_LCD_1_SCB_I2CMasterClearStatus(); 
}

/*******************************************************************************
* Function Name: I2C_LCD_1_ReadFromSlave
********************************************************************************
* Summary:
*      This function reads bLength number of bytes of data from the I2C slave
*      device, the data read would be stored in the abI2CBuffer
*
* Parameters:
*  address - address of the I2C slave being addressed
*  bLength - the length of the data to be read
*  abReadBuffer - Pointer to buffer which would hold the I2C read data
*
*  Return:
*   None
*
* Note:
*  Exits the function if the read is successful, otherwise keeps retrying
* (blocking call). Note that if the read operation is desired staring from
*  a specific buffer location, that buffer offset location should first be written using
*  WriteToSlave() function. Then, the ReadFromSlave() function should be called
*  to start reading from that location.
*
*******************************************************************************/
void I2C_LCD_1_ReadFromSlave(uint8 address, uint8 *abReadBuffer, uint8 bLength)
{
	uint8 status = 0;
    
    /* Wait for pending transfer, if any, to complete */
    while (I2C_LCD_1_SCB_I2CMasterStatus() & I2C_LCD_1_SCB_I2C_MSTAT_XFER_INP);
    
	do
	{	
	    do
	    {
			/* clear any previous status */
    		I2C_LCD_1_SCB_I2CMasterClearStatus(); 
			
	        /* read back the data */
	        status = I2C_LCD_1_SCB_I2CMasterReadBuf(address, abReadBuffer, bLength, I2C_LCD_1_SCB_I2C_MODE_COMPLETE_XFER);	
			
			/* Check if the start condition was generated properly. Else, resend again */ 
			
	    }while(status != I2C_LCD_1_SCB_I2C_MSTR_NO_ERROR);		
        
        /* wait till read operation is complete or an error flag is set */
        while ((I2C_LCD_1_SCB_I2CMasterStatus() & (I2C_LCD_1_SCB_I2C_MSTAT_RD_CMPLT | I2C_LCD_1_SCB_I2C_MSTAT_ERR_MASK)) == 0);
		
		/* Repeat until the entire read transfer has been successfully completed  */
    
    }while(I2C_LCD_1_SCB_I2CMasterStatus()!= I2C_LCD_1_SCB_I2C_MSTAT_RD_CMPLT);
    
    /* clear any previous status */
    I2C_LCD_1_SCB_I2CMasterClearStatus(); 
}

/* [] END OF FILE */
