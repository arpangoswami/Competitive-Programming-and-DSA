#include<bits/stdc++.h>
using namespace std;
int getMinVertex(bool *visited,int *distance,int n){
    int minVertex=-1;
    for(int i=0;i<n;i++){
        if(!visited[i] && ((minVertex==-1)||(distance[minVertex]>distance[i]))){
            minVertex=i;
        }
    }
    return minVertex;
}
void dijkstras(int **edges,int n){
    bool *visited=new bool [n]();
    int  *distance=new int [n];
    for(int i=0;i<n;i++){
        distance[i]=INT_MAX;
    }
    distance[0]=0;
    for(int i=0;i<n-1;i++){
        int minVertex=getMinVertex(visited,distance,n);
        visited[minVertex]=true;
        for(int j=0;j<n;j++){
            if(edges[minVertex][j]!=0 && visited[j]==false){
                int currDist=distance[minVertex]+edges[minVertex][j];
                if(currDist<distance[j]){
                    distance[j]=currDist;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<i<<" "<<distance[i]<<endl;
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
    dijkstras(edges,n);
    cout<<endl;
    for(int i=0;i<n;i++){
        delete []edges[i];
    }
    delete []edges;
}
