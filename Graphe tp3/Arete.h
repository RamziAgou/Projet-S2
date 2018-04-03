#ifndef ARETE_H_INCLUDED
#define ARETE_H_INCLUDED
#include <iostream>

class Arete
{
private:
    int m_som1;
    int m_som2;
    int m_poids;

public:
    Arete();
    Arete(int _som1, int _som2, int _poids);
    ~Arete();

    void AfficherArete();
    int getPoids() const;
    int getSom1() const;
    int getSom2() const;
};

#endif // ARETE_H_INCLUDED
