#include <iostream>
using namespace std;

class Math {
public:
    
    int add(int a, int b) {
        return a + b;
    }

    int add(int a, int b, int c) {
        return a + b + c;
    }
    
    float add(float a, float b) {
        return a + b;
    }
};

int main() {
    Math m;

    cout << "Add 2 integers: " << m.add(10, 20) << endl;
    cout << "Add 3 integers: " << m.add(10, 20, 30) << endl;
    cout << "Add 2 floats: " << m.add(5.5f, 2.3f) << endl;

    return 0;
}
