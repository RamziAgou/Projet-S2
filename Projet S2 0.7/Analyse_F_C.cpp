#include "Analyse_F_C.h"

void Analyse_F_C()
{

    int i;

    Graph g;
    g.make_example();

    bool fin=false;

    std::vector<Edge> lesaretaenlever;
    lesaretaenlever=g.update_F_C();

    grman::WidgetText suivant_label;
    grman::WidgetButton suivant;

    g.getm_interface()->get_main_box().add_child(suivant);
    suivant.set_frame(800,700,60,40);
    suivant.set_bg_color(BLANCBLEU);

    suivant.add_child(suivant_label);
    suivant_label.set_message("Suivant");



    while(!fin)
    {
        if(suivant.clicked())
            fin=true;
        g.update();
        grman::mettre_a_jour();
    }



    std::shared_ptr<GraphInterface> reduit;
    reduit = std::make_shared<GraphInterface>(50, 0, 750, 600);

    reduit->dessiner_reduit(g.F_C(),lesaretaenlever);
    g.setinterface(reduit);
    fin=false;
    g.getm_interface()->get_main_box().add_child(suivant);
    suivant_label.set_message("Retour au menu");
    suivant.set_frame_dim(200,40);

    while(!fin)
    {
        if(suivant.clicked())
            fin=true;
        g.update();
    std::cout<<"j'ai réussi a uptade le nvx graphe"<<std::endl;
    grman::mettre_a_jour();

    }

}

