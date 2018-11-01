#include <iostream>
#include <cstring>

#define MAX_LEN 2000

struct node{
    char data;
    node *next;
};

struct stack{
    node *head;
    int size;

    void init(){
        head = NULL;
        size = 0;
    }
    void push(char  inp){
        node *t = new node;

        t->data = inp;
        t->next = NULL;
        if (size > 0){
            t->next = head;
        }
        head = t;
        ++size;
    }
    char top(){
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


bool isValid(char *expression ){
    /*
        This procedure is simple, we will PUSH opening brackets to stack,
        and when we encounter closing bracket we will POP from stack then compare it to closing bracket to match them.
    */
    stack s;
    s.init();
    
    int length_of_string = strlen(expression);
    int i = 0;
 
    while ( i < length_of_string ){
        char cur_char = expression[i];
        if( cur_char == '(' ||  cur_char == '{' ||  cur_char == '['  ){
            s.push( expression[i] );
        }

        if( cur_char == ')' ||  cur_char == '}' ||  cur_char == ']' ){
            if ( !s.isEmpty() ){
                char c = s.top();
                s.pop();
                if (   !( (c == '(' && cur_char == ')')  ||   ( c == '{' && cur_char == '}')   ||  ( c == '[' && cur_char == ']')) ) {
                    s.clear();
                    return false;;
                }
            }
            else{
                s.clear();
                return false;
            }
        }
        i++;
    }

    if ( !s.isEmpty() ){
        s.clear();
        return false;
    }
    s.clear();
    return true;
    
}
int main(){
    /*Driver program for  experession checker*/
    /*
    If an expression includes unmathced parantheses, it is unvalid.
    We will use stack data structure to check wheter it is valid or not.
    */
    char expression[2000];
    std::cin.getline(expression , MAX_LEN);
    std::cout << "Input expression is\t" << expression << std::endl;
    if ( isValid( expression ) ){
        std::cout << "This expression is cool\n";
    }
    else{
        std::cout << "We can not evaluate it\n";
    }
    stack s;

    return 0;
}