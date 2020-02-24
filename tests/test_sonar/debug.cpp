/*
 * Nom: debug.cpp
 * Auteurs : Tassaux Lucas (1782898), Lachieze-Rey Hugo (1934177), 
 * Yassine Jabir (1955564) et Joseph Homsi (1986704)
 * Description: Un des fichiers pour notre librairie du laboratoire 7. 
 */
#include "debug.h"

void ecrireInfo(uint8_t donnee) //const char*
{
initialisationUART(); 
/*for (uint8_t i =0; i<strlen(donnee);i++){
    transmissionUART (donnee[i]);
}*/
transmissionUART(donnee);

}

