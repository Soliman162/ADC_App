#include "std_types.h"
#include "BIT_MATH.h"

#include "TIMER1_interface.h"
#include "TIMER1_private.h"
#include "TIMER1_config.h"


void Timer1_voidInit(void)
{
    TCCR1A_REG = 0b00000000;
    TCCR1B_REG = 0b00000010;
}

void Timer1_voidDelay_Micro_Seconds(u32 Copy_u32Delay_micro_Seconds)
{
    while (Copy_u32Delay_micro_Seconds > TIMER1_OVER_FLOW_VALUE)
    {
        TCNT1_L_H_REG = 0;
        /*check over flow*/
        while( GETBIT(TIFR_REG,TIMER1_OVERFLOW_FLAG_BIT_NUM) == 0 );
        /*Clear flag*/
        SETBIT(TIFR_REG,TIMER1_OVERFLOW_FLAG_BIT_NUM);
        Copy_u32Delay_micro_Seconds -= TIMER1_OVER_FLOW_VALUE;
    }

    if( Copy_u32Delay_micro_Seconds < TIMER1_OVER_FLOW_VALUE )
    {
        TCNT1_L_H_REG = TIMER1_OVER_FLOW_VALUE - Copy_u32Delay_micro_Seconds;
    }else if( Copy_u32Delay_micro_Seconds == TIMER1_OVER_FLOW_VALUE)
    {
        TCNT1_L_H_REG = 0;
    }
    /*check over flow*/
    while( GETBIT(TIFR_REG,TIMER1_OVERFLOW_FLAG_BIT_NUM) == 0 );
    /*Clear flag*/
    SETBIT(TIFR_REG,TIMER1_OVERFLOW_FLAG_BIT_NUM);
}

