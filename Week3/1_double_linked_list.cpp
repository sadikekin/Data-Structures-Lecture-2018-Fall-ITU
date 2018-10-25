#include <iostream>

using namespace std;


struct Node {
    Node *next; // Keep the address of the next node.
    Node *prev; // Keep the address of the prev node.
    int val; // Could be anything
};

struct List {
    Node *head; // Starting point of the list
    int nodeCount;
    void init();
    void addEnd(int val);
    void addStart(int val);
    void addIndex(int val, int index);
    void deleteEnd();
    void deleteFront();
    void deleteIndex(int index);
    void deleteList();
    void printBack();
    void printList();
    
};

// Create an not connected node.
Node* initNode(int val){
    Node* node = new Node;
    node->next = nullptr;
    node->prev = nullptr;
    node->val = val;
    return node;
}

// Init list.
void List::init() {
    head = nullptr;
    nodeCount = 0;
}

// Add node to the end.
void List::addEnd(int val)  {
    if(nodeCount == 0){ // If list is empty make that node head.
        head = initNode(val);
    }else { // Otherwise go to the end.
        Node *traverse = head;
        
        while(traverse->next)
            traverse = traverse->next;
        
        Node *newNode = initNode(val);
        
        traverse->next = newNode;
        newNode->prev = traverse;
    }
    nodeCount++;
}


void List::addStart(int val) {
    if(nodeCount == 0){ // If list is empty make that node head.
        head = initNode(val);
    }else { // Otherwise add it to the start.
        Node *newNode = initNode(val);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        nodeCount++;
    }
    
}

void List::addIndex(int val, int index) {
    if(index > nodeCount){
        printf("Sorry dude, I do not have that many node\n");
        return;
    }
    
    if(index == nodeCount){ // Index = nodeCount means addEnd;
        addEnd(val);
        return;
    }
    
    if(index == 0) { // Index = 0 means addStart
        addStart(val);
        return;
    }
    
    Node *traverse = head;
    
    while(index--)
        traverse = traverse->next;
    
    Node *newNode = initNode(val);
    newNode->prev = traverse->prev;
    newNode->next = traverse;
    
    traverse->prev->next = newNode;
    traverse->prev = newNode;
    
    nodeCount++;
}

// Go until the end and delete it.
void List::deleteEnd() {
    if(head == nullptr) {
        printf("Really?! The list is already empty!\n");
        return;
    }
    Node *traverse = head;
    
    while(traverse->next)
        traverse = traverse->next;
    
    traverse->prev->next = nullptr;
    delete traverse;
    nodeCount--;
    
}

void List::deleteFront() {
    Node *tempNode = head;
    
    
    tempNode->next->prev = nullptr;
    head = tempNode->next;
    
    delete tempNode;
    nodeCount--;
    
}


void List::deleteIndex(int index) {
    if(index > nodeCount){
        printf("Sorry dude, I do not have that many node\n");
        return;
    }
    
    if(index == 0) {
        deleteFront();
        return;
    }
    
    if(index == nodeCount){
        deleteEnd();
        return;
    }
    
    Node *tempNode = head;
    while(index--)
        tempNode = tempNode->next;
    
    tempNode->prev->next = tempNode->next;
    tempNode->next->prev = tempNode->prev;
    
    delete tempNode;
    
    nodeCount--;
}

// Print from the front
void List::printList() {
    
    if(nodeCount == 0){
        printf("The list is empty\n");
        return;
    }
    
    printf("The size of the list is %d\n", nodeCount);
    
    Node *tempNode = head;
    
    while(tempNode){
        printf("%d ", tempNode->val);
        tempNode = tempNode->next;
    }
    printf("\n");
}

// Delete all list
void List::deleteList() {
    Node *tempNode = head;
    
    while(tempNode){
        Node *newTemp = tempNode;
        tempNode = tempNode->next;
        delete newTemp;
    }
    
    nodeCount = 0;
}

// Print from the back.
void List::printBack() {
    
    if(nodeCount == 0){
        printf("The list is empty\n");
        return;
    }
    
    printf("The size of the list is %d\n", nodeCount);
    
    Node *tempNode = head;
    
    while(tempNode->next) tempNode = tempNode->next;
    
    while(tempNode){
        printf("%d ", tempNode->val);
        tempNode = tempNode->prev;
    }
    printf("\n");
}

int main() {
    List myList;
    myList.init();
    
    printf("\t Add End \n");
    myList.addEnd(3), myList.addEnd(2), myList.addEnd(5), myList.addEnd(1);
    myList.printList();
    
    printf("------------\n");
    printf("\t Add Start \n");
    
    myList.addStart(1), myList.addStart(2), myList.addStart(3);
    myList.printList();
    
    printf("------------\n");
    printf("\t Add to the Index \n");
    
    myList.addIndex(10,0), myList.addIndex(30,1), myList.addIndex(50,1);
    myList.printList();
    
    printf("------------\n");
    printf("\t Delete from end \n");
    
    myList.deleteEnd(), myList.deleteEnd(), myList.deleteEnd();
    myList.printList();
    
    printf("------------\n");
    printf("\t Delete at index \n");
    
    myList.deleteIndex(2);
    myList.printList();
    
    printf("------------\n");
    printf("\t Print backwards \n");
    
    myList.printBack();
    
    printf("------------\n");
    printf("\t Delete all list \n");
    
    myList.deleteList();
    myList.printList();
    
    printf("------------\n");
    
    return 0;
}
