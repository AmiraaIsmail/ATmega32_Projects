/**************************************************************************************/
/********************************ADC_program.c************************************/
/**************************Created: 4/3/2024  1:00:00 PM******************************/
/********************************Author: Amira Ismail**********************************/
/**************************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC_register.h"
#include "ADC_interface.h"

void ADC_voidInit(u8 copy_u8ReferenceVoltage)
{
	//REFERENCE VOLTAGE
	switch(copy_u8ReferenceVoltage)
	{
	case ADC_REFERENCE_AVCC:
		CLR_BIT(ADMUX_REG, REFS1);
		SET_BIT(ADMUX_REG, REFS0);
		break;
	case ADC_REFERENCE_AREF:
		CLR_BIT(ADMUX_REG, REFS1);
		CLR_BIT(ADMUX_REG, REFS0);
		break;
	case ADC_REFERENCE_INTERNAL:  	//Vref = 2.56V internal
		SET_BIT(ADMUX_REG, REFS1);
		SET_BIT(ADMUX_REG, REFS0);
		break;
	}

	//RIGHT ADJUSTEMENT
	CLR_BIT(ADMUX_REG, ADLAR);

	//PRESCALER 128
	SET_BIT(ADCSRA_REG, ADPS0);
	SET_BIT(ADCSRA_REG, ADPS1);
	SET_BIT(ADCSRA_REG, ADPS2);

	//DISABLE INTERRUPT
	CLR_BIT(ADCSRA_REG, ADIE);

	//DISABLE AUTO TRIGGER
	CLR_BIT(ADCSRA_REG, ADATE);

	//ENABLE ADC
	SET_BIT(ADCSRA_REG, ADEN);
}

void ADC_u8ReadDigitalValue (u8 copy_u8ChannelNumber, u16* copy_pu16DigitalValue)
{
	if ((copy_pu16DigitalValue != NULL)&&(copy_u8ChannelNumber < 32))
	{
		//CLEAR ADMUX BITS
		ADMUX_REG &= 0b11100000;       //0b11100000 = 0xE0

		//SET THE REQUIRED CHANNEL
		ADMUX_REG |= copy_u8ChannelNumber;

		//START CONVERSION
		SET_BIT(ADCSRA_REG, ADSC);

		//BUSY WAIT
		while(GET_BIT(ADCSRA_REG, ADIF) == 0);

		//CLR FLAG
		SET_BIT(ADCSRA_REG, ADIF);

		//READ DATA
		*copy_pu16DigitalValue = ADC_u16_REG;

	}
	else
	{
		//
	}
}


