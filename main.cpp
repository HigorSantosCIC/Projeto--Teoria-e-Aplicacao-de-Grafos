#include <bits/stdc++.h>
#include "graph.h"

using namespace std;

int main(){

    graph g(63);
    create_graph(g);

    bfs(g, 1); 
}