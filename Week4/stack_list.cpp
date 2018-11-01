#include <iostream>



struct node{
    int data;
    node *next;
};

struct stack{
    node *head;
    int size;

    void init(){
        head = NULL;
        size = 0;
    }
    void push(int  inp){
        node *t = new node;

        t->data = inp;
        t->next = NULL;
        if (size > 0){
            t->next = head;
        }
        head = t;
        ++size;
    }
    int top(){
        return head->data;
    }
    void pop(){
        if ( size > 0 ){
            node *tmp = head->next;
            delete head;
            head = tmp;
            size--;
        }
    }
    void clear(){
        while ( size > 0 ){
            pop();
        }
    }
    bool isEmpty(){
        return size==0;
    }
    void dump(){
        std::cout << "dumping\n"; 
        node *trv = head;
        while ( trv!=NULL ){
            std::cout << trv->data << " ";
            trv = trv->next;
        }
        std::cout << std::endl;
    }
};

int main(){
    /*Driver program for implemented stack*/
    stack s;
    s.init();
    s.push(1);
    s.push(2);
    s.push(3);


    s.dump();
    s.clear();
    return 0;
}