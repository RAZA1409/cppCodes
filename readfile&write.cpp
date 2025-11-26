#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main(){

    //read from newfile,txt
    ifstream fin("newfile.txt");
    if(!fin){
        cerr <<"Cannot open newfile.txt\n";
        return 1;
    }
    ofstream fout("output.txt");
    if(!fout){
        cerr <<"cannot open or create output.txt\n";
        return 1;
    }
    string line;
    while(getline(fin,line)){
        fout<<line<<'\n';
    }
    fin.close();
    fout.close();
    cout<<"File copied to output.txt\n";
    return 0;
}
