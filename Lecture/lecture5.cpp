#include <iostream>

using namespace std;

int main() {
    int n = 4;
    int *a = new int[3];
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    a[30] = 4;

    for(int i=0;i<30;i++) cout << a[i] << endl;
    
    delete[] a;
    
    return 0;
    
}
