/**************************************************************************************/
/********************************TIMER_program.c***************************************/
/**************************Created: 3/10/2023  6:00:00 PM******************************/
/********************************Author: Amira Ismail**********************************/
/**************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMER_interface.h"
#include "TIMER_register.h"
#include "TIMER_private.h"
#include "TIMER_config.h"

static void (*TIMER0_pvCallBack)(void) = NULL;
static void (*ICU_pvcallbackfunc)(void) = NULL;
static void (*TIMER1_pvCallBack)(void) = NULL;

void TIMER0_voidInit(void)
{
	//SET WAVE GENERATION MODE TO FAST PWM
	SET_BIT(TCCR0, TCCR0_WGM00);
	SET_BIT(TCCR0, TCCR0_WGM01);

	//SET COMPARE MATCH TO 250
	OCR0 = 64;

	//OUTPUT COMPARE MATCH INTERRUPT ENABLE
	SET_BIT(TIMSK, TIMSK_OCIE0);

	//SET PRESCALER TO 8
	CLR_BIT(TCCR0,TCCR0_CS00);
	SET_BIT(TCCR0, TCCR0_CS01);
	CLR_BIT(TCCR0, TCCR0_CS02);

	//CLEAR ON COMP, SET ON TOP
	SET_BIT(TCCR0, TCCR0_COM01);
	CLR_BIT(TCCR0, TCCR0_COM00);
}

u8 TIMER0_u8CallBack(void(*Copy_pvCallBack)(void))
{
	u8 Local_u8Error = 1;

	if(Copy_pvCallBack != NULL)
	{
		TIMER0_pvCallBack = Copy_pvCallBack;
	}
	else
	{
		Local_u8Error = NULL;
	}

	return Local_u8Error;
}

void TIMER1_voidInit(void)
{
	//INTIALIZE AT NORMAL MODE, SET PRESCALER TO 8
	CLR_BIT(TCCR1B, TCCR1B_CS10);
	SET_BIT(TCCR1B, TCCR1B_CS11);
	CLR_BIT(TCCR1B, TCCR1B_CS12);
}

void TIMER1_voidSetTimer1Val(u16 TIMER1_u16Val)
{
	TCNT1 = TIMER1_u16Val;
}

u16 TIMER1_u16ReadTimerVal(void)
{
	return TCNT1;
}

void TIMER1_voidReset (void)
{
	TCNT1 = 0x00;
	CLR_BIT(TIFR, TIFR_ICF1);
	CLR_BIT(TIFR, TIFR_TOV1);
}

void TIMER1_voidOVFIntEnable(void)
{
	SET_BIT(TIMSK, TIMSK_TOIE1);
	TCCR1A = 0;
}

void ICU_voidInit(void)
{
	/*set trigger to rising edge*/
	SET_BIT(TCCR1B,TCCR1B_ICES1);


	/*ENABLE INPUT CAPTURE INTERUPT*/
	SET_BIT(TIMSK,TIMSK_TICIE1);
}

u8 ICU_u8SetEdge(u8 Copy_u8Edge)
{
	u8 Local_erorr= OK;
	/**/
	if(Copy_u8Edge==ICU_RISING_EDGE)
	{
		SET_BIT(TCCR1B,TCCR1B_ICES1);
	}else if(Copy_u8Edge==ICU_FALLING_EDGE)
	{
		CLR_BIT(TCCR1B,TCCR1B_ICES1);
	}else
	{
		Local_erorr=NOK;
	}
	return Local_erorr;
}

void ICU_voidEnableInterrupt(void)
{
	SET_BIT(TIMSK,TIMSK_TICIE1);
}

void ICU_voidDisableInterrupt(void)
{
	CLR_BIT(TIMSK,TIMSK_TICIE1);
}
u16 ICU_u16ReadInputcapture(void)
{
	return ICR1;
}

u8 ICU_u8SetCallback(void(*copy_pvcallbackfunc)(void))
{
	u8 Local_states = OK;
	if(copy_pvcallbackfunc!=NULL)
	{
		ICU_pvcallbackfunc=copy_pvcallbackfunc;
	}else
	{
		Local_states=NOK;
	}

	return Local_states;
}

u8 TIMER1_u8OVFCallBack(void(*copy_pvcallbackfunc)(void))
{
	u8 Local_u8ErrorState = OK;
	if(copy_pvcallbackfunc != NULL)
	{
		TIMER1_pvCallBack = copy_pvcallbackfunc;
	}
	else
	{
		Local_u8ErrorState = NOK;
	}

	return Local_u8ErrorState;
}
//TIMER0 COMP
void __vector_10 (void) __attribute__((signal));
void __vector_10 (void)
{
	if(TIMER0_pvCallBack!=NULL)
	{
		TIMER0_pvCallBack();
	}
}

//TIMER1 CAPT
void __vector_6 (void) __attribute__((signal));
void __vector_6 (void)
{
	if(ICU_pvcallbackfunc!= NULL)
	{
		ICU_pvcallbackfunc();
	}
}

//TIMER1 ISR OVF
void __vector_9 (void) __attribute__((signal));
void __vector_9 (void)
{
	if(TIMER1_pvCallBack!=NULL)
	{
		TIMER1_pvCallBack();
	}
}
