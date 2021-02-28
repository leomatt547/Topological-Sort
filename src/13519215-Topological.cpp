/*File Topological
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

//Memproses Graph yang terbentuk dan mengembalikan matriks vektor integer yang sudah terurut
void topsort(Toposort *T, Graph *G){
    int N = GetnumberOfNodes(*G); //Mendapatkan jumlah node pada grafik
    for (int a = 0; a<N ; a++){
        Ordering(*T).push_back(vector<int>()); //Menyiapkan loyang untuk suatu baris vektor integer
        V(*T).push_back(false); //Mendefinisikan seluruh node berstatus false
        for(int b = 0; b < N; b++){
            //Menginisiasi semua nilai dalam matriks vektor integer menjadi Nil
            Ordering(*T).at(a).push_back(Nil);
        }
    }
    //Inisiasi nilai indeks i dan j yang akan diproses
    int i = N - 1;
    int j = N - 1;

    for (int at = 0; at < N; at++){
        //Mengecek apakah node yang akan dikunjungi bernilai false
        if (V(*T).at(at) == false){
            //Masuk ke dalam dfs secara rekursif
            i = dfs(i, j, at, T, G);
        }
        //Menyimpan di indeks terpisah setelah dfs selesai dipanggil
        j -= 1;
        i = N-1;
    }
}

//Membantu topsort dalam melakukan rekursif, menerima integer i,j dan node yang dituju
int dfs(int i, int j, int at,Toposort *T, Graph *G){
    //Saat node sudah dikunjungi, set status ke true
    V(*T).at(at) = true;
    for (int b = 0; b < (V(*T).size()); b++){ //mencari node yang dituju pada graph
        if (Elmt(*G,b,at) == 1){
            // Jika ada node yang dituju, kunjungi saja selama belum tersentuh
            if(V(*T).at(b) == false){
                //Rekursif lagi dong
                i = dfs(i, j, b, T, G);
            }
        }
    }
    //Masukkan ke vektor integer ordering
    Ordering(*T).at(i).at(j) = at;
    //Kurangi i sebesar 1
    return i-1;
}

bool cek_nil (vector<int> produk){
    bool found = true;
    int i = 0;
    while (i < produk.size() && found){
        if (produk.at(i) != Nil){
            found = false;
        }
        i++;
    }
    return found;
}
void sikat (Toposort *T){
    vector<vector<int>> produk;
    vector<vector<int>> produk2;
    for (int i = Ordering(*T).size()-1; i >= 0 ; i--){
        produk.push_back(vector<int>());
        if (cek_nil(Ordering(*T).at(i))){
            produk.pop_back();
        }else{
            for (int j = Ordering(*T).size()-1; j >= 0; j--){
                produk.at(produk.size()-1).push_back(Ordering(*T).at(i).at(j));
            }
        }
    }

    for (int i = 0; i < produk.size();i++){
        produk2.push_back(vector<int>());
        for (int j = 0; j < produk.at(i).size();j++){
            produk2.at(i).push_back(Nil);
        }
    }

    for (int j = 0; j < produk.at(0).size();j++){
        int k = 0;
        for (int i = 0; i < produk.size();i++){
            if (produk.at(i).at(j)!=Nil){
                produk2.at(k).at(j) = produk.at(i).at(j);
                k++;
            }
        }
    }

    Ordering(*T) = produk2;
}
vector<vector<string>> terjemahkan_key (Toposort *T, map<string,int> matkul){
    vector<vector<string>> hasil;
    for (int i= 0; i <= Ordering(*T).size()-1; i++){
        hasil.push_back(vector<string>());
        for (int j = 0;  j <= Ordering(*T).at(i).size()-1; j++){
            if (Ordering(*T).at(i).at(j)==Nil){
                hasil.at(hasil.size()-1).push_back("");
            }else if (Ordering(*T).at(i).at(j)!=Nil){
                hasil.at(hasil.size()-1).push_back(key_matkulnya_apa(matkul, Ordering(*T).at(i).at(j)));
            }
        }
    }
    return hasil;
}

void printSemester(vector<vector<string>> hasil){
    if (hasil.size()>8){
        cout << "Maaf, Penyusunan mata kuliah dibatasi hanya untuk 8 semester saja!" << endl;;
        cout << "Silahkan kurangi matakuliah pada prereq.txt" << endl;
    }else{
        cout << "<<Saran Pengambilan Mata Kuliah>>" << endl;
        for (int i=0; i< hasil.size(); i++){
            cout << "Semester "<<i+1<< " : ";
            for(int j=0; j <= hasil.at(i).size()-1; j++){
                if (hasil.at(i).at(j) == ""){
                    cout<<"";
                }else if (j == hasil.at(i).size()-1){
                    cout << hasil.at(i).at(j);
                }else{
                    cout << hasil.at(i).at(j) << ", ";
                }
            }
            cout << endl;
        }
    }
}

void show_Matkul_key(map<string,int> mapnya){
    for(auto it = mapnya.cbegin(); it != mapnya.cend(); ++it){
        cout << it->first << " " << it->second << endl;
    }
}