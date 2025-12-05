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

class derived_private:private base{
    public:
    void showData(){
    cout<<"Value of a is private "<<a<<endl;
    cout<<"Value of b is private "<<b<<endl;
    // cout<<"Value of c is"<<c;  ////private not accessible
}
};

int main(){
    derived_private dp;
    dp.showData();
    // cout<<"Outside acces derived class a is "<<dp.a<<endl; //not accecible bcs it is protected in base class
    return 0;
}