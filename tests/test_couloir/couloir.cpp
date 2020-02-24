/*
 * Nom: couloir.cpp
 * Auteurs : Tassaux Lucas (1782898), Lachieze-Rey Hugo (1934177), 
 * Yassine Jabir (1955564) et Joseph Homsi (1986704)
 * Description: Un des fichiers pour notre projet. 
 */

#include "couloir.h"
#include "ligne.h"

bool verif = true;
bool direction = true;
uint32_t dureeRebond = 0;               // durée du rebond d'une ligne à une autre
uint8_t compteurRebonds = 0;

// while (PINA = 0x02){
//     roueDroite(150, avancer);
//     roueGauche(50, avancer);
// }

// Si le detecteur de ligne est a 01 ou 05 on change de direction 
void rebondir(bool& avancerDirection){ 
    switch (PINA) 
    {
        case G:                         // gauche (05)
        case GFG: 
             // if (dureeRebond != 0 && dureeRebond < ){}  dureeRond++  
             // else                   
            roueDroite(0, arreter);
            roueGauche(130, avancer);
            _delay_ms(10);
            avancerDirection = false;
            compteurRebonds++;
            break;
         
        case D: 
        case DFD:                        // droite (01)
             // if (dureeRebond != 0 && dureeRebond < ){}  dureeRond++  
             // else {}
            roueDroite(120, avancer);
            roueGauche(0, arreter); 
            _delay_ms(10);
            avancerDirection = true;
            compteurRebonds++;
            break;  

            default : 
            if (avancerDirection == true){
                roueDroite(120, avancer);
                roueGauche(90, avancer);
            } else {
                roueDroite(90, avancer);
                roueGauche(130, avancer);
            }
    }
}

// pour repartir sur la ligne de fin 
void repartirLigne(){
    switch (PINA)
    {
        case FD:
        case C:
        case FG:
            suivreLigne();
            _delay_ms(10);
            break;
    }
}

