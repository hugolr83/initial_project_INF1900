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
void allumerDEL(uint8_t couleur, char port) {
  switch (port) // pour les 4 ports du robot (A,B,C et D)
  {

  default :
    DDRB |= (1<<PB0) | (1<<PB1); // port b en mode sortie Broche 1 et 2
    PORTB = couleur;
    break;
  }
}
