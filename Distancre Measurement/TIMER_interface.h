/**************************************************************************************/
/********************************TIMER_interface.h***************************************/
/**************************Created: 3/10/2023  6:00:00 PM******************************/
/********************************Author: Amira Ismail**********************************/
/**************************************************************************************/

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

#define ICU_RISING_EDGE    1
#define ICU_FALLING_EDGE   0

void TIMER0_voidInit(void);

u8 TIMER0_u8CallBack(void(*Copy_pvCallBack)(void));

void TIMER1_voidInit(void);

void TIMER1_voidSetTimer1Val(u16 TIMER1_u16Val);

u16 TIMER1_u16ReadTimerVal(void);

u8 TIMER1_u8OVFCallBack(void(*copy_pvcallbackfunc)(void));

u8 ICU_u8SetEdge(u8 Copy_u8Edge);

void ICU_voidInit(void);

u16 ICU_u16ReadInputcapture(void);

void ICU_voidDisableInterrupt(void);

void ICU_voidEnableInterrupt(void);

u8 ICU_u8SetCallback(void(*copy_pvcallbackfunc)(void));

void TIMER1_voidReset (void);

void TIMER1_voidOVFIntEnable(void);


#endif
