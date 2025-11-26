#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main(){
    ifstream fin("numbers.txt");
    if(!fin){
        cerr<<"Cannot open numbers.txt\n";
        return 1;
    }
    ofstream fe("even.txt");
    ofstream fo("odd.txt");
    if(!fe || !fo){
        cerr<<"Cannot create even.txt or odd.txt files\n";
        return 1;
    }
    long x;
    while(fin >> x){
        if(x %2==0){
            fe<<x<<" ";
        }else{
            fo<<x<<" ";
        }
    }
    fin.close();
    fe.close();
    fo.close();
    return 0;

}