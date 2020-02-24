/*
 * Nom: minuterie.cpp
 * Auteurs : Tassaux Lucas (1782898), Lachieze-Rey Hugo (1934177), 
 * Yassine Jabir (1955564) et Joseph Homsi (1986704)
 * Description: Un des fichiers pour notre librairie du laboratoire 7. 
 */
#include"minuterie.h"

void partirMinuterie(uint16_t duree, uint16_t masqueTCCRnB, uint16_t masqueTCCRnC)
{

    // mode CTC du timer 1 avec horloge divisée par 1024
    // interruption après la durée spécifiée

    TCNT1 = 0;

    OCR1A = duree;

    //Mode CTC et clk/1024

    TCCR1B |= masqueTCCRnB;

    TCCR1C = masqueTCCRnC;

    TIMSK1 |= (1 << OCIE1A);
}

void arreterMinuterie()
{
    TCCR1B = 0;
    TCCR1C = 0;
}