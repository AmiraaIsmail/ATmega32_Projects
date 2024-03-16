/*
 * main.c
 *
 *  Created on: Mar 14, 2024
 *      Author: Amira
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "ADC_interface.h"
#include "KEYPAD_interface.h"
#include "KEYPAD_config.h"
#include "util/delay.h"


#define max_enter_numbers	2

void main (void)
{
	u8 NUM, CNT = 0, threshold = 0;
	u16 digital, percent;

	KeyPad_Init();
	CLCD_voidInit();
	ADC_voidInit(ADC_REFERENCE_AVCC);

	CLCD_voidSendString("Enter threshold: ");
	while(CNT < max_enter_numbers)
	{
		NUM = KeyPad_GetValue();
		if (NUM != NOTKEY)
		{
			CLCD_voidSendData(NUM);
			CNT++;
			threshold = threshold *10 + NUM - '0';
		}
	}

	while(1)
	{
		ADC_u8ReadDigitalValue(0, &digital);
		CLCD_voidGoToPosition(2, 0);
		CLCD_voidSendString("Percentage = ");
		percent = (digital*(u32)100)/1023;
		CLCD_voidSendNum(percent);
		_delay_ms(1000);

		if(percent < threshold)
		{
			DIO_voidSetPinValue(DIO_PORTA, DIO_PIN5, DIO_PIN_HIGH);
		}
		else
		{
			DIO_voidSetPinValue(DIO_PORTA, DIO_PIN5, DIO_PIN_LOW);
		}
	}
}
