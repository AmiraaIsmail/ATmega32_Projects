/**************************************************************************************/
/********************************Ultrasonic_program.c**********************************/
/**************************Created: 4/10/2023  11:00:00 PM*****************************/
/********************************Author: Amira Ismail**********************************/
/**************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "TIMER_interface.h"
#include "TIMER_register.h"
#include "Ultrasonic_interface.h"
#include "Ultrasonic_config.h"
#include "util/delay.h"

static volatile u8 flag = 0;
static volatile u16 t1, t2;
static u16 TOP;
u16 count;

void ULTRASONIC_voidInit(void)
{
	ICU_u8SetCallback(func);
	TIMER1_u8OVFCallBack(func1);
}

void ULTRASONIC_voidTrig(void)
{
	DIO_voidSetPinVal(TRIG_PORT, DIO_PIN_VAL_HIGH, TRIG_PIN);
	_delay_us(10);
	DIO_voidSetPinVal(TRIG_PORT, DIO_PIN_VAL_LOW, TRIG_PIN);
}

u16 ULTRASONIC_u16GetDist(void)
{
	u16 time, dist;
	//TCNT1 = 0;
	count = 0;
	_delay_ms(60);
	ICU_u8SetEdge(ICU_RISING_EDGE);
	ICU_voidEnableInterrupt();
	ULTRASONIC_voidTrig();
	while(flag<2)
	{

	}
	time = t2-t1 + TOP*count;
	dist = time /58;
	flag = 0;
}

void func (void)
{
	if(flag == 0)
	{
		t1 = ICR1;
		flag = 1;
		ICU_u8SetEdge(ICU_FALLING_EDGE);
	}
	else if(flag == 1)
	{
		t2 = ICR1;
		flag = 2;
		ICU_voidDisableInterrupt();
	}
}

void func1 (void)
{
	count++;
}

void ULTRASONIC_voidSetTopVal(u16 value)
{
	TOP = value;
}
