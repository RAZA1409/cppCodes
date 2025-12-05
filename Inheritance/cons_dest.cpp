#include<iostream>
using namespace std;

class Base{
    public:
    Base(){
        cout<<"Base constructor"<<endl;
    }
    ~Base(){
        cout<<"Base destructor"<<endl;
    }
};
class Child:public Base{
    public:
    Child(){
        cout<<"Base constructor of child class"<<endl;
    }
    ~Child(){
        cout<<"Base destructor of child class"<<endl;
    }
};
int main(){
    Child c;
}