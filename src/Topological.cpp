#include <iostream>
#include <vector>
#include "Topological.hpp"
#include "Graph.hpp"

using namespace std;

void topsort(Toposort *T, Graph G){
    int N = GetnumberOfNodes(G);
    for (int j = 0; j<N ; j++){
        V(*T).push_back(false);
        Ordering(*T).push_back(0);
    }
    //cout << "size ordering " << Ordering(*T).size() << endl;
    int i = N - 1;

    for (int at = 0; at < N; at++){
        if (V(*T).at(at) == false){
            //cout << "V[at] = "<< V(*T).at(at) << endl;
            //cout << "bisa" << endl;
            i = dfs(i, at, T, G);
        }
    }
}

int dfs(int i, int at,Toposort *T, Graph G){
    V(*T).at(at) = true;
    //cout << "V["<< at << "] dfs = " << V(*T).at(at) << endl;
    for (int b = 0; b < Ordering(*T).size(); b++){
        if (Elmt(G,at,b) == 1){
            /*for (int k=0; k<Ordering(*T).size();k++){
                cout << V(*T).at(k) << ", ";
            }
            cout<<endl;*/
            if(V(*T).at(b) == false){
                //cout << b << endl;
                i = dfs(i, b, T, G);
            }
        }
    }
    Ordering(*T).at(i) = at;
    return i-1;
}

vector<string> terjemahkan_key (Toposort *T, map<string,int> matkul){
    vector<string> hasil;
    for (int i = 0; i < Ordering(*T).size();i++){
        hasil.push_back(key_matkulnya_apa(matkul, Ordering(*T).at(i)));
    }
    return hasil;
}
int main(int argc, char const *argv[])
{
    Graph G;
    Toposort T;
    vector<string> hasil;
    string a = "prereq.txt";
    vector<string> wow = bacaGraph(a, &G);
    /*
    for (int i=0; i<wow.size(); i++){
        cout << wow[i];
    }
    */
    map<string,int> mapnya = matkul(wow);
    /*for(auto it = mapnya.cbegin(); it != mapnya.cend(); ++it)
    {
        cout << it->first << " " << it->second << endl;
    }
    */
    makeGraph(&G, mapnya, wow);
    //TulisGraph(&G);
    //cout << endl;
    //cout << GetnumberOfNodes(G) << endl;
    topsort(&T, G);
    /*
    for (int i=0; i< GetnumberOfNodes(G); i++){
        cout << Ordering(T).at(i) << endl;
    }*/
    hasil = terjemahkan_key(&T, mapnya);
    for (int i=0; i< GetnumberOfNodes(G); i++){
        cout << "Semester "<<i+1<< " : "<<hasil.at(i) << endl;
    }
    return 0;
}
