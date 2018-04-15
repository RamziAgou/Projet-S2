/*!
 * \file GrapheInterface.h
 * \brief Création d'un écosystème
 * \author Groupe AGOUGILE-CAMUGLI-AVAKIAN
 * \version 1.1
 */

#ifndef GRAPHEINTERFACE_H_INCLUDED
#define GRAPHEINTERFACE_H_INCLUDED
#include "grman/grman.h"
#include <string>
#include <vector>
#include "Edge.h"

/*! \class GrapheInterface
   * \brief classe representant l'interface graphique du graphe
   *
   *  La classe gere l'affichage de la totalité du graphe sur l'écran
   */
class GraphInterface
{
    friend class Graph;

    private :

        /// Les widgets de l'interface. N'oubliez pas qu'il ne suffit pas de déclarer
        /// ici un widget pour qu'il apparaisse, il faut aussi le mettre en place et
        /// le paramétrer ( voir l'implémentation du constructeur dans le .cpp )

        /// La boite qui contient toute l'interface d'un graphe
        grman::WidgetBox m_top_box;

        /// Dans cette boite seront ajoutés les (interfaces des) sommets et des arcs...
        grman::WidgetBox m_main_box;

        /// Dans cette boite seront ajoutés des boutons de contrôle etc...
        grman::WidgetBox m_tool_box;


        ///Bouton permettant d'appuyer sur suivant lors de la k_connexite
        grman::WidgetButton m_bouton_suivant;


        ///Bouton permettant de sauvegarder pendant la simulation
        grman::WidgetButton m_bouton_sauver;
        ///Bouton permettant de quitter pendant la simulation
        grman::WidgetButton m_bouton_quitter;
        ///Bouton permettant de charger pendant la simulation
        grman::WidgetButton m_bouton_charger;
        ///Bouton permettant d'ajouter un sommet pendant la simulation
        grman::WidgetButton m_add_sommet;
        ///Image a mettre sur le bouton ajouter sommet
        grman::WidgetImage m_add_sommet_image;

        ///Bouton permettant de supprimer un sommet pendant la simu
        grman::WidgetButton m_remove_sommet;
        ///Image a mettre sur le bouton supprimer sommet
        grman::WidgetImage m_remove_sommet_image;

        ///Bouton permettant d'ajouter une arete pendant la simu
        grman::WidgetButton m_add_arete;
        ///Image a mettre sur le bouton ajouter arete
        grman::WidgetImage m_add_arete_image;

        ///Bouton permettant de supprimer une arete pendant la simu
        grman::WidgetButton m_remove_arete;
        ///Image a mettre sur le bouton supprimer arete
        grman::WidgetImage m_remove_arete_image;

        ///Texte a mettre dans le bouton sauvegarder
        grman::WidgetText m_bouton_sauver_label1;
        grman::WidgetText m_bouton_sauver_label2;
        ///Texte a mettre dans le bouton quitter
        grman::WidgetText m_bouton_quitter_label;
        ///Texte pour editer sommet
        grman::WidgetText m_sommet_label;
        ///Texte pour editer arete
        grman::WidgetText m_arete_label;

        ///Texte a mettre dans le bouton charger
        grman::WidgetText m_bouton_charger_label;

        ///Bouton permettant de mettre en pause la simulation
        grman::WidgetButton m_bouton_pause;
        ///Image a mettre dans le bouton pause
        grman::WidgetImage m_bouton_pause_image;

        ///Bouton permettant de relancer la simulation
        grman::WidgetButton m_bouton_play;
        ///Image a mettre dans le bouton play
        grman::WidgetImage m_bouton_play_image;

        grman::WidgetText m_bouton_play_pause_label;

        grman::WidgetText m_edition_label;

         bool deja_clique=0;




    public :

        /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe GrapheInterface
     *
     *  \param x : Position en abscisse
        \param y : Position en ordonnee
        \param w : Taille en longueur
        \param h : Taille en largeur
     */
        GraphInterface(int x, int y, int w, int h);

        void page_menu();

        grman::WidgetButton& get_bouton_sauver();
        grman::WidgetButton& get_bouton_quitter();
        grman::WidgetButton& get_bouton_charger();
        grman::WidgetButton& get_bouton_pause();
        grman::WidgetButton& get_bouton_play();
        grman::WidgetButton& get_add_sommet();
        grman::WidgetButton& get_remove_sommet();
        grman::WidgetButton& get_add_arete();
        grman::WidgetButton& get_remove_arete();

        grman::WidgetBox& get_tool_box();


        grman::WidgetBox& get_main_box(){return m_main_box;}


        grman::WidgetText& get_bouton_play_pause_label();
        grman::WidgetText& get_sommet_label();
        grman::WidgetText& get_arete_label();
        grman::WidgetText& get_edition_label();



        void dessiner_reduit(std::vector<std::vector<int>> resultat_algo,std::vector<Edge> aretes_a_enlever);
};

#endif // GRAPHEINTERFACE_H_INCLUDED
