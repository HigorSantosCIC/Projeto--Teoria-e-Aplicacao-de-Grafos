#ifndef __graph__
#define __graph__ 
#include <stdlib.h>
/**
 * @brief 
 * 
 * @file func_graph.h
 * @author Higor Gabriel Azevedo Santos
 * @date 2019-09-01
 * 
 */
using namespace std;
/**
 * @brief Tipagem do vetor bidimensional (int) do clique. 
 * 
 */
typedef vector<vector<int>> click;
/**
 * @brief Tipagem do vetor bidimensional (int) do grafo. 
 * 
 */
typedef vector<vector<int>> graph;
/**
 * @brief Cria arestas a partir do dado de origem e destino
 * 
 * @param g 
 * @param source 
 * @param fate 
 */
void add_edge(graph& g, int source, int fate);
/**
 * @brief Funcao responsavel pelo calculo das aglomeracoes dos vertices, onde pega-se a partir dos cliques que sao triangular
 * 
 * 
 * @param c 
 * @param g 
 */
void all_agl(click& c, graph& g);
/**
 * @brief Modularizacao do Algoritimo de percorrimento no Grafo: Breadth First Search
 * 
 * @param g 
 * @param vertex 
 * @param visited 
 */
void bfs_alg(graph& g, int vertex, vector<bool>& visited); //agora precisamos verificar os cliques maximais (fazendo a indicação do numero de vertices e seus respectivos)
/**
 * @brief  Algoritimo de percorrimento no Grafo: Breadth First Search
 * 
 * @param g 
 * @param vertex 
 */
void bfs(graph& g, int vertex);
/**
 * @brief Algoritimo para encontrar o clique maximal de grafos nao direcionados: Bron-Kerbosch 
 * 
 * @param g 
 * @param c 
 * @param R 
 * @param P 
 * @param X 
 */
void bosch_alg(graph& g, click& c, vector<int>& R, vector<int>& P, vector<int>& X);

/**
 * @brief Modularizacao do Uso do Bron-Kerbosch 
 * 
 * @param g 
 * @param c 
 */
void click_begin(graph& g, click& c); 
/**
 * @brief Criação de um grafo a partir dos dados contidos no Arquivo ".mtx"
 * 
 * @param g
 */
void create_graph(graph& g);
/**
 * @brief Criacao de um menu principal para selecionar as funcoes principais.
 * 
 * @param c 
 * @param g 
 */
void menu(click& c, graph& g);
/**
 * @brief Usado para imprimir os cliques maximais ordenados.
 * 
 * @param c 
 */
void print_click(click& c);

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