#include <iostream>
#include <vector>
#include <string>
#include "Topological.hpp"
#include "Graph.hpp"

using namespace std;

void topsort(Toposort *T, Graph G){
    int N = GetnumberOfNodes(G);
    //cout << GetnumberOfNodes(G) << endl;
    for (int a = 0; a<N ; a++){
        Ordering(*T).push_back(vector<int>());
        V(*T).push_back(false);
        for(int b = 0; b < N; b++){
            Ordering(*T).at(a).push_back(Nil);
        }
    }
    //cout << "size ordering " << Ordering(*T).size() << endl;
    int i = 0;
    int j = N - 1;

    for (int at = 0; at < N; at++){
        if (V(*T).at(at) == false){
            //cout << at << endl;
            /*for (int k=0; k < Ordering(*T).size();k++){
                cout << V(*T).at(k) << " ";
            }
            cout<<endl;
            */
            //cout << "V[at] = "<< V(*T).at(at) << endl;
            //cout << "bisa" << endl;
            i = dfs(i, j, at, T, G);
            j -= 1;
            i = 0;
        }
    }
}

int dfs(int i, int j, int at,Toposort *T, Graph G){
    V(*T).at(at) = true;
    //cout << "V["<< at << "] dfs = " << V(*T).at(at) << endl;
    for (int b = 0; b < (Ordering(*T).size()); b++){
        if (Elmt(G,at,b) == 1){
            /*for (int k=0; k < Ordering(*T).size();k++){
                cout << V(*T).at(k) << ", ";
            }
            cout<<endl;*/
            if(V(*T).at(b) == false){
                i = dfs(i, j, b, T, G);
                //cout << "b nya adalah "<< b << endl;
            }
        }
    }
    Ordering(*T).at(i).at(j) = at;
    return i+1;
}

void sikat (Toposort *T){
    vector<vector<int>> produk;
    vector<vector<int>> produk2;
    for (int i = Ordering(*T).size()-1; i >= 0 ; i--){
        produk.push_back(vector<int>());
        if (Ordering(*T).at(i).at(Ordering(*T).size()-1)==Nil){
            produk.pop_back();
        }else{
            for (int j = Ordering(*T).size()-1; j >= 0; j--){
                if (Ordering(*T).at(i).at(j)==Nil){
                    produk.at(produk.size()-1).push_back(Nil);
                }
                else if (Ordering(*T).at(i).at(j)!=Nil){
                    //cout << produk.at(produk.size()-1).size() << endl;
                    produk.at(produk.size()-1).push_back(Ordering(*T).at(i).at(j));
                }
            }
        }
    }
    /*
    for (int i = 0; i < produk.size(); i++){
        for (int j = 0; j < produk.at(i).size(); j++){
            if(produk.at(i).at(produk.size()-1)!=Nil){
                for (int k = 0; k < produk.at(i).size(); k++){
                    if(produk.at(i).at(produk.size()-1)!=Nil){
                        
                    }
                }
            }
        }
    }
    */
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
    int gagal = 0;
    int berhasil = 0;
    sikat(T);
    for (int i= 0; i <= Ordering(*T).size()-1; i++){
        hasil.push_back(vector<string>());
        //for (int j = Ordering(*T).at(i).size()-1; j >= 0; j--){
        for (int j = 0;  j <= Ordering(*T).at(i).size()-1; j++){
            //cout << "bisa" << endl;
            /*if(Ordering(*T).at(i).at(Ordering(*T).at(i).size()-1)==Nil){
                //cout << "gagal ke i = " << i << endl;
                hasil.pop_back();
                gagal++;
                break;
            }*/
            if (Ordering(*T).at(i).at(j)==Nil){
                hasil.at(hasil.size()-1).push_back(" ");
            }else if (Ordering(*T).at(i).at(j)!=Nil){
                //cout << "size ordering indeks ke =  " << hasil.size()-1 << endl;
                hasil.at(hasil.size()-1).push_back(key_matkulnya_apa(matkul, Ordering(*T).at(i).at(j)));
                //cout << "berhasil ke i = " << i << endl;
                //cout << "berhasil indeks ke = " << berhasil << endl;
                berhasil++;
            }
        }
    }
    return hasil;
}
int main(int argc, char const *argv[])
{
    Graph G;
    Toposort T;
    vector<vector<string>> hasil;
    string a = "../test/prereq.txt";
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
    //TulisGraph(&G);
    //cout << endl;
    //cout << GetnumberOfNodes(G) << endl;
    topsort(&T, G);
    for (int i=0; i< GetnumberOfNodes(G); i++){
        for (int j=0; j< GetnumberOfNodes(G); j++){
            cout << Ordering(T).at(i).at(j) << " ";
        }
        cout << endl;
    }
    cout << endl;
    /*
    for (int i=0; i< GetnumberOfNodes(G); i++){
        for (int j=0; j< GetnumberOfNodes(G); j++){
            cout << Ordering(T).at(i).at(j) << " ";
        }
        cout << endl;
    }*/
    /*
    for (int i=0; i< GetnumberOfNodes(G); i++){
        cout << Ordering(T).at(i) << endl;
    }
    */
   
    hasil = terjemahkan_key(&T, mapnya);
    /*for (int i=0; i< hasil.size(); i++){
        for (int j=0; j< hasil.at(i).size(); j++){
            cout << hasil.at(i).at(j) << " ";
        }
        cout << endl;
    }
    */
    for (int i=0; i< hasil.size(); i++){
        cout << "Semester "<<i+1<< " : ";
        for(int j=0; j < hasil.at(i).size(); j++){
            cout << hasil.at(i).at(j) << " ";
        }
        cout << endl;
    }
    return 0;
}
