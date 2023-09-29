/*
 * ADC_register.h
 *
 *  Created on: 30 Aug 2023
 *      Author: ????
 */

#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_

#define ADMUX         *((volatile u8 *)(0x27))
#define ADCSRA        *((volatile u8 *)(0x26))
#define ADC           *((volatile u16*)(0x24))
#define SFIOR         *((volatile u8 *)(0x50))
#endif /* ADC_REGISTER_H_ */
