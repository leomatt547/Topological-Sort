/*File Main
Nama : Leonard Matheus
NIM : 13519215
Kelas : K-04
*/
#include <iostream>
#include <vector>
#include <string>
#include "13519215-Topological.hpp"
#include "13519215-Graph.hpp"

using namespace std;

int main(int argc, char const *argv[]){
    Graph G;
    Toposort T;
    vector<vector<string>> hasil;
    string a = "../test/prereq.txt";
    vector<string> wow = bacaGraph(a, &G);
    map<string,int> mapnya = matkul(wow);
    makeGraph(&G, mapnya, wow);
    //show_Matkul_key(mapnya);
    topsort(&T, &G);
    sikat(&T);
    hasil = terjemahkan_key(&T, mapnya);
    printSemester(hasil);
    
    return 0;
}
