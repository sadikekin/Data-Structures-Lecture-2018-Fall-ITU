#include <iostream>

using namespace std;

int main() {
    int n = 5;
    int *arr = new int[n+1];
    arr[0]=0;
    arr[1]=1;
    for(int i=2;i<n+1;i++){
        arr[i]=arr[i-1]+arr[i-2];
    }
    cout<<arr[n];
    delete[] arr;
    
    return 0;
}
