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


volatile uint8_t minuterieExpiree;
volatile uint8_t boutonPoussoir;

void initialisation(void)
{
    // cli est une routine qui bloque toutes les interruptions.
    // Il serait bien mauvais d'être interrompu alors que
    // le microcontroleur n'est pas prêt...

    cli();

    // configurer et choisir les ports pour les entrées
    // et les sorties. DDRx... Initialisez bien vos variables

    DDRA = 0xff; // PORT A est en mode sortie
    DDRD = 0x00; // PORT D est en mode entrée

    // cette procédure ajuste le registre EIMSK
    // de l’ATmega324PA pour permettre les interruptions externes

    EIMSK |= (1 << INT0);

    // il faut sensibiliser les interruptions externes aux
    // changements de niveau du bouton-poussoir
    // en ajustant le registre EICRA

    EICRA |= (1 << ISC00) | (1 << ISC01);

    // sei permet de recevoir à nouveau des interruptions.

    sei();
}

ISR(TIMER1_COMPA_vect)
{

    minuterieExpiree = 1;
}

ISR(INT0_vect)
{

    boutonPoussoir = 1;

    // anti-rebond

    _delay_ms(30);

    EIFR |= (1 << INTF0);
}

// placer le bon type de signal d'interruption
// à prendre en charge en argument

void partirMinuterie(uint16_t duree)
{

    minuterieExpiree = 0;

    // mode CTC du timer 1 avec horloge divisée par 1024
    // interruption après la durée spécifiée

    TCNT1 = 0;

    OCR1A = duree;

    //TCCR1A = 0;

    TCCR1B |= (1 << WGM12) | (1 << CS12) | (1 << CS10);

    TCCR1C = 0;

    TIMSK1 |= (1 << OCIE1A);
}

int main()
{

    initialisation();

    unsigned long rouge = 1;
    unsigned long vert = 2;

    _delay_ms(10000);

    PORTA = rouge;
    _delay_ms(100);
    PORTA = 0;
    partirMinuterie(7812);
    do
    {

        // attendre qu'une des deux variables soit modifiée
        // par une ou l'autre des interruptions.

    } while (minuterieExpiree == 0 && boutonPoussoir == 0);

    // Une interruption s'est produite. Arrêter toute
    // forme d'interruption. Une seule réponse suffit.

    cli();

    // Verifier la réponse

    if (minuterieExpiree == 0 && boutonPoussoir == 1)
    {
        PORTA = vert;
    }
    else
    {
        PORTA = rouge;
    }
}
