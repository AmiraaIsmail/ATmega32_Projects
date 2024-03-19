/*
 * main.c
 *
 *  Created on: Mar 17, 2024
 *      Author: Amira
 */

/*
 * Using LED, Buzzer, LCD, Keypad and Servo Create Login system:

That ask user to enter the password comparing  it to predefined one
If compare match will open the door and print welcome message on screen
Else allow up to 3 trials after that security system will fire(LED and Buzzer)
 *
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "SERVO_interface.h"
#include "PROJECT_interface.h"
#include "util/delay.h"

void main (void)
{
	PROJECT_voidInit();
	PROJECT_voidStart();
	while(1)
	{

	}
}
