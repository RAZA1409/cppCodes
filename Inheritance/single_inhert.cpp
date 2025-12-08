#include<iostream>
using namespace std;

class Employee{
    public:
    void work(){
        cout<<"Employee Working in Base Class"<<endl;
    }

};

class Devloper:public Employee{
public:
void code(){
    cout<<"Devloper writes code in Derived Class"<<endl;
}

};
int main(){
    Devloper dev;
    dev.work();
    dev.code();
   
   
    return 0;
}