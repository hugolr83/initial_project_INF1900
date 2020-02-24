
// #ifndef SONAR_H
// #define SONAR_H

// #define F_CPU 8000000
#include "ligne.h"
#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

void initMinuterie();

void initialisationINT1();

void envoyerSon();

void arreterSonar();

void initSonar();

bool suivreMur(uint8_t distance);

// #endif