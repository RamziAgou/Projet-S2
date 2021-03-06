/*!
 * \file Graph.h
 * \brief Cr�ation d'un �cosyst�me
 * \author Groupe AGOUGILE-CAMUGLI-AVAKIAN
 * \version 1.1
 */

#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED


/**************************************************************
    Ici sont propos�es 3 classes fondamentales
            Vertex (=Sommet)
            Edge (=Ar�te ou Arc)
            Graph (=Graphe)

    Les ar�tes et les sommets et le graphe qu'ils constituent
    "travaillent" �troitement ensemble : pour cette raison les
    Vertex et Edge se d�clarent amis (friend) de Graph pour que
    ce dernier puisse librement acc�der aux membres (y compris
    protected ou private) de Vertex et Edge.

    Ces Classes peuvent �tres compl�t�es. Il est �galement possible
    de les d�river mais il est malheureusement assez difficile
    de d�river le "triplet" des 3 classes en maintenant des relations
    coh�rentes ( rechercher "c++ class covariance" et "c++ parallel inheritance"
    pour commencer .. ). Il est donc sans doute pr�f�rable, si possible,
    de "customiser" ces classes de base directement, sans h�ritage.

    Le mod�le propos� permet de repr�senter un graphe orient� �ventuellement
    pond�r�, les arcs portent une ou des informations suppl�mentaire(s).
    Les relations/navigations Arcs -> Sommets et Sommets -> Arcs se font
    dans les 2 sens et utilisent des INDICES et NON PAS DES ADRESSES (pointeurs)
    de telle sorte que la topologie du graphe puisse �tre assez facilement
    lue et �crite en fichier, et b�n�ficie d'une bonne lisibilit� en cas de bugs...

    Chaque arc poss�de 2 attributs principaux (en plus de son �ventuelle pond�ration)
        -> m_from (indice du sommet de d�part de l'arc )
        -> m_to (indice du sommet d'arriv�e de l'arc )

    Chaque sommet poss�de 2 liste d'arcs (en plus de ses attributs "internes", marquages...)
        -> m_in (liste des indices des arcs arrivant au sommet : acc�s aux pr�d�cesseurs)
        -> m_out (liste des indices des arcs partant du sommet : acc�s aux successeurs)

    Cependant le probl�me des indices (par rapport aux pointeurs) et qu'en cas
    de destruction d'une entit� (un arc et/ou un sommet sont enlev�s du graphe) alors :

    - Soit il faut reprendre toute la num�rotation pour "boucher le trou"
      (par exemple on a supprim� le sommet n�4, le sommet n�5 devient le 4, 6 devient 5 etc...)
      ce qui pose des probl�mes de stabilit� et de coh�rence, et une difficult� � r�-introduire
      le(s) m�me(s) �l�ment supprim� (au m�me indice)

    - Soit on admet que la num�rotation des sommets et arcs n'est pas contigue, c�d qu'il
      peut y avoir des "trous" : sommets 0 1 5 7 8, pas de sommets 2 ni 3 ni 4 ni 6. La num�rotation
      est stable mais on ne peut plus utiliser un simple vecteur pour ranger la liste de tous
      les arcs et tous les sommets aux indices correspondants, on peut utiliser une map
      qui associe un objet arc ou sommet � des indices arbitraires (pas forc�ment contigus)

    C'est cette 2�me approche qui est propos�e ici : dans la classe graphe vous trouverez
        -> map<int, Edge>   m_edges
        -> map<int, Vertex> m_vertices    (le pluriel de vertex est vertices)

    Il faudra �tre attentif au fait que par rapport � un simple vecteur, le parcours des �l�ments
    ne pourra PAS se faire avec un simple for (int i=0; i<m_edges.size(); ++i) ...m_edges[i]...
    et que les parcours � it�rateur ne donneront pas directement des Edge ou des Vertex
    mais des pairs, l'objet d'int�r�t se trouvant dans "second" ("first" contenant l'indice)
                for (auto &it = m_edges.begin(); it!=m_edges.end(); ++it) ...it->second...
    ou bien     for (auto &e : m_edges) ...e.second...

    Il n'est pas obligatoire d'utiliser ces classes pour le projet, vous pouvez faire les votres

    Au niveau de l'interface, on dissocie une classe interface associ�e � chaque classe fondamentale
    de telle sorte qu'il soit possible de travailler avec des graphes non repr�sent�s � l'�cran
    Imaginons par exemple qu'on doive g�n�rer 1000 permutations de graphes pour tester des
    combinaisons, on ne souhaite pas repr�senter graphiquement ces 1000 graphes, et les
    interfaces p�sent lourd en ressource, avec cette organisation on est libre de r�server ou
    pas une interface de pr�sentation associ�e aux datas (d�couplage donn�es/interface)

***********************************************************************************************/

#include <map>
#include <string>
#include "Edge.h"
#include "GrapheInterface.h"
#include <fstream>
#include <stack>
#include <vector>
#include <queue>

/*! \class Graph
   * \brief classe representant le graphe
   *
   *  La classe gere la totalit�s des fonctionnalit�s du graphe
   */
class Graph
{
    private :

        /// La "liste" des ar�tes
        std::map<int, Edge> m_edges;

        /// La liste des sommets
        std::map<int, Vertex> m_vertices;

        ///Liste des sommets a supprimer � chaque tour de la k_connexit�
        std::vector<int> m_supprime;

        ///Tableau de toutes les combinaisons r�sultant de la k_connexit�
         std::vector<std::vector<int>> m_sommet_k_connexe;

        /// le POINTEUR sur l'interface associ�e, nullptr -> pas d'interface
        std::shared_ptr<GraphInterface> m_interface = nullptr;

        ///Nom du graphe
        std::string m_name;
        ///Nombre de sommet du graphe
        int m_ordre;
        ///Nombre d'arc du graphe
        int m_nbArc;

        ///Variable permettant de savoir dans quelle menu on se trouve
        int m_etat=0;

        ///Permet de v�rifier la k_connexit�
        int m_maxconnex = 0;


    public:


        /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe Graphe
     *
     *  \param interface : Interface du graphe
     */
        Graph (GraphInterface *interface=nullptr) :
            m_interface(interface)  {  }

        ///Ajoute un sommet au graphe et associe ce sommet � son interface
        void add_interfaced_vertex(int idx, std::string name, double value, int x, int y, std::string pic_name="",double range=0,int popu=0 ,int k_debase=0,double r=0, int pic_idx=0);
        ///Ajoute un arc au graphe et associe cet arc � son interface
        void add_interfaced_edge(int idx, int vert1, int vert2, double weight=0,double range=10);

        ///M�thode qui appelle la lecture du fichier et associe le graphe � une interface
        void make_example(std::string name_ecosys);

        ///Associe le graphe � une interface
        void make_menu();

        ///Permet de charger le graphe : le chargement prend en param�tre le nom du fichier
        void ChargerGraphe(std::string fichier);
        ///Sauvegarde le fichier dans le fichier de l'�cosyst�me actuel
        void SauverGraphe();

        ///Algorithme du BFS pour la connexit�
        void UseBFS(int a, int numero);
        ///Permet de trouver le nombre de composante connexe d'un graphe
        int Connexe();
        ///Permet de trouver le nombre de sommet a enlever pour ne plus etre connexe
        void K_Connexe();
        ///Permet de retirer de potentiel doublon des combinaisons de sommet a enlever pour la k_connexit�
        void VerifDoublon();
        ///M�thode permettant de r�cuperer la combinaison de K element parmi N (N est ici le nombre d'indice des sommets)
        std::vector<std::vector<int>> Combinaison(int K);
        ///Permet d'afficher les combinaisons des k elements parmi n
        void AffichageCombi();
        ///Affichage console du r�sultat de la k_connexit�
        void AfficherKConnexe();

        ///M�thode permettant de savoir si 2 vecteurs sont �gaux
        bool ComparerVect(std::vector<int> a, std::vector<int> b);

        ///Affiche l'�diteur quand l'utilisateur met la simulation en pause
        void afficher_editeur();
        ///Retire l'editeur quand l'utilisateur remet la situation en lecture
        void enlever_editeur();

        /// La m�thode update � appeler dans la boucle de jeu pour les graphes avec interface
        void update(int a=0);
        ///M�thode qui permet � la simulation de tourner
        bool update_simulation();
        std::vector<Edge> update_F_C();

        ///M�thode permettant de supprimer une Arete sans la supprimer de la map
        void SupprimerArete(int a);
        ///M�thode permettant de supprimer un sommet
        void SupprimerSommet(int b);
        ///Supprime un sommet en mettant sa population � 0
        void TuerSommet(int b);

        ///Gere le fichier supprimer permettant de garder en m�moire quelle sommet a �t� supprim�
        void EcrireFichierSupprimer();
        void ChargerSupprimer();

        ///Permet d'ajouter une arete -> utilise quand on ajoute un sommet seulement
        void AjouterArete(int a);
        ///Permet d'ajouter un sommet
        void AjouterSommet(int b);

        ///Permet d'ajouter ou de supprimer une arete ind�pendamment d'un sommet
        void VraiAjouterArete(int a, int b);
        void VraiSupprimerArete(int a);

        std::shared_ptr<GraphInterface> getm_interface() const;

        int getetat(){return m_etat;}

        int getOrdre() const;
        int getNbArc() const;
        std::string getName() const;
        void setOrdre(int a);
        void setNbArc(int a);
        void setName(std::string a);

        void setinterface(std::shared_ptr<GraphInterface> le_pt){m_interface=le_pt;}

        std::map<int, Vertex>& getMapVertex();
        std::map<int, Edge>& getMapEdge();

        std::vector<std::vector<int>>& getSommetConnexe(){return m_sommet_k_connexe;}

        ///algorithme de forte connexit�
        std::vector<std::vector<int>> F_C();

        ///tour de boucle
        void maths();
};


#endif // GRAPH_H_INCLUDED
