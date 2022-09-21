#include "std_types.h"
#include "DIO_interface.h"
#include "ADC_interface.h"

#include "LDR_interface.h"
#include "LDR_private.h"
#include "LDR_config.h"

void LDR_voidInit(void)
{
    SetPin_enumDirection(PORTA,LDR_PIN,DIO_INPUT);
    ADC_voidInit();
}
u32 LDR_u32Read_Light_Indensty(void)
{
    u32 Light_u32Resault = 0;
    ADC_voidSelect_SingleEnded_Channel(LDR_PIN);
    ADC_voidStart_Conversion();
    Light_u32Resault = ADC_u16GET_Conversion_Data();
    return Light_u32Resault;
}