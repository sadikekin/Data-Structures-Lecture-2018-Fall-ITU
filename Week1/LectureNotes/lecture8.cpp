#include <iostream>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d", arr+i);
    int t;
    scanf("%d", &t);
    
    bool flag = false;
    for(int i=0;i<n;i++) {
        if(*(arr+i) == t){
            flag = true;
        }
    }
    
    printf(flag ? "YES" : "NO");
    
    return 0;
}
