#include <iostream>

#define MAX_SIZE 100

/*Not good implementation*/
struct queue{
    int size;
    int container[MAX_SIZE];
    int qp;
    int head;
    void init(){
        size = 0;
        qp = 0;
        head = 0;
    }
    void push(int inp){
        if ( size < MAX_SIZE ){
            container[qp] = inp;
            qp++;
            ++size;
        }
    }
    int top(){
        return container[head];
    }
    void pop(){
        if ( size > 0 ){
            head++;
            size--;
        } 
    }
    void clear(){
        qp = 0;
        head = 0;
    }
    bool isEmpty(){
        return size==0;
    }
    void dump(){
        int trv = head;
        while ( trv < qp  ){
            std::cout << container[trv] << " ";
            trv++;
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
    q.dump();
    q.clear();
    return 0;
}