#include <iostream>

using namespace std;

void changeSecondValue(int *arr) {
    arr[1] = 0;
}

int main() {
    // Create an array
    int *arr = new int[10];
    for(int i=0;i<10;i++) arr[i] = 2*i-5;
    
    // Change the second value
    changeSecondValue(arr);
    
    // Print the array
    for(int i=0;i<10;i++) cout << arr[i] << endl;
    
    return 0;
}
