/**************************************************************************************/
/********************************CLCD_interface.h************************************/
/**************************Created: 2/3/2024  11:00:00 AM******************************/
/********************************Author: Amira Ismail**********************************/
/**************************************************************************************/

#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_
			
void CLCD_voidSendCommand (u8 CLCD_u8Command);			
void CLCD_voidSendData    (u8 CLCD_u8Data);	
void CLCD_voidInit        (void);		
void CLCD_voidGoToPosition(u8 CLCD_u8x, u8 CLCD_u8y);
void CLCD_voidSendString  (u8 *pvString);
void CLCD_voidSendNum     (u32 Num);
void CLCD_voidGoToPosition(u8 CLCD_uRow, u8 CLCD_u8Col);
void CLCD_voidWriteSpecialChar (u8 *pvPattern, u8 CLCD_u8BlockNum, u8 CLCD_u8x, u8 CLCD_u8y);
void CLCD_voidClear();








#endif  /*CLCD_INTERFACE_H_*/
