#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

typedef enum{

    STATE_LOW=0,
    STATE_HIGH

}LED_ACTIVE_STATE;

typedef struct{

    u8 LED_u8PORT;
    u8 LED_u8PIN;
    LED_ACTIVE_STATE Active_State;

}LED_config;

void LED_voidInit(LED_config *Copy_ptrLED);
void LED_voidON(LED_config *Copy_ptrLED);
void LED_voidOFF(LED_config *Copy_ptrLED);



#endif