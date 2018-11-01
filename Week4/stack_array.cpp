#include <iostream>

#define MAX_SIZE 100


struct stack{
    int size;
    int container[MAX_SIZE];
    int sp;
    void init(){
        size = 0;
        sp = 0;
    }
    void push(int inp){
        if ( size < MAX_SIZE ){
            container[sp] = inp;
            sp++;
            ++size;
        }
    }
    int top(){
        return container[sp-1];
    }
    void pop(){
        if ( size > 0 ){
            sp--;
            size--;
        } 
    }
    void clear(){
        sp = 0;
    }
    bool isEmpty(){
        return size==0;
    }
    void dump(){
        int trv = sp-1;
        while ( trv != -1 ){
            std::cout << container[trv] << " ";
            trv--;
        }
        std::cout << std::endl;
    }
};


int main(){
    stack s;
    s.init();
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(5);


    s.dump();
    s.clear();
    return 0;
}