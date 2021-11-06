#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
bool common(string &a,string &b){
	unordered_set<char> st1;
	for(char c:a){
		st1.insert(c);
	}
	for(char c:b){
		if(st1.count(c)){
			return true;
		}
	}
	return false;
}
int bfs(int sv,int end,int n,vector<int> adj_list[]){
	queue<int> q;
	vector<int> dist(n+1,1e5);
	dist[sv] = 1;
	q.push(sv);
	vector<bool> visited(n+1,false);
	visited[sv] = true;
	while(!q.empty()){
		int v = q.front();
		q.pop();
		for(int x:adj_list[v]){
			if(!visited[x]){
				q.push(x);
				dist[x] = 1 + dist[v];
				visited[x] = true;
			}
		}
	}
	return (dist[end] >= 1e5) ? -1 : dist[end];
}
void solveQ(){
	int n,q;
	cin >> n >> q;
	vector<int> adj_list[n+1];
	vector<string> names(n+1);
	for(int i=1;i<=n;i++){
		cin >> names[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i == j){
				continue;
			}
			if(common(names[i],names[j])){
				adj_list[i].push_back(j);
				adj_list[j].push_back(i);
			}
		}
	}
	while(q--){
		int x,y;
		cin >> x >> y;
		cout<<bfs(x,y,n,adj_list)<<" ";
	}
	cout<<"\n";
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int test;
	cin>>test;
	for(int t=1;t<=test;++t){
		cout<<"Case #"<<t<<": ";
		solveQ();
	}
	return 0;
}