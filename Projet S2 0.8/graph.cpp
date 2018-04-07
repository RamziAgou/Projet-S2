#include "graph.h"

///c bon

void Graph::maths()
{
    std::cout<<"je rentre dans maths"<<std::endl;
    int i=0;
    int ktempo;
    for(i=0;i<m_vertices.size();i++)
    {
        std::cout<<"je regarde le sommet"<<i<<std::endl;
        std::cout<<"sa pop est de: "<<m_vertices[i].m_popul<<std::endl;
        m_vertices[i].m_popul_moins_un=m_vertices[i].m_popul;
        std::cout<<"sa popmoins_un est de: "<<m_vertices[i].m_popul_moins_un<<std::endl;
    }
    for(auto elem : m_vertices)
    {
        ktempo=0;
        std::cout<<"je regarde le sommet"<<elem.first<<std::endl;
        std::cout<<"        son K est de "<<m_vertices[elem.first].m_K<<std::endl;
        std::cout<<"        son Kde base est de "<<m_vertices[elem.first].m_Kdebase<<std::endl;
        m_vertices[elem.first].m_K=m_vertices[elem.first].m_Kdebase;
        std::cout<<"        son K est maintenant de "<<m_vertices[elem.first].m_K<<std::endl;
        if(m_vertices[elem.first].m_in.size()!=0)
        {
            std::cout<<"il mange "<<m_vertices[elem.first].m_in.size()<<"animal"<<std::endl;
            for(int y=0;y<m_vertices[elem.first].m_in.size();y++)
            {
                std::cout<<"le coef de l'arrete est de"<<m_edges[m_vertices[elem.first].m_in[y]].getPoids()<<std::endl;
                std::cout<<"    la population de l'animal mangé est de"<<m_vertices[m_edges[m_vertices[elem.first].m_in[y]].getDepart()].m_popul_moins_un<<std::endl;
                if(m_edges[m_vertices[elem.first].m_in[y]].getPoids()!=0)
                    ktempo+=(double)((double)1/(double)m_edges[m_vertices[elem.first].m_in[y]].getPoids())*(double)m_vertices[m_edges[m_vertices[elem.first].m_in[y]].getDepart()].m_popul_moins_un;

                std::cout<<"    ktempo vaut:"<<ktempo<<std::endl;
            }

        m_vertices[elem.first].m_K+=ktempo;
        std::cout<<"ainsi le nouveau K vaut"<<m_vertices[elem.first].m_K<<std::endl<<std::endl;
        }
    }
    std::cout<<"les K finit"<<std::endl;
    std::cout<<"je modifie les populations"<<std::endl;
    for(auto elem : m_vertices)
    {
        std::cout<<elem.first<<" est le sommet que je regarde"<<std::endl;

        if(!m_vertices[elem.first].m_K==0)
        {
            std::cout<<m_vertices[elem.first].m_popul<<"="<<m_vertices[elem.first].m_popul<<"+"<<m_vertices[elem.first].m_r<<"*"<<m_vertices[elem.first].m_popul<<"*(1-"<<m_vertices[elem.first].m_popul<<"/"<<m_vertices[elem.first].m_K<<")"<<std::endl;
            m_vertices[elem.first].m_popul=(double)m_vertices[elem.first].m_popul+(double)m_vertices[elem.first].m_r*(double)m_vertices[elem.first].m_popul*(double)((double)1-(double)((double)((double)m_vertices[elem.first].m_popul)/(double)m_vertices[elem.first].m_K));
        }
        else
        {
            std::cout<<m_vertices[elem.first].m_popul<<"="<<m_vertices[elem.first].m_popul<<"+"<<m_vertices[elem.first].m_r<<"*"<<m_vertices[elem.first].m_popul<<"*(1-"<<m_vertices[elem.first].m_popul<<"/0.5)"<<std::endl;
            m_vertices[elem.first].m_popul=(double)m_vertices[elem.first].m_popul+(double)m_vertices[elem.first].m_r*(double)m_vertices[elem.first].m_popul*(double)((double)1-(double)((double)((double)m_vertices[elem.first].m_popul)/(double)0.5));
        }
        std::cout<<"population apres agrandissement:"<<m_vertices[elem.first].m_popul<<std::endl;
        if(m_vertices[elem.first].m_out.size()!=0)
        {
            for(int y=0;y<m_vertices[elem.first].m_out.size();y++)
            {
                std::cout<<"    population se fait manger par le sommet:"<<m_vertices[elem.first].m_out[y]<<std::endl;
                std::cout<<"ils en mange :"<<m_edges[m_vertices[elem.first].m_out[y]].m_poids*m_vertices[m_edges[m_vertices[elem.first].m_out[y]].m_to].getPopu()<<std::endl;
                m_vertices[elem.first].m_popul-=m_edges[m_vertices[elem.first].m_out[y]].m_poids*m_vertices[m_edges[m_vertices[elem.first].m_out[y]].m_to].getPopu();

            }
        }
        std::cout<<"____la population finale est :"<<m_vertices[elem.first].m_popul<<std::endl;
        if(m_vertices[elem.first].m_popul<=0)
        {
            m_vertices[elem.first].m_popul=0;
        }
    }
    std::cout<<"les N finit"<<std::endl;
}

std::shared_ptr<GraphInterface> Graph::getm_interface() const
{
    return m_interface;
}

int Graph::getNbArc() const
{
    return m_nbArc;
}

int Graph::getOrdre() const
{
    return m_ordre;
}

void Graph::setNbArc(int a)
{
    m_nbArc = a;
}

void Graph::setOrdre(int a)
{
    m_ordre = a;
}

std::string Graph::getName() const
{
    return m_name;
}

void Graph::setName(std::string a)
{
    m_name = a;
}

void Graph::AjouterArete(int a)
{
    Edge &deledge = m_edges[a];
    std::vector<int>& vedepart = m_vertices[deledge.m_from].m_out;
    std::vector<int>& vearrive = m_vertices[deledge.m_to].m_in;

    if(m_interface && deledge.m_interface)
    {
        m_interface->m_main_box.add_child(deledge.m_interface->m_top_edge);
    }

    for(auto elem : m_vertices)
    {
        if(elem.second.m_idx == deledge.m_from)
        {
            vedepart.push_back(a);
        }

        if(elem.second.m_idx == deledge.m_to)
        {
            vearrive.push_back(a);
        }
    }
}

void Graph::SupprimerArete(int a)
{
    Edge &deledge = m_edges[a];
    std::vector<int>& vedepart = m_vertices[deledge.m_from].m_out;
    std::vector<int>& vearrive = m_vertices[deledge.m_to].m_in;

    if(m_interface && deledge.m_interface)
    {
        m_interface->m_main_box.remove_child(deledge.m_interface->m_top_edge);
    }

    std::vector<int>::iterator it;
    for(it = vedepart.begin(); it != vedepart.end(); it++)
    {
        if((*it) == a)
        {
            vedepart.erase(it);
            it--;
        }
    }

    for(it = vearrive.begin(); it != vearrive.end(); it++)
    {
        if((*it) == a)
        {
            vearrive.erase(it);
            it--;
        }
    }
}

void Graph::AjouterSommet(int b)
{
    m_vertices[b].actif = true;
    std::vector<int>::iterator it;
    for(it = m_supprime.begin(); it!= m_supprime.end(); it++)
    {
        if((*it)==b)
        {
            m_supprime.erase(it);
            it--;
        }
    }
    Vertex &delVer = m_vertices[b];

    if(m_interface && delVer.m_interface)
    {
        m_interface->m_main_box.add_child(delVer.m_interface->m_top_box);
    }

    for(auto elem : m_edges)
    {
        if(elem.second.m_from == b)
        {
            if(m_vertices[elem.second.m_to].actif)
            {
                AjouterArete(elem.first);
            }
        }
        if(elem.second.m_to == b)
        {
            if(m_vertices[elem.second.m_from].actif)
            {
                AjouterArete(elem.first);
            }
        }
    }
}

void Graph::SupprimerSommet(int b)
{
    Vertex &delVer = m_vertices[b];
    m_vertices[b].actif = false;

    if(m_interface && delVer.m_interface)
    {
        m_interface->m_main_box.remove_child(delVer.m_interface->m_top_box);
    }

    std::vector<int>::iterator it;
    for(it = delVer.m_out.begin(); it != delVer.m_out.end(); it++)
    {
        SupprimerArete(*it);
        it--;
    }

    for(it = delVer.m_in.begin(); it != delVer.m_in.end(); it++)
    {
        SupprimerArete(*it);
        it--;
    }


    std::cout << "Vous avez supprime le/la : " << m_vertices[b].getName() << std::endl;

}

void Graph::ChargerSupprimer()
{
    m_supprime.clear();
    std::ifstream fp2;
    std::string fichier2 = m_name + "Supprimer.txt";
    fp2.open(fichier2.c_str());

    if(fp2)
    {
        int nbSupp;
        int indice;
        fp2 >> nbSupp;

        for(int i=0; i< nbSupp; i++)
        {
            fp2 >> indice;
            m_supprime.push_back(indice);
        }
    }

    for(unsigned int i=0; i< m_supprime.size(); i++)
    {
        SupprimerSommet(m_supprime[i]);
    }
}

void Graph::EcrireFichierSupprimer()
{
    std::ofstream fp(m_name + "Supprimer.txt");

    if(fp)
    {
        fp << m_supprime.size() << std::endl;
        std::vector<int>::iterator it;
        for(it = m_supprime.begin(); it!= m_supprime.end(); it++)
        {
            fp << m_vertices[*it].m_idx << std::endl;
        }
    }
}

void Graph::UseBFS(int a, int numero)
{
    std::queue<int> file;
    std::vector<int> adjacents;
    int actuel;
    int voisin;
    m_vertices[a].m_marque = true;
    file.push(a);
    m_vertices[a].m_connexe.push_back(numero);


    while(!file.empty())
    {
        adjacents.clear();
        actuel = file.front();
        file.pop();

        for(int i=0; i< m_vertices[actuel].m_out.size(); i++)
        {
            voisin = m_edges[m_vertices[actuel].m_out[i]].getArrive();
            if(voisin != actuel)
            {
                adjacents.push_back(voisin);
            }
            ///LA DOUBLE BOUCLE FOR PERMET DE CREER LE VECTEUR D ADJACENCE
        }

        for(int i=0; i< m_vertices[actuel].m_in.size(); i++)
        {
            voisin = m_edges[m_vertices[actuel].m_in[i]].getDepart();
            if(voisin != actuel)
            {
                adjacents.push_back(voisin);
            }
        }

        for(unsigned int i=0; i< adjacents.size(); i++)
        {
            voisin = adjacents[i];
            if(!m_vertices[voisin].m_marque)
            {
                m_vertices[voisin].m_marque = true;
                file.push(voisin);
            }
        }
    }

}

int Graph::Connexe()
{
    int numero = 0;
    int compteur = 0;


    //m_vertices[1].m_marque = true;
    for(auto elem : m_vertices)
    {
        if(!elem.second.m_marque)
        {
            UseBFS(elem.second.m_idx, numero);
            numero++;
        }
    }
    m_maxconnex =std::max(m_maxconnex, numero);


    for(auto elem : m_vertices)
    {
        m_vertices[elem.second.m_idx].m_marque = false;
    }

    return numero;

}


void Graph::K_Connexe()
{
    std::vector<std::vector<int>> Combi;
    std::vector<int> actuel;
    int connexe;
    int k = 1;
    int numeroCombi = 0;
    bool fin = false;

    //Connexe();;
    while(!fin)
    {

        if(m_maxconnex >1 && numeroCombi == Combi.size()-1)
            fin = true;
        Combi = Combinaison(k);
        actuel = Combi[numeroCombi];


        for(unsigned int i=0; i< actuel.size(); i++)
        {
            m_vertices[actuel[i]].m_marque = true;
        }
        connexe = Connexe();

        if(connexe >1)
        {
            for(unsigned int i=0; i< actuel.size(); i++)
            {
                m_sommet_k_connexe.push_back(actuel);
            }
        }
        numeroCombi++;
        if(numeroCombi == Combi.size() && m_maxconnex <= 1)
        {
            numeroCombi = 1;
            k++;
        }
    }
}

void Graph::AfficherKConnexe()
{
    K_Connexe();
    std::cout << "Ce Graphe est " << m_sommet_k_connexe[0].size() << "-Sommet-Connexe" << std::endl;
    for(unsigned int i=0; i< m_sommet_k_connexe.size(); i++)
    {
        std::cout << "Les sommets a enlever sont : ";
        for(unsigned int j=0; j< m_sommet_k_connexe[i].size(); j++)
        {
            std::cout << m_sommet_k_connexe[i][j] << " - ";
        }
        std::cout << std::endl;
    }
}


void Graph::AffichageCombi()
{
    std::vector<std::vector<int>> Combi;
    Combi = Combinaison(1);

    for(unsigned int i=0; i< Combi.size(); i++)
    {
        std::cout << "Combinaison numero " << i << " : "
                  ;
        for(unsigned int j=0; j< Combi[i].size(); j++)
        {
            std::cout << Combi[i][j] << " - ";
        }
        std::cout << std::endl;
    }
}


std::vector<std::vector<int>> Graph::Combinaison(int K)
{
    std::vector<std::vector<int>> Combi;
    std::vector<int> Combi2;
    std::string bitmask(K, 1);
    bitmask.resize(m_vertices.size(), 0);

    do
    {
        Combi2.clear();
        for (int i = 0; i < m_vertices.size(); ++i)
        {
            if (bitmask[i])
            {
                //std::cout << " " << i;
                Combi2.push_back(i);
            }

        }
        //std::cout << std::endl;
        Combi.push_back(Combi2);
    }
    while (std::prev_permutation(bitmask.begin(), bitmask.end()));

    return Combi;
}




void Graph::TuerSommet(int b)
{
    SupprimerSommet(b);
    m_vertices[b].m_popul = 0;
    m_supprime.push_back(b);
}

void Graph::ChargerGraphe(std::string fichier)
{
    m_interface = std::make_shared<GraphInterface>(50, 0, 750, 600);
    std::cout<<"je commence";
    m_edges.clear();
    m_vertices.clear();


    std::string buffer, nom;
    int buffer2, x, y, popul, idx;
    double poids, range, r;
    int indice1, indice2,k_debase;
    std::ifstream fp;
    fichier += ".txt";
    fp.open(fichier.c_str());

    if(fp)
    {
        fp >> buffer;
        setName(buffer);
        std::cout << "Name : " << getName() << std::endl;

        fp >> buffer2;
        setOrdre(buffer2);
        std::cout << "ORDRE : " << getOrdre() << std::endl;

        fp >> buffer2;
        setNbArc(buffer2);

        for(int i=0; i< getOrdre(); i++)
        {
            fp >> idx >> nom >> x >> y >> popul >> range>>k_debase>>r;
            //nom = "Images/" + nom + ".jpg";
            add_interfaced_vertex(idx, nom, popul, x, y, nom + ".jpg", range, popul,k_debase,r);
            std::cout << "Indice : " << i <<  " Nom : " << nom << " x : " << x << " y : " << y << " Popul : " << popul << "Range : " << range << std::endl;
        }

        for(int j=0; j< getNbArc(); j++)
        {
            fp >> indice1 >> indice2 >> poids >> range;
            std::cout << std::endl << "INDICE 1 : " << indice1 << " INDICE 2 : " << indice2 << std::endl;

            add_interfaced_edge(j, indice1, indice2, poids,range);
        }

        ChargerSupprimer();
    }
}

void Graph::SauverGraphe()
{

    for(const auto elem : m_edges)
    {
        std::cout << "Depart : " << elem.second.getDepart() << " Arrive : " << elem.second.getArrive() << std::endl;
    }
    std::ofstream fp(m_name + ".txt");
    Vertex actuel;

    if(fp)
    {
        fp << m_name << std::endl
           << m_ordre << std::endl
           << m_nbArc << std::endl;

        for(int i=0; i< m_ordre; i++)
        {
            actuel = getMapVertex()[i];
            fp << actuel.getIdx() << " " << actuel.getName() << " " << actuel.getX() << " " << actuel.getY()
               << " " << actuel.getPopu() << " " << actuel.getRange()<<" "<<actuel.m_Kdebase <<" "<<actuel.m_r<< std::endl;
        }

        for(int j=0; j< m_nbArc; j++)
        {
            fp << m_vertices[m_edges[j].getDepart()].getIdx() << " " << m_vertices[m_edges[j].getArrive()].getIdx() << " "
               << m_edges[j].getPoids() << " " << 10 << std::endl;
        }

        EcrireFichierSupprimer();
    }
    else
        std::cout << "Erreur FICHIER" << std::endl;
}

std::map<int, Vertex>& Graph::getMapVertex()
{
    return m_vertices;
}

std::map<int, Edge>& Graph::getMapEdge()
{
    return m_edges;
}


/// Méthode spéciale qui construit un graphe arbitraire (démo)
/// Cette méthode est à enlever et remplacer par un système
/// de chargement de fichiers par exemple.
/// Bien sûr on ne veut pas que vos graphes soient construits
/// "à la main" dans le code comme ça.
void Graph::make_example(std::string name_ecosys)
{
    m_interface = std::make_shared<GraphInterface>(50, 0, 750, 600);

   ChargerGraphe(name_ecosys);
   // ChargerGraphe("Foret");
    //ChargerGraphe("Foret");
    // La ligne précédente est en gros équivalente à :
    // m_interface = new GraphInterface(50, 0, 750, 600);
//
//    /// Les sommets doivent être définis avant les arcs
//    // Ajouter le sommet d'indice 0 de valeur 30 en x=200 et y=100 avec l'image clown1.jpg etc...
//    add_interfaced_vertex(0,"clown1", 30.0, 200, 100, "clown1.jpg");
//    add_interfaced_vertex(1, 60.0, 400, 100, "clown2.jpg");
//    add_interfaced_vertex(2,  50.0, 200, 300, "clown3.jpg");
//    add_interfaced_vertex(3,  0.0, 400, 300, "clown4.jpg");
//    add_interfaced_vertex(4,  100.0, 600, 300, "clown5.jpg");
//    add_interfaced_vertex(5,  0.0, 100, 500, "bad_clowns_xx3xx.jpg", 0);
//    add_interfaced_vertex(6,  0.0, 300, 500, "bad_clowns_xx3xx.jpg", 1);
//    add_interfaced_vertex(7,  0.0, 500, 500, "bad_clowns_xx3xx.jpg", 2);
//
//    /// Les arcs doivent être définis entre des sommets qui existent !
//    // AJouter l'arc d'indice 0, allant du sommet 1 au sommet 2 de poids 50 etc...
//    add_interfaced_edge(0, 1, 2, 50.0);
//    add_interfaced_edge(1, 0, 1, 50.0);
//    add_interfaced_edge(2, 1, 3, 75.0);
//    add_interfaced_edge(3, 4, 1, 25.0);
//    add_interfaced_edge(4, 6, 3, 25.0);
//    add_interfaced_edge(5, 7, 3, 25.0);
//    add_interfaced_edge(6, 3, 4, 0.0);
//    add_interfaced_edge(7, 2, 0, 100.0);
//    add_interfaced_edge(8, 5, 2, 20.0);
//    add_interfaced_edge(9, 3, 7, 80.0);
}

//void Graph::make_reduit(vector)

bool Graph::update_simulation()
{

    if ( m_interface->get_bouton_charger().clicked() )
    {
        ChargerGraphe(m_name);
    }

    if ( m_interface->get_bouton_sauver().clicked() )
    {
        SauverGraphe();
    }

    if( m_interface->get_add_sommet().clicked())
    {
        int choix;
        bool possible = false;
        std::cout << "Quelle sommet voulez-vous revoir dans ce magnifique ecosystème " << std::endl;
        std::cout << "Vous avez le choix entre : [";
        for(unsigned int i=0; i<m_supprime.size(); i++)
        {
            std::cout << " " << m_supprime[i] << "(" << m_vertices[m_supprime[i]].m_nom << ")";
        }
        std::cout << " ]" << std::endl;

        std::cin >> choix;

        for(unsigned int i=0; i<m_supprime.size(); i++)
        {
            if(choix == m_supprime[i])
                possible = true;
        }

        if(possible)
        {
            AjouterSommet(choix);
        }
        else
            std::cout << "Ce sommet n'a pas ete supprime" << std::endl;

    }

    if( m_interface->get_remove_sommet().clicked())
    {
        if(m_interface->deja_clique==0)
        {
            for(auto elem : m_vertices)
            {
                elem.second.getInterVertex()->m_top_box.add_child(elem.second.getInterVertex()->m_delete );
            }
            m_interface->deja_clique=1;
        }

        else
        {
            for(auto elem : m_vertices)
            {
                elem.second.getInterVertex()->m_top_box.remove_child(elem.second.getInterVertex()->m_delete );

            }
            m_interface->deja_clique=0;
        }
    }

//    for(auto elem : m_vertices)
//    {
//        if(m_interface->deja_clique == 1 && elem.second.getInterVertex()->m_delete.clicked())
//        {
//            if(elem.second.getInterVertex()->m_delete.clicked())
//            {
//                std::cout << " Je vais supprimer un sommet" << std::endl;
//                TuerSommet(elem.second.m_idx);
//            }
//        }
//    }

    for(auto elem : m_vertices)
    {
        if(elem.second.getInterVertex()->m_delete.clicked())
        {
            TuerSommet(elem.second.m_idx);
        }
    }

    if ( m_interface->get_bouton_pause().clicked() )
    {
        afficher_editeur();//affiche l'interface editeur
        m_etat=0;

        for(auto elem : m_vertices)
        {
            //affiche les sliders des Sommets
            elem.second.getInterVertex()->m_top_box.add_child(elem.second.getInterVertex()->m_slider_value);
            elem.second.getInterVertex()->m_slider_value.set_range(0.0, elem.second.getRange());  // Valeurs arbitraires, à adapter...
            elem.second.getInterVertex()->m_slider_value.set_dim(20,80);
            elem.second.getInterVertex()->m_slider_value.set_gravity_xy(grman::GravityX::Left, grman::GravityY::Up);

        }

        for(auto elem : m_edges)
        {
            elem.second.getInterEdge()->m_box_edge.add_child(elem.second.getInterEdge()->m_slider_weight);
            elem.second.getInterEdge()->m_box_edge.set_dim(60,60);
            elem.second.getInterEdge()->m_slider_weight.set_range(0.0, elem.second.getrange());  // Valeurs arbitraires, à adapter...
            elem.second.getInterEdge()->m_slider_weight.set_dim(16,40);
            elem.second.getInterEdge()->m_slider_weight.set_gravity_y(grman::GravityY::Up);

        }
    }

     for(auto elem : m_vertices)
    {
        elem.second.getInterVertex()->adjust_dim_sommet();

    }

    for(auto elem : m_edges)
    {
        elem.second.getInterEdge()->indicateur_poids();

    }

    if ( m_interface->get_bouton_play().clicked() )
    {
        m_etat=1;
        enlever_editeur();//enleve l'interface editeur

        for(auto elem : m_vertices)
        {
            elem.second.getInterVertex()->m_top_box.remove_child(elem.second.getInterVertex()->m_delete );

        }

        for(auto elem : m_vertices)
        {
            elem.second.getInterVertex()->m_top_box.remove_child(elem.second.getInterVertex()->m_slider_value);

        }

        for(auto elem : m_edges)
        {
            elem.second.getInterEdge()->m_box_edge.remove_child(elem.second.getInterEdge()->m_slider_weight);
            elem.second.getInterEdge()->m_box_edge.set_dim(60,15);

        }
    }

//    std::cout<<"pas appuyer"<<std::endl;
    return false;
}

std::vector<Edge> Graph::update_F_C()
{
    int testd,testa;
    std::vector<std::vector<int>> sommet_a_afficher;
    sommet_a_afficher=F_C();
    std::cout<<"je supprime les affichages"<<std::endl;

    m_interface->m_top_box.remove_child(m_interface->get_tool_box());

    for(auto elem : m_vertices)
    {
        elem.second.getInterVertex()->m_top_box.remove_child(elem.second.getInterVertex()->m_slider_value);

    }

    for(auto elem : m_edges)
    {
        elem.second.getInterEdge()->m_box_edge.remove_child(elem.second.getInterEdge()->m_slider_weight);
        elem.second.getInterEdge()->m_box_edge.set_dim(24,15);

    }

    std::vector<Edge> aretes_a_conserver;
    std::vector<Edge> aretes_a_enlever;

    for(int i=0;i<sommet_a_afficher.size();i++)
    {
        for(auto elem_arete : m_edges)
        {
            testa=0;
            testd=0;
            for(int y=0;y<sommet_a_afficher[i].size();y++)
            {
                if(elem_arete.second.m_from==sommet_a_afficher[i][y])
                {
                    testd=1;
                }
                if(elem_arete.second.m_to==sommet_a_afficher[i][y])
                {
                    testa=1;
                }
            }
            if(testa==1&&testd==1)
            aretes_a_conserver.push_back(elem_arete.second);
        }
    }
    int tempo;
    for(auto elem_arete : m_edges)
        {
            tempo=0;
            for(int z=0;z<aretes_a_conserver.size();z++)
            {
                if((elem_arete.second.m_from==aretes_a_conserver[z].m_from)&&(elem_arete.second.m_to==aretes_a_conserver[z].m_to))
                    tempo=1;
            }
            if(tempo!=1)
                aretes_a_enlever.push_back(elem_arete.second);
        }
    for(int i=0;i<aretes_a_enlever.size();i++)
    {
        m_interface->m_main_box.remove_child(aretes_a_enlever[i].m_interface->m_top_edge);
    }
    return aretes_a_enlever;
}

/// La méthode update à appeler dans la boucle de jeu pour les graphes avec interface
void Graph::update(int a)
{


    if (!m_interface)
    {
        std::cout<<"il n'y a pas d'interface a afficher"<<std::endl;

    }

    for (auto &elt : m_vertices)
        elt.second.pre_update();

    for (auto &elt : m_edges)
        elt.second.pre_update();

    m_interface->m_top_box.update();


    for (auto &elt : m_vertices)
        elt.second.post_update();

    for (auto &elt : m_edges)
        elt.second.post_update();


}

/// Aide à l'ajout de sommets interfacés
void Graph::add_interfaced_vertex(int idx, std::string name, double value, int x, int y, std::string pic_name,double range,int popu,int k_debase,double r, int pic_idx )
{
    if ( m_vertices.find(idx)!=m_vertices.end() )
    {
        std::cerr << "Error adding vertex at idx=" << idx << " already used..." << std::endl;
        throw "Error adding vertex";
    }
    // Création d'une interface de sommet
    VertexInterface *vi = new VertexInterface(idx, x, y, pic_name,range, pic_idx);
    // Ajout de la top box de l'interface de sommet
    m_interface->m_main_box.add_child(vi->m_top_box);
    // On peut ajouter directement des vertices dans la map avec la notation crochet :
    m_vertices[idx] = Vertex(name, value, vi);
    m_vertices[idx].setKdebase(k_debase);
    m_vertices[idx].m_r=r;
    m_vertices[idx].setIdx(idx);
    m_vertices[idx].setRange(range);
    m_vertices[idx].setPopu(popu);
    std::cout << m_vertices[idx].getPopu() << std::endl;

}

/// Aide à l'ajout d'arcs interfacés
void Graph::add_interfaced_edge(int idx, int id_vert1, int id_vert2, double weight,double range)
{
    if ( m_edges.find(idx)!=m_edges.end() )
    {
        std::cerr << "Error adding edge at idx=" << idx << " already used..." << std::endl;
        throw "Error adding edge";
    }

    if ( m_vertices.find(id_vert1)==m_vertices.end() || m_vertices.find(id_vert2)==m_vertices.end() )
    {
        std::cerr << "Error adding edge idx=" << idx << " between vertices " << id_vert1 << " and " << id_vert2 << " not in m_vertices" << std::endl;
        throw "Error adding edge";
    }

    EdgeInterface *ei = new EdgeInterface(m_vertices[id_vert1], m_vertices[id_vert2]);
    m_interface->m_main_box.add_child(ei->m_top_edge);
    m_edges[idx] = Edge(weight, ei);
    m_edges[idx].m_range=range;
    m_edges[idx].setArrive(id_vert2);
    m_edges[idx].setDepart(id_vert1);
    m_vertices[id_vert1].m_out.push_back(idx);
    m_vertices[id_vert2].m_in.push_back(idx);
}

std::vector<std::vector<int>> Graph::F_C()
{
    int depart=0;
    int tempo=0;
    int i=0;
    std::vector<std::vector<int>> resultat_algo;
    std::vector<int> composante_fortement_connexe_actuel;
    std::stack<int> pile;
    std::cout<<std::endl<<"Nettoyage fort "<<std::endl;
        for(auto elem_net : m_vertices)
        {
            std::cout<<" le sommet "<<elem_net.first<<" a pour plus "<<m_vertices[elem_net.first].m_plus<<" et pour moins "<<m_vertices[elem_net.first].m_moins<<std::endl;
                std::cout<<"        je le nettois"<<std::endl;
                m_vertices[elem_net.first].m_moins=0;
                m_vertices[elem_net.first].m_plus=0;
        }
        std::cout<<"                        nettoyage terminé"<<std::endl;
    for(auto elem_depart : m_vertices)
    {
        std::cout<<std::endl<<"je commence par nettoyer tout les plus et moins qui ne sont pas a -1 -1"<<std::endl;
        for(auto elem_net : m_vertices)
        {
            std::cout<<" le sommet "<<elem_net.first<<" a pour plus "<<m_vertices[elem_net.first].m_plus<<" et pour moins "<<m_vertices[elem_net.first].m_moins<<std::endl;
            if(!(m_vertices[elem_net.first].m_moins==-1&&m_vertices[elem_net.first].m_plus==-1))
            {
                std::cout<<"        je le nettois"<<std::endl;
                m_vertices[elem_net.first].m_moins=0;
                m_vertices[elem_net.first].m_plus=0;
            }
        }
        std::cout<<"                        nettoyage terminé"<<std::endl;
        depart=elem_depart.first;
        std::cout<<"je commence la forte connexite a "<<depart<<std::endl;
        if(m_vertices[depart].m_moins!=-1&&m_vertices[depart].m_plus!=-1)
        {
            std::cout<<"le départ n'est pas a -1 -1 donc nouvelle connexité à partir de ce point"<<std::endl;
            m_vertices[depart].m_moins=2;
            m_vertices[depart].m_plus=2;
            pile.push(depart);
            while(!pile.empty())
            {
                std::cout<<"    La pile n'est pas vide je continue"<<std::endl;
                tempo=pile.top();
                std::cout<<"        le point a partir du quel je regarde est "<<tempo<<std::endl;
                pile.pop();
                std::cout<<"            il a "<< m_vertices[tempo].m_out.size()<<"arrete sortantes"<<std::endl;
                for(i=0; i<m_vertices[tempo].m_out.size(); i++)
                {
                    std::cout<<"                Dans l'arrete d'indice "<<m_vertices[tempo].m_out[i]<<std::endl;
                    std::cout<<m_edges[m_vertices[tempo].m_out[i]].getArrive()<<"                    est le sommet d'arrive de larete"<<std::endl;
                    std::cout<<"                        ca marque plus est "<<m_vertices[m_edges[m_vertices[tempo].m_out[i]].getArrive()].m_plus<<std::endl;
                    std::cout<<"                        ca marque moins est "<<m_vertices[m_edges[m_vertices[tempo].m_out[i]].getArrive()].m_moins<<std::endl;

                    if((m_vertices[m_edges[m_vertices[tempo].m_out[i]].getArrive()].m_plus!=2)&&(m_vertices[m_edges[m_vertices[tempo].m_out[i]].getArrive()].m_plus!=1)&&(m_vertices[m_edges[m_vertices[tempo].m_out[i]].getArrive()].m_plus!=-1)&&(m_vertices[m_edges[m_vertices[tempo].m_out[i]].getArrive()].m_moins!=-1))
                    {
                        m_vertices[m_edges[m_vertices[tempo].m_out[i]].getArrive()].m_plus=1;
                        pile.push(m_edges[m_vertices[tempo].m_out[i]].getArrive());
                        std::cout<<"                    je met + sur " <<m_edges[m_vertices[tempo].m_out[i]].getArrive()<<std::endl;
                    }
                }
            }
            pile.push(depart);
            std::cout<<"les plus c'est finit je fais les moins"<<std::endl<<std::endl;
            while(!pile.empty())
            {
                std::cout<<"    La pile n'est pas vide je continue"<<std::endl;
                tempo=pile.top();
                std::cout<<"        le point a partir du quel je regarde est "<<tempo<<std::endl;
                pile.pop();
                std::cout<<"            il a "<< m_vertices[tempo].m_in.size()<<"arrete entrante"<<std::endl;
                for(i=0; i<m_vertices[tempo].m_in.size(); i++)
                {
                    std::cout<<"                Dans l'arrete d'indice "<<m_vertices[tempo].m_in[i]<<std::endl;
                    std::cout<<m_edges[m_vertices[tempo].m_in[i]].getDepart()<<"                    est le sommet de Depart de larete "<<std::endl;
                    std::cout<<"                        ca marque plus est "<<m_vertices[m_edges[m_vertices[tempo].m_in[i]].getDepart()].m_plus<<std::endl;
                    std::cout<<"                        ca marque moins est "<<m_vertices[m_edges[m_vertices[tempo].m_in[i]].getDepart()].m_moins<<std::endl;

                    if((m_vertices[m_edges[m_vertices[tempo].m_in[i]].getDepart()].m_moins!=2)&&(m_vertices[m_edges[m_vertices[tempo].m_in[i]].getDepart()].m_moins!=1)&&(m_vertices[m_edges[m_vertices[tempo].m_in[i]].getDepart()].m_plus!=-1)&&(m_vertices[m_edges[m_vertices[tempo].m_in[i]].getDepart()].m_moins!=-1))
                    {
                        m_vertices[m_edges[m_vertices[tempo].m_in[i]].getDepart()].m_moins=1;
                        pile.push(m_edges[m_vertices[tempo].m_in[i]].getDepart());
                        std::cout<<"                je met - sur " <<m_edges[m_vertices[tempo].m_in[i]].getDepart()<<std::endl;
                    }
                }
            }

            std::cout<<"j'ai finit un tour de recherche je passe à la verif du graphe actuel"<<std::endl;
            for(auto elem_verif : m_vertices)
            {

                tempo=elem_verif.first;
                std::cout<<tempo<<" est l'ellement que je verifie  "<<std::endl;;
                std::cout<<"    sa marque plus est "<<m_vertices[tempo].m_plus<<std::endl;
                std::cout<<"    sa marque moins est "<<m_vertices[tempo].m_moins<<std::endl;
                if((m_vertices[tempo].m_moins==1&&m_vertices[tempo].m_plus==1)||(m_vertices[tempo].m_moins==2&&m_vertices[tempo].m_plus==2))
                {
                    std::cout<<"        il est marqué ou est l'origine de la recherche je le met a -1/-1 et l'ajoute";
                    m_vertices[tempo].m_moins=-1;
                    m_vertices[tempo].m_plus=-1;

                    composante_fortement_connexe_actuel.push_back(tempo);
                }
                else
                {
                    if(!(m_vertices[tempo].m_moins==-1&&m_vertices[tempo].m_plus==-1))
                    {
                        m_vertices[tempo].m_moins=0;
                        m_vertices[tempo].m_plus=0;
                    }

                }
            }


        }

        if(composante_fortement_connexe_actuel.size()!=0)
            resultat_algo.push_back(composante_fortement_connexe_actuel);
        composante_fortement_connexe_actuel.clear();
    }
    for(i=0; i<resultat_algo.size(); i++)
    {
        std::cout<<"connexité numéro:   "<<i<<std::endl;
        for(int y=0; y<resultat_algo[i].size(); y++)
        {
            std::cout<<resultat_algo[i][y]<<" ";
        }
    }
    return resultat_algo;
}

void Graph::afficher_editeur()
{

    m_interface->get_tool_box().add_child(m_interface->get_edition_label());
    m_interface->get_tool_box().add_child(m_interface->get_sommet_label());
    m_interface->get_tool_box().remove_child(m_interface->get_bouton_pause());
    m_interface->get_tool_box().add_child(m_interface->get_bouton_play());
    m_interface->get_bouton_play_pause_label().set_message("Pause");
    m_interface->get_tool_box().add_child(m_interface->get_add_sommet());
    m_interface->get_tool_box().add_child(m_interface->get_remove_sommet());

}

void Graph::enlever_editeur()
{
    //enleve l'editeur
    m_interface->get_tool_box().remove_child(m_interface->get_bouton_play());
    m_interface->get_tool_box().add_child(m_interface->get_bouton_pause());
    m_interface->get_bouton_play_pause_label().set_message("Simulation");

    m_interface->get_tool_box().remove_child(m_interface->get_edition_label());
    m_interface->get_tool_box().remove_child(m_interface->get_sommet_label());
    m_interface->get_tool_box().remove_child(m_interface->get_add_sommet());
    m_interface->get_tool_box().remove_child(m_interface->get_remove_sommet());
}


void Graph::make_menu()
{
    m_interface = std::make_shared<GraphInterface>(50, 0, 750, 600);
}
