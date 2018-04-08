#include "EdgeInterface.h"

EdgeInterface::EdgeInterface(Vertex& from, Vertex& to)
{
    // Le WidgetEdge de l'interface de l'arc
    if ( !(from.m_interface && to.m_interface) )
    {
        std::cerr << "Error creating EdgeInterface between vertices having no interface" << std::endl;
        throw "Bad EdgeInterface instanciation";
    }
    m_top_edge.attach_from(from.m_interface->m_top_box);
    m_top_edge.attach_to(to.m_interface->m_top_box);
    m_top_edge.reset_arrow_with_bullet();
//    m_top_edge.set;
//    m_top_edge.add_item( {grman::ArrowItemType::Arrow, 0.4 }   );
//    m_top_edge.add_item( {grman::ArrowItemType::Arrow, 0.5, 14}   );
    //m_top_edge.add_item( {grman::ArrowItemType::Arrow, 0.6, 14, 1.0 }   );
//    m_top_edge.add_item( {grman::ArrowItemType::, 0.6, 14}   );
//    m_top_edge.add_item( {grman::ArrowItemType::, 0.6, 14, 1.0 }   );

    // Une boite pour englober les widgets de r�glage associ�s
    m_top_edge.add_child(m_box_edge);
    m_box_edge.set_dim(24,15);
    m_box_edge.set_bg_color(BLANCBLEU);

    // Le slider de r�glage de valeur
//    m_box_edge.add_child( m_slider_weight );
//    m_slider_weight.set_range(0.0 , 100.0); // Valeurs arbitraires, � adapter...
//    m_slider_weight.set_dim(16,40);
//    m_slider_weight.set_gravity_y(grman::GravityY::Up);

    // Label de visualisation de valeur
    m_box_edge.add_child( m_label_weight );
    m_label_weight.set_gravity_y(grman::GravityY::Down);
    ///ajout�
    m_top_edge.add_child(m_Ibox_edge);

    m_Ibox_edge.set_frame(-12,16,40,40);
    m_Ibox_edge.add_child(m_image_edge);


}

void EdgeInterface::indicateur_poids()
{
    if(m_slider_weight.get_value()>=0)
    {
        m_top_edge.reset_arrow();
    }

    if(m_slider_weight.get_value()>=10)
    {
        m_top_edge.reset_arrow();
        m_top_edge.add_item( {grman::ArrowItemType::Arrow, 0.9, 14 }   );
    }
    if(m_slider_weight.get_value()>=20)
    {
        m_top_edge.reset_arrow();


        m_top_edge.add_item( {grman::ArrowItemType::Arrow, 0.8, 14 }   );
        m_top_edge.add_item( {grman::ArrowItemType::Arrow, 0.9, 14,}   );

    }
}




