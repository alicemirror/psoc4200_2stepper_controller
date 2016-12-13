/***************************************************************************//**
* \file Comm_UART.c
* \version 3.20
*
* \brief
*  This file provides the source code to the API for the SCB Component in
*  UART mode.
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
#include "Comm_SPI_UART_PVT.h"


#if (Comm_UART_WAKE_ENABLE_CONST && Comm_UART_RX_WAKEUP_IRQ)
    /**
    * \addtogroup group_globals
    * \{
    */
    /** This global variable determines whether to enable Skip Start
    * functionality when Comm_Sleep() function is called:
    * 0 – disable, other values – enable. Default value is 1.
    * It is only available when Enable wakeup from Deep Sleep Mode is enabled.
    */
    uint8 Comm_skipStart = 1u;
    /** \} globals */
#endif /* (Comm_UART_WAKE_ENABLE_CONST && Comm_UART_RX_WAKEUP_IRQ) */

#if(Comm_SCB_MODE_UNCONFIG_CONST_CFG)

    /***************************************
    *  Configuration Structure Initialization
    ***************************************/

    const Comm_UART_INIT_STRUCT Comm_configUart =
    {
        Comm_UART_SUB_MODE,
        Comm_UART_DIRECTION,
        Comm_UART_DATA_BITS_NUM,
        Comm_UART_PARITY_TYPE,
        Comm_UART_STOP_BITS_NUM,
        Comm_UART_OVS_FACTOR,
        Comm_UART_IRDA_LOW_POWER,
        Comm_UART_MEDIAN_FILTER_ENABLE,
        Comm_UART_RETRY_ON_NACK,
        Comm_UART_IRDA_POLARITY,
        Comm_UART_DROP_ON_PARITY_ERR,
        Comm_UART_DROP_ON_FRAME_ERR,
        Comm_UART_WAKE_ENABLE,
        0u,
        NULL,
        0u,
        NULL,
        Comm_UART_MP_MODE_ENABLE,
        Comm_UART_MP_ACCEPT_ADDRESS,
        Comm_UART_MP_RX_ADDRESS,
        Comm_UART_MP_RX_ADDRESS_MASK,
        (uint32) Comm_SCB_IRQ_INTERNAL,
        Comm_UART_INTR_RX_MASK,
        Comm_UART_RX_TRIGGER_LEVEL,
        Comm_UART_INTR_TX_MASK,
        Comm_UART_TX_TRIGGER_LEVEL,
        (uint8) Comm_UART_BYTE_MODE_ENABLE,
        (uint8) Comm_UART_CTS_ENABLE,
        (uint8) Comm_UART_CTS_POLARITY,
        (uint8) Comm_UART_RTS_POLARITY,
        (uint8) Comm_UART_RTS_FIFO_LEVEL
    };


    /*******************************************************************************
    * Function Name: Comm_UartInit
    ****************************************************************************//**
    *
    *  Configures the Comm for UART operation.
    *
    *  This function is intended specifically to be used when the Comm
    *  configuration is set to “Unconfigured Comm” in the customizer.
    *  After initializing the Comm in UART mode using this function,
    *  the component can be enabled using the Comm_Start() or
    * Comm_Enable() function.
    *  This function uses a pointer to a structure that provides the configuration
    *  settings. This structure contains the same information that would otherwise
    *  be provided by the customizer settings.
    *
    *  \param config: pointer to a structure that contains the following list of
    *   fields. These fields match the selections available in the customizer.
    *   Refer to the customizer for further description of the settings.
    *
    *******************************************************************************/
    void Comm_UartInit(const Comm_UART_INIT_STRUCT *config)
    {
        uint32 pinsConfig;

        if (NULL == config)
        {
            CYASSERT(0u != 0u); /* Halt execution due to bad function parameter */
        }
        else
        {
            /* Get direction to configure UART pins: TX, RX or TX+RX */
            pinsConfig  = config->direction;

        #if !(Comm_CY_SCBIP_V0 || Comm_CY_SCBIP_V1)
            /* Add RTS and CTS pins to configure */
            pinsConfig |= (0u != config->rtsRxFifoLevel) ? (Comm_UART_RTS_PIN_ENABLE) : (0u);
            pinsConfig |= (0u != config->enableCts)      ? (Comm_UART_CTS_PIN_ENABLE) : (0u);
        #endif /* !(Comm_CY_SCBIP_V0 || Comm_CY_SCBIP_V1) */

            /* Configure pins */
            Comm_SetPins(Comm_SCB_MODE_UART, config->mode, pinsConfig);

            /* Store internal configuration */
            Comm_scbMode       = (uint8) Comm_SCB_MODE_UART;
            Comm_scbEnableWake = (uint8) config->enableWake;
            Comm_scbEnableIntr = (uint8) config->enableInterrupt;

            /* Set RX direction internal variables */
            Comm_rxBuffer      =         config->rxBuffer;
            Comm_rxDataBits    = (uint8) config->dataBits;
            Comm_rxBufferSize  = (uint8) config->rxBufferSize;

            /* Set TX direction internal variables */
            Comm_txBuffer      =         config->txBuffer;
            Comm_txDataBits    = (uint8) config->dataBits;
            Comm_txBufferSize  = (uint8) config->txBufferSize;

            /* Configure UART interface */
            if(Comm_UART_MODE_IRDA == config->mode)
            {
                /* OVS settings: IrDA */
                Comm_CTRL_REG  = ((0u != config->enableIrdaLowPower) ?
                                                (Comm_UART_GET_CTRL_OVS_IRDA_LP(config->oversample)) :
                                                (Comm_CTRL_OVS_IRDA_OVS16));
            }
            else
            {
                /* OVS settings: UART and SmartCard */
                Comm_CTRL_REG  = Comm_GET_CTRL_OVS(config->oversample);
            }

            Comm_CTRL_REG     |= Comm_GET_CTRL_BYTE_MODE  (config->enableByteMode)      |
                                             Comm_GET_CTRL_ADDR_ACCEPT(config->multiprocAcceptAddr) |
                                             Comm_CTRL_UART;

            /* Configure sub-mode: UART, SmartCard or IrDA */
            Comm_UART_CTRL_REG = Comm_GET_UART_CTRL_MODE(config->mode);

            /* Configure RX direction */
            Comm_UART_RX_CTRL_REG = Comm_GET_UART_RX_CTRL_MODE(config->stopBits)              |
                                        Comm_GET_UART_RX_CTRL_POLARITY(config->enableInvertedRx)          |
                                        Comm_GET_UART_RX_CTRL_MP_MODE(config->enableMultiproc)            |
                                        Comm_GET_UART_RX_CTRL_DROP_ON_PARITY_ERR(config->dropOnParityErr) |
                                        Comm_GET_UART_RX_CTRL_DROP_ON_FRAME_ERR(config->dropOnFrameErr);

            if(Comm_UART_PARITY_NONE != config->parity)
            {
               Comm_UART_RX_CTRL_REG |= Comm_GET_UART_RX_CTRL_PARITY(config->parity) |
                                                    Comm_UART_RX_CTRL_PARITY_ENABLED;
            }

            Comm_RX_CTRL_REG      = Comm_GET_RX_CTRL_DATA_WIDTH(config->dataBits)       |
                                                Comm_GET_RX_CTRL_MEDIAN(config->enableMedianFilter) |
                                                Comm_GET_UART_RX_CTRL_ENABLED(config->direction);

            Comm_RX_FIFO_CTRL_REG = Comm_GET_RX_FIFO_CTRL_TRIGGER_LEVEL(config->rxTriggerLevel);

            /* Configure MP address */
            Comm_RX_MATCH_REG     = Comm_GET_RX_MATCH_ADDR(config->multiprocAddr) |
                                                Comm_GET_RX_MATCH_MASK(config->multiprocAddrMask);

            /* Configure RX direction */
            Comm_UART_TX_CTRL_REG = Comm_GET_UART_TX_CTRL_MODE(config->stopBits) |
                                                Comm_GET_UART_TX_CTRL_RETRY_NACK(config->enableRetryNack);

            if(Comm_UART_PARITY_NONE != config->parity)
            {
               Comm_UART_TX_CTRL_REG |= Comm_GET_UART_TX_CTRL_PARITY(config->parity) |
                                                    Comm_UART_TX_CTRL_PARITY_ENABLED;
            }

            Comm_TX_CTRL_REG      = Comm_GET_TX_CTRL_DATA_WIDTH(config->dataBits)    |
                                                Comm_GET_UART_TX_CTRL_ENABLED(config->direction);

            Comm_TX_FIFO_CTRL_REG = Comm_GET_TX_FIFO_CTRL_TRIGGER_LEVEL(config->txTriggerLevel);

        #if !(Comm_CY_SCBIP_V0 || Comm_CY_SCBIP_V1)
            Comm_UART_FLOW_CTRL_REG = Comm_GET_UART_FLOW_CTRL_CTS_ENABLE(config->enableCts) | \
                                            Comm_GET_UART_FLOW_CTRL_CTS_POLARITY (config->ctsPolarity)  | \
                                            Comm_GET_UART_FLOW_CTRL_RTS_POLARITY (config->rtsPolarity)  | \
                                            Comm_GET_UART_FLOW_CTRL_TRIGGER_LEVEL(config->rtsRxFifoLevel);
        #endif /* !(Comm_CY_SCBIP_V0 || Comm_CY_SCBIP_V1) */

            /* Configure interrupt with UART handler but do not enable it */
            CyIntDisable    (Comm_ISR_NUMBER);
            CyIntSetPriority(Comm_ISR_NUMBER, Comm_ISR_PRIORITY);
            (void) CyIntSetVector(Comm_ISR_NUMBER, &Comm_SPI_UART_ISR);

            /* Configure WAKE interrupt */
        #if(Comm_UART_RX_WAKEUP_IRQ)
            CyIntDisable    (Comm_RX_WAKE_ISR_NUMBER);
            CyIntSetPriority(Comm_RX_WAKE_ISR_NUMBER, Comm_RX_WAKE_ISR_PRIORITY);
            (void) CyIntSetVector(Comm_RX_WAKE_ISR_NUMBER, &Comm_UART_WAKEUP_ISR);
        #endif /* (Comm_UART_RX_WAKEUP_IRQ) */

            /* Configure interrupt sources */
            Comm_INTR_I2C_EC_MASK_REG = Comm_NO_INTR_SOURCES;
            Comm_INTR_SPI_EC_MASK_REG = Comm_NO_INTR_SOURCES;
            Comm_INTR_SLAVE_MASK_REG  = Comm_NO_INTR_SOURCES;
            Comm_INTR_MASTER_MASK_REG = Comm_NO_INTR_SOURCES;
            Comm_INTR_RX_MASK_REG     = config->rxInterruptMask;
            Comm_INTR_TX_MASK_REG     = config->txInterruptMask;
        
            /* Configure TX interrupt sources to restore. */
            Comm_IntrTxMask = LO16(Comm_INTR_TX_MASK_REG);

            /* Clear RX buffer indexes */
            Comm_rxBufferHead     = 0u;
            Comm_rxBufferTail     = 0u;
            Comm_rxBufferOverflow = 0u;

            /* Clear TX buffer indexes */
            Comm_txBufferHead = 0u;
            Comm_txBufferTail = 0u;
        }
    }

#else

    /*******************************************************************************
    * Function Name: Comm_UartInit
    ****************************************************************************//**
    *
    *  Configures the SCB for the UART operation.
    *
    *******************************************************************************/
    void Comm_UartInit(void)
    {
        /* Configure UART interface */
        Comm_CTRL_REG = Comm_UART_DEFAULT_CTRL;

        /* Configure sub-mode: UART, SmartCard or IrDA */
        Comm_UART_CTRL_REG = Comm_UART_DEFAULT_UART_CTRL;

        /* Configure RX direction */
        Comm_UART_RX_CTRL_REG = Comm_UART_DEFAULT_UART_RX_CTRL;
        Comm_RX_CTRL_REG      = Comm_UART_DEFAULT_RX_CTRL;
        Comm_RX_FIFO_CTRL_REG = Comm_UART_DEFAULT_RX_FIFO_CTRL;
        Comm_RX_MATCH_REG     = Comm_UART_DEFAULT_RX_MATCH_REG;

        /* Configure TX direction */
        Comm_UART_TX_CTRL_REG = Comm_UART_DEFAULT_UART_TX_CTRL;
        Comm_TX_CTRL_REG      = Comm_UART_DEFAULT_TX_CTRL;
        Comm_TX_FIFO_CTRL_REG = Comm_UART_DEFAULT_TX_FIFO_CTRL;

    #if !(Comm_CY_SCBIP_V0 || Comm_CY_SCBIP_V1)
        Comm_UART_FLOW_CTRL_REG = Comm_UART_DEFAULT_FLOW_CTRL;
    #endif /* !(Comm_CY_SCBIP_V0 || Comm_CY_SCBIP_V1) */

        /* Configure interrupt with UART handler but do not enable it */
    #if(Comm_SCB_IRQ_INTERNAL)
        CyIntDisable    (Comm_ISR_NUMBER);
        CyIntSetPriority(Comm_ISR_NUMBER, Comm_ISR_PRIORITY);
        (void) CyIntSetVector(Comm_ISR_NUMBER, &Comm_SPI_UART_ISR);
    #endif /* (Comm_SCB_IRQ_INTERNAL) */

        /* Configure WAKE interrupt */
    #if(Comm_UART_RX_WAKEUP_IRQ)
        CyIntDisable    (Comm_RX_WAKE_ISR_NUMBER);
        CyIntSetPriority(Comm_RX_WAKE_ISR_NUMBER, Comm_RX_WAKE_ISR_PRIORITY);
        (void) CyIntSetVector(Comm_RX_WAKE_ISR_NUMBER, &Comm_UART_WAKEUP_ISR);
    #endif /* (Comm_UART_RX_WAKEUP_IRQ) */

        /* Configure interrupt sources */
        Comm_INTR_I2C_EC_MASK_REG = Comm_UART_DEFAULT_INTR_I2C_EC_MASK;
        Comm_INTR_SPI_EC_MASK_REG = Comm_UART_DEFAULT_INTR_SPI_EC_MASK;
        Comm_INTR_SLAVE_MASK_REG  = Comm_UART_DEFAULT_INTR_SLAVE_MASK;
        Comm_INTR_MASTER_MASK_REG = Comm_UART_DEFAULT_INTR_MASTER_MASK;
        Comm_INTR_RX_MASK_REG     = Comm_UART_DEFAULT_INTR_RX_MASK;
        Comm_INTR_TX_MASK_REG     = Comm_UART_DEFAULT_INTR_TX_MASK;
    
        /* Configure TX interrupt sources to restore. */
        Comm_IntrTxMask = LO16(Comm_INTR_TX_MASK_REG);

    #if(Comm_INTERNAL_RX_SW_BUFFER_CONST)
        Comm_rxBufferHead     = 0u;
        Comm_rxBufferTail     = 0u;
        Comm_rxBufferOverflow = 0u;
    #endif /* (Comm_INTERNAL_RX_SW_BUFFER_CONST) */

    #if(Comm_INTERNAL_TX_SW_BUFFER_CONST)
        Comm_txBufferHead = 0u;
        Comm_txBufferTail = 0u;
    #endif /* (Comm_INTERNAL_TX_SW_BUFFER_CONST) */
    }
#endif /* (Comm_SCB_MODE_UNCONFIG_CONST_CFG) */


/*******************************************************************************
* Function Name: Comm_UartPostEnable
****************************************************************************//**
*
*  Restores HSIOM settings for the UART output pins (TX and/or RTS) to be
*  controlled by the SCB UART.
*
*******************************************************************************/
void Comm_UartPostEnable(void)
{
#if (Comm_SCB_MODE_UNCONFIG_CONST_CFG)
    #if (Comm_TX_SDA_MISO_PIN)
        if (Comm_CHECK_TX_SDA_MISO_PIN_USED)
        {
            /* Set SCB UART to drive the output pin */
            Comm_SET_HSIOM_SEL(Comm_TX_SDA_MISO_HSIOM_REG, Comm_TX_SDA_MISO_HSIOM_MASK,
                                           Comm_TX_SDA_MISO_HSIOM_POS, Comm_TX_SDA_MISO_HSIOM_SEL_UART);
        }
    #endif /* (Comm_TX_SDA_MISO_PIN_PIN) */

    #if !(Comm_CY_SCBIP_V0 || Comm_CY_SCBIP_V1)
        #if (Comm_SS0_PIN)
            if (Comm_CHECK_SS0_PIN_USED)
            {
                /* Set SCB UART to drive the output pin */
                Comm_SET_HSIOM_SEL(Comm_SS0_HSIOM_REG, Comm_SS0_HSIOM_MASK,
                                               Comm_SS0_HSIOM_POS, Comm_SS0_HSIOM_SEL_UART);
            }
        #endif /* (Comm_SS0_PIN) */
    #endif /* !(Comm_CY_SCBIP_V0 || Comm_CY_SCBIP_V1) */

#else
    #if (Comm_UART_TX_PIN)
         /* Set SCB UART to drive the output pin */
        Comm_SET_HSIOM_SEL(Comm_TX_HSIOM_REG, Comm_TX_HSIOM_MASK,
                                       Comm_TX_HSIOM_POS, Comm_TX_HSIOM_SEL_UART);
    #endif /* (Comm_UART_TX_PIN) */

    #if (Comm_UART_RTS_PIN)
        /* Set SCB UART to drive the output pin */
        Comm_SET_HSIOM_SEL(Comm_RTS_HSIOM_REG, Comm_RTS_HSIOM_MASK,
                                       Comm_RTS_HSIOM_POS, Comm_RTS_HSIOM_SEL_UART);
    #endif /* (Comm_UART_RTS_PIN) */
#endif /* (Comm_SCB_MODE_UNCONFIG_CONST_CFG) */

    /* Restore TX interrupt sources. */
    Comm_SetTxInterruptMode(Comm_IntrTxMask);
}


/*******************************************************************************
* Function Name: Comm_UartStop
****************************************************************************//**
*
*  Changes the HSIOM settings for the UART output pins (TX and/or RTS) to keep
*  them inactive after the block is disabled. The output pins are controlled by
*  the GPIO data register. Also, the function disables the skip start feature
*  to not cause it to trigger after the component is enabled.
*
*******************************************************************************/
void Comm_UartStop(void)
{
#if(Comm_SCB_MODE_UNCONFIG_CONST_CFG)
    #if (Comm_TX_SDA_MISO_PIN)
        if (Comm_CHECK_TX_SDA_MISO_PIN_USED)
        {
            /* Set GPIO to drive output pin */
            Comm_SET_HSIOM_SEL(Comm_TX_SDA_MISO_HSIOM_REG, Comm_TX_SDA_MISO_HSIOM_MASK,
                                           Comm_TX_SDA_MISO_HSIOM_POS, Comm_TX_SDA_MISO_HSIOM_SEL_GPIO);
        }
    #endif /* (Comm_TX_SDA_MISO_PIN_PIN) */

    #if !(Comm_CY_SCBIP_V0 || Comm_CY_SCBIP_V1)
        #if (Comm_SS0_PIN)
            if (Comm_CHECK_SS0_PIN_USED)
            {
                /* Set output pin state after block is disabled */
                Comm_spi_ss0_Write(Comm_GET_UART_RTS_INACTIVE);

                /* Set GPIO to drive output pin */
                Comm_SET_HSIOM_SEL(Comm_SS0_HSIOM_REG, Comm_SS0_HSIOM_MASK,
                                               Comm_SS0_HSIOM_POS, Comm_SS0_HSIOM_SEL_GPIO);
            }
        #endif /* (Comm_SS0_PIN) */
    #endif /* !(Comm_CY_SCBIP_V0 || Comm_CY_SCBIP_V1) */

#else
    #if (Comm_UART_TX_PIN)
        /* Set GPIO to drive output pin */
        Comm_SET_HSIOM_SEL(Comm_TX_HSIOM_REG, Comm_TX_HSIOM_MASK,
                                       Comm_TX_HSIOM_POS, Comm_TX_HSIOM_SEL_GPIO);
    #endif /* (Comm_UART_TX_PIN) */

    #if (Comm_UART_RTS_PIN)
        /* Set output pin state after block is disabled */
        Comm_rts_Write(Comm_GET_UART_RTS_INACTIVE);

        /* Set GPIO to drive output pin */
        Comm_SET_HSIOM_SEL(Comm_RTS_HSIOM_REG, Comm_RTS_HSIOM_MASK,
                                       Comm_RTS_HSIOM_POS, Comm_RTS_HSIOM_SEL_GPIO);
    #endif /* (Comm_UART_RTS_PIN) */

#endif /* (Comm_SCB_MODE_UNCONFIG_CONST_CFG) */

#if (Comm_UART_WAKE_ENABLE_CONST)
    /* Disable skip start feature used for wakeup */
    Comm_UART_RX_CTRL_REG &= (uint32) ~Comm_UART_RX_CTRL_SKIP_START;
#endif /* (Comm_UART_WAKE_ENABLE_CONST) */

    /* Store TX interrupt sources (exclude level triggered). */
    Comm_IntrTxMask = LO16(Comm_GetTxInterruptMode() & Comm_INTR_UART_TX_RESTORE);
}


/*******************************************************************************
* Function Name: Comm_UartSetRxAddress
****************************************************************************//**
*
*  Sets the hardware detectable receiver address for the UART in the
*  Multiprocessor mode.
*
*  \param address: Address for hardware address detection.
*
*******************************************************************************/
void Comm_UartSetRxAddress(uint32 address)
{
     uint32 matchReg;

    matchReg = Comm_RX_MATCH_REG;

    matchReg &= ((uint32) ~Comm_RX_MATCH_ADDR_MASK); /* Clear address bits */
    matchReg |= ((uint32)  (address & Comm_RX_MATCH_ADDR_MASK)); /* Set address  */

    Comm_RX_MATCH_REG = matchReg;
}


/*******************************************************************************
* Function Name: Comm_UartSetRxAddressMask
****************************************************************************//**
*
*  Sets the hardware address mask for the UART in the Multiprocessor mode.
*
*  \param addressMask: Address mask.
*   - Bit value 0 – excludes bit from address comparison.
*   - Bit value 1 – the bit needs to match with the corresponding bit
*     of the address.
*
*******************************************************************************/
void Comm_UartSetRxAddressMask(uint32 addressMask)
{
    uint32 matchReg;

    matchReg = Comm_RX_MATCH_REG;

    matchReg &= ((uint32) ~Comm_RX_MATCH_MASK_MASK); /* Clear address mask bits */
    matchReg |= ((uint32) (addressMask << Comm_RX_MATCH_MASK_POS));

    Comm_RX_MATCH_REG = matchReg;
}


#if(Comm_UART_RX_DIRECTION)
    /*******************************************************************************
    * Function Name: Comm_UartGetChar
    ****************************************************************************//**
    *
    *  Retrieves next data element from receive buffer.
    *  This function is designed for ASCII characters and returns a char where
    *  1 to 255 are valid characters and 0 indicates an error occurred or no data
    *  is present.
    *  - RX software buffer is disabled: Returns data element retrieved from RX
    *    FIFO.
    *  - RX software buffer is enabled: Returns data element from the software
    *    receive buffer.
    *
    *  \return
    *   Next data element from the receive buffer. ASCII character values from
    *   1 to 255 are valid. A returned zero signifies an error condition or no
    *   data available.
    *
    *  \sideeffect
    *   The errors bits may not correspond with reading characters due to
    *   RX FIFO and software buffer usage.
    *   RX software buffer is enabled: The internal software buffer overflow
    *   is not treated as an error condition.
    *   Check Comm_rxBufferOverflow to capture that error condition.
    *
    *******************************************************************************/
    uint32 Comm_UartGetChar(void)
    {
        uint32 rxData = 0u;

        /* Reads data only if there is data to read */
        if (0u != Comm_SpiUartGetRxBufferSize())
        {
            rxData = Comm_SpiUartReadRxData();
        }

        if (Comm_CHECK_INTR_RX(Comm_INTR_RX_ERR))
        {
            rxData = 0u; /* Error occurred: returns zero */
            Comm_ClearRxInterruptSource(Comm_INTR_RX_ERR);
        }

        return (rxData);
    }


    /*******************************************************************************
    * Function Name: Comm_UartGetByte
    ****************************************************************************//**
    *
    *  Retrieves the next data element from the receive buffer, returns the
    *  received byte and error condition.
    *   - The RX software buffer is disabled: returns the data element retrieved
    *     from the RX FIFO. Undefined data will be returned if the RX FIFO is
    *     empty.
    *   - The RX software buffer is enabled: returns data element from the
    *     software receive buffer.
    *
    *  \return
    *   Bits 7-0 contain the next data element from the receive buffer and
    *   other bits contain the error condition.
    *   - Comm_UART_RX_OVERFLOW - Attempt to write to a full
    *     receiver FIFO.
    *   - Comm_UART_RX_UNDERFLOW	Attempt to read from an empty
    *     receiver FIFO.
    *   - Comm_UART_RX_FRAME_ERROR - UART framing error detected.
    *   - Comm_UART_RX_PARITY_ERROR - UART parity error detected.
    *
    *  \sideeffect
    *   The errors bits may not correspond with reading characters due to
    *   RX FIFO and software buffer usage.
    *   RX software buffer is enabled: The internal software buffer overflow
    *   is not treated as an error condition.
    *   Check Comm_rxBufferOverflow to capture that error condition.
    *
    *******************************************************************************/
    uint32 Comm_UartGetByte(void)
    {
        uint32 rxData;
        uint32 tmpStatus;

        if (Comm_CHECK_RX_SW_BUFFER)
        {
            Comm_DisableInt();
        }
        

        if (0u != Comm_SpiUartGetRxBufferSize())
        {
            /* Enables interrupt to receive more bytes: at least one byte is in
            * buffer.
            */
            if (Comm_CHECK_RX_SW_BUFFER)
            {
                Comm_EnableInt();
            }
            

            /* Get received byte */
            rxData = Comm_SpiUartReadRxData();
        }
        else
        {
            /* Reads a byte directly from RX FIFO: underflow is raised in the
            * case of empty. Otherwise the first received byte will be read.
            */
            rxData = Comm_RX_FIFO_RD_REG;


            /* Enables interrupt to receive more bytes. */
            if (Comm_CHECK_RX_SW_BUFFER)
            {

                /* The byte has been read from RX FIFO. Clear RX interrupt to
                * not involve interrupt handler when RX FIFO is empty.
                */
                Comm_ClearRxInterruptSource(Comm_INTR_RX_NOT_EMPTY);

                Comm_EnableInt();
            }
            
        }

        /* Get and clear RX error mask */
        tmpStatus = (Comm_GetRxInterruptSource() & Comm_INTR_RX_ERR);
        Comm_ClearRxInterruptSource(Comm_INTR_RX_ERR);

        /* Puts together data and error status:
        * MP mode and accept address: 9th bit is set to notify mark.
        */
        rxData |= ((uint32) (tmpStatus << 8u));

        return (rxData);
    }


    #if !(Comm_CY_SCBIP_V0 || Comm_CY_SCBIP_V1)
        /*******************************************************************************
        * Function Name: Comm_UartSetRtsPolarity
        ****************************************************************************//**
        *
        *  Sets active polarity of RTS output signal.
        *  Only available for PSoC 4100 BLE / PSoC 4200 BLE / PSoC 4100M / PSoC 4200M /
        *  PSoC 4200L / PSoC 4000S / PSoC 4100S / PSoC Analog Coprocessor devices.
        *
        *  \param polarity: Active polarity of RTS output signal.
        *   - Comm_UART_RTS_ACTIVE_LOW  - RTS signal is active low.
        *   - Comm_UART_RTS_ACTIVE_HIGH - RTS signal is active high.
        *
        *******************************************************************************/
        void Comm_UartSetRtsPolarity(uint32 polarity)
        {
            if(0u != polarity)
            {
                Comm_UART_FLOW_CTRL_REG |= (uint32)  Comm_UART_FLOW_CTRL_RTS_POLARITY;
            }
            else
            {
                Comm_UART_FLOW_CTRL_REG &= (uint32) ~Comm_UART_FLOW_CTRL_RTS_POLARITY;
            }
        }


        /*******************************************************************************
        * Function Name: Comm_UartSetRtsFifoLevel
        ****************************************************************************//**
        *
        *  Sets level in the RX FIFO for RTS signal activation.
        *  While the RX FIFO has fewer entries than the RX FIFO level the RTS signal
        *  remains active, otherwise the RTS signal becomes inactive.
        *  Only available for PSoC 4100 BLE / PSoC 4200 BLE / PSoC 4100M / PSoC 4200M /
        *  PSoC 4200L / PSoC 4000S / PSoC 4100S / PSoC Analog Coprocessor devices.
        *
        *  \param level: Level in the RX FIFO for RTS signal activation.
        *   The range of valid level values is between 0 and RX FIFO depth - 1.
        *   Setting level value to 0 disables RTS signal activation.
        *
        *******************************************************************************/
        void Comm_UartSetRtsFifoLevel(uint32 level)
        {
            uint32 uartFlowCtrl;

            uartFlowCtrl = Comm_UART_FLOW_CTRL_REG;

            uartFlowCtrl &= ((uint32) ~Comm_UART_FLOW_CTRL_TRIGGER_LEVEL_MASK); /* Clear level mask bits */
            uartFlowCtrl |= ((uint32) (Comm_UART_FLOW_CTRL_TRIGGER_LEVEL_MASK & level));

            Comm_UART_FLOW_CTRL_REG = uartFlowCtrl;
        }
    #endif /* !(Comm_CY_SCBIP_V0 || Comm_CY_SCBIP_V1) */

#endif /* (Comm_UART_RX_DIRECTION) */


#if(Comm_UART_TX_DIRECTION)
    /*******************************************************************************
    * Function Name: Comm_UartPutString
    ****************************************************************************//**
    *
    *  Places a NULL terminated string in the transmit buffer to be sent at the
    *  next available bus time.
    *  This function is blocking and waits until there is a space available to put
    *  requested data in transmit buffer.
    *
    *  \param string: pointer to the null terminated string array to be placed in the
    *   transmit buffer.
    *
    *******************************************************************************/
    void Comm_UartPutString(const char8 string[])
    {
        uint32 bufIndex;

        bufIndex = 0u;

        /* Blocks the control flow until all data has been sent */
        while(string[bufIndex] != ((char8) 0))
        {
            Comm_UartPutChar((uint32) string[bufIndex]);
            bufIndex++;
        }
    }


    /*******************************************************************************
    * Function Name: Comm_UartPutCRLF
    ****************************************************************************//**
    *
    *  Places byte of data followed by a carriage return (0x0D) and line feed
    *  (0x0A) in the transmit buffer.
    *  This function is blocking and waits until there is a space available to put
    *  all requested data in transmit buffer.
    *
    *  \param txDataByte: the data to be transmitted.
    *
    *******************************************************************************/
    void Comm_UartPutCRLF(uint32 txDataByte)
    {
        Comm_UartPutChar(txDataByte);  /* Blocks control flow until all data has been sent */
        Comm_UartPutChar(0x0Du);       /* Blocks control flow until all data has been sent */
        Comm_UartPutChar(0x0Au);       /* Blocks control flow until all data has been sent */
    }


    #if !(Comm_CY_SCBIP_V0 || Comm_CY_SCBIP_V1)
        /*******************************************************************************
        * Function Name: CommSCB_UartEnableCts
        ****************************************************************************//**
        *
        *  Enables usage of CTS input signal by the UART transmitter.
        *  Only available for PSoC 4100 BLE / PSoC 4200 BLE / PSoC 4100M / PSoC 4200M /
        *  PSoC 4200L / PSoC 4000S / PSoC 4100S / PSoC Analog Coprocessor devices.
        *
        *******************************************************************************/
        void Comm_UartEnableCts(void)
        {
            Comm_UART_FLOW_CTRL_REG |= (uint32)  Comm_UART_FLOW_CTRL_CTS_ENABLE;
        }


        /*******************************************************************************
        * Function Name: Comm_UartDisableCts
        ****************************************************************************//**
        *
        *  Disables usage of CTS input signal by the UART transmitter.
        *  Only available for PSoC 4100 BLE / PSoC 4200 BLE / PSoC 4100M / PSoC 4200M /
        *  PSoC 4200L / PSoC 4000S / PSoC 4100S / PSoC Analog Coprocessor devices.
        *
        *******************************************************************************/
        void Comm_UartDisableCts(void)
        {
            Comm_UART_FLOW_CTRL_REG &= (uint32) ~Comm_UART_FLOW_CTRL_CTS_ENABLE;
        }


        /*******************************************************************************
        * Function Name: Comm_UartSetCtsPolarity
        ****************************************************************************//**
        *
        *  Sets active polarity of CTS input signal.
        *  Only available for PSoC 4100 BLE / PSoC 4200 BLE / PSoC 4100M / PSoC 4200M /
        *  PSoC 4200L / PSoC 4000S / PSoC 4100S / PSoC Analog Coprocessor devices.
        *
        *  \param polarity: Active polarity of CTS output signal.
        *   - Comm_UART_CTS_ACTIVE_LOW  - CTS signal is active low.
        *   - Comm_UART_CTS_ACTIVE_HIGH - CTS signal is active high.
        *
        *******************************************************************************/
        void Comm_UartSetCtsPolarity(uint32 polarity)
        {
            if (0u != polarity)
            {
                Comm_UART_FLOW_CTRL_REG |= (uint32)  Comm_UART_FLOW_CTRL_CTS_POLARITY;
            }
            else
            {
                Comm_UART_FLOW_CTRL_REG &= (uint32) ~Comm_UART_FLOW_CTRL_CTS_POLARITY;
            }
        }
    #endif /* !(Comm_CY_SCBIP_V0 || Comm_CY_SCBIP_V1) */

#endif /* (Comm_UART_TX_DIRECTION) */


#if (Comm_UART_WAKE_ENABLE_CONST)
    /*******************************************************************************
    * Function Name: Comm_UartSaveConfig
    ****************************************************************************//**
    *
    *  Clears and enables an interrupt on a falling edge of the Rx input. The GPIO
    *  interrupt does not track in the active mode, therefore requires to be 
    *  cleared by this API.
    *
    *******************************************************************************/
    void Comm_UartSaveConfig(void)
    {
    #if (Comm_UART_RX_WAKEUP_IRQ)
        /* Set SKIP_START if requested (set by default). */
        if (0u != Comm_skipStart)
        {
            Comm_UART_RX_CTRL_REG |= (uint32)  Comm_UART_RX_CTRL_SKIP_START;
        }
        else
        {
            Comm_UART_RX_CTRL_REG &= (uint32) ~Comm_UART_RX_CTRL_SKIP_START;
        }
        
        /* Clear RX GPIO interrupt status and pending interrupt in NVIC because
        * falling edge on RX line occurs while UART communication in active mode.
        * Enable interrupt: next interrupt trigger should wakeup device.
        */
        Comm_CLEAR_UART_RX_WAKE_INTR;
        Comm_RxWakeClearPendingInt();
        Comm_RxWakeEnableInt();
    #endif /* (Comm_UART_RX_WAKEUP_IRQ) */
    }


    /*******************************************************************************
    * Function Name: Comm_UartRestoreConfig
    ****************************************************************************//**
    *
    *  Disables the RX GPIO interrupt. Until this function is called the interrupt
    *  remains active and triggers on every falling edge of the UART RX line.
    *
    *******************************************************************************/
    void Comm_UartRestoreConfig(void)
    {
    #if (Comm_UART_RX_WAKEUP_IRQ)
        /* Disable interrupt: no more triggers in active mode */
        Comm_RxWakeDisableInt();
    #endif /* (Comm_UART_RX_WAKEUP_IRQ) */
    }


    #if (Comm_UART_RX_WAKEUP_IRQ)
        /*******************************************************************************
        * Function Name: Comm_UART_WAKEUP_ISR
        ****************************************************************************//**
        *
        *  Handles the Interrupt Service Routine for the SCB UART mode GPIO wakeup
        *  event. This event is configured to trigger on a falling edge of the RX line.
        *
        *******************************************************************************/
        CY_ISR(Comm_UART_WAKEUP_ISR)
        {
        #ifdef Comm_UART_WAKEUP_ISR_ENTRY_CALLBACK
            Comm_UART_WAKEUP_ISR_EntryCallback();
        #endif /* Comm_UART_WAKEUP_ISR_ENTRY_CALLBACK */

            Comm_CLEAR_UART_RX_WAKE_INTR;

        #ifdef Comm_UART_WAKEUP_ISR_EXIT_CALLBACK
            Comm_UART_WAKEUP_ISR_ExitCallback();
        #endif /* Comm_UART_WAKEUP_ISR_EXIT_CALLBACK */
        }
    #endif /* (Comm_UART_RX_WAKEUP_IRQ) */
#endif /* (Comm_UART_RX_WAKEUP_IRQ) */


/* [] END OF FILE */
