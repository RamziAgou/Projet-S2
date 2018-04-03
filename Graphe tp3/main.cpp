#include "Graphe.h"


int main()
{
    Graphe graf;
    graf.Fichier("Arete.txt");

    graf.Menu();
//    std::cout << "Toutes les aretes du graphe : " << std::endl;
//    graf.Afficher();
//    std::cout << std::endl << "Les aretes tries par poids croissant: " << std::endl;
//    graf.Kruskal();
//    std::cout << std::endl << "les aretes composant l'arbre de poids minimum: " << std::endl;
//    graf.AfficheArbre();
//    graf.AfficherDijkstra();
    return 0;
}
