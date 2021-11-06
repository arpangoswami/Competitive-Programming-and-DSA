#include<bits/stdc++.h>
using namespace std;
void dfs_print(bool **adj_mat,int n,int sv,bool *visited){
    cout<<sv<<'\t';
    visited[sv]=true;
    for(int i=0;i<n;i++){
        if(i==sv){
            continue;
        }
        if(adj_mat[sv][i]==1){
            if(visited[i]==true){
                continue;
            }
            dfs_print(adj_mat,n,i,visited);
        }
    }
}
int main(void){
    int vertex,edges;
    cin>>vertex>>edges;
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
    bool *visited=new bool[vertex];
    for(int i=0;i<vertex;i++){
        visited[i]=false;
    }
    //print_bfs(adj_mat,0,vertex);
    dfs_print(adj_mat,vertex,1,visited);
    cout<<endl;
    delete []visited;
    for(int i=0;i<vertex;i++){
        delete []adj_mat[i];
    }
    delete []adj_mat;
}
