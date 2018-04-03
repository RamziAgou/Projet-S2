#ifndef SOMMET_H_INCLUDED
#define SOMMET_H_INCLUDED

class Sommet
{
private:
    int m_numero;
    int m_indice;
    bool m_marque;
    int m_distPart;
    int m_pred;

public:
    Sommet();
    Sommet(int _numero);
    ~Sommet();

    int getNumero() const;

    int getDistance() const;
    void setDistance(int a);

    int getPred() const;
    void setPred(int a);

    int getIndice() const;      ///ACCESSEUR POUR INDICE
    void setIndice(int a);

    bool getMarque() const;     ///Accesseur POUR MARQUAGE
    void setMarque(bool a);
};

#endif // SOMMET_H_INCLUDED
