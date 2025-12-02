#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
    //read from file newfile.txt
    ifstream fin("newfile.txt");
    if(!fin){
        cerr<<"Cannot be able to read file\n";
        return 1;
    }
    ofstream fout("uppercase.txt");
    if(!fout){
        cerr<<"cannot be create or open upper.txt file\n";
        return 1;
    }

    string word;
    while(fin >> word){
        for(char &c : word){
            c=toupper(c);
        }

        fout<<word<<" ";
    }
    fin.close();
    fout.close();
    cout<<"words change to upper case in uppercase.txt\n";
    return 0;
}