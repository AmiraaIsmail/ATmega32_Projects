/**************************************************************************************/
/********************************CLCD_program.c****************************************/
/**************************Created: 4/10/2023  10:00:00 PM*****************************/
/********************************Author: Amira Ismail**********************************/
/**************************************************************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "CLCD_config.h"
#include "util/delay.h"
u8 number;
void CLCD_voidSendCommand(u8 CLCD_u8Command)
{
	// SET RS => 0
	DIO_voidSetPinVal(CLCD_CNTL,DIO_PIN_VAL_LOW,DIO_PIN0);

	// SET RW => 0
	DIO_voidSetPinVal(CLCD_CNTL,DIO_PIN_VAL_LOW,DIO_PIN1);

	//SEND COMMAND
	DIO_voidSetPortVal(CLCD_DATA,CLCD_u8Command);

	// SET E => 1
	DIO_voidSetPinVal(CLCD_CNTL,DIO_PIN_VAL_HIGH,DIO_PIN2);
	_delay_ms(1);
	DIO_voidSetPinVal(CLCD_CNTL,DIO_PIN_VAL_LOW,DIO_PIN2);
}

void CLCD_voidSendData(u8 CLCD_u8Data)
{
	// SET RS => 0
		DIO_voidSetPinVal(CLCD_CNTL,DIO_PIN_VAL_HIGH,DIO_PIN0);

		// SET RW => 0
		DIO_voidSetPinVal(CLCD_CNTL,DIO_PIN_VAL_LOW,DIO_PIN1);

		//SEND COMMAND
		DIO_voidSetPortVal(CLCD_DATA,CLCD_u8Data);

		// SET E => 1
		DIO_voidSetPinVal(CLCD_CNTL,DIO_PIN_VAL_HIGH,DIO_PIN2);
		_delay_ms(1);
		DIO_voidSetPinVal(CLCD_CNTL,DIO_PIN_VAL_LOW,DIO_PIN2);


}

void CLCD_voidInit(void)
{
	DIO_voidSetPortDir(CLCD_DATA,DIO_PORT_OUT);
	DIO_voidSetPinDir(CLCD_CNTL,DIO_PIN_DIR_OUT,DIO_PIN0);
	DIO_voidSetPinDir(CLCD_CNTL,DIO_PIN_DIR_OUT,DIO_PIN1);
	DIO_voidSetPinDir(CLCD_CNTL,DIO_PIN_DIR_OUT,DIO_PIN2);
	_delay_ms(40);

	CLCD_voidSendCommand(0b00111000);
	_delay_ms(1);
	CLCD_voidSendCommand(0b00001100);
	_delay_ms(1);
	CLCD_voidSendCommand(0b00000001);
	_delay_ms(2);



}
void CLCD_voidSendString(u8 *pvString)
{
	u8 i;


	while (pvString[i] !='\0')
	{
		CLCD_voidSendData(pvString[i]);

		i++;
	}
}

void CLCD_voidGotopos(u8 CLCD_x , u8 CLCD_y ){
	u8 CLCD_pos;

	if (CLCD_x==0)
	{
		CLCD_pos=CLCD_y;
	}
	else if(CLCD_x==1)
	{
		CLCD_pos= CLCD_y + 0x40;

	}
	CLCD_voidSendCommand(CLCD_pos+128);

}
void CLCD_voidSendAstrix(u8 *Astrix)
{
	u8 x;

	while (Astrix[x] !='\0')
	{
		CLCD_voidSendData(Astrix[x]);
		_delay_ms(500);
		CLCD_voidGotopos(0,x);
		Astrix[x]='*';
		CLCD_voidSendData(Astrix[x]);
		x++;
	}
}
void CLCD_voidSendNum(u32 Num)
{
	u8 arr[10], i = 0, j = 0;
	if (Num == 0)
	{
		CLCD_voidSendData('0');
	}
	else
	{
		while(Num)
		{
			arr[i] = Num%10 + '0';
			Num/=10;
			i++;
		}
		for(j = i; j > 0; j--)
		{
			CLCD_voidSendData(arr[j-1]);
		}
	}
}
void CLCD_voidClear(void)
{
	CLCD_voidSendCommand(0b00000001);
}

void CLCD_voidWriteSpecialChar (u8 *pvPattern, u8 CLCD_u8BlockNum, u8 CLCD_u8x, u8 CLCD_u8y)
{
	u8 CLCD_u8CGRAMAddress = 0, i = 0;
	CLCD_u8CGRAMAddress = CLCD_u8BlockNum * 8;
	CLCD_voidSendCommand (CLCD_u8CGRAMAddress+64);
	for (i = 0; i < 8; i++)
	{
		CLCD_voidSendData(pvPattern[i]);
	}
	CLCD_voidGotopos(CLCD_u8x, CLCD_u8y);
	CLCD_voidSendData(pvPattern);
}

















/*void CLCD_SPICEAL(u8 *CLCD_PATERN , u8 *CLCD_BLOCK_NUM , u8 CLCD_X , u8 CLCD_Y )
{
	u8 CGRAM_ADR=0 , ITERAOR=0;
	CGRAM_ADR=CGRAM_ADR*8;
	CLCD_voidSendCommand(CGRAM_ADR+64);
	FOR (ITERAOR=0;ITERAOR<8;ITERAOR++){
		CLCD_voidSendData(CLCD_PATERN[ITERAOR]);
	}
	CLCD_voidGotopos(CLCD_X,CLCD_Y);
	CLCD_voidSendData(CLCD_PATERN);






}*/
