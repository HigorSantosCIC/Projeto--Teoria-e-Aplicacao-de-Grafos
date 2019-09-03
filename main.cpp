#include <bits/stdc++.h>
#include "graph.h"

using namespace std;

int main(){

    graph g(63);
    click c;
    create_graph(g);
    click_begin(g, c);
    
    menu(c, g);

    return 0;
}