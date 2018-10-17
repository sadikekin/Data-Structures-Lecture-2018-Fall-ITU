#include"list.h"
// Allocate memory space for new node.
Node* init_node(int val){
  Node * newnode = new Node;
  newnode->next = NULL;
  newnode->val = val;
  return newnode;
}


void List::init_list(){
  head = NULL;
  nodeCount = 0;
}
//Add new node to start of the list.
// New head will be this node.
void List::add_start(int val){
  Node *newnode = init_node(val);
  newnode->next = head;
  head = newnode;
  nodeCount++;
}

void List::print_list(){
  Node *traverse = head;
  cout << "There are " << nodeCount << " items on the list."<<endl;
  while(traverse != NULL){
      cout << traverse->val << "  ";
      traverse = traverse->next;
  }
  cout << endl;
}

void List::add_end(int val){
  Node *newnode = init_node(val);
  if(head == NULL)
    head = newnode;
  else{
    Node *traverse = head;
    while(traverse->next != NULL){ // Move to the last index.
      traverse = traverse->next;
    }
    traverse->next = newnode;
    nodeCount++;
  }
}

void List::add_index(int val,int index){
  if(index >= nodeCount) add_end(val);
  else if(index < 1) add_start(val);
  else{
    Node *newnode = init_node(val);
    Node *traverse = head; // Move to the desired index.
    for(int i = 0  ;i < index-1;i++)
      traverse = traverse->next;
    // Pointer for the next element.
    Node *temp = traverse->next;
    //Order of the operations are important.
    newnode->next = temp;
    traverse->next = newnode;
}
}

void List::delete_list(){
  Node *traverse = head;
  while(traverse != NULL){
    head = traverse->next;
    traverse->next = NULL;
    delete traverse;
    traverse = head;
  }
  delete head;
}

void List::delete_at_index(int index){
  if(index < 0 || index > nodeCount) return;
  Node *traverse = head; // Will point to desired node to be deleted.
  if(index == 0){
    head = traverse->next;
  }
  else{
    Node *temp = head; // Will point the previous node.
    for(int i = 0 ; i< index ;i++){
      temp = traverse;
      traverse = traverse->next;
    }
    temp->next = traverse->next;
  }
  traverse->next = NULL;
  delete traverse;
  nodeCount--;
}
