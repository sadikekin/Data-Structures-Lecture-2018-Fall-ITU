#include <iostream>
#include <cstring> // memcpy
using namespace std;

int currentSize = 0;
int currentCapacity = 2;
int *arr;

void push(int val){
    arr[currentSize] = val;
    
    currentSize++;
    if(currentSize >= currentCapacity){
        currentCapacity *= 2; // Increase the capacity
        int *newArr = new int[currentCapacity]; // Allocate new dynamic array
        memcpy(newArr, arr, sizeof(int) * currentSize); // Copy old values to new array
        
        delete[] arr; // Delete old array
        arr = newArr; // Change the pointer
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
    
    for(int i=0;i<currentSize;i++) {
      cout << arr[i] << endl;
    }
    cout << "Current size is " << currentSize << " Current capacity is " << currentCapacity << endl;
    return 0;
}

