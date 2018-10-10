#include <iostream>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    
    int *arr = new int[n];
    for(int i=0;i<n;i++) scanf("%d", arr + i);
    
    int searchNum;
    scanf("%d", &searchNum);
    
    bool isInside = false;
    for(int i=0;i<n;i++) if(arr[i] == searchNum) isInside = true;
    
    printf(isInside ? "Yes\n" : "No\n");
}
