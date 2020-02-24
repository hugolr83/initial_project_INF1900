/*
 * Nom: directionRobot.cpp
 * Auteurs : Tassaux Lucas (1782898), Lachieze-Rey Hugo (1934177), 
 * Yassine Jabir (1955564) et Joseph Homsi (1986704)
 * Description: Un des fichiers pour notre librairie du laboratoire 9. 
 */
#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include "roue.h"
#include "DEL.h"

int main()
{
    roueGauche(250, avancer);
    roueDroite(250, avancer);
    _delay_ms(1000);
    roueGauche(0, arreter);
    roueDroite(0, arreter);
    _delay_ms(500);
    roueDroite(250, reculer);
    roueGauche(250, avancer);
    _delay_ms(1000);
    roueGauche(0, arreter);
    roueDroite(0, arreter);
}