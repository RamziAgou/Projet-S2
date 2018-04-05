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


//    Acceuil1();
//
//
//
//    int i;
//    g.update(1);
//    grman::mettre_a_jour();
//
//    std::cin>>i;
//    ///clear le graphe
//
//    ///recharger le graphe
//    g.make_example();

    bool fin = false;
    /// Vous gardez la main sur la "boucle de jeu"
    /// ( contrairement � des frameworks plus avanc�s )
    while (!fin )
    {
        std::cout<<"je commence a update"<<std::endl;

        std::cout<<"fin=" <<fin<<std::endl;
        if(g.update())
            fin = true;
        std::cout<<"fin=" <<fin<<std::endl;
        std::cout<<"j'ai finit l'update"<<std::endl;

        if(key[KEY_ESC])
            fin = true;
        /// Il faut appeler les m�thodes d'update des objets qui comportent des widgets

        /// Mise � jour g�n�rale (clavier/souris/buffer etc...)
        std::cout<<"fin=" <<fin<<std::endl;
        grman::mettre_a_jour();
        std::cout<<"je met a jour"<<std::endl;
        std::cout << "X = " << g.getMapVertex()[1].getX() << " Y = " << g.getMapVertex()[1].getY() << std::endl;
        std::cout << "Population de Crabe = " << g.getMapVertex()[1].getPopu() << std::endl;
        std::cout<<"fin=" <<fin<<std::endl;
    }


    grman::fermer_allegro();

    return 0;
}
END_OF_MAIN();


