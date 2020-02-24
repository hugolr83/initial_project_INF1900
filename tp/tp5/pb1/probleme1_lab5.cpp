/*
 * Nom: probleme1_lab4.cpp
 * Auteurs : Tassaux Lucas (1782898) et Lachieze-Rey Hugo (1934177)
 * License http://www.gnu.org/copyleft/gpl.html GNU/GPL
 * Description: Ceci est la solution du probleme 1 du laboratoire 5. 
 */

#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include "memoire_24.h"
#include <string.h>


int main()
{
    DDRA = 0xff; // PORT A est en mode sortie
    unsigned long rouge = 1;
    unsigned long vert = 2;

    Memoire24CXXX memoire;
    char tab[] = "*P*O*L*Y*T*E*C*H*N*I*Q*U*E* *M*O*N*T*R*E*A*L*";
    
    memoire.ecriture(0x00, (uint8_t*)tab, sizeof(tab)/sizeof(char));
    _delay_ms(5);
    char tablu[45];
    memoire.lecture(0x00, (uint8_t*)tablu, sizeof(tablu)/sizeof(char));
    bool verif = true;
    for (uint8_t i = 0; i < strlen(tab); i++)
    {
        if (tab[i] != tablu[i])
        {
            verif = false;
        }
    }

    if (verif)
    {
        PORTA = vert;
    }
    else
    {
        PORTA = rouge;
    }
}