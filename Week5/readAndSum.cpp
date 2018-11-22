#include <iostream>

using namespace std;

int recSum(int n){
    // Base case
    if(n == 0) return 0;
    
    // Read
    int a;
    scanf("%d", &a);
    
    // Recursive calls
    return a + recSum(n-1);
    
}

int main() {
    int n;
    scanf("%d", &n);
    
    printf("%d\n", recSum(n));
    return 0;
}
