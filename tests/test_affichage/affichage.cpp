/*
 * Nom: affichage.cpp
 * Auteurs : Tassaux Lucas (1782898), Lachieze-Rey Hugo (1934177), 
 * Yassine Jabir (1955564) et Joseph Homsi (1986704)
 * Description: Un des fichiers pour notre projet.
 */

#define F_CPU 8000000
#include "affichage.h"

// Fonction pour afficher la section du parcours sur l'ecran LCD
// Prend en paramètre l'état dans lequel se trouve le robot

void afficherLCD(SectionParcours etat_present)
{
    switch (etat_present)
    {
    case Mur:
    
        disp.clear(); // fonction de lcm pour effacer le contenu de l'afficheur LCD
        disp.write("Mur", 5); // fonction de lcm pour écrire une chaine à l'indice voulu
    
        break;
    
    case Couloir:
    
        disp.clear(); 
        disp.write("Couloir", 3);
       
        break;

    case Coupures: 
    
        disp.clear(); 
        disp.write("Coupures", 2);
    
        break;
    
    case Boucles: 
    
        disp.write("Boucles", 3);
        disp.clear(); 
    
        break;
 
    }
}