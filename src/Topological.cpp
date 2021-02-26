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
    int i = N - 1;
    int j = N - 1;

    for (int at = 0; at < N; at++){
        if (V(*T).at(at) == false){
            cout << at << endl;
            for (int k=0; k < Ordering(*T).size();k++){
                cout << V(*T).at(k) << " ";
            }
            cout<<endl;
            //cout << "V[at] = "<< V(*T).at(at) << endl;
            //cout << "bisa" << endl;
            i = dfs(i, j, at, T, G);
            j -= 1;
            i = N - 1;
        }
    }
}

int dfs(int i, int j, int at,Toposort *T, Graph G){
    V(*T).at(at) = true;
    //cout << "V["<< at << "] dfs = " << V(*T).at(at) << endl;
    for (int b = 0; b < (Ordering(*T).size()); b++){
        if (Elmt(G,at,b) == 1){
            for (int k=0; k < Ordering(*T).size();k++){
                cout << V(*T).at(k) << ", ";
            }
            cout<<endl;
            if(V(*T).at(b) == false){
                cout << "b nya adalah "<< b << endl;
                i = dfs(i, j, b, T, G);
            }
        }  
    } 
    Ordering(*T).at(i).at(j) = at;
    return i-1;
}

vector<vector<string>> terjemahkan_key (Toposort *T, map<string,int> matkul){
    vector<vector<string>> hasil;
    for (int i=Ordering(*T).size()-1; i>=0; i--){
        hasil.push_back(vector<string>());
        for (int j = Ordering(*T).at(i).size()-1; j>=0; j--){
            //cout << "bisa" << endl;
            if(Ordering(*T).at(i).at(j)==Nil){
                break;
            }else{

                int a = Ordering(*T).size()-1-i;
                int b = Ordering(*T).at(i).size()-1-j;
                hasil.at(a).push_back(key_matkulnya_apa(matkul, Ordering(*T).at(i).at(j)));
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
    /*
    for (int i=0; i< GetnumberOfNodes(G); i++){
        cout << Ordering(T).at(i) << endl;
    }*/
    hasil = terjemahkan_key(&T, mapnya);
    for (int i=0; i< hasil.size(); i++){
        cout << "Semester "<<i+1<< " : ";
        for(int j=0; j < hasil.at(i).size(); j++){
            cout << hasil.at(i).at(j) << ",";
        }
        cout << endl;
    }
    return 0;
}
