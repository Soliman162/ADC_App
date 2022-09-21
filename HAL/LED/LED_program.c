#include "std_types.h"

#include "DIO_interface.h"

#include "LED_interface.h"


void LED_voidInit(LED_config *Copy_ptrLED)
{
    SetPin_enumDirection(Copy_ptrLED->LED_u8PORT,Copy_ptrLED->LED_u8PIN,DIO_OUTPUT);
    if( Copy_ptrLED->Active_State == STATE_HIGH )
    {
        SetPin_enumValue(Copy_ptrLED->LED_u8PORT,Copy_ptrLED->LED_u8PIN,DIO_LOW);

    }else if( Copy_ptrLED->Active_State == STATE_LOW )
    {
        SetPin_enumValue(Copy_ptrLED->LED_u8PORT,Copy_ptrLED->LED_u8PIN,DIO_HIGH);
    }
}
void LED_voidON(LED_config *Copy_ptrLED)
{
    if( Copy_ptrLED->Active_State == STATE_HIGH )
    {
        SetPin_enumValue(Copy_ptrLED->LED_u8PORT,Copy_ptrLED->LED_u8PIN,DIO_HIGH);

    }else if( Copy_ptrLED->Active_State == STATE_LOW )
    {
        SetPin_enumValue(Copy_ptrLED->LED_u8PORT,Copy_ptrLED->LED_u8PIN,DIO_LOW);
    }
}
void LED_voidOFF(LED_config *Copy_ptrLED)
{
    if( Copy_ptrLED->Active_State == STATE_HIGH )
    {
        SetPin_enumValue(Copy_ptrLED->LED_u8PORT,Copy_ptrLED->LED_u8PIN,DIO_LOW);

    }else if( Copy_ptrLED->Active_State == STATE_LOW )
    {
        SetPin_enumValue(Copy_ptrLED->LED_u8PORT,Copy_ptrLED->LED_u8PIN,DIO_HIGH);
    }
}