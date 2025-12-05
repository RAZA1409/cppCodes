#include<iostream>
using namespace std;


class base{
    public:
    void name(){
    cout<<"This is a my name in Base class"<<endl;
}
};
class child:public base{
    public:
    void name(){
        base::name(); //We cann call base class function within a child class without creating it's object
        cout<<"This is a name in Child class"<<endl;
    }

};
int main(){
    child c;
    c.name();
    c.base::name();
}