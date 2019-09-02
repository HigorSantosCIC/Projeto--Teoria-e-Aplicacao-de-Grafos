#include <bits/stdc++.h>
#include "graph.h"

using namespace std;

int main(){
    graph g(63);
    click c;

    create_graph(g);
    click_begin(g, c);

    bfs(g, 1);

    print_click(c); 
    all_agl(c, g);

    return 0;
}