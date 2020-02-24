/*
 * Nom: probleme2_lab2.cpp
 * Auteurs : Tassaux Lucas (1782898) et Lachieze-Rey Hugo (1934177)
 * License http://www.gnu.org/copyleft/gpl.html GNU/GPL
 * Description: Ceci est la solution du probleme 2 du laboratoire 2. 
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
#define F_CPU 8000000
#define B_pressed (PIND & 0x04) //bouton appuyé
#include <debug.h>
#include <avr/io.h>
#include <util/delay.h>


int main()
{
    DDRA = 0xff; // PORT A est en mode sortie
    DDRD = 0x00; // PORT D est en mode entrée
    unsigned long rouge = 1;
    unsigned long vert = 2;
    enum Etat
    {
        INIT,
        E1,
        E2,
        E3,
        E4,
        E5
    };
    Etat Etat_present = INIT;
    for (;;)
    {

        switch (Etat_present)
        {
        case INIT:
        DEBUG_RS232(Etat_present);
            PORTA = rouge;
            //système anti-rebond
            if (B_pressed)
            {
                _delay_ms(10);
                if (B_pressed)
                {
                    Etat_present = E1;
                }
            }
            break;

        case E1:
            while (B_pressed)
            {
                PORTA = vert;
                _delay_ms(2);
                PORTA = rouge;
                _delay_ms(1);
            }
            Etat_present = E2;
            break;

        case E2:
            PORTA = vert;
            if (B_pressed)
            {
                _delay_ms(10);
                if (B_pressed)
                {
                    Etat_present = E3;
                }
            }
            break;

        case E3:
            while (B_pressed)
            {
                PORTA = rouge;
            }
            Etat_present = E4;
            break;

        case E4:
            PORTA = 0;
            if (B_pressed)
            {
                _delay_ms(10);
                if (B_pressed)
                {
                    Etat_present = E5;
                }
            }
            break;
        case E5:
            while (B_pressed)
            {
                PORTA = vert;
            }
            Etat_present = INIT;
            break;
        }
    }
}
