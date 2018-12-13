#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    stack<vector<int>> myStack;
    vector<int> vec(5);
    
    // append values
    myStack.push(vec);
    vec.clear();
    vec.resize(10, 9);
    myStack.push(vec);
    
    while(!myStack.empty()){
        // Element in the stack
        auto el = myStack.top();
        myStack.pop();
        
        // iterate through vector
        for(auto val : el){
            printf("%d ", val);
        }
        printf("\n");
        
        
    }
    
    return 0;
}
