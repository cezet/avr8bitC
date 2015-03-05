/*
 * tabletest.c
 *
 * Created: 2015-03-02 20:46:19
 *  Author: czoper
 */ 


#include <avr/io.h>

//void dhtxx_message_read(uint16_t *table);
//uint8_t dhtx_byte_read(void);
uint16_t table_test[3];

int8_t dupa1 = 10;
int8_t dupa11;
uint8_t dupa2 = 10;
int16_t number;
int8_t integral_p, decimal_p;


int main(void)
{
	 number = 5;
//	dhtxx_message_read_v2(table_test);
	
    while(1)
    {
       number--;
	   integral_p = number / 10;
	   decimal_p = number % 10;
	   if (decimal_p < 0)
	   {
		   decimal_p = -decimal_p;
	   }
		 
		
    }
	return 1;
}
/*
void dhtxx_message_read(uint16_t *table){
	uint16_t temp;
	for (int i = 0; i < 3 ; i++)
	{
		temp = (uint16_t) dhtx_byte_read();
		temp <<= 8;
		temp |= dhtx_byte_read();
		*table++ = temp;
		*table++;
	}
	
} 

void dhtxx_message_read_v2(uint8_t *table){
	
	table += 5;
	for (int i = 5; i > 0; i--)
	{
		*table-- = dhtx_byte_read();
	}
	*table = table;
}

uint8_t dhtx_byte_read(){
	static uint8_t dupa;
	if (dupa == 0) {
		dupa++;
		return 0x01;
	}
	else if (dupa == 1) {
		dupa++;
		return 0x2;
	}
	else if (dupa == 2) {
		dupa++;
		return 0x3;
	}
	else if (dupa == 3) {
		dupa++;
		return 0x4;
	}
	else if (dupa == 4) {
		dupa++;
		return 0x5;
	}
	else return 0x99;
	

	
}

*/