#include <iostream>

using namespace std;

int fibo(int a){
    if(a == 1 || a == 2) return 1;

    return fibo(a-1) + fibo(a-2);
}
int main() {
    printf("%d\n", fibo(5));
    return 0;
}
