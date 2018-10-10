#include <iostream>

using namespace std;


int main() {
    int t;
    scanf("%d", &t);
    int *arr = new int[t+1];
    arr[0] = 0;
    arr[1] = 1;
    
    for(int i=2;i<=t;i++)
        arr[i] = arr[i-1] + arr[i-2];
    
    printf("Ith fib is %d\n", arr[t]);
    
    return 0;
}
