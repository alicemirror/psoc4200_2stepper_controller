/*******************************************************************************
* File Name: SCB_1_I2C.h
* Version 1.0
*
* Description:
*  This file provides constants and parameter values for the SCB component.
*
********************************************************************************
* Copyright 2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_I2C_SCB_1_H)
#define CY_SCB_I2C_SCB_1_H

#include "SCB_1.h"


/***************************************
*       Type defines
***************************************/

typedef struct
{
    uint32 mode;
    uint32 oversampleLow;
    uint32 oversampleHigh;
    uint32 enableMedianFilter;
    uint32 slaveAddr;
    uint32 slaveAddrMask;
    uint32 acceptAddr;
    uint32 enableWake;
} SCB_1_I2C_INIT_STRUCT;


/***************************************
*       Global components vars
***************************************/

extern const SCB_1_I2C_INIT_STRUCT SCB_1_configI2C;


/***************************************
*   Parameters from customizer
****************************************/

#define SCB_1_I2C_MODE                   (1u)
#define SCB_1_I2C_OVS_FACTOR_LOW         (8u)
#define SCB_1_I2C_OVS_FACTOR_HIGH        (8u)
#define SCB_1_I2C_MEDIAN_FILTER_ENABLE   (1u)
#define SCB_1_I2C_SLAVE_ADDRESS          (8u)
#define SCB_1_I2C_SLAVE_ADDRESS_MASK     (254u)
#define SCB_1_I2C_ACCEPT_ADRESS          (0u)
#define SCB_1_I2C_WAKE_ENABLE            (0u)
#define SCB_1_I2C_WAKE_ACTION            (0u)
#define SCB_1_I2C_DATA_RATE              (100u)


/***************************************
*   Access to I2C config structure
****************************************/

#define SCB_1_I2C_INIT_ACCESS(ptr, field)  (((SCB_1_I2C_INIT_STRUCT *) (ptr))->field)


/***************************************
*   Condition compilation parameters
****************************************/

/* I2C sub mode enum */
#define SCB_1_I2C_MODE_SLAVE              (0x01u)
#define SCB_1_I2C_MODE_MASTER             (0x02u)
#define SCB_1_I2C_MODE_MULTI_MASTER       (0x06u)
#define SCB_1_I2C_MODE_MULTI_MASTER_SLAVE (0x07u)
#define SCB_1_I2C_MODE_MULTI_MASTER_MASK  (0x04u)

#if(SCB_1_SCB_MODE_UNCFG_CONST_CFG)

    /* Returns true if slave mode is enabled */
    #define SCB_1_I2C_SLAVE   (0u != (SCB_1_I2C_INIT_ACCESS(SCB_1_scbCfg, mode) & \
                                                 SCB_1_I2C_MODE_SLAVE))

    /* Returns true if master mode is enabled */
    #define SCB_1_I2C_MASTER  (0u != (SCB_1_I2C_INIT_ACCESS(SCB_1_scbCfg, mode) & \
                                                 SCB_1_I2C_MODE_MASTER))

    /* Returns true if multi-master mode is enabled */
    #define SCB_1_I2C_MULTI_MASTER \
                                    (0u != (SCB_1_I2C_INIT_ACCESS(SCB_1_scbCfg, mode) & \
                                            SCB_1_I2C_MODE_MULTI_MASTER))

    /* Returns true if multi-master-slave mode is enabled */
    #define SCB_1_I2C_MULTI_MASTER_SLAVE \
                                    (0u != (SCB_1_I2C_INIT_ACCESS(SCB_1_scbCfg, mode) & \
                                            SCB_1_I2C_MODE_MULTI_MASTER_SLAVE))

    /* Returns true if address accepts in RX FIFO */
    #define SCB_1_I2C_ACCEPT_ADDR \
                                    (0u != SCB_1_I2C_INIT_ACCESS(SCB_1_scbCfg, acceptAddr))

    /* Returns true if wakeup on address match is enabled */
    #define SCB_1_I2C_WAKEUP \
                                    (0u != SCB_1_I2C_INIT_ACCESS(SCB_1_scbCfg, enableWake))

    #define SCB_1_I2C_SLAVE_CONST        (1u)
    #define SCB_1_I2C_MASTER_CONST       (1u)
    #define SCB_1_I2C_ACCEPT_ADDR_CONST  (1u)

    #define SCB_1_I2C_BTLDR_COMM_ENABLED ((CYDEV_BOOTLOADER_IO_COMP == CyBtldr_SCB_1) || \
                                                     (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_Custom_Interface))

#else

    /* Returns true if slave mode is enabled */
    #define SCB_1_I2C_SLAVE   (0u != (SCB_1_I2C_MODE_SLAVE & SCB_1_I2C_MODE))

    /* Returns true if master mode is enabled */
    #define SCB_1_I2C_MASTER  (0u != (SCB_1_I2C_MODE_MASTER & SCB_1_I2C_MODE))

    /* Returns true if multi-master mode is enabled */
    #define SCB_1_I2C_MULTI_MASTER \
                                    (0u != (SCB_1_I2C_MODE_MULTI_MASTER & SCB_1_I2C_MODE))

    /* Returns true if multi-master-slave mode is enabled */
    #define SCB_1_I2C_MULTI_MASTER_SLAVE \
                                    (0u != (SCB_1_I2C_MODE_MULTI_MASTER_SLAVE & SCB_1_I2C_MODE))

    /* Returns true if address accepts in RX FIFO */
    #define SCB_1_I2C_ACCEPT_ADDR     (0u != SCB_1_I2C_ACCEPT_ADRESS)

    /* Returns true if wakeup on address match is enabled */
    #define SCB_1_I2C_WAKEUP          (0u != SCB_1_I2C_WAKE_ENABLE)


    #define SCB_1_I2C_SLAVE_CONST        (SCB_1_I2C_SLAVE)
    #define SCB_1_I2C_MASTER_CONST       (SCB_1_I2C_MASTER)
    #define SCB_1_I2C_ACCEPT_ADDR_CONST  (SCB_1_I2C_ACCEPT_ADDR)

    #define SCB_1_I2C_BTLDR_COMM_ENABLED     (SCB_1_I2C_SLAVE_CONST && \
                                                          ((CYDEV_BOOTLOADER_IO_COMP == CyBtldr_SCB_1) || \
                                                           (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_Custom_Interface)))

#endif /* (SCB_1_SCB_MODE_UNCFG_CONST_CFG) */


/***************************************
*        Function Prototypes
***************************************/

/* Common functions */
void SCB_1_I2CInit(SCB_1_I2C_INIT_STRUCT *config);

/* Internal functions for external linking */
void SCB_1_I2CStop(void);
void SCB_1_I2CSaveConfig(void);
void SCB_1_I2CRestoreConfig(void);

/* I2C Master functions prototypes */
#if(SCB_1_I2C_MASTER_CONST)
    /* Read and Clear status functions */
    uint32 SCB_1_I2CMasterStatus(void);
    uint32 SCB_1_I2CMasterClearStatus(void);

    /* Interrupt based operation functions */
    uint32 SCB_1_I2CMasterWriteBuf(uint32 slaveAddress, uint8 * wrData, uint32 cnt, uint32 mode);
    uint32 SCB_1_I2CMasterReadBuf(uint32 slaveAddress, uint8 * rdData, uint32 cnt, uint32 mode);
    uint32 SCB_1_I2CMasterGetReadBufSize(void);
    uint32 SCB_1_I2CMasterGetWriteBufSize(void);
    void   SCB_1_I2CMasterClearReadBuf(void);
    void   SCB_1_I2CMasterClearWriteBuf(void);

    /* Manual operation functions */
    uint32 SCB_1_I2CMasterSendStart(uint32 slaveAddress, uint32 R_nW);
    uint32 SCB_1_I2CMasterSendRestart(uint32 slaveAddress, uint32 R_nW);
    uint32 SCB_1_I2CMasterSendStop(void);
    uint32 SCB_1_I2CMasterWriteByte(uint32 theByte);
    uint32 SCB_1_I2CMasterReadByte(uint32 ackNack);
#endif /* (SCB_1_I2C_MASTER_CONST) */

/* I2C Slave functions prototypes */
#if(SCB_1_I2C_SLAVE_CONST)
    /* Read and Clear status functions */
    uint32 SCB_1_I2CSlaveStatus(void);
    uint32 SCB_1_I2CSlaveClearReadStatus(void);
    uint32 SCB_1_I2CSlaveClearWriteStatus(void);

    /* Set Slave address and mask */
    void   SCB_1_I2CSlaveSetAddress(uint32 address);
    void   SCB_1_I2CSlaveSetAddressMask(uint32 mask);

    /* Interrupt based operation functions */
    void   SCB_1_I2CSlaveInitReadBuf(uint8 * rdBuf, uint32 bufSize);
    void   SCB_1_I2CSlaveInitWriteBuf(uint8 * wrBuf, uint32 bufSize);
    uint32 SCB_1_I2CSlaveGetReadBufSize(void);
    uint32 SCB_1_I2CSlaveGetWriteBufSize(void);
    void   SCB_1_I2CSlaveClearReadBuf(void);
    void   SCB_1_I2CSlaveClearWriteBuf(void);
#endif /* (SCB_1_I2C_SLAVE_CONST) */

CY_ISR_PROTO(SCB_1_I2C_ISR); /* Interrupt handler */

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (SCB_1_I2C_BTLDR_COMM_ENABLED)

    /* Bootloader physical layer functions */
    void SCB_1_I2CCyBtldrCommStart(void);
    void SCB_1_I2CCyBtldrCommStop (void);
    void SCB_1_I2CCyBtldrCommReset(void);
    cystatus SCB_1_I2CCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus SCB_1_I2CCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

    /* Size of Read/Write buffers for I2C bootloader  */
    #define SCB_1_I2C_BTLDR_SIZEOF_READ_BUFFER   (64u)
    #define SCB_1_I2C_BTLDR_SIZEOF_WRITE_BUFFER  (64u)
    #define SCB_1_I2C_MIN_UINT16(a, b)           ( ((uint16)(a) < (b)) ? ((uint16) (a)) : ((uint16) (b)) )
    #define SCB_1_WAIT_1_MS                      (1u)

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (SCB_1_I2C_BTLDR_COMM_ENABLED) */


/***************************************
*            API Constants
***************************************/

/* EZI2C struct init constants */
#define SCB_1_I2C_WAKE_CLOCK_STRETCH (0u)
#define SCB_1_I2C_WAKE_ADDRESS_NACK  (1u)

/* General I2C constants */
#define SCB_1_I2C_READ_FLAG          (0x01u) /* Read flag of the Address */
#define SCB_1_I2C_FIFO_SIZE          (8u)    /* Max FIFO entries for I2C */
#define SCB_1_I2C_SLAVE_OVFL_RETURN  (0xFFu) /* Return by slave when overflow */

/* Master/Slave control constants */
#define SCB_1_I2C_WRITE_XFER_MODE    (0u)    /* Write    */
#define SCB_1_I2C_READ_XFER_MODE     (1u)    /* Read     */
#define SCB_1_I2C_ACK_DATA           (0u)    /* Send ACK */
#define SCB_1_I2C_NAK_DATA           (1u)    /* Send NAK */

/* "Mode" constants for MasterWriteBuf() or MasterReadBuf() function */
#define SCB_1_I2C_MODE_COMPLETE_XFER     (0x00u)    /* Full transfer with Start and Stop       */
#define SCB_1_I2C_MODE_REPEAT_START      (0x01u)    /* Begin with a ReStart instead of a Start */
#define SCB_1_I2C_MODE_NO_STOP           (0x02u)    /* Complete the transfer without a Stop    */

/* Master status */
#define SCB_1_I2C_MSTAT_CLEAR            (0x00u)    /* Clear (init) status value */

#define SCB_1_I2C_MSTAT_RD_CMPLT         (0x01u)    /* Read complete               */
#define SCB_1_I2C_MSTAT_WR_CMPLT         (0x02u)    /* Write complete              */
#define SCB_1_I2C_MSTAT_XFER_INP         (0x04u)    /* Master transfer in progress */
#define SCB_1_I2C_MSTAT_XFER_HALT        (0x08u)    /* Transfer is halted          */

#define SCB_1_I2C_MSTAT_ERR_MASK         (0x3F0u)   /* Mask for all errors                                    */
#define SCB_1_I2C_MSTAT_ERR_SHORT_XFER   (0x010u)   /* Master NAKed before end of packet                      */
#define SCB_1_I2C_MSTAT_ERR_ADDR_NAK     (0x020u)   /* Slave did not ACK                                      */
#define SCB_1_I2C_MSTAT_ERR_ARB_LOST     (0x040u)   /* Master lost arbitration during communication           */
#define SCB_1_I2C_MSTAT_ERR_START_ABORT  (0x080u)   /* The Slave was addressed before the Start was generated */
#define SCB_1_I2C_MSTAT_ERR_BUS_ERROR    (0x100u)   /* The misplaced Start or Stop is happen on the bus       */
#define SCB_1_I2C_MSTAT_ERR_XFER         (0x200u)   /* Error during transfer                                  */

/* Master API returns */
#define SCB_1_I2C_MSTR_NO_ERROR          (0x00u)    /* Function complete without error                               */
#define SCB_1_I2C_MSTR_BUS_BUSY          (0x01u)    /* Bus is busy, process not started                              */
#define SCB_1_I2C_MSTR_NOT_READY         (0x02u)    /* Master not Master on the bus or Slave operation in progress   */
#define SCB_1_I2C_MSTR_ERR_LB_NAK        (0x03u)    /* Last Byte Naked                                               */
#define SCB_1_I2C_MSTR_ERR_ARB_LOST      (0x04u)    /* Master lost arbitration during communication                  */
#define SCB_1_I2C_MSTR_ERR_ABORT_START_GEN  (0x05u) /* Master did not generate Start, the Slave was addressed before */

/* Slave Status Constants */
#define SCB_1_I2C_SSTAT_RD_CMPLT         (0x01u)    /* Read transfer complete                       */
#define SCB_1_I2C_SSTAT_RD_BUSY          (0x02u)    /* Read transfer in progress                    */
#define SCB_1_I2C_SSTAT_RD_ERR_OVFL      (0x04u)    /* Read overflow Error                          */
#define SCB_1_I2C_SSTAT_RD_ERR           (0x08u)    /* Read was interrupted by misplaced Start/Stop */
#define SCB_1_I2C_SSTAT_RD_MASK          (0x0Fu)    /* Read Status Mask                             */
#define SCB_1_I2C_SSTAT_RD_NO_ERR        (0x00u)    /* Read no Error                                */

#define SCB_1_I2C_SSTAT_WR_CMPLT         (0x10u)    /* Write transfer complete                       */
#define SCB_1_I2C_SSTAT_WR_BUSY          (0x20u)    /* Write transfer in progress                    */
#define SCB_1_I2C_SSTAT_WR_ERR_OVFL      (0x40u)    /* Write overflow Error                          */
#define SCB_1_I2C_SSTAT_WR_ERR           (0x80u)    /* Write was interrupted by misplaced Start/Stop */
#define SCB_1_I2C_SSTAT_WR_MASK          (0xF0u)    /* Write Status Mask                             */
#define SCB_1_I2C_SSTAT_WR_NO_ERR        (0x00u)    /* Write no Error                                */

#define SCB_1_I2C_SSTAT_RD_CLEAR         (0x0Fu)    /* Read Status clear  */
#define SCB_1_I2C_SSTAT_WR_CLEAR         (0xF0u)    /* Write Status Clear */


/***************************************
*           I2C FSM states
***************************************/

#define SCB_1_I2C_FSM_EXIT_IDLE      (0x00u) /* Master and Slave are not active, need to exit to IDLE */

/* Slave mode FSM states */
#define SCB_1_I2C_FSM_IDLE           (0x10u) /* Idle I2C state                */
#define SCB_1_I2C_FSM_SLAVE          (0x10u) /* Slave mask for all its states */

#define SCB_1_I2C_FSM_SL_WR          (0x11u) /* Slave write states */
#define SCB_1_I2C_FSM_SL_RD          (0x12u) /* Slave read  states */

/* Master mode FSM states */
#define SCB_1_I2C_FSM_MASTER         (0x20u) /* Master mask for all its states */
#define SCB_1_I2C_FSM_MSTR_ADDR      (0x08u) /* Master address phase           */
#define SCB_1_I2C_FSM_MSTR_DATA      (0x04u) /* Master data phase              */
#define SCB_1_I2C_FSM_MSTR_RD        (0x01u) /* Master read phase              */

#define SCB_1_I2C_FSM_MSTR_WR_ADDR   (0x28u) /* FSM master transmit address with write          */
#define SCB_1_I2C_FSM_MSTR_RD_ADDR   (0x29u) /* FSM master transmit address with read           */
#define SCB_1_I2C_FSM_MSTR_WR_DATA   (0x24u) /* FSM master writes data into the slave           */
#define SCB_1_I2C_FSM_MSTR_RD_DATA   (0x25u) /* FSM master reads data from the slave            */
#define SCB_1_I2C_FSM_MSTR_HALT      (0x60u) /* FSM master halt state: wait for Stop or ReStart */

/* Request to complete any on-going transfer */
#define SCB_1_CMPLT_ANY_TRANSFER     (0x01u)

/* Returns true if FSM is in any Master state */
#define SCB_1_CHECK_I2C_FSM_MASTER   (0u != (SCB_1_I2C_FSM_MASTER & SCB_1_state))

/* Returns true if FSM is in any Slave state */
#define SCB_1_CHECK_I2C_FSM_SLAVE    (0u != (SCB_1_I2C_FSM_SLAVE  & SCB_1_state))

/* Returns true if FSM is in Master send address state */
#define SCB_1_CHECK_I2C_FSM_ADDR (0u != (SCB_1_I2C_FSM_MSTR_ADDR & SCB_1_state))

/* Returns true if FSM is in Master send or receive data state */
#define SCB_1_CHECK_I2C_FSM_DATA (0u != (SCB_1_I2C_FSM_MSTR_DATA  & SCB_1_state))

/* Returns true if FSM is in any of read states: applied for Slave and Master */
#define SCB_1_CHECK_I2C_FSM_RD   (0u != (SCB_1_I2C_FSM_MSTR_RD  & SCB_1_state))

/* Returns true if FSM is in IDLE state */
#define SCB_1_CHECK_I2C_FSM_IDLE (SCB_1_I2C_FSM_IDLE == SCB_1_state)

/* Returns true if FSM is HALT state */
#define SCB_1_CHECK_I2C_FSM_HALT (SCB_1_I2C_FSM_MSTR_HALT == SCB_1_state)

/* Set Master read or write completion depends on state */
#define SCB_1_GET_I2C_MSTAT_CMPLT (SCB_1_CHECK_I2C_FSM_RD ?           \
                                                    (SCB_1_I2C_MSTAT_RD_CMPLT) : \
                                                    (SCB_1_I2C_MSTAT_WR_CMPLT))


/***************************************
*       Macro Definitions
***************************************/

/* Return TRUE if sourceMask is set in SCB_1_I2C_MASTER_CMD_REG: used to check if Start was generated */
#define SCB_1_CHECK_I2C_MASTER_CMD(sourceMask)   (0u != (SCB_1_I2C_MASTER_CMD_REG & (sourceMask)))

/* Return TRUE if SCB_1_MODE_NO_STOP is set in SCB_1_mstrControl: used to detect NoStop condition */
#define SCB_1_CHECK_I2C_MODE_NO_STOP(mode)   (0u != (SCB_1_I2C_MODE_NO_STOP & (mode)))

/* Return TRUE if SCB_1_MODE_REPEAT_START is set: used to detect when generate ReStart condition */
#define SCB_1_CHECK_I2C_MODE_RESTART(mode)   (0u != (SCB_1_I2C_MODE_REPEAT_START  & (mode)))

/* Return TRUE if SCB_1_state is in one of master states */
#define SCB_1_CHECK_I2C_MASTER_ACTIVE    (SCB_1_CHECK_I2C_FSM_MASTER)


/***************************************
*      Default register settings
***************************************/

#define SCB_1_CTRL_I2C       (SCB_1_CTRL_MODE_I2C)

#define SCB_1_I2C_CTRL       (SCB_1_I2C_CTRL_S_GENERAL_IGNORE)

#define SCB_1_I2C_RX_CTRL    ((SCB_1_FIFO_SIZE - 1u) | \
                                         SCB_1_RX_CTRL_MSB_FIRST | \
                                         SCB_1_RX_CTRL_ENABLED)

#define SCB_1_I2C_TX_CTRL    ((SCB_1_FIFO_SIZE - 1u) | \
                                         SCB_1_TX_CTRL_MSB_FIRST | \
                                         SCB_1_TX_CTRL_ENABLED)

#define SCB_1_I2C_INTR_SLAVE_MASK    (SCB_1_INTR_SLAVE_I2C_ADDR_MATCH | \
                                                 SCB_1_INTR_SLAVE_I2C_NACK       | \
                                                 SCB_1_INTR_SLAVE_I2C_WRITE_STOP | \
                                                 SCB_1_INTR_SLAVE_I2C_BUS_ERROR)

#define SCB_1_I2C_INTR_MASTER_MASK   (SCB_1_INTR_MASTER_I2C_ARB_LOST | \
                                                 SCB_1_INTR_MASTER_I2C_NACK     | \
                                                 SCB_1_INTR_MASTER_I2C_STOP     | \
                                                 SCB_1_INTR_MASTER_I2C_BUS_ERROR)

#endif /* (CY_SCB_I2C_SCB_1_H) */


/* [] END OF FILE */
