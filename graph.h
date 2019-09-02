#ifndef __graph__
#define __graph__ 
#include <stdlib.h>
using namespace std;

//funções relacionadas ao grafo nao direcionado

typedef vector<vector<int>> graph;
typedef vector<vector<int>> click;

void create_graph(graph& g); //cria um grafo a partir da referencia do endereço  da tipagem vector<vector

void add_edge(graph& g, int source, int fate); // cria arestas a partir do dado de origem e destino

    //pra percorrer os vertices e verificar os graus, é preciso usar um algoritmo pra percorrer nosso grafo
    //a selecionada sera a breadth first search

void bfs(graph& g, int vertex);

void bfs_alg(graph& g, int vertex, vector<bool>& visited);

#endif