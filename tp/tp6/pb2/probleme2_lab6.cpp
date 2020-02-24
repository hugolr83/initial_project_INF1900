/*
 * Nom: probleme2_lab6.cpp
 * Auteurs : Tassaux Lucas (1782898) et Lachieze-Rey Hugo (1934177)
 * Description: Ceci est la solution du probleme 2 du laboratoire 6. 
 * Broches utilisées : PORTA et PORTB
 */

#define F_CPU 8000000
#include "can.h"
#include <avr/io.h>
#include <util/delay.h>

int main()
{

    DDRA = 0x00; // PORT A est en mode entrée
    DDRB = 0xff; // PORT B est en mode sortie

    //initialisation des couleurs pour le portB
    unsigned long rouge = 1;
    unsigned long vert = 2;
    can capteur;

    for (;;)
    {
        uint16_t luminosite_16 = capteur.lecture(0x00);  //conversion de la luminosité en signal numérique
        uint8_t luminosite_8 = luminosite_16 >> 2;  //conversion en uint8 et suppression des bits non pertinents
        if (luminosite_8 > 235)
        {
            PORTB = rouge;
        }
        else if ( luminosite_8 < 85)
        {
            PORTB = vert;
        }
        else
        {
            //couleur ambrée
            PORTB = vert;
            _delay_ms(2);
            PORTB = rouge;
            _delay_ms(1);
        }
    }
return 0 ;

}
