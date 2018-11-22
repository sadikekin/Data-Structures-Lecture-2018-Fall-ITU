#include <iostream>

using namespace std;

int fac(int i){
    // Base case
    if(i <= 1) return 1;
    
    // Recursive calls
    return i * fac(i-1);
}
int main(){
    // Call fac
    printf("%d\n", fac(5));
    return 0;
}
