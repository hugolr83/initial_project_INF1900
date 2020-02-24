/*
 * Nom: ecrireCode.cpp
 * Auteurs : Tassaux Lucas (1782898), Lachieze-Rey Hugo (1934177), 
 * Yassine Jabir (1955564) et Joseph Homsi (1986704)
 * Description: Un des fichiers pour notre librairie du laboratoire 9. 
 */

#define F_CPU 8000000
#include <memoire_24.h>
#include <memoire.h>
#include <DEL.h>
#include <debug.h>
#include <avr/io.h>
#include <util/delay.h>


int main()
{
  
  Memoire24CXXX memoire;
  initialisationUART();
  uint8_t donnee;
  uint16_t adresse = 0x00;
  uint16_t taille = 0;
  uint16_t taille_2 = 0;
    
  taille = receptionUART();       
  memoire.ecriture(adresse, taille); 
  _delay_ms(5);
  adresse++;

  taille = taille <<8;
  taille_2 = receptionUART();
  memoire.ecriture(adresse, taille_2);
  _delay_ms(5);
  adresse++;
  taille |= taille_2;
  
  for(uint8_t i = 2 ; i < taille ; i++){
      donnee = receptionUART();
      memoire.ecriture(adresse, donnee);
      _delay_ms(5);
      adresse++;
      
    }   
}