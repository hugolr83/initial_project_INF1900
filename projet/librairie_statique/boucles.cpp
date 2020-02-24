/*
 * Nom: ligne.cpp
 * Auteurs : Tassaux Lucas (1782898), Lachieze-Rey Hugo (1934177), 
 * Yassine Jabir (1955564) et Joseph Homsi (1986704)
 * Description: Un des fichiers pour notre projet 
 */

#include "boucles.h"

void boucle()
{
    //MN
    suivreLigne(100);
    _delay_ms(100);
    allumerDEL(0x02, 'B');
    //NO
    suivreLigne(100);
    allumerDEL(0x00, 'B');
    //OP
    tourner90();
    suivreLigne(100);
    //PQ
    tourner90();
    suivreLigne(100);
    //QM
    tourner90();
    //suivreLigne(100);
    suivreLigne(100);
    //MN
    tourner90();
    suivreLigne(100);
    //NS
    tourner90();
    suivreLigne(100);
    //SR
    tourner90();
    suivreLigne(100);
    //RM
    tourner90();
    suivreLigne(100);
    //MT
    tourner90();
    suivreLigne(100);
    suivreLigne(100);
    suivreLigne(100);
}