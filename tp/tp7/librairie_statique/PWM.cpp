/*
 * Nom: PWM.cpp 
 * Auteurs : Tassaux Lucas (1782898) et Lachieze-Rey Hugo (1934177)
 * Description: Un des fichiers pour notre librairie du laboratoire 7. 
 */

#include "PWM.h"

void ajustementPWM(uint8_t parametre, uint16_t maskTCCRnA, uint16_t maskTCCRnB) 
{

    // mise à un des sorties OC1A et OC1B sur comparaison

    // réussie en mode PWM 8 bits, phase correcte

    // et valeur de TOP fixe à 0xFF (mode #1 de la table 17-6

    // page 177 de la description technique du ATmega324PA)

    OCR1A = parametre;

    OCR1B = parametre;

    // division d'horloge par 8 - implique une frequence de PWM fixe

    TCCR1A |= maskTCCRnA;

    TCCR1B |= maskTCCRnB;

    TCCR1C = 0;
}

 