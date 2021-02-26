#ifndef TOPOLOGICAL_HPP
#define TOPOLOGICAL_HPP

#include "Graph.cpp"
#include <vector>

typedef struct { 
    vector<int> ordering;
    vector<bool> V;
} Toposort;

#define Ordering(T) (T).ordering
#define V(T) (T).V

void topsort(Toposort *T, Graph G);
int dfs(int i, int at,Toposort *T, Graph G);
vector<string> terjemahkan_key (Toposort *T);
vector<string> terjemahkan_key (Toposort *T, map<string,int> matkul);
#endif