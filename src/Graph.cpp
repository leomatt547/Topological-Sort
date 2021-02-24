#include <iostream>
#include <fstream>
#include <string>
#include "Graph.hpp"

using namespace std;

Graph::Graph(int m, int n){
    this->m = m;
    this->n = n;
}

void Graph::read_graph(){
    fstream file;
	file.open("prereq.txt",ios::in); //open a file to perform read operation using file object
    if (file.is_open()){ //checking whether the file is open
        string tp;
        while(getline(file, tp)){ //read data from file object and put it into string.
            cout << tp << "\n"; //print the data of the string
        }
        file.close(); //close the file object.
    }
}

void Graph::disp_graph(){
	cout<<"Matrix Elements:";
	for(int i=0;i<m;i++){
	    for(int j=0;j<n;j++){
		cout<<G[i][j]<<"  ";
	    cout<<endl;
	    }  
    }
}

void Graph::set_graph(){
	for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
                G[i][j]=0;
            }
        }
    }
		  

int main(int argc, char const *argv[])
{
    int m,n,p,q;
    cout<<"enter first matrix size ?";
    cin>>m>>n;
    Graph m1(m,n);
    m1.read_graph();
    cout<<"enter second matrix size ?";
    cin>>p>>q;
    Graph m2(p,q);
    m2.read_graph();;
    m1.disp_graph();
    m2.disp_graph();
    return 0;
}