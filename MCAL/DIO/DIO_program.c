#include "std_types.h"
#include "BIT_MATH.h"


#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"


ERROR_enumSTATE SetPort_enumDirection (u8 Copy_u8Port , u8 Copy_u8Direction){

	ERROR_enumSTATE LOCerror_enumState =DIO_OK;

	if( (Copy_u8Port<=PORTD) && (Copy_u8Port>=PORTA) ){

		switch (Copy_u8Port){

		case(PORTA):if((Copy_u8Direction<=255) && (Copy_u8Direction>=0)){DDRA_REG=Copy_u8Direction;} break;
		case(PORTB):if((Copy_u8Direction<=255) && (Copy_u8Direction>=0)){DDRB_REG=Copy_u8Direction;} break;
		case(PORTC):if((Copy_u8Direction<=255) && (Copy_u8Direction>=0)){DDRC_REG=Copy_u8Direction;} break;
		case(PORTD):if((Copy_u8Direction<=255) && (Copy_u8Direction>=0)){DDRD_REG=Copy_u8Direction;} break;

		default	   : LOCerror_enumState =DIO_NOK; 	break;
		}
	}else{LOCerror_enumState =DIO_NOK;}

	return LOCerror_enumState;
}

////////////////////////////////////////////////////////////////////////////
ERROR_enumSTATE SetPort_enumValue     (u8 Copy_u8Port , u8 Copy_u8Value){

	ERROR_enumSTATE LOCerror_enumState =DIO_OK;

	if( (Copy_u8Port<=PORTD) && (Copy_u8Port>=PORTA) ){

		switch (Copy_u8Port){

		case(PORTA):if((Copy_u8Value<=255) && (Copy_u8Value>=0)){PORTA_REG=Copy_u8Value;} break;
		case(PORTB):if((Copy_u8Value<=255) && (Copy_u8Value>=0)){PORTB_REG=Copy_u8Value;} break;
		case(PORTC):if((Copy_u8Value<=255) && (Copy_u8Value>=0)){PORTC_REG=Copy_u8Value;} break;
		case(PORTD):if((Copy_u8Value<=255) && (Copy_u8Value>=0)){PORTD_REG=Copy_u8Value;} break;

		default	   : LOCerror_enumState =DIO_NOK; 	break;
		}
	}else{LOCerror_enumState =DIO_NOK;}

	return LOCerror_enumState;

}

///////////////////////////////////////////////////////////////////////////////////
ERROR_enumSTATE SetPin_enumDirection (u8 Copy_u8Port ,u8 Copy_u8Pin , u8 Copy_u8Direction){

	ERROR_enumSTATE LOCerror_enumState =DIO_OK;

	if( (Copy_u8Port<=PORTD) && (Copy_u8Port>=PORTA) ){

		switch (Copy_u8Port){

				case(PORTA):

								if     (Copy_u8Direction==DIO_OUTPUT){SETBIT(DDRA_REG,Copy_u8Pin);}
								else if(Copy_u8Direction==DIO_INPUT) {CLRBIT(DDRA_REG,Copy_u8Pin);}
								else{LOCerror_enumState =DIO_NOK;}

								break;

				case(PORTB):
								if     (Copy_u8Direction==DIO_OUTPUT){SETBIT(DDRB_REG,Copy_u8Pin);}
								else if(Copy_u8Direction==DIO_INPUT) {CLRBIT(DDRB_REG,Copy_u8Pin);}
								else{LOCerror_enumState =DIO_NOK;}

								break;
				case(PORTC):
								if     (Copy_u8Direction==DIO_OUTPUT){SETBIT(DDRC_REG,Copy_u8Pin);}
								else if(Copy_u8Direction==DIO_INPUT) {CLRBIT(DDRC_REG,Copy_u8Pin);}
								else{LOCerror_enumState =DIO_NOK;}

								break;
				case(PORTD):
								if     (Copy_u8Direction==DIO_OUTPUT){SETBIT(DDRD_REG,Copy_u8Pin);}
								else if(Copy_u8Direction==DIO_INPUT) {CLRBIT(DDRD_REG,Copy_u8Pin);}
								else{LOCerror_enumState =DIO_NOK;}

								break;

				default	   : LOCerror_enumState =DIO_NOK; 	break;
		}
	}else{LOCerror_enumState =DIO_NOK;}

	return LOCerror_enumState;

}

///////////////////////////////////////////////////////////////////////////////////////
ERROR_enumSTATE SetPin_enumValue     (u8 Copy_u8Port ,u8 Copy_u8Pin , u8 Copy_u8Value){

	ERROR_enumSTATE LOCerror_enumState =DIO_OK;

		if( (Copy_u8Port<=PORTD) && (Copy_u8Port>=PORTA) ){
			if(Copy_u8Pin>=PIN0 && Copy_u8Pin<=PIN7 ){
				switch (Copy_u8Port){

						case(PORTA):

										if     ( Copy_u8Value==DIO_HIGH){SETBIT (PORTA_REG,Copy_u8Pin);}
										else if( Copy_u8Value==DIO_LOW ){CLRBIT (PORTA_REG,Copy_u8Pin);}
										else	{LOCerror_enumState =DIO_NOK;}

										break;

						case(PORTB):
										if     ( Copy_u8Value==DIO_HIGH){SETBIT (PORTB_REG,Copy_u8Pin);}
										else if( Copy_u8Value==DIO_LOW ){CLRBIT (PORTB_REG,Copy_u8Pin);}
										else   {LOCerror_enumState =DIO_NOK;}

										break;
						case(PORTC):
										if	   ( Copy_u8Value==DIO_HIGH){SETBIT (PORTC_REG,Copy_u8Pin);}
										else if( Copy_u8Value==DIO_LOW ){CLRBIT (PORTC_REG,Copy_u8Pin);}
										else   {LOCerror_enumState =DIO_NOK;}

										break;
						case(PORTD):
										if     ( Copy_u8Value==DIO_HIGH){SETBIT (PORTD_REG,Copy_u8Pin);}
										else if( Copy_u8Value==DIO_LOW ){CLRBIT (PORTD_REG,Copy_u8Pin);}
										else   {LOCerror_enumState =DIO_NOK;}
										break;

						default	   :   LOCerror_enumState =DIO_NOK; 	break;
				}
			}else{LOCerror_enumState =DIO_NOK;}
		}else{LOCerror_enumState =DIO_NOK;}

		return LOCerror_enumState;
}

////////////////////////////////////////////////////////////////
ERROR_enumSTATE GetPort_u8Value     (u8 Copy_u8Port,u8 *COPY_u8ptrDATA ){

	ERROR_enumSTATE LOCerror_enumState =DIO_OK;

	if( (Copy_u8Port<=PORTD) && (Copy_u8Port>=PORTA) ){

		switch (Copy_u8Port){

			case(PORTA): *COPY_u8ptrDATA=PINA_REG; break;
			case(PORTB): *COPY_u8ptrDATA=PINB_REG; break;
			case(PORTC): *COPY_u8ptrDATA=PINC_REG; break;
			case(PORTD): *COPY_u8ptrDATA=PIND_REG; break;

			default	   : LOCerror_enumState =DIO_NOK; 	break;
		}
	}else{LOCerror_enumState =DIO_NOK;}

	return LOCerror_enumState;
}
//////////////////////////////////////////////////////////////////////////

ERROR_enumSTATE GetPin_enumValue     (u8 Copy_u8Port, u8 Copy_u8Pin, u8 *COPY_u8ptrDATA ){

	ERROR_enumSTATE LOCerror_enumState =DIO_OK;

		if( (Copy_u8Port<=PORTD) && (Copy_u8Port>=PORTA) ){
			if(Copy_u8Pin>=PIN0 && Copy_u8Pin<=PIN7 ){
				switch (Copy_u8Port){

					case(PORTA): *COPY_u8ptrDATA=GETBIT(PINA_REG,Copy_u8Pin); break;
					case(PORTB): *COPY_u8ptrDATA=GETBIT(PINB_REG,Copy_u8Pin); break;
					case(PORTC): *COPY_u8ptrDATA=GETBIT(PINC_REG,Copy_u8Pin); break;
					case(PORTD): *COPY_u8ptrDATA=GETBIT(PIND_REG,Copy_u8Pin); break;

					default	   : LOCerror_enumState =DIO_NOK; 	break;
				}
			}else{LOCerror_enumState =DIO_NOK;}

		}else{LOCerror_enumState =DIO_NOK;}

		return LOCerror_enumState;
}
