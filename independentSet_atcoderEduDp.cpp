/*

https://atcoder.jp/contests/dp/tasks/dp_p
P - Independent Set  / 
Time Limit: 2 sec / Memory Limit: 1024 MB

Score : 
100
 points
Output
Print the number of ways in which the vertices can be painted, modulo 
10
9
+
7
.

Sample Input 1 
Copy
3
1 2
2 3
Sample Output 1 
Copy
5
There are five ways to paint the vertices, as follows:



Sample Input 2 
Copy
4
1 2
1 3
1 4
Sample Output 2 
Copy
9
There are nine ways to paint the vertices, as follows:



Sample Input 3 
Copy
1
Sample Output 3 
Copy
2
Sample Input 4 
Copy
10
8 5
10 8
6 5
1 5
4 8
2 10
3 6
9 2
1 7
Sample Output 4 
Copy
157
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1e9 + 7;
int dp[100001][2];
int solve(int v,int col,int par,vector<int> adj_list[]){
	if(dp[v][col] != -1){
		return dp[v][col];
	}
	int ans = 1;
	if(col == 0){
		for(int x:adj_list[v]){
			if(x == par){
				continue;
			}
			int prod1 = solve(x,0,v,adj_list);
			prod1 += solve(x,1,v,adj_list);
			prod1 %= MOD;
			ans *= prod1; 
			ans %= MOD;
		}
	}else{
		for(int x:adj_list[v]){
			if(x == par){
				continue;
			}
			ans *= solve(x,0,v,adj_list);
			ans %= MOD;
		}
	}
	return dp[v][col] = ans;
}
void solveQuestion(){
	int n;
	cin >> n;
	vector<int> adj_list[n+1];
	for(int i=1;i<n;i++){
		int u,v;
		cin >> u >> v;
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}
	memset(dp,-1,sizeof(dp));
	cout<<(solve(1,0,0,adj_list) + solve(1,1,0,adj_list))%MOD<<'\n';
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