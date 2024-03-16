/**************************************************************************************/
/********************************ADC_interface.h************************************/
/**************************Created: 4/3/2024  1:00:00 PM******************************/
/********************************Author: Amira Ismail**********************************/
/**************************************************************************************/

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_


#define ADC_CHANNEL0	0
#define ADC_CHANNEL1	1
#define ADC_CHANNEL2	2
#define ADC_CHANNEL3	3
#define ADC_CHANNEL4	4
#define ADC_CHANNEL5	5
#define ADC_CHANNEL6	6
#define ADC_CHANNEL7	7


#define ADC_REFERENCE_AVCC			1
#define ADC_REFERENCE_AREF			2
#define ADC_REFERENCE_INTERNAL		3


void ADC_voidInit(u8 copy_u8ReferenceVoltage);
void ADC_u8ReadDigitalValue(u8 copy_u8ChannelNumber, u16* copy_pu16DigitalValue);


#endif		/*ADC_INTERFACE_H_*/
