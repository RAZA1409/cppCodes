#include<iostream>
using namespace std;

class Employee{
    public:
    void work(){
        cout<<"Employee Working in Base Class"<<endl;
    }
protected:
    int salary=200;
private:
    int age=20;
};

class Devloper:public Employee{
public:
void code(){
    cout<<"Devloper writes code in Derived Class"<<endl;
}

void show_Salary(){
    cout<<"Employee Salary is "<<salary<<endl;
}

};
int main(){
    Employee e;
    e.work();
    Devloper dev;
    dev.code();
    dev.work();
    dev.show_Salary();
    return 0;
}