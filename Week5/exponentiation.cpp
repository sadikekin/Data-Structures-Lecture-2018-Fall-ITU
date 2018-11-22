#include <iostream>

using namespace std;

int exp(int base, int pow){
    // Base
    if(pow == 0 ){
        return 1;
    }
    
    // Multiply recursively
    return base * exp(base, pow-1);
}

int main(){
    printf("%d\n", exp(2, 5));
    
    return 0;
}
