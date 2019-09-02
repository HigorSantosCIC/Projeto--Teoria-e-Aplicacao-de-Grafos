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

void bfs(graph& g, int vertex){
    vector<bool> visited(g.size(), false);
    bfs_alg(g, vertex, visited);
}
    //pega o vetor booleano que marca os lugares visitados do nosso grafo
    
void bfs_alg(graph& g, int vertex, vector<bool>& visited){
    queue<int> fila;
    fila.push(vertex); //insere no topo da fila o vertice
    visited[vertex] = true; //coloca como 1 onde foi visitado

    while(fila.size()){
        int front = fila.front(); 
        fila.pop();
        cout << "Vertice:" << front << "  Grau: " << g[front].size() << endl;

        for(auto aux: g[front]){
            if(!visited[aux]){
                fila.push(aux);
                visited[aux] = true;
            }
        }

    }

    for(int i = 1; i < visited.size(); i++){
        if(visited[i] == false){
            bfs_alg(g, i , visited);
        }
    }
}
