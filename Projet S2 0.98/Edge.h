#ifndef EDGE_H_INCLUDED
#define EDGE_H_INCLUDED
#include "EdgeInterface.h"

class Edge
{
    // Les (methodes des) classes amies pourront acc�der
    // directement aux attributs (y compris priv�s)
    friend class Graph;
    friend class EdgeInterface;

    private :
        /// indice du sommet de d�part de l'arc
        int m_from;

        /// indice du sommet d'arriv�e de l'arc
        int m_to;

        /// un exemple de donn�e associ�e � l'arc, on peut en ajouter d'autres...
        double m_poids;

        double m_range=10;

        /// le POINTEUR sur l'interface associ�e, nullptr -> pas d'interface
        std::shared_ptr<EdgeInterface> m_interface = nullptr;


    public:

        /// Les constructeurs sont � compl�ter selon vos besoin...
        /// Ici on ne donne qu'un seul constructeur qui peut utiliser une interface
        Edge (double poids=0, EdgeInterface *interface=nullptr) :
             m_poids(poids), m_interface(interface)  {  }

        /// Edge �tant g�r� par Graph ce sera la m�thode update de graph qui appellera
        /// le pre_update et post_update de Edge (pas directement la boucle de jeu)
        /// Voir l'impl�mentation Graph::update dans le .cpp
        void pre_update();
        void post_update();

        int getDepart() const;
        int getArrive() const;
        double getPoids() const;

        double getrange(){return m_range;}

        void setArrive(int a);
        void setDepart(int a);

        std::shared_ptr<EdgeInterface>& getInterEdge();
};

#endif // EDGE_H_INCLUDED