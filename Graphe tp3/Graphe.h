#ifndef GRAPHE_H_INCLUDED
#define GRAPHE_H_INCLUDED
#include <vector>
#include "Arete.h"
#include "Sommet.h"
#include <fstream>
#include <algorithm>

class Graphe
{
private:
    std::vector<Arete> m_aretes;
    std::vector<Sommet> m_sommets;
    std::vector<Arete> Arbre;
    std::vector<int> Chemin;
    int m_ordre;
    int m_nbrArete;

public:
    Graphe();
    ~Graphe();

    void Fichier(std::string nomfichier);
    void Afficher();

    void Kruskal();
    void Dijkstra(int k);
    void AfficherArbre();
    void AfficherDijkstra();
    void AfficherPred();

    void Menu();
};

bool Comparer(const Arete &A,const Arete &B);


#endif // GRAPHE_H_INCLUDED
