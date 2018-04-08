#include "Acceuil2.h"

///on choisit ici l'ecosysteme (on voit donc les trois ecosystem (avec leurs descriptions)
///ou on atteint le manuel
///ou on quitte le programme
///menu mère
bool Acceuil2()
{
    bool fin;
    fin=false;


    ///création d'un graph adapter au menu (sans tool box et sans sommet)
    Graph menu;
    menu.make_menu();
    menu.getm_interface()->page_menu();


    ///image du fond
    grman::WidgetImage image_fond;
    menu.getm_interface()->get_main_box().add_child(image_fond);
    image_fond.set_pic_name("fond.jpg");




    ///bouton pour le premier ecosystème basique avec une box, un bouton, un label et une image
        grman::WidgetBox basique;
        grman::WidgetText basique_label;
        grman::WidgetButton basique_bouton;
        grman::WidgetImage basique_image;
        basique.add_child(basique_image);
        basique.add_child(basique_bouton);
        basique.add_child(basique_label);
        menu.getm_interface()->get_main_box().add_child(basique);
        basique_bouton.set_frame_dim(195,195);
        basique_bouton.set_gravity_xy(grman::GravityX::Left,grman::GravityY::Up);
        basique.set_frame_dim(200,200);
        basique.set_frame_pos(200,200);
        basique_image.set_pic_name("basique.jpg");
        basique_label.set_message("Ecosystème numéro 1");
        basique_label.set_gravity_xy(grman::GravityX::Left,grman::GravityY::Up);


    ///bouton pour le deuxième ecosystème Marin avec une box, un bouton, un label et une image
        grman::WidgetBox Marin;
        grman::WidgetText Marin_label;
        grman::WidgetButton Marin_bouton;
        grman::WidgetImage Marin_image;
        Marin.add_child(Marin_image);
        Marin.add_child(Marin_bouton);
        Marin.add_child(Marin_label);
        menu.getm_interface()->get_main_box().add_child(Marin);
        Marin_bouton.set_frame_dim(195,195);
        Marin_bouton.set_gravity_xy(grman::GravityX::Left,grman::GravityY::Up);
        Marin.set_frame_dim(200,200);
        Marin.set_frame_pos(450,200);
        Marin_image.set_pic_name("Marin.jpg");
        Marin_label.set_message("Ecosystème numéro 2");
        Marin_label.set_gravity_xy(grman::GravityX::Left,grman::GravityY::Up);

    ///bouton pour le troisième ecosystème foret avec une box, un bouton, un label et une image
        grman::WidgetBox Foret_boreale;
        grman::WidgetText Foret_boreale_label;
        grman::WidgetButton Foret_boreale_bouton;
        grman::WidgetImage Foret_boreale_image;
        Foret_boreale.add_child(Foret_boreale_image);
        Foret_boreale.add_child(Foret_boreale_bouton);
        Foret_boreale.add_child(Foret_boreale_label);
        menu.getm_interface()->get_main_box().add_child(Foret_boreale);
        Foret_boreale_bouton.set_frame_dim(195,195);
        Foret_boreale_bouton.set_gravity_xy(grman::GravityX::Left,grman::GravityY::Up);
        Foret_boreale.set_frame_dim(200,200);
        Foret_boreale.set_frame_pos(700,200);
        Foret_boreale_image.set_pic_name("Foret_boreale.jpg");
        Foret_boreale_label.set_message("Ecosystème numéro 3");
        Foret_boreale_label.set_gravity_xy(grman::GravityX::Left,grman::GravityY::Up);

    ///bouton pour le dernier ecosystème forte_connex avec une box, un bouton, un label et une image
        grman::WidgetBox forte_connex;
        grman::WidgetText forte_connex_label;
        grman::WidgetButton forte_connex_bouton;
        grman::WidgetImage forte_connex_image;
        forte_connex.add_child(forte_connex_image);
        forte_connex.add_child(forte_connex_bouton);
        forte_connex.add_child(forte_connex_label);
        menu.getm_interface()->get_main_box().add_child(forte_connex);
        forte_connex_bouton.set_frame_dim(195,195);
        forte_connex_bouton.set_gravity_xy(grman::GravityX::Left,grman::GravityY::Up);
        forte_connex.set_frame_dim(200,200);
        forte_connex.set_frame_pos(700,450);
        forte_connex_image.set_pic_name("forte.jpg");
        forte_connex_label.set_message("Ecosystème numéro 4");
        forte_connex_label.set_gravity_xy(grman::GravityX::Left,grman::GravityY::Up);

    ///bouton pour acceder au Manuel
        grman::WidgetBox manuel;

        grman::WidgetButton manuel_bouton;
        grman::WidgetImage manuel_image;
        manuel.add_child(manuel_image);
        manuel.add_child(manuel_bouton);

        menu.getm_interface()->get_main_box().add_child(manuel);
        manuel_bouton.set_frame_dim(195,195);
        manuel_bouton.set_gravity_xy(grman::GravityX::Left,grman::GravityY::Up);
        manuel.set_frame_dim(200,200);
        manuel.set_frame_pos(200,450);
        manuel_image.set_pic_name("manuel_menu.jpg");



    /// bouton pour quitter
        grman::WidgetButton quitter;
        grman::WidgetText quitter_label;
        menu.getm_interface()->get_main_box().add_child(quitter);
        quitter.set_frame_dim(50,50);
        quitter.set_bg_color(ROUGE);
        quitter.set_gravity_xy(grman::GravityX::Right,grman::GravityY::Down);
        quitter.add_child(quitter_label);
        quitter_label.set_message("Exit");

    ///tant qu'on quitte pas le logiciel on affiche le graphe et on met à jour les widget et l'etat de la souris
    while(!fin)
    {
        menu.update();
        grman::mettre_a_jour();
        ///si un bouton est cliqué on accède à la fonction correspondante
        if(quitter.clicked())
        {
            fin=true;
        }
        if(basique_bouton.clicked())
        {
             std::cout<<"c'est cliqué 1"<<std::endl;
             Menu1("basique");

        }
        if(Marin_bouton.clicked())
        {
            std::cout<<"c'est cliqué 2"<<std::endl;
            Menu1("Marin");
        }
        if(Foret_boreale_bouton.clicked())
        {
             std::cout<<"c'est cliqué 3"<<std::endl;
             Menu1("Foret_boreale");
        }
        if(manuel_bouton.clicked())
        {
            std::cout<<"c'est cliqué manuel"<<std::endl;
            Manuel();
        }
        if(forte_connex_bouton.clicked())
        {
             std::cout<<"c'est cliqué 4"<<std::endl;
             Menu1("forte_connex");
        }


    }
}

