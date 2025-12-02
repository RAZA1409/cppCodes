#include<iostream>
using namespace std; 
class Counter{
    int value;
    public:
    Counter(int v=0){
        value=v;
    }
    Counter operator ++(int){
        Counter temp=*this;
        value++;
        return temp;
    }
    void show(){
        cout<<"Value: "<<value<<endl;
    }
};
int main(){
    Counter c(10);
    Counter old =c++;
    old.show();
    c.show();
}