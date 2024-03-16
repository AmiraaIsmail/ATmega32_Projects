/**************************************************************************************/
/********************************ADC_register.h************************************/
/**************************Created: 4/3/2024  1:00:00 PM******************************/
/********************************Author: Amira Ismail**********************************/
/**************************************************************************************/

#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_

#define  ADMUX_REG           (*(volatile u8*)0X27)
#define  REFS1			7
#define  REFS0			6
#define  ADLAR			5
#define  MUX4			4
#define  MUX3			3
#define  MUX2			2
#define  MUX1			1
#define  MUX0			0

#define  ADCSRA_REG          (*(volatile u8*)0X26)
#define  ADEN			7
#define  ADSC			6
#define  ADATE			5
#define  ADIF			4
#define  ADIE			3
#define  ADPS2			2
#define  ADPS1			1
#define  ADPS0			0

#define  ADCH_REG            (*(volatile u8*)0X25)

#define  ADC_u16_REG         (*(volatile u16*)0X24)

#define  SFIOR_REG           (*(volatile u8*)0X50)
#define  ADTS2			7
#define  ADTS1			6	
#define  ADTS0			5



#endif		/*ADC_REGISTER_H_*/
