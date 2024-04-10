/**************************************************************************************/
/********************************TIMER_register.h**************************************/
/**************************Created: 3/10/2023  6:00:00 PM******************************/
/********************************Author: Amira Ismail**********************************/
/**************************************************************************************/

#ifndef TIMER_REGISTER_H_
#define TIMER_REGISTER_H_

#define OCR0		*((volatile u8*)0X5C)   //OUTPUT COMPARE REGISTER 0


#define TIMSK		*((volatile u8*)0X59)   //TIMER MASK
#define TIMSK_OCIE0		1					//OUTPUT COMPARE 0 INTERRUPT ENABLE
#define TIMSK_TICIE1    5                   //TIMER1 INPUT CAPTURE INTERRUPT ENABLE
#define TIMSK_TOIE1		2					//TIMER1 OVERFLOW INTERRUPT ENABLE

#define TCCR0		*((volatile u8*)0X53)   //TIMER0 CONTROL REGISTER
#define TCCR0_WGM00		6					//WAVEFORM GENERATION MODE BIT 0
#define TCCR0_WGM01		3					//WAVEFORM GENERATION MODE BIT 1

#define TCCR0_CS00		0					//PRESCALER BIT 0
#define TCCR0_CS01		1					//PRESCALER BIT 1
#define TCCR0_CS02		2					//PRESCALER BIT 2

#define TCCR0_COM00		4
#define TCCR0_COM01		5

#define TCCR1B		*((volatile u8*)0X4E)   //TIMER1 CONTROL REGISTER B
#define TCCR1B_CS10		0					//PRESCALER BIT 0
#define TCCR1B_CS11		1					//PRESCALER BIT 1
#define TCCR1B_CS12		2					//PRESCALER BIT 2
#define TCCR1B_ICES1    6                   //INPUT CAPTURE EDGR

#define TCCR1A		*((volatile u8*)0X4F)   //TIMER1 CONTROL REGISTER B

#define TIFR		*((volatile u8*)0X58)
#define TIFR_TOV1		2
#define TIFR_ICF1		5

#define TCNT1		*((volatile u16*)0X4C)

#define ICR1        *((volatile u16*)0x46)

#endif
