/*
 * Nom: DEL.cpp 
 * Auteurs : Tassaux Lucas (1782898) et Lachieze-Rey Hugo (1934177)
 * Description: Un des fichiers pour notre librairie du laboratoire 7. 
 * Legende couleur : 
 * Pour les pin 1 et 2: 0 = noir / 1 = rouge / 2 = vert
 * Pour la couleur ambre il suffit d'alterner entre les couleurs verte et rouge
 */

#include "DEL.h"

// allumer la DEL du robot selon le port désiré et la couleur voulue
void allumerDEL(uint8_t couleur, char port)
{
    switch (port) // pour les 4 ports du robot (A,B,C et D)
    {
    case 'A':
        DDRA = 0xff; // port en mode sortie
        PORTA = couleur;
        break;

    case 'B':
        DDRB = 0xff; // port en mode sortie
        PORTB = couleur;
        break;

    case 'C':
        DDRC = 0xff; // port en mode sortie
        PORTC = couleur;
        break;

    case 'D':
        DDRD = 0xff; // port en mode sortie
        PORTD = couleur;
        break;
    }
}
