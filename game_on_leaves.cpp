#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int child(int v,vector<int> *adj_list,int par){
	int ans = 1;
	for(int x:adj_list[v]){
		if(x == par){
			continue;
		}
		ans+=child(x,adj_list,v);
	}
	return ans;
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		int n,x;
		cin>>n>>x;
		vector<int>* adj_list = new vector<int>[n+1]();
		for(int i=0;i<(n-1);i++){
			int u,v;
			cin>>u>>v;
			adj_list[u].push_back(v);
			adj_list[v].push_back(u);
		}
		if(adj_list[x].size() <= 1){
			cout<<"Ayush"<<"\n";
		}else{
			int odd = 0;
			for(int v:adj_list[x]){
				int cnt = child(v,adj_list,x);
				if(cnt%2 == 1){
					odd++;
				}
			}
			if(odd%2 == 0){
				cout<<"Ashish"<<"\n";
			}else{
				cout<<"Ayush"<<"\n";
			}
		}
		delete []adj_list;
	}
	return 0;
}