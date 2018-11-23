#include <iostream>

using namespace std;
// 2
// 3
// -1 -4 5  => 25
// 4
// 4 6 3 -10  => 61 (16 + 36 + 9)

int readBlockNums(int n){
    if(n == 0) return 0;
    
    // Read
    int a;
    scanf("%d", &a);
    
    // Return the output
    if(a > 0)
        return (a*a) + readBlockNums(n-1);
    else
        return readBlockNums(n-1);
}

void readBlock(int t){
    // Base
    if(t == 0) return;
    
    // Read
    int n;
    scanf("%d", &n);
    
    // Calculate the answer
    int ans = readBlockNums(n);
    
    printf("%d\n", ans);
    
    // Recursive calls
    readBlock(t-1);
    
}

int main(){
    int t;
    
    scanf("%d", &t);
    readBlock(t);
    
    return 0;
    
}
