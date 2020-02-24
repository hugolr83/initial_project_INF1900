/*
 * Nom: debug.h
 * Auteurs : Tassaux Lucas (1782898), Lachieze-Rey Hugo (1934177), 
 * Yassine Jabir (1955564) et Joseph Homsi (1986704)
 * Description: Un des fichiers pour notre librairie du laboratoire 7. 
 */
#include "Memoire.h" 
#include "memoire_24.h"
#include <avr/io.h>

#define DEBUG
#ifdef DEBUG 
    #define DEBUG_RS232(x) ecrireInfo(x)
#else 
    #define DEBUG_RS232(x) do {} while(0)
#endif

void ecrireInfo(enum donnee);