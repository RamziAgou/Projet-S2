#include "Acceuil2.h"

///on choisit ici l'ecosysteme (on voit donc les trois ecosystem (avec leurs descriptions)
///ou on atteint le manuel
///ou on quitte le programme
///menu mère
bool Acceuil2()
{

    Graph menu;
    menu.make_menu();
    menu.getm_interface()->page_menu();
    menu.update();
    grman::mettre_a_jour();
}

