#include <bits/stdc++.h>
using namespace std;
typedef pair<long long,int> pii;
void dijkstras(vector<pair<int,long long> > *adj_list,int n){
    vector<bool> visited(n,false);
    vector<long long>distance(n,INT_MAX);
    int src = 0;
    distance[0] = 0;
    priority_queue<pii,vector<pii>,greater<pii> > pq;
    pq.push({0,src});
    while(!pq.empty()){
        pii temp = pq.top();
        pq.pop();
        int idx = temp.second;
        long long dist = temp.first;
        if(visited[idx] == true) continue;
        visited[idx] = true;
        for(int i=0;i<adj_list[idx].size();i++){
            int neighbour = adj_list[idx][i].first;
            long long dt = adj_list[idx][i].second;
            if(visited[neighbour] == false && distance[neighbour]>distance[idx]+dt){
                distance[neighbour] = distance[idx]+dt;
                pq.push(make_pair(distance[neighbour],neighbour));
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<i<<" "<<distance[i]<<endl;
    }
}
int main(int argc,char const *argv[]){
    int n,e;
    cin>>n>>e;
    vector<pair<int,long long> > *adj_list = new vector<pair<int,long long> > [n];
    for(int i=0;i<e;i++){
        int src,dest;
        long long weight;
        cin>>src>>dest>>weight;
        adj_list[src].push_back(make_pair(dest,weight));
        adj_list[dest].push_back(make_pair(src,weight));
    }
    dijkstras(adj_list,n);
    delete []adj_list;
    return 0;
}
