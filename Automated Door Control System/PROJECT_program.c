/**************************************************************************************/
/********************************PROJECT_interface.h***********************************/
/**************************Created: 18/3/2024  02:00:00 PM*****************************/
/********************************Author: Amira Ismail**********************************/
/**************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "PROJECT_interface.h"
#include "PROJECT_config.h"
#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "KEYPAD_interface.h"
#include "KEYPAD_config.h"
#include "SERVO_interface.h"
#include "util/delay.h"


u16 NUM = 0;
void PROJECT_voidInit(void)
{
	KeyPad_Init();
	CLCD_voidInit();
	SERVO_voidInit();
	DIO_voidSetPinDirection(LED_PORT, LED_PIN, DIO_PORT_OUTPUT);
	DIO_voidSetPinDirection(BUZ_PORT, BUZ_PIN, DIO_PORT_OUTPUT);
}

void PROJECT_voidStart(void)
{
	u8 Trails_Count = 0;

	while(Trails_Count < Max_Trials_num)
	{
		CLCD_voidSendString("Enter the Password: ");
		PROJECT_voidWritePass();

		if(NUM == Password)
		{
			CLCD_voidClear();
			CLCD_voidSendString(" ***DOOR OPENED***");
			SERVO_voidStart(90);
			break;
		}
		else
		{
			Trails_Count++;
			CLCD_voidClear();
			CLCD_voidSendString("  PASS NOT CORRECT");
			_delay_ms(1000);
			CLCD_voidClear();
		}
	}
	if (Trails_Count == Max_Trials_num)
	{
		PROJECT_voidStop();
	}
}

void PROJECT_voidWritePass(void)
{
	u8 copy_u8Pass, COUNTER = 0, local_u8CNT = 0;
	u16 temp = 0;

	while(local_u8CNT < Pass_nums)
	{
		copy_u8Pass = KeyPad_GetValue();
		if (copy_u8Pass != NOTKEY)
		{
			CLCD_voidSendData(copy_u8Pass);
			_delay_ms(300);
			CLCD_voidGoToPosition(2, COUNTER);
			CLCD_voidSendData('*');
			COUNTER++;
			local_u8CNT++;
			temp = temp *10 + copy_u8Pass - '0';
		}
	}
	NUM = temp;
	temp = 0;
}

void PROJECT_voidStop(void)
{
	DIO_voidSetPinValue(LED_PORT, LED_PIN, DIO_PIN_HIGH);
	DIO_voidSetPinValue(BUZ_PORT, BUZ_PIN, DIO_PIN_HIGH);

	CLCD_voidClear();
	CLCD_voidGoToPosition(2, 2);
	CLCD_voidSendString("TRY AGAIN LATER");
}
