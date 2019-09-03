#ifndef __graph__
#define __graph__ 
#include <stdlib.h>

using namespace std;

typedef vector<vector<int>> click;
typedef vector<vector<int>> graph;
void add_edge(graph& g, int source, int fate); // cria arestas a partir do dado de origem e destino
void all_agl(click& c, graph& g);
void bfs_alg(graph& g, int vertex, vector<bool>& visited); //agora precisamos verificar os cliques maximais (fazendo a indicação do numero de vertices e seus respectivos)
void bfs(graph& g, int vertex);
void bosch_alg(graph& g, click& c, vector<int>& R, vector<int>& P, vector<int>& X);
void click_begin(graph& g, click& c); //para verificar os cliques maximais, utilizaremos o algoritimo de Bronker Bosh
void create_graph(graph& g); //cria um grafo a partir da referencia do endereço  da tipagem vector<vector
void menu(click& c, graph& g);
void print_click(click& c);
//pra percorrer os vertices e verificar os graus, é preciso usar um algoritmo pra percorrer nosso grafo
//a selecionada sera a breadth first search

/*Bosh pseudocodigo: 
    Bosh(r,p,x)
    if P and X sao vazios then
        report R como clique maximo
    
    for cada vertice em P do
        Bosh(R uniao v, P intersecção N(v), X inter N(v))
        P <- P\v
        X <- X uniao v
*/
#endif