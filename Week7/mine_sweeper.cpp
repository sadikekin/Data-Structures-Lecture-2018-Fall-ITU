#include <iostream>
#include <queue>
#include <vector>

using namespace std;

//5 5
//1 0 1 1 1
//0 0 1 1 1
//1 1 0 1 1
//1 1 1 0 0
//1 0 1 1 1
//1 3

int mineMovement(vector<vector<int>> matrix, int a, int b){
    queue<pair<int,int>> q;
    q.push(make_pair(a,b));
    
    vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix[0].size(), false));
    
    visited[a][b] = true;
    
    int sum = 0;
    while(!q.empty()){
        pair<int,int> currentNode = q.front();
        q.pop();
        
        sum++;
        
        // UP
        int colm = currentNode.first - 1, row = currentNode.second;
        if(colm >= 0 && !visited[colm][row] && matrix[colm][row] != 0){
            q.push(make_pair(colm, row));
            visited[colm][row] = true;
        }
        
        // DOWN
        colm = currentNode.first + 1, row = currentNode.second;
        if(colm < matrix.size() && !visited[colm][row] && matrix[colm][row] != 0){
            q.push(make_pair(colm, row));
            visited[colm][row] = true;
        }
        
        
        // LEFT
        colm = currentNode.first, row = currentNode.second - 1;
        if(row >= 0 && !visited[colm][row] && matrix[colm][row] != 0){
            q.push(make_pair(colm, row));
            visited[colm][row] = true;
        }
        
        
        // RIGHT
        colm = currentNode.first, row = currentNode.second + 1;
        if(row < matrix[0].size() && !visited[colm][row] && matrix[colm][row] != 0){
            q.push(make_pair(colm, row));
            visited[colm][row] = true;
        }
        
    }
    
    return sum;
    
}

int main() {
    int n,m;
    scanf("%d %d", &n, &m);
    // Create the matrix
    vector<vector<int>> matrix(n, vector<int>(m, 0));
    
    int z;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d ", &z);
            matrix[i][j] = z;
        }
    }
    
    int a, b;
    scanf("%d %d", &a, &b);
    
    int walkCount = mineMovement(matrix, a, b);
    printf("%d\n", walkCount);
    
}
