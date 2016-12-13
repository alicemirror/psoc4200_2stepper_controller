/*******************************************************************************
* File Name: SCB_1.c
* Version 1.0
*
* Description:
*
*
*******************************************************************************
* Copyright 2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "SCB_1.h"

/**********************************
*      System variables
**********************************/

uint8 SCB_1_initVar = 0u;

#if(SCB_1_SCB_MODE_UNCFG_CONST_CFG)
    /* Stores internal component configuration for unconfigured mode */
    volatile uint32 SCB_1_scbMode;
    volatile void * SCB_1_scbCfg = NULL;

#endif /* (SCB_1_SCB_MODE_UNCFG_CONST_CFG) */

void (* SCB_1_customIntrHandler) (void) = NULL;


/*******************************************************************************
* Function Name: SCB_1_Init
********************************************************************************
*
* Summary:
*
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void SCB_1_Init(void)
{
    #if(SCB_1_SCB_MODE_I2C_CONST_CFG)
        SCB_1_I2CInit((SCB_1_I2C_INIT_STRUCT *) &SCB_1_configI2C);

    #elif(SCB_1_SCB_MODE_SPI_CONST_CFG)
        SCB_1_SpiInit((SCB_1_SPI_INIT_STRUCT *) &SCB_1_configSpi);

    #elif(SCB_1_SCB_MODE_UART_CONST_CFG)
        SCB_1_UartInit((SCB_1_UART_INIT_STRUCT *) &SCB_1_configUart);

    #elif(SCB_1_SCB_MODE_EZI2C_CONST_CFG)
        SCB_1_EzI2CInit((SCB_1_EZI2C_INIT_STRUCT *) &SCB_1_configEzI2C);

    #elif(SCB_1_SCB_MODE_EZSPI_CONST_CFG)
        SCB_1_EzSpiInit((SCB_1_EZSPI_INIT_STRUCT *) &SCB_1_configEzSpi);

    #else
        /* The mode to enable is unknown */
        SCB_1_scbMode = SCB_1_SCB_MODE_UNCONFIG;
        SCB_1_scbCfg  = NULL;

    #endif /* (SCB_1_SCB_MODE_I2C_CONST_CFG) */
}


/*******************************************************************************
* Function Name: SCB_1_Enable
********************************************************************************
*
* Summary:
*
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void SCB_1_Enable(void)
{
    SCB_1_CTRL_REG |= SCB_1_CTRL_ENABLED;  /* Enable SCB block */
}


/*******************************************************************************
* Function Name: SCB_1_Start
********************************************************************************
*
* Summary:
*
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  SCB_1_initVar - used to check initial configuration, modified
*  on first function call.
*
*******************************************************************************/
void SCB_1_Start(void)
{
    if(0u == SCB_1_initVar)
    {
        SCB_1_Init();       /* Initialize component */
        SCB_1_initVar = 1u; /* SCB was initialized  */
    }

    SCB_1_Enable();
}


/*******************************************************************************
* Function Name: SCB_1_Stop
********************************************************************************
*
* Summary:
*
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void SCB_1_Stop(void)
{
    SCB_1_CTRL_REG &= ~SCB_1_CTRL_ENABLED;  /* Disable SCB block */
}


/*******************************************************************************
* Function Name: SCB_1_SetCustomInterruptHandler
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
void SCB_1_SetCustomInterruptHandler(void (*func) (void))
{
    SCB_1_customIntrHandler = func;  /* Register interrupt handler */
}


#if(SCB_1_SCB_MODE_UNCFG_CONST_CFG)
    /*******************************************************************************
    * Function Name: SCB_1_SetPins
    ********************************************************************************
    *
    * Summary:
    *
    * Parameters:
    *
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void SCB_1_SetPins(uint32 mode, uint32 subMode, uint32 spiSsUartTxRx)
    {
        uint32 hsiomSel;
        uint8 pinsDm[SCB_1_SCB_PINS_NUMBER];
        uint32 i;

        /* Make all unused */
        for(i=0u; i<SCB_1_SCB_PINS_NUMBER; i++)
        {
            pinsDm[i] = PIN_DM_ALG_HIZ;
        }

        /* Choice the Dm and HSIOM */
        if((SCB_1_SCB_MODE_I2C   == mode) ||
           (SCB_1_SCB_MODE_EZI2C == mode))
        {
            hsiomSel  = SCB_1_HSIOM_I2C_SEL;

            pinsDm[SCB_1_MOSI_SCL_RX_PIN_INDEX] = ((uint8) PIN_DM_OD_LO);
            pinsDm[SCB_1_MISO_SDA_TX_PIN_INDEX] = ((uint8) PIN_DM_OD_LO);
        }
        else if((SCB_1_SCB_MODE_SPI   == mode) ||
                (SCB_1_SCB_MODE_EZSPI == mode))
        {
            hsiomSel =  SCB_1_HSIOM_SPI_SEL;

            if(SCB_1_SPI_SLAVE == subMode)
            {
                pinsDm[SCB_1_MOSI_SCL_RX_PIN_INDEX] = ((uint8) PIN_DM_DIG_HIZ);
                pinsDm[SCB_1_MISO_SDA_TX_PIN_INDEX] = ((uint8) PIN_DM_STRONG);
                pinsDm[SCB_1_SCLK_PIN_INDEX]        = ((uint8) PIN_DM_DIG_HIZ);
                pinsDm[SCB_1_SS0_PIN_INDEX]         = ((uint8) PIN_DM_DIG_HIZ);
            }
            else /* (Master) */
            {
                pinsDm[SCB_1_MOSI_SCL_RX_PIN_INDEX] = ((uint8) PIN_DM_STRONG);
                pinsDm[SCB_1_MISO_SDA_TX_PIN_INDEX] = ((uint8) PIN_DM_DIG_HIZ);
                pinsDm[SCB_1_SCLK_PIN_INDEX]        = ((uint8) PIN_DM_STRONG);

                if(0ul != spiSsUartTxRx)
                {
                    pinsDm[SCB_1_SS0_PIN_INDEX] = ((uint8) PIN_DM_STRONG);

                    if(spiSsUartTxRx > 1ul)
                    {
                        pinsDm[SCB_1_SS1_PIN_INDEX] = ((uint8) PIN_DM_STRONG);
                    }

                    if(spiSsUartTxRx > 2ul)
                    {
                        pinsDm[SCB_1_SS2_PIN_INDEX] = ((uint8) PIN_DM_STRONG);
                    }

                    if(spiSsUartTxRx > 3ul)
                    {
                        pinsDm[SCB_1_SS3_PIN_INDEX] = ((uint8) PIN_DM_STRONG);
                    }
                }
            }
        }
        else /* UART */
        {
            hsiomSel =  SCB_1_HSIOM_UART_SEL;

            if(SCB_1_UART_MODE_SMARTCARD == subMode)
            {
                pinsDm[SCB_1_MISO_SDA_TX_PIN_INDEX] = ((uint8) PIN_DM_OD_LO);
            }
            else
            {
                if(0u != (SCB_1_UART_RX & spiSsUartTxRx))
                {
                    pinsDm[SCB_1_MOSI_SCL_RX_PIN_INDEX] = ((uint8) PIN_DM_DIG_HIZ);
                }

                if(0u != (SCB_1_UART_TX & spiSsUartTxRx))
                {
                    pinsDm[SCB_1_MOSI_SCL_RX_PIN_INDEX] = ((uint8) PIN_DM_STRONG);
                }
            }
        }

        /* Condfigure pins: set HSIOM and DM */

        #if(SCB_1_MOSI_SCL_RX_PIN)
            SCB_1_SET_HSIOM_SEL(SCB_1_MOSI_SCL_RX_HSIOM_REG, SCB_1_MOSI_SCL_RX_HSIOM__MASK,
                                           SCB_1_MOSI_SCL_RX_HSIOM__POS, hsiomSel);
        #endif /* (SCB_1_MOSI_SCL_RX_PIN) */

        #if(SCB_1_MISO_SDA_TX_PIN)
            SCB_1_SET_HSIOM_SEL(SCB_1_MISO_SDA_TX_HSIOM_REG, SCB_1_MISO_SDA_TX_HSIOM__MASK,
                                           SCB_1_MISO_SDA_TX_HSIOM__POS, hsiomSel);
        #endif /* (SCB_1_MOSI_SCL_RX_PIN) */

        #if(SCB_1_SCLK_PIN)
            SCB_1_SET_HSIOM_SEL(SCB_1_SCLK_HSIOM_REG, SCB_1_SCLK_HSIOM__MASK,
                                           SCB_1_SCLK_HSIOM__POS, hsiomSel);
        #endif /* (SCB_1_SCLK_PIN) */

        #if(SCB_1_SS0_PIN)
            SCB_1_SET_HSIOM_SEL(SCB_1_SS0_HSIOM_REG, SCB_1_SS0_HSIOM__MASK,
                                           SCB_1_SS0_HSIOM__POS, hsiomSel);
        #endif /* (SCB_1_SS1_PIN) */

        #if(SCB_1_SS1_PIN)
            SCB_1_SET_HSIOM_SEL(SCB_1_SS1_HSIOM_REG, SCB_1_SS1_HSIOM__MASK,
                                           SCB_1_SS1_HSIOM__POS, hsiomSel);
        #endif /* (SCB_1_SS1_PIN) */

        #if(SCB_1_SS2_PIN)
            SCB_1_SET_HSIOM_SEL(SCB_1_SS2_HSIOM_REG, SCB_1_SS2_HSIOM__MASK,
                                           SCB_1_SS2_HSIOM__POS, hsiomSel);
        #endif /* (SCB_1_SS2_PIN) */

        #if(SCB_1_SS3_PIN)
            SCB_1_SET_HSIOM_SEL(SCB_1_SS3_HSIOM_REG,  SCB_1_SS3_HSIOM__MASK,
                                           SCB_1_SS3_HSIOM__POS, hsiomSel);
        #endif /* (SCB_1_SS3_PIN) */


        /******** Set DM ********/
        #if(SCB_1_MOSI_SCL_RX_WAKE_PIN)
            SCB_1_spi_mosi_i2c_scl_uart_rx_wake_SetDriveMode(pinsDm[SCB_1_MOSI_SCL_RX_PIN_WAKE_INDEX]);

            /* Set interrupt on rising edge */
            SCB_1_SET_INCFG_TYPE(SCB_1_MOSI_SCL_RX_WAKE_INTCFG_REG,
                                            SCB_1_MOSI_SCL_RX_WAKE_INTCFG_TYPE__MASK,
                                            SCB_1_MOSI_SCL_RX_WAKE_INTCFG_TYPE__POS,
                                            SCB_1_INTCFG_TYPE_RASING_EDGE);

        #endif /* (SCB_1_MOSI_SCL_RX_PIN) */

        #if(SCB_1_MOSI_SCL_RX_PIN)
            SCB_1_spi_mosi_i2c_scl_uart_rx_SetDriveMode(pinsDm[SCB_1_MOSI_SCL_RX_PIN_INDEX]);
        #endif /* (SCB_1_MOSI_SCL_RX_PIN) */

        #if(SCB_1_MISO_SDA_TX_PIN)
            SCB_1_spi_miso_i2c_sda_uart_tx_SetDriveMode(pinsDm[SCB_1_MISO_SDA_TX_PIN_INDEX]);
        #endif /* (SCB_1_MOSI_SCL_RX_PIN) */


        #if(SCB_1_SCLK_PIN)
            SCB_1_spi_clk_SetDriveMode(pinsDm[SCB_1_SCLK_PIN_INDEX]);
        #endif /* (SCB_1_SCLK_PIN) */

        #if(SCB_1_SS0_PIN)
            SCB_1_spi_ss0_SetDriveMode(pinsDm[SCB_1_SS0_PIN_INDEX]);
        #endif /* (SCB_1_SS0_PIN) */

        #if(SCB_1_SS1_PIN)
            SCB_1_spi_ss1_SetDriveMode(pinsDm[SCB_1_SS1_PIN_INDEX]);
        #endif /* (SCB_1_SS1_PIN) */

        #if(SCB_1_SS2_PIN)
            SCB_1_spi_ss2_SetDriveMode(pinsDm[SCB_1_SS2_PIN_INDEX]);
        #endif /* (SCB_1_SS2_PIN) */

        #if(SCB_1_SS3_PIN)
            SCB_1_spi_ss3_SetDriveMode(pinsDm[SCB_1_SS3_PIN_INDEX]);
        #endif /* (SCB_1_SS3_PIN) */
    }

#endif /* (SCB_1_SCB_MODE_UNCFG_CONST_CFG) */


/* [] END OF FILE */
