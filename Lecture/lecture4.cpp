#include <iostream>

using namespace std;

void maximize(int &a, int &b, int &c){
    int arr[] = {a, b, c};

    int max = 0;

    for(int i=0;i<3;i++) if(arr[i] > max) max = arr[i];

    a = max, b = max, c = max;
    
    // Murat's method
    a = a > b ? a: b;
    a = b = c = (a > c ? a : c);
    
}

int main(){
    int a,b,c;
    scanf("%d %d %d", &a, &b, &c);
    maximize(a,b,c);
    printf("%d %d %d\n", a, b, c);
}
