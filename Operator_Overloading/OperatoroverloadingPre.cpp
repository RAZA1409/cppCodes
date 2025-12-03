#include<iostream>
using namespace std; 
class Counter{
    int value;
    public:
    Counter(int v=0){
        value=v;
    }
    void operator ++(){
        value++;
    }
    void show(){
        cout<<"Value: "<<value<<endl;
    }
};
int main(){
    Counter c(10);
    ++c;
    c.show();
}