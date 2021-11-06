#include<bits/stdc++.h>
using namespace std;
int getMinVertex(bool *visited,int *weight,int n){
    int minVertex=-1;
    for(int i=0;i<n;i++){
        if(!visited[i] && ((minVertex==-1)||(weight[minVertex]>weight[i]))){
            minVertex=i;
        }
    }
    return minVertex;
}
void prims(int **adjacent,int n){
    int *weight=new int[n];
    for(int i=0;i<n;i++){
        weight[i]=INT_MAX;
    }
    bool *visited=new bool[n]();
    int *parent=new int[n];
    parent[0]=-1;
    weight[0]=0;
    for(int i=0;i<n-1;i++){
        int minVertex=getMinVertex(visited,weight,n);
        visited[minVertex]=true;
        for(int j=0;j<n;j++){
            if(adjacent[minVertex][j]!=0 && !visited[j]){
                if(weight[j]>adjacent[minVertex][j]){
                    weight[j]=adjacent[minVertex][j];
                    parent[j]=minVertex;
                }
            }
        }
    }
    for(int i=1;i<n;i++){
        if(parent[i]<i){
            cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;
        }
        else{
            cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
        }
    }
}
int main(void){
    int n,e;
    cin>>n>>e;
    int **edges=new int *[n];
    for(int i=0;i<n;i++){
        edges[i]=new int [n];
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }
    for(int i=0;i<e;i++){
        int s,d,weight;
        cin>>s>>d>>weight;
        edges[s][d]=weight;
        edges[d][s]=weight;
    }
    prims(edges,n);
    cout<<endl;
    for(int i=0;i<n;i++){
        delete []edges[i];
    }
    delete []edges;
}
