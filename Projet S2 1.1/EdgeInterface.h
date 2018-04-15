/*!
 * \file EdgeInterface.h
 * \brief Cr�ation d'un �cosyst�me
 * \author Groupe AGOUGILE-CAMUGLI-AVAKIAN
 * \version 1.1
 */

#ifndef EDGEINTERFACE_H_INCLUDED
#define EDGEINTERFACE_H_INCLUDED
#include "grman/grman.h"
#include "Vertex.h"


/*! \class EdgeInterface
   * \brief classe representant l'interface graphique des arcs du graphe
   *
   *  La classe permet de cr�er un arc graphiquement et de le g�rer
   */
class EdgeInterface
{
    // Les (methodes des) classes amies pourront acc�der
    // directement aux attributs (y compris priv�s)
    friend class Edge;
    friend class Graph;
    friend class GraphInterface;

    private :

        /// Les widgets de l'interface. N'oubliez pas qu'il ne suffit pas de d�clarer
        /// ici un widget pour qu'il apparaisse, il faut aussi le mettre en place et
        /// le param�trer ( voir l'impl�mentation du constructeur dans le .cpp )

        /// Le WidgetEdge qui "contient" toute l'interface d'un arc
        grman::WidgetEdge m_top_edge;

        /// Une boite pour englober les widgets de r�glage associ�s
        grman::WidgetBox m_box_edge;

        /// Un slider de visualisation/modification du poids valeur de l'arc
        grman::WidgetVSlider m_slider_weight;

        /// Un label de visualisation du poids de l'arc
        grman::WidgetText m_label_weight;

    public :

        /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe EdgeInterface
     *
     *  \param from : Indice du sommet de depart
        \param to : Indice du sommet d'arrive
     */
        EdgeInterface(Vertex& from, Vertex& to);

        EdgeInterface(VertexInterface& from, VertexInterface& to);

        ///Affiche un certain nombre de fleche representant l'intensit� de l'echange
        void indicateur_poids();
};

#endif // EDGEINTERFACE_H_INCLUDED
