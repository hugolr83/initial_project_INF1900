/*
 * Nom: Debounce.cpp
 * Auteurs : Tassaux Lucas (1782898), Lachieze-Rey Hugo (1934177), 
 * Yassine Jabir (1955564) et Joseph Homsi (1986704)
 * Description: Un des fichiers pour notre librairie du laboratoire 7. 
 */

#include "AntiRebond.h"

bool BoutonPresse()
{
    if (PIND & 0x04)
    {
        _delay_ms(10);
        while (PIND & 0x04)
        {
            return true;
        }
    }
    else
    {
        return false;
    }
}
