/*File Graph
Nama : Leonard Matheus
NIM : 13519215
Kelas : K-04
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map> 
#include "13519215-Graph.hpp"

using namespace std;

//Membaca input file dan membuat vektor string untuk dibuatkan mapnya
vector<string> bacaGraph(string &filePath, Graph * G) {
    //merujuk file input
    ifstream in(filePath);
    char c;
    vector<string> bahan;

    int jumlahkata = 0;
    int i = 0;
    //Jika file terbuka, maka ...
    if(in.is_open()) {
        //Ketika file terbuka, maka ...
        while(in.good()) {
            string tp;
            while(getline(in, tp)){  //membaca dari objek file dan menyimpan dalam string.
                //Inisiasi filter bila ada koma dan titik
                string delimiter = ", ";
                string titik = ".";
                size_t pos = 0;
                string token;
                while ((pos = tp.find(delimiter)) != string::npos || (pos = tp.find(titik)) != string::npos) {
                    //ekstraksi token dari awal sampai diketemukan koma atau titik
                    token = tp.substr(0, pos);
                    //Push back ke loyang kita yang berupa vektor string
                    bahan.push_back(token);
                    //Kalau ketemu delimiternya, hapus sepanjang panjang demiliter
                    if(tp.find(delimiter)){
                        tp.erase(0, pos + delimiter.length());
                    }else if (tp.find(titik)){
                        tp.erase(0, pos + titik.length());
                    }
                }
                //masukkan enter apabila berbeda baris
                bahan.push_back("\n");
            }
        }
    }

    //Error saat membaca file
    if(!in.eof() && in.fail())
        cout << "Error saat membuka " << filePath << endl;

    //Tutup File
    in.close();

    return bahan;
}  

//Mengekstraksi list mata kuliah yang dibentuk menjadi matriks graph
void makeGraph(Graph * G, map<string,int> list_matkul, vector<string> inputmatkul){
    //inisiasi baris efektif dan kolom efektif dari list_matkul yang dibaca dari fungsi bacagraph
    NBrsEff(*G)=list_matkul.size();
    NKolEff(*G)=list_matkul.size();
    int NB, NK = list_matkul.size();
    int valuekiri, valuekanan = 0;
    indeks i,j,k;
    //Isi matriks dengan 0 semuanya
    for (i = BrsMin; i < NB; i++){
        for (j = KolMin; j < NK; j++){
            Elmt(*G, i, j) = 0;
        }
    }
    string kanan = "";
    string kiri = "";
    for (k = 0; k<(inputmatkul.size()); k++){
        //Bila string kiri tidak ada isi, langsung jadikan sebagai graph dependencies dan masukkan ke graph
        if (kiri == "" || inputmatkul.at(k-1)=="\n"){
            kiri = inputmatkul.at(k);
        }
        //Isi matkul di kanannya
        kanan = inputmatkul.at(k);
        if (kiri != kanan && kanan !="\n"){
            valuekiri = list_matkul.at(kiri); 
            valuekanan = list_matkul.at(kanan);
            //Apabila sudah didapatkan pasangan simpul graph yang tepat yaitu valuekanan dan kirinya, masukkan ke matriks graph
            Elmt(*G, valuekanan, valuekiri) = 1;
        }
    }
}

//Menampilkan matriks graph ke layar
void TulisGraph (Graph *G){
    indeks i,j;
    for (i = GetFirstIdxBrs(*G); i <= GetLastIdxBrs(*G); i++){
        for (j = GetFirstIdxKol(*G); j <= GetLastIdxKol(*G); j++){
            cout << Elmt(*G,i,j);
            if (j!=GetLastIdxKol(*G)){
                cout << " ";
            }
        }
        //Apabila sudah di akhir baris, print newline
        if (i!=GetLastIdxBrs(*G)){
            cout << endl;
        }
    }
}

//Getter Indeks Pertama Baris Matriks Adjacency List
indeks GetFirstIdxBrs (Graph G){
    return (BrsMin);
}

//Getter Indeks Pertama Kolom Matriks Adjacency List
indeks GetFirstIdxKol (Graph G){
    return (KolMin);
}

//Getter Indeks Terakhir Baris Matriks Adjacency List
indeks GetLastIdxBrs (Graph G){
    return(NBrsEff(G)-1+BrsMin);
}

//Getter Indeks Terakhir Kolom Matriks Adjacency List
indeks GetLastIdxKol (Graph G){
    return(NKolEff(G)-1+KolMin);
}

//Getter jumlah node yang ada di graph
int GetnumberOfNodes(Graph G){
    return NBrsEff(G) - BrsMin;
}

//Membuat map antara nama matkulnya
map<string, int> matkul (vector<string> senaraimatkul){
    map<string, int> dict;
    int indeks = 0;
    for (int i=0; i<senaraimatkul.size(); i++){
        //Jika jumlah elemen senarai mata kuliah pada suatu key masih nol dan elemen bukan baris baru
        if (dict.count(senaraimatkul.at(i))<=0 && senaraimatkul.at(i)!="\n"){
            //Insert elemen senarai mata kuliah pada map dict untuk key baru berupa integer
            dict.insert(make_pair(senaraimatkul.at(i), indeks));
            indeks++;
        }
    }
    return dict;
}

//Untuk mendapatkan key dari indeks integer matkul yang ditanya
string key_matkulnya_apa (map<string, int> matakuliah, int valuenya){
    string key = "";
    //Auto iterasi pada mapnya
    for (auto &i : matakuliah) {
        if (i.second == valuenya) {
            key = i.first;
            break;
        }
    }
    return key;
}