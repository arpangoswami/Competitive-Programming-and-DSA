#include <iostream>
#include<queue>
using namespace std;
void print_bfs(bool **adj_mat,int sv, int n){
queue <int> pendingVertices;
bool *visited = new bool[n];
for(int i=0;i<n;i++){
    visited[i]=false;
}
pendingVertices.push(sv);
visited[sv]=true;
while(pendingVertices.empty()!=true){
    int current=pendingVertices.front();
    pendingVertices.pop();
    cout<<current<<'\n';
    for(int i=0;i<n;i++){
        if(i==current)
            continue;
        if(adj_mat[current][i]==1 && visited[i]==false){
            visited[i]=true;
            pendingVertices.push(i);
        }
    }
    delete [] visited;
}
}
int main(void) {
    int vertex, edges;
    cin >> vertex >> edges;

  /*

  	   Write Your Code Here
	   Complete the Rest of the Program
	   You have to take input and print the output yourself

  */
    bool **adj_mat=new bool *[vertex];
    for(int i=0;i<vertex;i++){
        adj_mat[i]=new bool[vertex];
        for(int j=0;j<vertex;j++){
            adj_mat[i][j]=false;
        }
    }
    while(edges--){
        int p1,p2;
        cin>>p1>>p2;
        adj_mat[p1][p2]=true;
        adj_mat[p2][p1]=true;
    }
    print_bfs(adj_mat,0,vertex);
    for(int i=0;i<vertex;i++){
        delete []adj_mat[i];
    }
    delete []adj_mat;
}
