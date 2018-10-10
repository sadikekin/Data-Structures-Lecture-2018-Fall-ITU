#include <iostream>

using namespace std;

void maximize(int &a, int &b, int &c){
    int arr[3] = {a, b, c};
    
    int maxVal = 0;
    
    for(int i=0;i<3;i++) if(arr[i] > maxVal) maxVal = arr[i];
    
    a = maxVal, b = maxVal, c = maxVal;
}

int main() {
    int a = 5, b = 10, c = 99;
    
    cout << "a: " << a << " b: " << b << " c: " << c << endl;
    
    maximize(a, b, c);
    
    cout << "a: " << a << " b: " << b << " c: " << c << endl;
    return 0;
}
