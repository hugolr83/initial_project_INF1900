/*
 * Nom: coupures.cpp
 * Auteurs : Tassaux Lucas (1782898), Lachieze-Rey Hugo (1934177), 
 * Yassine Jabir (1955564) et Joseph Homsi (1986704)
 * Description: Un des fichiers pour notre librairie du laboratoire 7. 
 */
#include "coupures.h"

void coupures()
{
    for (int i = 0; i < 2; i++)
    {
        suivreLigne();
        jouerNote(80);
        while (PINA == RIEN)
        {
            roueDroite(60, avancer);
            roueGauche(120, avancer);
            allumerDEL(0x01, 'B');
            
        }
        roueGauche(0, arreter);
        roueDroite(0, arreter);
        allumerDEL(0x00, 'B');
        arreterSono();

        suivreLigne();
        jouerNote(45);
        while (PINA == RIEN)
        {
            roueGauche(60, avancer);
            roueDroite(120, avancer);
            allumerDEL(0x02, 'B');
            
        }
        roueDroite(0, arreter);
        roueGauche(0, arreter);
        allumerDEL(0x00, 'B');
        arreterSono();
    }
    suivreLigne();
}