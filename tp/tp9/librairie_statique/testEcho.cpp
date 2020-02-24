

#define F_CPU 8000000
#include "directionRobot.h"
#include <avr/io.h>
#include <util/delay.h>

#define enModeEecoute PORTB 0x02
volatile bool minActive;
volatile bool obstacleOn;

void envoi() {
  DDRB = 0x1; // a changer selon le pins a activer
  // PORTB=0x1;
  _delay_us(10);
  DDRB = 0x00; // retour d'ondes
}

// registre A timer 2 interruption de timer minuterie arrive
ISR(TIMER2_COMPA_vect) { minActive = false; obstacleOn =false;}

void initialisationTimer2() {
  TTCR2A |= (1 << COM2A0) | (1 << WGM1);
  TTCR2B |= (1 << CS22) | (1 << CS21) | (1 << CS20);
  TCNT2 = 0;
  OCR2A = 281; // la valeur qui arrete le timer arrete pour 36ms
  TIMSK2 |= (1 << OCI2A);
  TIFR2 |= (1 << OCF2A);
  minActive = true; 
}

int main {

  envoi();             // envoi un son
  _delay_us(200);      // le temps que le son soit envoye
  if (enModeEecoute) { // si le pin pour la lecture est set a 1 alors on pars la
                       // minuterie
    initialisationTimer2();
  }
  do{
    if(PORTB 0x0){
      double valeurCompteur=TCNT2;
      minActive=false;
    }
  }while(minActive)

  double temps= (valeurCompteur+1)*1000/7812; //donne le temps en ms
  double distance = temps/58; //convertir le temps en distance

  printf("le temps de travel pour le son : ");
  printf("%lf", temps);
  printf("\n")
  printf("le temps de travel pour le son : ");
  printf("%lf", distance);





};