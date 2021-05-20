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

    {/* Pin direction */
     PORT_PIN_LED1_DIRECTION,

     /* Pin direction changeable or not */
     PORT_PIN_LED1_DIRECTION_CHANGEABLE,

     /* Pin id */
     PORT_PIN_LED1_ID,

     /* Pin Initial mode */

     PORT_PIN_LED1_INITIAL_MODE,

     /* Pin initial value */
     PORT_PIN_LED1_LEVEL_VALUE,

     /* Pin Mode  */
     PORT_PIN_LED1_MODE,

     /* Pin Mode changable */
     PORT_PIN_LED1_MODE_CHANGEABLE,

     /* Pin internal resisstor */
     PORT_PIN_LED1_INTERNAL_RESISTOR

    },

    {/* Pin direction */
     PORT_PIN_SW1_DIRECTION,

     /* Pin direction changeable or not */
     PORT_PIN_SW1_DIRECTION_CHANGEABLE,

     /* Pin id */
     PORT_PIN_SW1_ID,

     /* Pin Initial mode */

     PORT_PIN_SW1_INITIAL_MODE,

     /* Pin initial value */
     PORT_PIN_SW1_LEVEL_VALUE,

     /* Pin Mode  */
     PORT_PIN_SW1_MODE,

     /* Pin Mode changable */
     PORT_PIN_SW1_MODE_CHANGEABLE,

     /* Pin internal resisstor */
     PORT_PIN_SW1_INTERNAL_RESISTOR

    }};
