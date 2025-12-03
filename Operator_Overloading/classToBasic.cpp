#include<iostream>
using namespace std;
class Number{
    int x;
    public:
    Number(int a){
        x=a;
    }
    operator int(){
        return x;
    }
};
int main(){
    Number n(50);
    int a=n;
    cout<<a;
}