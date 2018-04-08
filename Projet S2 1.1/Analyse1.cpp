#include "Analyse1.h"

///____________________________________________
///voir acceuil 2 c'est le meme principe qu'ici
///____________________________________________
void Analyse1(std::string name_ecosys)
{
        Graph menu;
        menu.make_menu();
        menu.getm_interface()->page_menu();
        grman::WidgetImage image_fond;
        menu.getm_interface()->get_main_box().add_child(image_fond);
        image_fond.set_pic_name("fond.jpg");
        bool fin=false;


    ///forte_connex
        grman::WidgetBox forte_connex;

        grman::WidgetButton forte_connex_bouton;
        grman::WidgetImage forte_connex_image;
        forte_connex.add_child(forte_connex_image);
        forte_connex.add_child(forte_connex_bouton);

        menu.getm_interface()->get_main_box().add_child(forte_connex);
        forte_connex_bouton.set_frame_dim(615,295);
        forte_connex_bouton.set_gravity_xy(grman::GravityX::Left,grman::GravityY::Up);
        forte_connex.set_frame_dim(620,300);
        forte_connex.set_frame_pos(200,100);
        forte_connex_image.set_pic_name("forte_connex.jpg");


    ///K_connex
        grman::WidgetBox K_connex;

        grman::WidgetButton K_connex_bouton;
        grman::WidgetImage K_connex_image;
        K_connex.add_child(K_connex_image);
        K_connex.add_child(K_connex_bouton);

        menu.getm_interface()->get_main_box().add_child(K_connex);
        K_connex_bouton.set_frame_dim(615,295);
        K_connex_bouton.set_gravity_xy(grman::GravityX::Left,grman::GravityY::Up);
        K_connex.set_frame_dim(620,300);
        K_connex.set_frame_pos(200,400);
        K_connex_image.set_pic_name("K_connex.jpg");

    /// retour
        grman::WidgetButton retour;
        grman::WidgetText retour_label;
        menu.getm_interface()->get_main_box().add_child(retour);
        retour.set_frame_dim(50,50);
        retour.set_bg_color(ROUGE);
        retour.set_gravity_xy(grman::GravityX::Right,grman::GravityY::Down);
        retour.add_child(retour_label);
        retour_label.set_message("Retour");


        while(!fin)
    {
        menu.update();
        grman::mettre_a_jour();
        if(forte_connex_bouton.clicked())
        {
            Analyse_F_C(name_ecosys);
        }
        if(K_connex_bouton.clicked())
        {
            analyse_K_C(name_ecosys);
        }
        if(retour.clicked())
        {
            return;
        }
    }
}

