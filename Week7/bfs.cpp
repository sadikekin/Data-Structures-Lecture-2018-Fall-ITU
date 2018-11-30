#include <iostream>
#include <vector>
#include <queue>

using namespace std;


void bfs(vector< vector<int> > &graph){
    queue<int> q;
    q.push(0);
    
    vector<bool> visited(6, false);
    visited[0] = true;
    
    while(!q.empty()){
        int currentNode = q.front();
        q.pop();
        
        printf("%d ", currentNode);
        
        for(int i=0;i<graph[currentNode].size();i++){
            int nextNode = graph[currentNode][i];
            if(visited[nextNode] == false){
                q.push(nextNode);
                visited[nextNode] = true;
            }
        }
        
    }
}

int main() {
    vector< vector<int> > graph;
    // resize graph
    graph.resize(6);
    // create graph
    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[0].push_back(4);
    
    graph[1].push_back(0);
    graph[1].push_back(2);
    
    graph[2].push_back(0);
    graph[2].push_back(1);
    graph[2].push_back(3);
    graph[2].push_back(4);
    
    graph[3].push_back(2);
    graph[3].push_back(5);
    
    graph[4].push_back(0);
    graph[4].push_back(2);
    graph[4].push_back(5);
    
    graph[5].push_back(3);
    graph[5].push_back(4);
    
    bfs(graph);
    return 0;
}
