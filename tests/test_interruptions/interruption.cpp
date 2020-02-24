/*
 * Nom: interruption.cpp
 * Auteurs : Tassaux Lucas (1782898), Lachieze-Rey Hugo (1934177), 
 * Yassine Jabir (1955564) et Joseph Homsi (1986704)
 * Description: Un des fichiers pour notre projet 
 */
#include "interruption.h"


void initialisationBouton(void)
{
    // cli est une routine qui bloque toutes les interruptions.
    // Il serait bien mauvais d'être interrompu alors que
    // le microcontroleur n'est pas prêt...

    cli();

    // cette procédure ajuste le registre EIMSK
    // de l’ATmega324PA pour permettre les interruptions externes

    EIMSK |= (1 << INT0);

    // il faut sensibiliser les interruptions externes aux
    // changements de niveau du bouton-poussoir
    // en ajustant le registre EICRA

    EICRA |= (1 << ISC00) | (1<<ISC01);

    // sei permet de recevoir à nouveau des interruptions.

    sei();
}


ISR(INT0_vect)
{
    if (etat_present == coupures)
    {
        etat_present = couloir;
    }
    else
    {
        etat_present = Etat(etat_present + 1);
    }
    // anti-rebond

    _delay_ms(30);

    EIFR |= (1 << INTF0);
}


