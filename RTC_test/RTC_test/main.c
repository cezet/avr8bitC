/*
 * RTC_test.c
 *
 * Created: 28/01/2015 21:06:29
 *  Author: czop.m
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdlib.h>
#include "HD44780.h"
#include "I2C.h"
#include "common.h"
#include "dhtxx.h"
#include "dhtxx_v2.h"

uint8_t dec2bcd(uint8_t);
uint8_t bufor[4];
volatile uint8_t seconds, minutes, hours;
char text_buffer[10];
uint8_t test = 0;

int8_t Rh1, Rh2, Th1, Th2;
uint16_t dht22_table[2] = {0};
	
int8_t integral_p, decimal_p;
int main(void)
{
	LCD_Initalize();
	LCD_Clear();
	LCD_WriteText("CZAS: ");
	
	
	
	
	//port pd5 - wyjscie
	DDRD |= (1<<PD5);
	
	//saleale trigger
	DDRB |= (1<<PB6);
	
	//port pd2 - int0 wejscie, podciagniete
	DDRD &= ~(1<<PD2);
	PORTD |= (1<<PD2);
	//ustawienia dla przerwania int0
	//MCUCR |= (1<<ISC01) | (1<<ISC00);
	//GICR |= (1<<INT0);
	
	
	TWI_init_baud();

	sei();
	
    while(1)
    {
        //TODO:: Please write your application code 
		//test++;
		PORTB |= (1<<PB6);
		
		TWI_read_buffer(0xA2, 0x02, 4, bufor);
		
		TWI_read_buffer(0xA2, 0x02, 4, bufor);
		
			PORTB &= ~(1<<PB6);
		seconds = bufor[0];
		minutes = bufor[1];
		hours = bufor[2];
		
		LCD_GoTo(7, 0);
		bcd_to_ascii(hours, text_buffer);
		LCD_WriteText(text_buffer);
		LCD_WriteText(":");
		bcd_to_ascii(minutes, text_buffer);
		LCD_WriteText(text_buffer);
		LCD_WriteText(":");
		
		//itoa(seconds, text_buffer, 10);
		bcd_to_ascii(seconds, text_buffer);
		LCD_WriteText(text_buffer);
		//LCD_GoTo(0,2);
		_delay_ms(3000);
		
		dhtxxV2_reset(2);
		dhtxxV2_check(2);
		dhtxxV2_message_read(dht22_table, 2);
		
		itoa(dhtxxV2_trunc(dht22_table), text_buffer, 10);
				
		
		
		
		LCD_GoTo(0,1);
		
		//itoa()
		
		bcd_to_ascii(Rh1, text_buffer);
		LCD_WriteText(text_buffer);
		
		LCD_WriteText(".");
		bcd_to_ascii(Rh2, text_buffer);
		LCD_WriteText(text_buffer);
		LCD_WriteText(" : ");
		bcd_to_ascii(Th1, text_buffer);
		LCD_WriteText(text_buffer);
		LCD_WriteText(".");
		bcd_to_ascii(Th2, text_buffer);
		LCD_WriteText(text_buffer);
		_delay_ms(500);
		
		
    }
	return 1;
}

uint8_t dec2bcd(uint8_t dec){
	return ((dec/10)<<4) | (dec % 10);
}
/*
ISR(INT0_vect){
	
	cli();
	PORTD ^= (1<<PD5);
	
	PORTB &= ~(1<<PB6);
	
	TWI_read_buffer(0xA2, 0x02, 3, bufor);
	
	PORTB |= (1<<PB6);
	
	
	seconds = bufor[0];
	minutes = bufor[1];
	hours = bufor[2];
	
	//itoa(seconds, text_buffer, 10);
	LCD_WriteText(seconds);
	
	
	sei();
	
	
}
*/