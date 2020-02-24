/*
 * Nom: probleme1_lab3.cpp
 * Auteurs : Tassaux Lucas (1782898) et Lachieze-Rey Hugo (1934177)
 * License http://www.gnu.org/copyleft/gpl.html GNU/GPL
 * Description: Ceci est la solution du probleme 1 du laboratoire 2. 
 */
#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#define B_pressed (PIND & 0x04) //bouton appuyé

void LoopDelay(int a)
{

    for (int i = 0; i <= a; i++)
    {
        _delay_us(3);
    }
}
int main()
{
    DDRB = 0xff; // PORT B est en mode sortie
    DDRD = 0x00; // PORT D est en mode entrée
    uint8_t rouge = 1;
    int period = 1000;

    for (;;)
    {
        if (B_pressed)
        {
            _delay_ms(20);
            while (B_pressed)
            {
                PORTB = rouge;
            }
            PORTB = 0;

            for (int a = 1000; a >= 0; a -= 1)
            {
                PORTB = rouge;

                LoopDelay(a);

                PORTB = 0;

                LoopDelay(period - a);
            }
        }
    }
}