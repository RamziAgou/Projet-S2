#include "Sommet.h"

Sommet::Sommet()
{

}

Sommet::Sommet(int _numero)
{
    m_numero = _numero;
    m_indice = _numero;
}

Sommet::~Sommet()
{

}

int Sommet::getNumero() const
{
    return m_numero;
}

bool Sommet::getMarque() const
{
    return m_marque;
}

void Sommet::setMarque(bool a)
{
    m_marque = a;
}

int Sommet::getDistance() const
{
    return m_distPart;
}

void Sommet::setDistance(int a)
{
    m_distPart = a;
}

int Sommet::getPred() const
{
    return m_pred;
}

void Sommet::setPred(int a)
{
    m_pred = a;
}

int Sommet::getIndice() const
{
    return m_indice;
}

void Sommet::setIndice(int a)
{
    m_indice = a;
}
