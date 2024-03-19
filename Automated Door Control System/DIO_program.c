/**************************************************************************************/
/***********************************DIO_program.c**************************************/
/**************************Created: 29/2/2024  8:34:00 PM******************************/
/********************************Author: Amira Ismail**********************************/
/**************************************************************************************/



#include"STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"


                         /*************** PIN APIS ***************/

void DIO_voidSetPinDirection(u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8PinDirection)
{
	if(copy_u8PinId<=7)
	{
		if(copy_u8PinDirection == DIO_PIN_OUTPUT)
			switch(copy_u8PortId)
			{
			case DIO_PORTA:SET_BIT(DDRA,copy_u8PinId);break;
			case DIO_PORTB:SET_BIT(DDRB,copy_u8PinId);break;
			case DIO_PORTC:SET_BIT(DDRC,copy_u8PinId);break;
			case DIO_PORTD:SET_BIT(DDRD,copy_u8PinId);break;
			}
		else if(copy_u8PinDirection == DIO_PIN_INPUT)
			switch(copy_u8PortId)
			{
			case DIO_PORTA:CLR_BIT(DDRA,copy_u8PinId);break;
			case DIO_PORTB:CLR_BIT(DDRB,copy_u8PinId);break;
			case DIO_PORTC:CLR_BIT(DDRC,copy_u8PinId);break;
			case DIO_PORTD:CLR_BIT(DDRD,copy_u8PinId);break;
			}
	}

}

void DIO_voidSetPinValue(u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8PinValue)
{
	if(copy_u8PinId<=7)
	{
		if(copy_u8PinValue == DIO_PIN_HIGH)
		{
			switch(copy_u8PortId)
			{
			case DIO_PORTA:SET_BIT(PORTA,copy_u8PinId);break;
			case DIO_PORTB:SET_BIT(PORTB,copy_u8PinId);break;
			case DIO_PORTC:SET_BIT(PORTC,copy_u8PinId);break;
			case DIO_PORTD:SET_BIT(PORTD,copy_u8PinId);break;
			}
		}

		else if(copy_u8PinId<=7)
		{
			if(copy_u8PinValue == DIO_PIN_LOW)
			{
				switch(copy_u8PortId)
				{
				case DIO_PORTA:CLR_BIT(PORTA,copy_u8PinId);break;
				case DIO_PORTB:CLR_BIT(PORTB,copy_u8PinId);break;
				case DIO_PORTC:CLR_BIT(PORTC,copy_u8PinId);break;
				case DIO_PORTD:CLR_BIT(PORTD,copy_u8PinId);break;
				}
			}
		}
	}
}

void DIO_voidGetPinValue(u8 copy_u8PortId, u8 copy_u8PinId, u8 *copy_pu8_PinValue)
{
	if(copy_u8PinId<=7)
	{
		switch(copy_u8PortId)
		{
		case DIO_PORTA:*copy_pu8_PinValue = GET_BIT(PINA,copy_u8PinId);break;
		case DIO_PORTB:*copy_pu8_PinValue = GET_BIT(PINB,copy_u8PinId);break;
		case DIO_PORTC:*copy_pu8_PinValue = GET_BIT(PINC,copy_u8PinId);break;
		case DIO_PORTD:*copy_pu8_PinValue = GET_BIT(PIND,copy_u8PinId);break;
		}
	}
}

u8 DIO_u8GetPinValue(u8 copy_u8PortId, u8 copy_u8PinId)
{
	u8 Local_u8Reading;
	if(copy_u8PinId<=7)
	{
		switch(copy_u8PortId)
		{
		case DIO_PORTA:Local_u8Reading = GET_BIT(PINA,copy_u8PinId);break;
		case DIO_PORTB:Local_u8Reading = GET_BIT(PINB,copy_u8PinId);break;
		case DIO_PORTC:Local_u8Reading = GET_BIT(PINC,copy_u8PinId);break;
		case DIO_PORTD:Local_u8Reading = GET_BIT(PIND,copy_u8PinId);break;
		}
	}
	return Local_u8Reading;
}

void DIO_voidTogglePinValue(u8 copy_u8PortId, u8 copy_u8PinId)
{
	switch(copy_u8PortId)
	{
	case DIO_PORTA: TOG_BIT(PORTA, copy_u8PinId); break;
	case DIO_PORTB: TOG_BIT(PORTB, copy_u8PinId); break;
	case DIO_PORTC: TOG_BIT(PORTC, copy_u8PinId); break;
	case DIO_PORTD: TOG_BIT(PORTD, copy_u8PinId); break;
	}
}

void DIO_voidActivePinInPullUpResistance(u8 copy_u8PortId, u8 copy_u8PinId)
{
	switch(copy_u8PortId)
	{
	case DIO_PORTA: SET_BIT(PORTA, copy_u8PinId); break;
	case DIO_PORTB: SET_BIT(PORTB, copy_u8PinId); break;
	case DIO_PORTC: SET_BIT(PORTC, copy_u8PinId); break;
	case DIO_PORTD: SET_BIT(PORTD, copy_u8PinId); break;
	}
}



                      /*************** PORT APIS ***************/

void DIO_voidSetPortDirection(u8 copy_u8PortId, u8 copy_u8PortDirection)
{
	switch(copy_u8PortId)
	{
	case DIO_PORTA:DDRA = copy_u8PortDirection;break;
	case DIO_PORTB:DDRB = copy_u8PortDirection;break;
	case DIO_PORTC:DDRC = copy_u8PortDirection;break;
	case DIO_PORTD:DDRD = copy_u8PortDirection;break;
	}
}

void DIO_voidSetPortValue(u8 copy_u8PortId, u8 copy_u8PortValue)
{
	switch(copy_u8PortId)
	{
	case DIO_PORTA:PORTA = copy_u8PortValue;break;
	case DIO_PORTB:PORTB = copy_u8PortValue;break;
	case DIO_PORTC:PORTC = copy_u8PortValue;break;
	case DIO_PORTD:PORTD = copy_u8PortValue;break;
	}
}

void DIO_voidGetPortValue(u8 copy_u8PortId, u8 *copy_pu8_PinValue)
{
	switch(copy_u8PortId)
	{
	case DIO_PORTA: *copy_pu8_PinValue = PORTA;break;
	case DIO_PORTB: *copy_pu8_PinValue = PORTB;break;
	case DIO_PORTC: *copy_pu8_PinValue = PORTC;break;
	case DIO_PORTD: *copy_pu8_PinValue = PORTD;break;
	}
}

void DIO_voidTogglePortValue(u8 copy_u8PortId)
{
	switch(copy_u8PortId)
	{
	case DIO_PORTA: PORTA^=DIO_PORT_HIGH;break;
	case DIO_PORTB: PORTB^=DIO_PORT_HIGH;break;
	case DIO_PORTC: PORTC^=DIO_PORT_HIGH;break;
	case DIO_PORTD: PORTD^=DIO_PORT_HIGH;break;
	}
}

void DIO_voidActivePortInPullUpResistance(u8 copy_u8PortId)
{
	switch(copy_u8PortId)
	{
	case DIO_PORTA: PORTA = DIO_PORT_HIGH;break;
	case DIO_PORTB: PORTB = DIO_PORT_HIGH;break;
	case DIO_PORTC: PORTC = DIO_PORT_HIGH;break;
	case DIO_PORTD: PORTD = DIO_PORT_HIGH;break;
	}
}







