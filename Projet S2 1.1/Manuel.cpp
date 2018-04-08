#include "Manuel.h"

///rtfm
///____________________________________________
///voir acceuil 1 c'est le meme principe qu'ici
///____________________________________________

void Manuel()
{
    ///j'utilise un graphe pour le bouton de sortie
    bool fin;
    fin=false;

    Graph menu;
    menu.make_menu();
    menu.getm_interface()->page_menu();

    grman::WidgetImage image_fond;
    menu.getm_interface()->get_main_box().add_child(image_fond);
    image_fond.set_pic_name("manuel.jpg");

    /// quitter
        grman::WidgetButton quitter;
        grman::WidgetText quitter_label;
        menu.getm_interface()->get_main_box().add_child(quitter);
        quitter.set_frame_dim(50,50);
        quitter.set_bg_color(ROUGE);
        quitter.set_gravity_xy(grman::GravityX::Right,grman::GravityY::Down);
        quitter.add_child(quitter_label);
        quitter_label.set_message("Retour");

    while(!fin)
    {
        menu.update();
        grman::mettre_a_jour();
        if(quitter.clicked())
        {
            fin=true;
        }
    }

}
