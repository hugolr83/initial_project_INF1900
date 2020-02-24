#define F_CPU 8000000
#include "sonar.h"
volatile uint8_t compteur = 0;
uint8_t distanceMur = 0;
char tabValeurs[16] = "";
char *valeurRetour = 0;

ISR(INT1_vect) {
  if (PIND & 0X08) {
    TCNT2 = 0;
  } else {
    compteur = TCNT2;
  }
}

int main() {
  suivreLigne();
  initSonar();
  envoyerSon();
  while (PINA == RIEN) {
    
    if (suivreMur(compteur)) {
      allumerDEL(0x01, 'B');
    } else {
      allumerDEL(0x02, 'B');
    }

    _delay_ms(50);
    envoyerSon();
  }
  arreterSonar();
  suivreLigne();
};