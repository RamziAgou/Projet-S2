#include "analyse_K_C.h"

bool analyse_K_C(std::string name_ecosys)
{

    Graph g;
    g.make_example(name_ecosys);
    g.getm_interface()->page_menu();
    g.AffichageCombi();
    g.VerifDoublon();
    g.AfficherKConnexe();


    grman::WidgetBox Suivant;
    grman::WidgetText Suivant_label;
    grman::WidgetButton Suivant_bouton;
    grman::WidgetImage Suivant_image;
    Suivant.add_child(Suivant_image);
    Suivant.add_child(Suivant_bouton);
    Suivant.add_child(Suivant_label);
    g.getm_interface()->get_main_box().add_child(Suivant);
    Suivant.set_frame_dim(127,130);
    Suivant.set_gravity_xy(grman::GravityX::Right, grman::GravityY::Down);
    Suivant_bouton.set_frame_dim(121,125);
    Suivant_bouton.set_gravity_xy(grman::GravityX::Left,grman::GravityY::Up);
    Suivant_image.set_pic_name("Suivant.png");

    grman::WidgetButton quitter;
    grman::WidgetText quitter_label;
    g.getm_interface()->get_main_box().add_child(quitter);
    quitter.set_frame_dim(100,50);
    quitter.set_bg_color(ROUGE);
    quitter.set_gravity_xy(grman::GravityX::Right,grman::GravityY::Up);
    quitter.add_child(quitter_label);
    quitter_label.set_message("Exit");

    int numeroCombi = 0;

        g.update();
        grman::mettre_a_jour();

        if(quitter.clicked())
        {
            return true;
        }

        for(unsigned int i=0; i< g.getSommetConnexe()[numeroCombi].size(); i++)
        {
            g.SupprimerSommet(g.getSommetConnexe()[numeroCombi][i]);
        }

        if(Suivant_bouton.clicked())
        {
            for(unsigned int i=0; i< g.getSommetConnexe()[numeroCombi].size(); i++)
            {
                g.AjouterSommet(g.getSommetConnexe()[numeroCombi][i]);
            }
            numeroCombi++;
        }

        if(numeroCombi >= g.getSommetConnexe().size())
        {
            numeroCombi = 0;
        }

        return false;
}
