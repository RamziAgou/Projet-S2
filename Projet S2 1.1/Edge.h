/*!
 * \file Edge.h
 * \brief Cr�ation d'un �cosyst�me
 * \author Groupe AGOUGILE-CAMUGLI-AVAKIAN
 * \version 1.1
 */

#ifndef EDGE_H_INCLUDED
#define EDGE_H_INCLUDED
#include "EdgeInterface.h"


/*! \class Edge
   * \brief classe representant les arcs du graphe
   *
   *  La classe permet la cr�ation des arcs du graphe
   */
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

        ///Poids de l'arc representant la valeur de l'echange
        double m_poids;

        ///Valeur maximale que peut atteindre le poids de l'arc (utile pour le slider)
        double m_range=10;

        /// le POINTEUR sur l'interface associ�e, nullptr -> pas d'interface
        std::shared_ptr<EdgeInterface> m_interface = nullptr;


    public:

        /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe Edge
     *
     *  \param poids : poids de l'arc
        \param interface : Interface de l'arc
     */
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
