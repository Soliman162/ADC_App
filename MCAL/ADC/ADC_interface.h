#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

typedef enum{

    ADC_CHANNEL_0=PIN0,
    ADC_CHANNEL_1=PIN1,
    ADC_CHANNEL_2=PIN2,
    ADC_CHANNEL_3=PIN3,
    ADC_CHANNEL_4=PIN4,
    ADC_CHANNEL_5=PIN5,
    ADC_CHANNEL_6=PIN6,
    ADC_CHANNEL_7=PIN7

}ADC_SinglEnded_Channels;

typedef enum{

    ADC_Channel_0_0_x10=8,
    ADC_Channel_1_0_x10,

    ADC_Channel_0_0_x200,
    ADC_Channel_1_0_x200,

    ADC_Channel_2_2_x10,
    ADC_Channel_3_2_x10,

    ADC_Channel_2_2_x200,
    ADC_Channel_3_2_x200,

    ADC_Cahnnel_0_1_x1,
    ADC_Cahnnel_1_1_x1,
    ADC_Cahnnel_2_1_x1,
    ADC_Cahnnel_3_1_x1,
    ADC_Cahnnel_4_1_x1,
    ADC_Cahnnel_5_1_x1,
    ADC_Cahnnel_6_1_x1,
    ADC_Cahnnel_7_1_x1,

    ADC_Cahnnel_0_2_x1,
    ADC_Cahnnel_1_2_x1,
    ADC_Cahnnel_2_2_x1,
    ADC_Cahnnel_3_2_x1,
    ADC_Cahnnel_4_2_x1

}ADC_Differential_Channels;

typedef enum{

    ADC_Free_Running=0,
    ADC_Analog_Comparator,
    External_Interrupt_Request,
    Timer_Counter0_Compare_Match,
    Timer_Counter0_Overflow,
    Timer_Counter_Compare_Match_B,
    Timer_Counter1_Overflow,
    Timer_Counter1_Capture_Event

}ADC_Trigger_Source;


void ADC_voidInit(void);
void ADC_voidStart_Conversion(void);
u16  ADC_u16GET_Conversion_Data(void);
void ADC_voidSelect_SingleEnded_Channel(ADC_SinglEnded_Channels Copy_enumChannel);
void ADC_voidSelect_Differential_Channel(ADC_Differential_Channels Copy_enumChannel);
void ADC_voidEnable_Auto_Trigger(void);
void ADC_voidSET_Trigger_Source(ADC_Trigger_Source Copy_enumSource);



#endif