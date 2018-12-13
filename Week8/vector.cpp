#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void takeVector(vector<double> myVec){
    printf("I am in the function -> %lf\n", myVec[0]);
}

bool mySortFunc(int a, int b){
    return a < b;
}
int main() {
    // Create a vector
    vector<double> vec(6, 5);
    
    // Loop through it
    for(int i=0;i<vec.size();i++){
        printf("%lf ", vec[i]);
    }
    printf("\n");
    
    // Change elements
    for(auto &value : vec){
        value = 9;
    }
    // Another loop
    for(auto value : vec){
        printf("%lf ", value);
    }
    printf("\n");
    
    // Push back
    vec.push_back(5);
    vec.push_back(10);
    
    takeVector(vec);
    
    // Sort vector
    sort(vec.begin(), vec.end(), mySortFunc);
    // Another loop
    for(auto value : vec){
        printf("%lf ", value);
    }
    printf("\n");
    
    // Reverse
    reverse(vec.begin(), vec.end());
    
    printf("the first element -> %lf\n", vec[0]);
    // Clear the vector
    vec.clear();
    
    printf("size -> %lu\n", vec.size());
    printf("the capacity -> %lu\n", vec.capacity());
    printf("is empty? -> %d\n", vec.empty());
    
    
}
