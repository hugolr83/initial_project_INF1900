/*
 * Nom: directionRobot.h
 * Auteurs : Tassaux Lucas (1782898), Lachieze-Rey Hugo (1934177), 
 * Yassine Jabir (1955564) et Joseph Homsi (1986704)
 * Description: Un des fichiers pour notre librairie du laboratoire 9. 
 */
#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include <PWM.h>

enum direction{avancer, reculer, tourner_droite, tourner_gauche, arreter};
void directionaSuivre(uint8_t puissance, direction sens);