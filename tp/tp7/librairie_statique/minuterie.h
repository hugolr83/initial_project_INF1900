/*
 * Nom: minuterie.h
 * Auteurs : Tassaux Lucas (1782898), Lachieze-Rey Hugo (1934177), 
 * Yassine Jabir (1955564) et Joseph Homsi (1986704)
 * Description: Un des fichiers pour notre librairie du laboratoire 7. 
 */
#include <avr/io.h>


void partirMinuterie(uint16_t duree, uint16_t masqueTCCRnB, uint16_t masqueTCCRnC);
void arreterMinuterie();