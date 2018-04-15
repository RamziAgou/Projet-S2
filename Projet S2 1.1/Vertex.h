/*!
 * \file Vertex.h
 * \brief Cr�ation d'un �cosyst�me
 * \author Groupe AGOUGILE-CAMUGLI-AVAKIAN
 * \version 1.1
 */

#ifndef VERTEX_H_INCLUDED
#define VERTEX_H_INCLUDED
#include <vector>
#include <memory>
#include "VertexInterface.h"

/*! \class Vertex
   * \brief classe representant les sommets du graphe
   *
   *  La classe gere les sommets du graphe
   */
class Vertex
{
    // Les (methodes des) classes amies pourront acc�der
    // directement aux attributs (y compris priv�s)
    friend class Graph;
    friend class VertexInterface;
    friend class Edge;
    friend class EdgeInterface;

    private :
        /// liste des indices des arcs arrivant au sommet : acc�s aux pr�d�cesseurs
        std::vector<int> m_in;

        /// liste des indices des arcs partant du sommet : acc�s aux successeurs
        std::vector<int> m_out;

        ///Valeur repr�sentant la population de l'esp�ce
        int m_popul;

        ///Nom de l'esp�ce
        std::string m_nom;

        ///Indice du Sommet
        int m_idx;
        ///Valeur maximale que la population peut atteindre
        double m_range;

        ///Variable utilis� dans l'algorithme de forte connexit�
        int m_plus;
        int m_moins;

        ///Variable utilis� pour le BFS et la Connexit�
        bool m_marque = false;
        ///Variable utilis� pour le BFS et la Connexit�
        std::vector<int> m_connexe;
        bool actif = true;



        int m_popul_moins_un;

        int m_K;
        int m_Kdebase;

        double m_r;

        /// le POINTEUR sur l'interface associ�e, nullptr -> pas d'interface
        std::shared_ptr<VertexInterface> m_interface = nullptr;

        // Docu shared_ptr : https://msdn.microsoft.com/fr-fr/library/hh279669.aspx
        // La ligne pr�c�dente est en gros �quivalent � la ligne suivante :
        // VertexInterface * m_interface = nullptr;


    public:

        /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe Vertex
     *
     *  \param name : Nom du graphe
        \param value : Population de l'espece
        \param interface : Interface du sommet
     */
        Vertex (std::string name ="", double value=0, VertexInterface *interface=nullptr) :
            m_nom(name), m_popul(value), m_interface(interface),m_moins(0),m_plus(0),m_popul_moins_un(0),m_K(0),m_r(0.01),m_Kdebase(0)  {  }

        /// Vertex �tant g�r� par Graph ce sera la m�thode update de graph qui appellera
        /// le pre_update et post_update de Vertex (pas directement la boucle de jeu)
        /// Voir l'impl�mentation Graph::update dans le .cpp
        void pre_update();
        void post_update();

        ///R�cup�re la position en abscisse du sommet sur l'�cran
        double getX();
        ///R�cup�re la position en ordonn�e du sommet sur l'�cran
        double getY();

        void setIdx(int a);
        int getIdx() const;

        void setKdebase(int a) {m_Kdebase=a;}

        int getPopu() const;
        void setPopu(int a);

        double getRange() const;
        void setRange(double a);

        std::string getName() const;
        std::shared_ptr<VertexInterface>& getInterVertex();
};

#endif // VERTEX_H_INCLUDED
