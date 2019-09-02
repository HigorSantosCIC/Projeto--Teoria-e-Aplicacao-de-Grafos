#include <bits/stdc++.h>
#include "graph.h"

using namespace std;

int main(){

    graph g(63);
    click c;
    create_graph(g);

    bfs(g, 1);
    click_begin(g, c);
    print_click(c); 

}