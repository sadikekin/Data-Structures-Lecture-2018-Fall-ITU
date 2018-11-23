#include <iostream>

using namespace std;

int fastExp(int base, int pow){
    // Base-1
    if(pow == 0){
        return 1;
    }
    
    // Base-2
    if(pow == 1){
        return base;
    }
    
  
    // recursive calls
    int half = fastExp(base, pow/2);
    if(pow%2 == 1){
        return half * half * base;
    }else {
        return half*half;
    }
    
}

int main() {
    printf("%d\n",fastExp(2, 10));
    return 0;
}
