#include "std_types.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"

#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"


void ADC_voidInit(void)
{
    /*Enable ADC*/
    ADCSRA_REG |= (1<<7);
    /*choose the highst prescaller*/
    ADCSRA_REG |= Division_Factor;
    /*choose Vref*/
    ADMUX_REG |= (0b11)<<7;
    /*choose Channel*/
    ADMUX_REG |=0;
    /*Choose Adjustment*/
    ADMUX_REG &= ~(1<<5);
}

void ADC_voidStart_Conversion(void)
{
    ADCSRA_REG |= (1<<6);
}
u16  ADC_u16GET_Conversion_Data(void)
{
    u16 ADC_u16Conversion_Resault = 0;
    while(GETBIT(ADCSRA_REG,4) !=1);
    ADC_u16Conversion_Resault = ( ADCL_REG | (ADCH_REG<<8) );
    ADCSRA_REG |= (1<<4);
    return  ADC_u16Conversion_Resault;
}

void ADC_voidSelect_SingleEnded_Channel(ADC_SinglEnded_Channels Copy_enumChannel)
{
    ADMUX_REG &= ~(0b11111);
    ADMUX_REG |= Copy_enumChannel;
}

void ADC_voidSelect_Differential_Channel(ADC_Differential_Channels Copy_enumChannel)
{
    ADMUX_REG &= ~(0b11111);
    ADMUX_REG |= Copy_enumChannel;
}

void ADC_voidEnable_Auto_Trigger(void)
{
    ADCSRA_REG |= (1<<5);
}
void ADC_voidSET_Trigger_Source(ADC_Trigger_Source Copy_enumSource)
{
    SFIOR_REG &= ~(0b111<<5);
    SFIOR_REG |= (Copy_enumSource<<5);
}

