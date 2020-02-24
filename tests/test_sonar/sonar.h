#define F_CPU 8000000
#include "debug.h"
#include "ligne.h"
#include "customprocs.h"
#include "affichage.h"
#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

void initMinuterie();

void initialisationINT1();

void envoyerSon();

void arreterSonar();

void initSonar();

bool suivreMur(uint8_t distance);