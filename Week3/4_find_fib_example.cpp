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

struct Node {
    int val;
    Node *next;
};

struct List {
    Node *head;
    void push(int val);
    void createFib();
    bool printList();
};

void List::createFib() {
    Node *node = new Node;
    node->val = head->val + head->next->val;
    node->next = head;
    
    head = node;
}
void List::push(int val) {
    Node *tempNode = new Node;
    tempNode->next = head;
    tempNode->val = val;
    
    head = tempNode;
}

bool List::printList() {
    Node *traverse = head;
    
    while(traverse) {
        printf("%d ", traverse->val);
        traverse = traverse->next;
    }
    printf("\n");
}

int main(){
    List myList{};
    
    // Init fib
    myList.push(1), myList.push(1);
    
    for(int i=0;i<6;i++) myList.createFib();
    
    myList.printList();
    
    
    
    
    return 0;
}




