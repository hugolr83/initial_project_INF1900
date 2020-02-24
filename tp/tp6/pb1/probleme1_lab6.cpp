/*
 * Nom: probleme1_lab6.cpp
 * Auteurs : Tassaux Lucas (1782898) et Lachieze-Rey Hugo (1934177)
 * Description: Ceci est la solution du probleme 1 du laboratoire 6. 

+--------------+--------+----------+--------------+------------+
| État présent | bouton | compteur | État suivant | sortie DEL |
+--------------+--------+----------+--------------+------------+
| INIT         |      0 | 0        | INIT         | E          |
| INIT         |      1 | 0        | COMPTEUR     | E          |
| COMPTEUR     |      1 | ++       | COMPTEUR     | E          |
| COMPTEUR     |      0 | <120     | DEL          | A          |
| COMPTEUR     |      1 | 120      | DEL          | A          |
| DEL          |      0 | 0        | INIT         | E          |
+--------------+--------+----------+--------------+------------+

Légende : 
Entrées :  bouton (0 = relaché / 1 = appuyé)
Sorties DEL : E = eteinte / A = allumée selon les consignes 
États : INIT = état intial, bouton non pressé, compteur = 0
        COMPTEUR = le bouton est appuyé, le compteur s'incrémente  
        DEL = le bouton est relaché ou le compteur atteint 120. La led s'allume selon les consignes. 

Broches utilisées : PORTB et PORTD
 */

#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

volatile uint8_t boutonPoussoir = 0;
volatile uint8_t compteur = 0;
enum Etat
{
    INIT,
    COMPTEUR,
    DEL
};
volatile Etat Etat_present = INIT;

void initialisation(void)
{
    cli();

    DDRB = 0xff; // PORT B est en mode sortie
    DDRD = 0x00; // PORT D est en mode entrée

    // cette procédure ajuste le registre EIMSK
    // de l’ATmega324PA pour permettre les interruptions externes

    EIMSK |= (1 << INT0);

    //Interuption sur les deux fronts de l'horloge

    EICRA |= (1 << ISC00);

    // sei permet de recevoir à nouveau des interruptions.

    sei();
}

void partirMinuterie(uint16_t duree)
{

    // mode CTC du timer 1 avec horloge divisée par 1024
    // interruption après la durée spécifiée

    TCNT1 = 0;

    OCR1A = duree;

    //Mode CTC et clk/1024

    TCCR1B |= (1 << WGM12) | (1 << CS12) | (1 << CS10);

    TCCR1C = 0;

    TIMSK1 |= (1 << OCIE1A);
}

void arreterMinuterie()
{
    //réinitialisation de la minuterie
    TCCR1B = 0;
}

ISR(INT0_vect)
{
    // anti-rebond

    _delay_ms(30);

    //pression du bouton poussoir
    if (boutonPoussoir == 0)
    {
        Etat_present = COMPTEUR;
        boutonPoussoir = 1;
        partirMinuterie(781); // F_CPU / 1024 / 10
    }
    //relachement du bouton poussoir
    else
    {
        boutonPoussoir = 0;
    }

    EIFR |= (1 << INTF0);
}

//Incrémentation du compteur
ISR(TIMER1_COMPA_vect)
{

    compteur++;
}


int main()
{
    for (;;)
    {

        initialisation();
        
        //initialisation des couleurs pour le portB
        unsigned long rouge = 4;
        unsigned long vert = 8;
        
        switch (Etat_present)
        {
        case INIT:
            PORTB = 0;
            break;

        case COMPTEUR:

            //conditions nécessaires pour allumer la DEL
            if (compteur == 120 || boutonPoussoir == 0)
            {
                arreterMinuterie();
                Etat_present = DEL;
            }
            break;

        case DEL:
            PORTB = vert;
            _delay_ms(500);
            PORTB = 0;
            _delay_ms(2000);
            //Allumage de la DEL compteur/2 fois a la fréquence de 2 fois par seconde 
            for (uint8_t i = 0; i < compteur / 2; i++)
            {
                PORTB = rouge;
                _delay_ms(250);
                PORTB = 0;
                _delay_ms(250);
                PORTB = rouge;
                _delay_ms(250);
                PORTB = 0;
                _delay_ms(250);
            }
            PORTB = vert;
            _delay_ms(1000);
            Etat_present = INIT;
            compteur = 0;
            break;
        }

        cli();
    }
}
