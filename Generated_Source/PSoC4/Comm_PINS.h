/***************************************************************************//**
* \file Comm_PINS.h
* \version 3.20
*
* \brief
*  This file provides constants and parameter values for the pin components
*  buried into SCB Component.
*
* Note:
*
********************************************************************************
* \copyright
* Copyright 2013-2016, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_PINS_Comm_H)
#define CY_SCB_PINS_Comm_H

#include "cydevice_trm.h"
#include "cyfitter.h"
#include "cytypes.h"


/***************************************
*   Conditional Compilation Parameters
****************************************/

/* Unconfigured pins */
#define Comm_REMOVE_RX_WAKE_SCL_MOSI_PIN  (1u)
#define Comm_REMOVE_RX_SCL_MOSI_PIN      (0u)
#define Comm_REMOVE_TX_SDA_MISO_PIN      (0u)
#define Comm_REMOVE_SCLK_PIN      (1u)
#define Comm_REMOVE_SS0_PIN      (1u)
#define Comm_REMOVE_SS1_PIN                 (1u)
#define Comm_REMOVE_SS2_PIN                 (1u)
#define Comm_REMOVE_SS3_PIN                 (1u)

/* Mode defined pins */
#define Comm_REMOVE_I2C_PINS                (1u)
#define Comm_REMOVE_SPI_MASTER_PINS         (1u)
#define Comm_REMOVE_SPI_MASTER_SCLK_PIN     (1u)
#define Comm_REMOVE_SPI_MASTER_MOSI_PIN     (1u)
#define Comm_REMOVE_SPI_MASTER_MISO_PIN     (1u)
#define Comm_REMOVE_SPI_MASTER_SS0_PIN      (1u)
#define Comm_REMOVE_SPI_MASTER_SS1_PIN      (1u)
#define Comm_REMOVE_SPI_MASTER_SS2_PIN      (1u)
#define Comm_REMOVE_SPI_MASTER_SS3_PIN      (1u)
#define Comm_REMOVE_SPI_SLAVE_PINS          (1u)
#define Comm_REMOVE_SPI_SLAVE_MOSI_PIN      (1u)
#define Comm_REMOVE_SPI_SLAVE_MISO_PIN      (1u)
#define Comm_REMOVE_UART_TX_PIN             (1u)
#define Comm_REMOVE_UART_RX_TX_PIN          (1u)
#define Comm_REMOVE_UART_RX_PIN             (1u)
#define Comm_REMOVE_UART_RX_WAKE_PIN        (1u)
#define Comm_REMOVE_UART_RTS_PIN            (1u)
#define Comm_REMOVE_UART_CTS_PIN            (1u)

/* Unconfigured pins */
#define Comm_RX_WAKE_SCL_MOSI_PIN (0u == Comm_REMOVE_RX_WAKE_SCL_MOSI_PIN)
#define Comm_RX_SCL_MOSI_PIN     (0u == Comm_REMOVE_RX_SCL_MOSI_PIN)
#define Comm_TX_SDA_MISO_PIN     (0u == Comm_REMOVE_TX_SDA_MISO_PIN)
#define Comm_SCLK_PIN     (0u == Comm_REMOVE_SCLK_PIN)
#define Comm_SS0_PIN     (0u == Comm_REMOVE_SS0_PIN)
#define Comm_SS1_PIN                (0u == Comm_REMOVE_SS1_PIN)
#define Comm_SS2_PIN                (0u == Comm_REMOVE_SS2_PIN)
#define Comm_SS3_PIN                (0u == Comm_REMOVE_SS3_PIN)

/* Mode defined pins */
#define Comm_I2C_PINS               (0u == Comm_REMOVE_I2C_PINS)
#define Comm_SPI_MASTER_PINS        (0u == Comm_REMOVE_SPI_MASTER_PINS)
#define Comm_SPI_MASTER_SCLK_PIN    (0u == Comm_REMOVE_SPI_MASTER_SCLK_PIN)
#define Comm_SPI_MASTER_MOSI_PIN    (0u == Comm_REMOVE_SPI_MASTER_MOSI_PIN)
#define Comm_SPI_MASTER_MISO_PIN    (0u == Comm_REMOVE_SPI_MASTER_MISO_PIN)
#define Comm_SPI_MASTER_SS0_PIN     (0u == Comm_REMOVE_SPI_MASTER_SS0_PIN)
#define Comm_SPI_MASTER_SS1_PIN     (0u == Comm_REMOVE_SPI_MASTER_SS1_PIN)
#define Comm_SPI_MASTER_SS2_PIN     (0u == Comm_REMOVE_SPI_MASTER_SS2_PIN)
#define Comm_SPI_MASTER_SS3_PIN     (0u == Comm_REMOVE_SPI_MASTER_SS3_PIN)
#define Comm_SPI_SLAVE_PINS         (0u == Comm_REMOVE_SPI_SLAVE_PINS)
#define Comm_SPI_SLAVE_MOSI_PIN     (0u == Comm_REMOVE_SPI_SLAVE_MOSI_PIN)
#define Comm_SPI_SLAVE_MISO_PIN     (0u == Comm_REMOVE_SPI_SLAVE_MISO_PIN)
#define Comm_UART_TX_PIN            (0u == Comm_REMOVE_UART_TX_PIN)
#define Comm_UART_RX_TX_PIN         (0u == Comm_REMOVE_UART_RX_TX_PIN)
#define Comm_UART_RX_PIN            (0u == Comm_REMOVE_UART_RX_PIN)
#define Comm_UART_RX_WAKE_PIN       (0u == Comm_REMOVE_UART_RX_WAKE_PIN)
#define Comm_UART_RTS_PIN           (0u == Comm_REMOVE_UART_RTS_PIN)
#define Comm_UART_CTS_PIN           (0u == Comm_REMOVE_UART_CTS_PIN)


/***************************************
*             Includes
****************************************/

#if (Comm_RX_WAKE_SCL_MOSI_PIN)
    #include "Comm_uart_rx_wake_i2c_scl_spi_mosi.h"
#endif /* (Comm_RX_SCL_MOSI) */

#if (Comm_RX_SCL_MOSI_PIN)
    #include "Comm_uart_rx_i2c_scl_spi_mosi.h"
#endif /* (Comm_RX_SCL_MOSI) */

#if (Comm_TX_SDA_MISO_PIN)
    #include "Comm_uart_tx_i2c_sda_spi_miso.h"
#endif /* (Comm_TX_SDA_MISO) */

#if (Comm_SCLK_PIN)
    #include "Comm_spi_sclk.h"
#endif /* (Comm_SCLK) */

#if (Comm_SS0_PIN)
    #include "Comm_spi_ss0.h"
#endif /* (Comm_SS0_PIN) */

#if (Comm_SS1_PIN)
    #include "Comm_spi_ss1.h"
#endif /* (Comm_SS1_PIN) */

#if (Comm_SS2_PIN)
    #include "Comm_spi_ss2.h"
#endif /* (Comm_SS2_PIN) */

#if (Comm_SS3_PIN)
    #include "Comm_spi_ss3.h"
#endif /* (Comm_SS3_PIN) */

#if (Comm_I2C_PINS)
    #include "Comm_scl.h"
    #include "Comm_sda.h"
#endif /* (Comm_I2C_PINS) */

#if (Comm_SPI_MASTER_PINS)
#if (Comm_SPI_MASTER_SCLK_PIN)
    #include "Comm_sclk_m.h"
#endif /* (Comm_SPI_MASTER_SCLK_PIN) */

#if (Comm_SPI_MASTER_MOSI_PIN)
    #include "Comm_mosi_m.h"
#endif /* (Comm_SPI_MASTER_MOSI_PIN) */

#if (Comm_SPI_MASTER_MISO_PIN)
    #include "Comm_miso_m.h"
#endif /*(Comm_SPI_MASTER_MISO_PIN) */
#endif /* (Comm_SPI_MASTER_PINS) */

#if (Comm_SPI_SLAVE_PINS)
    #include "Comm_sclk_s.h"
    #include "Comm_ss_s.h"

#if (Comm_SPI_SLAVE_MOSI_PIN)
    #include "Comm_mosi_s.h"
#endif /* (Comm_SPI_SLAVE_MOSI_PIN) */

#if (Comm_SPI_SLAVE_MISO_PIN)
    #include "Comm_miso_s.h"
#endif /*(Comm_SPI_SLAVE_MISO_PIN) */
#endif /* (Comm_SPI_SLAVE_PINS) */

#if (Comm_SPI_MASTER_SS0_PIN)
    #include "Comm_ss0_m.h"
#endif /* (Comm_SPI_MASTER_SS0_PIN) */

#if (Comm_SPI_MASTER_SS1_PIN)
    #include "Comm_ss1_m.h"
#endif /* (Comm_SPI_MASTER_SS1_PIN) */

#if (Comm_SPI_MASTER_SS2_PIN)
    #include "Comm_ss2_m.h"
#endif /* (Comm_SPI_MASTER_SS2_PIN) */

#if (Comm_SPI_MASTER_SS3_PIN)
    #include "Comm_ss3_m.h"
#endif /* (Comm_SPI_MASTER_SS3_PIN) */

#if (Comm_UART_TX_PIN)
    #include "Comm_tx.h"
#endif /* (Comm_UART_TX_PIN) */

#if (Comm_UART_RX_TX_PIN)
    #include "Comm_rx_tx.h"
#endif /* (Comm_UART_RX_TX_PIN) */

#if (Comm_UART_RX_PIN)
    #include "Comm_rx.h"
#endif /* (Comm_UART_RX_PIN) */

#if (Comm_UART_RX_WAKE_PIN)
    #include "Comm_rx_wake.h"
#endif /* (Comm_UART_RX_WAKE_PIN) */

#if (Comm_UART_RTS_PIN)
    #include "Comm_rts.h"
#endif /* (Comm_UART_RTS_PIN) */

#if (Comm_UART_CTS_PIN)
    #include "Comm_cts.h"
#endif /* (Comm_UART_CTS_PIN) */


/***************************************
*              Registers
***************************************/

#if (Comm_RX_SCL_MOSI_PIN)
    #define Comm_RX_SCL_MOSI_HSIOM_REG   (*(reg32 *) Comm_uart_rx_i2c_scl_spi_mosi__0__HSIOM)
    #define Comm_RX_SCL_MOSI_HSIOM_PTR   ( (reg32 *) Comm_uart_rx_i2c_scl_spi_mosi__0__HSIOM)
    
    #define Comm_RX_SCL_MOSI_HSIOM_MASK      (Comm_uart_rx_i2c_scl_spi_mosi__0__HSIOM_MASK)
    #define Comm_RX_SCL_MOSI_HSIOM_POS       (Comm_uart_rx_i2c_scl_spi_mosi__0__HSIOM_SHIFT)
    #define Comm_RX_SCL_MOSI_HSIOM_SEL_GPIO  (Comm_uart_rx_i2c_scl_spi_mosi__0__HSIOM_GPIO)
    #define Comm_RX_SCL_MOSI_HSIOM_SEL_I2C   (Comm_uart_rx_i2c_scl_spi_mosi__0__HSIOM_I2C)
    #define Comm_RX_SCL_MOSI_HSIOM_SEL_SPI   (Comm_uart_rx_i2c_scl_spi_mosi__0__HSIOM_SPI)
    #define Comm_RX_SCL_MOSI_HSIOM_SEL_UART  (Comm_uart_rx_i2c_scl_spi_mosi__0__HSIOM_UART)
    
#elif (Comm_RX_WAKE_SCL_MOSI_PIN)
    #define Comm_RX_WAKE_SCL_MOSI_HSIOM_REG   (*(reg32 *) Comm_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM)
    #define Comm_RX_WAKE_SCL_MOSI_HSIOM_PTR   ( (reg32 *) Comm_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM)
    
    #define Comm_RX_WAKE_SCL_MOSI_HSIOM_MASK      (Comm_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_MASK)
    #define Comm_RX_WAKE_SCL_MOSI_HSIOM_POS       (Comm_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_SHIFT)
    #define Comm_RX_WAKE_SCL_MOSI_HSIOM_SEL_GPIO  (Comm_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_GPIO)
    #define Comm_RX_WAKE_SCL_MOSI_HSIOM_SEL_I2C   (Comm_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_I2C)
    #define Comm_RX_WAKE_SCL_MOSI_HSIOM_SEL_SPI   (Comm_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_SPI)
    #define Comm_RX_WAKE_SCL_MOSI_HSIOM_SEL_UART  (Comm_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_UART)    
   
    #define Comm_RX_WAKE_SCL_MOSI_INTCFG_REG (*(reg32 *) Comm_uart_rx_wake_i2c_scl_spi_mosi__0__INTCFG)
    #define Comm_RX_WAKE_SCL_MOSI_INTCFG_PTR ( (reg32 *) Comm_uart_rx_wake_i2c_scl_spi_mosi__0__INTCFG)
    #define Comm_RX_WAKE_SCL_MOSI_INTCFG_TYPE_POS  (Comm_uart_rx_wake_i2c_scl_spi_mosi__SHIFT)
    #define Comm_RX_WAKE_SCL_MOSI_INTCFG_TYPE_MASK ((uint32) Comm_INTCFG_TYPE_MASK << \
                                                                           Comm_RX_WAKE_SCL_MOSI_INTCFG_TYPE_POS)
#else
    /* None of pins Comm_RX_SCL_MOSI_PIN or Comm_RX_WAKE_SCL_MOSI_PIN present.*/
#endif /* (Comm_RX_SCL_MOSI_PIN) */

#if (Comm_TX_SDA_MISO_PIN)
    #define Comm_TX_SDA_MISO_HSIOM_REG   (*(reg32 *) Comm_uart_tx_i2c_sda_spi_miso__0__HSIOM)
    #define Comm_TX_SDA_MISO_HSIOM_PTR   ( (reg32 *) Comm_uart_tx_i2c_sda_spi_miso__0__HSIOM)
    
    #define Comm_TX_SDA_MISO_HSIOM_MASK      (Comm_uart_tx_i2c_sda_spi_miso__0__HSIOM_MASK)
    #define Comm_TX_SDA_MISO_HSIOM_POS       (Comm_uart_tx_i2c_sda_spi_miso__0__HSIOM_SHIFT)
    #define Comm_TX_SDA_MISO_HSIOM_SEL_GPIO  (Comm_uart_tx_i2c_sda_spi_miso__0__HSIOM_GPIO)
    #define Comm_TX_SDA_MISO_HSIOM_SEL_I2C   (Comm_uart_tx_i2c_sda_spi_miso__0__HSIOM_I2C)
    #define Comm_TX_SDA_MISO_HSIOM_SEL_SPI   (Comm_uart_tx_i2c_sda_spi_miso__0__HSIOM_SPI)
    #define Comm_TX_SDA_MISO_HSIOM_SEL_UART  (Comm_uart_tx_i2c_sda_spi_miso__0__HSIOM_UART)
#endif /* (Comm_TX_SDA_MISO_PIN) */

#if (Comm_SCLK_PIN)
    #define Comm_SCLK_HSIOM_REG   (*(reg32 *) Comm_spi_sclk__0__HSIOM)
    #define Comm_SCLK_HSIOM_PTR   ( (reg32 *) Comm_spi_sclk__0__HSIOM)
    
    #define Comm_SCLK_HSIOM_MASK      (Comm_spi_sclk__0__HSIOM_MASK)
    #define Comm_SCLK_HSIOM_POS       (Comm_spi_sclk__0__HSIOM_SHIFT)
    #define Comm_SCLK_HSIOM_SEL_GPIO  (Comm_spi_sclk__0__HSIOM_GPIO)
    #define Comm_SCLK_HSIOM_SEL_I2C   (Comm_spi_sclk__0__HSIOM_I2C)
    #define Comm_SCLK_HSIOM_SEL_SPI   (Comm_spi_sclk__0__HSIOM_SPI)
    #define Comm_SCLK_HSIOM_SEL_UART  (Comm_spi_sclk__0__HSIOM_UART)
#endif /* (Comm_SCLK_PIN) */

#if (Comm_SS0_PIN)
    #define Comm_SS0_HSIOM_REG   (*(reg32 *) Comm_spi_ss0__0__HSIOM)
    #define Comm_SS0_HSIOM_PTR   ( (reg32 *) Comm_spi_ss0__0__HSIOM)
    
    #define Comm_SS0_HSIOM_MASK      (Comm_spi_ss0__0__HSIOM_MASK)
    #define Comm_SS0_HSIOM_POS       (Comm_spi_ss0__0__HSIOM_SHIFT)
    #define Comm_SS0_HSIOM_SEL_GPIO  (Comm_spi_ss0__0__HSIOM_GPIO)
    #define Comm_SS0_HSIOM_SEL_I2C   (Comm_spi_ss0__0__HSIOM_I2C)
    #define Comm_SS0_HSIOM_SEL_SPI   (Comm_spi_ss0__0__HSIOM_SPI)
#if !(Comm_CY_SCBIP_V0 || Comm_CY_SCBIP_V1)
    #define Comm_SS0_HSIOM_SEL_UART  (Comm_spi_ss0__0__HSIOM_UART)
#endif /* !(Comm_CY_SCBIP_V0 || Comm_CY_SCBIP_V1) */
#endif /* (Comm_SS0_PIN) */

#if (Comm_SS1_PIN)
    #define Comm_SS1_HSIOM_REG  (*(reg32 *) Comm_spi_ss1__0__HSIOM)
    #define Comm_SS1_HSIOM_PTR  ( (reg32 *) Comm_spi_ss1__0__HSIOM)
    
    #define Comm_SS1_HSIOM_MASK     (Comm_spi_ss1__0__HSIOM_MASK)
    #define Comm_SS1_HSIOM_POS      (Comm_spi_ss1__0__HSIOM_SHIFT)
    #define Comm_SS1_HSIOM_SEL_GPIO (Comm_spi_ss1__0__HSIOM_GPIO)
    #define Comm_SS1_HSIOM_SEL_I2C  (Comm_spi_ss1__0__HSIOM_I2C)
    #define Comm_SS1_HSIOM_SEL_SPI  (Comm_spi_ss1__0__HSIOM_SPI)
#endif /* (Comm_SS1_PIN) */

#if (Comm_SS2_PIN)
    #define Comm_SS2_HSIOM_REG     (*(reg32 *) Comm_spi_ss2__0__HSIOM)
    #define Comm_SS2_HSIOM_PTR     ( (reg32 *) Comm_spi_ss2__0__HSIOM)
    
    #define Comm_SS2_HSIOM_MASK     (Comm_spi_ss2__0__HSIOM_MASK)
    #define Comm_SS2_HSIOM_POS      (Comm_spi_ss2__0__HSIOM_SHIFT)
    #define Comm_SS2_HSIOM_SEL_GPIO (Comm_spi_ss2__0__HSIOM_GPIO)
    #define Comm_SS2_HSIOM_SEL_I2C  (Comm_spi_ss2__0__HSIOM_I2C)
    #define Comm_SS2_HSIOM_SEL_SPI  (Comm_spi_ss2__0__HSIOM_SPI)
#endif /* (Comm_SS2_PIN) */

#if (Comm_SS3_PIN)
    #define Comm_SS3_HSIOM_REG     (*(reg32 *) Comm_spi_ss3__0__HSIOM)
    #define Comm_SS3_HSIOM_PTR     ( (reg32 *) Comm_spi_ss3__0__HSIOM)
    
    #define Comm_SS3_HSIOM_MASK     (Comm_spi_ss3__0__HSIOM_MASK)
    #define Comm_SS3_HSIOM_POS      (Comm_spi_ss3__0__HSIOM_SHIFT)
    #define Comm_SS3_HSIOM_SEL_GPIO (Comm_spi_ss3__0__HSIOM_GPIO)
    #define Comm_SS3_HSIOM_SEL_I2C  (Comm_spi_ss3__0__HSIOM_I2C)
    #define Comm_SS3_HSIOM_SEL_SPI  (Comm_spi_ss3__0__HSIOM_SPI)
#endif /* (Comm_SS3_PIN) */

#if (Comm_I2C_PINS)
    #define Comm_SCL_HSIOM_REG  (*(reg32 *) Comm_scl__0__HSIOM)
    #define Comm_SCL_HSIOM_PTR  ( (reg32 *) Comm_scl__0__HSIOM)
    
    #define Comm_SCL_HSIOM_MASK     (Comm_scl__0__HSIOM_MASK)
    #define Comm_SCL_HSIOM_POS      (Comm_scl__0__HSIOM_SHIFT)
    #define Comm_SCL_HSIOM_SEL_GPIO (Comm_sda__0__HSIOM_GPIO)
    #define Comm_SCL_HSIOM_SEL_I2C  (Comm_sda__0__HSIOM_I2C)
    
    #define Comm_SDA_HSIOM_REG  (*(reg32 *) Comm_sda__0__HSIOM)
    #define Comm_SDA_HSIOM_PTR  ( (reg32 *) Comm_sda__0__HSIOM)
    
    #define Comm_SDA_HSIOM_MASK     (Comm_sda__0__HSIOM_MASK)
    #define Comm_SDA_HSIOM_POS      (Comm_sda__0__HSIOM_SHIFT)
    #define Comm_SDA_HSIOM_SEL_GPIO (Comm_sda__0__HSIOM_GPIO)
    #define Comm_SDA_HSIOM_SEL_I2C  (Comm_sda__0__HSIOM_I2C)
#endif /* (Comm_I2C_PINS) */

#if (Comm_SPI_SLAVE_PINS)
    #define Comm_SCLK_S_HSIOM_REG   (*(reg32 *) Comm_sclk_s__0__HSIOM)
    #define Comm_SCLK_S_HSIOM_PTR   ( (reg32 *) Comm_sclk_s__0__HSIOM)
    
    #define Comm_SCLK_S_HSIOM_MASK      (Comm_sclk_s__0__HSIOM_MASK)
    #define Comm_SCLK_S_HSIOM_POS       (Comm_sclk_s__0__HSIOM_SHIFT)
    #define Comm_SCLK_S_HSIOM_SEL_GPIO  (Comm_sclk_s__0__HSIOM_GPIO)
    #define Comm_SCLK_S_HSIOM_SEL_SPI   (Comm_sclk_s__0__HSIOM_SPI)
    
    #define Comm_SS0_S_HSIOM_REG    (*(reg32 *) Comm_ss0_s__0__HSIOM)
    #define Comm_SS0_S_HSIOM_PTR    ( (reg32 *) Comm_ss0_s__0__HSIOM)
    
    #define Comm_SS0_S_HSIOM_MASK       (Comm_ss0_s__0__HSIOM_MASK)
    #define Comm_SS0_S_HSIOM_POS        (Comm_ss0_s__0__HSIOM_SHIFT)
    #define Comm_SS0_S_HSIOM_SEL_GPIO   (Comm_ss0_s__0__HSIOM_GPIO)  
    #define Comm_SS0_S_HSIOM_SEL_SPI    (Comm_ss0_s__0__HSIOM_SPI)
#endif /* (Comm_SPI_SLAVE_PINS) */

#if (Comm_SPI_SLAVE_MOSI_PIN)
    #define Comm_MOSI_S_HSIOM_REG   (*(reg32 *) Comm_mosi_s__0__HSIOM)
    #define Comm_MOSI_S_HSIOM_PTR   ( (reg32 *) Comm_mosi_s__0__HSIOM)
    
    #define Comm_MOSI_S_HSIOM_MASK      (Comm_mosi_s__0__HSIOM_MASK)
    #define Comm_MOSI_S_HSIOM_POS       (Comm_mosi_s__0__HSIOM_SHIFT)
    #define Comm_MOSI_S_HSIOM_SEL_GPIO  (Comm_mosi_s__0__HSIOM_GPIO)
    #define Comm_MOSI_S_HSIOM_SEL_SPI   (Comm_mosi_s__0__HSIOM_SPI)
#endif /* (Comm_SPI_SLAVE_MOSI_PIN) */

#if (Comm_SPI_SLAVE_MISO_PIN)
    #define Comm_MISO_S_HSIOM_REG   (*(reg32 *) Comm_miso_s__0__HSIOM)
    #define Comm_MISO_S_HSIOM_PTR   ( (reg32 *) Comm_miso_s__0__HSIOM)
    
    #define Comm_MISO_S_HSIOM_MASK      (Comm_miso_s__0__HSIOM_MASK)
    #define Comm_MISO_S_HSIOM_POS       (Comm_miso_s__0__HSIOM_SHIFT)
    #define Comm_MISO_S_HSIOM_SEL_GPIO  (Comm_miso_s__0__HSIOM_GPIO)
    #define Comm_MISO_S_HSIOM_SEL_SPI   (Comm_miso_s__0__HSIOM_SPI)
#endif /* (Comm_SPI_SLAVE_MISO_PIN) */

#if (Comm_SPI_MASTER_MISO_PIN)
    #define Comm_MISO_M_HSIOM_REG   (*(reg32 *) Comm_miso_m__0__HSIOM)
    #define Comm_MISO_M_HSIOM_PTR   ( (reg32 *) Comm_miso_m__0__HSIOM)
    
    #define Comm_MISO_M_HSIOM_MASK      (Comm_miso_m__0__HSIOM_MASK)
    #define Comm_MISO_M_HSIOM_POS       (Comm_miso_m__0__HSIOM_SHIFT)
    #define Comm_MISO_M_HSIOM_SEL_GPIO  (Comm_miso_m__0__HSIOM_GPIO)
    #define Comm_MISO_M_HSIOM_SEL_SPI   (Comm_miso_m__0__HSIOM_SPI)
#endif /* (Comm_SPI_MASTER_MISO_PIN) */

#if (Comm_SPI_MASTER_MOSI_PIN)
    #define Comm_MOSI_M_HSIOM_REG   (*(reg32 *) Comm_mosi_m__0__HSIOM)
    #define Comm_MOSI_M_HSIOM_PTR   ( (reg32 *) Comm_mosi_m__0__HSIOM)
    
    #define Comm_MOSI_M_HSIOM_MASK      (Comm_mosi_m__0__HSIOM_MASK)
    #define Comm_MOSI_M_HSIOM_POS       (Comm_mosi_m__0__HSIOM_SHIFT)
    #define Comm_MOSI_M_HSIOM_SEL_GPIO  (Comm_mosi_m__0__HSIOM_GPIO)
    #define Comm_MOSI_M_HSIOM_SEL_SPI   (Comm_mosi_m__0__HSIOM_SPI)
#endif /* (Comm_SPI_MASTER_MOSI_PIN) */

#if (Comm_SPI_MASTER_SCLK_PIN)
    #define Comm_SCLK_M_HSIOM_REG   (*(reg32 *) Comm_sclk_m__0__HSIOM)
    #define Comm_SCLK_M_HSIOM_PTR   ( (reg32 *) Comm_sclk_m__0__HSIOM)
    
    #define Comm_SCLK_M_HSIOM_MASK      (Comm_sclk_m__0__HSIOM_MASK)
    #define Comm_SCLK_M_HSIOM_POS       (Comm_sclk_m__0__HSIOM_SHIFT)
    #define Comm_SCLK_M_HSIOM_SEL_GPIO  (Comm_sclk_m__0__HSIOM_GPIO)
    #define Comm_SCLK_M_HSIOM_SEL_SPI   (Comm_sclk_m__0__HSIOM_SPI)
#endif /* (Comm_SPI_MASTER_SCLK_PIN) */

#if (Comm_SPI_MASTER_SS0_PIN)
    #define Comm_SS0_M_HSIOM_REG    (*(reg32 *) Comm_ss0_m__0__HSIOM)
    #define Comm_SS0_M_HSIOM_PTR    ( (reg32 *) Comm_ss0_m__0__HSIOM)
    
    #define Comm_SS0_M_HSIOM_MASK       (Comm_ss0_m__0__HSIOM_MASK)
    #define Comm_SS0_M_HSIOM_POS        (Comm_ss0_m__0__HSIOM_SHIFT)
    #define Comm_SS0_M_HSIOM_SEL_GPIO   (Comm_ss0_m__0__HSIOM_GPIO)
    #define Comm_SS0_M_HSIOM_SEL_SPI    (Comm_ss0_m__0__HSIOM_SPI)
#endif /* (Comm_SPI_MASTER_SS0_PIN) */

#if (Comm_SPI_MASTER_SS1_PIN)
    #define Comm_SS1_M_HSIOM_REG    (*(reg32 *) Comm_ss1_m__0__HSIOM)
    #define Comm_SS1_M_HSIOM_PTR    ( (reg32 *) Comm_ss1_m__0__HSIOM)
    
    #define Comm_SS1_M_HSIOM_MASK       (Comm_ss1_m__0__HSIOM_MASK)
    #define Comm_SS1_M_HSIOM_POS        (Comm_ss1_m__0__HSIOM_SHIFT)
    #define Comm_SS1_M_HSIOM_SEL_GPIO   (Comm_ss1_m__0__HSIOM_GPIO)
    #define Comm_SS1_M_HSIOM_SEL_SPI    (Comm_ss1_m__0__HSIOM_SPI)
#endif /* (Comm_SPI_MASTER_SS1_PIN) */

#if (Comm_SPI_MASTER_SS2_PIN)
    #define Comm_SS2_M_HSIOM_REG    (*(reg32 *) Comm_ss2_m__0__HSIOM)
    #define Comm_SS2_M_HSIOM_PTR    ( (reg32 *) Comm_ss2_m__0__HSIOM)
    
    #define Comm_SS2_M_HSIOM_MASK       (Comm_ss2_m__0__HSIOM_MASK)
    #define Comm_SS2_M_HSIOM_POS        (Comm_ss2_m__0__HSIOM_SHIFT)
    #define Comm_SS2_M_HSIOM_SEL_GPIO   (Comm_ss2_m__0__HSIOM_GPIO)
    #define Comm_SS2_M_HSIOM_SEL_SPI    (Comm_ss2_m__0__HSIOM_SPI)
#endif /* (Comm_SPI_MASTER_SS2_PIN) */

#if (Comm_SPI_MASTER_SS3_PIN)
    #define Comm_SS3_M_HSIOM_REG    (*(reg32 *) Comm_ss3_m__0__HSIOM)
    #define Comm_SS3_M_HSIOM_PTR    ( (reg32 *) Comm_ss3_m__0__HSIOM)
    
    #define Comm_SS3_M_HSIOM_MASK      (Comm_ss3_m__0__HSIOM_MASK)
    #define Comm_SS3_M_HSIOM_POS       (Comm_ss3_m__0__HSIOM_SHIFT)
    #define Comm_SS3_M_HSIOM_SEL_GPIO  (Comm_ss3_m__0__HSIOM_GPIO)
    #define Comm_SS3_M_HSIOM_SEL_SPI   (Comm_ss3_m__0__HSIOM_SPI)
#endif /* (Comm_SPI_MASTER_SS3_PIN) */

#if (Comm_UART_RX_PIN)
    #define Comm_RX_HSIOM_REG   (*(reg32 *) Comm_rx__0__HSIOM)
    #define Comm_RX_HSIOM_PTR   ( (reg32 *) Comm_rx__0__HSIOM)
    
    #define Comm_RX_HSIOM_MASK      (Comm_rx__0__HSIOM_MASK)
    #define Comm_RX_HSIOM_POS       (Comm_rx__0__HSIOM_SHIFT)
    #define Comm_RX_HSIOM_SEL_GPIO  (Comm_rx__0__HSIOM_GPIO)
    #define Comm_RX_HSIOM_SEL_UART  (Comm_rx__0__HSIOM_UART)
#endif /* (Comm_UART_RX_PIN) */

#if (Comm_UART_RX_WAKE_PIN)
    #define Comm_RX_WAKE_HSIOM_REG   (*(reg32 *) Comm_rx_wake__0__HSIOM)
    #define Comm_RX_WAKE_HSIOM_PTR   ( (reg32 *) Comm_rx_wake__0__HSIOM)
    
    #define Comm_RX_WAKE_HSIOM_MASK      (Comm_rx_wake__0__HSIOM_MASK)
    #define Comm_RX_WAKE_HSIOM_POS       (Comm_rx_wake__0__HSIOM_SHIFT)
    #define Comm_RX_WAKE_HSIOM_SEL_GPIO  (Comm_rx_wake__0__HSIOM_GPIO)
    #define Comm_RX_WAKE_HSIOM_SEL_UART  (Comm_rx_wake__0__HSIOM_UART)
#endif /* (Comm_UART_WAKE_RX_PIN) */

#if (Comm_UART_CTS_PIN)
    #define Comm_CTS_HSIOM_REG   (*(reg32 *) Comm_cts__0__HSIOM)
    #define Comm_CTS_HSIOM_PTR   ( (reg32 *) Comm_cts__0__HSIOM)
    
    #define Comm_CTS_HSIOM_MASK      (Comm_cts__0__HSIOM_MASK)
    #define Comm_CTS_HSIOM_POS       (Comm_cts__0__HSIOM_SHIFT)
    #define Comm_CTS_HSIOM_SEL_GPIO  (Comm_cts__0__HSIOM_GPIO)
    #define Comm_CTS_HSIOM_SEL_UART  (Comm_cts__0__HSIOM_UART)
#endif /* (Comm_UART_CTS_PIN) */

#if (Comm_UART_TX_PIN)
    #define Comm_TX_HSIOM_REG   (*(reg32 *) Comm_tx__0__HSIOM)
    #define Comm_TX_HSIOM_PTR   ( (reg32 *) Comm_tx__0__HSIOM)
    
    #define Comm_TX_HSIOM_MASK      (Comm_tx__0__HSIOM_MASK)
    #define Comm_TX_HSIOM_POS       (Comm_tx__0__HSIOM_SHIFT)
    #define Comm_TX_HSIOM_SEL_GPIO  (Comm_tx__0__HSIOM_GPIO)
    #define Comm_TX_HSIOM_SEL_UART  (Comm_tx__0__HSIOM_UART)
#endif /* (Comm_UART_TX_PIN) */

#if (Comm_UART_RX_TX_PIN)
    #define Comm_RX_TX_HSIOM_REG   (*(reg32 *) Comm_rx_tx__0__HSIOM)
    #define Comm_RX_TX_HSIOM_PTR   ( (reg32 *) Comm_rx_tx__0__HSIOM)
    
    #define Comm_RX_TX_HSIOM_MASK      (Comm_rx_tx__0__HSIOM_MASK)
    #define Comm_RX_TX_HSIOM_POS       (Comm_rx_tx__0__HSIOM_SHIFT)
    #define Comm_RX_TX_HSIOM_SEL_GPIO  (Comm_rx_tx__0__HSIOM_GPIO)
    #define Comm_RX_TX_HSIOM_SEL_UART  (Comm_rx_tx__0__HSIOM_UART)
#endif /* (Comm_UART_RX_TX_PIN) */

#if (Comm_UART_RTS_PIN)
    #define Comm_RTS_HSIOM_REG      (*(reg32 *) Comm_rts__0__HSIOM)
    #define Comm_RTS_HSIOM_PTR      ( (reg32 *) Comm_rts__0__HSIOM)
    
    #define Comm_RTS_HSIOM_MASK     (Comm_rts__0__HSIOM_MASK)
    #define Comm_RTS_HSIOM_POS      (Comm_rts__0__HSIOM_SHIFT)    
    #define Comm_RTS_HSIOM_SEL_GPIO (Comm_rts__0__HSIOM_GPIO)
    #define Comm_RTS_HSIOM_SEL_UART (Comm_rts__0__HSIOM_UART)    
#endif /* (Comm_UART_RTS_PIN) */


/***************************************
*        Registers Constants
***************************************/

/* HSIOM switch values. */ 
#define Comm_HSIOM_DEF_SEL      (0x00u)
#define Comm_HSIOM_GPIO_SEL     (0x00u)
/* The HSIOM values provided below are valid only for Comm_CY_SCBIP_V0 
* and Comm_CY_SCBIP_V1. It is not recommended to use them for 
* Comm_CY_SCBIP_V2. Use pin name specific HSIOM constants provided 
* above instead for any SCB IP block version.
*/
#define Comm_HSIOM_UART_SEL     (0x09u)
#define Comm_HSIOM_I2C_SEL      (0x0Eu)
#define Comm_HSIOM_SPI_SEL      (0x0Fu)

/* Pins settings index. */
#define Comm_RX_WAKE_SCL_MOSI_PIN_INDEX   (0u)
#define Comm_RX_SCL_MOSI_PIN_INDEX       (0u)
#define Comm_TX_SDA_MISO_PIN_INDEX       (1u)
#define Comm_SCLK_PIN_INDEX       (2u)
#define Comm_SS0_PIN_INDEX       (3u)
#define Comm_SS1_PIN_INDEX                  (4u)
#define Comm_SS2_PIN_INDEX                  (5u)
#define Comm_SS3_PIN_INDEX                  (6u)

/* Pins settings mask. */
#define Comm_RX_WAKE_SCL_MOSI_PIN_MASK ((uint32) 0x01u << Comm_RX_WAKE_SCL_MOSI_PIN_INDEX)
#define Comm_RX_SCL_MOSI_PIN_MASK     ((uint32) 0x01u << Comm_RX_SCL_MOSI_PIN_INDEX)
#define Comm_TX_SDA_MISO_PIN_MASK     ((uint32) 0x01u << Comm_TX_SDA_MISO_PIN_INDEX)
#define Comm_SCLK_PIN_MASK     ((uint32) 0x01u << Comm_SCLK_PIN_INDEX)
#define Comm_SS0_PIN_MASK     ((uint32) 0x01u << Comm_SS0_PIN_INDEX)
#define Comm_SS1_PIN_MASK                ((uint32) 0x01u << Comm_SS1_PIN_INDEX)
#define Comm_SS2_PIN_MASK                ((uint32) 0x01u << Comm_SS2_PIN_INDEX)
#define Comm_SS3_PIN_MASK                ((uint32) 0x01u << Comm_SS3_PIN_INDEX)

/* Pin interrupt constants. */
#define Comm_INTCFG_TYPE_MASK           (0x03u)
#define Comm_INTCFG_TYPE_FALLING_EDGE   (0x02u)

/* Pin Drive Mode constants. */
#define Comm_PIN_DM_ALG_HIZ  (0u)
#define Comm_PIN_DM_DIG_HIZ  (1u)
#define Comm_PIN_DM_OD_LO    (4u)
#define Comm_PIN_DM_STRONG   (6u)


/***************************************
*          Macro Definitions
***************************************/

/* Return drive mode of the pin */
#define Comm_DM_MASK    (0x7u)
#define Comm_DM_SIZE    (3u)
#define Comm_GET_P4_PIN_DM(reg, pos) \
    ( ((reg) & (uint32) ((uint32) Comm_DM_MASK << (Comm_DM_SIZE * (pos)))) >> \
                                                              (Comm_DM_SIZE * (pos)) )

#if (Comm_TX_SDA_MISO_PIN)
    #define Comm_CHECK_TX_SDA_MISO_PIN_USED \
                (Comm_PIN_DM_ALG_HIZ != \
                    Comm_GET_P4_PIN_DM(Comm_uart_tx_i2c_sda_spi_miso_PC, \
                                                   Comm_uart_tx_i2c_sda_spi_miso_SHIFT))
#endif /* (Comm_TX_SDA_MISO_PIN) */

#if (Comm_SS0_PIN)
    #define Comm_CHECK_SS0_PIN_USED \
                (Comm_PIN_DM_ALG_HIZ != \
                    Comm_GET_P4_PIN_DM(Comm_spi_ss0_PC, \
                                                   Comm_spi_ss0_SHIFT))
#endif /* (Comm_SS0_PIN) */

/* Set bits-mask in register */
#define Comm_SET_REGISTER_BITS(reg, mask, pos, mode) \
                    do                                           \
                    {                                            \
                        (reg) = (((reg) & ((uint32) ~(uint32) (mask))) | ((uint32) ((uint32) (mode) << (pos)))); \
                    }while(0)

/* Set bit in the register */
#define Comm_SET_REGISTER_BIT(reg, mask, val) \
                    ((val) ? ((reg) |= (mask)) : ((reg) &= ((uint32) ~((uint32) (mask)))))

#define Comm_SET_HSIOM_SEL(reg, mask, pos, sel) Comm_SET_REGISTER_BITS(reg, mask, pos, sel)
#define Comm_SET_INCFG_TYPE(reg, mask, pos, intType) \
                                                        Comm_SET_REGISTER_BITS(reg, mask, pos, intType)
#define Comm_SET_INP_DIS(reg, mask, val) Comm_SET_REGISTER_BIT(reg, mask, val)

/* Comm_SET_I2C_SCL_DR(val) - Sets I2C SCL DR register.
*  Comm_SET_I2C_SCL_HSIOM_SEL(sel) - Sets I2C SCL HSIOM settings.
*/
/* SCB I2C: scl signal */
#if (Comm_CY_SCBIP_V0)
#if (Comm_I2C_PINS)
    #define Comm_SET_I2C_SCL_DR(val) Comm_scl_Write(val)

    #define Comm_SET_I2C_SCL_HSIOM_SEL(sel) \
                          Comm_SET_HSIOM_SEL(Comm_SCL_HSIOM_REG,  \
                                                         Comm_SCL_HSIOM_MASK, \
                                                         Comm_SCL_HSIOM_POS,  \
                                                         (sel))
    #define Comm_WAIT_SCL_SET_HIGH  (0u == Comm_scl_Read())

/* Unconfigured SCB: scl signal */
#elif (Comm_RX_WAKE_SCL_MOSI_PIN)
    #define Comm_SET_I2C_SCL_DR(val) \
                            Comm_uart_rx_wake_i2c_scl_spi_mosi_Write(val)

    #define Comm_SET_I2C_SCL_HSIOM_SEL(sel) \
                    Comm_SET_HSIOM_SEL(Comm_RX_WAKE_SCL_MOSI_HSIOM_REG,  \
                                                   Comm_RX_WAKE_SCL_MOSI_HSIOM_MASK, \
                                                   Comm_RX_WAKE_SCL_MOSI_HSIOM_POS,  \
                                                   (sel))

    #define Comm_WAIT_SCL_SET_HIGH  (0u == Comm_uart_rx_wake_i2c_scl_spi_mosi_Read())

#elif (Comm_RX_SCL_MOSI_PIN)
    #define Comm_SET_I2C_SCL_DR(val) \
                            Comm_uart_rx_i2c_scl_spi_mosi_Write(val)


    #define Comm_SET_I2C_SCL_HSIOM_SEL(sel) \
                            Comm_SET_HSIOM_SEL(Comm_RX_SCL_MOSI_HSIOM_REG,  \
                                                           Comm_RX_SCL_MOSI_HSIOM_MASK, \
                                                           Comm_RX_SCL_MOSI_HSIOM_POS,  \
                                                           (sel))

    #define Comm_WAIT_SCL_SET_HIGH  (0u == Comm_uart_rx_i2c_scl_spi_mosi_Read())

#else
    #define Comm_SET_I2C_SCL_DR(val)        do{ /* Does nothing */ }while(0)
    #define Comm_SET_I2C_SCL_HSIOM_SEL(sel) do{ /* Does nothing */ }while(0)

    #define Comm_WAIT_SCL_SET_HIGH  (0u)
#endif /* (Comm_I2C_PINS) */

/* SCB I2C: sda signal */
#if (Comm_I2C_PINS)
    #define Comm_WAIT_SDA_SET_HIGH  (0u == Comm_sda_Read())
/* Unconfigured SCB: sda signal */
#elif (Comm_TX_SDA_MISO_PIN)
    #define Comm_WAIT_SDA_SET_HIGH  (0u == Comm_uart_tx_i2c_sda_spi_miso_Read())
#else
    #define Comm_WAIT_SDA_SET_HIGH  (0u)
#endif /* (Comm_MOSI_SCL_RX_PIN) */
#endif /* (Comm_CY_SCBIP_V0) */

/* Clear UART wakeup source */
#if (Comm_RX_SCL_MOSI_PIN)
    #define Comm_CLEAR_UART_RX_WAKE_INTR        do{ /* Does nothing */ }while(0)
    
#elif (Comm_RX_WAKE_SCL_MOSI_PIN)
    #define Comm_CLEAR_UART_RX_WAKE_INTR \
            do{                                      \
                (void) Comm_uart_rx_wake_i2c_scl_spi_mosi_ClearInterrupt(); \
            }while(0)

#elif(Comm_UART_RX_WAKE_PIN)
    #define Comm_CLEAR_UART_RX_WAKE_INTR \
            do{                                      \
                (void) Comm_rx_wake_ClearInterrupt(); \
            }while(0)
#else
#endif /* (Comm_RX_SCL_MOSI_PIN) */


/***************************************
* The following code is DEPRECATED and
* must not be used.
***************************************/

/* Unconfigured pins */
#define Comm_REMOVE_MOSI_SCL_RX_WAKE_PIN    Comm_REMOVE_RX_WAKE_SCL_MOSI_PIN
#define Comm_REMOVE_MOSI_SCL_RX_PIN         Comm_REMOVE_RX_SCL_MOSI_PIN
#define Comm_REMOVE_MISO_SDA_TX_PIN         Comm_REMOVE_TX_SDA_MISO_PIN
#ifndef Comm_REMOVE_SCLK_PIN
#define Comm_REMOVE_SCLK_PIN                Comm_REMOVE_SCLK_PIN
#endif /* Comm_REMOVE_SCLK_PIN */
#ifndef Comm_REMOVE_SS0_PIN
#define Comm_REMOVE_SS0_PIN                 Comm_REMOVE_SS0_PIN
#endif /* Comm_REMOVE_SS0_PIN */

/* Unconfigured pins */
#define Comm_MOSI_SCL_RX_WAKE_PIN   Comm_RX_WAKE_SCL_MOSI_PIN
#define Comm_MOSI_SCL_RX_PIN        Comm_RX_SCL_MOSI_PIN
#define Comm_MISO_SDA_TX_PIN        Comm_TX_SDA_MISO_PIN
#ifndef Comm_SCLK_PIN
#define Comm_SCLK_PIN               Comm_SCLK_PIN
#endif /* Comm_SCLK_PIN */
#ifndef Comm_SS0_PIN
#define Comm_SS0_PIN                Comm_SS0_PIN
#endif /* Comm_SS0_PIN */

#if (Comm_MOSI_SCL_RX_WAKE_PIN)
    #define Comm_MOSI_SCL_RX_WAKE_HSIOM_REG     Comm_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define Comm_MOSI_SCL_RX_WAKE_HSIOM_PTR     Comm_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define Comm_MOSI_SCL_RX_WAKE_HSIOM_MASK    Comm_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define Comm_MOSI_SCL_RX_WAKE_HSIOM_POS     Comm_RX_WAKE_SCL_MOSI_HSIOM_REG

    #define Comm_MOSI_SCL_RX_WAKE_INTCFG_REG    Comm_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define Comm_MOSI_SCL_RX_WAKE_INTCFG_PTR    Comm_RX_WAKE_SCL_MOSI_HSIOM_REG

    #define Comm_MOSI_SCL_RX_WAKE_INTCFG_TYPE_POS   Comm_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define Comm_MOSI_SCL_RX_WAKE_INTCFG_TYPE_MASK  Comm_RX_WAKE_SCL_MOSI_HSIOM_REG
#endif /* (Comm_RX_WAKE_SCL_MOSI_PIN) */

#if (Comm_MOSI_SCL_RX_PIN)
    #define Comm_MOSI_SCL_RX_HSIOM_REG      Comm_RX_SCL_MOSI_HSIOM_REG
    #define Comm_MOSI_SCL_RX_HSIOM_PTR      Comm_RX_SCL_MOSI_HSIOM_PTR
    #define Comm_MOSI_SCL_RX_HSIOM_MASK     Comm_RX_SCL_MOSI_HSIOM_MASK
    #define Comm_MOSI_SCL_RX_HSIOM_POS      Comm_RX_SCL_MOSI_HSIOM_POS
#endif /* (Comm_MOSI_SCL_RX_PIN) */

#if (Comm_MISO_SDA_TX_PIN)
    #define Comm_MISO_SDA_TX_HSIOM_REG      Comm_TX_SDA_MISO_HSIOM_REG
    #define Comm_MISO_SDA_TX_HSIOM_PTR      Comm_TX_SDA_MISO_HSIOM_REG
    #define Comm_MISO_SDA_TX_HSIOM_MASK     Comm_TX_SDA_MISO_HSIOM_REG
    #define Comm_MISO_SDA_TX_HSIOM_POS      Comm_TX_SDA_MISO_HSIOM_REG
#endif /* (Comm_MISO_SDA_TX_PIN_PIN) */

#if (Comm_SCLK_PIN)
    #ifndef Comm_SCLK_HSIOM_REG
    #define Comm_SCLK_HSIOM_REG     Comm_SCLK_HSIOM_REG
    #define Comm_SCLK_HSIOM_PTR     Comm_SCLK_HSIOM_PTR
    #define Comm_SCLK_HSIOM_MASK    Comm_SCLK_HSIOM_MASK
    #define Comm_SCLK_HSIOM_POS     Comm_SCLK_HSIOM_POS
    #endif /* Comm_SCLK_HSIOM_REG */
#endif /* (Comm_SCLK_PIN) */

#if (Comm_SS0_PIN)
    #ifndef Comm_SS0_HSIOM_REG
    #define Comm_SS0_HSIOM_REG      Comm_SS0_HSIOM_REG
    #define Comm_SS0_HSIOM_PTR      Comm_SS0_HSIOM_PTR
    #define Comm_SS0_HSIOM_MASK     Comm_SS0_HSIOM_MASK
    #define Comm_SS0_HSIOM_POS      Comm_SS0_HSIOM_POS
    #endif /* Comm_SS0_HSIOM_REG */
#endif /* (Comm_SS0_PIN) */

#define Comm_MOSI_SCL_RX_WAKE_PIN_INDEX Comm_RX_WAKE_SCL_MOSI_PIN_INDEX
#define Comm_MOSI_SCL_RX_PIN_INDEX      Comm_RX_SCL_MOSI_PIN_INDEX
#define Comm_MISO_SDA_TX_PIN_INDEX      Comm_TX_SDA_MISO_PIN_INDEX
#ifndef Comm_SCLK_PIN_INDEX
#define Comm_SCLK_PIN_INDEX             Comm_SCLK_PIN_INDEX
#endif /* Comm_SCLK_PIN_INDEX */
#ifndef Comm_SS0_PIN_INDEX
#define Comm_SS0_PIN_INDEX              Comm_SS0_PIN_INDEX
#endif /* Comm_SS0_PIN_INDEX */

#define Comm_MOSI_SCL_RX_WAKE_PIN_MASK Comm_RX_WAKE_SCL_MOSI_PIN_MASK
#define Comm_MOSI_SCL_RX_PIN_MASK      Comm_RX_SCL_MOSI_PIN_MASK
#define Comm_MISO_SDA_TX_PIN_MASK      Comm_TX_SDA_MISO_PIN_MASK
#ifndef Comm_SCLK_PIN_MASK
#define Comm_SCLK_PIN_MASK             Comm_SCLK_PIN_MASK
#endif /* Comm_SCLK_PIN_MASK */
#ifndef Comm_SS0_PIN_MASK
#define Comm_SS0_PIN_MASK              Comm_SS0_PIN_MASK
#endif /* Comm_SS0_PIN_MASK */

#endif /* (CY_SCB_PINS_Comm_H) */


/* [] END OF FILE */
