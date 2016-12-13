/***************************************************************************//**
* \file Comm_I2C.c
* \version 3.20
*
* \brief
*  This file provides the source code to the API for the SCB Component in
*  I2C mode.
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
#include "Comm_I2C_PVT.h"


/***************************************
*      I2C Private Vars
***************************************/

volatile uint8 Comm_state;  /* Current state of I2C FSM */

#if(Comm_SCB_MODE_UNCONFIG_CONST_CFG)

    /***************************************
    *  Configuration Structure Initialization
    ***************************************/

    /* Constant configuration of I2C */
    const Comm_I2C_INIT_STRUCT Comm_configI2C =
    {
        Comm_I2C_MODE,
        Comm_I2C_OVS_FACTOR_LOW,
        Comm_I2C_OVS_FACTOR_HIGH,
        Comm_I2C_MEDIAN_FILTER_ENABLE,
        Comm_I2C_SLAVE_ADDRESS,
        Comm_I2C_SLAVE_ADDRESS_MASK,
        Comm_I2C_ACCEPT_ADDRESS,
        Comm_I2C_WAKE_ENABLE,
        Comm_I2C_BYTE_MODE_ENABLE,
        Comm_I2C_DATA_RATE,
        Comm_I2C_ACCEPT_GENERAL_CALL,
    };

    /*******************************************************************************
    * Function Name: Comm_I2CInit
    ****************************************************************************//**
    *
    *
    *  Configures the Comm for I2C operation.
    *
    *  This function is intended specifically to be used when the Comm 
    *  configuration is set to “Unconfigured Comm” in the customizer. 
    *  After initializing the Comm in I2C mode using this function, 
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
    void Comm_I2CInit(const Comm_I2C_INIT_STRUCT *config)
    {
        uint32 medianFilter;
        uint32 locEnableWake;

        if(NULL == config)
        {
            CYASSERT(0u != 0u); /* Halt execution due to bad function parameter */
        }
        else
        {
            /* Configure pins */
            Comm_SetPins(Comm_SCB_MODE_I2C, Comm_DUMMY_PARAM,
                                     Comm_DUMMY_PARAM);

            /* Store internal configuration */
            Comm_scbMode       = (uint8) Comm_SCB_MODE_I2C;
            Comm_scbEnableWake = (uint8) config->enableWake;
            Comm_scbEnableIntr = (uint8) Comm_SCB_IRQ_INTERNAL;

            Comm_mode          = (uint8) config->mode;
            Comm_acceptAddr    = (uint8) config->acceptAddr;

        #if (Comm_CY_SCBIP_V0)
            /* Adjust SDA filter settings. Ticket ID#150521 */
            Comm_SET_I2C_CFG_SDA_FILT_TRIM(Comm_EC_AM_I2C_CFG_SDA_FILT_TRIM);
        #endif /* (Comm_CY_SCBIP_V0) */

            /* Adjust AF and DF filter settings. Ticket ID#176179 */
            if (((Comm_I2C_MODE_SLAVE != config->mode) &&
                 (config->dataRate <= Comm_I2C_DATA_RATE_FS_MODE_MAX)) ||
                 (Comm_I2C_MODE_SLAVE == config->mode))
            {
                /* AF = 1, DF = 0 */
                Comm_I2C_CFG_ANALOG_FITER_ENABLE;
                medianFilter = Comm_DIGITAL_FILTER_DISABLE;
            }
            else
            {
                /* AF = 0, DF = 1 */
                Comm_I2C_CFG_ANALOG_FITER_DISABLE;
                medianFilter = Comm_DIGITAL_FILTER_ENABLE;
            }

        #if (!Comm_CY_SCBIP_V0)
            locEnableWake = (Comm_I2C_MULTI_MASTER_SLAVE) ? (0u) : (config->enableWake);
        #else
            locEnableWake = config->enableWake;
        #endif /* (!Comm_CY_SCBIP_V0) */

            /* Configure I2C interface */
            Comm_CTRL_REG     = Comm_GET_CTRL_BYTE_MODE  (config->enableByteMode) |
                                            Comm_GET_CTRL_ADDR_ACCEPT(config->acceptAddr)     |
                                            Comm_GET_CTRL_EC_AM_MODE (locEnableWake);

            Comm_I2C_CTRL_REG = Comm_GET_I2C_CTRL_HIGH_PHASE_OVS(config->oversampleHigh) |
                    Comm_GET_I2C_CTRL_LOW_PHASE_OVS (config->oversampleLow)                          |
                    Comm_GET_I2C_CTRL_S_GENERAL_IGNORE((uint32)(0u == config->acceptGeneralAddr))    |
                    Comm_GET_I2C_CTRL_SL_MSTR_MODE  (config->mode);

            /* Configure RX direction */
            Comm_RX_CTRL_REG      = Comm_GET_RX_CTRL_MEDIAN(medianFilter) |
                                                Comm_I2C_RX_CTRL;
            Comm_RX_FIFO_CTRL_REG = Comm_CLEAR_REG;

            /* Set default address and mask */
            Comm_RX_MATCH_REG    = ((Comm_I2C_SLAVE) ?
                                                (Comm_GET_I2C_8BIT_ADDRESS(config->slaveAddr) |
                                                 Comm_GET_RX_MATCH_MASK(config->slaveAddrMask)) :
                                                (Comm_CLEAR_REG));


            /* Configure TX direction */
            Comm_TX_CTRL_REG      = Comm_I2C_TX_CTRL;
            Comm_TX_FIFO_CTRL_REG = Comm_CLEAR_REG;

            /* Configure interrupt with I2C handler but do not enable it */
            CyIntDisable    (Comm_ISR_NUMBER);
            CyIntSetPriority(Comm_ISR_NUMBER, Comm_ISR_PRIORITY);
            (void) CyIntSetVector(Comm_ISR_NUMBER, &Comm_I2C_ISR);

            /* Configure interrupt sources */
        #if(!Comm_CY_SCBIP_V1)
            Comm_INTR_SPI_EC_MASK_REG = Comm_NO_INTR_SOURCES;
        #endif /* (!Comm_CY_SCBIP_V1) */

            Comm_INTR_I2C_EC_MASK_REG = Comm_NO_INTR_SOURCES;
            Comm_INTR_RX_MASK_REG     = Comm_NO_INTR_SOURCES;
            Comm_INTR_TX_MASK_REG     = Comm_NO_INTR_SOURCES;

            Comm_INTR_SLAVE_MASK_REG  = ((Comm_I2C_SLAVE) ?
                            (Comm_GET_INTR_SLAVE_I2C_GENERAL(config->acceptGeneralAddr) |
                             Comm_I2C_INTR_SLAVE_MASK) : (Comm_CLEAR_REG));

            Comm_INTR_MASTER_MASK_REG = ((Comm_I2C_MASTER) ?
                                                     (Comm_I2C_INTR_MASTER_MASK) :
                                                     (Comm_CLEAR_REG));

            /* Configure global variables */
            Comm_state = Comm_I2C_FSM_IDLE;

            /* Internal slave variables */
            Comm_slStatus        = 0u;
            Comm_slRdBufIndex    = 0u;
            Comm_slWrBufIndex    = 0u;
            Comm_slOverFlowCount = 0u;

            /* Internal master variables */
            Comm_mstrStatus     = 0u;
            Comm_mstrRdBufIndex = 0u;
            Comm_mstrWrBufIndex = 0u;
        }
    }

#else

    /*******************************************************************************
    * Function Name: Comm_I2CInit
    ****************************************************************************//**
    *
    *  Configures the SCB for the I2C operation.
    *
    *******************************************************************************/
    void Comm_I2CInit(void)
    {
    #if(Comm_CY_SCBIP_V0)
        /* Adjust SDA filter settings. Ticket ID#150521 */
        Comm_SET_I2C_CFG_SDA_FILT_TRIM(Comm_EC_AM_I2C_CFG_SDA_FILT_TRIM);
    #endif /* (Comm_CY_SCBIP_V0) */

        /* Adjust AF and DF filter settings. Ticket ID#176179 */
        Comm_I2C_CFG_ANALOG_FITER_ENABLE_ADJ;

        /* Configure I2C interface */
        Comm_CTRL_REG     = Comm_I2C_DEFAULT_CTRL;
        Comm_I2C_CTRL_REG = Comm_I2C_DEFAULT_I2C_CTRL;

        /* Configure RX direction */
        Comm_RX_CTRL_REG      = Comm_I2C_DEFAULT_RX_CTRL;
        Comm_RX_FIFO_CTRL_REG = Comm_I2C_DEFAULT_RX_FIFO_CTRL;

        /* Set default address and mask */
        Comm_RX_MATCH_REG     = Comm_I2C_DEFAULT_RX_MATCH;

        /* Configure TX direction */
        Comm_TX_CTRL_REG      = Comm_I2C_DEFAULT_TX_CTRL;
        Comm_TX_FIFO_CTRL_REG = Comm_I2C_DEFAULT_TX_FIFO_CTRL;

        /* Configure interrupt with I2C handler but do not enable it */
        CyIntDisable    (Comm_ISR_NUMBER);
        CyIntSetPriority(Comm_ISR_NUMBER, Comm_ISR_PRIORITY);
    #if(!Comm_I2C_EXTERN_INTR_HANDLER)
        (void) CyIntSetVector(Comm_ISR_NUMBER, &Comm_I2C_ISR);
    #endif /* (Comm_I2C_EXTERN_INTR_HANDLER) */

        /* Configure interrupt sources */
    #if(!Comm_CY_SCBIP_V1)
        Comm_INTR_SPI_EC_MASK_REG = Comm_I2C_DEFAULT_INTR_SPI_EC_MASK;
    #endif /* (!Comm_CY_SCBIP_V1) */

        Comm_INTR_I2C_EC_MASK_REG = Comm_I2C_DEFAULT_INTR_I2C_EC_MASK;
        Comm_INTR_SLAVE_MASK_REG  = Comm_I2C_DEFAULT_INTR_SLAVE_MASK;
        Comm_INTR_MASTER_MASK_REG = Comm_I2C_DEFAULT_INTR_MASTER_MASK;
        Comm_INTR_RX_MASK_REG     = Comm_I2C_DEFAULT_INTR_RX_MASK;
        Comm_INTR_TX_MASK_REG     = Comm_I2C_DEFAULT_INTR_TX_MASK;

        /* Configure global variables */
        Comm_state = Comm_I2C_FSM_IDLE;

    #if(Comm_I2C_SLAVE)
        /* Internal slave variable */
        Comm_slStatus        = 0u;
        Comm_slRdBufIndex    = 0u;
        Comm_slWrBufIndex    = 0u;
        Comm_slOverFlowCount = 0u;
    #endif /* (Comm_I2C_SLAVE) */

    #if(Comm_I2C_MASTER)
    /* Internal master variable */
        Comm_mstrStatus     = 0u;
        Comm_mstrRdBufIndex = 0u;
        Comm_mstrWrBufIndex = 0u;
    #endif /* (Comm_I2C_MASTER) */
    }
#endif /* (Comm_SCB_MODE_UNCONFIG_CONST_CFG) */


/*******************************************************************************
* Function Name: Comm_I2CStop
****************************************************************************//**
*
*  Resets the I2C FSM into the default state.
*
*******************************************************************************/
void Comm_I2CStop(void)
{
    Comm_state = Comm_I2C_FSM_IDLE;
}


#if(Comm_I2C_WAKE_ENABLE_CONST)
    /*******************************************************************************
    * Function Name: Comm_I2CSaveConfig
    ****************************************************************************//**
    *
    *  Enables Comm_INTR_I2C_EC_WAKE_UP interrupt source. This interrupt
    *  triggers on address match and wakes up device.
    *
    *******************************************************************************/
    void Comm_I2CSaveConfig(void)
    {
    #if (!Comm_CY_SCBIP_V0)
        #if (Comm_I2C_MULTI_MASTER_SLAVE_CONST && Comm_I2C_WAKE_ENABLE_CONST)
            /* Enable externally clocked address match if it was not enabled before.
            * This applicable only for Multi-Master-Slave. Ticket ID#192742 */
            if (0u == (Comm_CTRL_REG & Comm_CTRL_EC_AM_MODE))
            {
                /* Enable external address match logic */
                Comm_Stop();
                Comm_CTRL_REG |= Comm_CTRL_EC_AM_MODE;
                Comm_Enable();
            }
        #endif /* (Comm_I2C_MULTI_MASTER_SLAVE_CONST) */

        #if (Comm_SCB_CLK_INTERNAL)
            /* Disable clock to internal address match logic. Ticket ID#187931 */
            Comm_SCBCLK_Stop();
        #endif /* (Comm_SCB_CLK_INTERNAL) */
    #endif /* (!Comm_CY_SCBIP_V0) */

        Comm_SetI2CExtClkInterruptMode(Comm_INTR_I2C_EC_WAKE_UP);
    }


    /*******************************************************************************
    * Function Name: Comm_I2CRestoreConfig
    ****************************************************************************//**
    *
    *  Disables Comm_INTR_I2C_EC_WAKE_UP interrupt source. This interrupt
    *  triggers on address match and wakes up device.
    *
    *******************************************************************************/
    void Comm_I2CRestoreConfig(void)
    {
        /* Disable wakeup interrupt on address match */
        Comm_SetI2CExtClkInterruptMode(Comm_NO_INTR_SOURCES);

    #if (!Comm_CY_SCBIP_V0)
        #if (Comm_SCB_CLK_INTERNAL)
            /* Enable clock to internal address match logic. Ticket ID#187931 */
            Comm_SCBCLK_Start();
        #endif /* (Comm_SCB_CLK_INTERNAL) */
    #endif /* (!Comm_CY_SCBIP_V0) */
    }
#endif /* (Comm_I2C_WAKE_ENABLE_CONST) */


/* [] END OF FILE */
