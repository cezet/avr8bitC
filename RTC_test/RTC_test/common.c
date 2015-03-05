/*
 * common.c
 *
 * Created: 02/03/2015 00:04:09
 *  Author: czop.m
 */ 

#include "common.h"

void bcd_to_ascii(char inp_byte, char *text){
	*text++ = (inp_byte >> 4) + '0';
	*text++ = (inp_byte & 0x0F) + '0';
	*text++ = '\0';
}
