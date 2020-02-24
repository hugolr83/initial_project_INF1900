/*
 * Nom: Memoire.h
 * Auteurs : Tassaux Lucas (1782898), Lachieze-Rey Hugo (1934177), 
 * Yassine Jabir (1955564) et Joseph Homsi (1986704)
 * Description: Un des fichiers pour notre librairie du laboratoire 7. 
 */


#define F_CPU 8000000
#include "memoire_24.h"
#include <avr/io.h>
#include <util/delay.h>

uint8_t receptionUART();
void transmissionUART ( uint8_t donnee );
void initialisationUART (void);
void affichageMemoire(uint16_t adresse, uint8_t caractereLu, uint8_t dernierCaractereLu);
void lectureMemoire(Memoire24CXXX memoire, uint16_t adresse, uint8_t donnee);




