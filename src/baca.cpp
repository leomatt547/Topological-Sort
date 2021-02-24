#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;
void readCharFile(string &filePath) {
    ifstream in(filePath);
    char c;

    if(in.is_open()) {
        while(in.good()) {
            in.get(c);
            cout << c;
        }
        cout << endl;
    }

    if(!in.eof() && in.fail())
        cout << "error reading " << filePath << endl;

    in.close();
}
int main(){
    fstream file;
    /*newfile.open("tpoint.txt",ios::out);  // open a file to perform write operation using file object
    if(newfile.is_open()){ //checking whether the file is open {
        newfile<<"Tutorials point \n"; //inserting text
        newfile.close(); //close the file object
    }
	file.open("prereq.txt",ios::in); //open a file to perform read operation using file object
        file.close(); //close the file object.
    }*/
    string a = "prereq.txt";
    readCharFile(a);
}