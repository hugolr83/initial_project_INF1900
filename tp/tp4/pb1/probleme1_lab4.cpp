/*
 * Nom: probleme1_lab4.cpp
 * Auteurs : Tassaux Lucas (1782898) et Lachieze-Rey Hugo (1934177)
 * License http://www.gnu.org/copyleft/gpl.html GNU/GPL
 * Description: Ceci est la solution du probleme 1 du laboratoire 4. 
 * Table des états :
+--------------+---+--------------+------------+
| État présent | B | État suivant | sortie DEL |
+--------------+---+--------------+------------+
| INIT         | 0 | INIT         |          R |
| INIT         | 1 | E1           |          J |
| E1           | 1 | E1           |          J |
| E1           | 0 | E2           |          V |
| E2           | 0 | E2           |          V |
| E2           | 1 | E3           |          R |
| E3           | 1 | E3           |          R |
| E3           | 0 | E4           |          0 |
| E4           | 0 | E4           |          0 |
| E4           | 1 | E5           |          V |
| E5           | 1 | E5           |          V |
| E5           | 0 | INIT         |          R |
+--------------+---+--------------+------------+

Légende : 
Entrées : B = bouton (0 = relaché / 1 = appuyé)
Sorties DEL : V=vert / R=rouge / J=ambré / 0=Noir 
États : INIT= état intial, bouton appuyé zero fois
        E1= état 1, bouton appuyé
        E2= état 2, bouton relaché pour la première fois
        E3= état 3, bouton appuyé pour la deuxième fois
        E4= état 4, bouton relaché pour la deuxième fois
        E5= état 5, bouton appuyé pour la troisième fois

Broches utilisées : PORTA 1 et 2 / PORTD 3
 */

#define B_pressed (PIND & 0x04) //bouton appuyé
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#define F_CPU 8000000

enum Etat
{
    INIT,
    E1,
    E2,
    E3,
    E4,
    E5
};

volatile Etat Etat_present = INIT;

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

    EICRA |= (1 << ISC00);

    // sei permet de recevoir à nouveau des interruptions.

    sei();
}

// placer le bon type de signal d'interruption
// à prendre en charge en argument

ISR(INT0_vect)
{

    // laisser un delai avant de confirmer la réponse du
    // bouton-poussoir: environ 30 ms (anti-rebond)

    _delay_ms(30);

    // se souvenir ici si le bouton est pressé ou relâché

    if (Etat_present == E5)
    {
        Etat_present = INIT;
    }
    else
    {
        Etat_present = Etat(Etat_present + 1);
    }

    // changements d'états tels que ceux de la
    // semaine précédente

    // Voir la note plus bas pour comprendre cette instruction et son rôle

    EIFR |= (1 << INTF0);
}

int main()
{

    initialisation();

    unsigned long rouge = 1;
    unsigned long vert = 2;

    for (;;)
    {

        switch (Etat_present)
        {
        case INIT:
            PORTA = rouge;
            break;

        case E1:
            PORTA = vert;
            _delay_ms(2);
            PORTA = rouge;
            _delay_ms(1);
            break;

        case E2:
            PORTA = vert;
            break;

        case E3:
            PORTA = rouge;
            break;

        case E4:
            PORTA = 0;
            break;

        case E5:
            PORTA = vert;
            break;
        }
    }
}
