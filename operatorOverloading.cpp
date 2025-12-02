#include<iostream>
using namespace std;

class Number{
    int num;
public:
    Number(int val=0){
        num=val;
    }
    Number operator -(){
        Number temp;
        temp.num =-num;
        return temp;
    }
    void display(){
        cout<<"Value "<<num<<endl;
    }
};
int main(){
    Number n(10);
    Number n2;
    n2=-n;
    n.display();
    n2.display();
}