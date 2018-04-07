#ifndef GRAPHEINTERFACE_H_INCLUDED
#define GRAPHEINTERFACE_H_INCLUDED
#include "grman/grman.h"
#include <string>
#include <vector>
#include "Edge.h"

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


        grman::WidgetButton m_bouton_suivant;


        grman::WidgetButton m_bouton_sauver;
        grman::WidgetButton m_bouton_quitter;
        grman::WidgetButton m_bouton_charger;
        grman::WidgetButton m_add_sommet;
        grman::WidgetImage m_add_sommet_image;

        grman::WidgetButton m_remove_sommet;
        grman::WidgetImage m_remove_sommet_image;

        grman::WidgetText m_bouton_sauver_label1;
        grman::WidgetText m_bouton_sauver_label2;
        grman::WidgetText m_bouton_quitter_label;
        grman::WidgetText m_sommet_label;

        grman::WidgetText m_bouton_charger_label;

        grman::WidgetButton m_bouton_pause;
        grman::WidgetImage m_bouton_pause_image;

        grman::WidgetButton m_bouton_play;
        grman::WidgetImage m_bouton_play_image;

        grman::WidgetText m_bouton_play_pause_label;

        grman::WidgetText m_edition_label;

         bool deja_clique=0;
        // A compléter éventuellement par des widgets de décoration ou
        // d'édition (boutons ajouter/enlever ...)




    public :

        // Le constructeur met en place les éléments de l'interface
        // voir l'implémentation dans le .cpp
        GraphInterface(int x, int y, int w, int h);

        void page_menu();

        grman::WidgetButton& get_bouton_sauver();
        grman::WidgetButton& get_bouton_quitter();
        grman::WidgetButton& get_bouton_charger();
        grman::WidgetButton& get_bouton_pause();
        grman::WidgetButton& get_bouton_play();
        grman::WidgetButton& get_add_sommet();
        grman::WidgetButton& get_remove_sommet();

        grman::WidgetBox& get_tool_box();


        grman::WidgetBox& get_main_box(){return m_main_box;}


        grman::WidgetText& get_bouton_play_pause_label();
        grman::WidgetText& get_sommet_label();
        grman::WidgetText& get_edition_label();



        void dessiner_reduit(std::vector<std::vector<int>> resultat_algo,std::vector<Edge> aretes_a_enlever);
};

#endif // GRAPHEINTERFACE_H_INCLUDED
