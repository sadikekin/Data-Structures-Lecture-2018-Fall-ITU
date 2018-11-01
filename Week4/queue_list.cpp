#include <iostream>

struct node{
    int data;
    node *next;
};

struct queue{
    node *head, *tail;
    int size;

    void init(){
        head = NULL;
        tail = NULL;
        size = 0;
    }
    void push(int inp){
        node *tmp = new node;
        
        tmp->next = NULL;
        tmp->data = inp;

        if ( size == 0 ){
            head = tmp;
            tail = head;
        }
        
        if ( size > 0){
            tail->next = tmp;
            tail = tmp;
        }
        size++;
    }
    int top(){
        return head->data;
    }
    void pop(){
        if ( size > 0 ){
            node *tmp = head;
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
    queue q;
    q.init();
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(5);
    q.push(3);


    q.dump();
    q.clear();
    return 0;
}