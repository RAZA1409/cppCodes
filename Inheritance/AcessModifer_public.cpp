#include<iostream>
using namespace std;

class base{
public:
    int a=10;
protected:
    int b=20;
private:
    int c=30;
};

class derived:public base{
    public:
    void showData(){
    cout<<"Value of a is "<<a<<endl;
    cout<<"Value of b is "<<b<<endl;
    // cout<<"Value of c is"<<c;  ////private not accessible
}
};

int main(){
    derived d;
    d.showData();
    cout<<"Outside acces derived class a is "<<d.a<<endl;
    // cout<<"Outside acces derived class b is "<<d.b<<endl; // protected Not accessible
}