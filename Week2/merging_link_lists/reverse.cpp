#include"list.h"

/*
  QUESTION
  reverse a given link list.
  INPUT:   1  3 5 6 -1 -2
  OUTPUT: -2 -1 6 5 4  1
*/


void reverseList(List *list){
    Node *trav = list->head;
    Node *next;
    Node *prev = NULL; // previous node of the head is NULL.
    while(trav != NULL){
      next = trav->next;
      trav->next = prev;
      prev = trav;
      trav = next;
    }
    list-> head = prev;
}




int main(){
  List list;
  list.init_list();
  list.add_end(1);
  list.add_end(3);
  list.add_end(5);
  list.add_end(6);
  list.add_end(-1);
  list.add_end(-2);
  list.print_list();
  reverseList(&list);
  list.print_list();
  list.delete_list();

  return 0;
}
