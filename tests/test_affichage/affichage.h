/*
 * Nom: affichage.h
 * Auteurs : Tassaux Lucas (1782898), Lachieze-Rey Hugo (1934177), 
 * Yassine Jabir (1955564) et Joseph Homsi (1986704)
 * Description: Un des fichiers pour notre projet.
 */

#include "lcm_so1602dtr_m_fw.h"
#include "customprocs.h"
#include "lcm_so1602dtr_m_fw.h"

// Code fourni pour l'affichage LCD (utilsation des includes et defines)
#define DEMO_DDR	DDRC 
#define DEMO_PORT	PORTC 
static LCM disp(&DEMO_DDR, &DEMO_PORT);

// Les 4 sections du parcours à réaliser
enum SectionParcours{
        Mur,
        Couloir,
        Coupures,
        Boucles
    };

void afficherLCD(SectionParcours etat_present);