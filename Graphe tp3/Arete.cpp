#include "Arete.h"

Arete::Arete()
{

}

Arete::Arete(int _som1, int _som2, int _poids)
{
    m_som1 = _som1;
    m_som2 = _som2;
    m_poids = _poids;
}

Arete::~Arete()
{

}

void Arete::AfficherArete()
{
    std::cout << m_som1 << "-" << m_som2 << "|" << m_poids << std::endl;
}

int Arete::getPoids() const
{
    return m_poids;
}

int Arete::getSom1() const
{
    return m_som1;
}

int Arete::getSom2() const
{
    return m_som2;
}
