#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_

void CLCD_voidSendCommand(u8 CLCD_u8Command);

void CLCD_voidSendData(u8 CLCD_u8Data);

void CLCD_voidInit(void);

void CLCD_voidSendString(u8 *pvString);

void CLCD_voidSendAstrixString(u8 *Astrix);

void CLCD_voidSendNum(u32 NUM);

void CLCD_voidGotopos(u8 CLCD_x , u8 CLCD_y );

void CLCD_voidOpr(u8 plus_num);

void CLCD_voidWriteSpecialChar (u8 *pvPattern, u8 CLCD_u8BlockNum, u8 CLCD_u8x, u8 CLCD_u8y);

void CLCD_voidClear(void);

#endif




