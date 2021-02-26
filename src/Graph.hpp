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

#define NBrsEff(M) (M).NBrsEff
#define NKolEff(M) (M).NKolEff
#define Elmt(M,i,j) (M).Mem[(i)][(j)]

void makeGraph (int NB, int NK, Graph * G); 
void TulisGraph (Graph * G);
indeks GetFirstIdxBrs (Graph G);
/* Mengirimkan indeks baris terkecil M */
indeks GetFirstIdxKol (Graph G);
/* Mengirimkan indeks kolom terkecil M */
indeks GetLastIdxBrs (Graph G);
/* Mengirimkan indeks baris terbesar M */
indeks GetLastIdxKol (Graph G);
/* Mengirimkan indeks kolom terbesar M */
bool isIdxValid (int i, int j);
vector<string> bacaGraph(string &filePath, Graph * G);
map<string, int> matkul (vector<string> * senaraimatkul);
string key_matkulnya_apa (map<string, int> matakuliah, int valuenya);
int getnumberofNodes(Graph * G);

#endif