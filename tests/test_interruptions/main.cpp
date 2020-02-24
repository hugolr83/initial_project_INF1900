#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include "interruption.h"
#include "DEL.h"




int main()
{
    initialisationBouton();

    volatile bool debutParcours = false;
    volatile Etat etat_present = couloir;


    //attente du début du parcours
    while (debutParcours == false){}
    _delay_ms(2000);
    

    for (;;)
    {
        switch (etat_present)
        {
        case couloir:

        allumerDEL(0x01, 'B');
        break;

        case mur:
        allumerDEL(0x02, 'B');
        break;

        case boucles:
        allumerDEL(0x00, 'B');
        break;

        case coupures: 
        allumerDEL(0x00, 'B');
        break;

        }
    }
}
