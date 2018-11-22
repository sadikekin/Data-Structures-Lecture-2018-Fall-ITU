#include <iostream>

using namespace std;

void fillArr(int i, int *myArr){
    // Base Case
    if(i < 0){
        return;
    }
    
    // Fill Arr
    myArr[i] = 10-i;
    
    // Call func
    fillArr(i-1, myArr);
}

void printArray(int i, int *myArr){
    // Base Case
    if(i >= 10){
        return;
    }
    
    // Print arr
    printf("%d ", myArr[i]);
    
    // Call func
    printArray(i + 1, myArr);
}

int sumArray(int i, int *myArr){
    if(i >= 10){
        return -10;
    }
    
    return myArr[i] + sumArray(i+1, myArr);
}


int main() {
    
    int myArr[10];
    
    fillArr(9, myArr);
    
    printArray(0, myArr);
    
    printf("\n");
    
    
    printf("%d\n", sumArray(0, myArr));
    
    
    
    return 0;
}
