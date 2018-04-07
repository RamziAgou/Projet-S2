#include "grman/grman.h"
#include <iostream>

#include "graph.h"
#include "Acceuil1.h"
#include "Simulation.h"
#include "Analyse_F_C.h"
#include "Acceuil2.h"
#include "analyse_K_C.h"

int main()
{
    /// A appeler en 1er avant d'instancier des objets graphiques etc..t.
    grman::init();

    /// Le nom du répertoire où se trouvent les images à charger
    grman::set_pictures_path("pics");

    /// Un exemple de graphe

    ///g.TuerSommet(5);

    Acceuil1();

   // analyse_K_C();
 //int i;
   // std::cin>>i;


//    bool fin=false;
//    while(fin!=true)
//    {
//        Acceuil2();
//    }

    ///______________________________
    ///Début Forte conexité
    ///______________________________
   // Analyse_F_C();
    ///______________________________
    ///FIN Forte conexité
    ///______________________________
    Simulation();

    ///clear le graphe

    ///recharger le graphe




    grman::fermer_allegro();

    return 0;
}
END_OF_MAIN();


