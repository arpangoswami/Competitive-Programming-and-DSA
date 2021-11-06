#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
ll power(ll a,ll b){
	if(b == 0){
		return 1;
	}
	ll smallAns = power(a,b/2);
	if(b&1){
		return smallAns*smallAns*a;
	}
	return smallAns*smallAns;
}
bool dfs(int sv,int fv,vector<int>* adj_list,vector<bool> &visited,vector<int> &path){
	visited[sv] = true;
	path.push_back(sv);
	if(sv == fv){
		return true;
	}
	for(int x:adj_list[sv]){
		if(!visited[x]){
			bool f = dfs(x,fv,adj_list,visited,path);
			if(f){
				return true;
			}
		}
	}
	path.pop_back();
	return false;
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		int n,q;
		cin>>n>>q;
		vector<int> arr(n+1);
		for(int i=1;i<=n;i++){
			cin>>arr[i];
		}
		vector<int> *adj_list = new vector<int>[n+1]();
		for(int i=0;i<(n-1);i++){
			int u,v;
			cin>>u>>v;
			adj_list[u].push_back(v);
			adj_list[v].push_back(u);
		}
		while(q--){
			int u,v;
			cin>>u>>v;
			vector<bool> visited(n+1,false);
			vector<int> path;
			dfs(u,v,adj_list,visited,path);
			vector<int> wts;
			for(int x:path){
				wts.push_back(arr[x]);
			}
			sort(wts.begin(),wts.end());
			int min_difference = 1e9;
			for(int i=wts.size()-1;i>=1;i--){
				min_difference = min(min_difference,wts[i]-wts[i-1]);
			}
			cout<<min_difference<<endl;
		}
		delete []adj_list;
	}
	return 0;
}