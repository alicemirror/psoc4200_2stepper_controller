/*******************************************************************************
* File Name: I2C_LCD_1_SCB.c
* Version 1.0
*
* Description:
*  This file provides the source code to the API for the SCB Component.
*
* Note:
*
*******************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "I2C_LCD_1_SCB_PVT.h"

#if(I2C_LCD_1_SCB_SCB_MODE_I2C_INC)
    #include "I2C_LCD_1_SCB_I2C_PVT.h"
#endif /* (I2C_LCD_1_SCB_SCB_MODE_I2C_INC) */

#if(I2C_LCD_1_SCB_SCB_MODE_SPI_INC || I2C_LCD_1_SCB_SCB_MODE_UART_INC)
    #include "I2C_LCD_1_SCB_SPI_UART_PVT.h"
#endif /* (I2C_LCD_1_SCB_SCB_MODE_SPI_INC || I2C_LCD_1_SCB_SCB_MODE_UART_INC) */

#if(I2C_LCD_1_SCB_SCB_MODE_EZBUF_I2C_INC || I2C_LCD_1_SCB_SCB_MODE_EZBUF_SPI_INC)
    #include "I2C_LCD_1_SCB_EZBUF_MODE_PVT.h"
#endif /* (I2C_LCD_1_SCB_SCB_MODE_EZBUF_I2C_INC || I2C_LCD_1_SCB_SCB_MODE_EZBUF_SPI_INC) */


/**********************************
*    Run Time Configuration Vars
**********************************/

/* Stores internal component configuration for unconfigured mode */
#if(I2C_LCD_1_SCB_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Common config vars */
    volatile uint8 I2C_LCD_1_SCB_scbMode = I2C_LCD_1_SCB_SCB_MODE_UNCONFIG;
    volatile uint8 I2C_LCD_1_SCB_scbEnableWake;

    /* I2C config vars */
    volatile uint8 I2C_LCD_1_SCB_mode;
    volatile uint8 I2C_LCD_1_SCB_acceptAddr;

    /* SPI/UART config vars */
    volatile uint8 * I2C_LCD_1_SCB_rxBuffer;
    volatile uint8   I2C_LCD_1_SCB_rxDataBits;
    volatile uint32  I2C_LCD_1_SCB_rxBufferSize;

    volatile uint8 * I2C_LCD_1_SCB_txBuffer;
    volatile uint8   I2C_LCD_1_SCB_txDataBits;
    volatile uint32  I2C_LCD_1_SCB_txBufferSize;

    /* EZI2C/EZSPI vars */
    volatile uint8 I2C_LCD_1_SCB_operationMode;
    volatile uint8 I2C_LCD_1_SCB_enableWaitStates;
    volatile uint8 I2C_LCD_1_SCB_wakeAction;

#endif /* (I2C_LCD_1_SCB_SCB_MODE_UNCONFIG_CONST_CFG) */


/**********************************
*     Common SCB Vars
**********************************/

uint8 I2C_LCD_1_SCB_initVar = 0u;
cyisraddress I2C_LCD_1_SCB_customIntrHandler = NULL;


/***************************************
*    Private Function Prototypes
***************************************/

static void I2C_LCD_1_SCB_ScbModeStop(void);


/*******************************************************************************
* Function Name: I2C_LCD_1_SCB_Init
********************************************************************************
*
* Summary:
*  Initializes SCB component to operate in one of selected configurations:
*  I2C, SPI, UART, EZI2C or EZSPI.
*  This function does not do any initialization when configuration is set to
*  Unconfigured SCB.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void I2C_LCD_1_SCB_Init(void)
{
    #if(I2C_LCD_1_SCB_SCB_MODE_UNCONFIG_CONST_CFG)
        if(I2C_LCD_1_SCB_SCB_MODE_UNCONFIG_RUNTM_CFG)
        {
            I2C_LCD_1_SCB_initVar = 0u; /* Clear init var */
        }
        else
        {
            /* Initialization was done before call */
        }

    #elif(I2C_LCD_1_SCB_SCB_MODE_I2C_CONST_CFG)
        I2C_LCD_1_SCB_I2CInit();

    #elif(I2C_LCD_1_SCB_SCB_MODE_SPI_CONST_CFG)
        I2C_LCD_1_SCB_SpiInit();

    #elif(I2C_LCD_1_SCB_SCB_MODE_UART_CONST_CFG)
        I2C_LCD_1_SCB_UartInit();

    #elif(I2C_LCD_1_SCB_SCB_MODE_EZBUF_I2C_CONST_CFG)
        I2C_LCD_1_SCB_EzBufI2CInit();

    #elif(I2C_LCD_1_SCB_SCB_MODE_EZBUF_SPI_CONST_CFG)
        I2C_LCD_1_SCB_EzBufSpiInit();

    #else

    #endif /* (I2C_LCD_1_SCB_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: I2C_LCD_1_SCB_Enable
********************************************************************************
*
* Summary:
*  Enables SCB component operation.
*  The SCB configuration should be not changed when the component is enabled.
*  Any configuration changes should be made after disabling the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void I2C_LCD_1_SCB_Enable(void)
{
    #if(I2C_LCD_1_SCB_SCB_MODE_UNCONFIG_CONST_CFG)
        if(!I2C_LCD_1_SCB_SCB_MODE_UNCONFIG_RUNTM_CFG)
        {
            /* Enable SCB block, only if already configured */
            I2C_LCD_1_SCB_CTRL_REG |= I2C_LCD_1_SCB_CTRL_ENABLED;
        }
    #else
        I2C_LCD_1_SCB_CTRL_REG |= I2C_LCD_1_SCB_CTRL_ENABLED; /* Enable SCB block */
    #endif /* (I2C_LCD_1_SCB_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: I2C_LCD_1_SCB_Start
********************************************************************************
*
* Summary:
*  Invokes SCB_Init() and SCB_Enable().
*  After this function call the component is enabled and ready for operation.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  I2C_LCD_1_SCB_initVar - used to check initial configuration, modified
*  on first function call.
*
*******************************************************************************/
void I2C_LCD_1_SCB_Start(void)
{
    if(0u == I2C_LCD_1_SCB_initVar)
    {
        I2C_LCD_1_SCB_initVar = 1u; /* Component was initialized */
        I2C_LCD_1_SCB_Init();       /* Initialize component      */
    }

    I2C_LCD_1_SCB_Enable();
}


/*******************************************************************************
* Function Name: I2C_LCD_1_SCB_Stop
********************************************************************************
*
* Summary:
*  Disables the SCB component.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void I2C_LCD_1_SCB_Stop(void)
{
    I2C_LCD_1_SCB_CTRL_REG &= (uint32) ~I2C_LCD_1_SCB_CTRL_ENABLED;  /* Disable SCB block */

    #if(I2C_LCD_1_SCB_SCB_IRQ_INTERNAL)
        I2C_LCD_1_SCB_SCB_IRQ_ClearPending(); /* Clear pending interrupt */
    #endif /* (I2C_LCD_1_SCB_SCB_IRQ_INTERNAL) */

    I2C_LCD_1_SCB_ScbModeStop(); /* Calls scbMode specific Stop function */
}


/*******************************************************************************
* Function Name: I2C_LCD_1_SCB_SetCustomInterruptHandler
********************************************************************************
*
* Summary:
*  Registers a function to be called by the internal interrupt handler.
*  First the function that is registered is called, then the internal interrupt
*  handler performs any operations such as software buffer management functions
*  before the interrupt returns.  It is user's responsibility to not break the
*  software buffer operations. Only one custom handler is supported, which is
*  the function provided by the most recent call.
*  At initialization time no custom handler is registered.
*
* Parameters:
*  func: Pointer to the function to register.
*        The value NULL indicates to remove the current custom interrupt
*        handler.
*
* Return:
*  None
*
*******************************************************************************/
void I2C_LCD_1_SCB_SetCustomInterruptHandler(cyisraddress func)
{
    I2C_LCD_1_SCB_customIntrHandler = func; /* Register interrupt handler */
}


/*******************************************************************************
* Function Name: I2C_LCD_1_SCB_ScbModeStop
********************************************************************************
*
* Summary:
*  Calls Stop function for specific operation mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
static void I2C_LCD_1_SCB_ScbModeStop(void)
{
    #if(I2C_LCD_1_SCB_SCB_MODE_UNCONFIG_CONST_CFG)
        if(I2C_LCD_1_SCB_SCB_MODE_I2C_RUNTM_CFG)
        {
            I2C_LCD_1_SCB_I2CStop();
        }
    #elif(I2C_LCD_1_SCB_SCB_MODE_I2C_CONST_CFG)
        I2C_LCD_1_SCB_I2CStop();
    #else

    #endif /* (I2C_LCD_1_SCB_SCB_MODE_UNCONFIG_CONST_CFG) */
}



#if(I2C_LCD_1_SCB_SCB_MODE_UNCONFIG_CONST_CFG)
    /*******************************************************************************
    * Function Name: I2C_LCD_1_SCB_SetPins
    ********************************************************************************
    *
    * Summary:
    *  Sets pins settings accordingly to selected operation mode.
    *  Only available in Unconfigured operation mode. The mode specific
    *  initialization function calls it.
    *  Pins configuration is set by PSoC Creator when specific mode of operation
    *  selected in design time.
    *
    * Parameters:
    *  mode:      Mode of SCB operation.
    *  subMode:   Submode of SCB operation. It is only required for SPI and UART
    *             modes.
    *  UartTxRx:  Direction for UART.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void I2C_LCD_1_SCB_SetPins(uint32 mode, uint32 subMode, uint32 UartTxRx)
    {
        uint32 hsiomSel[I2C_LCD_1_SCB_SCB_PINS_NUMBER];
        uint32 pinsDm  [I2C_LCD_1_SCB_SCB_PINS_NUMBER];
        uint32 i;

        /* Make all unused */
        for(i = 0u; i < I2C_LCD_1_SCB_SCB_PINS_NUMBER; i++)
        {
            hsiomSel[i] = I2C_LCD_1_SCB_HSIOM_DEF_SEL;
            pinsDm[i]   = I2C_LCD_1_SCB_PIN_DM_ALG_HIZ;
        }

        /* Choice the Dm and HSIOM */
        if((I2C_LCD_1_SCB_SCB_MODE_I2C       == mode) ||
           (I2C_LCD_1_SCB_SCB_MODE_EZBUF_I2C == mode))
        {
            hsiomSel[I2C_LCD_1_SCB_MOSI_SCL_RX_PIN_INDEX] = I2C_LCD_1_SCB_HSIOM_I2C_SEL;
            hsiomSel[I2C_LCD_1_SCB_MISO_SDA_TX_PIN_INDEX] = I2C_LCD_1_SCB_HSIOM_I2C_SEL;

            pinsDm[I2C_LCD_1_SCB_MOSI_SCL_RX_PIN_INDEX] = I2C_LCD_1_SCB_PIN_DM_OD_LO;
            pinsDm[I2C_LCD_1_SCB_MISO_SDA_TX_PIN_INDEX] = I2C_LCD_1_SCB_PIN_DM_OD_LO;
        }
        else if((I2C_LCD_1_SCB_SCB_MODE_SPI       == mode) ||
                (I2C_LCD_1_SCB_SCB_MODE_EZBUF_SPI == mode))
        {
            hsiomSel[I2C_LCD_1_SCB_MOSI_SCL_RX_PIN_INDEX] = I2C_LCD_1_SCB_HSIOM_SPI_SEL;
            hsiomSel[I2C_LCD_1_SCB_MISO_SDA_TX_PIN_INDEX] = I2C_LCD_1_SCB_HSIOM_SPI_SEL;
            hsiomSel[I2C_LCD_1_SCB_SCLK_PIN_INDEX]        = I2C_LCD_1_SCB_HSIOM_SPI_SEL;

            if(I2C_LCD_1_SCB_SPI_SLAVE == subMode)
            {
                /* Slave */
                pinsDm[I2C_LCD_1_SCB_MOSI_SCL_RX_PIN_INDEX] = I2C_LCD_1_SCB_PIN_DM_DIG_HIZ;
                pinsDm[I2C_LCD_1_SCB_MISO_SDA_TX_PIN_INDEX] = I2C_LCD_1_SCB_PIN_DM_STRONG;
                pinsDm[I2C_LCD_1_SCB_SCLK_PIN_INDEX]        = I2C_LCD_1_SCB_PIN_DM_DIG_HIZ;

                #if(I2C_LCD_1_SCB_SS0_PIN)
                    /* Only SS0 is valid choice for Slave */
                    hsiomSel[I2C_LCD_1_SCB_SS0_PIN_INDEX] = I2C_LCD_1_SCB_HSIOM_SPI_SEL;
                    pinsDm  [I2C_LCD_1_SCB_SS0_PIN_INDEX] = I2C_LCD_1_SCB_PIN_DM_DIG_HIZ;
                #endif /* (I2C_LCD_1_SCB_SS1_PIN) */
            }
            else /* (Master) */
            {
                pinsDm[I2C_LCD_1_SCB_MOSI_SCL_RX_PIN_INDEX] = I2C_LCD_1_SCB_PIN_DM_STRONG;
                pinsDm[I2C_LCD_1_SCB_MISO_SDA_TX_PIN_INDEX] = I2C_LCD_1_SCB_PIN_DM_DIG_HIZ;
                pinsDm[I2C_LCD_1_SCB_SCLK_PIN_INDEX]        = I2C_LCD_1_SCB_PIN_DM_STRONG;

                #if(I2C_LCD_1_SCB_SS0_PIN)
                    hsiomSel[I2C_LCD_1_SCB_SS0_PIN_INDEX] = I2C_LCD_1_SCB_HSIOM_SPI_SEL;
                    pinsDm  [I2C_LCD_1_SCB_SS0_PIN_INDEX] = I2C_LCD_1_SCB_PIN_DM_STRONG;
                #endif /* (I2C_LCD_1_SCB_SS0_PIN) */

                #if(I2C_LCD_1_SCB_SS1_PIN)
                    hsiomSel[I2C_LCD_1_SCB_SS1_PIN_INDEX] = I2C_LCD_1_SCB_HSIOM_SPI_SEL;
                    pinsDm  [I2C_LCD_1_SCB_SS1_PIN_INDEX] = I2C_LCD_1_SCB_PIN_DM_STRONG;
                #endif /* (I2C_LCD_1_SCB_SS1_PIN) */

                #if(I2C_LCD_1_SCB_SS2_PIN)
                    hsiomSel[I2C_LCD_1_SCB_SS2_PIN_INDEX] = I2C_LCD_1_SCB_HSIOM_SPI_SEL;
                    pinsDm  [I2C_LCD_1_SCB_SS2_PIN_INDEX] = I2C_LCD_1_SCB_PIN_DM_STRONG;
                #endif /* (I2C_LCD_1_SCB_SS2_PIN) */

                #if(I2C_LCD_1_SCB_SS3_PIN)
                    hsiomSel[I2C_LCD_1_SCB_SS3_PIN_INDEX] = I2C_LCD_1_SCB_HSIOM_SPI_SEL;
                    pinsDm  [I2C_LCD_1_SCB_SS3_PIN_INDEX] = I2C_LCD_1_SCB_PIN_DM_STRONG;
                #endif /* (I2C_LCD_1_SCB_SS2_PIN) */
            }
        }
        else /* UART */
        {
            if(I2C_LCD_1_SCB_UART_MODE_SMARTCARD == subMode)
            {
                /* SmartCard */
                hsiomSel[I2C_LCD_1_SCB_MISO_SDA_TX_PIN_INDEX] = I2C_LCD_1_SCB_HSIOM_UART_SEL;
                pinsDm  [I2C_LCD_1_SCB_MISO_SDA_TX_PIN_INDEX] = I2C_LCD_1_SCB_PIN_DM_OD_LO;
            }
            else /* Standard or IrDA */
            {
                if(0u != (I2C_LCD_1_SCB_UART_RX & UartTxRx))
                {
                    hsiomSel[I2C_LCD_1_SCB_MOSI_SCL_RX_PIN_INDEX] = I2C_LCD_1_SCB_HSIOM_UART_SEL;
                    pinsDm  [I2C_LCD_1_SCB_MOSI_SCL_RX_PIN_INDEX] = I2C_LCD_1_SCB_PIN_DM_DIG_HIZ;
                }

                if(0u != (I2C_LCD_1_SCB_UART_TX & UartTxRx))
                {
                    hsiomSel[I2C_LCD_1_SCB_MISO_SDA_TX_PIN_INDEX] = I2C_LCD_1_SCB_HSIOM_UART_SEL;
                    pinsDm  [I2C_LCD_1_SCB_MISO_SDA_TX_PIN_INDEX] = I2C_LCD_1_SCB_PIN_DM_STRONG;
                }
            }
        }

        /* Condfigure pins: set HSIOM and DM */
        /* Condfigure pins: DR registers configuration remains unchanged for cyfitter_cfg() */

        #if(I2C_LCD_1_SCB_MOSI_SCL_RX_PIN)
            I2C_LCD_1_SCB_SET_HSIOM_SEL(I2C_LCD_1_SCB_MOSI_SCL_RX_HSIOM_REG,
                                           I2C_LCD_1_SCB_MOSI_SCL_RX_HSIOM_MASK,
                                           I2C_LCD_1_SCB_MOSI_SCL_RX_HSIOM_POS,
                                           hsiomSel[I2C_LCD_1_SCB_MOSI_SCL_RX_PIN_INDEX]);
        #endif /* (I2C_LCD_1_SCB_MOSI_SCL_RX_PIN) */

        #if(I2C_LCD_1_SCB_MOSI_SCL_RX_WAKE_PIN)
            I2C_LCD_1_SCB_SET_HSIOM_SEL(I2C_LCD_1_SCB_MOSI_SCL_RX_WAKE_HSIOM_REG,
                                           I2C_LCD_1_SCB_MOSI_SCL_RX_WAKE_HSIOM_MASK,
                                           I2C_LCD_1_SCB_MOSI_SCL_RX_WAKE_HSIOM_POS,
                                           hsiomSel[I2C_LCD_1_SCB_MOSI_SCL_RX_WAKE_PIN_INDEX]);
        #endif /* (I2C_LCD_1_SCB_MOSI_SCL_RX_WAKE_PIN) */

        #if(I2C_LCD_1_SCB_MISO_SDA_TX_PIN)
            I2C_LCD_1_SCB_SET_HSIOM_SEL(I2C_LCD_1_SCB_MISO_SDA_TX_HSIOM_REG,
                                           I2C_LCD_1_SCB_MISO_SDA_TX_HSIOM_MASK,
                                           I2C_LCD_1_SCB_MISO_SDA_TX_HSIOM_POS,
                                           hsiomSel[I2C_LCD_1_SCB_MISO_SDA_TX_PIN_INDEX]);
        #endif /* (I2C_LCD_1_SCB_MOSI_SCL_RX_PIN) */

        #if(I2C_LCD_1_SCB_SCLK_PIN)
            I2C_LCD_1_SCB_SET_HSIOM_SEL(I2C_LCD_1_SCB_SCLK_HSIOM_REG, I2C_LCD_1_SCB_SCLK_HSIOM_MASK,
                                           I2C_LCD_1_SCB_SCLK_HSIOM_POS, hsiomSel[I2C_LCD_1_SCB_SCLK_PIN_INDEX]);
        #endif /* (I2C_LCD_1_SCB_SCLK_PIN) */

        #if(I2C_LCD_1_SCB_SS0_PIN)
            I2C_LCD_1_SCB_SET_HSIOM_SEL(I2C_LCD_1_SCB_SS0_HSIOM_REG, I2C_LCD_1_SCB_SS0_HSIOM_MASK,
                                           I2C_LCD_1_SCB_SS0_HSIOM_POS, hsiomSel[I2C_LCD_1_SCB_SS0_PIN_INDEX]);
        #endif /* (I2C_LCD_1_SCB_SS1_PIN) */

        #if(I2C_LCD_1_SCB_SS1_PIN)
            I2C_LCD_1_SCB_SET_HSIOM_SEL(I2C_LCD_1_SCB_SS1_HSIOM_REG, I2C_LCD_1_SCB_SS1_HSIOM_MASK,
                                           I2C_LCD_1_SCB_SS1_HSIOM_POS, hsiomSel[I2C_LCD_1_SCB_SS1_PIN_INDEX]);
        #endif /* (I2C_LCD_1_SCB_SS1_PIN) */

        #if(I2C_LCD_1_SCB_SS2_PIN)
            I2C_LCD_1_SCB_SET_HSIOM_SEL(I2C_LCD_1_SCB_SS2_HSIOM_REG, I2C_LCD_1_SCB_SS2_HSIOM_MASK,
                                           I2C_LCD_1_SCB_SS2_HSIOM_POS, hsiomSel[I2C_LCD_1_SCB_SS2_PIN_INDEX]);
        #endif /* (I2C_LCD_1_SCB_SS2_PIN) */

        #if(I2C_LCD_1_SCB_SS3_PIN)
            I2C_LCD_1_SCB_SET_HSIOM_SEL(I2C_LCD_1_SCB_SS3_HSIOM_REG,  I2C_LCD_1_SCB_SS3_HSIOM_MASK,
                                           I2C_LCD_1_SCB_SS3_HSIOM_POS, hsiomSel[I2C_LCD_1_SCB_SS3_PIN_INDEX]);
        #endif /* (I2C_LCD_1_SCB_SS3_PIN) */



        #if(I2C_LCD_1_SCB_MOSI_SCL_RX_PIN)
            I2C_LCD_1_SCB_spi_mosi_i2c_scl_uart_rx_SetDriveMode((uint8)
                                                                   pinsDm[I2C_LCD_1_SCB_MOSI_SCL_RX_PIN_INDEX]);
        #endif /* (I2C_LCD_1_SCB_MOSI_SCL_RX_PIN) */

        #if(I2C_LCD_1_SCB_MOSI_SCL_RX_WAKE_PIN)
        I2C_LCD_1_SCB_spi_mosi_i2c_scl_uart_rx_wake_SetDriveMode((uint8)
                                                                   pinsDm[I2C_LCD_1_SCB_MOSI_SCL_RX_WAKE_PIN_INDEX]);

        /* Set interrupt on rising edge */
        I2C_LCD_1_SCB_SET_INCFG_TYPE(I2C_LCD_1_SCB_MOSI_SCL_RX_WAKE_INTCFG_REG,
                                        I2C_LCD_1_SCB_MOSI_SCL_RX_WAKE_INTCFG_TYPE_MASK,
                                        I2C_LCD_1_SCB_MOSI_SCL_RX_WAKE_INTCFG_TYPE_POS,
                                        I2C_LCD_1_SCB_INTCFG_TYPE_FALLING_EDGE);

        #endif /* (I2C_LCD_1_SCB_MOSI_SCL_RX_WAKE_PIN) */

        #if(I2C_LCD_1_SCB_MISO_SDA_TX_PIN)
            I2C_LCD_1_SCB_spi_miso_i2c_sda_uart_tx_SetDriveMode((uint8)
                                                                        pinsDm[I2C_LCD_1_SCB_MISO_SDA_TX_PIN_INDEX]);
        #endif /* (I2C_LCD_1_SCB_MOSI_SCL_RX_PIN) */

        #if(I2C_LCD_1_SCB_SCLK_PIN)
            I2C_LCD_1_SCB_spi_clk_SetDriveMode((uint8) pinsDm[I2C_LCD_1_SCB_SCLK_PIN_INDEX]);
        #endif /* (I2C_LCD_1_SCB_SCLK_PIN) */

        #if(I2C_LCD_1_SCB_SS0_PIN)
            I2C_LCD_1_SCB_spi_ss0_SetDriveMode((uint8) pinsDm[I2C_LCD_1_SCB_SS0_PIN_INDEX]);
        #endif /* (I2C_LCD_1_SCB_SS0_PIN) */

        #if(I2C_LCD_1_SCB_SS1_PIN)
            I2C_LCD_1_SCB_spi_ss1_SetDriveMode((uint8) pinsDm[I2C_LCD_1_SCB_SS1_PIN_INDEX]);
        #endif /* (I2C_LCD_1_SCB_SS1_PIN) */

        #if(I2C_LCD_1_SCB_SS2_PIN)
            I2C_LCD_1_SCB_spi_ss2_SetDriveMode((uint8) pinsDm[I2C_LCD_1_SCB_SS2_PIN_INDEX]);
        #endif /* (I2C_LCD_1_SCB_SS2_PIN) */

        #if(I2C_LCD_1_SCB_SS3_PIN)
            I2C_LCD_1_SCB_spi_ss3_SetDriveMode((uint8) pinsDm[I2C_LCD_1_SCB_SS3_PIN_INDEX]);
        #endif /* (I2C_LCD_1_SCB_SS3_PIN) */
    }

#endif /* (I2C_LCD_1_SCB_SCB_MODE_UNCONFIG_CONST_CFG) */


/* [] END OF FILE */
