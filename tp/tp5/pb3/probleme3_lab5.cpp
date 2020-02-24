/*
 * Nom: probleme1_lab4.cpp
 * Auteurs : Tassaux Lucas (1782898) et Lachieze-Rey Hugo (1934177)
 * License http://www.gnu.org/copyleft/gpl.html GNU/GPL
 * Description: Ceci est la solution du probleme 3 du laboratoire 5. 
 */

#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include "memoire_24.h"
#include <string.h>


void initialisationUART ( void ) {

    // 2400 bauds. Nous vous donnons la valeur des deux
    // premier registres pour vous éviter des complications

    UBRR0H = 0;
    UBRR0L = 0xCF;

    // permettre la réception et la transmission par le UART0

    // UCSR0A 
    UCSR0B |= (1 << RXEN0) | (1 << TXEN0)  ;

    // Format des trames: 8 bits, 1 stop bits, none parity

    UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00) ;

};
    
// De l'USART vers le PC

void transmissionUART ( uint8_t donnee ) {

    while ( !( UCSR0A & (1<<UDRE0)) );
    /* Put data into buffer, sends the data */
    UDR0 = donnee;
}

int main()
{ 
    uint16_t adresse = 0x00; 
    uint8_t caractereLu; 
    initialisationUART();

    Memoire24CXXX memoire;

    do{
        memoire.lecture(adresse, &caractereLu);
        transmissionUART(caractereLu);
        adresse += sizeof(caractereLu); 
    }while (caractereLu != 0xFF);
}