/**************************************************************************************/
/********************************PWM_register.h****************************************/
/**************************Created: 17/3/2024  11:00:00 AM*****************************/
/********************************Author: Amira Ismail**********************************/
/**************************************************************************************/

#ifndef PWM_REGISTER_H_
#define PWM_REGISTER_H_


/************************************TMR0 REGISTERS************************************/
#define TCCR0_REG			(*(volatile u8*)0x53)
#define CS00                0
#define CS01                1
#define CS02                2
#define WGM01               3
#define COM00               4
#define COM01               5
#define WGM00               6
#define FOC0                7

#define TCNT0_REG           (*(volatile u8*)0x52)

#define OCR0_REG            (*(volatile u8*)0x5C)

#define TIMSK_REG           (*(volatile u8*)0x59)
#define TOIE0               0
#define OCIE0               1

#define TIFR_REG            (*(volatile u8*)0x58)
#define TOV0                0
#define OCF0                1


/************************************TMR1 REGISTERS************************************/
#define TCCR1A_REG			(*(volatile u8*)0x4F)
#define WGM10                	0
#define WGM11                	1
#define FOC1B                	2
#define FOC1A                	3
#define COM1B0               	4
#define COM1B1               	5
#define COM1A0               	6
#define COM1A1               	7

#define TCCR1B_REG           (*(volatile u8*)0x4E)
#define CS10					0
#define CS11					1
#define CS12					2
#define WGM12					3
#define WGM13					4
#define ICES1					6
#define ICNC1					7

#define TCNT1H_REG           (*(volatile u8*)0x4D)

#define TCNT1L_REG           (*(volatile u8*)0x4C)

#define OCR1AH_REG           (*(volatile u16*)0x4B)

#define OCR1AL_REG           (*(volatile u16*)0x4A)

#define OCR1BH_REG           (*(volatile u16*)0x49)

#define OCR1BL_REG           (*(volatile u16*)0x48)

#define ICR1H_REG            (*(volatile u16*)0x47)

#define ICR1L_REG            (*(volatile u16*)0x46)

#define TIMSK_REG            (*(volatile u8*)0x59)
#define TOIE1					2
#define OCIE1B					3
#define OCIE1A					4
#define TICIE1					5

#define TIFR_REG          	 (*(volatile u8*)0x58)
#define TOV1					2
#define OCF1B					3
#define OCF1A					4
#define ICF1					5


/************************************TMR2 REGISTERS************************************/
#define TCCR2_REG			(*(volatile u8*)0x45)
#define CS20                0
#define CS21                1
#define CS22                2
#define WGM21               3
#define COM20               4
#define COM21               5
#define WGM20               6
#define FOC2                7

#define TCNT2_REG           (*(volatile u8*)0x44)

#define OCR2_REG            (*(volatile u8*)0x43)

#define TIMSK_REG           (*(volatile u8*)0x59)
#define TOIE2               6
#define OCIE2               7

#define TIFR_REG            (*(volatile u8*)0x58)
#define TOV2                6
#define OCF2                7

#endif /*PWM_REGISTER_H_*/
