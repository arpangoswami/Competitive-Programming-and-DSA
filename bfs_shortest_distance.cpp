#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;
class Graph{
public:
    int vertices;
    vector<int> *adj_list;
    Graph(int v):vertices(v){
        adj_list = new vector<int>[v];
    }
    void add_edge(int v1,int v2,bool bidir = true){
        if(bidir){
            adj_list[v1].push_back(v2);
            adj_list[v2].push_back(v1);
        }
        else{
            adj_list[v1].push_back(v2);
        }
    }
};
void bfs(Graph g,int start,int *arr,int v){
    bool *visited = new bool[v]();
    visited[start] = true;
    queue<pair<int,int> >  q;
    q.push(make_pair(start,0));
    while(!q.empty()){
        start = q.front().first;
        for(int i=0;i<g.adj_list[start].size();i++){
            if(!visited[g.adj_list[start][i]]){
                    arr[g.adj_list[start][i]] = ((q.front()).second+1)*6;
                    q.push(make_pair(g.adj_list[start][i],((q.front()).second+1)));
                    visited[g.adj_list[start][i]] = true;
            }
        }
        q.pop();
    }
    delete []visited;
}
int main(void){
    int queries;
    cin>>queries;
    while(queries--){
        int ver,edge;
        cin>>ver>>edge;
        Graph g(ver);
        for(int x=0;x<edge;x++){
            int v1,v2;
            cin>>v1>>v2;
            g.add_edge((v1-1),(v2-1));
        }
        int sv;
        cin>>sv;
        int *arr = new int[ver];
        for(int i=0;i<ver;i++){
            arr[i] = -1;
        }
        bfs(g,sv-1,arr,ver);
        for(int i=0;i<ver;i++){
            if(i!=(sv-1))
                cout<<arr[i]<<" ";
        }
        delete []arr;
        cout<<endl;
        delete []g.adj_list;
    }
}
