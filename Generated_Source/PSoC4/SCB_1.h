/*******************************************************************************
* File Name: SCB_1.h
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

#if !defined(CY_SCB_SCB_1_H)
#define CY_SCB_SCB_1_H

#include "cydevice_trm.h"
#include "cyfitter.h"
#include "cytypes.h"
#include "CyLib.h"


/***************************************
*   Conditional compilation parameters
****************************************/

#define SCB_1_REMOVE_SCB_IRQ             (0u)
#define SCB_1_INTERRUPT_MODE_INTERNAL    (0u == SCB_1_REMOVE_SCB_IRQ)

#define SCB_1_REMOVE_UART_RX_WAKAUP_IRQ  (1u)
#define SCB_1_UART_RX_WAKAUP_IRQ         (0u == SCB_1_REMOVE_UART_RX_WAKAUP_IRQ)

#define SCB_1_SCB_MODE           (1u)

/* SCB modes enum */
#define SCB_1_SCB_MODE_I2C       (0x01u)
#define SCB_1_SCB_MODE_SPI       (0x02u)
#define SCB_1_SCB_MODE_UART      (0x04u)
#define SCB_1_SCB_MODE_EZI2C     (0x08u)
#define SCB_1_SCB_MODE_EZSPI     (0x10u)
#define SCB_1_SCB_MODE_UNCONFIG  (0x1Fu)

#define SCB_1_SCB_MODE_I2C_RUNTM_CFG    (SCB_1_SCB_MODE_I2C   == SCB_1_scbMode)
#define SCB_1_SCB_MODE_SPI_RUNTM_CFG    (SCB_1_SCB_MODE_SPI   == SCB_1_scbMode)
#define SCB_1_SCB_MODE_UART_RUNTM_CFG   (SCB_1_SCB_MODE_UART  == SCB_1_scbMode)
#define SCB_1_SCB_MODE_EZI2C_RUNTM_CFG  (SCB_1_SCB_MODE_EZI2C == SCB_1_scbMode)
#define SCB_1_SCB_MODE_EZSPI_RUNTM_CFG  (SCB_1_SCB_MODE_EZSPI == SCB_1_scbMode)

#define SCB_1_SCB_MODE_I2C_CONST_CFG    (0u != (SCB_1_SCB_MODE_I2C   & SCB_1_SCB_MODE))
#define SCB_1_SCB_MODE_SPI_CONST_CFG    (0u != (SCB_1_SCB_MODE_SPI   & SCB_1_SCB_MODE))
#define SCB_1_SCB_MODE_UART_CONST_CFG   (0u != (SCB_1_SCB_MODE_UART  & SCB_1_SCB_MODE))
#define SCB_1_SCB_MODE_EZI2C_CONST_CFG  (0u != (SCB_1_SCB_MODE_EZI2C & SCB_1_SCB_MODE))
#define SCB_1_SCB_MODE_EZSPI_CONST_CFG  (0u != (SCB_1_SCB_MODE_EZSPI & SCB_1_SCB_MODE))
#define SCB_1_SCB_MODE_UNCFG_CONST_CFG  (SCB_1_SCB_MODE_UNCONFIG == SCB_1_SCB_MODE)

/* SCB interrupt enum */
#define SCB_1_SCB_INTR_MODE_NONE     (0u)
#define SCB_1_SCB_INTR_MODE_INTERNAL (1u)
#define SCB_1_SCB_INTR_MODE_EXTERNAL (2u)

/* Bootloader communication interface enable */
#define SCB_1_BTLDR_COMM_ENABLED ((CYDEV_BOOTLOADER_IO_COMP == CyBtldr_SCB_1) || \
                                             (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_Custom_Interface))


/***************************************
*       inculdes
****************************************/

#if(SCB_1_SCB_MODE_I2C_CONST_CFG)
    #include "SCB_1_I2C.h"
#endif /* (SCB_1_SCB_MODE_I2C_CONST_CFG) */

#if(SCB_1_SCB_MODE_SPI_CONST_CFG || SCB_1_SCB_MODE_UART_CONST_CFG)
    #include "SCB_1_SPI_UART.h"
#endif /* (SCB_1_SCB_MODE_SPI_CONST_CFG || SCB_1_SCB_MODE_UART_CONST_CFG) */

#if(SCB_1_SCB_MODE_EZI2C_CONST_CFG || SCB_1_SCB_MODE_EZSPI_CONST_CFG)
    #include "SCB_1_EZ_MODE.h"
#endif /* (SCB_1_SCB_MODE_EZI2C_CONST_CFG || SCB_1_SCB_MODE_EZSPI_CONST_CFG) */

#if(SCB_1_INTERRUPT_MODE_INTERNAL)
    #include "SCB_1_SCB_IRQ.h"
#endif /* (SCB_1_INTERRUPT_MODE_INTERNAL) */

#if(SCB_1_UART_RX_WAKAUP_IRQ)
    #include "SCB_1_RX_WAKEUP_IRQ.h"
#endif /* (SCB_1_INTERRUPT_MODE_INTERNAL) */

#if(SCB_1_SCB_MODE_UNCFG_CONST_CFG)
    #include "SCB_1_PINS.h"
#endif /* (SCB_1_SCB_MODE_UNCFG_CONST_CFG) */


/***************************************
*        Function Prototypes
***************************************/

/* Start and Stop APIs */
void SCB_1_Init(void);
void SCB_1_Enable(void);
void SCB_1_Start(void);
void SCB_1_Stop(void);

#if(SCB_1_SCB_MODE_UNCFG_CONST_CFG)
    void SCB_1_SetPins(uint32 mode, uint32 subMode, uint32 spiSsUartTxRx);
#endif /* (SCB_1_SCB_MODE_UNCFG_CONST_CFG) */

/* Sleep and Wakeup APis */
void SCB_1_Sleep(void);
void SCB_1_Wakeup(void);

/* Customer interrupt handler */
void SCB_1_SetCustomInterruptHandler(void (*func) (void));

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (SCB_1_BTLDR_COMM_ENABLED)

    /* Bootloader Physical layer functions */
    void SCB_1_CyBtldrCommStart(void);
    void SCB_1_CyBtldrCommStop (void);
    void SCB_1_CyBtldrCommReset(void);
    cystatus SCB_1_CyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus SCB_1_CyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

    #if(CYDEV_BOOTLOADER_IO_COMP == CyBtldr_SCB_1)
        #define CyBtldrCommStart    SCB_1_CyBtldrCommStart
        #define CyBtldrCommStop     SCB_1_CyBtldrCommStop
        #define CyBtldrCommReset    SCB_1_CyBtldrCommReset
        #define CyBtldrCommWrite    SCB_1_CyBtldrCommWrite
        #define CyBtldrCommRead     SCB_1_CyBtldrCommRead
    #endif /* (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_SCB_1) */

#endif /*defined(CYDEV_BOOTLOADER_IO_COMP) && ((CYDEV_BOOTLOADER_IO_COMP == CyBtldr_SCB_1) || \
                                                     (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_Custom_Interface)) */

/* Interface to internal interrupt component */
#if(SCB_1_INTERRUPT_MODE_INTERNAL)
    #define SCB_1_EnableInt()    SCB_1_SCB_IRQ_Enable()
    #define SCB_1_DisableInt()   SCB_1_SCB_IRQ_Disable()
#endif /* (SCB_1_INTERRUPT_MODE_INTERNAL) */

/* Get interrupt cause */
#define SCB_1_GetInterruptCause()    (SCB_1_INTR_CAUSE_REG)

/* APIs to service INTR_RX register */
#define SCB_1_SetRxInterruptMode(interruptMask)      SCB_1_WRITE_INTR_RX_MASK(interruptMask)
#define SCB_1_ClearRxInterruptSource(interruptMask)  SCB_1_CLEAR_INTR_RX(interruptMask)
#define SCB_1_SetRxInterrupt(interruptMask)          SCB_1_SET_INTR_RX(interruptMask)
#define SCB_1_GetRxInterruptSource()                 (SCB_1_INTR_RX_REG)
#define SCB_1_GetRxInterruptMode()                   (SCB_1_INTR_RX_MASK_REG)
#define SCB_1_GetRxInterruptSourceMasked()           (SCB_1_INTR_RX_MASKED_REG)

/* APIs to service INTR_TX register */
#define SCB_1_SetTxInterruptMode(interruptMask)      SCB_1_WRITE_INTR_TX_MASK(interruptMask)
#define SCB_1_ClearTxInterruptSource(interruptMask)  SCB_1_CLEAR_INTR_TX(interruptMask)
#define SCB_1_SetTxInterrupt(interruptMask)          SCB_1_SET_INTR_TX(interruptMask)
#define SCB_1_GetTxInterruptSource()                 (SCB_1_INTR_TX_REG)
#define SCB_1_GetTxInterruptMode()                   (SCB_1_INTR_TX_MASK_REG)
#define SCB_1_GetTxInterruptSourceMasked()           (SCB_1_INTR_TX_MASKED_REG)

/* APIs to service INTR_MASTER register */
#define SCB_1_SetMasterInterruptMode(interruptMask)      SCB_1_WRITE_INTR_MASTER_MASK(interruptMask)
#define SCB_1_ClearMasterInterruptSource(interruptMask)  SCB_1_CLEAR_INTR_MASTER(interruptMask)
#define SCB_1_SetMasterInterrupt(interruptMask)          SCB_1_SET_INTR_MASTER(interruptMask)
#define SCB_1_GetMasterInterruptSource()                 (SCB_1_INTR_MASTER_REG)
#define SCB_1_GetMasterInterruptMode()                   (SCB_1_INTR_MASTER_MASK_REG)
#define SCB_1_GetMasterInterruptSourceMasked()           (SCB_1_INTR_MASTER_MASKED_REG)

/* APIs to service INTR_SLAVE register */
#define SCB_1_SetSlaveInterruptMode(interruptMask)       SCB_1_WRITE_INTR_SLAVE_MASK(interruptMask)
#define SCB_1_ClearSlaveInterruptSource(interruptMask)   SCB_1_CLEAR_INTR_SLAVE(interruptMask)
#define SCB_1_SetSlaveInterrupt(interruptMask)           SCB_1_SET_INTR_SLAVE(interruptMask)
#define SCB_1_GetSlaveInterruptSource()                  (SCB_1_INTR_SLAVE_REG)
#define SCB_1_GetSlaveInterruptMode()                    (SCB_1_INTR_SLAVE_MASK_REG)
#define SCB_1_GetSlaveInterruptSourceMasked()            (SCB_1_INTR_SLAVE_MASKED_REG)

/* APIs to service INTR_I2C_EC register */
#define SCB_1_SetI2CExtClkInterruptMode(interruptMask)       SCB_1_WRITE_INTR_I2C_EC_MASK(interruptMask)
#define SCB_1_ClearI2CExtClkInterruptSource(interruptMask)   SCB_1_CLEAR_INTR_I2C_EC(interruptMask)
#define SCB_1_GetI2CExtClkInterruptSource()                  (SCB_1_INTR_I2C_EC_REG)
#define SCB_1_GetI2CExtClkInterruptMode()                    (SCB_1_INTR_I2C_EC_MASK_REG)
#define SCB_1_GetI2CExtClkInterruptSourceMasked()            (SCB_1_INTR_I2C_EC_MASKED_REG)

/* APIs to service INTR_SPI_EC register */
#define SCB_1_SetSpiExtClkInterruptMode(interruptMask)       SCB_1_WRITE_INTR_SPI_EC_MASK(interruptMask)
#define SCB_1_ClearSpiExtClkInterruptSource(interruptMask)   SCB_1_CLEAR_INTR_SPI_EC(interruptMask)
#define SCB_1_GetExtSpiClkInterruptSource()                  (SCB_1_INTR_SPI_EC_REG)
#define SCB_1_GetExtSpiClkInterruptMode()                    (SCB_1_INTR_SPI_EC_MASK_REG)
#define SCB_1_GetExtSpiClkInterruptSourceMasked()            (SCB_1_INTR_SPI_EC_MASKED_REG)

/* Internal component APIs: NOT intended for customer use */
#define SCB_1_EnableRxInterrupt(sourceMask)              SCB_1_ENABLE_INTR_RX(sourceMask)
#define SCB_1_EnableTxInterrupt(sourceMask)              SCB_1_ENABLE_INTR_TX(sourceMask)
#define SCB_1_EnableMasterInterrupt(sourceMask)          SCB_1_ENABLE_INTR_MASTER(sourceMask)
#define SCB_1_EnableSlaveInterrupt(sourceMask)           SCB_1_ENABLE_INTR_SLAVE(sourceMask)
#define SCB_1_EnableI2CExtClkInterrupt(sourceMask)       SCB_1_ENABLE_INTR_I2C_EC(sourceMask)
#define SCB_1_EnableSpiExtClkInterrupt(sourceMask)       SCB_1_ENABLE_INTR_SPI_EC(sourceMask)

#define SCB_1_DisableRxInterrupt(sourceMask)             SCB_1_DISABLE_INTR_RX(sourceMask)
#define SCB_1_DisableTxInterrupt(sourceMask)             SCB_1_DISABLE_INTR_TX(sourceMask)
#define SCB_1_DisableMasterInterrupt(sourceMask)         SCB_1_DISABLE_INTR_MASTER(sourceMask)
#define SCB_1_DisableSlaveInterrupt(sourceMask)          SCB_1_DISABLE_INTR_SLAVE(sourceMask)
#define SCB_1_DisableI2CExtClkInterruptMode(sourceMask)  SCB_1_DISABLE_INTR_I2C_EC(sourceMask)
#define SCB_1_DisableSpiExtClkInterrupt(sourceMask)      SCB_1_DISABLE_INTR_SPI_EC(sourceMask)


/***************************************
*       Type defines
***************************************/

/* Structure to save registers before go to sleep */
typedef struct
{
    uint8 enableState;

} SCB_1_BACKUP_STRUCT;


/**********************************
*      Global veriables
**********************************/

extern uint8 SCB_1_initVar;

extern volatile uint32 SCB_1_scbMode;
extern volatile void * SCB_1_scbCfg;
extern void (* SCB_1_customIntrHandler) (void);
extern SCB_1_BACKUP_STRUCT SCB_1_backup;


/***************************************
*              Registers
***************************************/

#define SCB_1_CTRL_REG               (*(reg32 *) SCB_1_SCB__CTRL)
#define SCB_1_CTRL_PTR               ( (reg32 *) SCB_1_SCB__CTRL)

#define SCB_1_STATUS_REG             (*(reg32 *) SCB_1_SCB__STATUS)
#define SCB_1_STATUS_PTR             ( (reg32 *) SCB_1_SCB__STATUS)

#define SCB_1_SPI_CTRL_REG           (*(reg32 *) SCB_1_SCB__SPI_CTRL)
#define SCB_1_SPI_CTRL_PTR           ( (reg32 *) SCB_1_SCB__SPI_CTRL)

#define SCB_1_SPI_STATUS_REG         (*(reg32 *) SCB_1_SCB__SPI_STATUS)
#define SCB_1_SPI_STATUS_PTR         ( (reg32 *) SCB_1_SCB__SPI_STATUS)

#define SCB_1_UART_CTRL_REG          (*(reg32 *) SCB_1_SCB__UART_CTRL)
#define SCB_1_UART_CTRL_PTR          ( (reg32 *) SCB_1_SCB__UART_CTRL)

#define SCB_1_UART_TX_CTRL_REG       (*(reg32 *) SCB_1_SCB__UART_TX_CTRL)
#define SCB_1_UART_TX_CTRL_PTR       ( (reg32 *) SCB_1_SCB__UART_RX_CTRL)

#define SCB_1_UART_RX_CTRL_REG       (*(reg32 *) SCB_1_SCB__UART_RX_CTRL)
#define SCB_1_UART_RX_CTRL_PTR       ( (reg32 *) SCB_1_SCB__UART_RX_CTRL)

#define SCB_1_UART_RX_STATUS_REG     (*(reg32 *) SCB_1_SCB__UART_RX_STATUS)
#define SCB_1_UART_RX_STATUS_PTR     ( (reg32 *) SCB_1_SCB__UART_RX_STATUS)

#define SCB_1_I2C_CTRL_REG           (*(reg32 *) SCB_1_SCB__I2C_CTRL)
#define SCB_1_I2C_CTRL_PTR           ( (reg32 *) SCB_1_SCB__I2C_CTRL)

#define SCB_1_I2C_STATUS_REG         (*(reg32 *) SCB_1_SCB__I2C_STATUS)
#define SCB_1_I2C_STATUS_PTR         ( (reg32 *) SCB_1_SCB__I2C_STATUS)

#define SCB_1_I2C_MASTER_CMD_REG     (*(reg32 *) SCB_1_SCB__I2C_M_CMD)
#define SCB_1_I2C_MASTER_CMD_PTR     ( (reg32 *) SCB_1_SCB__I2C_M_CMD)

#define SCB_1_I2C_SLAVE_CMD_REG      (*(reg32 *) SCB_1_SCB__I2C_S_CMD)
#define SCB_1_I2C_SLAVE_CMD_PTR      ( (reg32 *) SCB_1_SCB__I2C_S_CMD)

#define SCB_1_I2C_CFG_REG            (*(reg32 *) SCB_1_SCB__I2C_CFG)
#define SCB_1_I2C_CFG_PTR            ( (reg32 *) SCB_1_SCB__I2C_CFG)

#define SCB_1_TX_CTRL_REG            (*(reg32 *) SCB_1_SCB__TX_CTRL)
#define SCB_1_TX_CTRL_PTR            ( (reg32 *) SCB_1_SCB__TX_CTRL)

#define SCB_1_TX_FIFO_CTRL_REG       (*(reg32 *) SCB_1_SCB__TX_FIFO_CTRL)
#define SCB_1_TX_FIFO_CTRL_PTR       ( (reg32 *) SCB_1_SCB__TX_FIFO_CTRL)

#define SCB_1_TX_FIFO_STATUS_REG     (*(reg32 *) SCB_1_SCB__TX_FIFO_STATUS)
#define SCB_1_TX_FIFO_STATUS_PTR     ( (reg32 *) SCB_1_SCB__TX_FIFO_STATUS)

#define SCB_1_TX_FIFO_WR_REG         (*(reg32 *) SCB_1_SCB__TX_FIFO_WR)
#define SCB_1_TX_FIFO_WR_PTR         ( (reg32 *) SCB_1_SCB__TX_FIFO_WR)

#define SCB_1_RX_CTRL_REG            (*(reg32 *) SCB_1_SCB__RX_CTRL)
#define SCB_1_RX_CTRL_PTR            ( (reg32 *) SCB_1_SCB__RX_CTRL)

#define SCB_1_RX_FIFO_CTRL_REG       (*(reg32 *) SCB_1_SCB__RX_FIFO_CTRL)
#define SCB_1_RX_FIFO_CTRL_PTR       ( (reg32 *) SCB_1_SCB__RX_FIFO_CTRL)

#define SCB_1_RX_FIFO_STATUS_REG     (*(reg32 *) SCB_1_SCB__RX_FIFO_STATUS)
#define SCB_1_RX_FIFO_STATUS_PTR     ( (reg32 *) SCB_1_SCB__RX_FIFO_STATUS)

#define SCB_1_RX_MATCH_REG           (*(reg32 *) SCB_1_SCB__RX_MATCH)
#define SCB_1_RX_MATCH_PTR           ( (reg32 *) SCB_1_SCB__RX_MATCH)

#define SCB_1_RX_FIFO_RD_REG         (*(reg32 *) SCB_1_SCB__RX_FIFO_RD)
#define SCB_1_RX_FIFO_RD_PTR         ( (reg32 *) SCB_1_SCB__RX_FIFO_RD)

#define SCB_1_RX_FIFO_RD_SILENT_REG  (*(reg32 *) SCB_1_SCB__RX_FIFO_RD_SILENT)
#define SCB_1_RX_FIFO_RD_SILENT_PTR  ( (reg32 *) SCB_1_SCB__RX_FIFO_RD_SILENT)

#define SCB_1_EZ_DATA_REG            (*(reg32 *) SCB_1_SCB__EZ_DATA00)
#define SCB_1_EZ_DATA_PTR            ( (reg32 *) SCB_1_SCB__EZ_DATA00)

#define SCB_1_INTR_CAUSE_REG         (*(reg32 *) SCB_1_SCB__INTR_CAUSE)
#define SCB_1_INTR_CAUSE_PTR         ( (reg32 *) SCB_1_SCB__INTR_CAUSE)

#define SCB_1_INTR_I2C_EC_REG        (*(reg32 *) SCB_1_SCB__INTR_I2C_EC)
#define SCB_1_INTR_I2C_EC_PTR        ( (reg32 *) SCB_1_SCB__INTR_I2C_EC)

#define SCB_1_INTR_I2C_EC_MASK_REG   (*(reg32 *) SCB_1_SCB__INTR_I2C_EC_MASK)
#define SCB_1_INTR_I2C_EC_MASK_PTR   ( (reg32 *) SCB_1_SCB__INTR_I2C_EC_MASK)

#define SCB_1_INTR_I2C_EC_MASKED_REG (*(reg32 *) SCB_1_SCB__INTR_I2C_EC_MASKED)
#define SCB_1_INTR_I2C_EC_MASKED_PTR ( (reg32 *) SCB_1_SCB__INTR_I2C_EC_MASKED)

#define SCB_1_INTR_SPI_EC_REG        (*(reg32 *) SCB_1_SCB__INTR_SPI_EC)
#define SCB_1_INTR_SPI_EC_PTR        ( (reg32 *) SCB_1_SCB__INTR_SPI_EC)

#define SCB_1_INTR_SPI_EC_MASK_REG   (*(reg32 *) SCB_1_SCB__INTR_SPI_EC_MASK)
#define SCB_1_INTR_SPI_EC_MASK_PTR   ( (reg32 *) SCB_1_SCB__INTR_SPI_EC_MASK)

#define SCB_1_INTR_SPI_EC_MASKED_REG (*(reg32 *) SCB_1_SCB__INTR_SPI_EC_MASKED)
#define SCB_1_INTR_SPI_EC_MASKED_PTR ( (reg32 *) SCB_1_SCB__INTR_SPI_EC_MASKED)

#define SCB_1_INTR_MASTER_REG        (*(reg32 *) SCB_1_SCB__INTR_M)
#define SCB_1_INTR_MASTER_PTR        ( (reg32 *) SCB_1_SCB__INTR_M)

#define SCB_1_INTR_MASTER_SET_REG    (*(reg32 *) SCB_1_SCB__INTR_M_SET)
#define SCB_1_INTR_MASTER_SET_PTR    ( (reg32 *) SCB_1_SCB__INTR_M_SET)

#define SCB_1_INTR_MASTER_MASK_REG   (*(reg32 *) SCB_1_SCB__INTR_M_MASK)
#define SCB_1_INTR_MASTER_MASK_PTR   ( (reg32 *) SCB_1_SCB__INTR_M_MASK)

#define SCB_1_INTR_MASTER_MASKED_REG (*(reg32 *) SCB_1_SCB__INTR_M_MASKED)
#define SCB_1_INTR_MASTER_MASKED_PTR ( (reg32 *) SCB_1_SCB__INTR_M_MASKED)

#define SCB_1_INTR_SLAVE_REG         (*(reg32 *) SCB_1_SCB__INTR_S)
#define SCB_1_INTR_SLAVE_PTR         ( (reg32 *) SCB_1_SCB__INTR_S)

#define SCB_1_INTR_SLAVE_SET_REG     (*(reg32 *) SCB_1_SCB__INTR_S_SET)
#define SCB_1_INTR_SLAVE_SET_PTR     ( (reg32 *) SCB_1_SCB__INTR_S_SET)

#define SCB_1_INTR_SLAVE_MASK_REG    (*(reg32 *) SCB_1_SCB__INTR_S_MASK)
#define SCB_1_INTR_SLAVE_MASK_PTR    ( (reg32 *) SCB_1_SCB__INTR_S_MASK)

#define SCB_1_INTR_SLAVE_MASKED_REG  (*(reg32 *) SCB_1_SCB__INTR_S_MASKED)
#define SCB_1_INTR_SLAVE_MASKED_PTR  ( (reg32 *) SCB_1_SCB__INTR_S_MASKED)

#define SCB_1_INTR_TX_REG            (*(reg32 *) SCB_1_SCB__INTR_TX)
#define SCB_1_INTR_TX_PTR            ( (reg32 *) SCB_1_SCB__INTR_TX)

#define SCB_1_INTR_TX_SET_REG        (*(reg32 *) SCB_1_SCB__INTR_TX_SET)
#define SCB_1_INTR_TX_SET_PTR        ( (reg32 *) SCB_1_SCB__INTR_TX_SET)

#define SCB_1_INTR_TX_MASK_REG       (*(reg32 *) SCB_1_SCB__INTR_TX_MASK)
#define SCB_1_INTR_TX_MASK_PTR       ( (reg32 *) SCB_1_SCB__INTR_TX_MASK)

#define SCB_1_INTR_TX_MASKED_REG     (*(reg32 *) SCB_1_SCB__INTR_TX_MASKED)
#define SCB_1_INTR_TX_MASKED_PTR     ( (reg32 *) SCB_1_SCB__INTR_TX_MASKED)

#define SCB_1_INTR_RX_REG            (*(reg32 *) SCB_1_SCB__INTR_RX)
#define SCB_1_INTR_RX_PTR            ( (reg32 *) SCB_1_SCB__INTR_RX)

#define SCB_1_INTR_RX_SET_REG        (*(reg32 *) SCB_1_SCB__INTR_RX_SET)
#define SCB_1_INTR_RX_SET_PTR        ( (reg32 *) SCB_1_SCB__INTR_RX_SET)

#define SCB_1_INTR_RX_MASK_REG       (*(reg32 *) SCB_1_SCB__INTR_RX_MASK)
#define SCB_1_INTR_RX_MASK_PTR       ( (reg32 *) SCB_1_SCB__INTR_RX_MASK)

#define SCB_1_INTR_RX_MASKED_REG     (*(reg32 *) SCB_1_SCB__INTR_RX_MASKED)
#define SCB_1_INTR_RX_MASKED_PTR     ( (reg32 *) SCB_1_SCB__INTR_RX_MASKED)


/***************************************
*        Registers Constants
***************************************/

/* SCB_1_CTRL */
#define SCB_1_CTRL_OVS__POS          (0u)  /* [3:0]   Oversampling factor                 */
#define SCB_1_CTRL_EC_AM_MODE__POS   (8u)  /* [8]     Externally clocked address match    */
#define SCB_1_CTRL_EC_OP_MODE__POS   (9u)  /* [9]     Externally clocked operation mode   */
#define SCB_1_CTRL_EZ_MODE__POS      (10u) /* [10]    EZ buffer is enabled                */
#define SCB_1_CTRL_ADDR_ACCEPT__POS  (16u) /* [16]    Put matched address in RX FIFO      */
#define SCB_1_CTRL_BLOCK__POS        (17u) /* [17]    Ext and Int logic to resolve colide */
#define SCB_1_CTRL_MODE__POS         (24u) /* [25:24] Operation mode                      */
#define SCB_1_CTRL_ENABLED__POS      (31u) /* [31]    Enable SCB block                    */
#define SCB_1_CTRL_OVS__MASK         ((uint32) (0x0Fu << SCB_1_CTRL_OVS__POS))
#define SCB_1_CTRL_EC_AM_MODE        ((uint32) (0x01u << SCB_1_CTRL_EC_AM_MODE__POS))
#define SCB_1_CTRL_EC_OP_MODE        ((uint32) (0x01u << SCB_1_CTRL_EC_OP_MODE__POS))
#define SCB_1_CTRL_EZ_MODE           ((uint32) (0x01u << SCB_1_CTRL_EZ_MODE__POS))
#define SCB_1_CTRL_ADDR_ACCEPT       ((uint32) (0x01u << SCB_1_CTRL_ADDR_ACCEPT__POS))
#define SCB_1_CTRL_BLOCK             ((uint32) (0x01u << SCB_1_CTRL_BLOCK__POS))
#define SCB_1_CTRL_MODE__MASK        ((uint32) (0x03u << SCB_1_CTRL_MODE__POS))
#define SCB_1_CTRL_MODE_I2C          ((uint32) (0x00u << SCB_1_CTRL_MODE__POS))
#define SCB_1_CTRL_MODE_SPI          ((uint32) (0x01u << SCB_1_CTRL_MODE__POS))
#define SCB_1_CTRL_MODE_UART         ((uint32) (0x02u << SCB_1_CTRL_MODE__POS))
#define SCB_1_CTRL_ENABLED           ((uint32) (0x01u << SCB_1_CTRL_ENABLED__POS))


/* SCB_1_STATUS_REG */
#define SCB_1_STATUS_EC_BUSY__POS    (0u)  /* [0] Bus busy. Externaly clocked loigc access to EZ memory */
#define SCB_1_STATUS_EC_BUSY         ((uint32) (0x0Fu << SCB_1_STATUS_EC_BUSY__POS))


/* SCB_1_SPI_CTRL_REG  */
#define SCB_1_SPI_CTRL_CONTINUOUS__POS       (0u)  /* [0]     Continuous or Separated SPI data transfers */
#define SCB_1_SPI_CTRL_SELECT_PRECEDE__POS   (1u)  /* [1]     Precedes or coincides start of data frame  */
#define SCB_1_SPI_CTRL_CPHA__POS             (2u)  /* [2]     SCLK phase                                 */
#define SCB_1_SPI_CTRL_CPOL__POS             (3u)  /* [3]     SCLK polarity                              */
#define SCB_1_SPI_CTRL_LATE_MISO_SAMPLE__POS (4u)  /* [4]     Late MISO sample enabled                   */
#define SCB_1_SPI_CTRL_LOOPBACK__POS         (16u) /* [16]    Local loopback control enabled             */
#define SCB_1_SPI_CTRL_MODE__POS             (24u) /* [25:24] Submode of SPI operation                   */
#define SCB_1_SPI_CTRL_SLAVE_SELECT__POS     (26u) /* [27:26] Selects SPI SS signal                      */
#define SCB_1_SPI_CTRL_MASTER_MODE__POS      (31u) /* [31]    Master mode enabled                        */
#define SCB_1_SPI_CTRL_CONTINUOUS            ((uint32) (0x01u << SCB_1_SPI_CTRL_CONTINUOUS__POS))
#define SCB_1_SPI_CTRL_SELECT_PRECEDE        ((uint32) (0x01u << SCB_1_SPI_CTRL_SELECT_PRECEDE__POS))
#define SCB_1_SPI_CTRL_CPHA                  ((uint32) (0x01u << SCB_1_SPI_CTRL_CPHA__POS))
#define SCB_1_SPI_CTRL_CPOL                  ((uint32) (0x01u << SCB_1_SPI_CTRL_CPOL__POS))
#define SCB_1_SPI_CTRL_LATE_MISO_SAMPLE      ((uint32) (0x01u << SCB_1_SPI_CTRL_LATE_MISO_SAMPLE__POS))
#define SCB_1_SPI_CTRL_LOOPBACK              ((uint32) (0x01u << SCB_1_SPI_CTRL_LOOPBACK__POS))
#define SCB_1_SPI_CTRL_MODE__MASK            ((uint32) (0x03u << SCB_1_SPI_CTRL_MODE__POS))
#define SCB_1_SPI_CTRL_MODE_MOTOROLA         ((uint32) (0x00u << SCB_1_CTRL_MODE__POS))
#define SCB_1_SPI_CTRL_MODE_TI               ((uint32) (0x01u << SCB_1_CTRL_MODE__POS))
#define SCB_1_SPI_CTRL_MODE_NS               ((uint32) (0x02u << SCB_1_CTRL_MODE__POS))
#define SCB_1_SPI_CTRL_SLAVE_SELECT__MASK    ((uint32) (0x03u << SCB_1_SPI_CTRL_SLAVE_SELECT__POS))
#define SCB_1_SPI_CTRL_SLAVE_SELECT0         ((uint32) (0x00u << SCB_1_SPI_CTRL_SLAVE_SELECT__POS))
#define SCB_1_SPI_CTRL_SLAVE_SELECT1         ((uint32) (0x01u << SCB_1_SPI_CTRL_SLAVE_SELECT__POS))
#define SCB_1_SPI_CTRL_SLAVE_SELECT2         ((uint32) (0x02u << SCB_1_SPI_CTRL_SLAVE_SELECT__POS))
#define SCB_1_SPI_CTRL_SLAVE_SELECT3         ((uint32) (0x03u << SCB_1_SPI_CTRL_SLAVE_SELECT__POS))
#define SCB_1_SPI_CTRL_MASTER                ((uint32) (0x01u << SCB_1_SPI_CTRL_MASTER_MODE__POS))
#define SCB_1_SPI_CTRL_SLAVE                 ((uint32) (0x00u << SCB_1_SPI_CTRL_MASTER_MODE__POS))


/* SCB_1_SPI_STATUS_REG  */
#define SCB_1_SPI_STATUS_BUS_BUSY__POS   (0u)  /* [0]    Bus busy - slave selected */
#define SCB_1_SPI_STATUS_EZ_ADDR__POS    (8u)  /* [15:8] EzAddress                 */

#define SCB_1_SPI_STATUS_BUS_BUSY        ((uint32) (0x01u << SCB_1_I2C_STATUS_BUS_BUSY__POS))
#define SCB_1_SPI_STATUS_EZ_ADDR__MASK   ((uint32) (0xFFu << SCB_1_I2C_STATUS_EZ_ADDR__POS))


/* SCB_1_UART_CTRL */
#define SCB_1_UART_CTRL_LOOPBACK__POS    (16u) /* [16] Loopback     */
#define SCB_1_UART_CTRL_MODE__POS        (24u) /* [24] UART subMode */

#define SCB_1_UART_CTRL_LOOPBACK             ((uint32) (0x01u << SCB_1_UART_CTRL_LOOPBACK__POS))
#define SCB_1_UART_CTRL_MODE_UART_STD        ((uint32) (0x00u << SCB_1_UART_CTRL_MODE__POS))
#define SCB_1_UART_CTRL_MODE_UART_SMARTCARD  ((uint32) (0x01u << SCB_1_UART_CTRL_MODE__POS))
#define SCB_1_UART_CTRL_MODE_UART_IRDA       ((uint32) (0x02u << SCB_1_UART_CTRL_MODE__POS))
#define SCB_1_UART_CTRL_MODE__MASK           ((uint32) (0x03u << SCB_1_UART_CTRL_MODE__POS))


/* SCB_1_UART_TX_CTRL */
#define SCB_1_UART_TX_CTRL_STOP_BITS__POS        (0u)  /* Stop bits: (Stop bits + 1) * 0.5 period */
#define SCB_1_UART_TX_CTRL_PARITY__POS           (4u)  /* Parity bit                              */
#define SCB_1_UART_TX_CTRL_PARITY_ENABLED__POS   (5u)  /* Parity enable                           */
#define SCB_1_UART_TX_CTRL_RETRY_ON_NACK__POS    (8u)  /* Smart Card: re-send frame on NACK       */
#define SCB_1_UART_TX_CTRL_ONE_STOP_BIT          ((uint32) (0x01u << SCB_1_UART_TX_CTRL_STOP_BITS__POS))
#define SCB_1_UART_TX_CTRL_ONE_HALF_STOP_BITS    ((uint32) (0x02u << SCB_1_UART_TX_CTRL_STOP_BITS__POS))
#define SCB_1_UART_TX_CTRL_TWO_STOP_BITS         ((uint32) (0x03u << SCB_1_UART_TX_CTRL_STOP_BITS__POS))
#define SCB_1_UART_TX_CTRL_STOP_BITS__MASK       ((uint32) (0x07u << SCB_1_UART_TX_CTRL_STOP_BITS__POS))
#define SCB_1_UART_TX_CTRL_PARITY                ((uint32) (0x01u << SCB_1_UART_TX_CTRL_PARITY__POS))
#define SCB_1_UART_TX_CTRL_PARITY_ENABLED        ((uint32) (0x01u << SCB_1_UART_TX_CTRL_PARITY_ENABLED__POS))
#define SCB_1_UART_TX_CTRL_RETRY_ON_NACK         ((uint32) (0x01u << SCB_1_UART_TX_CTRL_RETRY_ON_NACK__POS))


/* SCB_1_UART_RX_CTRL */
#define SCB_1_UART_RX_CTRL_STOP_BITS__POS            (0u)  /* Stop bits: (Stop bits + 1) * 0.5 period     */
#define SCB_1_UART_RX_CTRL_PARITY__POS               (4u)  /* Parity bit                                  */
#define SCB_1_UART_RX_CTRL_PARITY_ENABLED__POS       (5u)  /* Parity enable                               */
#define SCB_1_UART_RX_CTRL_POLARITY__POS             (6u)  /* IrDA: inverts polarity of incomming signal  */
#define SCB_1_UART_RX_CTRL_DROP_ON_PARITY_ERR__POS   (8u)  /* Drop and lost RX FIFO on parity error       */
#define SCB_1_UART_RX_CTRL_DROP_ON_FRAME_ERR__POS    (9u)  /* Drop and lost RX FIFO on frame error        */
#define SCB_1_UART_RX_CTRL_MP_MODE__POS              (10u) /* Multi-processor mode                        */
#define SCB_1_UART_RX_CTRL_LIN_MODE__POS             (12u) /* Lin mode: only applicable for UART Standart */
#define SCB_1_UART_RX_CTRL_SKIP_START__POS           (13u) /* Skip start not: only for UART Standart      */
#define SCB_1_UART_RX_CTRL_BREAK_WIDTH__POS          (16u) /* Break width: (Break width + 1)              */
#define SCB_1_UART_TX_CTRL_ONE_STOP_BIT              ((uint32) (0x01u << SCB_1_UART_TX_CTRL_STOP_BITS__POS))
#define SCB_1_UART_TX_CTRL_ONE_HALF_STOP_BITS        ((uint32) (0x02u << SCB_1_UART_TX_CTRL_STOP_BITS__POS))
#define SCB_1_UART_TX_CTRL_TWO_STOP_BITS             ((uint32) (0x03u << SCB_1_UART_TX_CTRL_STOP_BITS__POS))
#define SCB_1_UART_RX_CTRL_STOP_BITS__MASK           ((uint32) (0x07u << SCB_1_UART_RX_CTRL_STOP_BITS__POS))
#define SCB_1_UART_RX_CTRL_PARITY                    ((uint32) (0x01u << SCB_1_UART_RX_CTRL_PARITY__POS))
#define SCB_1_UART_RX_CTRL_PARITY_ENABLED            ((uint32) (0x01u << \
                                                                  SCB_1_UART_RX_CTRL_PARITY_ENABLED__POS))
#define SCB_1_UART_RX_CTRL_POLARITY                  ((uint32) (0x01u << SCB_1_UART_RX_CTRL_POLARITY__POS))
#define SCB_1_UART_RX_CTRL_DROP_ON_PARITY_ERR        ((uint32) (0x01u << \
                                                                  SCB_1_UART_RX_CTRL_DROP_ON_PARITY_ERR__POS))
#define SCB_1_UART_RX_CTRL_DROP_ON_FRAME_ERR         ((uint32) (0x01u << \
                                                                  SCB_1_UART_RX_CTRL_DROP_ON_FRAME_ERR__POS))
#define SCB_1_UART_RX_CTRL_MP_MODE                   ((uint32) (0x01u << SCB_1_UART_RX_CTRL_MP_MODE__POS))
#define SCB_1_UART_RX_CTRL_LIN_MODE                  ((uint32) (0x01u << SCB_1_UART_RX_CTRL_LIN_MODE__POS))
#define SCB_1_UART_RX_CTRL_SKIP_START                ((uint32) (0x01u << \
                                                                  SCB_1_UART_RX_CTRL_SKIP_START__POS))
#define SCB_1_UART_RX_CTRL_BREAK_WIDTH__MASK         ((uint32) (0x0Fu << \
                                                                  SCB_1_UART_RX_CTRL_BREAK_WIDTH__POS))

/* SCB_1_UART_RX_STATUS_REG */
#define SCB_1_UART_RX_STATUS_BR_COUNTER__POS     (0u)  /* Baute Rate counter */
#define SCB_1_UART_RX_STATUS_BR_COUNTER__MASK    ((uint32) (0xFFFu << SCB_1_UART_RX_CTRL_BREAK_WIDTH__POS))


/* SCB_1_I2C_CTRL */
#define SCB_1_I2C_CTRL_HIGH_PHASE_OVS__POS           (0u)   /* [3:0] Oversampling factor high: masrer only */
#define SCB_1_I2C_CTRL_LOW_PHASE_OVS__POS            (4u)   /* [7:4] Oversampling factor low:  masrer only */
#define SCB_1_I2C_CTRL_M_READY_DATA_ACK__POS         (8u)   /* [8]   Master ACKs data wgile RX FIFO != FULL*/
#define SCB_1_I2C_CTRL_M_NOT_READY_DATA_NACK__POS    (9u)   /* [9]   Master NACKs data if RX FIFO ==  FULL */
#define SCB_1_I2C_CTRL_S_GENERAL_IGNORE__POS         (11u)  /* [11]  Slave ignores General call            */
#define SCB_1_I2C_CTRL_S_READY_ADDR_ACK__POS         (12u)  /* [12]  Slave ACKs Address if RX FIFO != FULL */
#define SCB_1_I2C_CTRL_S_READY_DATA_ACK__POS         (13u)  /* [13]  Slave ACKs data while RX FIFO == FULL */
#define SCB_1_I2C_CTRL_S_NOT_READY_ADDR_NACK__POS    (14u)  /* [14]  Slave NACKs address if RX FIFO == FULL*/
#define SCB_1_I2C_CTRL_S_NOT_READY_DATA_NACK__POS    (15u)  /* [15]  Slave NACKs data if RX FIFO is  FULL  */
#define SCB_1_I2C_CTRL_LOOPBACK__POS                 (16u)  /* [16]  Loopback                              */
#define SCB_1_I2C_CTRL_SLAVE_MODE__POS               (30u)  /* [30]  Slave mode enabled                    */
#define SCB_1_I2C_CTRL_MASTER_MODE__POS              (31u)  /* [31]  Master mode enabled                   */
#define SCB_1_I2C_CTRL_HIGH_PHASE_OVS__MASK          ((uint32) (0x0Fu << \
                                                                   SCB_1_I2C_CTRL_HIGH_PHASE_OVS__POS))
#define SCB_1_I2C_CTRL_LOW_PHASE_OVS__MASK           ((uint32) (0x0Fu << SCB_1_I2C_CTRL_LOW_PHASE_OVS__POS))
#define SCB_1_I2C_CTRL_M_READY_DATA_ACK              ((uint32) (0x01u << \
                                                                   SCB_1_I2C_CTRL_M_READY_DATA_ACK__POS))
#define SCB_1_I2C_CTRL_M_NOT_READY_DATA_NACK         ((uint32) (0x01u << \
                                                                   SCB_1_I2C_CTRL_M_NOT_READY_DATA_NACK__POS))
#define SCB_1_I2C_CTRL_S_GENERAL_IGNORE              ((uint32) (0x01u << \
                                                                   SCB_1_I2C_CTRL_S_GENERAL_IGNORE__POS))
#define SCB_1_I2C_CTRL_S_READY_ADDR_ACK              ((uint32) (0x01u << \
                                                                   SCB_1_I2C_CTRL_S_READY_ADDR_ACK__POS))
#define SCB_1_I2C_CTRL_S_READY_DATA_ACK              ((uint32) (0x01u << \
                                                                   SCB_1_I2C_CTRL_S_READY_DATA_ACK__POS))
#define SCB_1_I2C_CTRL_S_NOT_READY_ADDR_NACK         ((uint32) (0x01u << \
                                                                   SCB_1_I2C_CTRL_S_NOT_READY_ADDR_NACK__POS))
#define SCB_1_I2C_CTRL_S_NOT_READY_DATA_NACK         ((uint32) (0x01u << \
                                                                   SCB_1_I2C_CTRL_S_NOT_READY_DATA_NACK__POS))
#define SCB_1_I2C_CTRL_LOOPBACK                      ((uint32) (0x01u << SCB_1_I2C_CTRL_LOOPBACK__POS))
#define SCB_1_I2C_CTRL_SLAVE_MODE                    ((uint32) (0x01u << SCB_1_I2C_CTRL_SLAVE_MODE__POS))
#define SCB_1_I2C_CTRL_MASTER_MODE                   ((uint32) (0x01u << SCB_1_I2C_CTRL_MASTER_MODE__POS))


/* SCB_1_I2C_STATUS_REG  */
#define SCB_1_I2C_STATUS_BUS_BUSY__POS   (0u)  /* [0]    Bus busy: internally clocked */
#define SCB_1_I2C_STATUS_S_READ__POS     (4u)  /* [4]    Slave is read by master      */
#define SCB_1_I2C_STATUS_M_READ__POS     (5u)  /* [5]    Master reads Slave           */
#define SCB_1_I2C_STATUS_EZ_ADDR__POS    (8u)  /* [15:8] EZAddress                    */
#define SCB_1_I2C_STATUS_BUS_BUSY        ((uint32) (0x01u << SCB_1_I2C_STATUS_BUS_BUSY__POS))
#define SCB_1_I2C_STATUS_S_READ          ((uint32) (0x01u << SCB_1_I2C_STATUS_S_READ__POS))
#define SCB_1_I2C_STATUS_M_READ          ((uint32) (0x01u << SCB_1_I2C_STATUS_M_READ__POS))
#define SCB_1_I2C_STATUS_EZ_ADDR__MASK   ((uint32) (0xFFu << SCB_1_I2C_STATUS_EZ_ADDR__POS))


/* SCB_1_I2C_MASTER_CMD_REG */
#define SCB_1_I2C_MASTER_CMD_M_START__POS            (0u)  /* [0] Master generate Start                */
#define SCB_1_I2C_MASTER_CMD_M_START_ON_IDLE__POS    (1u)  /* [1] Master generate Start if bus is free */
#define SCB_1_I2C_MASTER_CMD_M_ACK__POS              (2u)  /* [2] Master generate ACK                  */
#define SCB_1_I2C_MASTER_CMD_M_NACK__POS             (3u)  /* [3] Master generate NACK                 */
#define SCB_1_I2C_MASTER_CMD_M_STOP__POS             (4u)  /* [4] Master generate Stop                 */
#define SCB_1_I2C_MASTER_CMD_M_START                 ((uint32) (0x01u << SCB_1_I2C_MASTER_CMD_M_START__POS))
#define SCB_1_I2C_MASTER_CMD_M_START_ON_IDLE         ((uint32) (0x01u << \
                                                                   SCB_1_I2C_MASTER_CMD_M_START_ON_IDLE__POS))
#define SCB_1_I2C_MASTER_CMD_M_ACK                   ((uint32) (0x01u << SCB_1_I2C_MASTER_CMD_M_ACK__POS))
#define SCB_1_I2C_MASTER_CMD_M_NACK                  ((uint32) (0x01u << SCB_1_I2C_MASTER_CMD_M_NACK__POS))
#define SCB_1_I2C_MASTER_CMD_M_STOP                  ((uint32) (0x01u << SCB_1_I2C_MASTER_CMD_M_STOP__POS))


/* SCB_1_I2C_SLAVE_CMD_REG  */
#define SCB_1_I2C_SLAVE_CMD_S_ACK__POS   (0u)  /* [0] Slave generate ACK  */
#define SCB_1_I2C_SLAVE_CMD_S_NACK__POS  (1u)  /* [1] Slave generate NACK */
#define SCB_1_I2C_SLAVE_CMD_S_ACK        ((uint32) (0x01u << SCB_1_I2C_SLAVE_CMD_S_ACK__POS))
#define SCB_1_I2C_SLAVE_CMD_S_NACK       ((uint32) (0x01u << SCB_1_I2C_SLAVE_CMD_S_NACK__POS))


/* SCB_1_TX_CTRL_REG */
#define SCB_1_TX_CTRL_DATA_WIDTH__POS    (0u)  /* [3:0] Dataframe width: (Data width - 1) */
#define SCB_1_TX_CTRL_MSB_FIRST__POS     (8u)  /* [8]   MSB first shifter-out             */
#define SCB_1_TX_CTRL_ENABLED__POS       (31u) /* [31]  Transmitter enabled               */
#define SCB_1_TX_CTRL_DATA_WIDTH_MASK    ((uint32) (0x0Fu << SCB_1_TX_CTRL_DATA_WIDTH__POS))
#define SCB_1_TX_CTRL_MSB_FIRST          ((uint32) (0x01u << SCB_1_TX_CTRL_MSB_FIRST__POS))
#define SCB_1_TX_CTRL_LSB_FIRST          ((uint32) (0x00u << SCB_1_TX_CTRL_MSB_FIRST__POS))
#define SCB_1_TX_CTRL_ENABLED            ((uint32) (0x01u << SCB_1_TX_CTRL_ENABLED__POS))


/* SCB_1_TX_CTRL_FIFO_REG */
#define SCB_1_TX_FIFO_CTRL_TRIGGER_LEVEL__POS    (0u)  /* [2:0] Trigger level                              */
#define SCB_1_TX_FIFO_CTRL_CLEAR__POS            (16u) /* [16]  Clear TX FIFO: claared after set           */
#define SCB_1_TX_FIFO_CTRL_FREEZE__POS           (17u) /* [17]  Freeze TX FIFO: HW do not inc read pointer */
#define SCB_1_TX_FIFO_CTRL_TRIGGER_LEVEL_MASK    ((uint32) (0x07u << SCB_1_TX_FIFO_CTRL_TRIGGER_LEVEL__POS))
#define SCB_1_TX_FIFO_CTRL_CLEAR                 ((uint32) (0x01u << SCB_1_TX_FIFO_CTRL_CLEAR__POS))
#define SCB_1_TX_FIFO_CTRL_FREEZE                ((uint32) (0x01u << SCB_1_TX_FIFO_CTRL_FREEZE__POS))


/* SCB_1_TX_FIFO_STATUS_REG */
#define SCB_1_TX_FIFO_STATUS_USED__POS       (0u)  /* [3:0]   Amount of entries in TX FIFO */
#define SCB_1_TX_FIFO_SR_VALID__POS          (15u) /* [15]    Shifter status of TX FIFO    */
#define SCB_1_TX_FIFO_STATUS_RD_PTR__POS     (16u) /* [18:16] TX FIFO read pointer         */
#define SCB_1_TX_FIFO_STATUS_WR_PTR__POS     (24u) /* [26:24] TX FIFO write pointer        */
#define SCB_1_TX_FIFO_STATUS_USED__MASK      ((uint32) (0x0Fu << SCB_1_TX_FIFO_STATUS_USED__POS))
#define SCB_1_TX_FIFO_SR_VALID               ((uint32) (0x01u << SCB_1_TX_FIFO_SR_VALID__POS))
#define SCB_1_TX_FIFO_STATUS_RD_PTR__MASK    ((uint32) (0x07u << SCB_1_TX_FIFO_STATUS_RD_PTR__POS))
#define SCB_1_TX_FIFO_STATUS_WR_PTR__MASK    ((uint32) (0x07u << SCB_1_TX_FIFO_STATUS_WR_PTR__POS))


/* SCB_1_TX_FIFO_WR_REG */
#define SCB_1_TX_FIFO_WR__POS    (0u)  /* [15:0] Data written into TX FIFO */
#define SCB_1_TX_FIFO_WR__MASK   ((uint32) (0xFFu << SCB_1_TX_FIFO_WR__POS))


/* SCB_1_RX_CTRL_REG */
#define SCB_1_RX_CTRL_DATA_WIDTH__POS    (0u)  /* [3:0] Dataframe width: (Data width - 1) */
#define SCB_1_RX_CTRL_MSB_FIRST__POS     (8u)  /* [8]   MSB first shifter-out             */
#define SCB_1_RX_CTRL_MEDIAN__POS        (9u)  /* [9]   Median filter                     */
#define SCB_1_RX_CTRL_ENABLED__POS       (31u) /* [31]  Receiver enabled                  */
#define SCB_1_RX_CTRL_DATA_WIDTH__MASK   ((uint32) (0x0Fu << SCB_1_RX_CTRL_DATA_WIDTH__POS))
#define SCB_1_RX_CTRL_MSB_FIRST          ((uint32) (0x01u << SCB_1_RX_CTRL_MSB_FIRST__POS))
#define SCB_1_RX_CTRL_LSB_FIRST          ((uint32) (0x00u << SCB_1_RX_CTRL_MSB_FIRST__POS))
#define SCB_1_RX_CTRL_MEDIAN             ((uint32) (0x01u << SCB_1_RX_CTRL_MEDIAN__POS))
#define SCB_1_RX_CTRL_ENABLED            ((uint32) (0x01u << SCB_1_RX_CTRL_ENABLED__POS))


/* SCB_1_RX_FIFO_CTRL_REG */
#define SCB_1_RX_FIFO_CTRL_TRIGGER_LEVEL__POS    (0u)   /* [2:0] Trigger level                            */
#define SCB_1_RX_FIFO_CTRL_CLEAR__POS            (16u)  /* [16]  Clear RX FIFO: claar after set           */
#define SCB_1_RX_FIFO_CTRL_FREEZE__POS           (17u)  /* [17]  Freeze RX FIFO: HW writes has not effect */
#define SCB_1_RX_FIFO_CTRL_TRIGGER_LEVEL_MASK    ((uint32) (0x07u << SCB_1_RX_FIFO_CTRL_TRIGGER_LEVEL__POS))
#define SCB_1_RX_FIFO_CTRL_CLEAR                 ((uint32) (0x01u << SCB_1_RX_FIFO_CTRL_CLEAR__POS))
#define SCB_1_RX_FIFO_CTRL_FREEZE                ((uint32) (0x01u << SCB_1_RX_FIFO_CTRL_FREEZE__POS))


/* SCB_1_RX_FIFO_STATUS_REG */
#define SCB_1_RX_FIFO_STATUS_USED__POS       (0u)   /* [3:0]   Amount of entries in RX FIFO */
#define SCB_1_RX_FIFO_SR_VALID__POS          (15u)  /* [15]    Shifter status of RX FIFO    */
#define SCB_1_RX_FIFO_STATUS_RD_PTR__POS     (16u)  /* [18:16] RX FIFO read pointer         */
#define SCB_1_RX_FIFO_STATUS_WR_PTR__POS     (24u)  /* [26:24] RX FIFO write pointer        */
#define SCB_1_RX_FIFO_STATUS_USED__MASK      ((uint32) (0x0Fu << SCB_1_RX_FIFO_STATUS_USED__POS))
#define SCB_1_RX_FIFO_SR_VALID               ((uint32) (0x01u << SCB_1_RX_FIFO_SR_VALID__POS))
#define SCB_1_RX_FIFO_STATUS_RD_PTR__MASK    ((uint32) (0x07u << SCB_1_RX_FIFO_STATUS_RD_PTR__POS))
#define SCB_1_RX_FIFO_STATUS_WR_PTR__MASK    ((uint32) (0x07u << SCB_1_RX_FIFO_STATUS_WR_PTR__POS))


/* SCB_1_RX_MATCH_REG */
#define SCB_1_RX_MATCH_ADDR__POS     (0u)  /* [7:0]   Slave address                        */
#define SCB_1_RX_MATCH_MASK__POS     (16u) /* [23:16] Slave address mask: 0 - doesn't care */
#define SCB_1_RX_MATCH_ADDR__MASK    ((uint32) (0xFFu << SCB_1_RX_MATCH_ADDR__POS))
#define SCB_1_RX_MATCH_MASK__MASK    ((uint32) (0xFFu << SCB_1_RX_MATCH_MASK__POS))


/* SCB_1_RX_FIFO_WR_REG */
#define SCB_1_RX_FIFO_RD__POS    (0u)  /* [15:0] Data read from RX FIFO */
#define SCB_1_RX_FIFO_RD__MASK   ((uint32) (0xFFu << SCB_1_RX_FIFO_RD__POS))


/* SCB_1_RX_FIFO_RD_SILENT_REG */
#define SCB_1_RX_FIFO_RD_SILENT__POS     (0u)  /* [15:0] Data read from RX FIFO: not remove data from FIFO */
#define SCB_1_RX_FIFO_RD_SILENT__MASK    ((uint32) (0xFFu << SCB_1_RX_FIFO_RD_SILENT__POS))

/* SCB_1_RX_FIFO_RD_SILENT_REG */
#define SCB_1_RX_FIFO_RD_SILENT__POS     (0u)  /* [15:0] Data read from RX FIFO: not remove data from FIFO */
#define SCB_1_RX_FIFO_RD_SILENT__MASK    ((uint32) (0xFFu << SCB_1_RX_FIFO_RD_SILENT__POS))

/* SCB_1_EZ_DATA_REG */
#define SCB_1_EZ_DATA__POS   (0u)  /* [7:0] Data from Ez Memory */
#define SCB_1_EZ_DATA__MASK  ((uint32) (0xFFu << SCB_1_EZ_DATA__POS))

/*  SCB_1_INTR_CAUSE_REG */
#define SCB_1_INTR_CAUSE_MASTER__POS (0u)  /* [0] Master interrupt active                 */
#define SCB_1_INTR_CAUSE_SLAVE__POS  (1u)  /* [1] Slave interrupt active                  */
#define SCB_1_INTR_CAUSE_TX__POS     (2u)  /* [2] Transmitter interrupt active            */
#define SCB_1_INTR_CAUSE_RX__POS     (3u)  /* [3] Receiver interrupt active               */
#define SCB_1_INTR_CAUSE_I2C_EC__POS (4u)  /* [4] Externally clock I2C interrupt active   */
#define SCB_1_INTR_CAUSE_SPI_EC__POS (5u)  /* [5] Externally clocked SPI interrupt active */
#define SCB_1_INTR_CAUSE_MASTER      ((uint32) (0x01u << SCB_1_INTR_CAUSE_MASTER__POS))
#define SCB_1_INTR_CAUSE_SLAVE       ((uint32) (0x01u << SCB_1_INTR_CAUSE_SLAVE__POS))
#define SCB_1_INTR_CAUSE_TX          ((uint32) (0x01u << SCB_1_INTR_CAUSE_TX__POS))
#define SCB_1_INTR_CAUSE_RX          ((uint32) (0x01u << SCB_1_INTR_CAUSE_RX__POS))
#define SCB_1_INTR_CAUSE_I2C_EC      ((uint32) (0x01u << SCB_1_INTR_CAUSE_I2C_EC__POS))
#define SCB_1_INTR_CAUSE_SPI_EC      ((uint32) (0x01u << SCB_1_INTR_CAUSE_SPI_EC__POS))


/* SCB_1_INTR_SPI_EC_REG, SCB_1_INTR_SPI_EC_MASK_REG, SCB_1_INTR_SPI_EC_MASKED_REG */
#define SCB_1_INTR_SPI_EC_WAKE_UP__POS       (0u)  /* [0] Address match: triggers wakeup of chip */
#define SCB_1_INTR_SPI_EC_EZ_STOP__POS       (1u)  /* [1] Externally clocked Stop detected       */
#define SCB_1_INTR_SPI_EC_EZ_WRITE_STOP__POS (2u)  /* [2] Externally clocked Write Stop detected */
#define SCB_1_INTR_SPI_EC_WAKE_UP            ((uint32) (0x01u << SCB_1_INTR_SPI_EC_WAKE_UP__POS))
#define SCB_1_INTR_SPI_EC_EZ_STOP            ((uint32) (0x01u << SCB_1_INTR_SPI_EC_EZ_STOP__POS))
#define SCB_1_INTR_SPI_EC_EZ_WRITE_STOP      ((uint32) (0x01u << SCB_1_INTR_SPI_EC_EZ_WRITE_STOP__POS))


/* SCB_1_INTR_I2C_EC, SCB_1_INTR_I2C_EC_MASK, SCB_1_INTR_I2C_EC_MASKED */
#define SCB_1_INTR_I2C_EC_WAKE_UP__POS       (0u)  /* [0] Address match: triggers wakeup of chip */
#define SCB_1_INTR_I2C_EC_EZ_STOP__POS       (1u)  /* [1] Externally clocked Stop detected       */
#define SCB_1_INTR_I2C_EC_EZ_WRITE_STOP__POS (2u)  /* [2] Externally clocked Write Stop detected */
#define SCB_1_INTR_I2C_EC_WAKE_UP            ((uint32) (0x01u << SCB_1_INTR_I2C_EC_WAKE_UP__POS))
#define SCB_1_INTR_I2C_EC_EZ_STOP            ((uint32) (0x01u << SCB_1_INTR_I2C_EC_EZ_STOP__POS))
#define SCB_1_INTR_I2C_EC_EZ_WRITE_STOP      ((uint32) (0x01u << SCB_1_INTR_I2C_EC_EZ_WRITE_STOP__POS))


/* SCB_1_INTR_MASTER, SCB_1_INTR_MASTER_SET,
   SCB_1_INTR_MASTER_MASK, SCB_1_INTR_MASTER_MASKED */
#define SCB_1_INTR_MASTER_I2C_ARB_LOST__POS  (0u)  /* [0] Master lost arbitration                          */
#define SCB_1_INTR_MASTER_I2C_NACK__POS      (1u)  /* [1] Master receives NACK: address or write to slave  */
#define SCB_1_INTR_MASTER_I2C_ACK__POS       (2u)  /* [2] Master receives NACK: address or write to slave  */
#define SCB_1_INTR_MASTER_I2C_STOP__POS      (4u)  /* [4] Master detects the Stop: only self generated Stop*/
#define SCB_1_INTR_MASTER_I2C_BUS_ERROR__POS (8u)  /* [8] Master detects bus error: misplaced Start or Stop*/
#define SCB_1_INTR_MASTER_SPI_DONE__POS      (9u)  /* [9] Master complete trasfer: Only for SPI            */
#define SCB_1_INTR_MASTER_I2C_ARB_LOST       ((uint32) (0x01u << SCB_1_INTR_MASTER_I2C_ARB_LOST__POS))
#define SCB_1_INTR_MASTER_I2C_NACK           ((uint32) (0x01u << SCB_1_INTR_MASTER_I2C_NACK__POS))
#define SCB_1_INTR_MASTER_I2C_ACK            ((uint32) (0x01u << SCB_1_INTR_MASTER_I2C_ACK__POS))
#define SCB_1_INTR_MASTER_I2C_STOP           ((uint32) (0x01u << SCB_1_INTR_MASTER_I2C_STOP__POS))
#define SCB_1_INTR_MASTER_I2C_BUS_ERROR      ((uint32) (0x01u << SCB_1_INTR_MASTER_I2C_BUS_ERROR__POS))
#define SCB_1_INTR_MASTER_SPI_DONE           ((uint32) (0x01u << SCB_1_INTR_MASTER_SPI_DONE__POS))

/* SCB_1_INTR_SLAVE, SCB_1_INTR_SLAVE_SET,
   SCB_1_INTR_SLAVE_MASK, SCB_1_INTR_SLAVE_MASKED */
#define SCB_1_INTR_SLAVE_I2C_ARB_LOST__POS       (0u)  /* [0]  Slave lost arbitration                   */
#define SCB_1_INTR_SLAVE_I2C_NACK__POS           (1u)  /* [1]  Slave receives NACK: master reads data   */
#define SCB_1_INTR_SLAVE_I2C_ACK__POS            (2u)  /* [2]  Slave receives ACK: master reads data    */
#define SCB_1_INTR_SLAVE_I2C_WRITE_STOP__POS     (3u)  /* [3]  Slave detects end of write transaction   */
#define SCB_1_INTR_SLAVE_I2C_STOP__POS           (4u)  /* [4]  Slave detects end of transaction intened */
#define SCB_1_INTR_SLAVE_I2C_START__POS          (5u)  /* [5]  Slave detects Start                      */
#define SCB_1_INTR_SLAVE_I2C_ADDR_MATCH__POS     (6u)  /* [6]  Slave address matches                    */
#define SCB_1_INTR_SLAVE_I2C_GENERAL__POS        (7u)  /* [7]  General call received                    */
#define SCB_1_INTR_SLAVE_I2C_BUS_ERROR__POS      (8u)  /* [8]  Slave detects bus error                  */
#define SCB_1_INTR_SLAVE_SPI_EZ_WRITE_STOP__POS  (9u)  /* [9]  Slave write complete: Only for SPI       */
#define SCB_1_INTR_SLAVE_SPI_EZ_STOP__POS        (10u) /* [10] Slave end of transaciton: Only for SPI   */
#define SCB_1_INTR_SLAVE_SPI_BUS_ERROR__POS      (11u) /* [11] Slave detects bus error: Only for SPI    */
#define SCB_1_INTR_SLAVE_I2C_ARB_LOST            ((uint32) (0x01u << SCB_1_INTR_SLAVE_I2C_ARB_LOST__POS))
#define SCB_1_INTR_SLAVE_I2C_NACK                ((uint32) (0x01u << SCB_1_INTR_SLAVE_I2C_NACK__POS))
#define SCB_1_INTR_SLAVE_I2C_ACK                 ((uint32) (0x01u << SCB_1_INTR_SLAVE_I2C_ACK__POS))
#define SCB_1_INTR_SLAVE_I2C_WRITE_STOP          ((uint32) (0x01u << SCB_1_INTR_SLAVE_I2C_WRITE_STOP__POS))
#define SCB_1_INTR_SLAVE_I2C_STOP                ((uint32) (0x01u << SCB_1_INTR_SLAVE_I2C_STOP__POS))
#define SCB_1_INTR_SLAVE_I2C_START               ((uint32) (0x01u << SCB_1_INTR_SLAVE_I2C_START__POS))
#define SCB_1_INTR_SLAVE_I2C_ADDR_MATCH          ((uint32) (0x01u << SCB_1_INTR_SLAVE_I2C_ADDR_MATCH__POS))
#define SCB_1_INTR_SLAVE_I2C_GENERAL             ((uint32) (0x01u << SCB_1_INTR_SLAVE_I2C_GENERAL__POS))
#define SCB_1_INTR_SLAVE_I2C_BUS_ERROR           ((uint32) (0x01u << SCB_1_INTR_SLAVE_I2C_BUS_ERROR__POS))
#define SCB_1_INTR_SLAVE_SPI_EZ_WRITE_STOP       ((uint32) (0x01u << \
                                                                SCB_1_INTR_SLAVE_SPI_EZ_WRITE_STOP__POS))
#define SCB_1_INTR_SLAVE_SPI_EZ_STOP             ((uint32) (0x01u << SCB_1_INTR_SLAVE_SPI_EZ_STOP__POS))
#define SCB_1_INTR_SLAVE_SPI_BUS_ERROR           ((uint32) (0x01u << SCB_1_INTR_SLAVE_SPI_BUS_ERROR__POS))


/* SCB_1_INTR_TX, SCB_1_INTR_TX_SET,
   SCB_1_INTR_TX_MASK, SCB_1_INTR_TX_MASKED */
#define SCB_1_INTR_TX_TRIGGER__POS       (0u)  /* [0]  Trigger on TX FIFO entires                       */
#define SCB_1_INTR_TX_NOT_FULL__POS      (1u)  /* [1]  TX FIFO is not full                              */
#define SCB_1_INTR_TX_EMPTY__POS         (4u)  /* [4]  TX FIFO is empty                                 */
#define SCB_1_INTR_TX_OVERFLOW__POS      (5u)  /* [5]  Attempt to write to a full TX FIFO               */
#define SCB_1_INTR_TX_UNDERFLOW__POS     (6u)  /* [6]  Attempt to read from an empty TX FIFO            */
#define SCB_1_INTR_TX_BLOCKED__POS       (7u)  /* [7]  No access to the EZ memory                       */
#define SCB_1_INTR_TX_UART_NACK__POS     (8u)  /* [8]  UART transmitter received a NACK: SmartCard mode */
#define SCB_1_INTR_TX_UART_DONE__POS     (9u)  /* [9]  UART transmitter done even                       */
#define SCB_1_INTR_TX_UART_ARB_LOST__POS (10u) /* [10] UART lost arbitration: LIN or SmartCard          */
#define SCB_1_INTR_TX_TRIGGER            ((uint32) (0x01u << SCB_1_INTR_TX_TRIGGER__POS))
#define SCB_1_INTR_TX_NOT_FULL           ((uint32) (0x01u << SCB_1_INTR_TX_NOT_FULL__POS))
#define SCB_1_INTR_TX_EMPTY              ((uint32) (0x01u << SCB_1_INTR_TX_EMPTY__POS))
#define SCB_1_INTR_TX_OVERFLOW           ((uint32) (0x01u << SCB_1_INTR_TX_OVERFLOW__POS))
#define SCB_1_INTR_TX_UNDERFLOW          ((uint32) (0x01u << SCB_1_INTR_TX_UNDERFLOW__POS))
#define SCB_1_INTR_TX_BLOCKED            ((uint32) (0x01u << SCB_1_INTR_TX_BLOCKED__POS))
#define SCB_1_INTR_TX_UART_NACK          ((uint32) (0x01u << SCB_1_INTR_TX_UART_NACK__POS))
#define SCB_1_INTR_TX_UART_DONE          ((uint32) (0x01u << SCB_1_INTR_TX_UART_DONE__POS))
#define SCB_1_INTR_TX_UART_ARB_LOST      ((uint32) (0x01u << SCB_1_INTR_TX_UART_ARB_LOST__POS))


/* SCB_1_INTR_RX, SCB_1_INTR_RX_SET,
   SCB_1_INTR_RX_MASK, SCB_1_INTR_RX_MASKED */
#define SCB_1_INTR_RX_TRIGGER__POS       (0u)   /* [0]  Trigger on RX FIFO entires            */
#define SCB_1_INTR_RX_NOT_EMPTY__POS     (2u)   /* [2]  RX FIFO is not empty                  */
#define SCB_1_INTR_RX_FULL__POS          (3u)   /* [3]  RX FIFO is full                       */
#define SCB_1_INTR_RX_OVERFLOW__POS      (5u)   /* [5]  Attempt to write to a full RX FIFO    */
#define SCB_1_INTR_RX_UNDERFLOW__POS     (6u)   /* [6]  Attempt to read from an empty RX FIFO */
#define SCB_1_INTR_RX_BLOCKED__POS       (7u)   /* [7]  No access to the EZ memory            */
#define SCB_1_INTR_RX_FRAME_ERROR__POS   (8u)   /* [8]  Frame error in received data frame    */
#define SCB_1_INTR_RX_PARITY_ERROR__POS  (9u)   /* [9]  Parity error in received data frame   */
#define SCB_1_INTR_RX_BAUD_DETECT__POS   (10u)  /* [10] LIN baudrate detection is completed   */
#define SCB_1_INTR_RX_BREAK_DETECT__POS  (11u)  /* [11] Break detection is successful         */
#define SCB_1_INTR_RX_TRIGGER            ((uint32) (0x01u << SCB_1_INTR_RX_TRIGGER__POS))
#define SCB_1_INTR_RX_NOT_EMPTY          ((uint32) (0x01u << SCB_1_INTR_RX_NOT_EMPTY__POS))
#define SCB_1_INTR_RX_FULL               ((uint32) (0x01u << SCB_1_INTR_RX_FULL__POS))
#define SCB_1_INTR_RX_OVERFLOW           ((uint32) (0x01u << SCB_1_INTR_RX_OVERFLOW__POS))
#define SCB_1_INTR_RX_UNDERFLOW          ((uint32) (0x01u << SCB_1_INTR_RX_UNDERFLOW__POS))
#define SCB_1_INTR_RX_BLOCKED            ((uint32) (0x01u << SCB_1_INTR_RX_BLOCKED__POS))
#define SCB_1_INTR_RX_FRAME_ERROR        ((uint32) (0x01u << SCB_1_INTR_RX_FRAME_ERROR__POS))
#define SCB_1_INTR_RX_PARITY_ERROR       ((uint32) (0x01u << SCB_1_INTR_RX_PARITY_ERROR__POS))
#define SCB_1_INTR_RX_BAUD_DETECT        ((uint32) (0x01u << SCB_1_INTR_RX_BAUD_DETECT__POS))
#define SCB_1_INTR_RX_BREAK_DETECT       ((uint32) (0x01u << SCB_1_INTR_RX_BREAK_DETECT__POS))


/* Define all interupt soureces */
#define SCB_1_INTR_I2C_EC_ALL    (SCB_1_INTR_I2C_EC_WAKE_UP | \
                                             SCB_1_INTR_I2C_EC_EZ_STOP | \
                                             SCB_1_INTR_I2C_EC_EZ_WRITE_STOP)

#define SCB_1_INTR_SPI_EC_ALL    (SCB_1_INTR_SPI_EC_WAKE_UP | \
                                             SCB_1_INTR_SPI_EC_EZ_STOP | \
                                             SCB_1_INTR_SPI_EC_EZ_WRITE_STOP)

#define SCB_1_INTR_MASTER_ALL    (SCB_1_INTR_MASTER_I2C_ARB_LOST  | \
                                             SCB_1_INTR_MASTER_I2C_NACK      | \
                                             SCB_1_INTR_MASTER_I2C_ACK       | \
                                             SCB_1_INTR_MASTER_I2C_STOP      | \
                                             SCB_1_INTR_MASTER_I2C_BUS_ERROR | \
                                             SCB_1_INTR_MASTER_SPI_DONE )

#define SCB_1_INTR_SLAVE_ALL     (SCB_1_INTR_SLAVE_I2C_ARB_LOST      | \
                                             SCB_1_INTR_SLAVE_I2C_NACK          | \
                                             SCB_1_INTR_SLAVE_I2C_ACK           | \
                                             SCB_1_INTR_SLAVE_I2C_WRITE_STOP    | \
                                             SCB_1_INTR_SLAVE_I2C_STOP          | \
                                             SCB_1_INTR_SLAVE_I2C_START         | \
                                             SCB_1_INTR_SLAVE_I2C_ADDR_MATCH    | \
                                             SCB_1_INTR_SLAVE_I2C_GENERAL       | \
                                             SCB_1_INTR_SLAVE_I2C_BUS_ERROR     | \
                                             SCB_1_INTR_SLAVE_SPI_EZ_WRITE_STOP | \
                                             SCB_1_INTR_SLAVE_SPI_EZ_STOP       | \
                                             SCB_1_INTR_SLAVE_SPI_BUS_ERROR)

#define SCB_1_INTR_TX_ALL        (SCB_1_INTR_TX_TRIGGER   | \
                                             SCB_1_INTR_TX_NOT_FULL  | \
                                             SCB_1_INTR_TX_EMPTY     | \
                                             SCB_1_INTR_TX_OVERFLOW  | \
                                             SCB_1_INTR_TX_UNDERFLOW | \
                                             SCB_1_INTR_TX_BLOCKED   | \
                                             SCB_1_INTR_TX_UART_NACK | \
                                             SCB_1_INTR_TX_UART_DONE | \
                                             SCB_1_INTR_TX_UART_ARB_LOST)

#define SCB_1_INTR_RX_ALL        (SCB_1_INTR_RX_TRIGGER      | \
                                             SCB_1_INTR_RX_NOT_EMPTY    | \
                                             SCB_1_INTR_RX_FULL         | \
                                             SCB_1_INTR_RX_OVERFLOW     | \
                                             SCB_1_INTR_RX_UNDERFLOW    | \
                                             SCB_1_INTR_RX_BLOCKED      | \
                                             SCB_1_INTR_RX_FRAME_ERROR  | \
                                             SCB_1_INTR_RX_PARITY_ERROR | \
                                             SCB_1_INTR_RX_BAUD_DETECT  | \
                                             SCB_1_INTR_RX_BREAK_DETECT)
                
/* General usege HW definitions */
#define SCB_1_ONE_BYTE_WIDTH (8u)   /* Number of bits in one byte */
#define SCB_1_FIFO_SIZE      (8u)   /* Size of TX or RX FIFO: defined by HW */
#define SCB_1_BUFFER_SIZE    (32u)  /* EZ Buffer size: defined by HW        */

/* I2C and EZI2C slave address defines */
#define SCB_1_I2C_SLAVE_ADDR__POS    (0x01u)    /* 7-bit address shift */
#define SCB_1_I2C_SLAVE_ADDR__MASK   (0xFEu)    /* 8-bit address mask */

/* OVS constants for IrDA Low Power operation */
#define SCB_1_CTRL_OVS_IRDA_LP_OVS16     (0x00u)
#define SCB_1_CTRL_OVS_IRDA_LP_OVS32     (0x01u)
#define SCB_1_CTRL_OVS_IRDA_LP_OVS48     (0x02u)
#define SCB_1_CTRL_OVS_IRDA_LP_OVS96     (0x03u)
#define SCB_1_CTRL_OVS_IRDA_LP_OVS192    (0x04u)
#define SCB_1_CTRL_OVS_IRDA_LP_OVS768    (0x05u)
#define SCB_1_CTRL_OVS_IRDA_LP_OVS1536   (0x06u)

#define SCB_1_UART_IRDA_LP_OVS16     (16u)
#define SCB_1_UART_IRDA_LP_OVS32     (32u)
#define SCB_1_UART_IRDA_LP_OVS48     (48u)
#define SCB_1_UART_IRDA_LP_OVS96     (96u)
#define SCB_1_UART_IRDA_LP_OVS192    (192u)
#define SCB_1_UART_IRDA_LP_OVS768    (768u)
#define SCB_1_UART_IRDA_LP_OVS1536   (1536u)

#define SCB_1_CTRL_OVS_IRDA_OVS      (SCB_1_CTRL_OVS_IRDA_LP_OVS16)


/***************************************
*       Common SCB Macro Definition
***************************************/

/* TX FIFO macro */
#define SCB_1_CLEAR_TX_FIFO  \
                            do{         \
                                SCB_1_TX_FIFO_CTRL_REG |=  SCB_1_TX_FIFO_CTRL_CLEAR; \
                                SCB_1_TX_FIFO_CTRL_REG &= ~SCB_1_TX_FIFO_CTRL_CLEAR; \
                            }while(0)

#define SCB_1_GET_TX_FIFO_ENTRIES    (SCB_1_TX_FIFO_STATUS_REG & \
                                                 SCB_1_TX_FIFO_STATUS_USED__MASK)

#define SCB_1_GET_TX_FIFO_SR_VALID   ((0u != (SCB_1_TX_FIFO_STATUS_REG & \
                                                         SCB_1_TX_FIFO_SR_VALID)) ? (1u) : (0u))

/* RX FIFO macro */
#define SCB_1_CLEAR_RX_FIFO  \
                                do{     \
                                    SCB_1_RX_FIFO_CTRL_REG |=  SCB_1_RX_FIFO_CTRL_CLEAR; \
                                    SCB_1_RX_FIFO_CTRL_REG &= ~SCB_1_RX_FIFO_CTRL_CLEAR; \
                                }while(0)

#define SCB_1_GET_RX_FIFO_ENTRIES    (SCB_1_RX_FIFO_STATUS_REG & \
                                                    SCB_1_RX_FIFO_STATUS_USED__MASK)

#define SCB_1_GET_RX_FIFO_SR_VALID   ((0u != (SCB_1_RX_FIFO_STATUS_REG & \
                                                         SCB_1_RX_FIFO_SR_VALID)) ? (1u) : (0u))

/* Enable interrupt source: set sourceMask bits in SCB_1_INTR_X_MASK_REG */
#define SCB_1_WRITE_INTR_I2C_EC_MASK(sourceMask) \
                                                do{         \
                                                    SCB_1_INTR_I2C_EC_MASK_REG = (sourceMask); \
                                                }while(0)

#define SCB_1_WRITE_INTR_SPI_EC_MASK(sourceMask) \
                                                do{         \
                                                    SCB_1_INTR_SPI_EC_MASK_REG = (sourceMask); \
                                                }while(0)
                                                
#define SCB_1_WRITE_INTR_MASTER_MASK(sourceMask) \
                                                do{         \
                                                    SCB_1_INTR_MASTER_MASK_REG = (sourceMask); \
                                                }while(0)
                                                
#define SCB_1_WRITE_INTR_SLAVE_MASK(sourceMask)  \
                                                do{         \
                                                    SCB_1_INTR_SLAVE_MASK_REG = (sourceMask); \
                                                }while(0)
                                                
#define SCB_1_WRITE_INTR_TX_MASK(sourceMask)     \
                                                do{         \
                                                    SCB_1_INTR_TX_MASK_REG = (sourceMask); \
                                                }while(0)
                                                
#define SCB_1_WRITE_INTR_RX_MASK(sourceMask)     \
                                                do{         \
                                                    SCB_1_INTR_RX_MASK_REG = (sourceMask); \
                                                }while(0)

#define SCB_1_ENABLE_INTR_I2C_EC(sourceMask) \
                                                do{     \
                                                    SCB_1_INTR_I2C_EC_MASK_REG |= (sourceMask); \
                                                }while(0)
                                                
#define SCB_1_ENABLE_INTR_SPI_EC(sourceMask) \
                                                do{     \
                                                    SCB_1_INTR_SPI_EC_MASK_REG |= (sourceMask); \
                                                }while(0)
                                                
#define SCB_1_ENABLE_INTR_MASTER(sourceMask) \
                                                do{     \
                                                    SCB_1_INTR_MASTER_MASK_REG |= (sourceMask); \
                                                }while(0)
                                                
#define SCB_1_ENABLE_INTR_SLAVE(sourceMask)  \
                                                do{     \
                                                    SCB_1_INTR_SLAVE_MASK_REG |= (sourceMask); \
                                                }while(0)
                                                
#define SCB_1_ENABLE_INTR_TX(sourceMask)     \
                                                do{     \
                                                    SCB_1_INTR_TX_MASK_REG |= (sourceMask); \
                                                }while(0)
                                                
#define SCB_1_ENABLE_INTR_RX(sourceMask)     \
                                                do{     \
                                                    SCB_1_INTR_RX_MASK_REG |= (sourceMask); \
                                                }while(0)

/* Disable interrupt source: clear sourceMask bits in SCB_1_INTR_X_MASK_REG */
#define SCB_1_DISABLE_INTR_I2C_EC(sourceMask) \
                                                do{     \
                                                    SCB_1_INTR_I2C_EC_MASK_REG &= ~(sourceMask); \
                                                }while(0)
                                                
#define SCB_1_DISABLE_INTR_SPI_EC(sourceMask) \
                                                do{      \
                                                    SCB_1_INTR_SPI_EC_MASK_REG &= ~(sourceMask); \
                                                 }while(0)
                                                 
#define SCB_1_DISABLE_INTR_MASTER(sourceMask) \
                                                do{      \
                                                SCB_1_INTR_MASTER_MASK_REG &= ~(sourceMask); \
                                                }while(0)
                                                
#define SCB_1_DISABLE_INTR_SLAVE(sourceMask) \
                                                do{     \
                                                    SCB_1_INTR_SLAVE_MASK_REG &= ~(sourceMask); \
                                                }while(0)
                                                
#define SCB_1_DISABLE_INTR_TX(sourceMask)    \
                                                do{     \
                                                    SCB_1_INTR_TX_MASK_REG &= ~(sourceMask); \
                                                 }while(0)
                                                 
#define SCB_1_DISABLE_INTR_RX(sourceMask)    \
                                                do{     \
                                                    SCB_1_INTR_RX_MASK_REG &= ~(sourceMask); \
                                                }while(0)

/* Set interrupt sources: write sourceMask bits in SCB_1_INTR_X_SET_REG */
#define SCB_1_SET_INTR_I2C_EC(sourceMask)    \
                                                do{     \
                                                    SCB_1_INTR_I2C_EC_SET_REG = (sourceMask); \
                                                }while(0)
                                                
#define SCB_1_SET_INTR_SPI_EC(sourceMask)    \
                                                do{     \
                                                    SCB_1_INTR_SPI_EC_SET_REG = (sourceMask); \
                                                }while(0)
                                                
#define SCB_1_SET_INTR_MASTER(sourceMask)    \
                                                do{     \
                                                    SCB_1_INTR_MASTER_SET_REG = (sourceMask); \
                                                }while(0)
                                                
#define SCB_1_SET_INTR_SLAVE(sourceMask) \
                                                do{ \
                                                    $INSTANCE_NAME`_INTR_SLAVE_SET_REG = (sourceMask); \
                                                }while(0)
                                                
#define SCB_1_SET_INTR_TX(sourceMask)    \
                                                do{ \
                                                    SCB_1_INTR_TX_SET_REG = (sourceMask); \
                                                }while(0)
                                                
#define SCB_1_SET_INTR_RX(sourceMask)    \
                                                do{ \
                                                    SCB_1_INTR_RX_SET_REG = (sourceMask); \
                                                }while(0)

/* Clear interrupt sources: write sourceMask bits in SCB_1_INTR_X_REG */
#define SCB_1_CLEAR_INTR_I2C_EC(sourceMask)  \
                                                do{     \
                                                    SCB_1_INTR_I2C_EC_REG = (sourceMask); \
                                                }while(0)
                                                
#define SCB_1_CLEAR_INTR_SPI_EC(sourceMask)  \
                                                do{     \
                                                    SCB_1_INTR_SPI_EC_REG = (sourceMask); \
                                                }while(0)
                                                
#define SCB_1_CLEAR_INTR_MASTER(sourceMask)  \
                                                do{     \
                                                    SCB_1_INTR_MASTER_REG = (sourceMask); \
                                                }while(0)
                                                
#define SCB_1_CLEAR_INTR_SLAVE(sourceMask)   \
                                                do{     \
                                                    SCB_1_INTR_SLAVE_REG  = (sourceMask); \
                                                }while(0)
                                                
#define SCB_1_CLEAR_INTR_TX(sourceMask)      \
                                                do{     \
                                                    SCB_1_INTR_TX_REG     = (sourceMask); \
                                                }while(0)
                                                
#define SCB_1_CLEAR_INTR_RX(sourceMask)      \
                                                do{     \
                                                    SCB_1_INTR_RX_REG     = (sourceMask); \
                                                }while(0)

/* Return TRUE if sourceMask is set in SCB_1_INTR_CAUSE_REG */
#define SCB_1_CHECK_CAUSE_INTR(sourceMask)    (0u != (SCB_1_INTR_CAUSE_REG & (sourceMask))

/* Return TRUE if sourceMask is set in  INTR_X_MASKED_REG */
#define SCB_1_CHECK_INTR_EC_I2C(sourceMask)  (0u != (SCB_1_INTR_I2C_EC_REG & (sourceMask)))
#define SCB_1_CHECK_INTR_EC_SPI(sourceMask)  (0u != (SCB_1_INTR_SPI_EC_REG & (sourceMask)))
#define SCB_1_CHECK_INTR_MASTER(sourceMask)  (0u != (SCB_1_INTR_MASTER_REG & (sourceMask)))
#define SCB_1_CHECK_INTR_SLAVE(sourceMask)   (0u != (SCB_1_INTR_SLAVE_REG  & (sourceMask)))
#define SCB_1_CHECK_INTR_TX(sourceMask)      (0u != (SCB_1_INTR_TX_REG     & (sourceMask)))
#define SCB_1_CHECK_INTR_RX(sourceMask)      (0u != (SCB_1_INTR_RX_REG     & (sourceMask)))

/* Return TRUE if sourceMask is set in SCB_1_INTR_X_MASKED_REG */
#define SCB_1_CHECK_INTR_I2C_EC_MASKED(sourceMask)   (0u != (SCB_1_INTR_I2C_EC_MASKED_REG & \
                                                                       (sourceMask)))
#define SCB_1_CHECK_INTR_SPI_EC_MASKED(sourceMask)   (0u != (SCB_1_INTR_SPI_EC_MASKED_REG & \
                                                                       (sourceMask)))
#define SCB_1_CHECK_INTR_MASTER_MASKED(sourceMask)   (0u != (SCB_1_INTR_MASTER_MASKED_REG & \
                                                                       (sourceMask)))
#define SCB_1_CHECK_INTR_SLAVE_MASKED(sourceMask)    (0u != (SCB_1_INTR_SLAVE_MASKED_REG  & \
                                                                       (sourceMask)))
#define SCB_1_CHECK_INTR_TX_MASKED(sourceMask)       (0u != (SCB_1_INTR_TX_MASKED_REG     & \
                                                                       (sourceMask)))
#define SCB_1_CHECK_INTR_RX_MASKED(sourceMask)       (0u != (SCB_1_INTR_RX_MASKED_REG     & \
                                                                       (sourceMask)))

/* Return TRUE if sourceMask is set in SCB_1_CTRL_REG: generaly is used to check enable bit */
#define SCB_1_GET_CTRL_ENABLED    (0u != (SCB_1_CTRL_REG & SCB_1_CTRL_ENABLED))

#define SCB_1_CHECK_SLAVE_AUTO_ADDR_NACK     (0u != (SCB_1_I2C_CTRL_REG & \
                                                                SCB_1_I2C_CTRL_S_NOT_READY_DATA_NACK))


/***************************************
*      I2C Macro Definition
***************************************/

/* Enable auto ACK/NACK */
#define SCB_1_ENABLE_SLAVE_AUTO_ADDR_NACK    \
                            do{                         \
                                SCB_1_I2C_CTRL_REG |= SCB_1_I2C_CTRL_S_NOT_READY_DATA_NACK; \
                            }while(0)

#define SCB_1_ENABLE_SLAVE_AUTO_DATA_ACK     \
                            do{                         \
                                SCB_1_I2C_CTRL_REG |= SCB_1_I2C_CTRL_S_READY_DATA_ACK; \
                            }while(0)

#define SCB_1_ENABLE_SLAVE_AUTO_DATA_NACK    \
                            do{                         \
                                SCB_1_I2C_CTRL_REG |= SCB_1_I2C_CTRL_S_NOT_READY_DATA_NACK; \
                            }while(0)

#define SCB_1_ENABLE_MASTER_AUTO_DATA_ACK    \
                            do{                         \
                                SCB_1_I2C_CTRL_REG |= SCB_1_I2C_CTRL_M_READY_DATA_ACK; \
                            }while(0)

#define SCB_1_ENABLE_MASTER_AUTO_DATA_NACK   \
                            do{                         \
                                SCB_1_I2C_CTRL_REG |= SCB_1_I2C_CTRL_M_NOT_READY_DATA_NACK; \
                            }while(0)

/* Disable auto ACK/NACK */
#define SCB_1_DISABLE_SLAVE_AUTO_ADDR_NACK   \
                            do{                         \
                                SCB_1_I2C_CTRL_REG &= ~SCB_1_I2C_CTRL_S_NOT_READY_DATA_NACK; \
                            }while(0)

#define SCB_1_DISABLE_SLAVE_AUTO_DATA_ACK    \
                            do{                         \
                                SCB_1_I2C_CTRL_REG &= ~SCB_1_I2C_CTRL_S_READY_DATA_ACK; \
                            }while(0)

#define SCB_1_DISABLE_SLAVE_AUTO_DATA_NACK   \
                            do{                         \
                                SCB_1_I2C_CTRL_REG &= ~SCB_1_I2C_CTRL_S_NOT_READY_DATA_NACK; \
                            }while(0)

#define SCB_1_DISABLE_MASTER_AUTO_DATA_ACK   \
                            do{                         \
                                SCB_1_I2C_CTRL_REG &= ~SCB_1_I2C_CTRL_M_READY_DATA_ACK; \
                            }while(0)

#define SCB_1_DISABLE_MASTER_AUTO_DATA_NACK  \
                            do{                         \
                                SCB_1_I2C_CTRL_REG &= ~SCB_1_I2C_CTRL_M_NOT_READY_DATA_NACK; \
                            }while(0)

/* Enable Slave autoACK/NACK Data */
#define SCB_1_ENABLE_SLAVE_AUTO_DATA     \
                            do{                     \
                                SCB_1_I2C_CTRL_REG |= (SCB_1_I2C_CTRL_S_READY_DATA_ACK |       \
                                                                   SCB_1_I2C_CTRL_S_NOT_READY_DATA_NACK); \
                            }while(0)

/* Disable Slave autoACK/NACK Data */
#define SCB_1_DISABLE_SLAVE_AUTO_DATA    \
                            do{                     \
                                SCB_1_I2C_CTRL_REG &= ~(SCB_1_I2C_CTRL_S_READY_DATA_ACK |      \
                                                                   SCB_1_I2C_CTRL_S_NOT_READY_DATA_NACK); \
                            }while(0)

/* Disable Master autoACK/NACK Data */
#define SCB_1_DISABLE_MASTER_AUTO_DATA   \
                            do{                     \
                                SCB_1_I2C_CTRL_REG &= ~(SCB_1_I2C_CTRL_M_READY_DATA_ACK |      \
                                                                   SCB_1_I2C_CTRL_M_NOT_READY_DATA_NACK); \
                            }while(0)

/* Master commands */
#define SCB_1_I2C_MASTER_GENERATE_START  \
                            do{                     \
                                SCB_1_I2C_MASTER_CMD_REG = SCB_1_I2C_MASTER_CMD_M_START_ON_IDLE; \
                            }while(0)

#define SCB_1_I2C_MASTER_CLEAR_START     \
                            do{                     \
                                SCB_1_I2C_MASTER_CMD_REG =  0u; \
                            }while(0)

#define SCB_1_I2C_MASTER_GENERATE_RESTART    \
                            do{                         \
                                SCB_1_I2C_MASTER_CMD_REG =                                            \
                                    (SCB_1_I2C_MASTER_CMD_M_START |                                   \
                                        (SCB_1_CHECK_I2C_STATUS(SCB_1_I2C_STATUS_M_READ) ? \
                                                    (SCB_1_I2C_MASTER_CMD_M_NACK) : (0u)));       \
                           }while(0)

#define SCB_1_I2C_MASTER_GENERATE_STOP   \
                            do{                     \
                                SCB_1_I2C_MASTER_CMD_REG =                                            \
                                    (SCB_1_I2C_MASTER_CMD_M_STOP |                                    \
                                        (SCB_1_CHECK_I2C_STATUS(SCB_1_I2C_STATUS_M_READ) ? \
                                            (SCB_1_I2C_MASTER_CMD_M_NACK) : (0u)));               \
                            }while(0)

#define SCB_1_I2C_MASTER_GENERATE_ACK    \
                            do{                     \
                                SCB_1_I2C_MASTER_CMD_REG = SCB_1_I2C_MASTER_CMD_M_ACK; \
                            }while(0)

#define SCB_1_I2C_MASTER_GENERATE_NACK   \
                            do{                     \
                                SCB_1_I2C_MASTER_CMD_REG = SCB_1_I2C_MASTER_CMD_M_NACK; \
                            }while(0)

/* Slave comamnds */
#define SCB_1_I2C_SLAVE_GENERATE_ACK     \
                            do{             \
                                SCB_1_I2C_SLAVE_CMD_REG = SCB_1_I2C_SLAVE_CMD_S_ACK; \
                            }while(0)

#define SCB_1_I2C_SLAVE_GENERATE_NACK    \
                            do{             \
                                SCB_1_I2C_SLAVE_CMD_REG = SCB_1_I2C_SLAVE_CMD_S_NACK; \
                            }while(0)

/* Return 8-bit address. The input address should be 7-bits */
#define SCB_1_GET_I2C_8BIT_ADDRESS(addr) (((uint32) (addr) << SCB_1_I2C_SLAVE_ADDR__POS) & \
                                                                         SCB_1_I2C_SLAVE_ADDR__MASK)


/***************************************
*      EzI2C Macro Definition
***************************************/

/* Returns I2C EzAddress */
#define SCB_1_GET_I2C_STATUS_EZ_ADDRESS      (SCB_1_I2C_STATUS_REG >> \
                                                            SCB_1_I2C_STATUS_EZ_ADDR__POS)

/* Returns true if bit is set in SCB_1_I2C_STATUS_REG */
#define SCB_1_CHECK_I2C_STATUS(sourceMask)   (0u != (SCB_1_I2C_STATUS_REG & (sourceMask)))


/***************************************
*      EzSpi Macro Definition
***************************************/

/* Returns SPI EzAddress */
#define SCB_1_GET_SPI_STATUS_EZ_ADDRESS      (SCB_1_SPI_STATUS_REG >> \
                                                            SCB_1_SPI_STATUS_EZ_ADDR__POS)

/* Returns true if bit is set in SCB_1_SPI_STATUS_REG */
#define SCB_1_CHECK_SPI_STATUS(sourceMask)   (0u != (SCB_1_SPI_STATUS_REG & (sourceMask)))


/***************************************
*   Gets defualt config bits
***************************************/

/* SCB_1_CTRL */
#define SCB_1_GET_CTRL_OVS(oversample)   ((uint32) ((oversample) - 1u))

#define SCB_1_GET_CTRL_OVS_IRDA_LP(oversample)   \
            ((SCB_1_UART_IRDA_LP_OVS16   == (oversample)) ? SCB_1_CTRL_OVS_IRDA_LP_OVS16 : \
             ((SCB_1_UART_IRDA_LP_OVS32   == (oversample)) ? SCB_1_CTRL_OVS_IRDA_LP_OVS32 : \
              ((SCB_1_UART_IRDA_LP_OVS48   == (oversample)) ? SCB_1_CTRL_OVS_IRDA_LP_OVS48 : \
               ((SCB_1_UART_IRDA_LP_OVS96   == (oversample)) ? SCB_1_CTRL_OVS_IRDA_LP_OVS96 : \
                ((SCB_1_UART_IRDA_LP_OVS192  == (oversample)) ? SCB_1_CTRL_OVS_IRDA_LP_OVS192 : \
                 ((SCB_1_UART_IRDA_LP_OVS768  == (oversample)) ? SCB_1_CTRL_OVS_IRDA_LP_OVS768 : \
                  ((SCB_1_UART_IRDA_LP_OVS1536 == (oversample)) ? SCB_1_CTRL_OVS_IRDA_LP_OVS1536 : \
                                                                              SCB_1_CTRL_OVS_IRDA_LP_OVS16)))))))

#define SCB_1_GET_CTRL_EC_OP_MODE(opMode)        ((0u != (opMode)) ? \
                                                                (SCB_1_CTRL_EC_OP_MODE)  : (0u))

#define SCB_1_GET_CTRL_EC_AM_MODE(amMode)        ((0u != (amMode)) ? \
                                                                (SCB_1_CTRL_EC_AM_MODE)  : (0u))

#define SCB_1_GET_CTRL_BLOCK(block)              ((0u != (block))  ? \
                                                                (SCB_1_CTRL_BLOCK)       : (0u))

#define SCB_1_GET_CTRL_ADDR_ACCEPT(acceptAddr)   ((0u != (acceptAddr)) ? \
                                                                (SCB_1_CTRL_ADDR_ACCEPT) : (0u))

/* SCB_1_I2C_CTRL */
#define SCB_1_GET_I2C_CTRL_HIGH_PHASE_OVS(oversampleHigh) ((uint32) ((oversampleHigh) - 1u))

#define SCB_1_GET_I2C_CTRL_LOW_PHASE_OVS(oversampleLow)   ((uint32) (((oversampleLow)  - 1u) << \
                                                                        SCB_1_I2C_CTRL_LOW_PHASE_OVS__POS))

#define SCB_1_GET_I2C_CTRL_SLAVE_MODE(mode)  ((0u != ((mode) & SCB_1_I2C_MODE_SLAVE))  ? \
                                                            (SCB_1_I2C_CTRL_SLAVE_MODE)  : (0u))

#define SCB_1_GET_I2C_CTRL_MASTER_MODE(mode) ((0u != ((mode) & SCB_1_I2C_MODE_MASTER)) ? \
                                                            (SCB_1_I2C_CTRL_MASTER_MODE) : (0u))

/* SCB_1_SPI_CTRL */
#define SCB_1_GET_SPI_CTRL_CONTINUOUS(separate)  ((0u != (separate)) ? \
                                                                (SCB_1_SPI_CTRL_CONTINUOUS) : (0u))
#define SCB_1_GET_SPI_CTRL_SELECT_PRECEDE(mode)  \
                                                   ((0u != ((mode) & SCB_1_SPI_MODE_TI_PRECEDES_MASK)) ? \
                                                                (SCB_1_SPI_CTRL_SELECT_PRECEDE) : (0u))

#define SCB_1_GET_SPI_CTRL_SCLK_MODE(mode)       ((uint32) ((mode) << SCB_1_SPI_CTRL_CPHA__POS))

#define SCB_1_GET_SPI_CTRL_LATE_MISO_SAMPLE(lateMiso) ((0u != (lateMiso)) ? \
                                                                (SCB_1_SPI_CTRL_LATE_MISO_SAMPLE) : (0u))

#define SCB_1_GET_SPI_CTRL_SUB_MODE(mode)        ((uint32) ((mode) & SCB_1_SPI_MODE_MASK) << \
                                                                SCB_1_SPI_CTRL_MODE__POS)

#define SCB_1_GET_SPI_CTRL_SLAVE_SELECT(select)  ((uint32) ((select) & \
                                                                SCB_1_SPI_CTRL_SLAVE_SELECT__MASK)<< \
                                                                SCB_1_SPI_CTRL_SLAVE_SELECT__POS)

#define SCB_1_GET_SPI_CTRL_MASTER_MODE(mode)     ((0u != (mode)) ? \
                                                                (SCB_1_SPI_CTRL_MASTER) : (0u))

/* SCB_1_UART_CTRL */
#define SCB_1_GET_UART_CTRL_MODE(mode)           ((uint32) ((mode) << SCB_1_UART_CTRL_MODE__POS))

/* SCB_1_UART_RX_CTRL */
#define SCB_1_GET_UART_RX_CTRL_MODE(stopBits)    ((uint32) ((stopBits) - 1u))

#define SCB_1_GET_UART_RX_CTRL_PARITY(parity)    ((0u != (parity))   ? \
                                                                    (SCB_1_UART_RX_CTRL_PARITY) : (0u))

#define SCB_1_GET_UART_RX_CTRL_POLARITY(parity)  ((0u != (polarity)) ? \
                                                                    (SCB_1_UART_RX_CTRL_POLARITY) : (0u))

#define SCB_1_GET_UART_RX_CTRL_DROP_ON_PARITY_ERR(dropErr) ((0u != (dropErr)) ? \
                                                        (SCB_1_UART_RX_CTRL_DROP_ON_PARITY_ERR) : (0u))

#define SCB_1_GET_UART_RX_CTRL_DROP_ON_FRAME_ERR(dropErr) ((0u != (dropErr)) ? \
                                                        (SCB_1_UART_RX_CTRL_DROP_ON_FRAME_ERR) : (0u))

#define SCB_1_GET_UART_RX_CTRL_MP_MODE(mpMode)   ((0u != (mpMode)) ? \
                                                        (SCB_1_UART_RX_CTRL_MP_MODE)  : (0u))

/* SCB_1_UART_TX_CTRL */
#define SCB_1_GET_UART_TX_CTRL_MODE(stopBits)    ((uint32) ((stopBits) - 1u))

#define SCB_1_GET_UART_TX_CTRL_PARITY(parity)    ((0u != (parity)) ? \
                                                               (SCB_1_UART_TX_CTRL_PARITY) : (0u))

#define SCB_1_GET_UART_TX_CTRL_RETRY_NACK(nack)  ((0u != (nack)) ? \
                                                               (SCB_1_UART_TX_CTRL_RETRY_ON_NACK) : (0u))

/* SCB_1_RX_CTRL */
#define SCB_1_GET_RX_CTRL_DATA_WIDTH(dataWidth)  ((uint32) ((dataWidth) - 1u))

#define SCB_1_GET_RX_CTRL_BIT_ORDER(bitOrder)    ((0u != (bitOrder)) ? \
                                                                (SCB_1_RX_CTRL_MSB_FIRST) : (0u))

#define SCB_1_GET_RX_CTRL_MEDIAN(filterEn)       ((0u != (filterEn)) ? \
                                                                (SCB_1_RX_CTRL_MEDIAN) : (0u))

/* SCB_1_RX_MATCH */
#define SCB_1_GET_RX_MATCH_ADDR(addr)    ((uint32) (addr))
#define SCB_1_GET_RX_MATCH_MASK(mask)    ((uint32) ((mask) << SCB_1_RX_MATCH_MASK__POS))

/* SCB_1_RX_FIFO_CTRL */
#define SCB_1_GET_RX_FIFO_CTRL_TRIGGER_LEVEL(level)  ((uint32) (level))

/* SCB_1_TX_CTRL */
#define SCB_1_GET_TX_CTRL_DATA_WIDTH(dataWidth)  ((uint32) ((dataWidth) - 1u))

#define SCB_1_GET_TX_CTRL_BIT_ORDER(bitOrder)    ((0u != (bitOrder)) ? \
                                                                (SCB_1_TX_CTRL_MSB_FIRST) : (0u))

/* SCB_1_TX_FIFO_CTRL */
#define SCB_1_GET_TX_FIFO_CTRL_TRIGGER_LEVEL(level)  ((uint32) (level))

#define SCB_1_NO_INTR_SOURCES    (0u)

#endif /* (CY_SCB_SCB_1_H) */


/* [] END OF FILE */
