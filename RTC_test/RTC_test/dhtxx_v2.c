/*
 * dhtxx_v2.c
 *
 * Created: 03/03/2015 16:02:54
 *  Author: czop.m
 */ 
#include <avr/io.h>
#include <util/delay.h>
#include "dhtxx_v2.h"


void dhtxxV2_reset(uint8_t sensor_id){
	
	DHTxxV2_DIR |= (1 << sensor_id);
	DHTxxV2_PORT &= ~(1 << sensor_id);
	
	_delay_ms(20);
	
	DHTxxV2_DIR &= ~(1 << sensor_id);
	_delay_us(5);
	
}

void dhtxxV2_check(uint8_t sensor_id)
{
	while (DHTxxV2_PIN & (1<<sensor_id))
	{
	}
	while (!(DHTxxV2_PIN & (1<<sensor_id)))
	{
	}
	while (DHTxxV2_PIN & (1<<sensor_id))
	{
	}
	
}

uint8_t dhtxxV2_byte_read(uint8_t sensor_id){
	
	uint8_t byte_data = 0;
		
	for (uint8_t i = 0; i < 8; i++)
	{
		while (DHTxxV2_PIN & (1<<sensor_id))
		{
		}
		_delay_us(35);
		
		if (DHTxxV2_PIN & (1<<sensor_id))
		{
			byte_data |= 1;
			byte_data = byte_data << 1;
		}
		else byte_data = byte_data << 1;
	}
	
	return byte_data;
	
}

void dhtxxV2_message_read(uint8_t *table, uint8_t sensor_id){
	
	table += 4;
	for (int byte = 4; byte > 0; byte--)
	{
		*table-- = dhtxxV2_byte_read(sensor_id);
	}
	/*
	*table = table;
	for (int byte = 0; byte < 4 ; byte++)
	{
		*table++ = dhtxxV2_byte_read(sensor_id); 
	}
	*/
	
}

void dhtxxV2_convert2int16(uint16_t *table){
	if (*table & 0x8000)
	{
		*table &= ~0x8000;
		*table = ~(*table);
		*table = *table + 1;
	}
}
int8_t dhtxxV2_trunc(uint16_t *table){
	
	return (int8_t) *table / 10;
}