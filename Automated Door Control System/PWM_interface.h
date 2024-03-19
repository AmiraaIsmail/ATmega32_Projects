/**************************************************************************************/
/********************************PWM_interface.h***************************************/
/**************************Created: 17/3/2024  11:00:00 AM*****************************/
/********************************Author: Amira Ismail**********************************/
/**************************************************************************************/

#ifndef PWM_INTERFACE_H_
#define PWM_INTERFACE_H_



/*Options for PWM1A_PRESCALER
 * 1- PWM1A_PRESCALER_1
 * 2- PWM1A_PRESCALER_8
 * 3- PWM1A_PRESCALER_64
 * 4- PWM1A_PRESCALER_256
 * 5- PWM1A_PRESCALER_1024
 */
#define PWM1A_PRESCALER		PWM1A_PRESCALER_64


/*Options for PWM1A_PRESCALER
 * 1- PWM2_PRESCALER_1
 * 2- PWM2_PRESCALER_8
 * 3- PWM2_PRESCALER_64
 * 4- PWM2_PRESCALER_256
 * 5- PWM2_PRESCALER_1024
 */
#define PWM2_PRESCALER		PWM2_PRESCALER_64


/*****************************************TMR0*****************************************/
void PWM_voidInitChannel_0(void);
void PWM_voidGenerate_PWM_Channel_0(u8 copy_u8DutyCycle);
void PWM_voidStopChannel_0(void);


/*****************************************TMR1*****************************************/
void PWM_voidInitChannel_1A(void);
void PWM_voidGenerate_PWM_Channel_1A(u32 copy_u32Frequancey_hz ,f32 copy_f32DutyCycle);
void PWM_voidStopChannel_1A(void);


/*****************************************TMR2*****************************************/
void PWM_voidInitChannel_2(void);
void PWM_voidGenerate_PWM_Channel_2(u8 copy_u8DutyCycle);
void PWM_voidStopChannel_2(void);


#endif /*PWM_INTERFACE_H_*/
