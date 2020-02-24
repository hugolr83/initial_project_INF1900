/*
 * Nom: Memoire.cpp
 * Auteurs : Tassaux Lucas (1782898), Lachieze-Rey Hugo (1934177), 
 * Yassine Jabir (1955564) et Joseph Homsi (1986704)
 * Description: Un des fichiers pour notre librairie du laboratoire 9. 
 */

#include "memoire.h"

// fonction de la documentation Atmel
void transmissionUART(uint8_t donnee)
{

    while (!(UCSR0A & (1 << UDRE0)));
    /* Put data into buffer, sends the data */
    UDR0 = donnee;
}

// fonction de la documentation Atmel
uint8_t receptionUART(void)
{
    /* Wait for data to be received */
    while (!(UCSR0A & (1 << RXC0)))
    {

    } /* Get and return received data from buffer */
    return UDR0;
}

void initialisationUART(void)
{

    // 2400 bauds. Nous vous donnons la valeur des deux
    // premier registres pour vous éviter des complications

    UBRR0H = 0;
    UBRR0L = 0xCF;

    // permettre la réception et la transmission par le UART0

    // UCSR0A
    UCSR0B |= (1 << RXEN0) | (1 << TXEN0);

    // Format des trames: 8 bits, 1 stop bits, none parity

    UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);
}

// afficher le contenu de la mémoire si besoin
void affichageMemoire(uint16_t adresse, uint8_t caractereLu, uint8_t dernierCaractereLu)
{

    initialisationUART();

    Memoire24CXXX memoire;

    do
    {
        memoire.lecture(adresse, &caractereLu);
        _delay_ms(5);
        transmissionUART(caractereLu);
        _delay_ms(5);
        adresse += sizeof(caractereLu);
    } while (caractereLu != dernierCaractereLu);
}

// lire la mémoire
void lectureMemoire(Memoire24CXXX memoire, uint16_t adresse, uint8_t donnee)
{

    _delay_ms(5);
    memoire.lecture(adresse, &donnee);
    _delay_ms(5);
    transmissionUART(donnee);
}