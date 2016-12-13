/*******************************************************************************
* File Name: Comm_uart_rx_i2c_scl_spi_mosi.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Comm_uart_rx_i2c_scl_spi_mosi_H) /* Pins Comm_uart_rx_i2c_scl_spi_mosi_H */
#define CY_PINS_Comm_uart_rx_i2c_scl_spi_mosi_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Comm_uart_rx_i2c_scl_spi_mosi_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} Comm_uart_rx_i2c_scl_spi_mosi_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   Comm_uart_rx_i2c_scl_spi_mosi_Read(void);
void    Comm_uart_rx_i2c_scl_spi_mosi_Write(uint8 value);
uint8   Comm_uart_rx_i2c_scl_spi_mosi_ReadDataReg(void);
#if defined(Comm_uart_rx_i2c_scl_spi_mosi__PC) || (CY_PSOC4_4200L) 
    void    Comm_uart_rx_i2c_scl_spi_mosi_SetDriveMode(uint8 mode);
#endif
void    Comm_uart_rx_i2c_scl_spi_mosi_SetInterruptMode(uint16 position, uint16 mode);
uint8   Comm_uart_rx_i2c_scl_spi_mosi_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void Comm_uart_rx_i2c_scl_spi_mosi_Sleep(void); 
void Comm_uart_rx_i2c_scl_spi_mosi_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(Comm_uart_rx_i2c_scl_spi_mosi__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define Comm_uart_rx_i2c_scl_spi_mosi_DRIVE_MODE_BITS        (3)
    #define Comm_uart_rx_i2c_scl_spi_mosi_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Comm_uart_rx_i2c_scl_spi_mosi_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the Comm_uart_rx_i2c_scl_spi_mosi_SetDriveMode() function.
         *  @{
         */
        #define Comm_uart_rx_i2c_scl_spi_mosi_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define Comm_uart_rx_i2c_scl_spi_mosi_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define Comm_uart_rx_i2c_scl_spi_mosi_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define Comm_uart_rx_i2c_scl_spi_mosi_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define Comm_uart_rx_i2c_scl_spi_mosi_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define Comm_uart_rx_i2c_scl_spi_mosi_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define Comm_uart_rx_i2c_scl_spi_mosi_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define Comm_uart_rx_i2c_scl_spi_mosi_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define Comm_uart_rx_i2c_scl_spi_mosi_MASK               Comm_uart_rx_i2c_scl_spi_mosi__MASK
#define Comm_uart_rx_i2c_scl_spi_mosi_SHIFT              Comm_uart_rx_i2c_scl_spi_mosi__SHIFT
#define Comm_uart_rx_i2c_scl_spi_mosi_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Comm_uart_rx_i2c_scl_spi_mosi_SetInterruptMode() function.
     *  @{
     */
        #define Comm_uart_rx_i2c_scl_spi_mosi_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define Comm_uart_rx_i2c_scl_spi_mosi_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define Comm_uart_rx_i2c_scl_spi_mosi_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define Comm_uart_rx_i2c_scl_spi_mosi_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(Comm_uart_rx_i2c_scl_spi_mosi__SIO)
    #define Comm_uart_rx_i2c_scl_spi_mosi_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(Comm_uart_rx_i2c_scl_spi_mosi__PC) && (CY_PSOC4_4200L)
    #define Comm_uart_rx_i2c_scl_spi_mosi_USBIO_ENABLE               ((uint32)0x80000000u)
    #define Comm_uart_rx_i2c_scl_spi_mosi_USBIO_DISABLE              ((uint32)(~Comm_uart_rx_i2c_scl_spi_mosi_USBIO_ENABLE))
    #define Comm_uart_rx_i2c_scl_spi_mosi_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define Comm_uart_rx_i2c_scl_spi_mosi_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define Comm_uart_rx_i2c_scl_spi_mosi_USBIO_ENTER_SLEEP          ((uint32)((1u << Comm_uart_rx_i2c_scl_spi_mosi_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << Comm_uart_rx_i2c_scl_spi_mosi_USBIO_SUSPEND_DEL_SHIFT)))
    #define Comm_uart_rx_i2c_scl_spi_mosi_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << Comm_uart_rx_i2c_scl_spi_mosi_USBIO_SUSPEND_SHIFT)))
    #define Comm_uart_rx_i2c_scl_spi_mosi_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << Comm_uart_rx_i2c_scl_spi_mosi_USBIO_SUSPEND_DEL_SHIFT)))
    #define Comm_uart_rx_i2c_scl_spi_mosi_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(Comm_uart_rx_i2c_scl_spi_mosi__PC)
    /* Port Configuration */
    #define Comm_uart_rx_i2c_scl_spi_mosi_PC                 (* (reg32 *) Comm_uart_rx_i2c_scl_spi_mosi__PC)
#endif
/* Pin State */
#define Comm_uart_rx_i2c_scl_spi_mosi_PS                     (* (reg32 *) Comm_uart_rx_i2c_scl_spi_mosi__PS)
/* Data Register */
#define Comm_uart_rx_i2c_scl_spi_mosi_DR                     (* (reg32 *) Comm_uart_rx_i2c_scl_spi_mosi__DR)
/* Input Buffer Disable Override */
#define Comm_uart_rx_i2c_scl_spi_mosi_INP_DIS                (* (reg32 *) Comm_uart_rx_i2c_scl_spi_mosi__PC2)

/* Interrupt configuration Registers */
#define Comm_uart_rx_i2c_scl_spi_mosi_INTCFG                 (* (reg32 *) Comm_uart_rx_i2c_scl_spi_mosi__INTCFG)
#define Comm_uart_rx_i2c_scl_spi_mosi_INTSTAT                (* (reg32 *) Comm_uart_rx_i2c_scl_spi_mosi__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define Comm_uart_rx_i2c_scl_spi_mosi_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(Comm_uart_rx_i2c_scl_spi_mosi__SIO)
    #define Comm_uart_rx_i2c_scl_spi_mosi_SIO_REG            (* (reg32 *) Comm_uart_rx_i2c_scl_spi_mosi__SIO)
#endif /* (Comm_uart_rx_i2c_scl_spi_mosi__SIO_CFG) */

/* USBIO registers */
#if !defined(Comm_uart_rx_i2c_scl_spi_mosi__PC) && (CY_PSOC4_4200L)
    #define Comm_uart_rx_i2c_scl_spi_mosi_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define Comm_uart_rx_i2c_scl_spi_mosi_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define Comm_uart_rx_i2c_scl_spi_mosi_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define Comm_uart_rx_i2c_scl_spi_mosi_DRIVE_MODE_SHIFT       (0x00u)
#define Comm_uart_rx_i2c_scl_spi_mosi_DRIVE_MODE_MASK        (0x07u << Comm_uart_rx_i2c_scl_spi_mosi_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins Comm_uart_rx_i2c_scl_spi_mosi_H */


/* [] END OF FILE */
