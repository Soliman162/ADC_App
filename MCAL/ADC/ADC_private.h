#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

#define Division_Factor_2       0b001
#define Division_Factor_4       0b010
#define Division_Factor_8       0b011
#define Division_Factor_16      0b100
#define Division_Factor_32      0b101
#define Division_Factor_64      0b110
#define Division_Factor_128     0b111


#define ADMUX_REG   *((volatile u8 *)0x27)
#define ADCSRA_REG  *((volatile u8 *)0x26)
#define ADCH_REG    *((volatile u8 *)0x25)
#define ADCL_REG    *((volatile u8 *)0x24)
#define SFIOR_REG   *((volatile u8 *)0x50)



#endif