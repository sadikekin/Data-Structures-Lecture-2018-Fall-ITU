#include <iostream>

using namespace std;

void fTwo(int x);
void fOne(int x);

void fOne(int x){
    // Base
    if(x <= 0){
        return;
    }
    
    // Print
    printf("%d ", x);
    
    // Recursive call
    fTwo(x/2);
}

void fTwo(int x){
    // Base
    if(x <= 0){
        return;
    }
    
    // Print
    printf("%d ", x);
    
    // Recursive
    fOne(x-1);
}

int main(){
    
    fOne(19);
    
    printf("\n");
    return 0;
}
