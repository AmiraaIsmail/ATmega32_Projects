/**************************************************************************************/
/********************************SERVO_program.c***************************************/
/**************************Created: 18/3/2024  01:00:00 PM*****************************/
/********************************Author: Amira Ismail**********************************/
/**************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "PWM_interface.h"
#include "SERVO_interface.h"

void SERVO_voidInit(void)
{
	DIO_voidSetPinDirection(DIO_PORTD, DIO_PIN5, DIO_PIN_OUTPUT);
	PWM_voidInitChannel_1A();
}

void SERVO_voidStart(u8 copy_u8Angle)
{
	u8 local_u8desired = (((copy_u8Angle + 90)/180)*5) + 5;
	PWM_voidGenerate_PWM_Channel_1A(copy_u32Frequancey_hz, local_u8desired);
}

void SERVO_voidStop(void)
{
	PWM_voidStopChannel_1A();
}
