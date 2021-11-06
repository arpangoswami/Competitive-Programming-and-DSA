/*
https://www.spoj.com/problems/ROADS/
ROADS - Roads
no tags 
Đọc đề đẹp hơn ở:
https://codeforces.com/group/FLVn1Sc504/contest/274521/problem/V
English	Vietnamese
N cities named with numbers 1 ... N are connected with one-way roads. Each road has two parameters associated with it: the road length and the toll that needs to be paid for the road (expressed in the number of coins). Bob and Alice used to live in the city 1. After noticing that Alice was cheating in the card game they liked to play, Bob broke up with her and decided to move away - to the city N. He wants to get there as quickly as possible, but he is short on cash. We want to help Bob to find the shortest path from the city 1 to the city N that he can afford with the amount of money he has.

Input
The input begins with the number t of test cases. Then t test cases follow. The first line of the each test case contains the integer K, 0 <= K <= 10000, maximum number of coins that Bob can spend on his way. The second line contains the integer N, 2 <= N <= 100, the total number of cities. The third line contains the integer R, 1 <= R <= 10000, the total number of roads. Each of the following R lines describes one road by specifying integers S, D, L and T separated by single blank characters : S is the source city, 1 <= S <= N D is the destination city, 1 <= D <= N L is the road length, 1 <= L <= 100. T is the toll (expressed in the number of coins), 0 <= T <= 100 Notice that different roads may have the same source and destination cities.

Output
For each test case, output a single line contain the total length of the shortest path from the city 1 to the city N whose total toll is less than or equal K coins. If such path does not exist, output -1.

Example
Input:
2
5
6
7
1 2 2 3
2 4 3 3
3 4 2 4
1 3 4 1
4 6 2 1
3 5 2 0
5 4 3 2
0
4
4
1 4 5 2
1 2 1 0
2 3 1 1
3 4 1 0

Output:
11
-1
*/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int inf = 1e9;
int dp[101][10001];
struct road{
	int dest;
	int length;
	int toll;
	road(){
		dest = 0;
		length = -1;
		toll = -1;
	}
	road(int d,int len,int toll){
		dest = d;
		length = len;
		this->toll = toll;
	}
};
int dfs(int sv,int ev,int k,vector<road>* adj_list){
	if(k<0){
		return inf;
	}
	if(dp[sv][k]!=-1){
		return dp[sv][k];
	}
	if(sv == ev){
		return dp[sv][k] = 0;
	}
	int ans = inf;
	for(road x:adj_list[sv]){
		int d = x.dest;
		if(d == sv){
			continue;
		}
		int cost = x.toll;
		int len = x.length;
		ans = min(ans,len + dfs(d,ev,k - cost,adj_list));
	}

	return dp[sv][k] = ans;
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		int k;
		cin>>k;
		int n;
		cin>>n;
		memset(dp,-1,sizeof(dp));
		vector<road> *adj_list = new vector<road>[n+1]();
		int e;
		cin>>e;
		for(int i=0;i<e;i++){
			int u,v,len,tol;
			cin>>u>>v>>len>>tol;
			road r = road(v,len,tol);
			adj_list[u].push_back(r);
		}
		int min_cost = dfs(1,n,k,adj_list);
		if(min_cost == inf){
			cout<<-1<<endl;
		}else{
			cout<<min_cost<<endl;
		}
		delete []adj_list;
	}
	return 0;
}