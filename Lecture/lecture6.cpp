#include <iostream>

using namespace std;

int cap = 0;
int size = 2;
int *arr;

void push(int a) {
    arr[cap] = a;
    cap++;
    if(cap >= size){
        int *temp = new int[size];
        for(int i=0;i<size;i++) temp[i] = arr[i];
        
        delete[] arr;
        size *= 2;
        arr = new int[size];
        
        for(int i=0;i<cap;i++) arr[i] = temp[i];
        
        delete[] temp;
    }
}


int main() {
    arr = new int[size];
    push(1);
    cout << "size: " << size << endl;
    push(2);
    cout << "size: " << size << endl;
    push(3);
    cout << "size: " << size << endl;
    push(4);
    cout << "size: " << size << endl;
    push(5);
    cout << "size: " << size << endl;
    push(6);
    cout << "size: " << size << endl;
    push(0);
    cout << "size: " << size << endl;
    push(5);
    cout << "size: " << size << endl;
    push(6);
    cout << "size: " << size << endl;
    push(0);
    
    for(int i=0;i<cap;i++) cout << arr[i] << endl;
    delete[] arr;
    return 0;
}
