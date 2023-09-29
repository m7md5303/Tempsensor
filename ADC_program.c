/*
 * ADC_program.c
 *
 *  Created on: 30 Aug 2023
 *      Author: ????
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC_register.h"
#include "ADC_private.h"
#include "ADC_interface.h"
#include "ADC_config.h"

void ADC_voidInit       (void){
	//Selection of VREF
#if(VREF==AREF)
	CLR_BIT(ADMUX , 6);
	CLR_BIT(ADMUX , 7);
#elif(VREF==AVCC)
	CLR_BIT(ADMUX , 7);
	SET_BIT(ADMUX , 6);
#elif(VREF==INTERNAL_VOLTAGE)
	SET_BIT(ADMUX , 6);
	SET_BIT(ADMUX , 7);
#endif
	//Set Normal Adjustment (Right / Left)
    CLR_BIT(ADMUX , 5);
    //use the normal enable signal
    CLR_BIT(ADCSRA ,  5);
    //if set auto-trigger will be used
    /**************************************/
    //	select the prescaler value
    //DIVIDE BY:
    /*
     000:divide by 2
     001:divide by 2
     010:divide by 4
     011:divide by 8
     100:divide by 16
     101:divide by 32
     110:divide by 64
     111:divide by 128
     */
    CLR_BIT(ADCSRA , 2);
    CLR_BIT(ADCSRA , 1);
    CLR_BIT(ADCSRA , 0);
    //Enabling the ADC
    SET_BIT(ADCSRA , 7);

}
u16  ADC_u16ReadChannel (u8 Copy_u8Channel){
//Select the channel
	ADMUX &=0b11100000;
	ADMUX|= Copy_u8Channel;
	//START THE CONVERSION
	SET_BIT(ADCSRA , 6);
	//POLLING ON ADC FLAG
	while((GET_BIT(ADCSRA , 4))!=1)
	{
		asm("NOP");
	}
	//CLEAR THE FLAG
	SET_BIT(ADCSRA , 4);
	return ADC;
}
