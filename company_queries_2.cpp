/*
Company Queries II
TASK SUBMIT RESULTS STATISTICS HACKING
Time limit: 1.00 s Memory limit: 512 MB
A company has n employees, who form a tree hierarchy where each employee has a boss, except for the general director.

Your task is to process q queries of the form: who is the lowest common boss of employees a and b in the hierarchy?

Input

The first input line has two integers n and q: the number of employees and queries. The employees are numbered 1,2,…,n, and employee 1 is the general director.

The next line has n−1 integers e2,e3,…,en: for each employee 2,3,…,n their boss.

Finally, there are q lines describing the queries. Each line has two integers a and b: who is the lowest common boss of employees a and b?

Output

Print the answer for each query.

Constraints
1≤n,q≤2⋅105
1≤ei≤i−1
1≤a,b≤n
Example

Input:
5 3
1 1 3 3
4 5
2 5
1 4

Output:
3
1
1
*/
#include <bits/stdc++.h>
#define N 200001
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int up[N][20];
vector<int> adj_list[N];
int levels[N];
void dfs(int sv,int par,int lvl){
	levels[sv] = lvl;
	for(int x:adj_list[sv]){
		if(x != par){
			dfs(x,sv,lvl+1);
		}
	}
}
void binary_lifting(int src,int par){
	up[src][0] = par;
	for(int i=1;i<20;i++){
		if(up[src][i-1]!=-1){
			up[src][i] = up[up[src][i-1]][i-1];
		}else{
			up[src][i] = -1;
		}
	}
	for(int child:adj_list[src]){
		if(child!=par){
			binary_lifting(child,src);
		}
	}
}
int lift_node(int v,int k){
	for(int i=19;i>=0;i--){
		if(v == -1 || k == 0){
			break;
		}
		if(k >= (1 << i)){
			v = up[v][i];
			k -= (1 << i);
		}
	}
	return v;
}
 
int ans_query(int x,int y){
	if(levels[x] < levels[y]){
		swap(x,y);
	}
	x = lift_node(x,levels[x] - levels[y]);
	if(x == y){
		return x;
	}
	for(int i=19;i>=0;i--){
		if(up[x][i]!=up[y][i]){
			x = up[x][i];
			y = up[y][i];
		}
	}
	return lift_node(x,1);
}
void solveQuestion(){
	int n,q;
	cin >> n >> q;
	for(int i=2;i<=n;i++){
		int x;
		cin >> x;
		adj_list[x].push_back(i);
		adj_list[i].push_back(x);
	}
	binary_lifting(1,-1);
	dfs(1,-1,0);
	while(q--){
		int x,y;
		cin >> x >> y;
		cout<<ans_query(x,y)<<"\n";
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