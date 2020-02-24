/*
 * Nom: directionRobot.cpp
 * Auteurs : Tassaux Lucas (1782898), Lachieze-Rey Hugo (1934177), 
 * Yassine Jabir (1955564) et Joseph Homsi (1986704)
 * Description: Un des fichiers pour notre librairie du laboratoire 9. 
 */
#include <directionRobot.h>

void directionaSuivre(uint8_t operande, direction sens)
{

    DDRD |= (1 << PD5) | (1 << PD7); // mode sortie
    DDRD |= (1 << PD4) | (1 << PD6);
    // PWM materiel ports 5 et 6
    // direction ports 7 et 8
    TCCR1A |= (1 << COM1A1) | (1 << WGM10) | (1 << COM1B1);
    TCCR1B |= (1 << CS11);
    // PWM materiel ports 5 et 6
    // direction ports 7 et 8

    uint8_t puissance =operande; // puissance en % (de 1 à 100)

    switch (sens)
    {
    case avancer:
        PORTD &= ~(1 << PD6) & ~(1 << PD7);
        OCR1A = puissance;
        OCR1B = 0.965 * (puissance);
        break;

    case reculer:
        PORTD |= (1 << PD6) | (1 << PD7); // inverse la polarité
        OCR1A = puissance;
        OCR1B = 0.97 * (puissance);
        break;

    case tourner_gauche:
        PORTD |= ~(1 << PD6) | (1 << PD7);
        OCR1A = 255;
        OCR1B = 255;
        break;

    case tourner_droite:
        PORTD |= (1 << PD6) | ~(1 << PD7);
        OCR1A = 255;
        OCR1B = 255; //etait a 255
        break;

    case arreter:
        DDRD = 0;
        break;
    }
}
