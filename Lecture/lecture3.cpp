#include <iostream>

using namespace std;

void swapC(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapCpp(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int a=5,b=2;
    cout << "a is " << a << " b is " << b << endl;
    swapC(&a, &b);
    cout << "a is " << a << " b is " << b << endl;
    swapCpp(a, b);
    cout << "a is " << a << " b is " << b << endl;
    
}
