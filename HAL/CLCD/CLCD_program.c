#include "std_types.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "TIMER1_interface.h"

#include "CLCD_interface.h"
#include "CLCD_config.h"


void CLCD_voidInit(void){

	SetPort_enumDirection (CLCD_DATA_PORT , 255);
	SetPin_enumDirection  (CLCD_CONTROL_PORT ,CLCD_CONTROL_PIN_RW, DIO_OUTPUT);
	SetPin_enumDirection  (CLCD_CONTROL_PORT ,CLCD_CONTROL_PIN_RS, DIO_OUTPUT);
	SetPin_enumDirection  (CLCD_CONTROL_PORT ,CLCD_CONTROL_PIN_EN, DIO_OUTPUT);

	Timer1_voidDelay_Micro_Seconds(50000);
	//FUNCTION SET COMMEND
	CLCD_voidSendCommand(0b00111000);
	Timer1_voidDelay_Micro_Seconds(1000);
	//DISPLAY ON / OFF
	CLCD_voidSendCommand(0b00001110);
	Timer1_voidDelay_Micro_Seconds(1000);
	//DISPLAY CLEAR
	CLCD_voidSendCommand(0b00000001);
	Timer1_voidDelay_Micro_Seconds(3000);
	//DISPLAY ENTRY MODE
	CLCD_voidSendCommand(0b00000010);
	Timer1_voidDelay_Micro_Seconds(3000);

}
void CLCD_voidSend_Data(u8 Copy_u8Data){

	SetPort_enumValue     ( CLCD_DATA_PORT , Copy_u8Data);

	SetPin_enumValue     (CLCD_CONTROL_PORT , CLCD_CONTROL_PIN_RW , DIO_LOW );
	SetPin_enumValue     (CLCD_CONTROL_PORT , CLCD_CONTROL_PIN_RS , DIO_HIGH);

	SetPin_enumValue     (CLCD_CONTROL_PORT , CLCD_CONTROL_PIN_EN , DIO_HIGH);
	Timer1_voidDelay_Micro_Seconds(1000);
	SetPin_enumValue     (CLCD_CONTROL_PORT , CLCD_CONTROL_PIN_EN , DIO_LOW );
	Timer1_voidDelay_Micro_Seconds(1000);

}
void CLCD_voidSendCommand(u8 Copy_u8Command){

	SetPort_enumValue     ( CLCD_DATA_PORT , Copy_u8Command);

	SetPin_enumValue     (CLCD_CONTROL_PORT , CLCD_CONTROL_PIN_RW , DIO_LOW);
	SetPin_enumValue     (CLCD_CONTROL_PORT , CLCD_CONTROL_PIN_RS , DIO_LOW);

	SetPin_enumValue     (CLCD_CONTROL_PORT , CLCD_CONTROL_PIN_EN , DIO_HIGH);
	Timer1_voidDelay_Micro_Seconds(1000);
	SetPin_enumValue     (CLCD_CONTROL_PORT , CLCD_CONTROL_PIN_EN , DIO_LOW );
	Timer1_voidDelay_Micro_Seconds(1000);
}
void CLCD_voidSend_String(u8 *Copy_u8PtrString){

	u8 LOC_u8Iterator=0;
	while(Copy_u8PtrString[LOC_u8Iterator]!='\0'){

		CLCD_voidSend_Data(Copy_u8PtrString[LOC_u8Iterator]);
		LOC_u8Iterator++;
	}
}

void CLCD_void_Send_Number(u64 Copy_u64Number){

	u64 LOC_u64Reversed =1;
	if(Copy_u64Number==0){CLCD_voidSend_Data('0');}
	else{

		while(Copy_u64Number!=0){
			LOC_u64Reversed = (LOC_u64Reversed*10)+(Copy_u64Number%10);
			Copy_u64Number/=10;
		}
		while(LOC_u64Reversed!=1){
			CLCD_voidSend_Data((LOC_u64Reversed%10)+48);
			LOC_u64Reversed/=10;
		}
	}
}

void CLCD_voidSetPosition (u8 Copy_u8Row , u8 Copy_u8Col){

	if(Copy_u8Row==CLCD_ROW_1){

		CLCD_voidSendCommand((0x80)+(Copy_u8Col-1));

	}else if (Copy_u8Row==CLCD_ROW_2){

		CLCD_voidSendCommand((0x80)+64+(Copy_u8Col-1));

	}
}


void Send_voidExtraString   (u8 Copy_u8Row , u8 Copy_u8Col  ){

	//go to CGRAM
	CLCD_voidSendCommand(0b01000000);
	//Draw Char
	for(u8 i =0 ;i<(sizeof(Arr_u8ExtraChar)/sizeof(Arr_u8ExtraChar[0]));i++)
	{
		CLCD_voidSend_Data(Arr_u8ExtraChar[i]);
	}
	//Back to DDRAM
	CLCD_voidSetPosition (Copy_u8Row , Copy_u8Col);
	//Send Address
	for(u8 i =0 ;i<5;i++){
		CLCD_voidSend_Data(i);
	}
}

void Clear_voidCLCD(void){

	 CLCD_voidSendCommand(0b00000001);
	 Timer1_voidDelay_Micro_Seconds(1000);
}

void Display_voidOff_On(void){

	 CLCD_voidSendCommand(0b00001000);
	 Timer1_voidDelay_Micro_Seconds(1000);
}
