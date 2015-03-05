/*
 * dhtxx.h
 *
 * Created: 27/01/2015 13:52:39
 *  Author: czop.m
 */ 


#ifndef DHTXX_H_
#define DHTXX_H_

#define DHTxx_PORT PORTA
#define DHTxx_PIN PINA
#define DHTxx_DIR DDRA
#define DHTxx_LINE (1<<PA2)

#define DHTxx_LINE_LO !(DHTxx_PIN & DHTxx_LINE)
#define DHTxx_LINE_HI (DHTxx_PIN & DHTxx_LINE)


void dhtxx_reset(void);

void dhtxx_check(void);
uint8_t dhtx_byte_read(void);
void dhtxx_message_read(uint8_t *table);

#endif /* DHTXX_H_ */