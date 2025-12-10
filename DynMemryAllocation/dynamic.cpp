#include<iostream>
using namespace std;


int main(){
    int *ptr= new int;
    *ptr=10;
    cout<<"The value stored in ptr: "<<*ptr<<endl;
    delete ptr;
    
   
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    int *arr = new int[n];
    cout<<"Enter the values in array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    delete[]arr;

}