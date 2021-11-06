#include <bits/stdc++.h>
using namespace std;
typedef pair<long long,int> current_weight;
void prims(vector<pair<int,long long> > *adj_list,int n){
    int src = 0;
    vector<bool> visited(n,false);
    vector<long long> weight(n,INT_MAX);
    vector<int> parent(n,-1);
    priority_queue<current_weight,vector<current_weight>,greater<current_weight> > pq;
    weight[src] = 0;
    pq.push(make_pair(0,src));
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        if(visited[u] == true) continue;
        visited[u] = true;
        for(int i = 0;i < adj_list[u].size();i++){
            int v = adj_list[u][i].first;
            int wt = adj_list[u][i].second;
            if(visited[v] == false && weight[v]>wt){
                weight[v] = wt;
                pq.push(make_pair(weight[v],v));
                parent[v] = u;
            }
        }
    }
    for(int i=1;i<n;i++){
        if(parent[i]<i){
            cout<<parent[i]+1<<" "<<i+1<<" "<<weight[i]<<endl;
        }
        else{
            cout<<i+1<<" "<<parent[i]+1<<" "<<weight[i]<<endl;
        }
    }
}
int main(int argc,char const* argv[]){
    int n,e;
    cin>>n>>e;
    vector<pair<int,long long> > *adj_list = new vector<pair<int,long long> > [n];
    for(int i=0;i<e;i++){
        int src,dest;
        long long weight;
        cin>>src>>dest>>weight;
        adj_list[src-1].push_back(make_pair(dest-1,weight));
        adj_list[dest-1].push_back(make_pair(src-1,weight));
    }
    prims(adj_list,n);
    delete []adj_list;
    return 0;
}
