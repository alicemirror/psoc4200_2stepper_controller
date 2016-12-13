/***************************************************************************//**
* \file Comm_SPI.c
* \version 3.20
*
* \brief
*  This file provides the source code to the API for the SCB Component in
*  SPI mode.
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

#if(Comm_SCB_MODE_UNCONFIG_CONST_CFG)

    /***************************************
    *  Configuration Structure Initialization
    ***************************************/

    const Comm_SPI_INIT_STRUCT Comm_configSpi =
    {
        Comm_SPI_MODE,
        Comm_SPI_SUB_MODE,
        Comm_SPI_CLOCK_MODE,
        Comm_SPI_OVS_FACTOR,
        Comm_SPI_MEDIAN_FILTER_ENABLE,
        Comm_SPI_LATE_MISO_SAMPLE_ENABLE,
        Comm_SPI_WAKE_ENABLE,
        Comm_SPI_RX_DATA_BITS_NUM,
        Comm_SPI_TX_DATA_BITS_NUM,
        Comm_SPI_BITS_ORDER,
        Comm_SPI_TRANSFER_SEPARATION,
        0u,
        NULL,
        0u,
        NULL,
        (uint32) Comm_SCB_IRQ_INTERNAL,
        Comm_SPI_INTR_RX_MASK,
        Comm_SPI_RX_TRIGGER_LEVEL,
        Comm_SPI_INTR_TX_MASK,
        Comm_SPI_TX_TRIGGER_LEVEL,
        (uint8) Comm_SPI_BYTE_MODE_ENABLE,
        (uint8) Comm_SPI_FREE_RUN_SCLK_ENABLE,
        (uint8) Comm_SPI_SS_POLARITY
    };


    /*******************************************************************************
    * Function Name: Comm_SpiInit
    ****************************************************************************//**
    *
    *  Configures the Comm for SPI operation.
    *
    *  This function is intended specifically to be used when the Comm 
    *  configuration is set to “Unconfigured Comm” in the customizer. 
    *  After initializing the Comm in SPI mode using this function, 
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
    void Comm_SpiInit(const Comm_SPI_INIT_STRUCT *config)
    {
        if(NULL == config)
        {
            CYASSERT(0u != 0u); /* Halt execution due to bad function parameter */
        }
        else
        {
            /* Configure pins */
            Comm_SetPins(Comm_SCB_MODE_SPI, config->mode, Comm_DUMMY_PARAM);

            /* Store internal configuration */
            Comm_scbMode       = (uint8) Comm_SCB_MODE_SPI;
            Comm_scbEnableWake = (uint8) config->enableWake;
            Comm_scbEnableIntr = (uint8) config->enableInterrupt;

            /* Set RX direction internal variables */
            Comm_rxBuffer      =         config->rxBuffer;
            Comm_rxDataBits    = (uint8) config->rxDataBits;
            Comm_rxBufferSize  = (uint8) config->rxBufferSize;

            /* Set TX direction internal variables */
            Comm_txBuffer      =         config->txBuffer;
            Comm_txDataBits    = (uint8) config->txDataBits;
            Comm_txBufferSize  = (uint8) config->txBufferSize;

            /* Configure SPI interface */
            Comm_CTRL_REG     = Comm_GET_CTRL_OVS(config->oversample)           |
                                            Comm_GET_CTRL_BYTE_MODE(config->enableByteMode) |
                                            Comm_GET_CTRL_EC_AM_MODE(config->enableWake)    |
                                            Comm_CTRL_SPI;

            Comm_SPI_CTRL_REG = Comm_GET_SPI_CTRL_CONTINUOUS    (config->transferSeperation)  |
                                            Comm_GET_SPI_CTRL_SELECT_PRECEDE(config->submode &
                                                                          Comm_SPI_MODE_TI_PRECEDES_MASK) |
                                            Comm_GET_SPI_CTRL_SCLK_MODE     (config->sclkMode)            |
                                            Comm_GET_SPI_CTRL_LATE_MISO_SAMPLE(config->enableLateSampling)|
                                            Comm_GET_SPI_CTRL_SCLK_CONTINUOUS(config->enableFreeRunSclk)  |
                                            Comm_GET_SPI_CTRL_SSEL_POLARITY (config->polaritySs)          |
                                            Comm_GET_SPI_CTRL_SUB_MODE      (config->submode)             |
                                            Comm_GET_SPI_CTRL_MASTER_MODE   (config->mode);

            /* Configure RX direction */
            Comm_RX_CTRL_REG     =  Comm_GET_RX_CTRL_DATA_WIDTH(config->rxDataBits)         |
                                                Comm_GET_RX_CTRL_BIT_ORDER (config->bitOrder)           |
                                                Comm_GET_RX_CTRL_MEDIAN    (config->enableMedianFilter) |
                                                Comm_SPI_RX_CTRL;

            Comm_RX_FIFO_CTRL_REG = Comm_GET_RX_FIFO_CTRL_TRIGGER_LEVEL(config->rxTriggerLevel);

            /* Configure TX direction */
            Comm_TX_CTRL_REG      = Comm_GET_TX_CTRL_DATA_WIDTH(config->txDataBits) |
                                                Comm_GET_TX_CTRL_BIT_ORDER (config->bitOrder)   |
                                                Comm_SPI_TX_CTRL;

            Comm_TX_FIFO_CTRL_REG = Comm_GET_TX_FIFO_CTRL_TRIGGER_LEVEL(config->txTriggerLevel);

            /* Configure interrupt with SPI handler but do not enable it */
            CyIntDisable    (Comm_ISR_NUMBER);
            CyIntSetPriority(Comm_ISR_NUMBER, Comm_ISR_PRIORITY);
            (void) CyIntSetVector(Comm_ISR_NUMBER, &Comm_SPI_UART_ISR);

            /* Configure interrupt sources */
            Comm_INTR_I2C_EC_MASK_REG = Comm_NO_INTR_SOURCES;
            Comm_INTR_SPI_EC_MASK_REG = Comm_NO_INTR_SOURCES;
            Comm_INTR_SLAVE_MASK_REG  = Comm_GET_SPI_INTR_SLAVE_MASK(config->rxInterruptMask);
            Comm_INTR_MASTER_MASK_REG = Comm_GET_SPI_INTR_MASTER_MASK(config->txInterruptMask);
            Comm_INTR_RX_MASK_REG     = Comm_GET_SPI_INTR_RX_MASK(config->rxInterruptMask);
            Comm_INTR_TX_MASK_REG     = Comm_GET_SPI_INTR_TX_MASK(config->txInterruptMask);
            
            /* Configure TX interrupt sources to restore. */
            Comm_IntrTxMask = LO16(Comm_INTR_TX_MASK_REG);

            /* Set active SS0 */
            Comm_SpiSetActiveSlaveSelect(Comm_SPI_SLAVE_SELECT0);

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
    * Function Name: Comm_SpiInit
    ****************************************************************************//**
    *
    *  Configures the SCB for the SPI operation.
    *
    *******************************************************************************/
    void Comm_SpiInit(void)
    {
        /* Configure SPI interface */
        Comm_CTRL_REG     = Comm_SPI_DEFAULT_CTRL;
        Comm_SPI_CTRL_REG = Comm_SPI_DEFAULT_SPI_CTRL;

        /* Configure TX and RX direction */
        Comm_RX_CTRL_REG      = Comm_SPI_DEFAULT_RX_CTRL;
        Comm_RX_FIFO_CTRL_REG = Comm_SPI_DEFAULT_RX_FIFO_CTRL;

        /* Configure TX and RX direction */
        Comm_TX_CTRL_REG      = Comm_SPI_DEFAULT_TX_CTRL;
        Comm_TX_FIFO_CTRL_REG = Comm_SPI_DEFAULT_TX_FIFO_CTRL;

        /* Configure interrupt with SPI handler but do not enable it */
    #if(Comm_SCB_IRQ_INTERNAL)
            CyIntDisable    (Comm_ISR_NUMBER);
            CyIntSetPriority(Comm_ISR_NUMBER, Comm_ISR_PRIORITY);
            (void) CyIntSetVector(Comm_ISR_NUMBER, &Comm_SPI_UART_ISR);
    #endif /* (Comm_SCB_IRQ_INTERNAL) */

        /* Configure interrupt sources */
        Comm_INTR_I2C_EC_MASK_REG = Comm_SPI_DEFAULT_INTR_I2C_EC_MASK;
        Comm_INTR_SPI_EC_MASK_REG = Comm_SPI_DEFAULT_INTR_SPI_EC_MASK;
        Comm_INTR_SLAVE_MASK_REG  = Comm_SPI_DEFAULT_INTR_SLAVE_MASK;
        Comm_INTR_MASTER_MASK_REG = Comm_SPI_DEFAULT_INTR_MASTER_MASK;
        Comm_INTR_RX_MASK_REG     = Comm_SPI_DEFAULT_INTR_RX_MASK;
        Comm_INTR_TX_MASK_REG     = Comm_SPI_DEFAULT_INTR_TX_MASK;

        /* Configure TX interrupt sources to restore. */
        Comm_IntrTxMask = LO16(Comm_INTR_TX_MASK_REG);
            
        /* Set active SS0 for master */
    #if (Comm_SPI_MASTER_CONST)
        Comm_SpiSetActiveSlaveSelect(Comm_SPI_SLAVE_SELECT0);
    #endif /* (Comm_SPI_MASTER_CONST) */

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
* Function Name: Comm_SpiPostEnable
****************************************************************************//**
*
*  Restores HSIOM settings for the SPI master output pins (SCLK and/or SS0-SS3) 
*  to be controlled by the SCB SPI.
*
*******************************************************************************/
void Comm_SpiPostEnable(void)
{
#if(Comm_SCB_MODE_UNCONFIG_CONST_CFG)

    if (Comm_CHECK_SPI_MASTER)
    {
    #if (Comm_SCLK_PIN)
        /* Set SCB SPI to drive output pin */
        Comm_SET_HSIOM_SEL(Comm_SCLK_HSIOM_REG, Comm_SCLK_HSIOM_MASK,
                                       Comm_SCLK_HSIOM_POS, Comm_SCLK_HSIOM_SEL_SPI);
    #endif /* (Comm_SCLK_PIN) */

    #if (Comm_SS0_PIN)
        /* Set SCB SPI to drive output pin */
        Comm_SET_HSIOM_SEL(Comm_SS0_HSIOM_REG, Comm_SS0_HSIOM_MASK,
                                       Comm_SS0_HSIOM_POS, Comm_SS0_HSIOM_SEL_SPI);
    #endif /* (Comm_SS0_PIN) */

    #if (Comm_SS1_PIN)
        /* Set SCB SPI to drive output pin */
        Comm_SET_HSIOM_SEL(Comm_SS1_HSIOM_REG, Comm_SS1_HSIOM_MASK,
                                       Comm_SS1_HSIOM_POS, Comm_SS1_HSIOM_SEL_SPI);
    #endif /* (Comm_SS1_PIN) */

    #if (Comm_SS2_PIN)
        /* Set SCB SPI to drive output pin */
        Comm_SET_HSIOM_SEL(Comm_SS2_HSIOM_REG, Comm_SS2_HSIOM_MASK,
                                       Comm_SS2_HSIOM_POS, Comm_SS2_HSIOM_SEL_SPI);
    #endif /* (Comm_SS2_PIN) */

    #if (Comm_SS3_PIN)
        /* Set SCB SPI to drive output pin */
        Comm_SET_HSIOM_SEL(Comm_SS3_HSIOM_REG, Comm_SS3_HSIOM_MASK,
                                       Comm_SS3_HSIOM_POS, Comm_SS3_HSIOM_SEL_SPI);
    #endif /* (Comm_SS3_PIN) */
    }

#else

    #if (Comm_SPI_MASTER_SCLK_PIN)
        /* Set SCB SPI to drive output pin */
        Comm_SET_HSIOM_SEL(Comm_SCLK_M_HSIOM_REG, Comm_SCLK_M_HSIOM_MASK,
                                       Comm_SCLK_M_HSIOM_POS, Comm_SCLK_M_HSIOM_SEL_SPI);
    #endif /* (Comm_MISO_SDA_TX_PIN_PIN) */

    #if (Comm_SPI_MASTER_SS0_PIN)
        /* Set SCB SPI to drive output pin */
        Comm_SET_HSIOM_SEL(Comm_SS0_M_HSIOM_REG, Comm_SS0_M_HSIOM_MASK,
                                       Comm_SS0_M_HSIOM_POS, Comm_SS0_M_HSIOM_SEL_SPI);
    #endif /* (Comm_SPI_MASTER_SS0_PIN) */

    #if (Comm_SPI_MASTER_SS1_PIN)
        /* Set SCB SPI to drive output pin */
        Comm_SET_HSIOM_SEL(Comm_SS1_M_HSIOM_REG, Comm_SS1_M_HSIOM_MASK,
                                       Comm_SS1_M_HSIOM_POS, Comm_SS1_M_HSIOM_SEL_SPI);
    #endif /* (Comm_SPI_MASTER_SS1_PIN) */

    #if (Comm_SPI_MASTER_SS2_PIN)
        /* Set SCB SPI to drive output pin */
        Comm_SET_HSIOM_SEL(Comm_SS2_M_HSIOM_REG, Comm_SS2_M_HSIOM_MASK,
                                       Comm_SS2_M_HSIOM_POS, Comm_SS2_M_HSIOM_SEL_SPI);
    #endif /* (Comm_SPI_MASTER_SS2_PIN) */

    #if (Comm_SPI_MASTER_SS3_PIN)
        /* Set SCB SPI to drive output pin */
        Comm_SET_HSIOM_SEL(Comm_SS3_M_HSIOM_REG, Comm_SS3_M_HSIOM_MASK,
                                       Comm_SS3_M_HSIOM_POS, Comm_SS3_M_HSIOM_SEL_SPI);
    #endif /* (Comm_SPI_MASTER_SS3_PIN) */

#endif /* (Comm_SCB_MODE_UNCONFIG_CONST_CFG) */

    /* Restore TX interrupt sources. */
    Comm_SetTxInterruptMode(Comm_IntrTxMask);
}


/*******************************************************************************
* Function Name: Comm_SpiStop
****************************************************************************//**
*
*  Changes the HSIOM settings for the SPI master output pins 
*  (SCLK and/or SS0-SS3) to keep them inactive after the block is disabled. 
*  The output pins are controlled by the GPIO data register.
*
*******************************************************************************/
void Comm_SpiStop(void)
{
#if(Comm_SCB_MODE_UNCONFIG_CONST_CFG)

    if (Comm_CHECK_SPI_MASTER)
    {
    #if (Comm_SCLK_PIN)
        /* Set output pin state after block is disabled */
        Comm_spi_sclk_Write(Comm_GET_SPI_SCLK_INACTIVE);

        /* Set GPIO to drive output pin */
        Comm_SET_HSIOM_SEL(Comm_SCLK_HSIOM_REG, Comm_SCLK_HSIOM_MASK,
                                       Comm_SCLK_HSIOM_POS, Comm_SCLK_HSIOM_SEL_GPIO);
    #endif /* (Comm_spi_sclk_PIN) */

    #if (Comm_SS0_PIN)
        /* Set output pin state after block is disabled */
        Comm_spi_ss0_Write(Comm_GET_SPI_SS0_INACTIVE);

        /* Set GPIO to drive output pin */
        Comm_SET_HSIOM_SEL(Comm_SS0_HSIOM_REG, Comm_SS0_HSIOM_MASK,
                                       Comm_SS0_HSIOM_POS, Comm_SS0_HSIOM_SEL_GPIO);
    #endif /* (Comm_spi_ss0_PIN) */

    #if (Comm_SS1_PIN)
        /* Set output pin state after block is disabled */
        Comm_spi_ss1_Write(Comm_GET_SPI_SS1_INACTIVE);

        /* Set GPIO to drive output pin */
        Comm_SET_HSIOM_SEL(Comm_SS1_HSIOM_REG, Comm_SS1_HSIOM_MASK,
                                       Comm_SS1_HSIOM_POS, Comm_SS1_HSIOM_SEL_GPIO);
    #endif /* (Comm_SS1_PIN) */

    #if (Comm_SS2_PIN)
        /* Set output pin state after block is disabled */
        Comm_spi_ss2_Write(Comm_GET_SPI_SS2_INACTIVE);

        /* Set GPIO to drive output pin */
        Comm_SET_HSIOM_SEL(Comm_SS2_HSIOM_REG, Comm_SS2_HSIOM_MASK,
                                       Comm_SS2_HSIOM_POS, Comm_SS2_HSIOM_SEL_GPIO);
    #endif /* (Comm_SS2_PIN) */

    #if (Comm_SS3_PIN)
        /* Set output pin state after block is disabled */
        Comm_spi_ss3_Write(Comm_GET_SPI_SS3_INACTIVE);

        /* Set GPIO to drive output pin */
        Comm_SET_HSIOM_SEL(Comm_SS3_HSIOM_REG, Comm_SS3_HSIOM_MASK,
                                       Comm_SS3_HSIOM_POS, Comm_SS3_HSIOM_SEL_GPIO);
    #endif /* (Comm_SS3_PIN) */
    
        /* Store TX interrupt sources (exclude level triggered) for master. */
        Comm_IntrTxMask = LO16(Comm_GetTxInterruptMode() & Comm_INTR_SPIM_TX_RESTORE);
    }
    else
    {
        /* Store TX interrupt sources (exclude level triggered) for slave. */
        Comm_IntrTxMask = LO16(Comm_GetTxInterruptMode() & Comm_INTR_SPIS_TX_RESTORE);
    }

#else

#if (Comm_SPI_MASTER_SCLK_PIN)
    /* Set output pin state after block is disabled */
    Comm_sclk_m_Write(Comm_GET_SPI_SCLK_INACTIVE);

    /* Set GPIO to drive output pin */
    Comm_SET_HSIOM_SEL(Comm_SCLK_M_HSIOM_REG, Comm_SCLK_M_HSIOM_MASK,
                                   Comm_SCLK_M_HSIOM_POS, Comm_SCLK_M_HSIOM_SEL_GPIO);
#endif /* (Comm_MISO_SDA_TX_PIN_PIN) */

#if (Comm_SPI_MASTER_SS0_PIN)
    /* Set output pin state after block is disabled */
    Comm_ss0_m_Write(Comm_GET_SPI_SS0_INACTIVE);

    /* Set GPIO to drive output pin */
    Comm_SET_HSIOM_SEL(Comm_SS0_M_HSIOM_REG, Comm_SS0_M_HSIOM_MASK,
                                   Comm_SS0_M_HSIOM_POS, Comm_SS0_M_HSIOM_SEL_GPIO);
#endif /* (Comm_SPI_MASTER_SS0_PIN) */

#if (Comm_SPI_MASTER_SS1_PIN)
    /* Set output pin state after block is disabled */
    Comm_ss1_m_Write(Comm_GET_SPI_SS1_INACTIVE);

    /* Set GPIO to drive output pin */
    Comm_SET_HSIOM_SEL(Comm_SS1_M_HSIOM_REG, Comm_SS1_M_HSIOM_MASK,
                                   Comm_SS1_M_HSIOM_POS, Comm_SS1_M_HSIOM_SEL_GPIO);
#endif /* (Comm_SPI_MASTER_SS1_PIN) */

#if (Comm_SPI_MASTER_SS2_PIN)
    /* Set output pin state after block is disabled */
    Comm_ss2_m_Write(Comm_GET_SPI_SS2_INACTIVE);

    /* Set GPIO to drive output pin */
    Comm_SET_HSIOM_SEL(Comm_SS2_M_HSIOM_REG, Comm_SS2_M_HSIOM_MASK,
                                   Comm_SS2_M_HSIOM_POS, Comm_SS2_M_HSIOM_SEL_GPIO);
#endif /* (Comm_SPI_MASTER_SS2_PIN) */

#if (Comm_SPI_MASTER_SS3_PIN)
    /* Set output pin state after block is disabled */
    Comm_ss3_m_Write(Comm_GET_SPI_SS3_INACTIVE);

    /* Set GPIO to drive output pin */
    Comm_SET_HSIOM_SEL(Comm_SS3_M_HSIOM_REG, Comm_SS3_M_HSIOM_MASK,
                                   Comm_SS3_M_HSIOM_POS, Comm_SS3_M_HSIOM_SEL_GPIO);
#endif /* (Comm_SPI_MASTER_SS3_PIN) */

    #if (Comm_SPI_MASTER_CONST)
        /* Store TX interrupt sources (exclude level triggered). */
        Comm_IntrTxMask = LO16(Comm_GetTxInterruptMode() & Comm_INTR_SPIM_TX_RESTORE);
    #else
        /* Store TX interrupt sources (exclude level triggered). */
        Comm_IntrTxMask = LO16(Comm_GetTxInterruptMode() & Comm_INTR_SPIS_TX_RESTORE);
    #endif /* (Comm_SPI_MASTER_CONST) */

#endif /* (Comm_SCB_MODE_UNCONFIG_CONST_CFG) */
}


#if (Comm_SPI_MASTER_CONST)
    /*******************************************************************************
    * Function Name: Comm_SetActiveSlaveSelect
    ****************************************************************************//**
    *
    *  Selects one of the four slave select lines to be active during the transfer.
    *  After initialization the active slave select line is 0.
    *  The component should be in one of the following states to change the active
    *  slave select signal source correctly:
    *   - The component is disabled.
    *   - The component has completed transfer (TX FIFO is empty and the
    *     SCB_INTR_MASTER_SPI_DONE status is set).
    *
    *  This function does not check that these conditions are met.
    *  This function is only applicable to SPI Master mode of operation.
    *
    *  \param slaveSelect: slave select line which will be active while the following
    *   transfer.
    *   - Comm_SPI_SLAVE_SELECT0 - Slave select 0.
    *   - Comm_SPI_SLAVE_SELECT1 - Slave select 1.
    *   - Comm_SPI_SLAVE_SELECT2 - Slave select 2.
    *   - Comm_SPI_SLAVE_SELECT3 - Slave select 3.
    *
    *******************************************************************************/
    void Comm_SpiSetActiveSlaveSelect(uint32 slaveSelect)
    {
        uint32 spiCtrl;

        spiCtrl = Comm_SPI_CTRL_REG;

        spiCtrl &= (uint32) ~Comm_SPI_CTRL_SLAVE_SELECT_MASK;
        spiCtrl |= (uint32)  Comm_GET_SPI_CTRL_SS(slaveSelect);

        Comm_SPI_CTRL_REG = spiCtrl;
    }
#endif /* (Comm_SPI_MASTER_CONST) */


#if !(Comm_CY_SCBIP_V0 || Comm_CY_SCBIP_V1)
    /*******************************************************************************
    * Function Name: Comm_SpiSetSlaveSelectPolarity
    ****************************************************************************//**
    *
    *  Sets active polarity for slave select line.
    *  The component should be in one of the following states to change the active
    *  slave select signal source correctly:
    *   - The component is disabled.
    *   - The component has completed transfer.
    *  
    *  This function does not check that these conditions are met.
    *
    *  \param slaveSelect: slave select line to change active polarity.
    *   - Comm_SPI_SLAVE_SELECT0 - Slave select 0.
    *   - Comm_SPI_SLAVE_SELECT1 - Slave select 1.
    *   - Comm_SPI_SLAVE_SELECT2 - Slave select 2.
    *   - Comm_SPI_SLAVE_SELECT3 - Slave select 3.
    *
    *  \param polarity: active polarity of slave select line.
    *   - Comm_SPI_SS_ACTIVE_LOW  - Slave select is active low.
    *   - Comm_SPI_SS_ACTIVE_HIGH - Slave select is active high.
    *
    *******************************************************************************/
    void Comm_SpiSetSlaveSelectPolarity(uint32 slaveSelect, uint32 polarity)
    {
        uint32 ssPolarity;

        /* Get position of the polarity bit associated with slave select line */
        ssPolarity = Comm_GET_SPI_CTRL_SSEL_POLARITY((uint32) 1u << slaveSelect);

        if (0u != polarity)
        {
            Comm_SPI_CTRL_REG |= (uint32)  ssPolarity;
        }
        else
        {
            Comm_SPI_CTRL_REG &= (uint32) ~ssPolarity;
        }
    }
#endif /* !(Comm_CY_SCBIP_V0 || Comm_CY_SCBIP_V1) */


#if(Comm_SPI_WAKE_ENABLE_CONST)
    /*******************************************************************************
    * Function Name: Comm_SpiSaveConfig
    ****************************************************************************//**
    *
    *  Clears INTR_SPI_EC.WAKE_UP and enables it. This interrupt
    *  source triggers when the master assigns the SS line and wakes up the device.
    *
    *******************************************************************************/
    void Comm_SpiSaveConfig(void)
    {
        /* Clear and enable SPI wakeup interrupt source */
        Comm_ClearSpiExtClkInterruptSource(Comm_INTR_SPI_EC_WAKE_UP);
        Comm_SetSpiExtClkInterruptMode(Comm_INTR_SPI_EC_WAKE_UP);
    }


    /*******************************************************************************
    * Function Name: Comm_SpiRestoreConfig
    ****************************************************************************//**
    *
    *  Disables the INTR_SPI_EC.WAKE_UP interrupt source. After wakeup
    *  slave does not drive the MISO line and the master receives 0xFF.
    *
    *******************************************************************************/
    void Comm_SpiRestoreConfig(void)
    {
        /* Disable SPI wakeup interrupt source */
        Comm_SetSpiExtClkInterruptMode(Comm_NO_INTR_SOURCES);
    }
#endif /* (Comm_SPI_WAKE_ENABLE_CONST) */


/* [] END OF FILE */
