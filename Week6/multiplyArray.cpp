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

// Tail recursive example
int multiplyArray(int i, int totalMul,  int *myArr){
    if(i >= 10){
        return totalMul;
    }
    
    return multiplyArray(i+1, totalMul * myArr[i], myArr);
}


int main() {
    
    int myArr[10];
    
    fillArr(9, myArr);
    
    printArray(0, myArr);
    
    printf("\n");
    
    
    printf("%d\n", multiplyArray(0, 1, myArr));
    
    
    
    return 0;
}

