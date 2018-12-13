#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> q;
    // Push to the queue
    for(int i=1;i<=10;i++)
        q.push(i);
    // Print elements of the queue
    while(!q.empty()){
        cout << q.front() << endl;
        q.pop();
    }

}
