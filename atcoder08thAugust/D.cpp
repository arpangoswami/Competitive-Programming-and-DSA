#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
#define ff first
#define ss second
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
stack<int> st;
vector<priority_queue<int,vector<int>,greater<int>>> adjacent;
int N;
vector<bool> visited;
void dfs(int v){
	st.push(v);
	cout << v <<" ";
	visited[v] = true;
	priority_queue<int,vector<int>,greater<int>> &pq = adjacent[v];
	while(!pq.empty()){
		int temp = pq.top();
		if(visited[temp]){
			pq.pop();
		}else{
			dfs(temp);
		}
	}
	if(v == 1){
		st.pop();
		return;
	}else{
		st.pop();
		cout<<st.top()<<" ";
	}
}
void solveQuestion(){
	cin >> N;
	adjacent.resize(N+1);
	visited.resize(N+1);
	for(int i=0;i<(N-1);i++){
		int u,v;
		cin >> u >> v;
		adjacent[u].push(v);
		adjacent[v].push(u);
	}
	dfs(1);
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	int tt = 1;
	//cin >> tt;
	while(tt-- > 0){
		solveQuestion();
	}
	return 0;
}