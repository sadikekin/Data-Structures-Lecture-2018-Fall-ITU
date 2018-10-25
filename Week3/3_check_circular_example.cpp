#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
#include <numeric>
#include <iterator>
#include <algorithm>
#include <cmath>
#include <chrono>
#include <cassert>

using namespace std;


// Find the cycle in given list

struct Node {
    int val;
    Node *next;
};

struct List {
    Node *head;
    void push(int val);
    bool cycleDetector();
};

void List::push(int val) {
    Node *tempNode = new Node;
    tempNode->next = head;
    tempNode->val = val;
    
    head = tempNode;
}

bool List::cycleDetector() {
    Node* fast = head;
    Node* slow = head;
    
    while(fast && slow && fast->next ){
        fast = fast->next->next;
        slow = slow->next;
        
        if(slow == fast) return true;
    }
    return false;
}

int main(){
    List myList{};
    
    for(int i=0;i<6;i++) myList.push(i);
    
    Node *traverse = myList.head;
    while(traverse->next) traverse = traverse->next;
    traverse->next = myList.head->next;
    
    
    if(myList.cycleDetector()){
        printf("Cycle has found!");
    }else{
        printf("There is no cycle");
    }
    
    
    return 0;
}




