#ifndef TOPOLOGICAL_HPP
#define TOPOLOGICAL_HPP

#include "Graph.cpp"
#include <vector>

typedef struct { 
    vector<vector<int>> ordering;
    vector<bool> V;
} Toposort;

#define Ordering(T) (T).ordering
#define V(T) (T).V
#define Nil 99

void topsort(Toposort *T, Graph *G);
int dfs(int i, int j, int at,Toposort *T, Graph *G);
vector<vector<string>> terjemahkan_key (Toposort *T, map<string,int> matkul);
void sikat (Toposort *T);
void printSemester(vector<vector<string>> hasil);
void show_Matkul_key(map<string,int> mapnya);
bool cek_nil (vector<int> produk);

#endif