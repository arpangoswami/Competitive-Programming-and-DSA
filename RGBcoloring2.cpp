/*

https://atcoder.jp/contests/abc199/tasks/abc199_d
D - RGB Coloring 2  / 
Time Limit: 2 sec / Memory Limit: 1024 MB

Score : 
400
 points


Output
Print the answer.

Sample Input 1 
Copy
3 3
1 2
2 3
3 1
Sample Input 2 
Copy
3 0
Sample Output 2 
Copy
27
Since the graph has no edge, we can freely choose the colors of the vertices.

Sample Input 3 
Copy
4 6
1 2
2 3
3 4
2 4
1 3
1 4
Sample Output 3 
Copy
0
There may be no way to satisfy the condition.

Sample Input 4 
Copy
20 0
Sample Output 4 
Copy
3486784401
The answer may not fit into the 
32
-bit signed integer type.
*/
#pragma GCC optimize(2)
#pragma GCC optimize(3)   
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#include<cstdlib>
#define int long long
#define ff first
#define ss second
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int n,m;
set<int> adj_list[20];
bool bipartite(int sv,vector<bool> &visited){
	set<int> st[2];
	st[0].insert(sv);
	queue<int> Q;
	visited[sv] = true;
	Q.push(sv);
	while(!Q.empty()){
		int v = Q.front();
		Q.pop();
		int col = st[0].count(v) ? 0 : 1;
		for(int x:adj_list[v]){
			if(st[col].count(x)){
				return false;
			}
			if(visited[x]){
				continue;
			}
			st[1^col].insert(x);
			visited[x] = true;
			Q.push(x);
		}
	}
	return true;
}
void solveQuestion(){
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int u,v;
		cin >> u >> v;
		u--;
		v--;
		adj_list[u].insert(v);
		adj_list[v].insert(u);
	}
	int ans = 0;
	for(int i=0;i<(1<<n);i++){
		int state = i;//set bits = vertices colored with R;
		bool f = false;
		vector<bool> visited(n);
		for(int j=0;j<n && !f;j++){
			if((i >> j) & 1){
				visited[j] = true;
				for(int x:adj_list[j]){
					if((i >> x) & 1){
						f = true;
					}
					if(f){
						break;
					}
				}
			}
		}
		if(f){
			continue;
		}else if(i == (1 << n) - 1){
			ans++;
			continue;
		}
		int cmp = 0;
		bool bipar = true;
		for(int j=0;j<n && bipar;j++){
			if(!visited[j]){
				bipar = bipartite(j,visited);
				cmp++;
			}
		}
		if(!bipar){
			continue;
		}
		//cout<<"i: "<<i<<"\n";
		ans += (1 << cmp);
	}
	//ans *= 3LL;
	cout << ans << '\n';
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