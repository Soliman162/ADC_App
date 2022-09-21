#include "std_types.h"

#include "DIO_interface.h"
#include "ADC_interface.h"
#include "TIMER1_interface.h"

#include "CLCD_interface.h"
#include "LM35_interface.h"

int main(void)
{
    u32 Temperature_u32 = 0;

    LM35_voidInit();
    CLCD_voidInit();

    while(1)
    {
        Temperature_u32 = LM35_u32Read_Temp();
        Clear_voidCLCD();
        CLCD_voidSetPosition(CLCD_ROW_1,CLCD_COL_1);
        CLCD_voidSend_String((u8 *)"Temperature:");
        CLCD_void_Send_Number(Temperature_u32);
        CLCD_voidSend_Data('C');
	    Timer1_voidDelay_Micro_Seconds(1000000);
    }

    return 0;
}