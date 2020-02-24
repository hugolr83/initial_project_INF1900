/*
 * Nom: probleme1_lab3.cpp
 * Auteurs : Tassaux Lucas (1782898) et Lachieze-Rey Hugo (1934177)
 * License http://www.gnu.org/copyleft/gpl.html GNU/GPL
 * Description: Ceci est la solution du probleme 1 du laboratoire 3. 
 */
#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#define B_pressed (PIND & 0x04) //bouton appuyé

void LoopDelay60Hz(int a)
{

    for (int i = 0; i <= a; i++)
    {
        _delay_us(555);
    }
}

void LoopDelay400Hz(int a)
{

    for (int i = 0; i <= a; i++)
    {
        _delay_us(12);
    }
}

int main()
{
    DDRB = 0xff; // PORT B est en mode sortie
    DDRD = 0x00; // PORT D est en mode entrée
    int period = 60;

    for (;;)
    {

        //60Hz, 0%/25%/50%/75%/100%
        for (int j = 0; j <= 60; j += 15)
        {

            for (int i = 60; i >= 0; i -= 1)
            {
                PORTB = 1;

                LoopDelay60Hz(j);

                PORTB = 0;

                LoopDelay60Hz(period - j);
            }
        }

        _delay_ms(1000);

        //400Hz, 0%/25%/50%/75%/100%
        for (int k = 0; k <= 400; k += 100)
        {

            for (int i = 400; i >= 0; i -= 1)
            {
                PORTB = 1;

                LoopDelay400Hz(k);

                PORTB = 0;

                LoopDelay400Hz(period - k);
            }
        }
    }
}
