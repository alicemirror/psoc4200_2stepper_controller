/*******************************************************************************
* File Name: SCB_1_BOOT.c
* Version 1.0
*
* Description:
*
*
********************************************************************************
* Copyright 2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "SCB_1.h"

#if defined(CYDEV_BOOTLOADER_IO_COMP) && ((CYDEV_BOOTLOADER_IO_COMP == CyBtldr_SCB_1) || \
                                          (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_Custom_Interface))

/*******************************************************************************
* Function Name: SCB_1_CyBtldrCommStart
********************************************************************************
*
* Summary:
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void SCB_1_CyBtldrCommStart(void)
{
    #if(SCB_1_SCB_MODE_UNCFG_CONST_CFG)
        if(SCB_1_SCB_MODE_I2C_RUNTM_CFG)
        {
            SCB_1_I2CCyBtldrCommStart();
        }
        else if(SCB_1_SCB_MODE_SPI_RUNTM_CFG)
        {
            SCB_1_SpiCyBtldrCommStart();
        }
        else if(SCB_1_SCB_MODE_UART_RUNTM_CFG)
        {
            SCB_1_UartCyBtldrCommStart();
        }
        else if(SCB_1_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            SCB_1_EzI2CCyBtldrCommStart();
        }
        else if(SCB_1_SCB_MODE_EZSPI_RUNTM_CFG)
        {
            SCB_1_EzSpiCyBtldrCommStart();
        }
        else
        {
            /* Unknown mode: do nothing */
        }
    #else

        #if(SCB_1_SCB_MODE_I2C_CONST_CFG)
            SCB_1_I2CCyBtldrCommStart();

        #elif(SCB_1_SCB_MODE_SPI_CONST_CFG)
            SCB_1_SpiCyBtldrCommStart();

        #elif(SCB_1_SCB_MODE_UART_CONST_CFG)
            SCB_1_UartCyBtldrCommStart();

        #elif(SCB_1_SCB_MODE_EZI2C_CONST_CFG)
            SCB_1_EzI2CCyBtldrCommStart();

        #else
            SCB_1_EzSpiCyBtldrCommStart();

        #endif /* (SCB_1_SCB_MODE_I2C_CONST_CFG) */

    #endif /* (SCB_1_SCB_MODE_UNCFG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: SCB_1_CyBtldrCommStop
********************************************************************************
*
* Summary:
*  Disables the communication component and disables the interrupt.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void SCB_1_CyBtldrCommStop(void)
{
    #if(SCB_1_SCB_MODE_UNCFG_CONST_CFG)
        if(SCB_1_SCB_MODE_I2C_RUNTM_CFG)
        {
            SCB_1_I2CCyBtldrCommStop();
        }
        else if(SCB_1_SCB_MODE_SPI_RUNTM_CFG)
        {
            SCB_1_SpiCyBtldrCommStop();
        }
        else if(SCB_1_SCB_MODE_UART_RUNTM_CFG)
        {
            SCB_1_UartCyBtldrCommStop();
        }
        else if(SCB_1_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            SCB_1_EzI2CCyBtldrCommStop();
        }
        else if(SCB_1_SCB_MODE_EZSPI_RUNTM_CFG)
        {
            SCB_1_EzSpiCyBtldrCommStop();
        }
        else
        {
            /* Unknown mode: do nothing */
        }
    #else

        #if(SCB_1_SCB_MODE_I2C_CONST_CFG)
            SCB_1_I2CCyBtldrCommStop();

        #elif(SCB_1_SCB_MODE_SPI_CONST_CFG)
            SCB_1_SpiCyBtldrCommStop();

        #elif(SCB_1_SCB_MODE_UART_CONST_CFG)
            SCB_1_UartCyBtldrCommStop();

        #elif(SCB_1_SCB_MODE_EZI2C_CONST_CFG)
            SCB_1_EzI2CCyBtldrCommStop();

        #else
            SCB_1_EzSpiCyBtldrCommStop();

        #endif /* (SCB_1_SCB_MODE_I2C_CONST_CFG) */

    #endif /* (SCB_1_SCB_MODE_UNCFG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: SCB_1_CyBtldrCommReset
********************************************************************************
*
* Summary:
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*
*******************************************************************************/
void SCB_1_CyBtldrCommReset(void)
{
    #if(SCB_1_SCB_MODE_UNCFG_CONST_CFG)
        if(SCB_1_SCB_MODE_I2C_RUNTM_CFG)
        {
            SCB_1_I2CCyBtldrCommReset();
        }
        else if(SCB_1_SCB_MODE_SPI_RUNTM_CFG)
        {
            SCB_1_SpiCyBtldrCommReset();
        }
        else if(SCB_1_SCB_MODE_UART_RUNTM_CFG)
        {
            SCB_1_UartCyBtldrCommReset();
        }
        else if(SCB_1_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            SCB_1_EzI2CCyBtldrCommReset();
        }
        else if(SCB_1_SCB_MODE_EZSPI_RUNTM_CFG)
        {
            SCB_1_EzSpiCyBtldrCommReset();
        }
        else
        {
            /* Unknown mode: do nothing */
        }
    #else

        #if(SCB_1_SCB_MODE_I2C_CONST_CFG)
            SCB_1_I2CCyBtldrCommReset();

        #elif(SCB_1_SCB_MODE_SPI_CONST_CFG)
            SCB_1_SpiCyBtldrCommReset();

        #elif(SCB_1_SCB_MODE_UART_CONST_CFG)
            SCB_1_UartCyBtldrCommReset();

        #elif(SCB_1_SCB_MODE_EZI2C_CONST_CFG)
            SCB_1_EzI2CCyBtldrCommReset();

        #else
            SCB_1_EzSpiCyBtldrCommReset();

        #endif /* (SCB_1_SCB_MODE_I2C_CONST_CFG) */

    #endif /* (SCB_1_SCB_MODE_UNCFG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: SCB_1_CyBtldrCommRead
********************************************************************************
*
* Summary:
*
* Parameters:
*  pData:    pointer to pData buffer with response command.
*  Size:     number of bytes required to be transmitted.
*  Count:    actual size of pData was transmitted.
*  TimeOut:  timeout value in tries of 10uS.
*
* Return:
*  Status of transmit operation.
*
* Global variables:
*
*******************************************************************************/
cystatus SCB_1_CyBtldrCommRead(uint8 pData[], uint16 size, uint16 * count, uint8 timeOut)
{
    cystatus status;

    #if(SCB_1_SCB_MODE_UNCFG_CONST_CFG)
        if(SCB_1_SCB_MODE_I2C_RUNTM_CFG)
        {
            status = SCB_1_I2CCyBtldrCommRead(pData, size, count, timeOut);
        }
        else if(SCB_1_SCB_MODE_SPI_RUNTM_CFG)
        {
            status = SCB_1_SpiCyBtldrCommRead(pData, size, count, timeOut);
        }
        else if(SCB_1_SCB_MODE_UART_RUNTM_CFG)
        {
            status = SCB_1_UartCyBtldrCommRead(pData, size, count, timeOut);
        }
        else if(SCB_1_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            status = SCB_1_EzI2CCyBtldrCommRead(pData, size, count, timeOut);
        }
        else if(SCB_1_SCB_MODE_EZSPI_RUNTM_CFG)
        {
            status = SCB_1_EzSpiCyBtldrCommRead(pData, size, count, timeOut);
        }
        else
        {
            status = CYRET_INVALID_STATE; /* Unknown mode: return status */
        }
    #else

        #if(SCB_1_SCB_MODE_I2C_CONST_CFG)
            status = SCB_1_I2CCyBtldrCommRead(pData, size, count, timeOut);

        #elif(SCB_1_SCB_MODE_SPI_CONST_CFG)
            status = SCB_1_SpiCyBtldrCommRead(pData, size, count, timeOut);

        #elif(SCB_1_SCB_MODE_UART_CONST_CFG)
            status = SCB_1_UartCyBtldrCommRead(pData, size, count, timeOut);

        #elif(SCB_1_SCB_MODE_EZI2C_CONST_CFG)
            status = SCB_1_EzI2CCyBtldrCommRead(pData, size, count, timeOut);

        #else
           status = SCB_1_EzSpiCyBtldrCommRead(pData, size, count, timeOut);

        #endif /* (SCB_1_SCB_MODE_I2C_CONST_CFG) */

    #endif /* (SCB_1_SCB_MODE_UNCFG_CONST_CFG) */

    return(status);
}


/*******************************************************************************
* Function Name: SCB_1_CyBtldrCommWrite
********************************************************************************
*
* Summary:
*
* Parameters:
*  pData:    pointer to data buffer with response command.
*  Size:     number of bytes required to be transmitted.
*  Count:    actual size of data was transmitted.
*  TimeOut:  timeout value in tries of 10uS.
*
* Return:
*  Status of transmit operation.
*
* Global variables:
*
*******************************************************************************/
cystatus SCB_1_CyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut)
{
    cystatus status;

    #if(SCB_1_SCB_MODE_UNCFG_CONST_CFG)
        if(SCB_1_SCB_MODE_I2C_RUNTM_CFG)
        {
            status = SCB_1_I2CCyBtldrCommWrite(pData, size, count, timeOut);
        }
        else if(SCB_1_SCB_MODE_SPI_RUNTM_CFG)
        {
            status = SCB_1_SpiCyBtldrCommWrite(pData, size, count, timeOut);
        }
        else if(SCB_1_SCB_MODE_UART_RUNTM_CFG)
        {
            status = SCB_1_UartCyBtldrCommWrite(pData, size, count, timeOut);
        }
        else if(SCB_1_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            status = SCB_1_EzI2CCyBtldrCommWrite(pData, size, count, timeOut);
        }
        else if(SCB_1_SCB_MODE_EZSPI_RUNTM_CFG)
        {
            status = SCB_1_EzSpiCyBtldrCommWrite(pData, size, count, timeOut);
        }
        else
        {
            status = CYRET_INVALID_STATE; /* Unknown mode: return status */
        }
    #else

        #if(SCB_1_SCB_MODE_I2C_CONST_CFG)
            status = SCB_1_I2CCyBtldrCommWrite(pData, size, count, timeOut);

        #elif(SCB_1_SCB_MODE_SPI_CONST_CFG)
            status = SCB_1_SpiCyBtldrCommWrite(pData, size, count, timeOut);

        #elif(SCB_1_SCB_MODE_UART_CONST_CFG)
            status = SCB_1_UartCyBtldrCommWrite(pData, size, count, timeOut);

        #elif(SCB_1_SCB_MODE_EZI2C_CONST_CFG)
            status = SCB_1_EzI2CCyBtldrCommWrite(pData, size, count, timeOut);

        #else
           status = SCB_1_EzSpiCyBtldrCommWrite(pData, size, count, timeOut);

        #endif /* (SCB_1_SCB_MODE_I2C_CONST_CFG) */

    #endif /* (SCB_1_SCB_MODE_UNCFG_CONST_CFG) */

    return(status);
}


#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && ((CYDEV_BOOTLOADER_IO_COMP == CyBtldr_SCB_1) || \
                                                     (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_Custom_Interface)) */


/* [] END OF FILE */
