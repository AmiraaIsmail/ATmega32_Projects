/**************************************************************************************/
/****************************************main.c****************************************/
/**************************Created: 4/10/2023  10:00:00 PM*****************************/
/********************************Author: Amira Ismail**********************************/
/**************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "TIMER_interface.h"
#include "CLCD_interface.h"
#include "GIE_INTERFACE.h"
#include "Ultrasonic_interface.h"
#include "Ultrasonic_config.h"
#include "util/delay.h"

void main (void)
{
	u16 dist;

	CLCD_voidInit();
	TIMER0_voidInit();
	TIMER1_voidInit();
	ULTRASONIC_voidInit();
	GIE_Enable();
	ULTRASONIC_voidSetTopVal(65535);

	DIO_voidSetPinDir(TRIG_PORT, DIO_PIN_DIR_OUT, TRIG_PIN);

	while(1)
	{
		dist = ULTRASONIC_u16GetDist();
		CLCD_voidGotopos(0, 0);
		CLCD_voidSendString("Distance = ");
		CLCD_voidSendNum(dist);
		CLCD_voidSendString("  cm");

	}
}
