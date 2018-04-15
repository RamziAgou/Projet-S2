/*!
 * \file VertexInterface.h
 * \brief Cr�ation d'un �cosyst�me
 * \author Groupe AGOUGILE-CAMUGLI-AVAKIAN
 * \version 1.1
 */

#ifndef VERTEXINTERFACE_H_INCLUDED
#define VERTEXINTERFACE_H_INCLUDED
#include "grman/grman.h"


/*! \class VertexInterface
   * \brief classe representant l'interface graphique des sommets
   *
   *  La classe gere l'affichage des sommets sur l'ecran
   */
class VertexInterface
{
    // Les (methodes des) classes amies pourront acc�der
    // directement aux attributs (y compris priv�s)
    friend class Vertex;
    friend class EdgeInterface;
    friend class Graph;
    friend class GraphInterface;

    private :


        /// La boite qui contient toute l'interface d'un sommet
        grman::WidgetBox m_top_box;

        /// Un slider de visualisation/modification de la valeur du sommet
        grman::WidgetVSlider m_slider_value;

        /// Un label de visualisation de la valeur du sommet
        grman::WidgetText m_label_value;

        /// Une image de "remplissage"
        grman::WidgetImage m_img;

        /// Un label indiquant l'index du sommet
        grman::WidgetText m_label_idx;


        /// bouton delete sommet
        grman::WidgetButton m_delete;
        grman::WidgetImage m_delete_image;

        /// Une boite pour le label pr�c�dent
        grman::WidgetText m_box_label_idx;

    public :

        /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe VertexInterface
     *
     *  \param idx : Indice du sommet
        \param x : Position du sommet sur l'ecran
        \param y : Position du sommet sur l'ecran
        \param pic_name : Nom de l'image a donner au sommet
        \param range : Valeur maximale de la population
        \param pic_idx : valeur utile si on fait une image en d�placement
     */
        VertexInterface(int idx, int x, int y, std::string pic_name="",double range=0, int pic_idx=0);

        ///R�cup�re la bo�te contenant toutes les informations du sommet par adresse
        grman::WidgetBox& getTopBox();

        void modifier_interface_reduit();
         void adjust_dim_sommet();
};

#endif // VERTEXINTERFACE_H_INCLUDED
