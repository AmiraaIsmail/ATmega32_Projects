/**************************************************************************************/
/***********************************CLCD_config.h**************************************/
/**************************Created: 2/3/2024  11:00:00 AM******************************/
/********************************Author: Amira Ismail**********************************/
/**************************************************************************************/



#ifndef CLCD_CONFIG_H_
#define CLCD_CONFIG_H_


#define CLCD_PORT    	    DIO_PORTB
#define CLCD_CONTROL_PORT   DIO_PORTA

//#define CLCD_RW				DIO_PIN4
#define CLCD_RS             DIO_PIN3
#define CLCD_EN             DIO_PIN2


#define LCD_MODE		LCD_4BIT    //4bit
//#define LCD_MODE		LCD_8BIT    //8bits

#define	LCD_4BIT		1
#define	LCD_8BIT		0

#endif	/*CLCD_CONFIG_H_*/
