#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
void dfs(int sv,vector<bool> &visited,vector<int>* adj_list,ll &cost,ll b){
	cost+=b;
	visited[sv] = true;
	for(int x:adj_list[sv]){
		if(!visited[x]){
			dfs(x,visited,adj_list,cost,b);
		}
	}
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		int n,m;
		ll a,b;
		cin>>n>>m>>a>>b;
		vector<int>* adj_list = new vector<int>[n+1]();
		for(int i=0;i<m;++i){
			int u,v;
			cin>>u>>v;
			adj_list[u].push_back(v);
			adj_list[v].push_back(u);
		}
		if(a<=b){
			cout<<a*n<<endl;
		}else{
			vector<bool> visited(n+1,false);
			ll cost = 0;
			for(int i=1;i<=n;i++){
				if(!visited[i]){
					cost+=a;
					cost-=b;
					dfs(i,visited,adj_list,cost,b);
				}
			}
			cout<<cost<<endl;
		}
		delete []adj_list;
	}
	return 0;
}