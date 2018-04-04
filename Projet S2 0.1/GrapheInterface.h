#ifndef GRAPHEINTERFACE_H_INCLUDED
#define GRAPHEINTERFACE_H_INCLUDED
#include "grman/grman.h"

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

        grman::WidgetBox m_boite_boutons;    // Sera la boite à boutons en haut à droite
        grman::WidgetButton m_bouton1;       // Sera le bouton avec le texte NEW
        grman::WidgetButton m_bouton_quitter;

        grman::WidgetText m_bouton1_label1;   // Le texte NEW
        grman::WidgetText m_bouton1_label2;
        grman::WidgetText m_bouton_quitter_label;


        grman::WidgetButton m_bouton_pause;       // Sera le bouton avec l'image de clown méchant
        grman::WidgetImage m_bouton_pause_image;  // L'image de clown méchant

        grman::WidgetButton m_bouton_play;       // Sera le bouton avec l'image de clown méchant
        grman::WidgetImage m_bouton_play_image;
        // A compléter éventuellement par des widgets de décoration ou
        // d'édition (boutons ajouter/enlever ...)

    public :

        // Le constructeur met en place les éléments de l'interface
        // voir l'implémentation dans le .cpp
        GraphInterface(int x, int y, int w, int h);
};

#endif // GRAPHEINTERFACE_H_INCLUDED
