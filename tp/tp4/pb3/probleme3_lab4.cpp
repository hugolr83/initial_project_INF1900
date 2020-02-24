/*
 * Nom: probleme2_lab4.cpp
 * Auteurs : Tassaux Lucas (1782898) et Lachieze-Rey Hugo (1934177)
 * License http://www.gnu.org/copyleft/gpl.html GNU/GPL
 * Description: Ceci est la solution du probleme 2 du laboratoire 4. 
 */

#define F_CPU 8000000
#define B_pressed (PIND & 0x04) //bouton appuyé
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

void ajustementPWM(uint8_t parametre)
{

    // mise à un des sorties OC1A et OC1B sur comparaison

    // réussie en mode PWM 8 bits, phase correcte

    // et valeur de TOP fixe à 0xFF (mode #1 de la table 17-6

    // page 177 de la description technique du ATmega324PA)

    OCR1A = parametre;

    OCR1B = parametre;

    // division d'horloge par 8 - implique une frequence de PWM fixe

    TCCR1A |= (1 << COM1A1) | (1 << WGM10)|(1 << COM1B1);

    TCCR1B |= (1 << CS11);

    TCCR1C = 0;
}
int main()
{
    DDRD = 0xFF; // PORT D est en mode sortie

    ajustementPWM(0);
    _delay_ms(2000);
    ajustementPWM(64);
    _delay_ms(2000);
    ajustementPWM(128);
    _delay_ms(2000);
    ajustementPWM(192);
    _delay_ms(2000);
    ajustementPWM(255);
    _delay_ms(2000);
    ajustementPWM(0);
}