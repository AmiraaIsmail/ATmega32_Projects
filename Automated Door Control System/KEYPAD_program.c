/**************************************************************************************/
/*********************************KEYPAD_program.c*************************************/
/**************************Created: 3/3/2024  11:30:00 PM******************************/
/********************************Author: Amira Ismail**********************************/
/**************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "KEYPAD_interface.h"
#include "KEYPAD_config.h"
#include "util/delay.h"

#define  COL_INIT    7
#define  COL_FINAL   3

#define  ROW_INIT    5
#define  ROW_FINAL   2



const u8 KeyPad_Value[4][4] ={ {'7','8','9','/'},
		{'4','5','6','*'},
		{'1','2','3','-'},
		{'#','0','=','+'} };





void KeyPad_Init(void)
{

	DIO_voidSetPinDirection( KEYPAD_COLUMN_PORT , KEYPAD_COLUMN0 , DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection( KEYPAD_COLUMN_PORT , KEYPAD_COLUMN1 , DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection( KEYPAD_COLUMN_PORT , KEYPAD_COLUMN2 , DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection( KEYPAD_COLUMN_PORT , KEYPAD_COLUMN3 , DIO_PIN_OUTPUT);

	DIO_voidSetPinDirection( KEYPAD_ROW_PORT , KEYPAD_ROW0 , DIO_PIN_INPUT);
	DIO_voidSetPinDirection( KEYPAD_ROW_PORT , KEYPAD_ROW1 , DIO_PIN_INPUT);
	DIO_voidSetPinDirection( KEYPAD_ROW_PORT , KEYPAD_ROW2 , DIO_PIN_INPUT);
	DIO_voidSetPinDirection( KEYPAD_ROW_PORT , KEYPAD_ROW3 , DIO_PIN_INPUT);

	SET_BIT(PORTC , KEYPAD_ROW0);
	SET_BIT(PORTC , KEYPAD_ROW1);
	SET_BIT(PORTC , KEYPAD_ROW2);
	SET_BIT(PORTC , KEYPAD_ROW3);

	DIO_voidSetPinValue(KEYPAD_COLUMN_PORT , KEYPAD_COLUMN0 , DIO_PIN_HIGH);
	DIO_voidSetPinValue(KEYPAD_COLUMN_PORT , KEYPAD_COLUMN1 , DIO_PIN_HIGH);
	DIO_voidSetPinValue(KEYPAD_COLUMN_PORT , KEYPAD_COLUMN2 , DIO_PIN_HIGH);
	DIO_voidSetPinValue(KEYPAD_COLUMN_PORT , KEYPAD_COLUMN3 , DIO_PIN_HIGH);

}

u8 KeyPad_GetValue(void)
{
	u8 Col_Loc = 0;
	u8 Row_Loc = 0;

	u8 Value = NOTKEY;
	u8 Temp = 0;





	for(Col_Loc = COL_INIT ; Col_Loc >= COL_FINAL ; Col_Loc--)
	{
		//Activate the column
		if (Col_Loc == 5)
		{
			continue;
		}
		DIO_voidSetPinValue(KEYPAD_COLUMN_PORT , Col_Loc , DIO_PIN_LOW);

		for(Row_Loc = ROW_INIT ; Row_Loc >= ROW_FINAL ; Row_Loc--)
		{

			DIO_voidGetPinValue(KEYPAD_ROW_PORT , Row_Loc,&Temp);

			//wait until the switch is releases
			if(!Temp)
			{
				if(Col_Loc<5)
				{
					Value =  KeyPad_Value[ROW_INIT - Row_Loc][COL_INIT - Col_Loc-1];
				}
				else
				{
					Value =  KeyPad_Value[ROW_INIT - Row_Loc][COL_INIT - Col_Loc];
				}


				while(!Temp)
				{
					DIO_voidGetPinValue(KEYPAD_ROW_PORT , Row_Loc,&Temp);
				}

				//Delay to avoid bouncing , bouncing occurs in mechanical switches and can cause one switch press to be detected as multiple presses
				_delay_ms(10);
			}

		}

		//deactivate column again
		DIO_voidSetPinValue(KEYPAD_COLUMN_PORT , Col_Loc , DIO_PIN_HIGH);

	}

	return Value ;
}

