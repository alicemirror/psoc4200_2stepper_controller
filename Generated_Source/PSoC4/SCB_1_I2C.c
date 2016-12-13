/*******************************************************************************
* File Name: SCB_1_I2C.c
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

#include "SCB_1_I2C_PVT.h"


/**********************************
*      Variables
**********************************/

volatile uint8 SCB_1_state;          /* Current state of I2C FSM         */
volatile uint8 SCB_1_wakeupSource;   /* Defines if I2C was wakeup source */


/**********************************
*      Constant
**********************************/

/* Constant configuration of I2C */
const SCB_1_I2C_INIT_STRUCT SCB_1_configI2C =
{
    SCB_1_I2C_MODE,
    SCB_1_I2C_OVS_FACTOR_LOW,
    SCB_1_I2C_OVS_FACTOR_HIGH,
    SCB_1_I2C_MEDIAN_FILTER_ENABLE,
    SCB_1_I2C_SLAVE_ADDRESS,
    SCB_1_I2C_SLAVE_ADDRESS_MASK,
    SCB_1_I2C_ACCEPT_ADRESS,
    SCB_1_I2C_WAKE_ENABLE
};


/*******************************************************************************
* Function Name: SCB_1_I2CInit
********************************************************************************
*
* Summary:
*  Initializes I2C registers with initial values provided from customizer.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void SCB_1_I2CInit(SCB_1_I2C_INIT_STRUCT *config)
{
    /* Configure I2C interface */
    SCB_1_CTRL_REG = SCB_1_GET_CTRL_ADDR_ACCEPT(config->acceptAddr) |
                                SCB_1_GET_CTRL_EC_AM_MODE (config->enableWake) |
                                SCB_1_CTRL_I2C;

    SCB_1_I2C_CTRL_REG = (SCB_1_GET_I2C_CTRL_HIGH_PHASE_OVS(config->oversampleHigh) |
                                     SCB_1_GET_I2C_CTRL_LOW_PHASE_OVS (config->oversampleLow)  |
                                     SCB_1_GET_I2C_CTRL_SLAVE_MODE    (config->mode)           |
                                     SCB_1_GET_I2C_CTRL_MASTER_MODE   (config->mode)           |
                                     SCB_1_I2C_CTRL);

    /* Set default address and mask */
    if(SCB_1_I2C_SLAVE)
    {
        SCB_1_RX_MATCH_REG = SCB_1_GET_I2C_8BIT_ADDRESS(config->slaveAddr) |
                                        SCB_1_GET_RX_MATCH_MASK(config->slaveAddrMask);
    }

    /* Configure TX and RX direction */
    SCB_1_RX_CTRL_REG = SCB_1_GET_RX_CTRL_MEDIAN(config->enableMedianFilter) |
                                   SCB_1_I2C_RX_CTRL;

    SCB_1_TX_CTRL_REG = SCB_1_I2C_TX_CTRL;

    SCB_1_RX_FIFO_CTRL_REG = 0u;
    SCB_1_TX_FIFO_CTRL_REG = 0u;

    /* Configure interrupt sources */
    SCB_1_INTR_SPI_EC_MASK_REG = SCB_1_NO_INTR_SOURCES;
    SCB_1_INTR_RX_MASK_REG     = SCB_1_NO_INTR_SOURCES;
    SCB_1_INTR_TX_MASK_REG     = SCB_1_NO_INTR_SOURCES;

    if(SCB_1_I2C_SLAVE)
    {
        SCB_1_INTR_SLAVE_MASK_REG  = SCB_1_I2C_INTR_SLAVE_MASK;
    }

    if(SCB_1_I2C_MASTER)
    {
        SCB_1_INTR_MASTER_MASK_REG = SCB_1_I2C_INTR_MASTER_MASK;
    }

    /* Configure interrupt with I2C handler and enabled it */
    SCB_1_SCB_IRQ_StartEx(&SCB_1_I2C_ISR);

    /* Configure global veriables */
    SCB_1_state = SCB_1_I2C_FSM_IDLE;

    #if(SCB_1_I2C_SLAVE_CONST)
        SCB_1_slStatus        = 0u;
        SCB_1_slRdBufIndex    = 0u;
        SCB_1_slWrBufIndex    = 0u;
        SCB_1_slOverFlowCount = 0u;
    #endif /* (SCB_1_I2C_SLAVE_CONST) */

    #if(SCB_1_I2C_MASTER_CONST)
        SCB_1_mstrStatus     = 0u;
        SCB_1_mstrRdBufIndex = 0u;
        SCB_1_mstrWrBufIndex = 0u;
    #endif /* (SCB_1_I2C_MASTER_CONST) */


    #if(SCB_1_SCB_MODE_UNCFG_CONST_CFG)
        /* Configure pins */
        SCB_1_SetPins(SCB_1_SCB_MODE_I2C, 0u, 0u);

        /* Set internal configuration */
        SCB_1_scbMode = SCB_1_SCB_MODE_I2C;
        SCB_1_scbCfg  = (void *) config;

    #endif /* (SCB_1_SCB_MODE_UNCFG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: SCB_1_I2CStop
********************************************************************************
*
* Summary:
*  Initializes I2C registers with initial values provided from customizer.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*
*
*******************************************************************************/
void SCB_1_I2CStop(void)
{
    SCB_1_state = SCB_1_I2C_FSM_IDLE; /* FSM State -> FSM_IDLE */
    SCB_1_SCB_IRQ_ClearPending();
}


/*******************************************************************************
* Function Name: SCB_1_I2CSaveConfig
********************************************************************************
*
* Summary:
*  Initializes I2C registers with initial values provided from customizer.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*
*
*******************************************************************************/
CY_ISR(SCB_1_I2C_WAKEUP_ISR);
void SCB_1_I2CSaveConfig(void)
{
    if(SCB_1_I2C_WAKEUP)
    {
        SCB_1_backup.enableState = 0u;   /* Keep SCB enabled */

        /* Change interrupt handler to wakeup one */
        #if(SCB_1_INTERRUPT_MODE_INTERNAL)
            SCB_1_SCB_IRQ_Disable();
            SCB_1_SCB_IRQ_SetVector(&SCB_1_I2C_WAKEUP_ISR);
            SCB_1_SCB_IRQ_Enable();
        #endif /* (SCB_1_INTERRUPT_MODE_INTERNAL) */

        SCB_1_SetI2CExtClkInterruptMode(SCB_1_INTR_I2C_EC_WAKE_UP);
    }
}


/*******************************************************************************
* Function Name: SCB_1_I2CRestoreConfig
********************************************************************************
*
* Summary:
*  Initializes I2C registers with initial values provided from customizer.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  None
*
*******************************************************************************/
void SCB_1_I2CRestoreConfig(void)
{
    if(SCB_1_I2C_WAKEUP)
    {
        /* Change interrupt handler to common I2C */
        #if(SCB_1_INTERRUPT_MODE_INTERNAL)
            SCB_1_SCB_IRQ_Disable();
            SCB_1_SCB_IRQ_SetVector(&SCB_1_I2C_ISR);
            SCB_1_SCB_IRQ_Enable();
        #endif /* (SCB_1_INTERRUPT_MODE_INTERNAL) */
    }
}


/*******************************************************************************
* Function Name: SCB_1_SPI_WAKEUP_ISR
********************************************************************************
*
* Summary:
*  Empty interrupt handler to trigger after wakeup.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
CY_ISR(SCB_1_I2C_WAKEUP_ISR)
{
    if(SCB_1_CHECK_INTR_I2C_EC_MASKED(SCB_1_INTR_I2C_EC_WAKE_UP))
    {
        /* Disable interrupt after wakeup. It will be cleared by I2C_ISR */
        SCB_1_SetI2CExtClkInterruptMode(SCB_1_NO_INTR_SOURCES);
    }
    
    #if(SCB_1_INTERRUPT_MODE_INTERNAL)
        SCB_1_SCB_IRQ_Disable();
    #endif /* (SCB_1_INTERRUPT_MODE_INTERNAL) */
}


/* [] END OF FILE */
