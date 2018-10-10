#include <iostream>

using namespace std;

int main() {
    // The second pointer access
    int a = 5; // Set a 5, again.
    cout << "The address of the a is " << &a << endl;
    
    int &b = a; // adress of b is equal to address of a.
    cout << "The address of the b is " << &b << " The value of the b is " << b << endl;
    
    int allChanger = 100;
    b = allChanger;
    cout << "The address of the a is " << &a << " The value of the a is " << a << endl;
    cout << "The address of the b is " << &b << " The value of the b is " << b << endl;
    return 0;
}



