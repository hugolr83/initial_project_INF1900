/*
 * Nom: Debounce.cpp
 * Auteurs : Tassaux Lucas (1782898), Lachieze-Rey Hugo (1934177),
 * Yassine Jabir (1955564) et Joseph Homsi (1986704)
 * Description: Un des fichiers pour notre librairie du projet.
 */

#include "sonorite.h"

void jouerNote(int note) {
  DDRB |= (1<<PB3) | (1<<PB2);
  TCNT0=0;
  TCCR0A |= (1 << COM0A0) | (1 << WGM01);
  TCCR0B |= (1 << CS02) | (1 << CS00); 
  OCR0A = 8000000 / (2 * 1024 * tableauMelodie[note-45]) - 1; 
}

void arreterSono(){
  TCNT0=0;
  DDRB=0;
  TCCR0A=0;
  TCCR0B=0;
  OCR0A=0;
}

