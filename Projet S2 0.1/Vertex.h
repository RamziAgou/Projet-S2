#ifndef VERTEX_H_INCLUDED
#define VERTEX_H_INCLUDED
#include <vector>
#include <memory>
#include "VertexInterface.h"

class Vertex
{
    // Les (methodes des) classes amies pourront accéder
    // directement aux attributs (y compris privés)
    friend class Graph;
    friend class VertexInterface;
    friend class Edge;
    friend class EdgeInterface;

    private :
        /// liste des indices des arcs arrivant au sommet : accès aux prédécesseurs
        std::vector<int> m_in;

        /// liste des indices des arcs partant du sommet : accès aux successeurs
        std::vector<int> m_out;

        /// un exemple de donnée associée à l'arc, on peut en ajouter d'autres...
        int m_popul;
        std::string m_nom;

        /// le POINTEUR sur l'interface associée, nullptr -> pas d'interface
        std::shared_ptr<VertexInterface> m_interface = nullptr;

        // Docu shared_ptr : https://msdn.microsoft.com/fr-fr/library/hh279669.aspx
        // La ligne précédente est en gros équivalent à la ligne suivante :
        // VertexInterface * m_interface = nullptr;


    public:

        /// Les constructeurs sont à compléter selon vos besoin...
        /// Ici on ne donne qu'un seul constructeur qui peut utiliser une interface
        Vertex (std::string name ="", double value=0, VertexInterface *interface=nullptr) :
            m_nom(name), m_popul(value), m_interface(interface)  {  }

        /// Vertex étant géré par Graph ce sera la méthode update de graph qui appellera
        /// le pre_update et post_update de Vertex (pas directement la boucle de jeu)
        /// Voir l'implémentation Graph::update dans le .cpp
        void pre_update();
        void post_update();

        double getX();
        double getY();

        std::string getName() const;
        std::shared_ptr<VertexInterface>& getInterVertex();
};

#endif // VERTEX_H_INCLUDED
