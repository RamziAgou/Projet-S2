#include "Analyse_F_C.h"

void Analyse_F_C(std::string name_ecosys)
{

    int i;

    Graph g;
    g.make_example(name_ecosys);

    bool fin=false;

    ///on extrait les arrete a enlever de l'algo
    std::vector<Edge> lesaretaenlever;
    lesaretaenlever=g.update_F_C();

    ///on créer un bouton pour continuer
    grman::WidgetText suivant_label;
    grman::WidgetButton suivant;

    g.getm_interface()->get_main_box().add_child(suivant);
    suivant.set_frame(700,650,60,40);
    suivant.set_bg_color(BLANCBLEU);

    suivant.add_child(suivant_label);
    suivant_label.set_message("Suivant");



    ///tant qu'on appuie pas sur suivant on affiche le graphe(sans les aretes qui gène
    while(!fin)
    {
        if(suivant.clicked())
            fin=true;
        g.update();
        grman::mettre_a_jour();
    }



    ///là c'est plus compliqué
    ///on recréer une interface(pas un graphe) de graphe

    std::shared_ptr<GraphInterface> reduit;
    reduit = std::make_shared<GraphInterface>(50, 0, 750, 600);

    ///on appele la méthode qui permet de mettre uniquement des sommet correspondant à des ellement de forte connexité et les aretes entre elle
    reduit->dessiner_reduit(g.F_C(),lesaretaenlever);

    ///on change le pointeur d'interface du graphe précedant avec celui qu'on vient de créer
    g.setinterface(reduit);
    fin=false;
    g.getm_interface()->get_main_box().add_child(suivant);
    suivant.set_frame_dim(200,40);
    suivant_label.set_message("Retour au menu");

    ///on affiche tant qu'on appuie pas sur quitter

    while(!fin)
    {
        if(suivant.clicked())
            fin=true;
        g.update();
    std::cout<<"j'ai réussi a uptade le nvx graphe"<<std::endl;
    grman::mettre_a_jour();

    }

}

