#ifndef GRAPHEINTERFACE_H_INCLUDED
#define GRAPHEINTERFACE_H_INCLUDED
#include "grman/grman.h"

class GraphInterface
{
    friend class Graph;

    private :

        /// Les widgets de l'interface. N'oubliez pas qu'il ne suffit pas de d�clarer
        /// ici un widget pour qu'il apparaisse, il faut aussi le mettre en place et
        /// le param�trer ( voir l'impl�mentation du constructeur dans le .cpp )

        /// La boite qui contient toute l'interface d'un graphe
        grman::WidgetBox m_top_box;

        /// Dans cette boite seront ajout�s les (interfaces des) sommets et des arcs...
        grman::WidgetBox m_main_box;

        /// Dans cette boite seront ajout�s des boutons de contr�le etc...
        grman::WidgetBox m_tool_box;

 //       grman::WidgetBox m_boite_boutons;    // Sera la boite � boutons en haut � droite
        grman::WidgetButton m_bouton_sauver;       // Sera le bouton avec le texte NEW
        grman::WidgetButton m_bouton_quitter;

        grman::WidgetText m_bouton_sauver_label1;
        grman::WidgetText m_bouton_sauver_label2;
        grman::WidgetText m_bouton_quitter_label;


        grman::WidgetButton m_bouton_pause;       // Sera le bouton avec l'image de clown m�chant
        grman::WidgetImage m_bouton_pause_image;  // L'image de clown m�chant

        grman::WidgetButton m_bouton_play;       // Sera le bouton avec l'image de clown m�chant
        grman::WidgetImage m_bouton_play_image;

        grman::WidgetText m_bouton_play_pause_label;
        // A compl�ter �ventuellement par des widgets de d�coration ou
        // d'�dition (boutons ajouter/enlever ...)

    public :

        // Le constructeur met en place les �l�ments de l'interface
        // voir l'impl�mentation dans le .cpp
        GraphInterface(int x, int y, int w, int h);

        grman::WidgetButton& get_bouton_sauver();
        grman::WidgetButton& get_bouton_quitter();
        grman::WidgetButton& get_bouton_pause();
        grman::WidgetButton& get_bouton_play();
        grman::WidgetBox& get_tool_box();

        grman::WidgetText& get_bouton_play_pause_label();
};

#endif // GRAPHEINTERFACE_H_INCLUDED
