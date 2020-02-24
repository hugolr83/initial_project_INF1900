/*
 * Nom: DEL.cpp 
 * Auteurs : Tassaux Lucas (1782898) et Lachieze-Rey Hugo (1934177)
 * Description: Un des fichiers pour notre librairie du laboratoire 7. 
 * Legende couleur : 
 * Pour les pin 1 et 2: 0 = noir / 1 = rouge / 2 = vert
 * Pour la couleur ambre il suffit d'alterner entre les couleurs verte et rouge
 */

#include "DEL.h"

void AllumerDEL(uint8_t couleur, char port)
{
    switch (port)
    {
    case 'A':
        DDRA = 0xff;
        PORTA = couleur;
        break;

    case 'B':
        DDRB = 0xff;
        PORTB = couleur;
        break;

    case 'C':
        DDRC = 0xff;
        PORTC = couleur;
        break;

    case 'D':
        DDRD = 0xff;
        PORTD = couleur;
        break;
    }
}
