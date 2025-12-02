#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream ifile("newfile.txt"); 

    if (!ifile) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    string word;
    int wordCount = 0;

    
    while (ifile >> word) {
        wordCount++;
    }
    cout << "Total number of words: " << wordCount << endl;

    ifile.close(); }
