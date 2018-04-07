#include "grman/grman.h"
#include <iostream>

#include "graph.h"
#include "Acceuil1.h"

int main()
{
    /// A appeler en 1er avant d'instancier des objets graphiques etc..t.
    grman::init();

    /// Le nom du répertoire où se trouvent les images à charger
    grman::set_pictures_path("pics");

    /// Un exemple de graphe
    Graph g;
    g.make_example();

    Acceuil1();


    g.make_example();
    g.AffichageCombi();
    g.AfficherKConnexe();
    //g.ChargerSupprimer();
    //g.TuerSommet(1);



    bool fin = false;
    /// Vous gardez la main sur la "boucle de jeu"
    /// ( contrairement à des frameworks plus avancés )
    while (!fin )
    {
        if(g.update())
            fin = true;

        if(key[KEY_ESC])
            fin = true;
        /// Il faut appeler les méthodes d'update des objets qui comportent des widgets

        /// Mise à jour générale (clavier/souris/buffer etc...)
        grman::mettre_a_jour();
    }


    grman::fermer_allegro();

    return 0;
}
END_OF_MAIN();


