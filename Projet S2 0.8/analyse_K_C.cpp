#include "analyse_K_C.h"

void analyse_K_C(std::string name_ecosys)
{

    Graph g;
    g.make_example(name_ecosys);
    g.AffichageCombi();
    g.AfficherKConnexe();
}
