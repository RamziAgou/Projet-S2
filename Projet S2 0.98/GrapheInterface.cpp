#include "GrapheInterface.h"

/// Ici le constructeur se contente de préparer un cadre d'accueil des
/// éléments qui seront ensuite ajoutés lors de la mise ne place du Graphe
GraphInterface::GraphInterface(int x, int y, int w, int h)
{
     m_top_box.set_dim(1000,740);
    m_top_box.set_gravity_xy(grman::GravityX::Right, grman::GravityY::Up);

    m_top_box.add_child(m_tool_box);
    m_tool_box.set_dim(80,720);
    m_tool_box.set_gravity_xy(grman::GravityX::Left, grman::GravityY::Up);
    m_tool_box.set_bg_color(BLANCBLEU);


    //bouton sauvegarder
    m_tool_box.add_child( m_bouton_sauver );
    m_bouton_sauver.set_frame(3,3,77,60);
    m_bouton_sauver.set_bg_color(BLANC);

    m_bouton_sauver.add_child(m_bouton_sauver_label1);
    m_bouton_sauver_label1.set_frame(14,25,100,100);
    m_bouton_sauver_label1.set_message("Sauve-");
    m_bouton_sauver.add_child(m_bouton_sauver_label2);
    m_bouton_sauver_label2.set_frame(14,35,100,100);
    m_bouton_sauver_label2.set_message("garder");

    //bouton charger
    m_tool_box.add_child( m_bouton_charger );
    m_bouton_charger.set_frame(3,63,77,60);
    m_bouton_charger.set_bg_color(BLANC);
    m_bouton_charger.add_child(m_bouton_charger_label);
    m_bouton_charger_label.set_message("Charger");



    //bouton quitter
    m_tool_box.add_child( m_bouton_quitter );
    m_bouton_quitter.set_frame(3,123,77,60);
    m_bouton_quitter.set_bg_color(BLANC);
    m_bouton_quitter.add_child(m_bouton_quitter_label);
    m_bouton_quitter_label.set_message("Quitter");


    m_tool_box.add_child( m_bouton_pause );
    m_bouton_pause.set_dim(30,30);
    m_bouton_pause.set_gravity_xy(grman::GravityX::Left, grman::GravityY::Down);
    m_bouton_pause.add_child(m_bouton_pause_image);
    m_bouton_pause_image.set_pic_name("bouton_pause.jpg");

    //m_tool_box.add_child( m_bouton_play );
    m_bouton_play.set_dim(30,30);
    m_bouton_play.set_gravity_xy(grman::GravityX::Right, grman::GravityY::Down);
    m_bouton_play.add_child(m_bouton_play_image);
    m_bouton_play_image.set_pic_name("bouton_play.png");


    m_tool_box.add_child( m_bouton_play_pause_label );
    m_bouton_play_pause_label.set_frame(5,675,100,100);
    m_bouton_play_pause_label.set_message("Simulation");

    //m_tool_box.add_child( m_edition_label );
    m_edition_label.set_frame(5,210,100,100);
    m_edition_label.set_message("EDITER :");

    //Edition Sommets
    //m_tool_box.add_child( m_sommet_label );
    m_sommet_label.set_frame(5,230,100,100);
    m_sommet_label.set_message("Sommet");

    //m_tool_box.add_child( m_add_sommet );
    m_add_sommet.set_frame(3,240,35,35);
    m_add_sommet.add_child(m_add_sommet_image);
    m_add_sommet_image.set_pic_name("add_sommet.jpg");

    //m_tool_box.add_child( m_remove_sommet );
    m_remove_sommet.set_frame(47,240,35,35);
    m_remove_sommet.add_child(m_remove_sommet_image);
    m_remove_sommet_image.set_pic_name("remove_sommet.png");

    //m_tool_box.add_child( m_edition_label );
    m_edition_label.set_frame(5,210,100,100);
    m_edition_label.set_message("EDITER :");

    //m_tool_box.add_child( m_sommet_label );
    m_sommet_label.set_frame(5,230,100,100);
    m_sommet_label.set_message("Sommet");




    m_top_box.add_child(m_main_box);
    m_main_box.set_dim(908,720);
    m_main_box.set_gravity_xy(grman::GravityX::Right, grman::GravityY::Up);
    m_main_box.set_bg_color(BLANCJAUNE);

}

void GraphInterface::page_menu()
{
    m_top_box.remove_child(m_tool_box);
    m_main_box.set_frame(0,0,1000,740);
    m_main_box.set_gravity_xy(grman::GravityX::Left,grman::GravityY::Up);
    m_main_box.set_bg_color(SABLESOMBRE);
}

void GraphInterface::dessiner_reduit(std::vector<std::vector<int>> resultat_algo,std::vector<Edge> aretes_a_enlever)
{
    ///enlever la tool box
    m_top_box.remove_child(m_tool_box);

    ///dessiner les trois sommet
    VertexInterface* pt_nouveau_sommet;
    std::string emplacement_photo="Connex.jpg";

    int depart,depart_ajuste;
    int arrive,arrive_ajuste;
    std::vector<VertexInterface*> vecteur_des_interfaces_de_sommet;
    int x=400;
    int y=10;
    int dx=150;
    int dy=150;


    for(int i=0;i<resultat_algo.size();i++)
    {
        if(x>600||x<200)
        {
            dx=-dx;
        }
        if(y<=0||y>500)
        {
            dy=-dy;
        }
        pt_nouveau_sommet= new VertexInterface(i,x+100,y+10,emplacement_photo,0,0);
        pt_nouveau_sommet->modifier_interface_reduit();

        m_top_box.add_child(pt_nouveau_sommet->getTopBox());
        vecteur_des_interfaces_de_sommet.push_back(pt_nouveau_sommet);
        x+=dx;
        y+=dy;
    }

    if(aretes_a_enlever.size()!=0)
    {
        for(int i=0;i<aretes_a_enlever.size();i++)
        {
            depart=aretes_a_enlever[i].getDepart();
            arrive=aretes_a_enlever[i].getArrive();
            for(int y=0;y<resultat_algo.size();y++)
            {
                for(int z=0;z<resultat_algo[y].size();z++)
                {
                    if(depart==resultat_algo[y][z])
                        depart_ajuste=y;
                    if(arrive==resultat_algo[y][z])
                        arrive_ajuste=y;
                }
            }
            ///creer une fleche de depart ajuste à arrive ajuste

            grman::WidgetEdge* pt_nouveau_arc;
            pt_nouveau_arc= new grman::WidgetEdge();
            pt_nouveau_arc->attach_from(vecteur_des_interfaces_de_sommet[depart_ajuste]->m_top_box);
            pt_nouveau_arc->attach_to(vecteur_des_interfaces_de_sommet[arrive_ajuste]->m_top_box);
            pt_nouveau_arc->reset_arrow_with_bullet();
            m_top_box.add_child(*pt_nouveau_arc);
            // EdgeInterface interface_de_larete(*vecteur_des_interfaces_de_sommet[depart_ajuste],*vecteur_des_interfaces_de_sommet[arrive_ajuste]);
            //  m_top_box.add_child();
        }
    }

}

grman::WidgetButton& GraphInterface::get_bouton_pause()
{
    return m_bouton_pause;
}

grman::WidgetButton& GraphInterface::get_bouton_quitter()
{
    return m_bouton_quitter;
}

grman::WidgetButton& GraphInterface::get_bouton_charger()
{
    return m_bouton_charger;
}

grman::WidgetButton& GraphInterface::get_bouton_play()
{
    return m_bouton_play;
}

grman::WidgetButton& GraphInterface::get_bouton_sauver()
{
    return m_bouton_sauver;
}

grman::WidgetBox& GraphInterface::get_tool_box()
{
    return m_tool_box;
}

grman::WidgetText& GraphInterface::get_bouton_play_pause_label()
{
    return m_bouton_play_pause_label;
}

grman::WidgetButton& GraphInterface::get_add_sommet()
{
    return m_add_sommet;
}

grman::WidgetButton& GraphInterface::get_remove_sommet()
{
    return m_remove_sommet;
}

grman::WidgetText& GraphInterface::get_sommet_label()
{
    return m_sommet_label;
}

grman::WidgetText& GraphInterface::get_edition_label()
{
    return m_edition_label;
}

