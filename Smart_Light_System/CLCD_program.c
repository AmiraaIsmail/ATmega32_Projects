/**************************************************************************************/
/********************************CLCD_interface.h************************************/
/**************************Created: 2/3/2024  11:30:00 AM******************************/
/********************************Author: Amira Ismail**********************************/
/**************************************************************************************/


#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "CLCD_config.h"
#include "util/delay.h"


void CLCD_voidSendCommand(u8 CLCD_u8Command)
{
	// RW low
	//DIO_voidSetPinValue(CLCD_CONTROL_PORT, CLCD_RW, DIO_PIN_LOW);
	// RS low
	DIO_voidSetPinValue(CLCD_CONTROL_PORT, CLCD_RS, DIO_PIN_LOW);
	// EN high
	DIO_voidSetPinValue(CLCD_CONTROL_PORT, CLCD_EN, DIO_PIN_HIGH);

#if	(LCD_MODE	==	LCD_4BIT)
	DIO_voidSetPinValue(CLCD_PORT,DIO_PIN0,(GET_BIT(CLCD_u8Command,4)));
	DIO_voidSetPinValue(CLCD_PORT,DIO_PIN1,(GET_BIT(CLCD_u8Command,5)));
	DIO_voidSetPinValue(CLCD_PORT,DIO_PIN2,(GET_BIT(CLCD_u8Command,6)));
	DIO_voidSetPinValue(CLCD_PORT,DIO_PIN4,(GET_BIT(CLCD_u8Command,7)));
	//Enable pulse
	DIO_voidSetPinValue(CLCD_CONTROL_PORT, CLCD_EN, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(CLCD_CONTROL_PORT, CLCD_EN, DIO_PIN_LOW);
	_delay_ms(1);

	DIO_voidSetPinValue(CLCD_PORT,DIO_PIN0,(GET_BIT(CLCD_u8Command,0)));
	DIO_voidSetPinValue(CLCD_PORT,DIO_PIN1,(GET_BIT(CLCD_u8Command,1)));
	DIO_voidSetPinValue(CLCD_PORT,DIO_PIN2,(GET_BIT(CLCD_u8Command,2)));
	DIO_voidSetPinValue(CLCD_PORT,DIO_PIN4,(GET_BIT(CLCD_u8Command,3)));
	//Enable pulse
	DIO_voidSetPinValue(CLCD_CONTROL_PORT, CLCD_EN, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(CLCD_CONTROL_PORT, CLCD_EN, DIO_PIN_LOW);
	_delay_ms(1);

#elif (LCD_MODE	== LCD_8BIT)
	DIO_voidSetPinValue(CLCD_PORT,DIO_PIN0,(GET_BIT(CLCD_u8Command,0)));
	DIO_voidSetPinValue(CLCD_PORT,DIO_PIN1,(GET_BIT(CLCD_u8Command,1)));
	DIO_voidSetPinValue(CLCD_PORT,DIO_PIN2,(GET_BIT(CLCD_u8Command,2)));
	DIO_voidSetPinValue(CLCD_PORT,DIO_PIN3,(GET_BIT(CLCD_u8Command,3)));
	DIO_voidSetPinValue(CLCD_PORT,DIO_PIN4,(GET_BIT(CLCD_u8Command,4)));
	DIO_voidSetPinValue(CLCD_PORT,DIO_PIN5,(GET_BIT(CLCD_u8Command,5)));
	DIO_voidSetPinValue(CLCD_PORT,DIO_PIN6,(GET_BIT(CLCD_u8Command,6)));
	DIO_voidSetPinValue(CLCD_PORT,DIO_PIN7,(GET_BIT(CLCD_u8Command,7)));

	//Enable pulse
	DIO_voidSetPinValue(CLCD_CONTROL_PORT, CLCD_EN, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(CLCD_CONTROL_PORT, CLCD_EN, DIO_PIN_LOW);
	_delay_ms(1);

#endif
}

void CLCD_voidSendData(u8 CLCD_u8Data)
{
	//Set RS = 1
	DIO_voidSetPinValue(CLCD_CONTROL_PORT, CLCD_RS, DIO_PIN_HIGH);

	//Set RW = 0
	//DIO_voidSetPinValue(CLCD_CONTROL_PORT, CLCD_RW, DIO_PIN_LOW);

	// EN high
	//DIO_voidSetPinValue(CLCD_CONTROL_PORT, CLCD_EN, DIO_PIN_HIGH);

	//Send Command
#if	(LCD_MODE	==	LCD_4BIT)
	DIO_voidSetPinValue(CLCD_PORT,DIO_PIN0,(GET_BIT(CLCD_u8Data,4)));
	DIO_voidSetPinValue(CLCD_PORT,DIO_PIN1,(GET_BIT(CLCD_u8Data,5)));
	DIO_voidSetPinValue(CLCD_PORT,DIO_PIN2,(GET_BIT(CLCD_u8Data,6)));
	DIO_voidSetPinValue(CLCD_PORT,DIO_PIN4,(GET_BIT(CLCD_u8Data,7)));
	//Enable pulse
	DIO_voidSetPinValue(CLCD_CONTROL_PORT, CLCD_EN, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(CLCD_CONTROL_PORT, CLCD_EN, DIO_PIN_LOW);
	_delay_ms(1);

	DIO_voidSetPinValue(CLCD_PORT,DIO_PIN0,(GET_BIT(CLCD_u8Data,0)));
	DIO_voidSetPinValue(CLCD_PORT,DIO_PIN1,(GET_BIT(CLCD_u8Data,1)));
	DIO_voidSetPinValue(CLCD_PORT,DIO_PIN2,(GET_BIT(CLCD_u8Data,2)));
	DIO_voidSetPinValue(CLCD_PORT,DIO_PIN4,(GET_BIT(CLCD_u8Data,3)));
	//Enable pulse
	DIO_voidSetPinValue(CLCD_CONTROL_PORT, CLCD_EN, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(CLCD_CONTROL_PORT, CLCD_EN, DIO_PIN_LOW);
	_delay_ms(1);

#elif (LCD_MODE	== LCD_8BIT)
	DIO_voidSetPinValue(CLCD_PORT,DIO_PIN0,(GET_BIT(CLCD_u8Data,0)));
	DIO_voidSetPinValue(CLCD_PORT,DIO_PIN1,(GET_BIT(CLCD_u8Data,1)));
	DIO_voidSetPinValue(CLCD_PORT,DIO_PIN2,(GET_BIT(CLCD_u8Data,2)));
	DIO_voidSetPinValue(CLCD_PORT,DIO_PIN3,(GET_BIT(CLCD_u8Data,3)));
	DIO_voidSetPinValue(CLCD_PORT,DIO_PIN4,(GET_BIT(CLCD_u8Data,4)));
	DIO_voidSetPinValue(CLCD_PORT,DIO_PIN5,(GET_BIT(CLCD_u8Data,5)));
	DIO_voidSetPinValue(CLCD_PORT,DIO_PIN6,(GET_BIT(CLCD_u8Data,6)));
	DIO_voidSetPinValue(CLCD_PORT,DIO_PIN7,(GET_BIT(CLCD_u8Data,7)));

	//Enable pulse
	DIO_voidSetPinValue(CLCD_CONTROL_PORT, CLCD_EN, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(CLCD_CONTROL_PORT, CLCD_EN, DIO_PIN_LOW);
	_delay_ms(1);

#endif
}

void CLCD_voidInit(void)
{
	DIO_voidSetPortDirection(CLCD_PORT, DIO_PORT_OUTPUT);
	DIO_voidSetPinDirection(CLCD_CONTROL_PORT, CLCD_EN, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(CLCD_CONTROL_PORT, CLCD_RS, DIO_PIN_OUTPUT);
	//DIO_voidSetPinDirection(CLCD_CONTROL_PORT, CLCD_RW, DIO_PIN_OUTPUT);
	_delay_ms(30);
	CLCD_voidSendCommand(0x38);
	_delay_ms(5);
	CLCD_voidSendCommand(0x38);
	_delay_us(150);
	CLCD_voidSendCommand(0x38);
	_delay_us(150);
	CLCD_voidSendCommand(0x01);
	_delay_us(150);
	CLCD_voidSendCommand(0x02);
	_delay_us(150);
	CLCD_voidSendCommand(0x06);
	_delay_us(150);
	CLCD_voidSendCommand(0x0d);
	_delay_us(150);
	CLCD_voidSendCommand(0x01);
	_delay_us(150);
}

void CLCD_voidSendString(u8 *pvString)
{
	while (*pvString !='\0')
	{
		CLCD_voidSendData(*pvString);
		pvString++;
	}
}

void CLCD_voidGoToPosition (u8 CLCD_uRow, u8 CLCD_u8Col)
{
	switch(CLCD_uRow)
	{
	case 0:
		CLCD_voidSendCommand(0x80 + CLCD_u8Col);break;
	case 1:
		CLCD_voidSendCommand(0xC0 + CLCD_u8Col);break;
	case 2:
		CLCD_voidSendCommand(0x94 + CLCD_u8Col);break;
	case 3:
		CLCD_voidSendCommand(0xD4 + CLCD_u8Col);break;
	}
}

void CLCD_voidWriteSpecialChar (u8 *pvPattern, u8 CLCD_u8BlockNum, u8 CLCD_u8x, u8 CLCD_u8y)
{
	u8 CLCD_u8CGRAMAddress = 0, i = 0;
	CLCD_u8CGRAMAddress = CLCD_u8BlockNum * 8;
	CLCD_voidSendCommand (CLCD_u8CGRAMAddress+64);
	for (i = 0; i < 8; i++)
	{
		CLCD_voidSendData(pvPattern[i]);
	}
	CLCD_voidGoToPosition(CLCD_u8x, CLCD_u8y);
	CLCD_voidSendData(pvPattern);
}

void CLCD_voidSendNum(u32 Num) // convert int to string
{
	u8 arr[10], i = 0, j = 0;
	if (Num == 0)
	{
		CLCD_voidSendData('0');
	}
	else
	{
		while(Num)
		{
			arr[i] = Num%10 + '0';
			Num/=10;
			i++;
		}
		for(j = i; j > 0; j--)
		{
			CLCD_voidSendData(arr[j-1]);
		}
	}
}

void CLCD_voidClear()
{
	CLCD_voidSendCommand(0X01);
	_delay_ms(2);
}
