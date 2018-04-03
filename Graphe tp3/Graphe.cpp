#include "Graphe.h"

Graphe::Graphe()
{

}

Graphe::~Graphe()
{

}

void Graphe::Fichier(std::string fichier)
{
    ///Ouverture d'un fichier en lecture
    std::ifstream fp;
    Sommet* s;

    fp.open(fichier.c_str());

    if(fp)
    {
        int som1;
        int som2;
        int poids;

        fp >> m_ordre;
        fp >> m_nbrArete;

        for(int i=0; i < m_nbrArete ; i++)
        {
            fp >> som1 >> som2 >> poids;
            Arete A(som1, som2, poids);
            m_aretes.push_back(A);

        }
    }

    for(int j=0; j < m_ordre; j++)
    {
        m_sommets.push_back(Sommet(j));
    }
}

void Graphe::Afficher()
{
    std::vector<Arete>::iterator it;
    for(it = m_aretes.begin(); it!= m_aretes.end(); it++)
    {
        (*it).AfficherArete();
    }
}

bool Comparer(const Arete &A,const Arete &B)
{
    return A.getPoids() < B.getPoids();
}

void Graphe::Kruskal()
{
    std::sort(m_aretes.begin(), m_aretes.end(), Comparer); /// TRI DU VECTEUR ARETE

    int nbrArete = 0;

    std::cout << std::endl;

    std::vector<Arete>::iterator it;
    std::vector<Sommet>::iterator jt;



    for(it = m_aretes.begin(); it!= m_aretes.end(); it++)
    {
        if(m_sommets[(*it).getSom1()].getIndice() != m_sommets[(*it).getSom2()].getIndice() && nbrArete != m_ordre -1)
        {
            for(jt = m_sommets.begin(); jt != m_sommets.end(); jt++)
            {
                if((*jt).getIndice() == m_sommets[(*it).getSom1()].getIndice())
                {
                    (*jt).setIndice(m_sommets[(*it).getSom2()].getIndice());
                }
            }
            Arbre.push_back(*it);
            nbrArete++;
        }
    }
}

void Graphe::AfficherArbre()
{
    std::cout << "L'abre est compose de :" << std::endl;
    std::vector<Arete>::iterator it;
    for(it = Arbre.begin(); it!= Arbre.end(); it++)
    {
        (*it).AfficherArete();
    }
}

void Graphe::Dijkstra(int k)
{
    int nbSom = 0;
    int actuel;
    int mini;
    int newDistance;
    int pred;
    std::vector<Sommet>::iterator it;
    std::vector<Arete>::iterator jt;
    for(it = m_sommets.begin(); it!= m_sommets.end(); it++) ///MARQUAGE A 0 ET LONGUEUR A INFINI
    {
        (*it).setMarque(false);
        (*it).setDistance(1000);
    }

    m_sommets[k].setDistance(0);


    while(nbSom < m_ordre)
    {
        mini = 1000;

        for(it = m_sommets.begin(); it!= m_sommets.end(); it++)
        {
            if(!(*it).getMarque() && (*it).getDistance() < mini)    ///ON CHERCHE LE SOMMETS AVEC LA PLUS PETITE DISTANCE PARTIELLE
            {
                actuel = (*it).getNumero();
                mini = (*it).getDistance();
            }
        }

        m_sommets[actuel].setMarque(true); ///On marque le sommet avec la plus petite distance
        nbSom++;


        for(jt = m_aretes.begin(); jt!= m_aretes.end(); jt++)
        {
            if((*jt).getSom1() == actuel && m_sommets[(*jt).getSom2()].getMarque() == false)  ///SI LE SOMMET CEST LE 1 ET QUE LE 2 EST PAS MARQUE
            {
                if(m_sommets[actuel].getDistance()+(*jt).getPoids() < m_sommets[(*jt).getSom2()].getDistance())
                {
                    pred = m_sommets[actuel].getNumero();
                    newDistance = m_sommets[actuel].getDistance()+(*jt).getPoids();
                    m_sommets[(*jt).getSom2()].setDistance(newDistance);
                    m_sommets[(*jt).getSom2()].setPred(pred);
                }
            }

            if((*jt).getSom2() == actuel && m_sommets[(*jt).getSom1()].getMarque() == false)  ///SI LE SOMMET CEST LE 2 ET QUE LE 1 EST PAS MARQUE
            {
                if(m_sommets[actuel].getDistance()+(*jt).getPoids() < m_sommets[(*jt).getSom1()].getDistance())
                {
                    pred = m_sommets[actuel].getNumero();
                    newDistance = m_sommets[actuel].getDistance()+(*jt).getPoids();
                    m_sommets[(*jt).getSom1()].setDistance(newDistance);
                    m_sommets[(*jt).getSom1()].setPred(pred);
                }
            }
        }
    }
}

void Graphe::AfficherPred()
{
    std::cout << "Predecesseur = " << std::endl;
    std::vector<Sommet>::iterator it;
    for(it = m_sommets.begin(); it!= m_sommets.end(); it++)
    {
        std::cout << (*it).getNumero() << " --> " << (*it).getPred() << std::endl;
    }
}
void Graphe::AfficherDijkstra()
{
    int depart;
    int arrive;
    int actuel;
    int somme = 0;
    std::cout << "Vous voulez partir de quelle sommet ? de 0 a " << m_ordre -1 << std::endl;
    std::cin >> depart;
    std::cout << "Vous voulez arrive a quelle sommet ? de 0 a " << m_ordre -1 << std::endl;
    std::cin >> arrive;

    Dijkstra(depart);
    actuel = arrive;
    Chemin.clear();
    Chemin.push_back(actuel);

    while(actuel != depart)
    {
        actuel = m_sommets[actuel].getPred();
        Chemin.insert(Chemin.begin(), actuel);
    }

    std::cout << "Le chemin le plus court en partant de " << depart << " est : ";
    std::vector<int>::iterator it;
    for(it = Chemin.begin(); it!= Chemin.end(); it++)
    {
        std::cout << (*it);
        if((*it)!= arrive)std::cout << "-";
    }

    std::cout << std::endl << "La longueur de ce chemin est de : " << m_sommets[arrive].getDistance() << std::endl;
}

void Graphe::Menu()
{
    int chaine;
    bool fin = false;

    do
    {
        std::cout << "Que voulez-vous ? " << std::endl
                  << "1.Afficher aretes " << std::endl
                  << "2.Trier les aretes par poids croissant " << std::endl
                  << "3.Afficher l'abre de poids minimum (Kruskal) " << std::endl
                  << "4.Calculer le chemin le plus court (Dijkstra) " << std::endl
                  << "5.Quitter et ne pas s'amuser avec ce bon vieux dijkstra" << std::endl;
        std::cin >> chaine;

        switch(chaine)
        {
        case 1:
            Afficher();
            break;

        case 2:
            std::sort(m_aretes.begin(), m_aretes.end(), Comparer);
            Afficher();
            break;

        case 3:
            Kruskal();
            AfficherArbre();
            break;

        case 4:
            AfficherDijkstra();
            break;

        case 5:
            fin = true;
            break;

        default:
            std::cout << "Vous avez surement du vous tromper..." << std::endl << std::endl;
        }
        std::cout << std::endl << std::endl;
    }while(!fin);
}
