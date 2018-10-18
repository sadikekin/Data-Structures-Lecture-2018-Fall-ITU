
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
