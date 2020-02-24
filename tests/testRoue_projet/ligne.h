/*
 * Nom: minuterie.h
 * Auteurs : Tassaux Lucas (1782898), Lachieze-Rey Hugo (1934177), 
 * Yassine Jabir (1955564) et Joseph Homsi (1986704)
 * Description: Un des fichiers pour notre librairie du laboratoire 7. 
 */
#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include "roue.h"
#include "DEL.h"

// ajouter port calibrage
/*G = 0x10,
    FG = 0x20,
    C = 0x04,
    FD = 0x08,
    D = 0x01,
    FGC = 0x24,
    GFG = 0x30,
    GFGC = 0x34,
    GFGCFD = 0x3C,
    GFGCFDD = 0x3D,
    FDC = 0x0C,
    DFD = 0x09,
    DFDC = 0x0D,
    DFDCFG = 0x2D,*/

enum Ligne
{
    G = ((1 << PA4)|(1 << PA1)),       // _BV() = cool 
    FG = ((1 << PA5)|(1 << PA1)),//0x02,
    C = ((1<< PA2)|(1 << PA1)),
    FD = ((1<< PA3)|(1 << PA1)),
    D = ((1<< PA0)|(1 << PA1)),
    FGC = ((1 << PA5) | (1<< PA2)|(1 << PA1)),
    FGCFD = ((1 << PA5) | (1<< PA2)|(1 << PA3) | (1 << PA1)),
    GFG = ((1 << PA4) | (1<< PA5)|(1 << PA1)),
    GFGC = ((1 << PA4) | (1<< PA5) | (1<<PA2) | (1 << PA1)),
    GFGCFD = ((1 << PA4) | (1<< PA5) | (1<<PA2) | (1<<PA3)|(1 << PA1)),
    GFGCFDD = ((1 << PA4) | (1<< PA5) | (1<<PA2) | (1<<PA3) | (1<<PA0)|(1 << PA1)),
    FDC = ((1 << PA3) | (1<< PA2)|(1 << PA1)),
    DFD = ((1 << PA0) | (1<< PA3)|(1 << PA1)),
    DFDC = ((1 << PA0) | (1<< PA3) | (1 << PA2)|(1 << PA1)),
    DFDCFG = ((1 << PA0) | (1<< PA3) | (1 << PA2) | (1 << PA5)|(1 << PA1)),
    RIEN = (1 << PA1)
};
void suivreLigne();
void tourner90();
