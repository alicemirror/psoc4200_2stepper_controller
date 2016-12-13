/***************************************************************************//**
* \file Comm.c
* \version 3.20
*
* \brief
*  This file provides the source code to the API for the SCB Component.
*
* Note:
*
*******************************************************************************
* \copyright
* Copyright 2013-2016, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "Comm_PVT.h"

#if (Comm_SCB_MODE_I2C_INC)
    #include "Comm_I2C_PVT.h"
#endif /* (Comm_SCB_MODE_I2C_INC) */

#if (Comm_SCB_MODE_EZI2C_INC)
    #include "Comm_EZI2C_PVT.h"
#endif /* (Comm_SCB_MODE_EZI2C_INC) */

#if (Comm_SCB_MODE_SPI_INC || Comm_SCB_MODE_UART_INC)
    #include "Comm_SPI_UART_PVT.h"
#endif /* (Comm_SCB_MODE_SPI_INC || Comm_SCB_MODE_UART_INC) */


/***************************************
*    Run Time Configuration Vars
***************************************/

/* Stores internal component configuration for Unconfigured mode */
#if (Comm_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Common configuration variables */
    uint8 Comm_scbMode = Comm_SCB_MODE_UNCONFIG;
    uint8 Comm_scbEnableWake;
    uint8 Comm_scbEnableIntr;

    /* I2C configuration variables */
    uint8 Comm_mode;
    uint8 Comm_acceptAddr;

    /* SPI/UART configuration variables */
    volatile uint8 * Comm_rxBuffer;
    uint8  Comm_rxDataBits;
    uint32 Comm_rxBufferSize;

    volatile uint8 * Comm_txBuffer;
    uint8  Comm_txDataBits;
    uint32 Comm_txBufferSize;

    /* EZI2C configuration variables */
    uint8 Comm_numberOfAddr;
    uint8 Comm_subAddrSize;
#endif /* (Comm_SCB_MODE_UNCONFIG_CONST_CFG) */


/***************************************
*     Common SCB Vars
***************************************/
/**
* \addtogroup group_general
* \{
*/

/** Comm_initVar indicates whether the Comm 
*  component has been initialized. The variable is initialized to 0 
*  and set to 1 the first time SCB_Start() is called. This allows 
*  the component to restart without reinitialization after the first 
*  call to the Comm_Start() routine.
*
*  If re-initialization of the component is required, then the 
*  Comm_Init() function can be called before the 
*  Comm_Start() or Comm_Enable() function.
*/
uint8 Comm_initVar = 0u;


#if (! (Comm_SCB_MODE_I2C_CONST_CFG || \
        Comm_SCB_MODE_EZI2C_CONST_CFG))
    /** This global variable stores TX interrupt sources after 
    * Comm_Stop() is called. Only these TX interrupt sources 
    * will be restored on a subsequent Comm_Enable() call.
    */
    uint16 Comm_IntrTxMask = 0u;
#endif /* (! (Comm_SCB_MODE_I2C_CONST_CFG || \
              Comm_SCB_MODE_EZI2C_CONST_CFG)) */
/** \} globals */

#if (Comm_SCB_IRQ_INTERNAL)
#if !defined (CY_REMOVE_Comm_CUSTOM_INTR_HANDLER)
    void (*Comm_customIntrHandler)(void) = NULL;
#endif /* !defined (CY_REMOVE_Comm_CUSTOM_INTR_HANDLER) */
#endif /* (Comm_SCB_IRQ_INTERNAL) */


/***************************************
*    Private Function Prototypes
***************************************/

static void Comm_ScbEnableIntr(void);
static void Comm_ScbModeStop(void);
static void Comm_ScbModePostEnable(void);


/*******************************************************************************
* Function Name: Comm_Init
****************************************************************************//**
*
*  Initializes the Comm component to operate in one of the selected
*  configurations: I2C, SPI, UART or EZI2C.
*  When the configuration is set to "Unconfigured SCB", this function does
*  not do any initialization. Use mode-specific initialization APIs instead:
*  Comm_I2CInit, Comm_SpiInit, 
*  Comm_UartInit or Comm_EzI2CInit.
*
*******************************************************************************/
void Comm_Init(void)
{
#if (Comm_SCB_MODE_UNCONFIG_CONST_CFG)
    if (Comm_SCB_MODE_UNCONFIG_RUNTM_CFG)
    {
        Comm_initVar = 0u;
    }
    else
    {
        /* Initialization was done before this function call */
    }

#elif (Comm_SCB_MODE_I2C_CONST_CFG)
    Comm_I2CInit();

#elif (Comm_SCB_MODE_SPI_CONST_CFG)
    Comm_SpiInit();

#elif (Comm_SCB_MODE_UART_CONST_CFG)
    Comm_UartInit();

#elif (Comm_SCB_MODE_EZI2C_CONST_CFG)
    Comm_EzI2CInit();

#endif /* (Comm_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: Comm_Enable
****************************************************************************//**
*
*  Enables Comm component operation: activates the hardware and 
*  internal interrupt. It also restores TX interrupt sources disabled after the 
*  Comm_Stop() function was called (note that level-triggered TX 
*  interrupt sources remain disabled to not cause code lock-up).
*  For I2C and EZI2C modes the interrupt is internal and mandatory for 
*  operation. For SPI and UART modes the interrupt can be configured as none, 
*  internal or external.
*  The Comm configuration should be not changed when the component
*  is enabled. Any configuration changes should be made after disabling the 
*  component.
*  When configuration is set to “Unconfigured Comm”, the component 
*  must first be initialized to operate in one of the following configurations: 
*  I2C, SPI, UART or EZ I2C, using the mode-specific initialization API. 
*  Otherwise this function does not enable the component.
*
*******************************************************************************/
void Comm_Enable(void)
{
#if (Comm_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Enable SCB block, only if it is already configured */
    if (!Comm_SCB_MODE_UNCONFIG_RUNTM_CFG)
    {
        Comm_CTRL_REG |= Comm_CTRL_ENABLED;

        Comm_ScbEnableIntr();

        /* Call PostEnable function specific to current operation mode */
        Comm_ScbModePostEnable();
    }
#else
    Comm_CTRL_REG |= Comm_CTRL_ENABLED;

    Comm_ScbEnableIntr();

    /* Call PostEnable function specific to current operation mode */
    Comm_ScbModePostEnable();
#endif /* (Comm_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: Comm_Start
****************************************************************************//**
*
*  Invokes Comm_Init() and Comm_Enable().
*  After this function call, the component is enabled and ready for operation.
*  When configuration is set to "Unconfigured SCB", the component must first be
*  initialized to operate in one of the following configurations: I2C, SPI, UART
*  or EZI2C. Otherwise this function does not enable the component.
*
* \globalvars
*  Comm_initVar - used to check initial configuration, modified
*  on first function call.
*
*******************************************************************************/
void Comm_Start(void)
{
    if (0u == Comm_initVar)
    {
        Comm_Init();
        Comm_initVar = 1u; /* Component was initialized */
    }

    Comm_Enable();
}


/*******************************************************************************
* Function Name: Comm_Stop
****************************************************************************//**
*
*  Disables the Comm component: disable the hardware and internal 
*  interrupt. It also disables all TX interrupt sources so as not to cause an 
*  unexpected interrupt trigger because after the component is enabled, the 
*  TX FIFO is empty.
*  Refer to the function Comm_Enable() for the interrupt 
*  configuration details.
*  This function disables the SCB component without checking to see if 
*  communication is in progress. Before calling this function it may be 
*  necessary to check the status of communication to make sure communication 
*  is complete. If this is not done then communication could be stopped mid 
*  byte and corrupted data could result.
*
*******************************************************************************/
void Comm_Stop(void)
{
#if (Comm_SCB_IRQ_INTERNAL)
    Comm_DisableInt();
#endif /* (Comm_SCB_IRQ_INTERNAL) */

    /* Call Stop function specific to current operation mode */
    Comm_ScbModeStop();

    /* Disable SCB IP */
    Comm_CTRL_REG &= (uint32) ~Comm_CTRL_ENABLED;

    /* Disable all TX interrupt sources so as not to cause an unexpected
    * interrupt trigger after the component will be enabled because the 
    * TX FIFO is empty.
    * For SCB IP v0, it is critical as it does not mask-out interrupt
    * sources when it is disabled. This can cause a code lock-up in the
    * interrupt handler because TX FIFO cannot be loaded after the block
    * is disabled.
    */
    Comm_SetTxInterruptMode(Comm_NO_INTR_SOURCES);

#if (Comm_SCB_IRQ_INTERNAL)
    Comm_ClearPendingInt();
#endif /* (Comm_SCB_IRQ_INTERNAL) */
}


/*******************************************************************************
* Function Name: Comm_SetRxFifoLevel
****************************************************************************//**
*
*  Sets level in the RX FIFO to generate a RX level interrupt.
*  When the RX FIFO has more entries than the RX FIFO level an RX level
*  interrupt request is generated.
*
*  \param level: Level in the RX FIFO to generate RX level interrupt.
*   The range of valid level values is between 0 and RX FIFO depth - 1.
*
*******************************************************************************/
void Comm_SetRxFifoLevel(uint32 level)
{
    uint32 rxFifoCtrl;

    rxFifoCtrl = Comm_RX_FIFO_CTRL_REG;

    rxFifoCtrl &= ((uint32) ~Comm_RX_FIFO_CTRL_TRIGGER_LEVEL_MASK); /* Clear level mask bits */
    rxFifoCtrl |= ((uint32) (Comm_RX_FIFO_CTRL_TRIGGER_LEVEL_MASK & level));

    Comm_RX_FIFO_CTRL_REG = rxFifoCtrl;
}


/*******************************************************************************
* Function Name: Comm_SetTxFifoLevel
****************************************************************************//**
*
*  Sets level in the TX FIFO to generate a TX level interrupt.
*  When the TX FIFO has less entries than the TX FIFO level an TX level
*  interrupt request is generated.
*
*  \param level: Level in the TX FIFO to generate TX level interrupt.
*   The range of valid level values is between 0 and TX FIFO depth - 1.
*
*******************************************************************************/
void Comm_SetTxFifoLevel(uint32 level)
{
    uint32 txFifoCtrl;

    txFifoCtrl = Comm_TX_FIFO_CTRL_REG;

    txFifoCtrl &= ((uint32) ~Comm_TX_FIFO_CTRL_TRIGGER_LEVEL_MASK); /* Clear level mask bits */
    txFifoCtrl |= ((uint32) (Comm_TX_FIFO_CTRL_TRIGGER_LEVEL_MASK & level));

    Comm_TX_FIFO_CTRL_REG = txFifoCtrl;
}


#if (Comm_SCB_IRQ_INTERNAL)
    /*******************************************************************************
    * Function Name: Comm_SetCustomInterruptHandler
    ****************************************************************************//**
    *
    *  Registers a function to be called by the internal interrupt handler.
    *  First the function that is registered is called, then the internal interrupt
    *  handler performs any operation such as software buffer management functions
    *  before the interrupt returns.  It is the user's responsibility not to break
    *  the software buffer operations. Only one custom handler is supported, which
    *  is the function provided by the most recent call.
    *  At the initialization time no custom handler is registered.
    *
    *  \param func: Pointer to the function to register.
    *        The value NULL indicates to remove the current custom interrupt
    *        handler.
    *
    *******************************************************************************/
    void Comm_SetCustomInterruptHandler(void (*func)(void))
    {
    #if !defined (CY_REMOVE_Comm_CUSTOM_INTR_HANDLER)
        Comm_customIntrHandler = func; /* Register interrupt handler */
    #else
        if (NULL != func)
        {
            /* Suppress compiler warning */
        }
    #endif /* !defined (CY_REMOVE_Comm_CUSTOM_INTR_HANDLER) */
    }
#endif /* (Comm_SCB_IRQ_INTERNAL) */


/*******************************************************************************
* Function Name: Comm_ScbModeEnableIntr
****************************************************************************//**
*
*  Enables an interrupt for a specific mode.
*
*******************************************************************************/
static void Comm_ScbEnableIntr(void)
{
#if (Comm_SCB_IRQ_INTERNAL)
    /* Enable interrupt in NVIC */
    #if (Comm_SCB_MODE_UNCONFIG_CONST_CFG)
        if (0u != Comm_scbEnableIntr)
        {
            Comm_EnableInt();
        }

    #else
        Comm_EnableInt();

    #endif /* (Comm_SCB_MODE_UNCONFIG_CONST_CFG) */
#endif /* (Comm_SCB_IRQ_INTERNAL) */
}


/*******************************************************************************
* Function Name: Comm_ScbModePostEnable
****************************************************************************//**
*
*  Calls the PostEnable function for a specific operation mode.
*
*******************************************************************************/
static void Comm_ScbModePostEnable(void)
{
#if (Comm_SCB_MODE_UNCONFIG_CONST_CFG)
#if (!Comm_CY_SCBIP_V1)
    if (Comm_SCB_MODE_SPI_RUNTM_CFG)
    {
        Comm_SpiPostEnable();
    }
    else if (Comm_SCB_MODE_UART_RUNTM_CFG)
    {
        Comm_UartPostEnable();
    }
    else
    {
        /* Unknown mode: do nothing */
    }
#endif /* (!Comm_CY_SCBIP_V1) */

#elif (Comm_SCB_MODE_SPI_CONST_CFG)
    Comm_SpiPostEnable();

#elif (Comm_SCB_MODE_UART_CONST_CFG)
    Comm_UartPostEnable();

#else
    /* Unknown mode: do nothing */
#endif /* (Comm_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: Comm_ScbModeStop
****************************************************************************//**
*
*  Calls the Stop function for a specific operation mode.
*
*******************************************************************************/
static void Comm_ScbModeStop(void)
{
#if (Comm_SCB_MODE_UNCONFIG_CONST_CFG)
    if (Comm_SCB_MODE_I2C_RUNTM_CFG)
    {
        Comm_I2CStop();
    }
    else if (Comm_SCB_MODE_EZI2C_RUNTM_CFG)
    {
        Comm_EzI2CStop();
    }
#if (!Comm_CY_SCBIP_V1)
    else if (Comm_SCB_MODE_SPI_RUNTM_CFG)
    {
        Comm_SpiStop();
    }
    else if (Comm_SCB_MODE_UART_RUNTM_CFG)
    {
        Comm_UartStop();
    }
#endif /* (!Comm_CY_SCBIP_V1) */
    else
    {
        /* Unknown mode: do nothing */
    }
#elif (Comm_SCB_MODE_I2C_CONST_CFG)
    Comm_I2CStop();

#elif (Comm_SCB_MODE_EZI2C_CONST_CFG)
    Comm_EzI2CStop();

#elif (Comm_SCB_MODE_SPI_CONST_CFG)
    Comm_SpiStop();

#elif (Comm_SCB_MODE_UART_CONST_CFG)
    Comm_UartStop();

#else
    /* Unknown mode: do nothing */
#endif /* (Comm_SCB_MODE_UNCONFIG_CONST_CFG) */
}


#if (Comm_SCB_MODE_UNCONFIG_CONST_CFG)
    /*******************************************************************************
    * Function Name: Comm_SetPins
    ****************************************************************************//**
    *
    *  Sets the pins settings accordingly to the selected operation mode.
    *  Only available in the Unconfigured operation mode. The mode specific
    *  initialization function calls it.
    *  Pins configuration is set by PSoC Creator when a specific mode of operation
    *  is selected in design time.
    *
    *  \param mode:      Mode of SCB operation.
    *  \param subMode:   Sub-mode of SCB operation. It is only required for SPI and UART
    *             modes.
    *  \param uartEnableMask: enables TX or RX direction and RTS and CTS signals.
    *
    *******************************************************************************/
    void Comm_SetPins(uint32 mode, uint32 subMode, uint32 uartEnableMask)
    {
        uint32 pinsDm[Comm_SCB_PINS_NUMBER];
        uint32 i;
        
    #if (!Comm_CY_SCBIP_V1)
        uint32 pinsInBuf = 0u;
    #endif /* (!Comm_CY_SCBIP_V1) */
        
        uint32 hsiomSel[Comm_SCB_PINS_NUMBER] = 
        {
            Comm_RX_SCL_MOSI_HSIOM_SEL_GPIO,
            Comm_TX_SDA_MISO_HSIOM_SEL_GPIO,
            0u,
            0u,
            0u,
            0u,
            0u,
        };

    #if (Comm_CY_SCBIP_V1)
        /* Supress compiler warning. */
        if ((0u == subMode) || (0u == uartEnableMask))
        {
        }
    #endif /* (Comm_CY_SCBIP_V1) */

        /* Set default HSIOM to GPIO and Drive Mode to Analog Hi-Z */
        for (i = 0u; i < Comm_SCB_PINS_NUMBER; i++)
        {
            pinsDm[i] = Comm_PIN_DM_ALG_HIZ;
        }

        if ((Comm_SCB_MODE_I2C   == mode) ||
            (Comm_SCB_MODE_EZI2C == mode))
        {
        #if (Comm_RX_SCL_MOSI_PIN)
            hsiomSel[Comm_RX_SCL_MOSI_PIN_INDEX] = Comm_RX_SCL_MOSI_HSIOM_SEL_I2C;
            pinsDm  [Comm_RX_SCL_MOSI_PIN_INDEX] = Comm_PIN_DM_OD_LO;
        #elif (Comm_RX_WAKE_SCL_MOSI_PIN)
            hsiomSel[Comm_RX_WAKE_SCL_MOSI_PIN_INDEX] = Comm_RX_WAKE_SCL_MOSI_HSIOM_SEL_I2C;
            pinsDm  [Comm_RX_WAKE_SCL_MOSI_PIN_INDEX] = Comm_PIN_DM_OD_LO;
        #else
        #endif /* (Comm_RX_SCL_MOSI_PIN) */
        
        #if (Comm_TX_SDA_MISO_PIN)
            hsiomSel[Comm_TX_SDA_MISO_PIN_INDEX] = Comm_TX_SDA_MISO_HSIOM_SEL_I2C;
            pinsDm  [Comm_TX_SDA_MISO_PIN_INDEX] = Comm_PIN_DM_OD_LO;
        #endif /* (Comm_TX_SDA_MISO_PIN) */
        }
    #if (!Comm_CY_SCBIP_V1)
        else if (Comm_SCB_MODE_SPI == mode)
        {
        #if (Comm_RX_SCL_MOSI_PIN)
            hsiomSel[Comm_RX_SCL_MOSI_PIN_INDEX] = Comm_RX_SCL_MOSI_HSIOM_SEL_SPI;
        #elif (Comm_RX_WAKE_SCL_MOSI_PIN)
            hsiomSel[Comm_RX_WAKE_SCL_MOSI_PIN_INDEX] = Comm_RX_WAKE_SCL_MOSI_HSIOM_SEL_SPI;
        #else
        #endif /* (Comm_RX_SCL_MOSI_PIN) */
        
        #if (Comm_TX_SDA_MISO_PIN)
            hsiomSel[Comm_TX_SDA_MISO_PIN_INDEX] = Comm_TX_SDA_MISO_HSIOM_SEL_SPI;
        #endif /* (Comm_TX_SDA_MISO_PIN) */
        
        #if (Comm_SCLK_PIN)
            hsiomSel[Comm_SCLK_PIN_INDEX] = Comm_SCLK_HSIOM_SEL_SPI;
        #endif /* (Comm_SCLK_PIN) */

            if (Comm_SPI_SLAVE == subMode)
            {
                /* Slave */
                pinsDm[Comm_RX_SCL_MOSI_PIN_INDEX] = Comm_PIN_DM_DIG_HIZ;
                pinsDm[Comm_TX_SDA_MISO_PIN_INDEX] = Comm_PIN_DM_STRONG;
                pinsDm[Comm_SCLK_PIN_INDEX] = Comm_PIN_DM_DIG_HIZ;

            #if (Comm_SS0_PIN)
                /* Only SS0 is valid choice for Slave */
                hsiomSel[Comm_SS0_PIN_INDEX] = Comm_SS0_HSIOM_SEL_SPI;
                pinsDm  [Comm_SS0_PIN_INDEX] = Comm_PIN_DM_DIG_HIZ;
            #endif /* (Comm_SS0_PIN) */

            #if (Comm_TX_SDA_MISO_PIN)
                /* Disable input buffer */
                 pinsInBuf |= Comm_TX_SDA_MISO_PIN_MASK;
            #endif /* (Comm_TX_SDA_MISO_PIN) */
            }
            else 
            {
                /* (Master) */
                pinsDm[Comm_RX_SCL_MOSI_PIN_INDEX] = Comm_PIN_DM_STRONG;
                pinsDm[Comm_TX_SDA_MISO_PIN_INDEX] = Comm_PIN_DM_DIG_HIZ;
                pinsDm[Comm_SCLK_PIN_INDEX] = Comm_PIN_DM_STRONG;

            #if (Comm_SS0_PIN)
                hsiomSel [Comm_SS0_PIN_INDEX] = Comm_SS0_HSIOM_SEL_SPI;
                pinsDm   [Comm_SS0_PIN_INDEX] = Comm_PIN_DM_STRONG;
                pinsInBuf |= Comm_SS0_PIN_MASK;
            #endif /* (Comm_SS0_PIN) */

            #if (Comm_SS1_PIN)
                hsiomSel [Comm_SS1_PIN_INDEX] = Comm_SS1_HSIOM_SEL_SPI;
                pinsDm   [Comm_SS1_PIN_INDEX] = Comm_PIN_DM_STRONG;
                pinsInBuf |= Comm_SS1_PIN_MASK;
            #endif /* (Comm_SS1_PIN) */

            #if (Comm_SS2_PIN)
                hsiomSel [Comm_SS2_PIN_INDEX] = Comm_SS2_HSIOM_SEL_SPI;
                pinsDm   [Comm_SS2_PIN_INDEX] = Comm_PIN_DM_STRONG;
                pinsInBuf |= Comm_SS2_PIN_MASK;
            #endif /* (Comm_SS2_PIN) */

            #if (Comm_SS3_PIN)
                hsiomSel [Comm_SS3_PIN_INDEX] = Comm_SS3_HSIOM_SEL_SPI;
                pinsDm   [Comm_SS3_PIN_INDEX] = Comm_PIN_DM_STRONG;
                pinsInBuf |= Comm_SS3_PIN_MASK;
            #endif /* (Comm_SS3_PIN) */

                /* Disable input buffers */
            #if (Comm_RX_SCL_MOSI_PIN)
                pinsInBuf |= Comm_RX_SCL_MOSI_PIN_MASK;
            #elif (Comm_RX_WAKE_SCL_MOSI_PIN)
                pinsInBuf |= Comm_RX_WAKE_SCL_MOSI_PIN_MASK;
            #else
            #endif /* (Comm_RX_SCL_MOSI_PIN) */

            #if (Comm_SCLK_PIN)
                pinsInBuf |= Comm_SCLK_PIN_MASK;
            #endif /* (Comm_SCLK_PIN) */
            }
        }
        else /* UART */
        {
            if (Comm_UART_MODE_SMARTCARD == subMode)
            {
                /* SmartCard */
            #if (Comm_TX_SDA_MISO_PIN)
                hsiomSel[Comm_TX_SDA_MISO_PIN_INDEX] = Comm_TX_SDA_MISO_HSIOM_SEL_UART;
                pinsDm  [Comm_TX_SDA_MISO_PIN_INDEX] = Comm_PIN_DM_OD_LO;
            #endif /* (Comm_TX_SDA_MISO_PIN) */
            }
            else /* Standard or IrDA */
            {
                if (0u != (Comm_UART_RX_PIN_ENABLE & uartEnableMask))
                {
                #if (Comm_RX_SCL_MOSI_PIN)
                    hsiomSel[Comm_RX_SCL_MOSI_PIN_INDEX] = Comm_RX_SCL_MOSI_HSIOM_SEL_UART;
                    pinsDm  [Comm_RX_SCL_MOSI_PIN_INDEX] = Comm_PIN_DM_DIG_HIZ;
                #elif (Comm_RX_WAKE_SCL_MOSI_PIN)
                    hsiomSel[Comm_RX_WAKE_SCL_MOSI_PIN_INDEX] = Comm_RX_WAKE_SCL_MOSI_HSIOM_SEL_UART;
                    pinsDm  [Comm_RX_WAKE_SCL_MOSI_PIN_INDEX] = Comm_PIN_DM_DIG_HIZ;
                #else
                #endif /* (Comm_RX_SCL_MOSI_PIN) */
                }

                if (0u != (Comm_UART_TX_PIN_ENABLE & uartEnableMask))
                {
                #if (Comm_TX_SDA_MISO_PIN)
                    hsiomSel[Comm_TX_SDA_MISO_PIN_INDEX] = Comm_TX_SDA_MISO_HSIOM_SEL_UART;
                    pinsDm  [Comm_TX_SDA_MISO_PIN_INDEX] = Comm_PIN_DM_STRONG;
                    
                    /* Disable input buffer */
                    pinsInBuf |= Comm_TX_SDA_MISO_PIN_MASK;
                #endif /* (Comm_TX_SDA_MISO_PIN) */
                }

            #if !(Comm_CY_SCBIP_V0 || Comm_CY_SCBIP_V1)
                if (Comm_UART_MODE_STD == subMode)
                {
                    if (0u != (Comm_UART_CTS_PIN_ENABLE & uartEnableMask))
                    {
                        /* CTS input is multiplexed with SCLK */
                    #if (Comm_SCLK_PIN)
                        hsiomSel[Comm_SCLK_PIN_INDEX] = Comm_SCLK_HSIOM_SEL_UART;
                        pinsDm  [Comm_SCLK_PIN_INDEX] = Comm_PIN_DM_DIG_HIZ;
                    #endif /* (Comm_SCLK_PIN) */
                    }

                    if (0u != (Comm_UART_RTS_PIN_ENABLE & uartEnableMask))
                    {
                        /* RTS output is multiplexed with SS0 */
                    #if (Comm_SS0_PIN)
                        hsiomSel[Comm_SS0_PIN_INDEX] = Comm_SS0_HSIOM_SEL_UART;
                        pinsDm  [Comm_SS0_PIN_INDEX] = Comm_PIN_DM_STRONG;
                        
                        /* Disable input buffer */
                        pinsInBuf |= Comm_SS0_PIN_MASK;
                    #endif /* (Comm_SS0_PIN) */
                    }
                }
            #endif /* !(Comm_CY_SCBIP_V0 || Comm_CY_SCBIP_V1) */
            }
        }
    #endif /* (!Comm_CY_SCBIP_V1) */

    /* Configure pins: set HSIOM, DM and InputBufEnable */
    /* Note: the DR register settings do not effect the pin output if HSIOM is other than GPIO */

    #if (Comm_RX_SCL_MOSI_PIN)
        Comm_SET_HSIOM_SEL(Comm_RX_SCL_MOSI_HSIOM_REG,
                                       Comm_RX_SCL_MOSI_HSIOM_MASK,
                                       Comm_RX_SCL_MOSI_HSIOM_POS,
                                        hsiomSel[Comm_RX_SCL_MOSI_PIN_INDEX]);

        Comm_uart_rx_i2c_scl_spi_mosi_SetDriveMode((uint8) pinsDm[Comm_RX_SCL_MOSI_PIN_INDEX]);

        #if (!Comm_CY_SCBIP_V1)
            Comm_SET_INP_DIS(Comm_uart_rx_i2c_scl_spi_mosi_INP_DIS,
                                         Comm_uart_rx_i2c_scl_spi_mosi_MASK,
                                         (0u != (pinsInBuf & Comm_RX_SCL_MOSI_PIN_MASK)));
        #endif /* (!Comm_CY_SCBIP_V1) */
    
    #elif (Comm_RX_WAKE_SCL_MOSI_PIN)
        Comm_SET_HSIOM_SEL(Comm_RX_WAKE_SCL_MOSI_HSIOM_REG,
                                       Comm_RX_WAKE_SCL_MOSI_HSIOM_MASK,
                                       Comm_RX_WAKE_SCL_MOSI_HSIOM_POS,
                                       hsiomSel[Comm_RX_WAKE_SCL_MOSI_PIN_INDEX]);

        Comm_uart_rx_wake_i2c_scl_spi_mosi_SetDriveMode((uint8)
                                                               pinsDm[Comm_RX_WAKE_SCL_MOSI_PIN_INDEX]);

        Comm_SET_INP_DIS(Comm_uart_rx_wake_i2c_scl_spi_mosi_INP_DIS,
                                     Comm_uart_rx_wake_i2c_scl_spi_mosi_MASK,
                                     (0u != (pinsInBuf & Comm_RX_WAKE_SCL_MOSI_PIN_MASK)));

         /* Set interrupt on falling edge */
        Comm_SET_INCFG_TYPE(Comm_RX_WAKE_SCL_MOSI_INTCFG_REG,
                                        Comm_RX_WAKE_SCL_MOSI_INTCFG_TYPE_MASK,
                                        Comm_RX_WAKE_SCL_MOSI_INTCFG_TYPE_POS,
                                        Comm_INTCFG_TYPE_FALLING_EDGE);
    #else
    #endif /* (Comm_RX_WAKE_SCL_MOSI_PIN) */

    #if (Comm_TX_SDA_MISO_PIN)
        Comm_SET_HSIOM_SEL(Comm_TX_SDA_MISO_HSIOM_REG,
                                       Comm_TX_SDA_MISO_HSIOM_MASK,
                                       Comm_TX_SDA_MISO_HSIOM_POS,
                                        hsiomSel[Comm_TX_SDA_MISO_PIN_INDEX]);

        Comm_uart_tx_i2c_sda_spi_miso_SetDriveMode((uint8) pinsDm[Comm_TX_SDA_MISO_PIN_INDEX]);

    #if (!Comm_CY_SCBIP_V1)
        Comm_SET_INP_DIS(Comm_uart_tx_i2c_sda_spi_miso_INP_DIS,
                                     Comm_uart_tx_i2c_sda_spi_miso_MASK,
                                    (0u != (pinsInBuf & Comm_TX_SDA_MISO_PIN_MASK)));
    #endif /* (!Comm_CY_SCBIP_V1) */
    #endif /* (Comm_RX_SCL_MOSI_PIN) */

    #if (Comm_SCLK_PIN)
        Comm_SET_HSIOM_SEL(Comm_SCLK_HSIOM_REG,
                                       Comm_SCLK_HSIOM_MASK,
                                       Comm_SCLK_HSIOM_POS,
                                       hsiomSel[Comm_SCLK_PIN_INDEX]);

        Comm_spi_sclk_SetDriveMode((uint8) pinsDm[Comm_SCLK_PIN_INDEX]);

        Comm_SET_INP_DIS(Comm_spi_sclk_INP_DIS,
                                     Comm_spi_sclk_MASK,
                                     (0u != (pinsInBuf & Comm_SCLK_PIN_MASK)));
    #endif /* (Comm_SCLK_PIN) */

    #if (Comm_SS0_PIN)
        Comm_SET_HSIOM_SEL(Comm_SS0_HSIOM_REG,
                                       Comm_SS0_HSIOM_MASK,
                                       Comm_SS0_HSIOM_POS,
                                       hsiomSel[Comm_SS0_PIN_INDEX]);

        Comm_spi_ss0_SetDriveMode((uint8) pinsDm[Comm_SS0_PIN_INDEX]);

        Comm_SET_INP_DIS(Comm_spi_ss0_INP_DIS,
                                     Comm_spi_ss0_MASK,
                                     (0u != (pinsInBuf & Comm_SS0_PIN_MASK)));
    #endif /* (Comm_SS0_PIN) */

    #if (Comm_SS1_PIN)
        Comm_SET_HSIOM_SEL(Comm_SS1_HSIOM_REG,
                                       Comm_SS1_HSIOM_MASK,
                                       Comm_SS1_HSIOM_POS,
                                       hsiomSel[Comm_SS1_PIN_INDEX]);

        Comm_spi_ss1_SetDriveMode((uint8) pinsDm[Comm_SS1_PIN_INDEX]);

        Comm_SET_INP_DIS(Comm_spi_ss1_INP_DIS,
                                     Comm_spi_ss1_MASK,
                                     (0u != (pinsInBuf & Comm_SS1_PIN_MASK)));
    #endif /* (Comm_SS1_PIN) */

    #if (Comm_SS2_PIN)
        Comm_SET_HSIOM_SEL(Comm_SS2_HSIOM_REG,
                                       Comm_SS2_HSIOM_MASK,
                                       Comm_SS2_HSIOM_POS,
                                       hsiomSel[Comm_SS2_PIN_INDEX]);

        Comm_spi_ss2_SetDriveMode((uint8) pinsDm[Comm_SS2_PIN_INDEX]);

        Comm_SET_INP_DIS(Comm_spi_ss2_INP_DIS,
                                     Comm_spi_ss2_MASK,
                                     (0u != (pinsInBuf & Comm_SS2_PIN_MASK)));
    #endif /* (Comm_SS2_PIN) */

    #if (Comm_SS3_PIN)
        Comm_SET_HSIOM_SEL(Comm_SS3_HSIOM_REG,
                                       Comm_SS3_HSIOM_MASK,
                                       Comm_SS3_HSIOM_POS,
                                       hsiomSel[Comm_SS3_PIN_INDEX]);

        Comm_spi_ss3_SetDriveMode((uint8) pinsDm[Comm_SS3_PIN_INDEX]);

        Comm_SET_INP_DIS(Comm_spi_ss3_INP_DIS,
                                     Comm_spi_ss3_MASK,
                                     (0u != (pinsInBuf & Comm_SS3_PIN_MASK)));
    #endif /* (Comm_SS3_PIN) */
    }

#endif /* (Comm_SCB_MODE_UNCONFIG_CONST_CFG) */


#if (Comm_CY_SCBIP_V0 || Comm_CY_SCBIP_V1)
    /*******************************************************************************
    * Function Name: Comm_I2CSlaveNackGeneration
    ****************************************************************************//**
    *
    *  Sets command to generate NACK to the address or data.
    *
    *******************************************************************************/
    void Comm_I2CSlaveNackGeneration(void)
    {
        /* Check for EC_AM toggle condition: EC_AM and clock stretching for address are enabled */
        if ((0u != (Comm_CTRL_REG & Comm_CTRL_EC_AM_MODE)) &&
            (0u == (Comm_I2C_CTRL_REG & Comm_I2C_CTRL_S_NOT_READY_ADDR_NACK)))
        {
            /* Toggle EC_AM before NACK generation */
            Comm_CTRL_REG &= ~Comm_CTRL_EC_AM_MODE;
            Comm_CTRL_REG |=  Comm_CTRL_EC_AM_MODE;
        }

        Comm_I2C_SLAVE_CMD_REG = Comm_I2C_SLAVE_CMD_S_NACK;
    }
#endif /* (Comm_CY_SCBIP_V0 || Comm_CY_SCBIP_V1) */


/* [] END OF FILE */
