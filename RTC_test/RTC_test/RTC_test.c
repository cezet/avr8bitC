/*
 * RTC_test.c
 *
 * Created: 28/01/2015 21:06:29
 *  Author: czop.m
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>
#include "HD44780.h"
#include "I2C.h"
#include "common.h"

uint8_t dec2bcd(uint8_t);
uint8_t bufor[4];
volatile uint8_t seconds, minutes, hours;
char text_buffer[10];
uint8_t test = 0;

int main(void)
{
	LCD_Initalize();
	LCD_Clear();
	LCD_WriteText("TEST INIT TEST");
	
	LCD_GoTo(0, 1);
	
	
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
	
	
	
	/*
	bufor[0] = 0;
	bufor[1] = dec2bcd(27);
	bufor[2] = dec2bcd(34);
	bufor[3] = dec2bcd(18);
	
	TWI_write_buffer(0xA2, 0x01, 4, bufor);
	*/
	
	
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
		
		bcd_to_ascii(hours, text_buffer);
		LCD_WriteText(text_buffer);
		LCD_WriteText(":");
		bcd_to_ascii(minutes, text_buffer);
		LCD_WriteText(text_buffer);
		LCD_WriteText(":");
		
		//itoa(seconds, text_buffer, 10);
		bcd_to_ascii(seconds, text_buffer);
		LCD_WriteText(text_buffer);
		LCD_GoTo(0,2);
		test = 57;
		bcd_to_ascii((char)test, text_buffer);
		LCD_WriteText(text_buffer);
		
		
		LCD_GoTo(0,1);
		_delay_ms(1000);
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