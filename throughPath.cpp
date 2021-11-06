#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
vector<int> adj_list[200001];
vector<int> levels;
vector<int> score;
void dfsLev(int v,int par){
	levels[v] = levels[par]+1;
	for(int x:adj_list[v]){
		if(x == par){
			continue;
		}
		dfsLev(x,v);
	}
}
void dfs(int v,int par,int score_prev){
	score[v] += score_prev;
	for(int x:adj_list[v]){
		if(x!=par){
			dfs(x,v,score[v]);
		}
	}
}
void solveQuestion(){
	int n;
	cin >> n;
	vector<pii> edges(n);
	for(int i=1;i<n;i++){
		cin >> edges[i].first >> edges[i].second;
		adj_list[edges[i].first].push_back(edges[i].second);
		adj_list[edges[i].second].push_back(edges[i].first);
	}
	levels.resize(n+1);
	score.resize(n+1);
	dfsLev(1,0);
	int q;
	cin >> q;
	while(q--){
		int type,edge_name,val;
		cin >> type >> edge_name >> val;
		if(type == 1){
			int v1 = edges[edge_name].first,v2 = edges[edge_name].second;
			if(levels[v1] > levels[v2]){
				score[v1] += val;
			}else{
				score[1] += val;
				score[v2] -= val;
			}
		}else{
			int v1 = edges[edge_name].first,v2 = edges[edge_name].second;
			if(levels[v1] > levels[v2]){
				score[1] += val;
				score[v1] -= val;
			}else{
				score[v2] += val;
			}
		}
	}
	dfs(1,0,0);
	for(int i=1;i<=n;i++){
		cout<<score[i]<<'\n';
	}
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test = 1;
	while(test--){
		solveQuestion();
	}
	return 0;
}