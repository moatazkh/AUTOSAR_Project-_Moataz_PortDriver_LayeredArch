/******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port_Cfg.h
 *
 * Description: Source file for TM4C123GH6PM Microcontroller - Port Driver.
 *
 * Author: Moataz Khaled
 ******************************************************************************/

#ifndef PORT_CFG_H
#define PORT_CFG_H

/*
 * Module Version 1.0.0
 */
#define PORT_CFG_SW_MAJOR_VERSION (1U)
#define PORT_CFG_SW_MINOR_VERSION (0U)
#define PORT_CFG_SW_PATCH_VERSION (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_CFG_AR_RELEASE_MAJOR_VERSION (4U)
#define PORT_CFG_AR_RELEASE_MINOR_VERSION (0U)
#define PORT_CFG_AR_RELEASE_PATCH_VERSION (3U)

/* Port Pin IDs */
#define PortA_Pin0_ID (uint8)0
#define PortA_Pin1_ID (uint8)1
#define PortA_Pin2_ID (uint8)2
#define PortA_Pin3_ID (uint8)3
#define PortA_Pin4_ID (uint8)4
#define PortA_Pin5_ID (uint8)5
#define PortA_Pin6_ID (uint8)6
#define PortA_Pin7_ID (uint8)7
#define PortB_Pin0_ID (uint8)8
#define PortB_Pin1_ID (uint8)9
#define PortB_Pin2_ID (uint8)10
#define PortB_Pin3_ID (uint8)11
#define PortB_Pin4_ID (uint8)12
#define PortB_Pin5_ID (uint8)13
#define PortB_Pin6_ID (uint8)14
#define PortB_Pin7_ID (uint8)15
#define PortC_Pin0_ID (uint8)16
#define PortC_Pin1_ID (uint8)17
#define PortC_Pin2_ID (uint8)18
#define PortC_Pin3_ID (uint8)19
#define PortC_Pin4_ID (uint8)20
#define PortC_Pin5_ID (uint8)21
#define PortC_Pin6_ID (uint8)22
#define PortC_Pin7_ID (uint8)23
#define PortD_Pin0_ID (uint8)24
#define PortD_Pin1_ID (uint8)25
#define PortD_Pin2_ID (uint8)26
#define PortD_Pin3_ID (uint8)27
#define PortD_Pin4_ID (uint8)28
#define PortD_Pin5_ID (uint8)29
#define PortD_Pin6_ID (uint8)30
#define PortD_Pin7_ID (uint8)31
#define PortE_Pin0_ID (uint8)32
#define PortE_Pin1_ID (uint8)33
#define PortE_Pin2_ID (uint8)34
#define PortE_Pin3_ID (uint8)35
#define PortE_Pin4_ID (uint8)36
#define PortE_Pin5_ID (uint8)37
#define PortF_Pin0_ID (uint8)38
#define PortF_Pin1_ID (uint8)39
#define PortF_Pin2_ID (uint8)40
#define PortF_Pin3_ID (uint8)41
#define PortF_Pin4_ID (uint8)42

/* Number of the configured pins  */
#define PORT_CONFIGURED_PORTPINS (2U)

/* Channel Index in the array of structures in Dio_PBcfg.c */
#define PORT_PIN_LED1_INDEX (uint8)0x00
#define PORT_PIN_SW1_INDEX (uint8)0x01

/* Switches the Development Error Detection and Notification on or off.
true: Enabled. false: Disabled. */
#define PORT_DEV_ERROR_DETECT (STD_ON)

/*Pre-processor switch to enable / disable the use of the function Port_SetPinDirection()*/
#define PORT_SET_PIN_DIRECTION_API (STD_ON)

/* Pre-processor switch to enable / disable the use of the function Port_SetPinMode()*/
#define PORT_SET_PIN_MODE_API (STD_ON)

/* Pre-processor switch to enable / disable the API to read out the modules version information */
#define PORT_VERSION_INFO_API (STD_ON)

/* PORT configured direction */
#define PORT_PIN_LED1_DIRECTION (Port_PinDirectionType) PORT_PIN_OUT
#define PORT_PIN_SW1_DIRECTION (Port_PinDirectionType) PORT_PIN_IN

/* Parameter to indicate if the direction is changeable on a port pin during runtime */
#define PORT_PIN_LED1_DIRECTION_CHANGEABLE (STD_OFF)
#define PORT_PIN_SW1_DIRECTION_CHANGEABLE (STD_OFF)

/* configuring port pins ID */
#define PORT_PIN_LED1_ID (PortF_Pin1_ID)
#define PORT_PIN_SW1_ID (PortF_Pin4_ID)

/* configuring initial mode for port pins */
#define PORT_PIN_LED1_INITIAL_MODE (PORT_PIN_MODE_DIO)
#define PORT_PIN_SW1_INITIAL_MODE (PORT_PIN_MODE_DIO)

/* confiruring initial value for LED1 */
#define PORT_PIN_LED1_LEVEL_VALUE (STD_HIGH)
#define PORT_PIN_SW1_LEVEL_VALUE (STD_LOW)

/* configuring initial mode for port pins */
#define PORT_PIN_LED1_MODE (PORT_PIN_MODE_DIO)
#define PORT_PIN_SW1_MODE (PORT_PIN_MODE_DIO)

/* configuring if mode is changable for port pins */
#define PORT_PIN_LED1_MODE_CHANGEABLE (STD_ON)
#define PORT_PIN_SW1_MODE_CHANGEABLE (STD_ON)

/* configuring internal resistor mode for port pins */
#define PORT_PIN_LED1_INTERNAL_RESISTOR (Port_InternalResistor)(OFF)
#define PORT_PIN_SW1_INTERNAL_RESISTOR (Port_InternalResistor) PULL_UP

#endif /* PORT_CFG_H */