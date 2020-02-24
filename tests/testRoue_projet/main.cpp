#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include "coupures.h"

int main()
{
   DDRA = 0x00;
   suivreLigne();
   tourner90();
   _delay_ms(100);
   coupures();
}