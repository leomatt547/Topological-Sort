#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map> 
#include "Graph.hpp"

using namespace std;

void makeGraph(int NB, int NK, Graph * G){
    NBrsEff(*G)=NB;
    NKolEff(*G)=NK;
    indeks i,j;
    for (i = BrsMin; i < NB; i++){
        for (j = KolMin; j < NK; j++){
            Elmt(*G, i, j) = 0;
        }
    }
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
                    //cout << token << endl;
                    bahan.push_back(token);
                    if(tp.find(delimiter)){
                        tp.erase(0, pos + delimiter.length());
                    }else if (tp.find(titik)){
                        tp.erase(0, pos + titik.length());
                    }
                }
                bahan.push_back("\n");
            }
            //in.get(c);
            /*if(c==','){
                bahan[jumlahkata][i] = '\0';
                i = 0;
                jumlahkata++;
            }else if (c=='.'){
                bahan[jumlahkata][i] = '?';
                jumlahkata++;
                i = 0;
            }else{
                bahan[jumlahkata][i] = c;
                i++;
            }*/
        }
    }

    if(!in.eof() && in.fail())
        cout << "error reading " << filePath << endl;

    in.close();

    return bahan;
}  

bool matkulfound (map<string,int> matkul, string target){
    bool found = false;
    int i = 0;
    while(i<matkul.size() && !found){
        if(matkul.at(target)==i){
            found = true;
        }
    }
    return found;
}
map<string, int> matkul (vector<string> senaraimatkul){
    map<string, int> dict;
    int indeks = 0;
    for (int i=0; i<senaraimatkul.size(); i++){
        if (!matkulfound(dict,senaraimatkul[i])){
            dict.insert({senaraimatkul.at(i), indeks});
            indeks++;
        }
    }
    return dict;
}

int main(int argc, char const *argv[]){
    Graph G;
    string a = "prereq.txt";
    vector<string> wow = bacaGraph(a, &G);
    for (int i=0; i<wow.size(); i++){
        cout << wow[i];
    }
    map<string,int> mapnya = matkul(wow);
    //cout << mapnya.at("C1") << endl;
    return 0;
}