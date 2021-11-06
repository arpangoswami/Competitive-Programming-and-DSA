#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int INF = 1e12;
void dijkstra(vector<pii> adj_list[],int n){
	vector<int> dist(n+1,INF);
	vector<int> interm(n+1,INF);
	int src = 1;
	dist[src] = 0;
	priority_queue<pii,vector<pii>,greater<pii> > pq;
    pq.push({0,src});
    while(!pq.empty()){
    	pii temp = pq.top();
    	pq.pop();
    	int idx = temp.second;
        int distance = temp.first;
        if(distance > dist[idx]){
        	continue;
        }
        for(int i=0;i<adj_list[idx].size();i++){
        	int v = adj_list[idx][i].first,wt = adj_list[idx][i].second;
            if(interm[v] > wt){
            	for(int j=0;j<adj_list[v].size();j++){
            		int v1 = adj_list[v][j].first,wt1 = adj_list[v][j].second;
            		if(dist[v1] > dist[idx] + (wt + wt1) * (wt + wt1)){
            			dist[v1] = dist[idx] + (wt + wt1) * (wt + wt1);
            			pq.push({dist[v1],v1});
            		}
            	}
            	interm[v] = wt;
            }
        }
    }
    for(int i=1;i<=n;i++){
    	if(dist[i] >= INF){
    		cout<<-1<<" ";
    	}
    	else{
    		cout<<dist[i]<<" ";
    	}
    }
}
void solveQuestion(){
	int n,m;
	cin >> n >> m;
	vector<pii> adj_list[n+1];
	for(int i=0;i<m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		adj_list[u].push_back({v,w});
		adj_list[v].push_back({u,w});
	}
	dijkstra(adj_list,n);
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test = 1;
	//cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}