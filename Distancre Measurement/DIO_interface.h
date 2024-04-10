/**************************************************************************************/
/********************************DIO_interface.h***************************************/
/**************************Created: 4/10/2023  1:00:00 PM******************************/
/********************************Author: Amira Ismail**********************************/
/**************************************************************************************/


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_


#include "STD_TYPES.h"
#include "DIO_register.h"
#include "DIO_private.h"

void DIO_voidSetPortDir(u8 DIO_u8Port ,u8 DIO_u8Dir);
void DIO_voidSetPortVal(u8 DIO_u8Port ,u8 DIO_u8Val);

void DIO_voidSetPinDir(u8 DIO_u8Port ,u8 DIO_u8Dir,u8 DIO_u8Pin);
void DIO_voidSetPinVal(u8 DIO_u8Port ,u8 DIO_u8Val,u8 DIO_u8Pin);

u8 DIO_u8GetPinVal(u8 DIO_u8Port,u8 DIO_u8Pin);

#define DIO_PORT_OUT     0XFF
#define DIO_PORT_IN      0X00

#define DIO_PORT_HIGH     0XFF
#define DIO_PORT_LOW      0X00

#define DIO_PIN0   0
#define DIO_PIN1   1
#define DIO_PIN2   2
#define DIO_PIN3   3
#define DIO_PIN4   4
#define DIO_PIN5   5
#define DIO_PIN6   6
#define DIO_PIN7   7


#define DIO_PIN_VAL_HIGH     1
#define DIO_PIN_VAL_LOW      0

#define DIO_PIN_DIR_OUT     1
#define DIO_PIN_DIR_IN        0

#define DIO_PORTA     0
#define DIO_PORTB     1
#define DIO_PORTC     2
#define DIO_PORTD     3





#endif
