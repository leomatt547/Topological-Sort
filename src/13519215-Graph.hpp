/*File Graph
Nama : Leonard Matheus
NIM : 13519215
Kelas : K-04
*/
#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

#define BrsMin 0
#define BrsMax 99
#define KolMin 0
#define KolMax 99

typedef int indeks; /* indeks baris, kolom */
typedef int ElType; 
typedef struct { 
	ElType Mem[BrsMax+1][KolMax+1];
    int NBrsEff; /* banyaknya/ukuran baris yg terdefinisi */
	int NKolEff; /* banyaknya/ukuran kolom yg terdefinisi */
} Graph;

#define NBrsEff(G) (G).NBrsEff
#define NKolEff(G) (G).NKolEff
#define Elmt(G,i,j) (G).Mem[(i)][(j)]

void makeGraph(Graph * G, map<string,int> list_matkul, vector<string> inputmatkul);
void TulisGraph (Graph * G);
indeks GetFirstIdxBrs (Graph G);
indeks GetFirstIdxKol (Graph G);
indeks GetLastIdxBrs (Graph G);
indeks GetLastIdxKol (Graph G);
int GetnumberOfNodes(Graph G);
bool isIdxValid (int i, int j);
vector<string> bacaGraph(string &filePath, Graph * G);
map<string, int> matkul (vector<string> senaraimatkul);
string key_matkulnya_apa (map<string, int> matakuliah, int valuenya);
int GetnumberofNodes(Graph G);

#endif