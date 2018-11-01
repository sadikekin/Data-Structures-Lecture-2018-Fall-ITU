#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>


#define N 15
#define M 15


struct node{
    /* Position of node */
    int x,y;
    node *next;
};

struct stack{
    node *head;
    int size;

    void init(){
        head = NULL;
        size = 0;
    }
    void push(int  x, int y){
        node *t = new node;

        t->x = x;
        t->y = y;
        t->next = NULL;
        if (size > 0){
            t->next = head;
        }
        head = t;
        ++size;
    }
    node top(){
        node res;
        res.x = head->x;
        res.y = head->y;
        return res;
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
            std::cout << trv->x << " " << trv->y << "\n";
            trv = trv->next;
        }
        std::cout << std::endl;
    }
};

bool isAvailable(char maze [N][M], int x, int y){
    
    if ( x< 0 || y <0 || x>=N || y>=M)
        return false;
    if ( maze[x][y] == '#')
        return false;
    return true; 
}
int moves[][2]=  { {-1,0}, {0,-1}, {1,0}, {0,1}};

void print( char maze[N][M]){
    for(int i=0; i<  N; ++i){
        for (int j=0; j < M; ++j){
            std::cout << maze[i][j];
        }
        std::cout << std::endl;
    }
}

bool dfs(int x, int y, char maze[N][M], bool visited[N][M], stack backtrack){
    
    backtrack.push( x, y );
    if ( maze[x][y] == '0' )
    {
        backtrack.pop();
        while( !backtrack.isEmpty() ){
            
            std::cout << "Exit is " << x << " " << y << std::endl;
            print(maze); 
            node step = backtrack.top();
            backtrack.pop();
            maze[step.x][step.y] = 'O';
            if ( step.x == 0 && step.y == 0 ){
                break;
            }
            system("sleep 0.01");
            system("clear");
            
        }

        backtrack.clear();
        return true;
    }
    
    visited[x][y] = true;

    for (int i = 0; i < 4; ++i){
        int new_x = x + moves[i][0];
        int new_y = y + moves[i][1];
        if ( isAvailable( maze, new_x, new_y ) && visited[ new_x ][ new_y ] == false  ) {
            bool result = dfs( new_x, new_y, maze,  visited, backtrack );
            if (result){
                return true;
            }
        }
    }

    return false;
}
int main(){
    /* Escaping from maze */
    /* 15 X 15 maze, # represent the blocks, we cannot move to there.*/
    /* x = 0 ,y = 0 is our start point, for sake of simplicity 0 indexing is used and coordinates starts from top-left */
    /* let 0 to our exit point here. */
    /* Lets exit from maze */

    char maze[N][M] = {
        {'*', '.', '.', '.', '.', '.', '.', '#', '#', '#', '.', '.', '.', '.', '.'},
        {'.', '#', '#', '.', '.', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.'},
        {'.', '#', '#', '.', '.', '.', '.', '.', '.', '#', '#', '.', '#', '#', '.'},
        {'.', '#', '#', '#', '.', '.', '.', '#', '.', '#', '#', '.', '#', '#', '.'},
        {'#', '#', '#', '.', '.', '.', '#', '#', '.', '#', '#', '.', '#', '#', '.'},
        {'.', '.', '#', '#', '.', '#', '.', '.', '.', '.', '#', '.', '#', '#', '.'},
        {'.', '#', '#', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.'},
        {'.', '.', '.', '#', '.', '.', '.', '#', '.', '.', '.', '.', '#', '#', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '#', '#', '#', '.', '#', '#', '.'},
        {'.', '.', '.', '#', '.', '.', '#', '.', '#', '.', '#', '.', '.', '.', '#'},
        {'.', '#', '.', '#', '.', '.', '#', '.', '#', '.', '#', '.', '.', '.', '#'},
        {'.', '#', '.', '#', '.', '.', '.', '.', '#', '.', '#', '.', '.', '.', '.'},
        {'.', '#', '.', '#', '.', '.', '.', '.', '#', '.', '#', '.', '0', '.', '.'},
        {'.', '#', '.', '.', '.', '.', '.', '.', '#', '.', '#', '.', '.', '.', '.'},
        {'.', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'}
    };
    bool visited[N][M];
    for (int i=0; i < N ; ++i) memset( *(visited+i), M, 0 );
    stack s;
    s.init();
    dfs(0,0,maze,visited ,s);
    

    return 0;
}