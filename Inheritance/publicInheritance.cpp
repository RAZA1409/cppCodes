#include <iostream>
using namespace std;

class Base {
public:
    int a = 10;      
protected:
    int b = 20;      
private:
    int c = 30;      
};

class DerivedPublic : public Base {
public:
    void showInside() {
        cout << "DerivedPublic a = " << a << endl; 
        cout << "DerivedPublic b = " << b << endl;  
        // cout << c;  //private not accessible
    }
};
class DerivedProtected : protected Base {
public:
    void showInside() {
        cout << "DerivedPublic a = " << a << endl; 
        cout << "DerivedPublic b = " << b << endl;  
        // cout << c;  //private not accessible
    }
};
class DerivedPrivate : private Base {
public:
    void showInside() {
        cout << "DerivedPublic a = " << a << endl; 
        cout << "DerivedPublic b = " << b << endl;  
        // cout << c;  //private not accessible
    }
};
class DerivedFourth : public DerivedPrivate {
public:
    void showInside() {
        // cout << "DerivedPublic a = " << a << endl; // Not accessible outside of the class
        // cout << "DerivedPublic b = " << b << endl;  // Not accessible outside of the class
        // cout << c;  //private not accessible
    }
};
int main() {
    DerivedPublic obj1;
    obj1.showInside();
    cout << "Outside access: obj1.a = " << obj1.a << endl; 

    DerivedProtected obj2;
    obj2.showInside();
    // cout << "Outside access: obj2.a = " << obj2.a << endl; // Not accessible outside of the class

    DerivedPrivate obj3;
    obj3.showInside();
    // cout << "Outside access: obj3.a = " << obj3.a << endl;// Not accessible outside of the class 

    DerivedFourth obj4;
    obj4.showInside();
    // cout << "Outside access: obj4.a = " << obj4.a << endl;// Not accessible outside of the class 
    return 0;
}