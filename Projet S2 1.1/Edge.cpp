/*!
 * \file Edge.cpp
 * \brief Cr�ation d'un �cosyst�me
 * \author Groupe AGOUGILE-CAMUGLI-AVAKIAN
 * \version 1.1
 */

#include "Edge.h"



void Edge::pre_update()
{
    if (!m_interface)
        return;

    /// Copier la valeur locale de la donn�e m_weight vers le slider associ�
    m_interface->m_slider_weight.set_value(m_poids);

    /// Copier la valeur locale de la donn�e m_weight vers le label sous le slider
    m_interface->m_label_weight.set_message( std::to_string( (double)m_poids ) );
}

std::shared_ptr<EdgeInterface>& Edge::getInterEdge()
{
    return m_interface;
}

/// Gestion du Edge apr�s l'appel � l'interface
void Edge::post_update()
{
    if (!m_interface)
        return;

    /// Reprendre la valeur du slider dans la donn�e m_weight locale
    m_poids = m_interface->m_slider_weight.get_value();
}

int Edge::getArrive() const
{
    return m_to;
}

void Edge::setArrive(int a)
{
    m_to = a;
}

void Edge::setDepart(int a)
{
    m_from = a;
}

int Edge::getDepart() const
{
    return m_from;
}

double Edge::getPoids() const
{
    return m_poids;
}
