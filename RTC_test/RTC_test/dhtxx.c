/*
 * dhtxx.c
 *
 * Created: 27/01/2015 13:52:26
 *  Author: czop.m
 */ 
#include <avr/io.h>
#include <util/delay.h>


#include "dhtxx.h"


void dhtxx_reset(void){
	
	DHTxx_DIR |= DHTxx_LINE;
	DHTxx_PORT &= ~DHTxx_LINE;
	
	_delay_ms(20);
	
	DHTxx_DIR &= ~DHTxx_LINE;
	_delay_us(5);
	
}

void dhtxx_check(void)
{
	while (DHTxx_LINE_HI)
	{
	}
	while (DHTxx_LINE_LO)
	{
	}
	while (DHTxx_LINE_HI)
	{
	}
	
}

uint8_t dhtx_byte_read(void){
	
	uint8_t byte_data = 0;
	
	
	
	for (uint8_t i = 0; i < 8; i++)
	{
		while (DHTxx_LINE_HI)
		{
		}
		_delay_us(35);
		
		if (DHTxx_LINE_HI)
		{
			byte_data |= 1;
			byte_data = byte_data << 1;
		}
		else byte_data = byte_data << 1;
	}
	
	return byte_data;
	
}

void dhtxx_message_read(uint8_t *table){
	for (int i = 0; i < 5 ; i++)
	{
		*table++ = dhtx_byte_read();
		//*table++;
	}
	
} 