#include <iostream>

using namespace std;

int currentSize = 0;
int currentCapacity = 2;
int *arr;

void push(int val){
    arr[currentSize] = val;
    
    currentSize++;
    if(currentSize >= currentCapacity){
        // Saving the values in the array
        int *tempArr = new int[currentCapacity];
        for(int i=0;i<currentSize;i++) tempArr[i] = arr[i];
        
        // Incrementing array's size
        delete[] arr;
        currentCapacity *= 2;
        arr = new int[currentCapacity];
        
        // Restoring the array.
        for(int i=0;i<currentSize;i++) arr[i] = tempArr[i];
        
        delete[] tempArr;
    }
}

int main() {
    arr = new int[currentCapacity];
    push(1);
    push(2);
    push(3);
    push(4);
    push(1);
    push(8);
    push(1);
    push(10);
    
    for(int i=0;i<currentSize;i++) cout << arr[i] << endl;
    cout << "Current size is " << currentSize << " Current capasity is " << currentCapacity << endl;
    return 0;
}

