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

//Membaca input file dan membuat vektor string untuk dibuatkan mapnya
vector<string> bacaGraph(string &filePath, Graph * G);
//Mengekstraksi list mata kuliah yang dibentuk menjadi matriks graph
void makeGraph(Graph * G, map<string,int> list_matkul, vector<string> inputmatkul);
//Menampilkan matriks graph ke layar
void TulisGraph (Graph * G);
//Getter Indeks Pertama Baris Matriks Adjacency List
indeks GetFirstIdxBrs (Graph G);
//Getter Indeks Pertama Kolom Matriks Adjacency List
indeks GetFirstIdxKol (Graph G);
//Getter Indeks Terakhir Baris Matriks Adjacency List
indeks GetLastIdxBrs (Graph G);
//Getter Indeks Terakhir Kolom Matriks Adjacency List
indeks GetLastIdxKol (Graph G);
//Getter jumlah node yang ada di graph
int GetnumberOfNodes(Graph G);
//Membuat map antara nama matkulnya
map<string, int> matkul (vector<string> senaraimatkul);
//Untuk mendapatkan key dari indeks integer matkul yang ditanya
string key_matkulnya_apa (map<string, int> matakuliah, int valuenya);

#endif