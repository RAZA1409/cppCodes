#include<iostream>
using namespace std;

class Complex{
int real,imag;
public:
Complex(int r=0,int i=0){
    real=r;
    imag=i;
}
Complex operator+(Complex c){
    Complex temp;
    temp.real=real+c.real;
    temp.imag=imag+c.imag;
    return temp;
}
void show(){
    cout<<real<<" + "<<imag<<"i"<<endl;
}

};
int main(){
    Complex c1(3,5);
    Complex c2(4,3);
    Complex c3 = c1 + c2;
    c3.show(); 
}