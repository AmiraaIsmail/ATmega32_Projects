/**************************************************************************************/
/********************************  KEYPAD_config.c ***********************************/
/**************************Created: 3/3/2024  10:30:00 PM******************************/
/********************************Author: Amira Ismail**********************************/
/**************************************************************************************/


#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_


#define   NOTKEY     'T'
#define   KEYPAD_COLUMN_PORT     DIO_PORTD
#define   KEYPAD_ROW_PORT        DIO_PORTC

#define   FIRSTCOLUMN           DIO_PIN3
#define   FIRSTROW              DIO_PIN2

#define   KEYPAD_COLUMN0     DIO_PIN7
#define   KEYPAD_COLUMN1     DIO_PIN6
#define   KEYPAD_COLUMN2     DIO_PIN4
#define   KEYPAD_COLUMN3     DIO_PIN3

#define   KEYPAD_ROW0        DIO_PIN5
#define   KEYPAD_ROW1        DIO_PIN4
#define   KEYPAD_ROW2        DIO_PIN3
#define   KEYPAD_ROW3        DIO_PIN2


#endif		/*KEYPAD_CONFIG_H_*/

