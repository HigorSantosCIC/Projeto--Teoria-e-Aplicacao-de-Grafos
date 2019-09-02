#ifndef __graph__
#define __graph__ 


    #include <stdlib.h>
    using namespace std;

    //funções relacionadas ao grafo nao direcionado

    typedef vector<vector<int>> graph;
    typedef vector<vector<int>> click;
    
    void create_graph(graph& g);

    void add_edge(graph& g, int source, int fate);

#endif