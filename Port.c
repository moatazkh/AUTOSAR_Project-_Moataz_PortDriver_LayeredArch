/******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.c
 *
 * Description: Source file for TM4C123GH6PM Microcontroller - Port Driver.
 *
 * Author: Moataz Khaled
 ******************************************************************************/

#include "Port.h"

#if (PORT_DEV_ERROR_DETECT == STD_ON)

#include "Det.h"
/* AUTOSAR Version checking between Det and Dio Modules */
#if ((DET_AR_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION) || (DET_AR_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION) || (DET_AR_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
#error "The AR version of Det.h does not match the expected version"
#endif

#endif

#include "tm4c123gh6pm_registers.h"

STATIC uint8 PORT_Status = PORT_NOT_INITIALIZED;

uint8 portNum, pinNum;

void get_Port_Pin_Num(Port_PinType Pin)
{
    if (Pin < PortF_Pin0_ID)
    {
        portNum = Pin / 8;
        pinNum = Pin % 8;
    }
    else
    {
        portNum = 5; //PortF number
        pinNum = (Pin - PortF_Pin0_ID) % 5;
    }
}

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
*              - Provide initial value for o/p pin
*              - Setup the internal resistor for i/p pin
************************************************************************************/
void Port_Init(const Port_ConfigType *ConfigPtr)
{
#if (PORT_DEV_ERROR_DETECT == STD_ON)
    /* check if the input configuration pointer is not a NULL_PTR */
    if (ConfigPtr == NULL_PTR)
    {
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, Port_Init_SID,
                        PORT_E_PARAM_CONFIG);
    }
    else
#endif
    {

        volatile uint32 *PortGpio_Ptr = NULL_PTR; /* point to the required Port Registers base address */
        volatile uint32 delay = 0;

        // uint32 portNum, pinNum;
        // uint8 i = 0;
        // for (i = 0; i < PORT_CONFIGURED_PORTPINS; i++)
        // {
        get_Port_Pin_Num(ConfigPtr->portPinType);

        switch (portNum)
        {
        case 0:
            PortGpio_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
            break;
        case 1:
            PortGpio_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
            break;
        case 2:
            PortGpio_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
            break;
        case 3:
            PortGpio_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
            break;
        case 4:
            PortGpio_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
            break;
        case 5:
            PortGpio_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
            break;
        }

        /* Enable clock for PORT and allow time for clock to start*/
        SYSCTL_REGCGC2_REG |= (1 << portNum);
        delay = SYSCTL_REGCGC2_REG;

        if (((portNum == 3) && (pinNum == 7)) || ((portNum == 5) && (pinNum == 0))) /* PD7 or PF0 */
        {
            *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_LOCK_REG_OFFSET) = 0x4C4F434B;       /* Unlock the GPIOCR register */
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_COMMIT_REG_OFFSET), pinNum); /* Set the corresponding bit in GPIOCR register to allow changes on this pin */
        }
        else if ((portNum == 2) && (pinNum <= 3)) /* PC0 to PC3 */
        {
            /* Do Nothing ...  this is the JTAG pins */
            return;
        }
        else
        {
            /* Do Nothing ... No need to unlock the commit register for this pin */
        }

        CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET), pinNum);   /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
        CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET), pinNum);          /* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
        *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (pinNum * 4)); /* Clear the PMCx bits for this pin */

        if (ConfigPtr->direction == PORT_PIN_OUT)
        {
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET), pinNum); /* Set the corresponding bit in the GPIODIR register to configure it as output pin */

            if (ConfigPtr->initialValue == STD_HIGH)
            {
                SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DATA_REG_OFFSET), pinNum); /* Set the corresponding bit in the GPIODATA register to provide initial value 1 */
            }
            else
            {
                CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DATA_REG_OFFSET), pinNum); /* Clear the corresponding bit in the GPIODATA register to provide initial value 0 */
            }
        }
        else if (ConfigPtr->direction == PORT_PIN_IN)
        {
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET), pinNum); /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */

            if (ConfigPtr->resistorType == PULL_UP)
            {
                SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_UP_REG_OFFSET), pinNum); /* Set the corresponding bit in the GPIOPUR register to enable the internal pull up pin */
            }
            else if (ConfigPtr->resistorType == PULL_DOWN)
            {
                SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_DOWN_REG_OFFSET), pinNum); /* Set the corresponding bit in the GPIOPDR register to enable the internal pull down pin */
            }
            else
            {
                CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_UP_REG_OFFSET), pinNum);   /* Clear the corresponding bit in the GPIOPUR register to disable the internal pull up pin */
                CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_DOWN_REG_OFFSET), pinNum); /* Clear the corresponding bit in the GPIOPDR register to disable the internal pull down pin */
            }
        }
        else
        {
            /* Do Nothing */
        }

        SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET), pinNum); /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
        // }
        PORT_Status = PORT_INITIALIZED;
    }
}

void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction)
{
    volatile uint32 *PortGpio_Ptr = NULL_PTR; /* point to the required Port Registers base address */
    sint8 index = -1;

    for (uint8 i = 0; i < PORT_CONFIGURED_PORTPINS; i++)
    {
        if (Port_Configuration[i].portPinType == Pin)
        {
            index = i;
            break;
        }
    }

#if (PORT_DEV_ERROR_DETECT == STD_ON)
    if (PORT_NOT_INITIALIZED == PORT_Status)
    {
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                        Port_SetPinDirection_SID, PORT_E_UNINIT);
        // error = TRUE;
    }
    else
    {
        /* No Action Required */
    }
    /* check if the input pin is valid */
    if (index == -1)
    {
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, Port_SetPinDirection_SID,
                        PORT_E_PARAM_PIN);
    }
    else
    {
    }

    if (Port_Configuration[index].isDirectionChangable == STD_OFF)
    {
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, Port_SetPinDirection_SID,
                        PORT_E_DIRECTION_UNCHANGEABLE);
    }
    else
    {
    }

#endif
    get_Port_Pin_Num(Pin);
    switch (portNum)
    {
    case 0:
        PortGpio_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
        break;
    case 1:
        PortGpio_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
        break;
    case 2:
        PortGpio_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
        break;
    case 3:
        PortGpio_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
        break;
    case 4:
        PortGpio_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
        break;
    case 5:
        PortGpio_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
        break;
    }
    if (Direction == PORT_PIN_OUT)
    {
        SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET), pinNum); /* Set the corresponding bit in the GPIODIR register to configure it as output pin */

        if (Port_Configuration[index].initialValue == STD_HIGH)
        {
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DATA_REG_OFFSET), pinNum); /* Set the corresponding bit in the GPIODATA register to provide initial value 1 */
        }
        else
        {
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DATA_REG_OFFSET), pinNum); /* Clear the corresponding bit in the GPIODATA register to provide initial value 0 */
        }
    }
    else if (Direction == PORT_PIN_IN)
    {
        CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET), pinNum); /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */

        if (Port_Configuration[index].resistorType == PULL_UP)
        {
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_UP_REG_OFFSET), pinNum); /* Set the corresponding bit in the GPIOPUR register to enable the internal pull up pin */
        }
        else if (Port_Configuration[index].resistorType == PULL_DOWN)
        {
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_DOWN_REG_OFFSET), pinNum); /* Set the corresponding bit in the GPIOPDR register to enable the internal pull down pin */
        }
        else
        {
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_UP_REG_OFFSET), pinNum);   /* Clear the corresponding bit in the GPIOPUR register to disable the internal pull up pin */
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_DOWN_REG_OFFSET), pinNum); /* Clear the corresponding bit in the GPIOPDR register to disable the internal pull down pin */
        }
    }
}

void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode)
{
    volatile uint32 *PortGpio_Ptr = NULL_PTR; /* point to the required Port Registers base address */
    sint8 index = -1;

    for (uint8 i = 0; i < PORT_CONFIGURED_PORTPINS; i++)
    {
        if (Port_Configuration[i].portPinType == Pin)
        {
            index = i;
            break;
        }
    }

#if (PORT_DEV_ERROR_DETECT == STD_ON)
    if (PORT_NOT_INITIALIZED == PORT_Status)
    {
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                        Port_SetPinMode_SID, PORT_E_UNINIT);
        // error = TRUE;
    }
    else
    {
        /* No Action Required */
    }
    /* check if the input configuration pointer is not a NULL_PTR */
    if (index == -1)
    {
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, Port_SetPinMode_SID,
                        PORT_E_PARAM_PIN);
    }
    else
    {
    }

    if (Port_Configuration[index].isPinModeChangable == STD_OFF)
    {
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, Port_SetPinMode_SID,
                        PORT_E_MODE_UNCHANGEABLE);
    }
    else
    {
    }

    if (Mode > MAX_MODE_NUMBER)
    {
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, Port_SetPinMode_SID,
                        PORT_E_PARAM_INVALID_MODE);
    }
    else
    {
    }

#endif
    get_Port_Pin_Num(Pin);

    switch (portNum)
    {
    case 0:
        PortGpio_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
        break;
    case 1:
        PortGpio_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
        break;
    case 2:
        PortGpio_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
        break;
    case 3:
        PortGpio_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
        break;
    case 4:
        PortGpio_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
        break;
    case 5:
        PortGpio_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
        break;
    }

    SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET), pinNum);            /* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
    *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (pinNum * 4)); /* Clear the PMCx bits for this pin */
    *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (Mode << (pinNum * 4));        /* set the PMCx bits for this pin with the desired mode */
}

void Port_GetVersionInfo(Std_VersionInfoType *versioninfo)
{
#if (PORT_DEV_ERROR_DETECT == STD_ON)
    if (PORT_NOT_INITIALIZED == PORT_Status)
    {
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                        Port_GetVersionInfo_SID, PORT_E_UNINIT);
        // error = TRUE;
    }
    else
    {
        /* No Action Required */
    }
    /* check if the input configuration pointer is not a NULL_PTR */
    if (NULL_PTR == versioninfo)
    {
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, Port_GetVersionInfo_SID,
                        PORT_E_PARAM_POINTER);
    }

#endif
    versioninfo->vendorID = PORT_VENDOR_ID;
    versioninfo->moduleID = PORT_MODULE_ID;
    versioninfo->sw_major_version = PORT_SW_MAJOR_VERSION;
    versioninfo->sw_minor_version = PORT_SW_MINOR_VERSION;
    versioninfo->sw_patch_version = PORT_SW_PATCH_VERSION;
}

void Port_RefreshPortDirection(void)
{
#if (PORT_DEV_ERROR_DETECT == STD_ON)
    if (PORT_NOT_INITIALIZED == PORT_Status)
    {
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                        Port_RefreshPortDirection_SID, PORT_E_UNINIT);
        // error = TRUE;
    }
    else
    {
        /* No Action Required */
    }

#endif
    for (uint8 i = 0; i < PORT_CONFIGURED_PORTPINS; i++)
    {
        Port_SetPinDirection(Port_Configuration[i].portPinType, Port_Configuration[i].direction);
    }
}
