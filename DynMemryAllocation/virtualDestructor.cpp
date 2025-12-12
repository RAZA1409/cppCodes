#include<iostream>
using namespace std;

class base{
    public:
    base(){
        cout<<"Base constructor\n";
    }
    virtual~base(){  //virtual keyword use karne sai derived class kai  destructor call ho zayenge 
        cout<<"Base destructor\n";
    }
};
class derived: public base{
    int* arr;
    public:
    derived(){
        arr = new int[5];
        cout<<"Derived  constructor\n";
    }
    ~derived(){
        delete[] arr;
        cout<<"Derived  destructor\n";
    }
};
int main(){
    base *ptr=new derived();
    delete ptr;
}
