#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include "boucle_test.h"

int main()
{
    DDRA = 0x00;
    impulsion();
    suivreLigne(150);
    _delay_ms(100);
    allumerDEL(0x01, 'B');
    boucle();

}