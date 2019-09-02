#include <bits/stdc++.h>
#include "graph.h"
using namespace std;


void create_graph(graph& g) {
    fstream mygraph;
    int x, y;
    string line;
    mygraph.open("grafo.mtx");

    while(getline(mygraph, line)){
        stringstream formato(line);
        formato >> x >> y;
        add_edge(g,x,y);
    }
}

void add_edge(graph& g, int source, int fate){
    g[source].push_back(fate);
    g[fate].push_back(source);
}

