#include <iostream>

using namespace std;

int main() {
    int a = 5; 
    
    int &b = a;
    
    cout << "The value of b " << b << endl;
    cout << "The address of b " << &b << endl;
    cout << "The address of a" << &a << endl;
}
