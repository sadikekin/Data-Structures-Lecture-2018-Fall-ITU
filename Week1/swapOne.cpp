#include <iostream>

using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a = 5;
    int b = 50;
    
    cout << "The value of a is " << a << endl;
    cout << "The value of b is " << b << endl;
    
    swap(&a, &b);
    
    cout << "The value of a is " << a << endl;
    cout << "The value of b is " << b << endl;
    
    return 0;
}
