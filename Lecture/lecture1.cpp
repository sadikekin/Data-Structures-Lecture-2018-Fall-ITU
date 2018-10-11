#include <iostream>

using namespace std;

int main() {
    int a = 5;
    cout << "The address of a is " << &a << endl;
    
    int *b = &a;
    
    *b = 20;
    
    int c = 50;
    b = &c;
    
    cout << "The value of *b " << *b << endl;
    cout << "The value of real b " << b << endl;
    cout << "The address of b" << &b << endl;
    cout << "The value of c " << &c << endl;
    cout << "The new value of a " << a << endl;
    cout << "The new address of a " << &a << endl;
    return 0;
}
