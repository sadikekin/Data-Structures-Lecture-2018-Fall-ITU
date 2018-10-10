#include <iostream>

using namespace std;

int main() {
    int a = 5;
    cout << "The address of the a is " << &a << endl;
    
    int *b = &a; // The address of a is equal to pointer of b.
    cout << "The address of the b is " << b << " The value of the b is " << *b << endl;
    
    int allChanger = 50;
    *b = allChanger;
    cout << "The address of the a is " << &a << " The value of the a is " << a << endl;
    cout << "The address of the b is " << b << " The value of the b is " << *b << endl;
    
    return 0;
}
