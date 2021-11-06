#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int INF = 1e18;
void solveQuestion(){
	int n,e,q;
	cin >> n >> e >> q;
	vector<vi> dist(n,vector<int>(n,INF));
	for(int i=0;i<e;i++){
		int u,v,w;
		cin >> u >> v >> w;
		u--;
		v--;
		if(w < dist[u][v]){
			dist[u][v] = w;
			dist[v][u] = w;
		}
	}
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				dist[i][j] = dist[j][i] = min(dist[i][j],dist[i][k] + dist[k][j]);
			}
		}
	}
	while(q--){
		int u,v;
		cin >> u >> v;
		u--;
		v--;
		if(u == v){
			dist[u][v] = 0;
		}
		else if(dist[u][v] == INF){
			dist[u][v] = -1;
		}
		cout<<dist[u][v]<<"\n";
	}
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test = 1;
	//cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}