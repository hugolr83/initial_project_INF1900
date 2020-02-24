/*
 * Nom: lectureCode.cpp
 * Auteurs : Tassaux Lucas (1782898), Lachieze-Rey Hugo (1934177), 
 * Yassine Jabir (1955564) et Joseph Homsi (1986704)
 * Description: Un des fichiers pour notre librairie du laboratoire 9. 
 */
#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include <DEL.h>
#include <memoire_24.h>
#include <memoire.h>
#include <PWM.h>
#include <directionRobot.h>
#include <sonorite.h>
#include <debug.h>

const uint8_t DBT = 0x01;
const uint8_t ATT = 0x02;
const uint8_t DAL = 0x44;
const uint8_t DET = 0x45;
const uint8_t SGO = 0x48;
const uint8_t SAR = 0x09;
const uint8_t MAR = 0x60;
const uint8_t MAR1 = 0x61;
const uint8_t MAV = 0x62;
const uint8_t MRE = 0x63;
const uint8_t TRD = 0x64;
const uint8_t TRG = 0x65;
const uint8_t DBC = 0xC0;
const uint8_t FBC = 0xC1;
const uint8_t FIN = 0xFF;

/*enum Commande 
{
    DBT = 0x01,
    ATT = 0x02,
    DAL = 0x44,
    DET = 0x45,
    SGO = 0x48,
    SAR = 0x09,
    MAR = 0x60 || 0x61, 
    MAV = 0x62,
    MRE = 0x63,
    TRD = 0x64,
    TRG = 0x65,
    DBC = 0xC0,
    FBC = 0xC1,
    FIN = 0xFF
};*/

int main()
{
    
    DDRD = 0xFF; // PORTD en sortie pour direction robot
    DDRB = 0xFF; // PORTB en sortie pour la sonorité et la DEL
    long vert = 0x01;
    long eteint = 0x00;
    Memoire24CXXX memoire;
    initialisationUART();
    uint16_t adresse = 0x00;
    uint8_t instructionLue = 0;
    uint8_t operandeLue = 0;
    uint8_t operande_stockee;
    uint16_t adresse_stockee;
    uint8_t iteration = 0;
    bool finParcours = false;
    //lectureMemoire(memoire, adresse, instructionLue);
    
    
    while (instructionLue != DBT)
    {   
        // Lecture + transmission
        _delay_ms(5);
        memoire.lecture(adresse, &instructionLue);
        _delay_ms(5);
        transmissionUART(instructionLue);
        
        adresse ++;
    }
    adresse++;

   while (finParcours == false) 
    {
        
        // Lecture + transmission
        _delay_ms(5);
        memoire.lecture(adresse, &instructionLue);
        _delay_ms(5);
        transmissionUART(instructionLue);
        adresse++;
        
        _delay_ms(5);
        memoire.lecture(adresse, &operandeLue);
        _delay_ms(5);
        transmissionUART(operandeLue);
        adresse++;

        switch (instructionLue)
        {
        case ATT:

            for (uint8_t i = 0; i < operandeLue; i++)
            {
                _delay_ms(25); // delay de 25 ms * operande
            }
            break;

        case DAL:
            if (operandeLue != 0)
            {
                allumerDEL(vert, 'B'); //allumer DEL en vert sur le port A
            }
            break;

        case DET:
            allumerDEL(eteint, 'B'); // éteindre la DEL
            break;

        case SGO:
            if(operandeLue<=81 && operandeLue>=45){
                  jouerNote(operandeLue); //joue une note pendant un certain temps defini dans la chore
            }
            break;
           
        case SAR:
            arreterSono();
            break;

        case MAR:
            directionaSuivre(0, arreter);
            break;

        case MAR1:
            directionaSuivre(0, arreter);
            break;

        case MAV:
            directionaSuivre(operandeLue, avancer);
            break;

        case MRE:
            directionaSuivre(operandeLue, reculer);
            break;

        case TRD:
            directionaSuivre(0, tourner_droite);
            _delay_ms(500);
            directionaSuivre(0, arreter);
            break;

        case TRG:
            directionaSuivre(0, tourner_gauche);
            _delay_ms(500);
            directionaSuivre(0, arreter);
            break;

        case DBC:

            adresse_stockee = adresse;
            operande_stockee = operandeLue;
            break;

        case FBC:
            if (iteration == operande_stockee)
            {
                iteration = 0;
            }
            else
            {
                adresse = adresse_stockee;
                iteration++;
            }
            break;
        case FIN: 
            finParcours = true;
            break;
        
        }

    }
}
