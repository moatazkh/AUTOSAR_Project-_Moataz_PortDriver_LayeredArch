/******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - Port Driver.
 *
 * Author: Mohamed Tarek
 ******************************************************************************/
#ifndef PORT_H // my version 0f port.h
#define PORT_H

#include "Common_Macros.h"
// #include "Std_Types.h"
// #include "Port_Cfg.h"

/*******************************************************************************
 *                              Module Definitions                             *
 *******************************************************************************/

/* GPIO Registers base addresses */
#define GPIO_PORTA_BASE_ADDRESS 0x40004000
#define GPIO_PORTB_BASE_ADDRESS 0x40005000
#define GPIO_PORTC_BASE_ADDRESS 0x40006000
#define GPIO_PORTD_BASE_ADDRESS 0x40007000
#define GPIO_PORTE_BASE_ADDRESS 0x40024000
#define GPIO_PORTF_BASE_ADDRESS 0x40025000

/* GPIO Registers offset addresses */
#define PORT_DATA_REG_OFFSET 0x3FC
#define PORT_DIR_REG_OFFSET 0x400
#define PORT_ALT_FUNC_REG_OFFSET 0x420
#define PORT_PULL_UP_REG_OFFSET 0x510
#define PORT_PULL_DOWN_REG_OFFSET 0x514
#define PORT_DIGITAL_ENABLE_REG_OFFSET 0x51C
#define PORT_LOCK_REG_OFFSET 0x520
#define PORT_COMMIT_REG_OFFSET 0x524
#define PORT_ANALOG_MODE_SEL_REG_OFFSET 0x528
#define PORT_CTL_REG_OFFSET 0x52C

/*             version       */

/* Id for the company in the AUTOSAR
 * for example Mohamed Tarek's ID = 1000 :) */
#define PORT_VENDOR_ID (1000U)

/* PORT Module Id */
#define PORT_MODULE_ID (124U)

/* PORT Instance Id */
#define PORT_INSTANCE_ID (0U)

/*
 * Module Version 1.0.0
 */
#define PORT_SW_MAJOR_VERSION (1U)
#define PORT_SW_MINOR_VERSION (0U)
#define PORT_SW_PATCH_VERSION (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_AR_RELEASE_MAJOR_VERSION (4U)
#define PORT_AR_RELEASE_MINOR_VERSION (0U)
#define PORT_AR_RELEASE_PATCH_VERSION (3U)

/*
 * Macros for PORT Status
 */
#define PORT_INITIALIZED (1U)
#define PORT_NOT_INITIALIZED (0U)

/* Standard AUTOSAR types */
#include "Std_Types.h"

/* AUTOSAR checking between Std Types and PORT Modules */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION) || (STD_TYPES_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION) || (STD_TYPES_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
#error "The AR version of Std_Types.h does not match the expected version"
#endif

/* PORT Pre-Compile Configuration Header file */
#include "PORT_Cfg.h"

/* AUTOSAR Version checking between PORT_Cfg.h and PORT.h files */
#if ((PORT_CFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION) || (PORT_CFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION) || (PORT_CFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
#error "The AR version of PORT_Cfg.h does not match the expected version"
#endif

/* Software Version checking between PORT_Cfg.h and PORT.h files */
#if ((PORT_CFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION) || (PORT_CFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION) || (PORT_CFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
#error "The SW version of PORT_Cfg.h does not match the expected version"
#endif

/*******************************************************************************
 *                      API Service Id Macros                                 *
 *******************************************************************************/
#define Port_Init_SID (uint8)0x00
#define Port_SetPinDirection_SID (uint8)0x01
#define Port_RefreshPortDirection_SID (uint8)0x02
#define Port_GetVersionInfo_SID (uint8)0x03
#define Port_SetPinMode_SID (uint8)0x04

/* Port Pin MODE value  */
#define PORT_PIN_MODE_ADC (0U)
#define PORT_PIN_MODE_DIO (10U)
#define PORT_PIN_NOT_ACTIVE (9U)

#define PORT_PIN_MODE_UART (1U)

#define PORT_PIN_MODE_SSI (2U)
#define PORT_PIN_MODE_UART1 (2U)

#define PORT_PIN_MODE_I2C (3U)
#define PORT_PIN_MODE_CAN0 (3U)

#define PORT_PIN_MODE_PWM0 (4U)

#define PORT_PIN_MODE_PWM1 (5U)

#define PORT_PIN_MODE_QEI (6U)

#define PORT_PIN_MODE_GPT (7U)

#define PORT_PIN_MODE_CAN (8U)
#define PORT_PIN_MODE_USB (8U)

#define MAX_MODE_NUMBER (15U)

/* Port Pin LEVEL value  */
#define PORT_PIN_LEVEL_HIGH (STD_HIGH)
#define PORT_PIN_LEVEL_LOW (STD_LOW)

/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/

/* Description: uint to hold PIN type */
typedef uint8 Port_PinType;

/* Description: uint to hold PIN mode type (ADC, SPI, DIO) */
typedef uint8 Port_PinModeType;

/* Description: uint to hold initial value in case of dio output */
typedef uint8 Port_PinLevelInit;

/* Description: Enum to hold PIN direction */
typedef enum
{
    PORT_PIN_IN,
    PORT_PIN_OUT
} Port_PinDirectionType;

/* Description: Enum to hold internal resistor type for PIN */
typedef enum
{
    OFF,
    PULL_UP,
    PULL_DOWN
} Port_InternalResistor;

/* Description: Structure to configure each individual PIN:
 *	1. the PORT mode (ADC, SPI, UART, etc..)
 *  2. the direction of pin --> INPUT or OUTPUT
 *	3. the number of the pin in the microcontroller.
 *  4. the internal resistor --> Disable, Pull up or Pull down
 *  5. initial value if pin is dio output
 */

typedef struct
{
    Port_PinDirectionType direction;
    uint8 isDirectionChangable;
    Port_PinType portPinType;
    Port_PinModeType mode;
    Port_PinLevelInit initialValue;
    Port_PinModeType pinMode;
    uint8 isPinModeChangable;
    Port_InternalResistor resistorType;
} Port_ConfigType;

/***************     Det error code    *************/

#define PORT_E_PARAM_PIN (uint8)0x0A
#define PORT_E_DIRECTION_UNCHANGEABLE (uint8)0x0B
#define PORT_E_PARAM_CONFIG (uint8)0x0C
#define PORT_E_PARAM_INVALID_MODE (uint8)0x0D
#define PORT_E_MODE_UNCHANGEABLE (uint8)0x0E
#define PORT_E_UNINIT (uint8)0x0F
#define PORT_E_PARAM_POINTER (uint8)0x10

/****************************************************/

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/************************************************************************************
* Service Name: Port_SetupGpioPin
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Parameters (in): ConfigPtr - Pointer to post-build configuration data
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Setup the pin configuration:
*              - Setup the pin as Digital GPIO pin
*              - Setup the direction of the GPIO pin
*              - Setup the internal resistor for i/p pin
************************************************************************************/

void Port_Init(const Port_ConfigType *ConfigPtr);

void Port_RefreshPortDirection(void);

#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction);
#endif

void Port_RefreshPortDirection(void);

#if (PORT_VERSION_INFO_API == STD_ON)
void Port_GetVersionInfo(Std_VersionInfoType *versioninfo);
#endif

#if (PORT_SET_PIN_MODE_API == STD_ON)
void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode);
#endif

/* Extern PB structures to be used by Dio and other modules */
extern const Port_ConfigType Port_Configuration[PORT_CONFIGURED_PORTPINS];

#endif /* PORT_H */ //end my version of port.h

//////////////////////////  Tarek version  ///////////////////////////////////////////////////

// #ifndef PORT_H
// #define PORT_H

// #include "Common_Macros.h"
// #include "Std_Types.h"

// /*******************************************************************************
//  *                              Module Definitions                             *
//  *******************************************************************************/

// /* GPIO Registers base addresses */
// #define GPIO_PORTA_BASE_ADDRESS 0x40004000
// #define GPIO_PORTB_BASE_ADDRESS 0x40005000
// #define GPIO_PORTC_BASE_ADDRESS 0x40006000
// #define GPIO_PORTD_BASE_ADDRESS 0x40007000
// #define GPIO_PORTE_BASE_ADDRESS 0x40024000
// #define GPIO_PORTF_BASE_ADDRESS 0x40025000

// /* GPIO Registers offset addresses */
// #define PORT_DATA_REG_OFFSET 0x3FC
// #define PORT_DIR_REG_OFFSET 0x400
// #define PORT_ALT_FUNC_REG_OFFSET 0x420
// #define PORT_PULL_UP_REG_OFFSET 0x510
// #define PORT_PULL_DOWN_REG_OFFSET 0x514
// #define PORT_DIGITAL_ENABLE_REG_OFFSET 0x51C
// #define PORT_LOCK_REG_OFFSET 0x520
// #define PORT_COMMIT_REG_OFFSET 0x524
// #define PORT_ANALOG_MODE_SEL_REG_OFFSET 0x528
// #define PORT_CTL_REG_OFFSET 0x52C

// /*******************************************************************************
//  *                              Module Data Types                              *
//  *******************************************************************************/

// /* Description: Enum to hold PIN direction */
// typedef enum
// {
//     INPUT,
//     OUTPUT
// } Port_PinDirection;

// /* Description: Enum to hold internal resistor type for PIN */
// typedef enum
// {
//     OFF,
//     PULL_UP,
//     PULL_DOWN
// } Port_InternalResistor;

// /* Description: Structure to configure each individual PIN:
//  *	1. the PORT Which the pin belongs to. 0, 1, 2, 3, 4 or 5
//  *	2. the number of the pin in the PORT.
//  *      3. the direction of pin --> INPUT or OUTPUT
//  *      4. the internal resistor --> Disable, Pull up or Pull down
//  */
// typedef struct
// {
//     uint8 port_num;
//     uint8 pin_num;
//     Port_PinDirection direction;
//     Port_InternalResistor resistor;
//     uint8 initial_value;
// } Port_ConfigType;

// /*******************************************************************************
//  *                      Function Prototypes                                    *
//  *******************************************************************************/

// /************************************************************************************
// * Service Name: Port_SetupGpioPin
// * Sync/Async: Synchronous
// * Reentrancy: reentrant
// * Parameters (in): ConfigPtr - Pointer to post-build configuration data
// * Parameters (inout): None
// * Parameters (out): None
// * Return value: None
// * Description: Function to Setup the pin configuration:
// *              - Setup the pin as Digital GPIO pin
// *              - Setup the direction of the GPIO pin
// *              - Setup the internal resistor for i/p pin
// ************************************************************************************/
// void Port_SetupGpioPin(const Port_ConfigType *ConfigPtr);

// #endif /* PORT_H */
