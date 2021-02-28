#include <iostream>
#include <vector>
#include <string>
#include "Topological.hpp"
#include "Graph.hpp"

using namespace std;

void topsort(Toposort *T, Graph *G){
    int N = GetnumberOfNodes(*G);
    //cout << GetnumberOfNodes(G) << endl;
    for (int a = 0; a<N ; a++){
        Ordering(*T).push_back(vector<int>());
        V(*T).push_back(false);
        for(int b = 0; b < N; b++){
            Ordering(*T).at(a).push_back(Nil);
        }
    }
    //cout << "size ordering " << Ordering(*T).size() << endl;
    int i = N - 1;
    int j = N - 1;

    for (int at = 0; at < N; at++){
        if (V(*T).at(at) == false){
            i = dfs(i, j, at, T, G);
        }
        j -= 1;
        i = N-1;
    }
}

int dfs(int i, int j, int at,Toposort *T, Graph *G){
    //cout << "at adalah " << at << endl;
    V(*T).at(at) = true;
    for (int b = 0; b < (V(*T).size()); b++){
        if (Elmt(*G,b,at) == 1){
            //cout << "True/False? "<< V(*T).at(b) << endl;
            //cout << "b adalah "<< b << endl;
            if(V(*T).at(b) == false){
                //cout << "b adalah "<< b<< endl;
                i = dfs(i, j, b, T, G);
            }
        }
    }
    Ordering(*T).at(i).at(j) = at;
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
                //if (Ordering(*T).at(i).at(j)!=Nil){
                    //cout << produk.at(produk.size()-1).size() << endl;
                    produk.at(produk.size()-1).push_back(Ordering(*T).at(i).at(j));
                //}
            }
        }
    }
/*
    for (int i = 0; i < produk.size();i++){
        for (int j = 0; j < produk.at(i).size();j++){
            cout << produk.at(i).at(j) << " ";
        }
        cout << endl;
    }*/

    for (int i = 0; i < produk.size();i++){
        produk2.push_back(vector<int>());
        for (int j = 0; j < produk.at(i).size();j++){
            produk2.at(i).push_back(Nil);
        }
    }
    //cout << "bisa" << endl;

    for (int j = 0; j < produk.at(0).size();j++){
        int k = 0;
        for (int i = 0; i < produk.size();i++){
            if (produk.at(i).at(j)!=Nil){
                produk2.at(k).at(j) = produk.at(i).at(j);
                k++;
            }
        }
    }
    /*
    for (int i = 0; i < produk2.size();i++){
        for (int j = 0; j < produk2.at(i).size();j++){
            cout << produk2.at(i).at(j) << " ";
        }
        cout << endl;
    }*/
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
    for (int i = 0; i < hasil.size();i++){
        for (int j = 0; j < hasil.at(i).size();j++){
            cout << hasil.at(i).at(j) << " ";
        }
        cout << endl;
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

int main(int argc, char const *argv[])
{
    Graph G;
    Toposort T;
    vector<vector<string>> hasil;
    string a = "../test/prereq8.txt";
    vector<string> wow = bacaGraph(a, &G);
    
    for (int i=0; i<wow.size(); i++){
        cout << wow[i] << " ";
    }
    cout << endl;
    map<string,int> mapnya = matkul(wow);
    makeGraph(&G, mapnya, wow);
    TulisGraph(&G);
    cout << endl;
    show_Matkul_key(mapnya);
    //cout << GetnumberOfNodes(G) << endl;
    topsort(&T, &G);
    for (int i = 0; i < Ordering(T).size();i++){
        for (int j = 0; j < Ordering(T).at(i).size();j++){
            cout << Ordering(T).at(i).at(j) << " ";
        }
        cout << endl;
    }
    sikat(&T);
    for (int i = 0; i < Ordering(T).size();i++){
        for (int j = 0; j < Ordering(T).at(i).size();j++){
            cout << Ordering(T).at(i).at(j) << " ";
        }
        cout << endl;
    }
    hasil = terjemahkan_key(&T, mapnya);
    /*for (int i = 0; i < hasil.size();i++){
        for (int j = 0; j < hasil.at(i).size();j++){
            cout << hasil.at(i).at(j) << " ";
        }
        cout << endl;
    }*/
    printSemester(hasil);
    
    return 0;
}
