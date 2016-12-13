/***************************************************************************//**
* \file Comm_EZI2C.h
* \version 3.20
*
* \brief
*  This file provides constants and parameter values for the SCB Component in
*  the EZI2C mode.
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

#if !defined(CY_SCB_EZI2C_Comm_H)
#define CY_SCB_EZI2C_Comm_H

#include "Comm.h"


/***************************************
*   Initial Parameter Constants
****************************************/

#define Comm_EZI2C_CLOCK_STRETCHING         (1u)
#define Comm_EZI2C_MEDIAN_FILTER_ENABLE     (1u)
#define Comm_EZI2C_NUMBER_OF_ADDRESSES      (0u)
#define Comm_EZI2C_PRIMARY_SLAVE_ADDRESS    (8u)
#define Comm_EZI2C_SECONDARY_SLAVE_ADDRESS  (9u)
#define Comm_EZI2C_SUB_ADDRESS_SIZE         (0u)
#define Comm_EZI2C_WAKE_ENABLE              (0u)
#define Comm_EZI2C_DATA_RATE                (100u)
#define Comm_EZI2C_SLAVE_ADDRESS_MASK       (254u)
#define Comm_EZI2C_BYTE_MODE_ENABLE         (0u)


/***************************************
*  Conditional Compilation Parameters
****************************************/

#if(Comm_SCB_MODE_UNCONFIG_CONST_CFG)

    #define Comm_SUB_ADDRESS_SIZE16             (0u != Comm_subAddrSize)
    #define Comm_SECONDARY_ADDRESS_ENABLE       (0u != Comm_numberOfAddr)

    #define Comm_EZI2C_EC_AM_ENABLE         (0u != (Comm_CTRL_REG & \
                                                                Comm_CTRL_EC_AM_MODE))
    #define Comm_EZI2C_SCL_STRETCH_ENABLE   (0u != (Comm_GetSlaveInterruptMode() & \
                                                                Comm_INTR_SLAVE_I2C_ADDR_MATCH))
    #define Comm_EZI2C_SCL_STRETCH_DISABLE       (!Comm_EZI2C_SCL_STRETCH_ENABLE)

    #define Comm_SECONDARY_ADDRESS_ENABLE_CONST  (1u)
    #define Comm_SUB_ADDRESS_SIZE16_CONST        (1u)
    #define Comm_EZI2C_SCL_STRETCH_ENABLE_CONST  (1u)
    #define Comm_EZI2C_SCL_STRETCH_DISABLE_CONST (1u)
    #define Comm_EZI2C_WAKE_ENABLE_CONST         (1u)

    #if (Comm_CY_SCBIP_V0 || Comm_CY_SCBIP_V1)
        #define Comm_EZI2C_FIFO_SIZE    (Comm_FIFO_SIZE)
    #else
        #define Comm_EZI2C_FIFO_SIZE    (Comm_GET_FIFO_SIZE(Comm_CTRL_REG & \
                                                                                    Comm_CTRL_BYTE_MODE))
    #endif /* (Comm_CY_SCBIP_V0 || Comm_CY_SCBIP_V1) */

#else

    #define Comm_SUB_ADDRESS_SIZE16         (0u != Comm_EZI2C_SUB_ADDRESS_SIZE)
    #define Comm_SUB_ADDRESS_SIZE16_CONST   (Comm_SUB_ADDRESS_SIZE16)

    #define Comm_SECONDARY_ADDRESS_ENABLE        (0u != Comm_EZI2C_NUMBER_OF_ADDRESSES)
    #define Comm_SECONDARY_ADDRESS_ENABLE_CONST  (Comm_SECONDARY_ADDRESS_ENABLE)

    #define Comm_EZI2C_SCL_STRETCH_ENABLE        (0u != Comm_EZI2C_CLOCK_STRETCHING)
    #define Comm_EZI2C_SCL_STRETCH_DISABLE       (!Comm_EZI2C_SCL_STRETCH_ENABLE)
    #define Comm_EZI2C_SCL_STRETCH_ENABLE_CONST  (Comm_EZI2C_SCL_STRETCH_ENABLE)
    #define Comm_EZI2C_SCL_STRETCH_DISABLE_CONST (Comm_EZI2C_SCL_STRETCH_DISABLE)

    #define Comm_EZI2C_WAKE_ENABLE_CONST         (0u != Comm_EZI2C_WAKE_ENABLE)
    #define Comm_EZI2C_EC_AM_ENABLE              (0u != Comm_EZI2C_WAKE_ENABLE)

    #define Comm_EZI2C_FIFO_SIZE Comm_GET_FIFO_SIZE(Comm_EZI2C_BYTE_MODE_ENABLE)

#endif /* (Comm_SCB_MODE_UNCONFIG_CONST_CFG) */


/***************************************
*       Type Definitions
***************************************/
/**
* \addtogroup group_structures
* @{
*/
typedef struct
{
    /** When enabled the SCL is stretched as required for proper operation: 
     *  0 – disable, 1 – enable.
    */
    uint32 enableClockStretch;
    
    /** This field is left for compatibility and its value is ignored. 
     *  Median filter is disabled for EZI2C mode.
    */
    uint32 enableMedianFilter;
    
    /** Number of supported addresses: 
     *  - Comm_EZI2C_ONE_ADDRESS
     *  - Comm_EZI2C_TWO_ADDRESSES
    */
    uint32 numberOfAddresses;
    
    /** Primary 7-bit slave address.
    */
    uint32 primarySlaveAddr;
    
    /** Secondary 7-bit slave address.
    */
    uint32 secondarySlaveAddr;
    
    /** Size of sub-address.
     *  - Comm_EZI2C_SUB_ADDR8_BITS 
     *  - Comm_EZI2C_SUB_ADDR16_BITS
    */
    uint32 subAddrSize;
    
    /** When enabled the TX and RX FIFO depth is doubled and equal to 
     *  16 bytes: 0 – disable, 1 – enable.
    */
    uint32 enableWake;
    
    /** When enabled the TX and RX FIFO depth is 16 bytes: 0 – disable, 
     *  1 – enable.
     * 
     *  Ignored for all devices other than PSoC 4100 BLE / PSoC 4200 BLE / 
     *  PSoC 4100M / PSoC 4200M / PSoC 4200L / PSoC 4000S / PSoC 4100S / 
     *  PSoC Analog Coprocessor.
    */
    uint8  enableByteMode;
} Comm_EZI2C_INIT_STRUCT;
/** @} structures */

/***************************************
*        Function Prototypes
***************************************/

/**
* \addtogroup group_ezi2c
* @{
*/

#if(Comm_SCB_MODE_UNCONFIG_CONST_CFG)
    void Comm_EzI2CInit(const Comm_EZI2C_INIT_STRUCT *config);
#endif /* (Comm_SCB_MODE_UNCONFIG_CONST_CFG) */

uint32 Comm_EzI2CGetActivity(void);

void   Comm_EzI2CSetAddress1(uint32 address);
uint32 Comm_EzI2CGetAddress1(void);
void   Comm_EzI2CSetBuffer1(uint32 bufSize, uint32 rwBoundary, volatile uint8 * buffer);
void   Comm_EzI2CSetReadBoundaryBuffer1(uint32 rwBoundary);

#if(Comm_SECONDARY_ADDRESS_ENABLE_CONST)
    void   Comm_EzI2CSetAddress2(uint32 address);
    uint32 Comm_EzI2CGetAddress2(void);
    void   Comm_EzI2CSetBuffer2(uint32 bufSize, uint32 rwBoundary, volatile uint8 * buffer);
    void   Comm_EzI2CSetReadBoundaryBuffer2(uint32 rwBoundary);
#endif /* (Comm_SECONDARY_ADDRESS_ENABLE_CONST) */
/** @} ezi2c */

#if(Comm_EZI2C_SCL_STRETCH_ENABLE_CONST)
    CY_ISR_PROTO(Comm_EZI2C_STRETCH_ISR);
#endif /* (Comm_EZI2C_SCL_STRETCH_ENABLE_CONST) */

#if(Comm_EZI2C_SCL_STRETCH_DISABLE_CONST)
    CY_ISR_PROTO(Comm_EZI2C_NO_STRETCH_ISR);
#endif /* (Comm_EZI2C_SCL_STRETCH_DISABLE) */


/***************************************
*            API Constants
***************************************/

/* Configuration structure constants */
#define Comm_EZI2C_ONE_ADDRESS      (0u)
#define Comm_EZI2C_TWO_ADDRESSES    (1u)

#define Comm_EZI2C_PRIMARY_ADDRESS  (0u)
#define Comm_EZI2C_BOTH_ADDRESSES   (1u)

#define Comm_EZI2C_SUB_ADDR8_BITS   (0u)
#define Comm_EZI2C_SUB_ADDR16_BITS  (1u)

/* Comm_EzI2CGetActivity() return constants */
#define Comm_EZI2C_STATUS_SECOND_OFFSET (1u)
#define Comm_EZI2C_STATUS_READ1     ((uint32) (Comm_INTR_SLAVE_I2C_NACK))        /* Bit [1]   */
#define Comm_EZI2C_STATUS_WRITE1    ((uint32) (Comm_INTR_SLAVE_I2C_WRITE_STOP))  /* Bit [3]   */
#define Comm_EZI2C_STATUS_READ2     ((uint32) (Comm_INTR_SLAVE_I2C_NACK >> \
                                                           Comm_EZI2C_STATUS_SECOND_OFFSET)) /* Bit [0]   */
#define Comm_EZI2C_STATUS_WRITE2    ((uint32) (Comm_INTR_SLAVE_I2C_WRITE_STOP >> \
                                                           Comm_EZI2C_STATUS_SECOND_OFFSET)) /* Bit [2]   */
#define Comm_EZI2C_STATUS_ERR       ((uint32) (0x10u))                                       /* Bit [4]   */
#define Comm_EZI2C_STATUS_BUSY      ((uint32) (0x20u))                                       /* Bit [5]   */
#define Comm_EZI2C_CLEAR_STATUS     ((uint32) (0x1Fu))                                       /* Bits [0-4]*/
#define Comm_EZI2C_CMPLT_INTR_MASK  ((uint32) (Comm_INTR_SLAVE_I2C_NACK | \
                                                           Comm_INTR_SLAVE_I2C_WRITE_STOP))


/***************************************
*     Vars with External Linkage
***************************************/

#if(Comm_SCB_MODE_UNCONFIG_CONST_CFG)
    extern const Comm_EZI2C_INIT_STRUCT Comm_configEzI2C;
#endif /* (Comm_SCB_MODE_UNCONFIG_CONST_CFG) */


/***************************************
*           FSM states
***************************************/

/* Returns to master when there is no data to transmit */
#define Comm_EZI2C_OVFL_RETURN  (0xFFu)

/* States of EZI2C Slave FSM */
#define Comm_EZI2C_FSM_OFFSET_HI8 ((uint8) (0x02u)) /* Idle state for 1 addr: waits for high byte offset */
#define Comm_EZI2C_FSM_OFFSET_LO8 ((uint8) (0x00u)) /* Idle state for 2 addr: waits for low byte offset  */
#define Comm_EZI2C_FSM_BYTE_WRITE ((uint8) (0x01u)) /* Data byte write state: byte by byte mode          */
#define Comm_EZI2C_FSM_WAIT_STOP  ((uint8) (0x03u)) /* Discards written bytes as they do not match write
                                                                   criteria */
#define Comm_EZI2C_FSM_WRITE_MASK ((uint8) (0x01u)) /* Incorporates write states: EZI2C_FSM_BYTE_WRITE and
                                                                   EZI2C_FSM_WAIT_STOP  */

#define Comm_EZI2C_FSM_IDLE     ((Comm_SUB_ADDRESS_SIZE16) ?      \
                                                (Comm_EZI2C_FSM_OFFSET_HI8) : \
                                                (Comm_EZI2C_FSM_OFFSET_LO8))

#define Comm_EZI2C_CONTINUE_TRANSFER    (1u)
#define Comm_EZI2C_COMPLETE_TRANSFER    (0u)

#define Comm_EZI2C_NACK_RECEIVED_ADDRESS  (0u)
#define Comm_EZI2C_ACK_RECEIVED_ADDRESS   (1u)

#define Comm_EZI2C_ACTIVE_ADDRESS1  (0u)
#define Comm_EZI2C_ACTIVE_ADDRESS2  (1u)


/***************************************
*       Macro Definitions
***************************************/

/* Access to global variables */
#if(Comm_SECONDARY_ADDRESS_ENABLE_CONST)

    #define Comm_EZI2C_UPDATE_LOC_STATUS(activeAddress, locStatus) \
            do{ \
                (locStatus) >>= (activeAddress); \
            }while(0)

    #define Comm_EZI2C_GET_INDEX(activeAddress) \
            ((Comm_EZI2C_ACTIVE_ADDRESS1 == (activeAddress)) ? \
                ((uint32) Comm_indexBuf1) :                    \
                ((uint32) Comm_indexBuf2))

    #define Comm_EZI2C_GET_OFFSET(activeAddress) \
            ((Comm_EZI2C_ACTIVE_ADDRESS1 == (activeAddress)) ? \
                ((uint32) Comm_offsetBuf1) :                   \
                ((uint32) Comm_offsetBuf2))

    #define Comm_EZI2C_SET_INDEX(activeAddress, locIndex) \
            do{ \
                if(Comm_EZI2C_ACTIVE_ADDRESS1 == (activeAddress)) \
                {    \
                    Comm_indexBuf1 = (uint16) (locIndex); \
                }    \
                else \
                {    \
                    Comm_indexBuf2 = (uint16) (locIndex); \
                }    \
            }while(0)

    #define Comm_EZI2C_SET_OFFSET(activeAddress, locOffset) \
            do{ \
                if(Comm_EZI2C_ACTIVE_ADDRESS1 == (activeAddress)) \
                {    \
                    Comm_offsetBuf1 = (uint16) (locOffset); \
                }    \
                else \
                {    \
                    Comm_offsetBuf2 = (uint16) (locOffset); \
                }    \
            }while(0)
#else
    #define Comm_EZI2C_UPDATE_LOC_STATUS(activeAddress, locStatus)  do{ /* Empty*/ }while(0)

    #define Comm_EZI2C_GET_INDEX(activeAddress)  ((uint32) (Comm_indexBuf1))

    #define Comm_EZI2C_GET_OFFSET(activeAddress) ((uint32) (Comm_offsetBuf1))

    #define Comm_EZI2C_SET_INDEX(activeAddress, locIndex) \
            do{ \
                Comm_indexBuf1 = (uint16) (locIndex); \
            }while(0)

    #define Comm_EZI2C_SET_OFFSET(activeAddress, locOffset) \
            do{ \
                Comm_offsetBuf1 = (uint16) (locOffset); \
            }while(0)

#endif  /* (Comm_SUB_ADDRESS_SIZE16_CONST) */


/* This macro only applicable for EZI2C slave without clock stretching.
* It should not be used for other pusposes. */
#define Comm_EZI2C_TX_FIFO_CTRL_SET   (Comm_EZI2C_TX_FIFO_CTRL | \
                                                   Comm_TX_FIFO_CTRL_CLEAR)
#define Comm_EZI2C_TX_FIFO_CTRL_CLEAR (Comm_EZI2C_TX_FIFO_CTRL)
#define Comm_FAST_CLEAR_TX_FIFO \
                            do{             \
                                Comm_TX_FIFO_CTRL_REG = Comm_EZI2C_TX_FIFO_CTRL_SET;   \
                                Comm_TX_FIFO_CTRL_REG = Comm_EZI2C_TX_FIFO_CTRL_CLEAR; \
                            }while(0)


/***************************************
*      Common Register Settings
***************************************/

#define Comm_CTRL_EZI2C     (Comm_CTRL_MODE_I2C)

#define Comm_EZI2C_CTRL     (Comm_I2C_CTRL_S_GENERAL_IGNORE | \
                                         Comm_I2C_CTRL_SLAVE_MODE)

#define Comm_EZI2C_CTRL_AUTO    (Comm_I2C_CTRL_S_READY_ADDR_ACK      | \
                                             Comm_I2C_CTRL_S_READY_DATA_ACK      | \
                                             Comm_I2C_CTRL_S_NOT_READY_ADDR_NACK | \
                                             Comm_I2C_CTRL_S_NOT_READY_DATA_NACK)

#define Comm_EZI2C_RX_CTRL  ((Comm_FIFO_SIZE - 1u)   | \
                                          Comm_RX_CTRL_MSB_FIRST | \
                                          Comm_RX_CTRL_ENABLED)

#define Comm_EZI2C_TX_FIFO_CTRL (2u)
#define Comm_TX_LOAD_SIZE       (2u)

#define Comm_EZI2C_TX_CTRL  ((Comm_ONE_BYTE_WIDTH - 1u) | \
                                          Comm_TX_CTRL_MSB_FIRST    | \
                                          Comm_TX_CTRL_ENABLED)

#define Comm_EZI2C_INTR_SLAVE_MASK  (Comm_INTR_SLAVE_I2C_BUS_ERROR | \
                                                 Comm_INTR_SLAVE_I2C_ARB_LOST  | \
                                                 Comm_INTR_SLAVE_I2C_STOP)

#define Comm_INTR_SLAVE_COMPLETE    (Comm_INTR_SLAVE_I2C_STOP | \
                                                 Comm_INTR_SLAVE_I2C_NACK | \
                                                 Comm_INTR_SLAVE_I2C_WRITE_STOP)


/***************************************
*    Initialization Register Settings
***************************************/

#if(Comm_SCB_MODE_EZI2C_CONST_CFG)

    #define Comm_EZI2C_DEFAULT_CTRL \
                                (Comm_GET_CTRL_BYTE_MODE  (Comm_EZI2C_BYTE_MODE_ENABLE)    | \
                                 Comm_GET_CTRL_ADDR_ACCEPT(Comm_EZI2C_NUMBER_OF_ADDRESSES) | \
                                 Comm_GET_CTRL_EC_AM_MODE (Comm_EZI2C_WAKE_ENABLE))

    #if(Comm_EZI2C_SCL_STRETCH_ENABLE_CONST)
        #define Comm_EZI2C_DEFAULT_I2C_CTRL (Comm_EZI2C_CTRL)
    #else
        #define Comm_EZI2C_DEFAULT_I2C_CTRL (Comm_EZI2C_CTRL_AUTO | Comm_EZI2C_CTRL)
    #endif /* (Comm_EZI2C_SCL_STRETCH_ENABLE_CONST) */


    #define Comm_EZI2C_DEFAULT_RX_MATCH \
                                (Comm_GET_I2C_8BIT_ADDRESS(Comm_EZI2C_PRIMARY_SLAVE_ADDRESS) | \
                                 Comm_GET_RX_MATCH_MASK   (Comm_EZI2C_SLAVE_ADDRESS_MASK))

    #define Comm_EZI2C_DEFAULT_RX_CTRL  (Comm_EZI2C_RX_CTRL)
    #define Comm_EZI2C_DEFAULT_TX_CTRL  (Comm_EZI2C_TX_CTRL)

    #define Comm_EZI2C_DEFAULT_RX_FIFO_CTRL (0u)
    #if(Comm_EZI2C_SCL_STRETCH_ENABLE_CONST)
        #define Comm_EZI2C_DEFAULT_TX_FIFO_CTRL (0u)
    #else
        #define Comm_EZI2C_DEFAULT_TX_FIFO_CTRL (2u)
    #endif /* (Comm_EZI2C_SCL_STRETCH_ENABLE_CONST) */

    /* Interrupt sources */
    #define Comm_EZI2C_DEFAULT_INTR_I2C_EC_MASK (Comm_NO_INTR_SOURCES)
    #define Comm_EZI2C_DEFAULT_INTR_SPI_EC_MASK (Comm_NO_INTR_SOURCES)
    #define Comm_EZI2C_DEFAULT_INTR_MASTER_MASK (Comm_NO_INTR_SOURCES)
    #define Comm_EZI2C_DEFAULT_INTR_TX_MASK     (Comm_NO_INTR_SOURCES)

    #if(Comm_EZI2C_SCL_STRETCH_ENABLE_CONST)
        #define Comm_EZI2C_DEFAULT_INTR_RX_MASK     (Comm_NO_INTR_SOURCES)
        #define Comm_EZI2C_DEFAULT_INTR_SLAVE_MASK  (Comm_INTR_SLAVE_I2C_ADDR_MATCH | \
                                                                 Comm_EZI2C_INTR_SLAVE_MASK)
    #else
        #define Comm_EZI2C_DEFAULT_INTR_RX_MASK     (Comm_INTR_RX_NOT_EMPTY)
        #define Comm_EZI2C_DEFAULT_INTR_SLAVE_MASK  (Comm_INTR_SLAVE_I2C_START | \
                                                                 Comm_EZI2C_INTR_SLAVE_MASK)
    #endif /* (Comm_EZI2C_SCL_STRETCH_ENABLE_CONST) */

#endif /* (Comm_SCB_MODE_EZI2C_CONST_CFG) */

#endif /* (CY_SCB_EZI2C_Comm_H) */


/* [] END OF FILE */
