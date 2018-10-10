#include <iostream>

using namespace std;

int *arr;
int size;


void deleteArr(int k) {
    int *temp = new int[size];
    for(int i=0;i<size;i++) temp[i] = arr[i];
    
    int arrCounter = 0;
    for(int i=0;i<size;i++){
        if(i != k){
            arr[arrCounter] = temp[i];
            arrCounter++;
        }
    }
    
    size--;
    delete[] temp;
}

int main() {
    size = 8;
    arr = new int[size];
    
    for(int i=0;i<size;i++) arr[i] = i+1;
    
    deleteArr(1);
    deleteArr(2);
    
    for(int i=0;i<size;i++) cout << arr[i] << endl;
    
    
    return 0;
}
