#include<bits/stdc++.h>
using namespace std;
bool flag=false;
stack<int> path;
void dfs_print(bool **adj_mat,int n,int sv,int fv,bool *visited){
    //cout<<sv<<'\t';
    visited[sv]=true;
    path.push(sv);
    //cout<<"vertex now "<<sv<<endl;
    for(int i=0;i<n;i++){
        if(i==sv){
            continue;
        }
        if(adj_mat[sv][i]==true){
            if(visited[i]==true){
                continue;
            }
            if(i==fv){
                flag=true;
                //cout<<"end vertex "<<fv<<endl;
                visited[i]=true;
                path.push(fv);
            }
            if(!flag)
                dfs_print(adj_mat,n,i,fv,visited);
            else
                return;
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
    int start,finish;
    cin>>start>>finish;
    bool *visited=new bool[vertex];
    for(int i=0;i<vertex;i++){
        visited[i]=false;
    }
    //print_bfs(adj_mat,0,vertex);
    dfs_print(adj_mat,vertex,start,finish,visited);
    if(flag){
        while(!path.empty()){
            cout<<path.top()<<" ";
            path.pop();
        }
    }
    else{
        cout<<endl;
    }
    delete []visited;
    for(int i=0;i<vertex;i++){
        delete []adj_mat[i];
    }
    delete []adj_mat;
}
