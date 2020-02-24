/*
 * Nom: sonorite.h
 * Auteurs : Tassaux Lucas (1782898), Lachieze-Rey Hugo (1934177), 
 * Yassine Jabir (1955564) et Joseph Homsi (1986704)
 * Description: Un des fichiers pour notre librairie du laboratoire 7. 
 */
// #ifndef SONORITE_H
// #define SONORITE_H


// #define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>

void jouerNote(int note);
void arreterSono();
void melodie();

const double tableauMelodie[] = {
    110,  //0
    116.5409404,
    123.4708253,
    130.8127827, //3
    138.5913155,
    146.832384,//5
    155.5634919,
    164.8137785,
    174.6141157, //8
    184.9972114,
    195.997718,//10
    207.6523488,
    220,    //12
    233.0818808,
    246.9416506,
    261.6255653,//15
    277.182631,
    293.6647679,
    311.1269837,
    329.6275569, //19
    349.2282314,
    369.9944227,
    391.995436, //22
    415.3046976,
    440,
    466.1637615, //25
    493.8833013,
    523.2511306,
    554.365262, //28
    587.3295358,
    622.2539674,
    659.2551138, //31
    698.4564629,
    739.9888454, //33
    783.990872,
    830.6093952, //35
    880
    };

// #endif
