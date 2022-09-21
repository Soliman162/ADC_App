/*
 * DIO_interface.h
 *
 *  Created on: Mar 7, 2021
 *      Author: DELL
 */

#ifndef MCAL_01_DIO_DIO_INTERFACE_H_
#define MCAL_01_DIO_DIO_INTERFACE_H_

typedef enum{

	DIO_NOK,
	DIO_OK

}ERROR_enumSTATE;

#define DIO_INPUT  0
#define DIO_OUTPUT 1

#define DIO_LOW  0
#define DIO_HIGH 1

#define PORTA  0
#define PORTB  1
#define PORTC   2
#define PORTD  3

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

ERROR_enumSTATE SetPort_enumDirection (u8 Copy_u8Port , u8 Copy_u8Direction);
ERROR_enumSTATE SetPort_enumValue     (u8 Copy_u8Port , u8 Copy_u8Value);

ERROR_enumSTATE SetPin_enumDirection  (u8 Copy_u8Port ,u8 Copy_u8Pin , u8 Copy_u8Direction);
ERROR_enumSTATE SetPin_enumValue      (u8 Copy_u8Port ,u8 Copy_u8Pin , u8 Copy_u8Value);

ERROR_enumSTATE GetPort_enumValue     (u8 Copy_u8Port,u8 *COPY_u8ptrDATA );
ERROR_enumSTATE GetPin_enumValue      (u8 Copy_u8Port, u8 Copy_u8Pin,u8 *COPY_u8ptrDATA );


#endif /* MCAL_01_DIO_DIO_INTERFACE_H_ */
