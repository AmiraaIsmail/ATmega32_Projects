/**************************************************************************************/
/********************************PWM_program.c*****************************************/
/**************************Created: 17/3/2024  11:00:00 AM*****************************/
/********************************Author: Amira Ismail**********************************/
/**************************************************************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "PWM_ config.h"
#include "PWM_ private.h"
#include "PWM_ register.h"
#include "PWM_interface.h"


/*****************************************TMR0*****************************************/
void PWM_voidInitChannel_0(void)
{
	//SELECT FAST PWM
	SET_BIT(TCCR0_REG, WGM00);
	SET_BIT(TCCR0_REG, WGM01);

	//SELECT NON INVERTING
	CLR_BIT(TCCR0_REG, COM00);
	SET_BIT(TCCR0_REG, COM01);
}

void PWM_voidGenerate_PWM_Channel_0(u8 copy_u8DutyCycle)
{
	u8 Local_u8ErrorState = true;
	if(copy_u8DutyCycle <= 100)
	{
		OCR0_REG = (((u16)copy_u8DutyCycle*256)/100)-1;

		//CHOOSE PRESCALER
#if PWM0_PRESCALER == PWM0_PRESCALER_1
		SET_BIT(TCCR0_REG,  CS00);
		CLR_BIT(TCCR0_REG,  CS01);
		CLR_BIT(TCCR0_REG,  CS02);

#elif PWM0_PRESCALER == PWM0_PRESCALER_8
		CLR_BIT(TCCR0_REG,  CS00);
		SET_BIT(TCCR0_REG,  CS01);
		CLR_BIT(TCCR0_REG,  CS02);

#elif PWM0_PRESCALER == PWM0_PRESCALER_64
		SET_BIT(TCCR0_REG,  CS00);
		SET_BIT(TCCR0_REG,  CS01);
		CLR_BIT(TCCR0_REG,  CS02);

#elif PWM0_PRESCALER == PWM0_PRESCALER_256
		CLR_BIT(TCCR0_REG,  CS00);
		CLR_BIT(TCCR0_REG,  CS01);
		SET_BIT(TCCR0_REG,  CS02);

#elif PWM0_PRESCALER == PWM_PRESCALER_1024
		SET_BIT(TCCR0_REG,  CS00);
		CLR_BIT(TCCR0_REG,  CS01);
		SET_BIT(TCCR0_REG,  CS02);
#endif
	}
	else
	{
		//return error state
		Local_u8ErrorState = false;
	}
}

void PWM_voidStopChannel_0(void)
{
	CLR_BIT(TCCR0_REG,  CS00);
	CLR_BIT(TCCR0_REG,  CS01);
	CLR_BIT(TCCR0_REG,  CS02);
}


/*****************************************TMR1*****************************************/
void PWM_voidInitChannel_1A(void)
{
	//SELECT FAST PWM
	CLR_BIT(TCCR1A_REG, WGM10);
	SET_BIT(TCCR1A_REG, WGM11);
	SET_BIT(TCCR1B_REG, WGM12);
	SET_BIT(TCCR1B_REG, WGM13);

	//SELECT NON INVERTING
	CLR_BIT(TCCR1A_REG, COM1A0);
	SET_BIT(TCCR1A_REG, COM1A1);
}

void PWM_voidGenerate_PWM_Channel_1A(u32 copy_u32Frequancey_hz ,f32 copy_f32DutyCycle)
{
	u8 Local_u8ErrorState = true;
	if(copy_f32DutyCycle <= 100)
	{
		//under condition tick time = 4us
		ICR1L_REG = ((1000000UL/copy_u32Frequancey_hz)/4)-1;

		OCR1AL_REG = ((copy_f32DutyCycle*(ICR1L_REG+1))/100)-1;

		//CHOOSE PRESCALER
#if PWM1A_PRESCALER == PWM1A_PRESCALER_1
		SET_BIT(TCCR1B_REG, CS10);
		CLR_BIT(TCCR1B_REG, CS11);
		CLR_BIT(TCCR1B_REG, CS12);

#elif PWM1A_PRESCALER == PWM1A_PRESCALER_8
		CLR_BIT(TCCR1B_REG, CS10);
		SET_BIT(TCCR1B_REG, CS11);
		CLR_BIT(TCCR1B_REG, CS12);

#elif PWM1A_PRESCALER == PWM1A_PRESCALER_64
		SET_BIT(TCCR1B_REG, CS10);
		SET_BIT(TCCR1B_REG, CS11);
		CLR_BIT(TCCR1B_REG, CS12);

#elif PWM1A_PRESCALER == PWM1A_PRESCALER_256
		CLR_BIT(TCCR1B_REG, CS10);
		CLR_BIT(TCCR1B_REG, CS11);
		SET_BIT(TCCR1B_REG, CS12);

#elif PWM1A_PRESCALER == PWM1A_PRESCALER_1024
		SET_BIT(TCCR1B_REG, CS10);
		CLR_BIT(TCCR1B_REG, CS11);
		SET_BIT(TCCR1B_REG, CS12);

#endif
	}
	else
	{
		//return error state
		Local_u8ErrorState = false;
	}
}

void PWM_voidStopChannel_1A(void)
{
	CLR_BIT(TCCR1B_REG, CS10);
	CLR_BIT(TCCR1B_REG, CS11);
	CLR_BIT(TCCR1B_REG, CS12);
}

