/*
 * Nom: probleme1_lab2.cpp
 * Auteurs : Tassaux Lucas (1782898) et Lachieze-Rey Hugo (1934177)
 * License http://www.gnu.org/copyleft/gpl.html GNU/GPL
 * Description: Ceci est la solution du probleme 1 du laboratoire 2. 
 * Table des états :
 
+--------------+---+--------------+------------+
| État présent | B | État suivant | sortie DEL |
+--------------+---+--------------+------------+
| INIT         | 0 | INIT         |          0 |
| INIT         | 1 | E1           |          0 |
| E1           | 0 | E1           |          0 |
| E1           | 1 | E2           |          0 |
| E2           | 0 | E2           |          0 |
| E2           | 1 | E3           |          0 |
| E3           | 0 | E3           |          0 |
| E3           | 1 | E4           |          0 |
| E4           | 0 | E4           |          0 |
| E4           | 1 | E5           |          1 |
| E5           | x | INIT         |          0 |
+--------------+---+--------------+------------+
Legende:
Entrée: B= bouton (si B=1, bouton poussé)
États : INIT= état initial, bouton pressé zero fois
        E1= état 1, bouton pressé 1 fois
        E2= état 2, bouton pressé 2 fois
        E3= état 3, bouton pressé 3 fois
        E4= état 4, bouton pressé 4 fois
        E5= état 5, bouton pressé 5 fois
Broches utilisées : PORTA 1 et 2 / PORTD 3
 */

#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
int main()
{
    
    DDRA = 0xff; // PORT A est en mode sortie
    DDRD = 0x00; // PORT D est en mode entrée
    unsigned long rouge = 1;
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
            PORTA = 0;
            //système anti-rebond
            if (PIND & 0x04)
            {
                _delay_ms(10);
                while (PIND & 0x04)
                {
                    Etat_present = E1;
                }
            }
            break;

        case E1:
            if (PIND & 0x04)
            {
                _delay_ms(10);
                while (PIND & 0x04)
                {
                    Etat_present = E2;
                }
            }
            break;
        case E2:
            if (PIND & 0x04)
            {
                _delay_ms(10);
                while (PIND & 0x04)
                {
                    Etat_present = E3;
                }
            }
            break;
        case E3:
            if (PIND & 0x04)
            {
                _delay_ms(10);
                while (PIND & 0x04)
                {
                    Etat_present = E4;
                }
            }
            break;
        case E4:
            if (PIND & 0x04)
            {
                _delay_ms(10);
                while (PIND & 0x04)
                {
                    Etat_present = E5;
                }
            }
            break;
        case E5:
            PORTA = rouge;
            _delay_ms(1000);
            Etat_present = INIT;
            break;
        }
    }
}
