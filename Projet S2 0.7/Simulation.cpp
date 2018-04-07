#include "Simulation.h"


void Simulation()
{
    Graph g;
    g.make_example();
    g.AjouterSommet(1);
    bool fin = false;
    int tempo_visu=0;
    int tempo_visu_max=30;
    int etat;
    /// Vous gardez la main sur la "boucle de jeu"
    /// ( contrairement à des frameworks plus avancés )
    while (!key[KEY_ESC] )
    {


        g.update();
        g.update_simulation();

        ///on verifie si on tourne la boucle de simulation (on est en play quoi)
        if(g.getetat()==1)
        {
            tempo_visu+=1;
            ///on fait un compteur pour attendre que l'utilisateur voit ce qui ce passe (avec tempo_visu)
            if(tempo_visu>tempo_visu_max)
            {
                tempo_visu=0;
                ///on effectu les calculs
                g.maths();
                std::cout<<"_______________________je finis les maths"<<std::endl;
            }
        }


        if(g.getm_interface()->get_bouton_quitter().clicked())
            return;
        grman::mettre_a_jour();

    }
    return;

}
