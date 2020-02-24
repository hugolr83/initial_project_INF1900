/*
 * Nom: ligne.cpp
 * Auteurs : Tassaux Lucas (1782898), Lachieze-Rey Hugo (1934177), 
 * Yassine Jabir (1955564) et Joseph Homsi (1986704)
 * Description: Un des fichiers pour notre projet 
 */

#include "ligne.h"

void suivreLigne(uint8_t puissance)
{

    bool verif = true;

    while (verif)
    {

        //DEBUG_RS232((uint8_t)ligne); debug

        switch (PINA)
        {
        case C:
        case FGC:
        case FDC:
        case FGCFD:
            roueGauche(puissance, avancer);
            roueDroite(puissance, avancer);
            _delay_ms(10);
            break;

        case G:
            roueDroite(180, avancer);
            roueGauche(70, avancer);
            _delay_ms(10);
            break;
        case FG:
        case GFG:
            roueDroite(150, avancer);
            roueGauche(80, avancer);
            _delay_ms(10);
            break;

        case D:
            roueGauche(180, avancer);
            roueDroite(70, avancer);
            _delay_ms(10);
            break;
        case FD:
        case DFD:
            roueGauche(150, avancer);
            roueDroite(80, avancer);
            _delay_ms(10);
            break;

        case GFGC:
        case GFGCFD:
        case GFGCFDD:
            roueGauche(100, avancer);
            roueDroite(100, avancer);
            _delay_ms(800);
            roueGauche(0, arreter);
            roueDroite(0, arreter);
            // _delay_ms(500);
            // roueDroite(150, reculer);
            // roueGauche(150, avancer);
            // _delay_ms(900);
            verif = false;
            break;

        case RIEN:
            roueGauche(0, arreter);
            roueDroite(0, arreter);
            verif = false;
            break;
        }
    }
}
void tourner90()
{
    // roueDroite(100, avancer);
    // roueGauche(100, avancer);
    // _delay_ms(1000);
    roueGauche(0, arreter);
    roueDroite(0, arreter);
    while (PINA != FGC)
    {
        roueDroite(130, reculer);
        roueGauche(130, avancer);
    }
    roueDroite(0, arreter);
    roueGauche(0, arreter);
}


//demarrer robot
void impulsion()
{
    roueDroite(255, avancer);
    roueGauche(255, avancer);
    _delay_ms(100);
}