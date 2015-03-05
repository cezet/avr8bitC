/*
 * dhtxx_v2.h
 *
 * Created: 03/03/2015 16:03:13
 *  Author: czop.m
 */ 


#ifndef DHTXX_V2_H_
#define DHTXX_V2_H_

#define DHTxxV2_PORT PORTA
#define DHTxxV2_PIN PINA
#define DHTxxV2_DIR DDRA

extern uint8_t sensor_id;

void dhtxxV2_reset(uint8_t sensor_id);
void dhtxxV2_check(uint8_t sensor_id);
uint8_t dhtxxV2_byte_read(uint8_t sensor_id);
void dhtxxV2_message_read(uint8_t *table, uint8_t sensor_id);
void dhtxxV2_convert2int16(uint16_t *table);
int8_t dhtxxV2_trunc(uint16_t *table);


#endif /* DHTXX_V2_H_ */