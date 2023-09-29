/*
 * main.c
 *
 *  Created on: 3 Sep 2023
 *      Author: ????
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "ADC_interface.h"
#include "CLCD_interface.h"
#include <util/delay.h>
int main(void){
	DIO_VoidSetPortDirection(DIO_u8PORTC,DIO_u8PORTHIGH);
	DIO_VoidSetPortDirection(DIO_u8PORTD,0b00001111);
	DIO_voidSetPinDirection(DIO_u8PORTA , 0 , DIO_u8INPUT);
	CLCD_voidInit();
	ADC_voidInit();
	while(1){
	u16 read_temp=0;
	read_temp=ADC_u16ReadChannel(0);
	read_temp=(read_temp*500)/1023;
	if(read_temp>40){
		DIO_voidSetPinValue(DIO_u8PORTD, 3 , DIO_u8HIGH);
	}
	else {
		DIO_voidSetPinValue(DIO_u8PORTD, 3 , DIO_u8LOW);
	}
	CLCD_voidPrintMultiDigit(read_temp);
	_delay_ms(5000);
	CLCD_voidClearDisplay();

}}

