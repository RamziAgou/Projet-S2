#include "graph.h"

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

void Graph::SupprimerSommet(int b)
{
    Vertex &delVer = m_vertices[b];

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

void Graph::ChargerGraphe(std::string _fichier)
{
    m_interface = std::make_shared<GraphInterface>(50, 0, 750, 600);
    std::cout<<"je commence";

    std::string fichier = _fichier;

    m_edges.clear();
    m_vertices.clear();



    std::string buffer, nom;
    int buffer2, x, y, popul, idx;
    double poids, range;
    int indice1, indice2;
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
            fp >> idx >> nom >> x >> y >> popul >> range;
            //nom = "Images/" + nom + ".jpg";
            add_interfaced_vertex(idx, nom, popul, x, y, nom + ".jpg", range, popul);
            std::cout << "Indice : " << i <<  " Nom : " << nom << " x : " << x << " y : " << y << " Popul : " << popul << "Range : " << range << std::endl;
        }

        for(int j=0; j< getNbArc(); j++)
        {
            fp >> indice1 >> indice2 >> poids >> range;
            std::cout << std::endl << "INDICE 1 : " << indice1 << " INDICE 2 : " << indice2 << std::endl;

            add_interfaced_edge(j, indice1, indice2, poids);
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
               << " " << actuel.getPopu() << " " << actuel.getRange() << std::endl;
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
void Graph::make_example()
{
    m_interface = std::make_shared<GraphInterface>(50, 0, 750, 600);

    //ChargerGraphe("Marin");
    ChargerGraphe("Foret");
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
        //ajouter_sommet();
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
            elem.second.getInterEdge()->m_box_edge.set_dim(24,60);
            elem.second.getInterEdge()->m_slider_weight.set_range(0.0, 100.0);  // Valeurs arbitraires, à adapter...
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
            elem.second.getInterEdge()->m_box_edge.set_dim(24,15);

        }
    }
    if ( m_interface->get_bouton_quitter().clicked() )
    {

        return true;
    }
    return false;
}

bool Graph::update_F_C()
{
    int testd,testa;
    std::vector<std::vector<int>> sommet_a_afficher;
    sommet_a_afficher=F_C();
    std::cout<<"je supprime les affichages"<<std::endl;

    m_interface->get_tool_box().remove_child(m_interface->get_bouton_pause());
    m_interface->get_tool_box().remove_child(m_interface->get_bouton_play());
    m_interface->get_tool_box().remove_child(m_interface->get_bouton_play_pause_label());
    m_interface->get_tool_box().remove_child(m_interface->get_bouton_sauver());
    for(auto elem : m_vertices)
    {
        elem.second.getInterVertex()->m_top_box.remove_child(elem.second.getInterVertex()->m_slider_value);

    }

    for(auto elem : m_edges)
    {
        elem.second.getInterEdge()->m_box_edge.remove_child(elem.second.getInterEdge()->m_slider_weight);
        elem.second.getInterEdge()->m_box_edge.set_dim(24,15);

    }
    for(int i=0; i<sommet_a_afficher.size(); i++)
    {
        for(auto elem_arete : m_edges)
        {
            testa=0;
            testd=0;
            for(int y=0; y<sommet_a_afficher[i].size(); y++)
            {
                if(elem_arete.second.m_from==sommet_a_afficher[i][y])
                {
                    testd=1;
                }
            }
        }
    }
    return false;
}
/// La méthode update à appeler dans la boucle de jeu pour les graphes avec interface
bool Graph::update(int a)
{
    bool fin=false;

    if (!m_interface)
    {
        std::cout<<"il n'y a pas d'interface a afficher"<<std::endl;
        return false;
    }

    for (auto &elt : m_vertices)
        elt.second.pre_update();

    for (auto &elt : m_edges)
        elt.second.pre_update();

    switch(a)
    {
    case 0:
        fin=update_simulation();
        break;
    case 1:
        fin=update_F_C();
        break;
    default:
        std::cout<<"uptade failed"<<std::endl;
    }
    m_interface->m_top_box.update();

    for (auto &elt : m_vertices)
        elt.second.post_update();

    for (auto &elt : m_edges)
        elt.second.post_update();
    return fin;

}

/// Aide à l'ajout de sommets interfacés
void Graph::add_interfaced_vertex(int idx, std::string name, double value, int x, int y, std::string pic_name,double range,int popu, int pic_idx )
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
    m_vertices[idx].setIdx(idx);
    m_vertices[idx].setRange(range);
    m_vertices[idx].setPopu(popu);
    std::cout << m_vertices[idx].getPopu() << std::endl;

}

/// Aide à l'ajout d'arcs interfacés
void Graph::add_interfaced_edge(int idx, int id_vert1, int id_vert2, double weight)
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
    for(auto elem_depart : m_vertices)
    {
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

                    if(m_vertices[m_edges[m_vertices[tempo].m_out[i]].getArrive()].m_plus!=2&&m_vertices[m_edges[m_vertices[tempo].m_out[i]].getArrive()].m_plus!=1)
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

                    if(m_vertices[m_edges[m_vertices[tempo].m_in[i]].getDepart()].m_plus!=2&&m_vertices[m_edges[m_vertices[tempo].m_in[i]].getDepart()].m_plus!=1)
                    {
                        m_vertices[m_edges[m_vertices[tempo].m_in[i]].getDepart()].m_plus=1;
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

//void Graph::ajouter_sommet()
//{
//    int choix;
//    do
//    {
//        std::cout << std::endl;
//        std::cout << "Choisissez quel sommet ajouter: " << std::endl;
//        std::cout << "Quitter: -1" << std::endl;
//        for(int i=0; i<m_supprime.size();i++)
//        {
//            std::cout << m_supprime[i].getIdx() << " " << m_supprime[i].getName() << std::endl;
//        }
//
//        std::cin >> choix;
//        //add_interfaced_vertex(m_sommet_supprime[choix].m_idx, )
//        if( choix <= m_supprime.size() && 0 <= choix  )
//        {
//            //add_interfaced_vertex(m_sommet_supprime[choix].getIdx(), m_sommet_supprime[choix].getName(), m_sommet_supprime[choix].getPopu(), m_sommet_supprime[choix].getX(), m_sommet_supprime[choix].getY(), m_sommet_supprime[choix].getName() + ".jpg", m_sommet_supprime[choix].getRange(), m_sommet_supprime[choix].getPopu());
//            m_interface->m_main_box.add_child(m_vertices[choix].m_interface->m_top_box);
//        }
//        //add_interfaced_edge(choix, indice1, indice2, poids);
//    }
//    while(choix <= m_sommet_supprime.size() && 0 <= choix );
//}

//void Graph::enlever_sommet()
//{
//
//
//}
