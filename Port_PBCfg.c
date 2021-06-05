/******************************************************************************
 *
 * Module: PORT
 *
 * File Name: PORT_PBcfg.c
 *
 * Description: Post Build Configuration Source file for TM4C123GH6PM Microcontroller - PORT Driver
 *
 * Author: Moataz Khaled
 ******************************************************************************/

#include "Port.h"

/*
 * Module Version 1.0.0
 */
#define PORT_PBCFG_SW_MAJOR_VERSION (1U)
#define PORT_PBCFG_SW_MINOR_VERSION (0U)
#define PORT_PBCFG_SW_PATCH_VERSION (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_PBCFG_AR_RELEASE_MAJOR_VERSION (4U)
#define PORT_PBCFG_AR_RELEASE_MINOR_VERSION (0U)
#define PORT_PBCFG_AR_RELEASE_PATCH_VERSION (3U)

/* AUTOSAR Version checking between PORT_PBcfg.c and PORT.h files */
#if ((PORT_PBCFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION) || (PORT_PBCFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION) || (PORT_PBCFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
#error "The AR version of PBcfg.c does not match the expected version"
#endif

/* Software Version checking between PORT_PBcfg.c and PORT.h files */
#if ((PORT_PBCFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION) || (PORT_PBCFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION) || (PORT_PBCFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
#error "The SW version of PBcfg.c does not match the expected version"
#endif

/* PB structure used with PORT_Init API */
const Port_ConfigType Port_Configuration[] = {

    /*******************************************************************************
    *                              PORT A initialaztion                           *
    *******************************************************************************/

    {/* Pin direction */
     PORT_PIN_OUT,

     /* Pin direction changeable or .not */
     STD_OFF,

     /* Pin id. */
     PortA_Pin0_ID,

     /* Pin Initial mode. */

     PORT_PIN_MODE_DIO,

     /* Pin initial value .*/
     STD_HIGH,

     /* Pin Mode.  */
     PORT_PIN_MODE_DIO,

     /* Pin Mode changable. */
     STD_ON,

     /* Pin internal resisstor. */
     (Port_InternalResistor)PULL_UP

    },
    {PORT_PIN_OUT,
     STD_OFF,
     PortA_Pin1_ID,
     PORT_PIN_MODE_DIO,
     STD_HIGH,
     PORT_PIN_MODE_DIO,
     STD_ON,
     (Port_InternalResistor)PULL_UP},
    {PORT_PIN_OUT,
     STD_OFF,
     PortA_Pin2_ID,
     PORT_PIN_MODE_DIO,
     STD_HIGH,
     PORT_PIN_MODE_DIO,
     STD_ON,
     (Port_InternalResistor)PULL_UP},
    {PORT_PIN_OUT,
     STD_OFF,
     PortA_Pin3_ID,
     PORT_PIN_MODE_DIO,
     STD_HIGH,
     PORT_PIN_MODE_DIO,
     STD_ON,
     (Port_InternalResistor)PULL_UP},
    {PORT_PIN_OUT,
     STD_OFF,
     PortA_Pin4_ID,
     PORT_PIN_MODE_DIO,
     STD_HIGH,
     PORT_PIN_MODE_DIO,
     STD_ON,
     (Port_InternalResistor)PULL_UP},
    {PORT_PIN_OUT,
     STD_OFF,
     PortA_Pin5_ID,
     PORT_PIN_MODE_DIO,
     STD_HIGH,
     PORT_PIN_MODE_DIO,
     STD_ON,
     (Port_InternalResistor)PULL_UP},
    {PORT_PIN_OUT,
     STD_OFF,
     PortA_Pin6_ID,
     PORT_PIN_MODE_DIO,
     STD_HIGH,
     PORT_PIN_MODE_DIO,
     STD_ON,
     (Port_InternalResistor)PULL_UP},
    {PORT_PIN_OUT,
     STD_OFF,
     PortA_Pin7_ID,
     PORT_PIN_MODE_DIO,
     STD_HIGH,
     PORT_PIN_MODE_DIO,
     STD_ON,
     (Port_InternalResistor)PULL_UP},

    /*******************************************************************************
    *                              PORT B initialaztion                           *
    *******************************************************************************/
    {PORT_PIN_OUT,
     STD_OFF,
     PortB_Pin0_ID,
     PORT_PIN_MODE_DIO,
     STD_HIGH,
     PORT_PIN_MODE_DIO,
     STD_ON,
     (Port_InternalResistor)PULL_UP},
    {PORT_PIN_OUT,
     STD_OFF,
     PortB_Pin1_ID,
     PORT_PIN_MODE_DIO,
     STD_HIGH,
     PORT_PIN_MODE_DIO,
     STD_ON,
     (Port_InternalResistor)PULL_UP},
    {PORT_PIN_OUT,
     STD_OFF,
     PortB_Pin2_ID,
     PORT_PIN_MODE_DIO,
     STD_HIGH,
     PORT_PIN_MODE_DIO,
     STD_ON,
     (Port_InternalResistor)PULL_UP},
    {PORT_PIN_OUT,
     STD_OFF,
     PortB_Pin3_ID,
     PORT_PIN_MODE_DIO,
     STD_HIGH,
     PORT_PIN_MODE_DIO,
     STD_ON,
     (Port_InternalResistor)PULL_UP},
    {PORT_PIN_OUT,
     STD_OFF,
     PortB_Pin4_ID,
     PORT_PIN_MODE_DIO,
     STD_HIGH,
     PORT_PIN_MODE_DIO,
     STD_ON,
     (Port_InternalResistor)PULL_UP},
    {PORT_PIN_OUT,
     STD_OFF,
     PortB_Pin5_ID,
     PORT_PIN_MODE_DIO,
     STD_HIGH,
     PORT_PIN_MODE_DIO,
     STD_ON,
     (Port_InternalResistor)PULL_UP},
    {PORT_PIN_OUT,
     STD_OFF,
     PortB_Pin6_ID,
     PORT_PIN_MODE_DIO,
     STD_HIGH,
     PORT_PIN_MODE_DIO,
     STD_ON,
     (Port_InternalResistor)PULL_UP},
    {PORT_PIN_OUT,
     STD_OFF,
     PortB_Pin7_ID,
     PORT_PIN_MODE_DIO,
     STD_HIGH,
     PORT_PIN_MODE_DIO,
     STD_ON,
     (Port_InternalResistor)PULL_UP},

    /*******************************************************************************
    *                              PORT C initialaztion                           *
    *******************************************************************************/
    {PORT_PIN_OUT,
     STD_OFF,
     PortC_Pin0_ID,
     PORT_PIN_MODE_DIO,
     STD_HIGH,
     PORT_PIN_MODE_DIO,
     STD_ON,
     (Port_InternalResistor)PULL_UP},
    {PORT_PIN_OUT,
     STD_OFF,
     PortC_Pin1_ID,
     PORT_PIN_MODE_DIO,
     STD_HIGH,
     PORT_PIN_MODE_DIO,
     STD_ON,
     (Port_InternalResistor)PULL_UP},
    {PORT_PIN_OUT,
     STD_OFF,
     PortC_Pin2_ID,
     PORT_PIN_MODE_DIO,
     STD_HIGH,
     PORT_PIN_MODE_DIO,
     STD_ON,
     (Port_InternalResistor)PULL_UP},
    {PORT_PIN_OUT,
     STD_OFF,
     PortC_Pin3_ID,
     PORT_PIN_MODE_DIO,
     STD_HIGH,
     PORT_PIN_MODE_DIO,
     STD_ON,
     (Port_InternalResistor)PULL_UP},
    {PORT_PIN_OUT,
     STD_OFF,
     PortC_Pin4_ID,
     PORT_PIN_MODE_DIO,
     STD_HIGH,
     PORT_PIN_MODE_DIO,
     STD_ON,
     (Port_InternalResistor)PULL_UP},
    {PORT_PIN_OUT,
     STD_OFF,
     PortC_Pin5_ID,
     PORT_PIN_MODE_DIO,
     STD_HIGH,
     PORT_PIN_MODE_DIO,
     STD_ON,
     (Port_InternalResistor)PULL_UP},
    {PORT_PIN_OUT,
     STD_OFF,
     PortC_Pin6_ID,
     PORT_PIN_MODE_DIO,
     STD_HIGH,
     PORT_PIN_MODE_DIO,
     STD_ON,
     (Port_InternalResistor)PULL_UP},
    {PORT_PIN_OUT,
     STD_OFF,
     PortC_Pin7_ID,
     PORT_PIN_MODE_DIO,
     STD_HIGH,
     PORT_PIN_MODE_DIO,
     STD_ON,
     (Port_InternalResistor)PULL_UP},

    /*******************************************************************************
    *                              PORT D initialaztion                           *
    *******************************************************************************/
    {PORT_PIN_OUT,
     STD_OFF,
     PortD_Pin0_ID,
     PORT_PIN_MODE_DIO,
     STD_HIGH,
     PORT_PIN_MODE_DIO,
     STD_ON,
     (Port_InternalResistor)PULL_UP},
    {PORT_PIN_OUT,
     STD_OFF,
     PortD_Pin1_ID,
     PORT_PIN_MODE_DIO,
     STD_HIGH,
     PORT_PIN_MODE_DIO,
     STD_ON,
     (Port_InternalResistor)PULL_UP},
    {PORT_PIN_OUT,
     STD_OFF,
     PortD_Pin2_ID,
     PORT_PIN_MODE_DIO,
     STD_HIGH,
     PORT_PIN_MODE_DIO,
     STD_ON,
     (Port_InternalResistor)PULL_UP},
    {PORT_PIN_OUT,
     STD_OFF,
     PortD_Pin3_ID,
     PORT_PIN_MODE_DIO,
     STD_HIGH,
     PORT_PIN_MODE_DIO,
     STD_ON,
     (Port_InternalResistor)PULL_UP},
    {PORT_PIN_OUT,
     STD_OFF,
     PortD_Pin4_ID,
     PORT_PIN_MODE_DIO,
     STD_HIGH,
     PORT_PIN_MODE_DIO,
     STD_ON,
     (Port_InternalResistor)PULL_UP},
    {PORT_PIN_OUT,
     STD_OFF,
     PortD_Pin5_ID,
     PORT_PIN_MODE_DIO,
     STD_HIGH,
     PORT_PIN_MODE_DIO,
     STD_ON,
     (Port_InternalResistor)PULL_UP},
    {PORT_PIN_OUT,
     STD_OFF,
     PortD_Pin6_ID,
     PORT_PIN_MODE_DIO,
     STD_HIGH,
     PORT_PIN_MODE_DIO,
     STD_ON,
     (Port_InternalResistor)PULL_UP},
    {PORT_PIN_OUT,
     STD_OFF,
     PortD_Pin7_ID,
     PORT_PIN_MODE_DIO,
     STD_HIGH,
     PORT_PIN_MODE_DIO,
     STD_ON,
     (Port_InternalResistor)PULL_UP},

    /*******************************************************************************
    *                              PORT E initialaztion                           *
    *******************************************************************************/
    {PORT_PIN_OUT,
     STD_OFF,
     PortE_Pin0_ID,
     PORT_PIN_MODE_DIO,
     STD_HIGH,
     PORT_PIN_MODE_DIO,
     STD_ON,
     (Port_InternalResistor)PULL_UP},
    {PORT_PIN_OUT,
     STD_OFF,
     PortE_Pin1_ID,
     PORT_PIN_MODE_DIO,
     STD_HIGH,
     PORT_PIN_MODE_DIO,
     STD_ON,
     (Port_InternalResistor)PULL_UP},
    {PORT_PIN_OUT,
     STD_OFF,
     PortE_Pin2_ID,
     PORT_PIN_MODE_DIO,
     STD_HIGH,
     PORT_PIN_MODE_DIO,
     STD_ON,
     (Port_InternalResistor)PULL_UP},
    {PORT_PIN_OUT,
     STD_OFF,
     PortE_Pin3_ID,
     PORT_PIN_MODE_DIO,
     STD_HIGH,
     PORT_PIN_MODE_DIO,
     STD_ON,
     (Port_InternalResistor)PULL_UP},
    {PORT_PIN_OUT,
     STD_OFF,
     PortE_Pin4_ID,
     PORT_PIN_MODE_DIO,
     STD_HIGH,
     PORT_PIN_MODE_DIO,
     STD_ON,
     (Port_InternalResistor)PULL_UP},
    {PORT_PIN_OUT,
     STD_OFF,
     PortE_Pin5_ID,
     PORT_PIN_MODE_DIO,
     STD_HIGH,
     PORT_PIN_MODE_DIO,
     STD_ON,
     (Port_InternalResistor)PULL_UP},

    /*******************************************************************************
    *                              PORT F initialaztion                           *
    *******************************************************************************/
    {PORT_PIN_OUT,
     STD_OFF,
     PortF_Pin0_ID,
     PORT_PIN_MODE_DIO,
     STD_HIGH,
     PORT_PIN_MODE_DIO,
     STD_ON,
     (Port_InternalResistor)PULL_UP},

    {PORT_PIN_LED1_DIRECTION,
     PORT_PIN_LED1_DIRECTION_CHANGEABLE,
     PORT_PIN_LED1_ID,
     PORT_PIN_LED1_INITIAL_MODE,
     PORT_PIN_LED1_LEVEL_VALUE,
     PORT_PIN_LED1_MODE,
     PORT_PIN_LED1_MODE_CHANGEABLE,
     PORT_PIN_LED1_INTERNAL_RESISTOR},

    {PORT_PIN_OUT,
     STD_OFF,
     PortF_Pin2_ID,
     PORT_PIN_MODE_DIO,
     STD_HIGH,
     PORT_PIN_MODE_DIO,
     STD_ON,
     (Port_InternalResistor)PULL_UP},

    {PORT_PIN_OUT,
     STD_OFF,
     PortF_Pin3_ID,
     PORT_PIN_MODE_DIO,
     STD_HIGH,
     PORT_PIN_MODE_DIO,
     STD_ON,
     (Port_InternalResistor)PULL_UP},

    {PORT_PIN_SW1_DIRECTION,
     PORT_PIN_SW1_DIRECTION_CHANGEABLE,
     PORT_PIN_SW1_ID,
     PORT_PIN_SW1_INITIAL_MODE,
     PORT_PIN_SW1_LEVEL_VALUE,
     PORT_PIN_SW1_MODE,
     PORT_PIN_SW1_MODE_CHANGEABLE,
     PORT_PIN_SW1_INTERNAL_RESISTOR}};
