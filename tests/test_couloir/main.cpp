#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include "ligne.h"
#include "couloir.h"

int main()
{
    DDRA = 0x00;
    bool direction = true;
    impulsion();
    suivreLigne();
    _delay_ms(100);
    tourner90();
    _delay_ms(100);
    suivreLigne();
    _delay_ms(100);

    while (1)
    {
        rebondir(direction);
        _delay_ms(15);
        repartirLigne();
    }
}