#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
struct node{
	int indeg;
	int outdeg;
};
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		int n,m;
		vector<int> *adj_list = new vector<int>[n+1]();
		map<int,int> indeg;
		set<node,cmp> st;
		for(int i=0;i<m;i++){
			int type,u,v;
			cin >> type >> u >> v;
			if(type == 0){
				adj_list[u].insert(v);
				adj_list[v].insert(u);
			}else{
				indeg[v]++;
				indeg[u]--;
			}
		}
		for(int )
		delete []adj_list;
	}
	return 0;
}