/*
 * Nom: directionRobot.cpp
 * Auteurs : Tassaux Lucas (1782898), Lachieze-Rey Hugo (1934177), 
 * Yassine Jabir (1955564) et Joseph Homsi (1986704)
 * Description: Un des fichiers pour notre librairie du laboratoire 9. 
 */
#include "roue.h"

void activationPWM()
{

    
    
    TCCR1A |= (1 << COM1A1) | (1 << WGM10) | (1 << COM1B1);
    TCCR1B |= (1 << CS11);
    // PWM materiel ports 5 et 6
    // direction ports 7 et 8
}

void roueGauche(uint8_t puissance, direction sens)
{
    DDRD |= (1 << PD5) | (1 << PD7); // mode sortie
    activationPWM();

    switch (sens)
    {
    case avancer:
        PORTD &= ~(1 << PD6);
        OCR1A = puissance;
        break;

    case reculer:
        PORTD |= (1 << PD6); // inverse la polarité
        OCR1A = puissance;
        break;

    case arreter:
        OCR1A = 0;
        break;
    }
}
void roueDroite(uint8_t puissance, direction sens)
{
    DDRD |= (1 << PD4) | (1 << PD6);
    activationPWM();
    switch (sens)
    {
    case avancer:
        PORTD &= ~(1 << PD7);
        OCR1B = puissance;
        break;

    case reculer:
        PORTD |= (1 << PD7); // inverse la polarité
        OCR1B = puissance;
    break;

    case arreter:
        OCR1B = 0;
        break;
    }
}