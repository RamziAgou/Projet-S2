#include "grman/grman.h"
#include <iostream>

#include "graph.h"
#include "Acceuil1.h"

int main()
{
    /// A appeler en 1er avant d'instancier des objets graphiques etc..t.
    grman::init();

    /// Le nom du r�pertoire o� se trouvent les images � charger
    grman::set_pictures_path("pics");

    /// Un exemple de graphe
    Graph g;
    g.make_example();


    Acceuil1();
    bool fin = false;
    /// Vous gardez la main sur la "boucle de jeu"
    /// ( contrairement � des frameworks plus avanc�s )
    while (!fin )
    {
        if(g.update())fin = true;
        if(key[KEY_ESC])fin = true;
        /// Il faut appeler les m�thodes d'update des objets qui comportent des widgets

        /// Mise � jour g�n�rale (clavier/souris/buffer etc...)
        grman::mettre_a_jour();

        std::cout << "X = " << g.getMapVertex()[1].getX() << " Y = " << g.getMapVertex()[1].getY() << std::endl;
        std::cout << "Population de Crabe = " << g.getMapVertex()[1].getPopu() << std::endl;

    }

    grman::fermer_allegro();

    return 0;
}
END_OF_MAIN();

