/*
 * Nom: lectureCode.cpp
 * Auteurs : Tassaux Lucas (1782898), Lachieze-Rey Hugo (1934177),
 * Yassine Jabir (1955564) et Joseph Homsi (1986704)
 * Description: Un des fichiers pour notre projet.

+--------------+--------+-------------+
| État présent | bouton | État suivant |
+--------------+--------+--------------+
| MUR          |        |  BOUCLES     |
| BOUCLES      |        |  COUPURES    |
| COUPURES     |        |  COULOIR     |
| COULOIR      |        |    MUR       |
+--------------+--------+--------------+

États : les états sont les différentes étapes du parcours

Broches utilisées :
    - Sonar : PORTD PIN2 et PIN4
    - Suiveur de ligne : PORTA
    - afficheur LCD :
 */

#define Etat_presse (PINB & 0x04)
#define Start_presse (PIND & 0x04)
#include <DEL.h>
#include <affichage.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <boucles.h>
#include <couloir.h>
#include <coupures.h>
#include <roue.h>
#include <sonar.h>
#include <util/delay.h>

// compteur afin de calculer la distance pour le sonar
uint8_t compteurOnde = 0;
// compteur pour les etapes du parcours
uint8_t compteurParcours = 0;
// booleen pour debuter le parcours lors de l'appui du bouton-poussoir
volatile bool debutParcours = true;
// choix personel pour commencer le parcours dans le code
volatile SectionParcours etat_present = Couloir;

volatile uint8_t compteurSonar = 0;

void initialisationBoutons(void) {
  // cli est une routine qui bloque toutes les interruptions.
  // Il serait bien mauvais d'être interrompu alors que
  // le microcontroleur n'est pas prêt...
  cli();
  DDRB &= ~(1 << PB2);
  DDRB &= ~(1 << PB4);
  // cette procédure ajuste le registre EIMSK
  // de l’ATmega324PA pour permettre les interruptions externes

  EIMSK |= (1 << INT0) | (1 << INT2);

  // il faut sensibiliser les interruptions externes aux
  // changements de niveau du bouton-poussoir
  // en ajustant le registre EICRA

  EICRA |= (1 << ISC00) | (1 << ISC01) | (1 << ISC20) | (1 << ISC21);

  // sei permet de recevoir à nouveau des interruptions.

  sei();
}

void arreterBoutons(){
  EIMSK &= ~(1 << INT0) & ~(1 << INT2);
  EICRA &= ~(1 << ISC00) & ~(1 << ISC01) & ~(1 << ISC20) & ~(1 << ISC21);
}

// Interuption du bouton qui change la section du parcours à faire
ISR(INT2_vect) {
  // bool rebond = boutonEtatPresse(); // anti-rebond
  if (Etat_presse) {
    _delay_ms(10);
    if (Etat_presse) {
      // allumerDEL(0x01, 'B');
      // afficherLCD(etat_present);
      if (etat_present == Boucles) {
        etat_present = Mur;
      } else {
        etat_present = SectionParcours(etat_present + 1);
      }
      afficherLCD(etat_present);
      EIFR |= (1 << INTF2);
    }
  }
}

// Interuption du bouton qui lance le parcours
// ISR(INT0_vect) {
//   if (Start_presse) {
//     _delay_ms(10);
//     if (Start_presse) {
//       debutParcours = true;
//       // anti-rebond
//       _delay_ms(30);
//     }
//   }
//   EIFR |= (1 << INTF0);
// }

// Interuption du sonar qui utilise la valeur du compteur pour calculer la distance
// ISR(INT1_vect) {
//   if (PIND & 0X08) {
//     TCNT2 = 0;
//   } else {
//     compteurSonar = TCNT2;
//   }
//   EIFR |= (1 << INTF1);
// }

int main() {

   activationPWM();
     suivreLigne(150);

//   //initialisationBoutons();
//   afficherLCD(etat_present);
//   //while (!debutParcours); // tant que le bouton-poussoir n'est pas enfoncer
//  // arreterBoutons();

//   while (debutParcours) {

//     switch (etat_present) {
//     case Mur:
//       // afficher la section sur l'ecran LCD
//       afficherLCD(etat_present);
//       allumerDEL(0x01, 'B');
//       suivreLigne(130);
//       allumerDEL(0x02, 'B');
//       initSonar();
//       envoyerSon();
//       while (PINA == RIEN) {
//         if (suivreMur(compteurSonar)) {
//           allumerDEL(0x01, 'B');
//         } else {
//           allumerDEL(0x02, 'B');
//         }
//         _delay_ms(50);
//         envoyerSon();
//       }
//       arreterSonar();
//       suivreLigne(130);
//       tourner90(); // virage de fin de section
//       compteurParcours++;
//       etat_present = Boucles;
//       break;

//     case Boucles:
//       afficherLCD(etat_present);
//       suivreLigne(130);
//       boucle();
//       tourner90();
//       compteurParcours++;
//       etat_present = Coupures;
//       break;

//     case Coupures:
//       afficherLCD(etat_present);
//       suivreLigne(130);
//       coupures();
//       tourner90();
//       compteurParcours++;
//       etat_present = Couloir;
//       break;

//     case Couloir:
//       afficherLCD(etat_present);
//       impulsion();
//       suivreLigne(110);
//       _delay_ms(100);
//       couloir();
//       _delay_ms(10);
//       tourner90();
//       compteurParcours++;
//       etat_present = Mur;
//       break;
      
//     }

//     // si les 4 etapes du parcours ont ete faites
//     if (compteurParcours == 4) {
//       debutParcours = false;
//       compteurParcours = 0;
//     }
//   }
//   // Arret de toutes les fonctionnalites du robot
//   roueGauche(0, arreter);
//   roueDroite(0, arreter);
//   disp.clear();
//   disp.write("Fin Parcours", 0);
}