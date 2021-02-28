/*File Topological
Nama : Leonard Matheus
NIM : 13519215
Kelas : K-04
*/

#ifndef TOPOLOGICAL_HPP
#define TOPOLOGICAL_HPP

#include "13519215-Graph.hpp"
#include <vector>

//Loyang untuk Toposort yang berisi matriks vector of integer ordering dan array of boolean V
typedef struct { 
    vector<vector<int>> ordering;
    vector<bool> V;
} Toposort;

//Macro untuk mengakses elemen dalam struct
#define Ordering(T) (T).ordering
#define V(T) (T).V

//Definisi Nil
#define Nil 99

//Memproses Graph yang terbentuk dan mengembalikan matriks vektor integer yang sudah terurut
void topsort(Toposort *T, Graph *G);
//Membantu topsort dalam melakukan rekursif, menerima integer i,j dan node yang dituju
int dfs(int i, int j, int at,Toposort *T, Graph *G);
//Merapihkan matriks vektor integer sehingga tidak ada mata kuliah yang tumpang tindih di semester lain
void sikat (Toposort *T);
//Mengubah integer menjadi string menurut map of pair(string, key) yang telah didefinisikan di awal
vector<vector<string>> terjemahkan_key (Toposort *T, map<string,int> matkul);
//Menampilkan Mata Kuliah yang disarankan di layar
void printSemester(vector<vector<string>> hasil);
//Menunjukkan pasangan mata kuliah dengan representasi integer yang dimasukkan ke dalam suatu map
void show_Matkul_key(map<string,int> mapnya);
//Mengecek apakah pada suatu baris/kolom terdapat nilai Nil semuanya secara simultan
bool cek_nil (vector<int> produk);

#endif