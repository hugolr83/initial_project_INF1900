// #define F_CPU 8000000
#include "sonar.h"

void initMinuterie() {
  TCNT2 = 0;
  TCCR2A = 0;
  TCCR2B |= (1 << CS22) | (1 << CS21) | (1 << WGM21);
}

void initialisationINT1() {
  cli();
  DDRD &= ~(1 << PD3);   // mode sortie pour le port
  EIMSK |= (1 << INT1);  // pour savoir quelle interruption lancer
  EICRA |= (1 << ISC10); // interruption sur tous les fronts
  sei();
}

void envoyerSon() {
  PORTD |= (1 << PD1);
  _delay_us(15);
  PORTD &= ~(1 << PD1);
}

void arreterSonar() {
  EIMSK &= ~(1 << INT1); // arret de l'interruption
  EICRA &= ~(1 << ISC10);
  TCCR2B = 0; // arret de la minuterie
}

void initSonar() {
  DDRD |= (1 << PD1);
  initMinuterie();
  initialisationINT1();
}

bool suivreMur(uint8_t distance) {
  if (distance > 0 && distance < 25) // tourner a droite
  {
    roueGauche(150, avancer);
    roueDroite(80, avancer);
  } else if (distance > 25 && distance < 36) {
    roueGauche(130, avancer);
    roueDroite(130, avancer);
    return true;
  } else if (distance > 36 && distance < 50) {
    roueGauche(80, avancer);
    roueDroite(150, avancer);
  } else {
    roueGauche(80, avancer);
    roueDroite(140, avancer);
  }
  return false;
}
