/**************************************************************************************/
/********************************DIO_program.c*****************************************/
/**************************Created: 4/10/2023  1:00:00 PM******************************/
/********************************Author: Amira Ismail**********************************/
/**************************************************************************************/

#include"STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"


void DIO_voidSetPortDir(u8 DIO_u8Port ,u8 DIO_u8Dir)
{

		switch(DIO_u8Port)
		{
		case DIO_PORTA:DDRA=DIO_u8Dir;break;
		case DIO_PORTB:DDRB=DIO_u8Dir;break;
		case DIO_PORTC:DDRC=DIO_u8Dir;break;
		case DIO_PORTD:DDRD=DIO_u8Dir;break;
		}
	}


	void DIO_voidSetPortVal(u8 DIO_u8Port ,u8 DIO_u8Val)
	{

			switch(DIO_u8Port)
			{
			case DIO_PORTA:PORTA=DIO_u8Val;break;
			case DIO_PORTB:PORTB=DIO_u8Val;break;
			case DIO_PORTC:PORTC=DIO_u8Val;break;
			case DIO_PORTD:PORTD=DIO_u8Val;break;
			}
		}



	void DIO_voidSetPinDir(u8 DIO_u8Port ,u8 DIO_u8Dir,u8 DIO_u8Pin)
	{
		if(DIO_u8Pin<=7)
		{
			if(DIO_u8Dir==DIO_PIN_DIR_OUT)
				switch(DIO_u8Port)
				{
				case DIO_PORTA:SET_BIT(DDRA,DIO_u8Pin);break;
				case DIO_PORTB:SET_BIT(DDRB,DIO_u8Pin);break;
				case DIO_PORTC:SET_BIT(DDRC,DIO_u8Pin);break;
				case DIO_PORTD:SET_BIT(DDRD,DIO_u8Pin);break;
				}
			else if(DIO_u8Dir==DIO_PIN_DIR_IN)
				switch(DIO_u8Port)
				{
				case DIO_PORTA:CLR_BIT(DDRA,DIO_u8Pin);break;
				case DIO_PORTB:CLR_BIT(DDRB,DIO_u8Pin);break;
				case DIO_PORTC:CLR_BIT(DDRC,DIO_u8Pin);break;
				case DIO_PORTD:CLR_BIT(DDRD,DIO_u8Pin);break;
				}
		}

	}

	void DIO_voidSetPinVal(u8 DIO_u8Port ,u8 DIO_u8Val,u8 DIO_u8Pin)
	{
			if(DIO_u8Pin<=7)
			{
				if(DIO_u8Val==DIO_PIN_VAL_HIGH)
				{
					switch(DIO_u8Port)
					{
					case DIO_PORTA:SET_BIT(PORTA,DIO_u8Pin);break;
					case DIO_PORTB:SET_BIT(PORTB,DIO_u8Pin);break;
					case DIO_PORTC:SET_BIT(PORTC,DIO_u8Pin);break;
					case DIO_PORTD:SET_BIT(PORTD,DIO_u8Pin);break;
					}
				}

			else if(DIO_u8Pin<=7)
			{
				if(DIO_u8Val==DIO_PIN_VAL_LOW)
				{
					switch(DIO_u8Port)
					{
					case DIO_PORTA:CLR_BIT(PORTA,DIO_u8Pin);break;
					case DIO_PORTB:CLR_BIT(PORTB,DIO_u8Pin);break;
					case DIO_PORTC:CLR_BIT(PORTC,DIO_u8Pin);break;
					case DIO_PORTD:CLR_BIT(PORTD,DIO_u8Pin);break;
					}
				}
			}
		}
	}

	u8 DIO_u8GetPinVal(u8 DIO_u8Port,u8 DIO_u8Pin)
	{
		u8 Localu8Reading=0;
		if(DIO_u8Pin<=7)
		{
			switch(DIO_u8Port)
			{
			case DIO_PORTA:Localu8Reading=GET_BIT(PINA,DIO_u8Pin);break;
			case DIO_PORTB:Localu8Reading=GET_BIT(PINB,DIO_u8Pin);break;
			case DIO_PORTC:Localu8Reading=GET_BIT(PINC,DIO_u8Pin);break;
			case DIO_PORTD:Localu8Reading=GET_BIT(PIND,DIO_u8Pin);break;
			}
		}
		return Localu8Reading;
	}

