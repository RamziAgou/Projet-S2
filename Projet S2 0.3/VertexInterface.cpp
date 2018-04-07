#include "VertexInterface.h"

grman::WidgetBox& VertexInterface::getTopBox()
{
    return m_top_box;
}

VertexInterface::VertexInterface(int idx, int x, int y, std::string pic_name,double range, int pic_idx)
{
    // La boite englobante
    m_top_box.set_pos(x, y);
    m_top_box.set_dim(130, 100);
    m_top_box.set_moveable();

    // Le slider de réglage de valeur
//    m_top_box.add_child( m_slider_value );
//    m_slider_value.set_range(0.0 , range); // Valeurs arbitraires, à adapter...
//    m_slider_value.set_dim(20,80);
//    m_slider_value.set_gravity_xy(grman::GravityX::Left, grman::GravityY::Up);



    // Label de visualisation de valeur
    m_top_box.add_child( m_label_value );
    m_label_value.set_gravity_xy(grman::GravityX::Left, grman::GravityY::Down);

    // Une illustration...
    if (pic_name!="")
    {
        m_top_box.add_child( m_img );
        m_img.set_pic_name(pic_name);
        m_img.set_animate(1);
        m_img.set_pic_idx(pic_idx);
        m_img.set_gravity_x(grman::GravityX::Right);
    }

    // Label de visualisation d'index du sommet dans une boite
    m_top_box.add_child( m_box_label_idx );
    m_box_label_idx.set_gravity_xy(grman::GravityX::Right, grman::GravityY::Down);
    m_box_label_idx.set_dim(20,12);
    m_box_label_idx.set_bg_color(BLANC);

    m_box_label_idx.add_child( m_label_idx );
    m_label_idx.set_message( std::to_string(idx) );

//    m_top_box.add_child( m_delete );
    m_delete.set_gravity_xy(grman::GravityX::Right, grman::GravityY::Up);
    m_delete.set_dim(20,20);
    m_delete.add_child( m_delete_image );
    m_delete_image.set_pic_name("delete.jpg");
}

//Augmente la dimention du sommet pour afficher la valeur entierement
void VertexInterface::adjust_dim_sommet()
{
    if(m_slider_value.get_value()>=10000)
    {
        m_top_box.set_dim(140, 100);
        m_img.set_gravity_x(grman::GravityX::Right);
    }
    else
    {
        m_top_box.set_dim(130, 100);
        m_img.set_gravity_x(grman::GravityX::Right);
    }
}
