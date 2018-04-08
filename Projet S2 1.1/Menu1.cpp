#include "Menu1.h"

///____________________________________________
///voir acceuil 1 c'est le meme principe qu'ici
///____________________________________________

/// simulation ou annalyse
void Menu1(std::string name_ecosys)
{
    Graph menu;
    menu.make_menu();
    menu.getm_interface()->page_menu();
    grman::WidgetImage image_fond;
    menu.getm_interface()->get_main_box().add_child(image_fond);
    image_fond.set_pic_name("fond.jpg");
    bool fin=false;


    ///analyse
        grman::WidgetBox Analyse;

        grman::WidgetButton Analyse_bouton;
        grman::WidgetImage Analyse_image;
        Analyse.add_child(Analyse_image);
        Analyse.add_child(Analyse_bouton);

        menu.getm_interface()->get_main_box().add_child(Analyse);
        Analyse_bouton.set_frame_dim(615,295);
        Analyse_bouton.set_gravity_xy(grman::GravityX::Left,grman::GravityY::Up);
        Analyse.set_frame_dim(620,300);
        Analyse.set_frame_pos(200,100);
        Analyse_image.set_pic_name("Analyse.jpg");


    ///simu
        grman::WidgetBox simu;

        grman::WidgetButton simu_bouton;
        grman::WidgetImage simu_image;
        simu.add_child(simu_image);
        simu.add_child(simu_bouton);

        menu.getm_interface()->get_main_box().add_child(simu);
        simu_bouton.set_frame_dim(615,295);
        simu_bouton.set_gravity_xy(grman::GravityX::Left,grman::GravityY::Up);
        simu.set_frame_dim(620,300);
        simu.set_frame_pos(200,400);
        simu_image.set_pic_name("simu.jpg");

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
        if(simu_bouton.clicked())
        {
            Simulation(name_ecosys);
        }
        if(Analyse_bouton.clicked())
        {
            Analyse1(name_ecosys);
        }
        if(retour.clicked())
        {
            return;
        }
    }

}
