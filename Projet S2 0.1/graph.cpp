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

void Graph::ChargerGraphe(std::string fichier)
{
    std::string buffer, nom;
    int buffer2, x, y, popul, range;
    double poids;
    int indice1, indice2;
    std::ifstream fp;
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
            fp >> nom >> x >> y >> popul >> range;
            //nom = "Images/" + nom + ".jpg";
            add_interfaced_vertex(i, nom, popul, x, y, nom + ".jpg");
            std::cout << "Indice : " << i <<  " Nom : " << nom << " x : " << x << " y : " << y << " Popul : " << popul << std::endl;
        }

        for(int j=0; j< getNbArc(); j++)
        {
            fp >> indice1 >> indice2 >> poids >> range;
            std::cout << std::endl << "INDICE 1 : " << indice1 << " INDICE 2 : " << indice2 << std::endl;

            add_interfaced_edge(j, indice1, indice2, poids);
        }

        std::cout << m_vertices[1].getInterVertex()->getTopBox().get_frame().pos.x << std::endl; ///RECUPERER X !!!

    }
}

std::map<int, Vertex>& Graph::getMapVertex()
{
    return m_vertices;
}


/// Méthode spéciale qui construit un graphe arbitraire (démo)
/// Cette méthode est à enlever et remplacer par un système
/// de chargement de fichiers par exemple.
/// Bien sûr on ne veut pas que vos graphes soient construits
/// "à la main" dans le code comme ça.
void Graph::make_example()
{
    m_interface = std::make_shared<GraphInterface>(50, 0, 750, 600);

    ChargerGraphe("Marin.txt");
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

/// La méthode update à appeler dans la boucle de jeu pour les graphes avec interface
void Graph::update()
{
    if (!m_interface)
        return;

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
void Graph::add_interfaced_vertex(int idx, std::string name, double value, int x, int y, std::string pic_name, int pic_idx )
{
    if ( m_vertices.find(idx)!=m_vertices.end() )
    {
        std::cerr << "Error adding vertex at idx=" << idx << " already used..." << std::endl;
        throw "Error adding vertex";
    }
    // Création d'une interface de sommet
    VertexInterface *vi = new VertexInterface(idx, x, y, pic_name, pic_idx);
    // Ajout de la top box de l'interface de sommet
    m_interface->m_main_box.add_child(vi->m_top_box);
    // On peut ajouter directement des vertices dans la map avec la notation crochet :
    m_vertices[idx] = Vertex(name, value, vi);
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
}

