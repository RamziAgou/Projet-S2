#include "Vertex.h"

std::string Vertex::getName() const
{
    return m_nom;
}

std::shared_ptr<VertexInterface>& Vertex::getInterVertex()
{
    return m_interface;
}

double Vertex::getX()
{
    return getInterVertex()->getTopBox().get_frame().pos.x;
}

double Vertex::getY()
{
   return getInterVertex()->getTopBox().get_frame().pos.y;
}

double Vertex::getRange() const
{
    return m_range;
}

void Vertex::setRange(double a)
{
    m_range = a;
}

/// Le constructeur met en place les éléments de l'interface
void Vertex::pre_update()
{
    if (!m_interface)
        return;

    /// Copier la valeur locale de la donnée m_value vers le slider associé
    m_interface->m_slider_value.set_value(m_popul);

    /// Copier la valeur locale de la donnée m_value vers le label sous le slider
    m_interface->m_label_value.set_message( std::to_string( (int)m_popul) );
}

void Vertex::AfficherArc()
{
    std::vector<int>::iterator it;
    for(it = m_out.begin(); it != m_out.end(); it++)
    {
        std::cout << "Indice : " << getIdx() << std::endl;
        std::cout << "INDICE ARC SORTANT = " << (*it) << std::endl;
    }

    for(it = m_in.begin(); it != m_in.end(); it++)
    {
        std::cout << "INDICE ARC ENTRANT = " << (*it) << std::endl;
    }
}
void Vertex::setIdx(int a)
{
    m_idx = a;
}

int Vertex::getPopu() const
{
    return m_popul;
}

void Vertex::setPopu(int a)
{
    m_popul = a;
}

int Vertex::getIdx() const
{
    return m_idx;
}

/// Gestion du Vertex après l'appel à l'interface
void Vertex::post_update()
{
    if (!m_interface)
        return;



    /// Reprendre la valeur du slider dans la donnée m_value locale
    setPopu(m_interface->m_slider_value.get_value());
}
/// Gestion du Vertex avant l'appel à l'interface
