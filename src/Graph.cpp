#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map> 
#include "Graph.hpp"

using namespace std;

void makeGraph(Graph * G, map<string,int> list_matkul, vector<string> inputmatkul){
    NBrsEff(*G)=list_matkul.size();
    NKolEff(*G)=list_matkul.size();
    int NB, NK = list_matkul.size();
    int valuekiri, valuekanan = 0;
    indeks i,j,k;
    for (i = BrsMin; i < NB; i++){
        for (j = KolMin; j < NK; j++){
            Elmt(*G, i, j) = 0;
        }
    }
    string kanan = "";
    string kiri = "";
    for (k = 0; k<(inputmatkul.size()); k++){
        if (kiri == "" || inputmatkul.at(k-1)=="\n"){
            kiri = inputmatkul.at(k);
        }
        kanan = inputmatkul.at(k);
        if (kiri != kanan && kanan !="\n"){
            valuekiri = list_matkul.at(kiri); 
            valuekanan = list_matkul.at(kanan);
            Elmt(*G, valuekanan, valuekiri) = 1;
        }
        /*
        if(inputmatkul.at(k+1)!="\n" && inputmatkul.at(k)!="\n"){
            kiri = inputmatkul.at(k); //cek string kiri
            kanan = inputmatkul.at(k+1); //cek string kanan
            valuekiri = list_matkul.at(kiri); 
            valuekanan = list_matkul.at(kanan);
            Elmt(*G, valuekanan, valuekiri) = 1;
        }
        */
    }
}

void TulisGraph (Graph *G){
    indeks i,j;
    for (i = GetFirstIdxBrs(*G); i <= GetLastIdxBrs(*G); i++){
        for (j = GetFirstIdxKol(*G); j <= GetLastIdxKol(*G); j++){
            cout << Elmt(*G,i,j);
            if (j!=GetLastIdxKol(*G)){
                cout << " ";
            }
        }
        if (i!=GetLastIdxBrs(*G)){
            cout << endl;;
        }
    }
}

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (Graph G){
    return (BrsMin);
}
/* Mengirimkan indeks baris terkecil M */
indeks GetFirstIdxKol (Graph G){
    return (KolMin);
}
/* Mengirimkan indeks kolom terkecil M */
indeks GetLastIdxBrs (Graph G){
    return(NBrsEff(G)-1+BrsMin);
}
/* Mengirimkan indeks baris terbesar M */
indeks GetLastIdxKol (Graph G){
    return(NKolEff(G)-1+KolMin);
}

vector<string> bacaGraph(string &filePath, Graph * G) {
    ifstream in(filePath);
    char c;
    vector<string> bahan;

    int jumlahkata = 0;
    int i = 0;
    if(in.is_open()) {
        while(in.good()) {
            string tp;
            while(getline(in, tp)){  //read data from file object and put it into string.
                string delimiter = ", ";
                string titik = ".";
                size_t pos = 0;
                string token;
                while ((pos = tp.find(delimiter)) != string::npos || (pos = tp.find(titik)) != string::npos) {
                    token = tp.substr(0, pos);
                    bahan.push_back(token);
                    if(tp.find(delimiter)){
                        tp.erase(0, pos + delimiter.length());
                    }else if (tp.find(titik)){
                        tp.erase(0, pos + titik.length());
                    }
                }
                bahan.push_back("\n");
            }
        }
    }

    if(!in.eof() && in.fail())
        cout << "error reading " << filePath << endl;

    in.close();

    return bahan;
}  

map<string, int> matkul (vector<string> senaraimatkul){
    map<string, int> dict;
    int indeks = 0;
    for (int i=0; i<senaraimatkul.size(); i++){
        if (dict.count(senaraimatkul.at(i))<=0 && senaraimatkul.at(i)!="\n"){
            dict.insert(make_pair(senaraimatkul.at(i), indeks));
            indeks++;
        }
    }
    return dict;
}

string key_matkulnya_apa (map<string, int> matakuliah, int valuenya){
    string key = "";
    for (auto &i : matakuliah) {
        if (i.second == valuenya) {
            key = i.first;
            break;
        }
    }
    return key;
}


int main(int argc, char const *argv[]){
    Graph G;
    string a = "prereq.txt";
    vector<string> wow = bacaGraph(a, &G);
    /*
    for (int i=0; i<wow.size(); i++){
        cout << wow[i];
    }
    */
    map<string,int> mapnya = matkul(wow);
    for(auto it = mapnya.cbegin(); it != mapnya.cend(); ++it)
    {
        cout << it->first << " " << it->second << endl;
    }
    makeGraph(&G, mapnya, wow);
    TulisGraph(&G);
    cout << endl;
    return 0;
}