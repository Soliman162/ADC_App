#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SETBIT(REG,BITNO) (REG|=  (1<<BITNO))
#define CLRBIT(REG,BITNO) (REG&= ~(1<<BITNO))
#define TOGBIT(REG,BITNO) (REG ^= (1<<BITNO))
#define GETBIT(REG,BITNO) ((REG>>BITNO)&1)

#endif