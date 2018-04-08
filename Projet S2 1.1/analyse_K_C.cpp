#include "analyse_K_C.h"

bool analyse_K_C(std::string name_ecosys)
{

    bool fin = false;

    ///On créer le graphe
    Graph g;
    g.make_example(name_ecosys);
    g.getm_interface()->page_menu();

    ///On affiche les Combinaisons, effectue l'algo de k_connexité puis on l'affiche sur la console
    g.AffichageCombi();
    g.VerifDoublon();
    g.AfficherKConnexe();


    ///Mise en place de l'affichage graphique
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

    ///Variable permettant de changer de combinaison de k_connexité
    int numeroCombi = 0;

    while(!fin)
    {
        g.update();
        grman::mettre_a_jour();

        ///Si on appuye sur le bouton quitter on quitte le sousprogramme
        if(quitter.clicked())
        {
            fin = true;
        }

        ///On supprimes les sommets formant la combinaisons pour pouvoir afficher que le graphe restant
        for(unsigned int i=0; i< g.getSommetConnexe()[numeroCombi].size(); i++)
        {
            g.SupprimerSommet(g.getSommetConnexe()[numeroCombi][i]);
        }

        ///Si on clique sur suivant on rajoute tous les sommets supprimés et on change de combinaisons
        if(Suivant_bouton.clicked())
        {
            for(unsigned int i=0; i< g.getSommetConnexe()[numeroCombi].size(); i++)
            {
                g.AjouterSommet(g.getSommetConnexe()[numeroCombi][i]);
            }
            numeroCombi++;
        }

        ///Permet de boucler quand on arrive a la derniere combinaison on revient a la premiere
        if(numeroCombi >= g.getSommetConnexe().size())
        {
            numeroCombi = 0;
        }
    }

        return false;
}
