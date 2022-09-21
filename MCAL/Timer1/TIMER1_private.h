#ifndef TIMER1_PRIVATE_H
#define TIMER1_PRIVATE_H

/***************************************************Timer1 Registers macros****************************************************/
#define TCCR1A_REG      *((volatile u8 *)0x4F)
#define TCCR1B_REG      *((volatile u8 *)0x4E)
#define TCNT1_L_H_REG   *((volatile u16*)0x4C)
#define OCR1AL_REG      *((volatile u16*)0x4A)
#define OCR1BL_REG      *((volatile u16*)0x48)
#define ICR1L_REG       *((volatile u16*)0x46)
#define TIMSK_REG       *((volatile u8 *)0x59)
#define TIFR_REG        *((volatile u8 *)0x58)
/******************************************************************************************************************************/
/***************************************************Timer1 counter over flow value*********************************************/
#define TIMER1_OVER_FLOW_VALUE  65536
/******************************************************************************************************************************/

/***************************************************Bit number*****************************************************************/
#define TIMER1_OVERFLOW_FLAG_BIT_NUM          2  
#define TIMER1_OVERFLOW_INT_Enable_BIT_NUM    2
/******************************************************************************************************************************/




#endif //  TIMER1_PRIVATE_H