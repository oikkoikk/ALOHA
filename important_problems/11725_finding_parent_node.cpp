#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int NUM = 100001;
int N;
vector<int> Tree[NUM];
int parent[NUM];
queue<int> Q;

void BFS(int start){
    Q.push(start);
    
    while(!Q.empty()){
        int curr = Q.front();
        Q.pop();
        
        for(int i=0; i<Tree[curr].size(); i++){
            int next = Tree[curr][i];
            
            if(parent[curr] == next) continue;
            //visited와 같은 역할
            
            Q.push(next);
            parent[next] = curr;
        }
    }
}