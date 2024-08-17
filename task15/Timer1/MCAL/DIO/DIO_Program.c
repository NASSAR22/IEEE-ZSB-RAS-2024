/*********************************************************/
/*************** Name 	  : Mahmoud Nagdy 	**************/
/*************** Date 	  : 27/4/2023 		**************/
/*************** SWC  	  : DIO 			**************/
/*************** Version  : 1.0 			**************/
/*********************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "DIO_Private.h"
#include "DIO_Config.h"

void DIO_voidInit(void)
{
	DIO_u8_DDRA_REG = Conc(DIO_u8_PA7_INITIAL_DIRECTION, DIO_u8_PA6_INITIAL_DIRECTION, DIO_u8_PA5_INITIAL_DIRECTION, DIO_u8_PA4_INITIAL_DIRECTION, DIO_u8_PA3_INITIAL_DIRECTION, DIO_u8_PA2_INITIAL_DIRECTION, DIO_u8_PA1_INITIAL_DIRECTION, DIO_u8_PA0_INITIAL_DIRECTION);
	DIO_u8_DDRB_REG = Conc(DIO_u8_PB7_INITIAL_DIRECTION, DIO_u8_PB6_INITIAL_DIRECTION, DIO_u8_PB5_INITIAL_DIRECTION, DIO_u8_PB4_INITIAL_DIRECTION, DIO_u8_PB3_INITIAL_DIRECTION, DIO_u8_PB2_INITIAL_DIRECTION, DIO_u8_PB1_INITIAL_DIRECTION, DIO_u8_PB0_INITIAL_DIRECTION);
	DIO_u8_DDRC_REG = Conc(DIO_u8_PC7_INITIAL_DIRECTION, DIO_u8_PC6_INITIAL_DIRECTION, DIO_u8_PC5_INITIAL_DIRECTION, DIO_u8_PC4_INITIAL_DIRECTION, DIO_u8_PC3_INITIAL_DIRECTION, DIO_u8_PC2_INITIAL_DIRECTION, DIO_u8_PC1_INITIAL_DIRECTION, DIO_u8_PC0_INITIAL_DIRECTION);
	DIO_u8_DDRD_REG = Conc(DIO_u8_PD7_INITIAL_DIRECTION, DIO_u8_PD6_INITIAL_DIRECTION, DIO_u8_PD5_INITIAL_DIRECTION, DIO_u8_PD4_INITIAL_DIRECTION, DIO_u8_PD3_INITIAL_DIRECTION, DIO_u8_PD2_INITIAL_DIRECTION, DIO_u8_PD1_INITIAL_DIRECTION, DIO_u8_PD0_INITIAL_DIRECTION);


	DIO_u8_PORTA_REG = Conc(DIO_u8_PA0_INITIAL_VALUE, DIO_u8_PA1_INITIAL_VALUE, DIO_u8_PA2_INITIAL_VALUE, DIO_u8_PA3_INITIAL_VALUE, DIO_u8_PA4_INITIAL_VALUE, DIO_u8_PA5_INITIAL_VALUE, DIO_u8_PA6_INITIAL_VALUE, DIO_u8_PA7_INITIAL_VALUE);
	DIO_u8_PORTB_REG = Conc(DIO_u8_PB0_INITIAL_VALUE, DIO_u8_PB1_INITIAL_VALUE, DIO_u8_PB2_INITIAL_VALUE, DIO_u8_PB3_INITIAL_VALUE, DIO_u8_PB4_INITIAL_VALUE, DIO_u8_PB5_INITIAL_VALUE, DIO_u8_PB6_INITIAL_VALUE, DIO_u8_PB7_INITIAL_VALUE);
	DIO_u8_PORTC_REG = Conc(DIO_u8_PC0_INITIAL_VALUE, DIO_u8_PC1_INITIAL_VALUE, DIO_u8_PC2_INITIAL_VALUE, DIO_u8_PC3_INITIAL_VALUE, DIO_u8_PC4_INITIAL_VALUE, DIO_u8_PC5_INITIAL_VALUE, DIO_u8_PC6_INITIAL_VALUE, DIO_u8_PC7_INITIAL_VALUE);
	DIO_u8_PORTD_REG = Conc(DIO_u8_PD0_INITIAL_VALUE, DIO_u8_PD1_INITIAL_VALUE, DIO_u8_PD2_INITIAL_VALUE, DIO_u8_PD3_INITIAL_VALUE, DIO_u8_PD4_INITIAL_VALUE, DIO_u8_PD5_INITIAL_VALUE, DIO_u8_PD6_INITIAL_VALUE, DIO_u8_PD7_INITIAL_VALUE);

}

u8 DIO_u8SetPinDirection(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinDirection)
{

	u8 Local_u8ErrorState = STD_TYPES_OK;

	if (Copy_u8PortId <= DIO_u8_PORTD && Copy_u8PinId <= DIO_u8_PIN7 && (Copy_u8PinDirection == DIO_u8_OUTPUT || Copy_u8PinDirection == DIO_u8_INPUT))
	{

		switch (Copy_u8PortId)
		{
		case DIO_u8_PORTA:
			switch (Copy_u8PinDirection)
			{
			case DIO_u8_OUTPUT:
				SET_BIT(DIO_u8_DDRA_REG, Copy_u8PinId);
				break;

			case DIO_u8_INPUT:
				CLR_BIT(DIO_u8_DDRA_REG, Copy_u8PinId);
				break;
			}
			break;

		case DIO_u8_PORTB:
			switch (Copy_u8PinDirection)
			{
			case DIO_u8_OUTPUT:
				SET_BIT(DIO_u8_DDRB_REG, Copy_u8PinId);
				break;

			case DIO_u8_INPUT:
				CLR_BIT(DIO_u8_DDRB_REG, Copy_u8PinId);
				break;
			}
			break;

		case DIO_u8_PORTC:
			switch (Copy_u8PinDirection)
			{
			case DIO_u8_OUTPUT:
				SET_BIT(DIO_u8_DDRC_REG, Copy_u8PinId);
				break;

			case DIO_u8_INPUT:
				CLR_BIT(DIO_u8_DDRC_REG, Copy_u8PinId);
				break;
			}
			break;

		case DIO_u8_PORTD:
			switch (Copy_u8PinDirection)
			{
			case DIO_u8_OUTPUT:
				SET_BIT(DIO_u8_DDRD_REG, Copy_u8PinId);
				break;

			case DIO_u8_INPUT:
				CLR_BIT(DIO_u8_DDRD_REG, Copy_u8PinId);
				break;
			}
			break;
		}
	}

	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}

	return Local_u8ErrorState;
}

u8 DIO_u8SetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinValue)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;

	if (Copy_u8PortId <= DIO_u8_PORTD && Copy_u8PinId <= DIO_u8_PIN7 && (Copy_u8PinValue == DIO_u8_LOW || Copy_u8PinValue == DIO_u8_HIGH))
	{
		switch (Copy_u8PortId)
		{
		case DIO_u8_PORTA:
			switch (Copy_u8PinValue)
			{

			case DIO_u8_HIGH:
				SET_BIT(DIO_u8_PORTA_REG, Copy_u8PinId);
				break;

			case DIO_u8_LOW:
				CLR_BIT(DIO_u8_PORTA_REG, Copy_u8PinId);
				break;
			default:
				Local_u8ErrorState = STD_TYPES_NOK;
			}
			break;

		case DIO_u8_PORTB:
			switch (Copy_u8PinValue)
			{

			case DIO_u8_HIGH:
				SET_BIT(DIO_u8_PORTB_REG, Copy_u8PinId);
				break;
			case DIO_u8_LOW:
				CLR_BIT(DIO_u8_PORTB_REG, Copy_u8PinId);
				break;
			default:
				Local_u8ErrorState = STD_TYPES_NOK;
			}
			break;

		case DIO_u8_PORTC:
			switch (Copy_u8PinValue)
			{
			case DIO_u8_LOW:
				CLR_BIT(DIO_u8_PORTC_REG, Copy_u8PinId);
				break;

			case DIO_u8_HIGH:
				SET_BIT(DIO_u8_PORTC_REG, Copy_u8PinId);
				break;
			default:
				Local_u8ErrorState = STD_TYPES_NOK;
			}
			break;

		case DIO_u8_PORTD:
			switch (Copy_u8PinValue)
			{
			case DIO_u8_LOW:
				CLR_BIT(DIO_u8_PORTC_REG, Copy_u8PinId);
				break;

			case DIO_u8_HIGH:
				SET_BIT(DIO_u8_PORTD_REG, Copy_u8PinId);
				break;
			default:
				Local_u8ErrorState = STD_TYPES_NOK;
			}
			break;
		}
	}

	else
	{
		u8 Local_u8ErrorState = STD_TYPES_NOK;
	}

	return Local_u8ErrorState;
}

u8 DIO_u8GetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 *Copy_pu8ReturnedPinValue)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	u8 Local_u8PinValue;

	if (Copy_u8PortId <= DIO_u8_PORTD && Copy_u8PinId <= DIO_u8_PIN7 && Copy_pu8ReturnedPinValue != NULL)
	{

		switch (Copy_u8PortId)
		{
		case DIO_u8_PORTA:
			Local_u8PinValue = GET_BIT(DIO_u8_PINA_REG, Copy_u8PinId);
			if (Local_u8PinValue == DIO_u8_LOW)
			{
				*Copy_pu8ReturnedPinValue = DIO_u8_LOW;
			}

			else
			{
				*Copy_pu8ReturnedPinValue = DIO_u8_HIGH;
			}
			break;

		case DIO_u8_PORTB:
			Local_u8PinValue = GET_BIT(DIO_u8_PINB_REG, Copy_u8PinId);
			if (Local_u8PinValue == DIO_u8_LOW)
			{
				*Copy_pu8ReturnedPinValue = DIO_u8_LOW;
			}

			else
			{
				*Copy_pu8ReturnedPinValue = DIO_u8_HIGH;
			}
			break;

		case DIO_u8_PORTC:
			Local_u8PinValue = GET_BIT(DIO_u8_PINC_REG, Copy_u8PinId);
			if (Local_u8PinValue == DIO_u8_LOW)
			{
				*Copy_pu8ReturnedPinValue = DIO_u8_LOW;
			}

			else
			{
				*Copy_pu8ReturnedPinValue = DIO_u8_HIGH;
			}
			break;

		case DIO_u8_PORTD:
			Local_u8PinValue = GET_BIT(DIO_u8_PIND_REG, Copy_u8PinId);
			if (Local_u8PinValue == DIO_u8_LOW)
			{
				*Copy_pu8ReturnedPinValue = DIO_u8_LOW;
			}

			else
			{
				*Copy_pu8ReturnedPinValue = DIO_u8_HIGH;
			}
			break;
		}
	}

	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}

	return Local_u8ErrorState;
}


u8 DIO_getPinValueWithoutPointer(u8 port_num, u8 pin_num)
{
	u8 pin_value = DIO_u8_LOW;


	if((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS))
	{
		/* Do Nothing */
	}
	else
	{
		/* Read the pin value as required */
		switch (port_num)
				{
				case DIO_u8_PORTA:
					pin_value = GET_BIT(DIO_u8_PINA_REG, pin_num);
					break;

				case DIO_u8_PORTB:
					pin_value = GET_BIT(DIO_u8_PINB_REG, pin_num);
					break;

				case DIO_u8_PORTC:
					pin_value = GET_BIT(DIO_u8_PINC_REG, pin_num);
					break;

				case DIO_u8_PORTD:
					pin_value = GET_BIT(DIO_u8_PIND_REG, pin_num);
					break;
				}
	}

	return pin_value;
}









u8 DIO_u8SetPortDirection(u8 Copy_u8PortId, u8 Copy_u8PortDirection)
{
	switch (Copy_u8PortId)
	{
	case DIO_u8_PORTA:
		switch (Copy_u8PortDirection)
		{
		case DIO_u8_INPUT:
			DIO_u8_DDRA_REG = DIO_u8PortLow;
			break;
		case DIO_u8_OUTPUT:
			DIO_u8_DDRA_REG = DIO_u8PortHigh;
			break;
		}
		break;

	case DIO_u8_PORTB:
		switch (Copy_u8PortDirection)
		{
		case DIO_u8_INPUT:
			DIO_u8_DDRB_REG = DIO_u8PortLow;
			break;
		case DIO_u8_OUTPUT:
			DIO_u8_DDRB_REG = DIO_u8PortHigh;
			break;
		}
		break;

	case DIO_u8_PORTC:
		switch (Copy_u8PortDirection)
		{
		case DIO_u8_INPUT:
			DIO_u8_DDRC_REG = DIO_u8PortLow;
			break;
		case DIO_u8_OUTPUT:
			DIO_u8_DDRC_REG = DIO_u8PortHigh;
			break;
		}
		break;

	case DIO_u8_PORTD:
		switch (Copy_u8PortDirection)
		{
		case DIO_u8_INPUT:
			DIO_u8_DDRD_REG = DIO_u8PortLow;
			break;
		case DIO_u8_OUTPUT:
			DIO_u8_DDRD_REG = DIO_u8PortHigh;
			break;
		}
		break;
	}
}

u8 DIO_u8SetPortValue(u8 Copy_u8PortId, u8 Copy_u8PortValue)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if (Copy_u8PortId <= DIO_u8_PORTD)
	{
		switch (Copy_u8PortId)
		{
		case DIO_u8_PORTA:
			switch (Copy_u8PortValue)
			{
			case DIO_u8_LOW:
				DIO_u8_PORTA_REG = DIO_u8PortLow;
				break;
			case DIO_u8_HIGH:
				DIO_u8_PORTA_REG = DIO_u8PortHigh;
				break;
			}
			break;

		case DIO_u8_PORTB:
			switch (Copy_u8PortValue)
			{
			case DIO_u8_LOW:
				DIO_u8_PORTB_REG = DIO_u8PortLow;
				break;
			case DIO_u8_HIGH:
				DIO_u8_PORTB_REG = DIO_u8PortHigh;
				break;
			}
			break;

		case DIO_u8_PORTC:
			switch (Copy_u8PortValue)
			{
			case DIO_u8_LOW:
				DIO_u8_PORTC_REG = DIO_u8PortLow;
				break;
			case DIO_u8_HIGH:
				DIO_u8_PORTC_REG = DIO_u8PortHigh;
				break;
			}
			break;

		case DIO_u8_PORTD:
			switch (Copy_u8PortValue)
			{
			case DIO_u8_LOW:
				DIO_u8_PORTD_REG = DIO_u8PortLow;
				break;
			case DIO_u8_HIGH:
				DIO_u8_PORTD_REG = DIO_u8PortHigh;
				break;
			}
			break;
		}
	}

	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}

	return Local_u8ErrorState;
}

u8 DIO_u8GetPortValue(u8 Copy_u8PortId, u8 *Copy_pu8ReturnedPortValue)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if (Copy_u8PortId <= DIO_u8_PORTD && Copy_pu8ReturnedPortValue != NULL)
	{
		switch (Copy_u8PortId)
		{
		case DIO_u8_PORTA:
			*Copy_pu8ReturnedPortValue = DIO_u8_PINA_REG;
			break;
		case DIO_u8_PORTB:
			*Copy_pu8ReturnedPortValue = DIO_u8_PINB_REG;
			break;

		case DIO_u8_PORTC:
			*Copy_pu8ReturnedPortValue = DIO_u8_PINC_REG;
			break;

		case DIO_u8_PORTD:
			*Copy_pu8ReturnedPortValue = DIO_u8_PIND_REG;
			break;
		}
	}

	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}

u8 DIO_u8SetValueToAllPins(u8 Copy_u8PortId, u8 Copy_u8Pin0, u8 Copy_u8Pin1, u8 Copy_u8Pin2, u8 Copy_u8Pin3, u8 Copy_u8Pin4, u8 Copy_u8Pin5, u8 Copy_u8Pin6, u8 Copy_u8Pin7)
{
	switch (Copy_u8PortId)
	{
	case DIO_u8_PORTA:
		if (Copy_u8Pin0 == DIO_u8_HIGH)
		{
			SET_BIT(DIO_u8_PORTA_REG, DIO_u8_PIN0);
		}
		else
		{
			CLR_BIT(DIO_u8_PORTA_REG, DIO_u8_PIN0);
		}

		if (Copy_u8Pin1 == DIO_u8_HIGH)
		{
			SET_BIT(DIO_u8_PORTA_REG, DIO_u8_PIN1);
		}
		else
		{
			CLR_BIT(DIO_u8_PORTA_REG, DIO_u8_PIN1);
		}

		if (Copy_u8Pin2 == DIO_u8_HIGH)
		{
			SET_BIT(DIO_u8_PORTA_REG, DIO_u8_PIN2);
		}
		else
		{
			CLR_BIT(DIO_u8_PORTA_REG, DIO_u8_PIN2);
		}

		if (Copy_u8Pin3 == DIO_u8_HIGH)
		{
			SET_BIT(DIO_u8_PORTA_REG, DIO_u8_PIN3);
		}
		else
		{
			CLR_BIT(DIO_u8_PORTA_REG, DIO_u8_PIN3);
		}

		if (Copy_u8Pin4 == DIO_u8_HIGH)
		{
			SET_BIT(DIO_u8_PORTA_REG, DIO_u8_PIN4);
		}
		else
		{
			CLR_BIT(DIO_u8_PORTA_REG, DIO_u8_PIN4);
		}

		if (Copy_u8Pin5 == DIO_u8_HIGH)
		{
			SET_BIT(DIO_u8_PORTA_REG, DIO_u8_PIN5);
		}
		else
		{
			CLR_BIT(DIO_u8_PORTA_REG, DIO_u8_PIN5);
		}

		if (Copy_u8Pin6 == DIO_u8_HIGH)
		{
			SET_BIT(DIO_u8_PORTA_REG, DIO_u8_PIN6);
		}
		else
		{
			CLR_BIT(DIO_u8_PORTA_REG, DIO_u8_PIN6);
		}

		if (Copy_u8Pin7 == DIO_u8_HIGH)
		{
			SET_BIT(DIO_u8_PORTA_REG, DIO_u8_PIN7);
		}
		else
		{
			CLR_BIT(DIO_u8_PORTA_REG, DIO_u8_PIN7);
		}
		break;

	case DIO_u8_PORTB:
		if (Copy_u8Pin0 == DIO_u8_HIGH)
		{
			SET_BIT(DIO_u8_PORTB_REG, DIO_u8_PIN0);
		}
		else
		{
			CLR_BIT(DIO_u8_PORTB_REG, DIO_u8_PIN0);
		}

		if (Copy_u8Pin1 == DIO_u8_HIGH)
		{
			SET_BIT(DIO_u8_PORTB_REG, DIO_u8_PIN1);
		}
		else
		{
			CLR_BIT(DIO_u8_PORTB_REG, DIO_u8_PIN1);
		}

		if (Copy_u8Pin2 == DIO_u8_HIGH)
		{
			SET_BIT(DIO_u8_PORTB_REG, DIO_u8_PIN2);
		}
		else
		{
			CLR_BIT(DIO_u8_PORTB_REG, DIO_u8_PIN2);
		}

		if (Copy_u8Pin3 == DIO_u8_HIGH)
		{
			SET_BIT(DIO_u8_PORTB_REG, DIO_u8_PIN3);
		}
		else
		{
			CLR_BIT(DIO_u8_PORTB_REG, DIO_u8_PIN3);
		}

		if (Copy_u8Pin4 == DIO_u8_HIGH)
		{
			SET_BIT(DIO_u8_PORTB_REG, DIO_u8_PIN4);
		}
		else
		{
			CLR_BIT(DIO_u8_PORTB_REG, DIO_u8_PIN4);
		}

		if (Copy_u8Pin5 == DIO_u8_HIGH)
		{
			SET_BIT(DIO_u8_PORTB_REG, DIO_u8_PIN5);
		}
		else
		{
			CLR_BIT(DIO_u8_PORTB_REG, DIO_u8_PIN5);
		}

		if (Copy_u8Pin6 == DIO_u8_HIGH)
		{
			SET_BIT(DIO_u8_PORTB_REG, DIO_u8_PIN6);
		}
		else
		{
			CLR_BIT(DIO_u8_PORTB_REG, DIO_u8_PIN6);
		}

		if (Copy_u8Pin7 == DIO_u8_HIGH)
		{
			SET_BIT(DIO_u8_PORTB_REG, DIO_u8_PIN7);
		}
		else
		{
			CLR_BIT(DIO_u8_PORTB_REG, DIO_u8_PIN7);
		}
		break;

	case DIO_u8_PORTC:
		if (Copy_u8Pin0 == DIO_u8_HIGH)
		{
			SET_BIT(DIO_u8_PORTC_REG, DIO_u8_PIN0);
		}
		else
		{
			CLR_BIT(DIO_u8_PORTC_REG, DIO_u8_PIN0);
		}

		if (Copy_u8Pin1 == DIO_u8_HIGH)
		{
			SET_BIT(DIO_u8_PORTC_REG, DIO_u8_PIN1);
		}
		else
		{
			CLR_BIT(DIO_u8_PORTC_REG, DIO_u8_PIN1);
		}

		if (Copy_u8Pin2 == DIO_u8_HIGH)
		{
			SET_BIT(DIO_u8_PORTC_REG, DIO_u8_PIN2);
		}
		else
		{
			CLR_BIT(DIO_u8_PORTC_REG, DIO_u8_PIN2);
		}

		if (Copy_u8Pin3 == DIO_u8_HIGH)
		{
			SET_BIT(DIO_u8_PORTC_REG, DIO_u8_PIN3);
		}
		else
		{
			CLR_BIT(DIO_u8_PORTC_REG, DIO_u8_PIN3);
		}

		if (Copy_u8Pin4 == DIO_u8_HIGH)
		{
			SET_BIT(DIO_u8_PORTC_REG, DIO_u8_PIN4);
		}
		else
		{
			CLR_BIT(DIO_u8_PORTC_REG, DIO_u8_PIN4);
		}

		if (Copy_u8Pin5 == DIO_u8_HIGH)
		{
			SET_BIT(DIO_u8_PORTC_REG, DIO_u8_PIN5);
		}
		else
		{
			CLR_BIT(DIO_u8_PORTC_REG, DIO_u8_PIN5);
		}

		if (Copy_u8Pin6 == DIO_u8_HIGH)
		{
			SET_BIT(DIO_u8_PORTC_REG, DIO_u8_PIN6);
		}
		else
		{
			CLR_BIT(DIO_u8_PORTC_REG, DIO_u8_PIN6);
		}

		if (Copy_u8Pin7 == DIO_u8_HIGH)
		{
			SET_BIT(DIO_u8_PORTC_REG, DIO_u8_PIN7);
		}
		else
		{
			CLR_BIT(DIO_u8_PORTC_REG, DIO_u8_PIN7);
		}
		break;

	case DIO_u8_PORTD:
		if (Copy_u8Pin0 == DIO_u8_HIGH)
		{
			SET_BIT(DIO_u8_PORTD_REG, DIO_u8_PIN0);
		}
		else
		{
			CLR_BIT(DIO_u8_PORTD_REG, DIO_u8_PIN0);
		}

		if (Copy_u8Pin1 == DIO_u8_HIGH)
		{
			SET_BIT(DIO_u8_PORTD_REG, DIO_u8_PIN1);
		}
		else
		{
			CLR_BIT(DIO_u8_PORTD_REG, DIO_u8_PIN1);
		}

		if (Copy_u8Pin2 == DIO_u8_HIGH)
		{
			SET_BIT(DIO_u8_PORTD_REG, DIO_u8_PIN2);
		}
		else
		{
			CLR_BIT(DIO_u8_PORTD_REG, DIO_u8_PIN2);
		}

		if (Copy_u8Pin3 == DIO_u8_HIGH)
		{
			SET_BIT(DIO_u8_PORTD_REG, DIO_u8_PIN3);
		}
		else
		{
			CLR_BIT(DIO_u8_PORTD_REG, DIO_u8_PIN3);
		}

		if (Copy_u8Pin4 == DIO_u8_HIGH)
		{
			SET_BIT(DIO_u8_PORTD_REG, DIO_u8_PIN4);
		}
		else
		{
			CLR_BIT(DIO_u8_PORTD_REG, DIO_u8_PIN4);
		}

		if (Copy_u8Pin5 == DIO_u8_HIGH)
		{
			SET_BIT(DIO_u8_PORTD_REG, DIO_u8_PIN5);
		}
		else
		{
			CLR_BIT(DIO_u8_PORTD_REG, DIO_u8_PIN5);
		}

		if (Copy_u8Pin6 == DIO_u8_HIGH)
		{
			SET_BIT(DIO_u8_PORTD_REG, DIO_u8_PIN6);
		}
		else
		{
			CLR_BIT(DIO_u8_PORTD_REG, DIO_u8_PIN6);
		}

		if (Copy_u8Pin7 == DIO_u8_HIGH)
		{
			SET_BIT(DIO_u8_PORTD_REG, DIO_u8_PIN7);
		}
		else
		{
			CLR_BIT(DIO_u8_PORTD_REG, DIO_u8_PIN7);
		}
		break;
	}
}
