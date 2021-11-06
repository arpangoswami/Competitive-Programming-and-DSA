#include<bits/stdc++.h>
using namespace std;
struct Edge
{
    int src;
    int dest;
    int weight;
};
bool compare(Edge e1,Edge e2){
    return (e1.weight<e2.weight);
}
int getParent(int v,int *parent){
    if(parent[v]==v){
        return v;
    }
    return getParent(parent[v],parent);
}
Edge *kruskal(Edge *edges,int n,int E){
    sort(edges,edges+E,compare);
    Edge *output= new Edge[n-1];
    int *parent= new int [n];
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
    int coun=0;
    int i=0;
    while(coun<(n-1)){
        Edge currentEdge=edges[i];
        int srcParent=getParent(currentEdge.src,parent);
        int destParent=getParent(currentEdge.dest,parent);
        if(srcParent!=destParent){
            output[coun]=currentEdge;
            coun++;
            parent[destParent]=srcParent;
        }
        i++;
    }
    delete []parent;
    return output;
}
int main(void){
    int n,e;
    cin>>n>>e;
    Edge *edges=new Edge[e];
    for(int i=0;i<e;i++){
        cin>>edges[i].src>>edges[i].dest>>edges[i].weight;
    }
    Edge *output=kruskal(edges,n,e);
    for(int i=0;i<n-1;i++){
        if(output[i].src<output[i].dest){
            cout<<output[i].src<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
        }
        else{
            cout<<output[i].dest<<" "<<output[i].src<<" "<<output[i].weight<<endl;
        }
    }
    delete []output;
    delete []edges;
}
