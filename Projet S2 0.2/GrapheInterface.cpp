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


    m_tool_box.add_child( m_bouton_sauver );
    m_bouton_sauver.set_frame(3,3,77,60);
    //m_boite_boutons.set_gravity_xy(grman::GravityX::Right, grman::GravityY::Up );
    m_bouton_sauver.set_bg_color(BLANC);

    //bouton sauvegarder
    m_bouton_sauver.add_child(m_bouton_sauver_label1);
    m_bouton_sauver_label1.set_frame(14,25,100,100);
    m_bouton_sauver_label1.set_message("Sauve-");
    m_bouton_sauver.add_child(m_bouton_sauver_label2);
    m_bouton_sauver_label2.set_frame(14,35,100,100);
    m_bouton_sauver_label2.set_message("garder");

    //bouton quitter
    m_tool_box.add_child( m_bouton_quitter );
    m_bouton_quitter.set_frame(3,63,77,60);
    m_bouton_quitter.set_bg_color(BLANC);
    m_bouton_quitter.add_child(m_bouton_quitter_label);
    m_bouton_quitter_label.set_message("Quitter");


    m_tool_box.add_child( m_bouton_pause );
    m_bouton_pause.set_dim(30,30);
    m_bouton_pause.set_gravity_xy(grman::GravityX::Left, grman::GravityY::Down);
    m_bouton_pause.add_child(m_bouton_pause_image);
    m_bouton_pause_image.set_pic_name("bouton_pause.jpg");

    m_tool_box.add_child( m_bouton_play );
    m_bouton_play.set_dim(30,30);
    m_bouton_play.set_gravity_xy(grman::GravityX::Right, grman::GravityY::Down);
    m_bouton_play.add_child(m_bouton_play_image);
    m_bouton_play_image.set_pic_name("bouton_play.png");

    m_tool_box.add_child( m_bouton_play_pause_label );
    m_bouton_play_pause_label.set_frame(5,675,100,100);
    m_bouton_play_pause_label.set_message("Simulation");


    //m_bouton_play_pause_label.set_message("Sauve-");


    m_top_box.add_child(m_main_box);
    m_main_box.set_dim(908,720);
    m_main_box.set_gravity_xy(grman::GravityX::Right, grman::GravityY::Up);
    m_main_box.set_bg_color(BLANCJAUNE);


}

grman::WidgetButton& GraphInterface::get_bouton_pause()
{
    return m_bouton_pause;
}

grman::WidgetButton& GraphInterface::get_bouton_quitter()
{
    return m_bouton_quitter;
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
