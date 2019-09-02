#include <bits/stdc++.h>
#include "graph.h"
using namespace std;

void menu(click& c, graph& g){
    int opcao;
    puts("\n MENU -> [Escolha a Opcao]\n\n");
    puts("[1] O vértice, e seu respectivo grau\n");
    puts("[2] Todos os Cliques Maximais\n");
    puts("[3] Coeficiente de Aglomeracao de cada vertice, e a medio do grafo\n");
    puts("[0] Voltar ao menu\n");

    while(1){
        cin >> opcao;
        system("clear");
    switch (opcao)
    {
        case 0:
            return;
            break;
        case 1:
            bfs(g, 1);
            break;
        case 2:
            print_click(c); 
            break;
        case 3:
            all_agl(c, g);
        break;
        default:
            cout << "Selecione uma opcao valida\n";
            break;
            }
        }
}


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

vector<int> inter(vector<int>& x, vector<int>& y){ //algoritimo para verificação de intersecao
    vector<int> result;
    for(int i = 0; i < x.size(); i++){
        int perm = x[i];
        for(int j = 0; j < y.size(); j++){
            if(perm == y[j]){
                result.push_back(y[j]);
            }
        }
    }
    return result;
}

void click_begin(graph& g, click& c){
    if(c.empty()){
        vector<int> r, p, x;
        for (int i = 1; i < g.size(); i++)
        {
            p.push_back(i);
        }
        bosch_alg(g, c, r, p, x);
    }
}

void bosch_alg(graph& g, click& c, vector<int>& R, vector<int>& P, vector<int>& X){

    if(P.empty() && X.empty()){
        sort(R.begin(), R.end());
        c.push_back(R);
        return;
    }

    for(int i = 0; P.size()>0;i++){
        int vertex = P[0];
        vector<int> R_new =  R, P_new = P, X_new =  X;

        R_new.push_back(vertex);
        P_new = inter(P, g[vertex]);
        X_new = inter(X, g[vertex]);

        bosch_alg(g, c, R_new, P_new, X_new);

        P.erase(P.begin());
        X.push_back(vertex);

    }        
}

void print_click(click& c){
    sort(c.begin(), c.end(), [](const vector<int>& a, const vector<int>& b) -> bool {
        return a.size() > b.size();});
    for(int i = 0; i < c.size(); i++){
        cout << "Tamanho CliqueMaximal = " << c[i].size() << " Vertices:{";
        for(int k = 0; k < c[i].size();k++){
            cout << c[i][k] << ",";
        }
        cout << "}" << endl;
    }
}

void all_agl(click& c, graph& g){
    
    click tri;

    for(int i = 0; i < c.size(); i++){
        if(c[i].size() == 3){
            tri.push_back(c[i]);
        }
    }

    double media = 0;

    for(int i = 1; i < g.size(); i++){
        int much_tri = 0;

        for(auto &it : tri){
            auto belong = find(it.begin(), it.end(), i) != it.end();
            if (belong) {
                much_tri++;
            }
        }

        int tam = g[i].size();
        double agl;

        if(much_tri == 0){
            agl = 0.0f;
        }   else {
            agl = (2.0f*much_tri)/(tam*(tam - 1));
        }
        media += agl;
        cout << "Coeficiente de Aglomeracao por vertice " <<  i << " : " << agl << endl;
    }

    cout << "\n\nCoeficiente de Aglomeracao Medio : " << media / (g.size()-1) << endl;

}
