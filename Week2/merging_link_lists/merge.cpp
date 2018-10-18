#include"list.h"

/*
  QUESTION
  Merge two given link lists. List will be sorted and merged list must be sorted.
  INPUT->  left: 1 2 15 27 and right: -1 3 10 11 19
  OUTPUT-> -1 1 2 3 10 11 15 19 27
  Initial link list should be empty at the end and no additional memory should be used.
*/


void merge_lists(List *left,List *right,List *merged){

  Node *temp; // Used while insterting nodes.
  Node *trav = merged->head;
  while ( left->head != NULL && right->head != NULL ) {
    if ( left->head->val < right->head->val ) { // Add left head node
        temp = left->head;
        left->head = left->head->next; // Move left head to the next
    }
    else{ // Add right head node
      temp = right->head;
      right->head = right->head->next;  // Move right head to the next
    }
    temp->next = NULL;
    if (merged->head == NULL) {
      merged->head = temp;
    }
    else{
      trav = merged->head;
      while(trav->next != NULL){// Move to the end of the list.
        trav = trav->next;
      }
      trav->next = temp;
    }
  }
  // Elements of left or right has ended. Push remaining ones to merged list.
  Node *remainingList = right->head == NULL ? left->head : right->head;
  while(remainingList != NULL){ // Push remaining elements.
      temp = remainingList;
      remainingList = remainingList->next;
      temp->next = NULL;
      trav = merged->head;
      while(trav->next != NULL){ // Move to the end of the list.
        trav = trav->next;
      }
      trav->next = temp;
  }
}


int main(){
  List listLeft,listRight,mergedList;
  listLeft.init_list();
  listRight.init_list();
  mergedList.init_list();


  listLeft.add_end(1);
  listLeft.add_end(2);
  listLeft.add_end(15);
  listLeft.add_end(27);

  listRight.add_end(-1);
  listRight.add_end(3);
  listRight.add_end(10);
  listRight.add_end(11);
  listRight.add_end(19);

  listLeft.print_list();
  listRight.print_list();

  merge_lists(&listLeft,&listRight,&mergedList);

  mergedList.print_list();

  mergedList.delete_list();

  return 0;
}
