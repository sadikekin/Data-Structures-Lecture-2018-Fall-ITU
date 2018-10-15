#include <iostream>

using namespace std;


struct Node{
  Node *next; // Keep address of next node.
  int val; //Could be anything.
};

struct List{
  Node *head; // Starting point of the list.
  int nodeCount;
  void init_list();
  void add_end(int val);
  void add_start(int val);
  void add_index(int val,int index);
  void delete_at_index(int index);
  void print_list();
  void delete_list();
};

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

int main(){
  List mList;
  mList.init_list();
  cout << "Adding elements to first index..."<<endl;
  mList.add_start(2);
  mList.add_start(1);
  mList.add_start(22);
  mList.print_list();
  cout << "Adding elements to last index..."<<endl<<endl;
  mList.add_end(-22);
  mList.add_end(-1);
  mList.add_end(8);
  mList.print_list();
  mList.add_index(12,10);
  mList.print_list();
  mList.add_index(12,-10);
  mList.print_list();
  mList.add_index(122,2);
  mList.print_list();
  cout << "Deleting element"<<endl;
  mList.delete_at_index(2);
  mList.print_list();
  mList.delete_at_index(0);
  mList.print_list();
  mList.delete_at_index(mList.nodeCount);
  mList.print_list();
  cout << "Exiting program, free allocated memory"<< endl;
  //Necessary to prevent memory leaks
  mList.delete_list();

  return 0;
}
