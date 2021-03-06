/*
 * Nom: directionRobot.cpp
 * Auteurs : Tassaux Lucas (1782898), Lachieze-Rey Hugo (1934177), 
 * Yassine Jabir (1955564) et Joseph Homsi (1986704)
 * Description: Un des fichiers pour notre librairie du laboratoire 9. 
 */
// #ifndef ROUE_H
// #define ROUE_H
// #define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#pragma once
enum direction{avancer, reculer, arreter};
void roueGauche(uint8_t puissance, direction sens);
void roueDroite(uint8_t puissance, direction sens);
void activationPWM();
// #endif