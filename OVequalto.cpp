#include<iostream>
using namespace std;
 class Marks{
    int m;
    public:
    Marks(int x=0){
        m=x;
    }
    bool operator==(Marks obj){
        return m==obj.m;
    }
 };
 int main(){
    Marks m1(30);
    Marks m2(30);
    if(m1==m2){
        cout<<"Equal"<<endl;
    }else{
        cout<<"Not equal"<<endl;
    }
    return 0;
 }