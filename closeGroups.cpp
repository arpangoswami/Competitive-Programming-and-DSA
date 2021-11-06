/*
	https://atcoder.jp/contests/abc187/tasks/abc187_f
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 18;
bool adj_mat[N][N];
bool good[1 << N];
int dp[1 << N];
void solveQuestion(){
	int n,m;
	cin >> n >> m;
	int subsets = 1LL << n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			adj_mat[i][j] = false;
		}
	}
	for(int i=0;i<m;i++){
		int u,v;
		cin >> u >> v;
		--u;
		--v;
		adj_mat[u][v] = true;
		adj_mat[v][u] = true;
	}
	for(int i=0;i<subsets;i++){
		vector<int> setBits;
		for(int j=0;j<n;j++){
			if(i & (1LL << j)){
				setBits.push_back(j);
			}
		}
		bool f = true;
		int N = setBits.size();
		for(int j=0;j<(N-1);j++){
			for(int k=j+1;k<N;k++){
				if(adj_mat[setBits[j]][setBits[k]] == false){
					f = false;
					break;
				}
			}
			if(!f){
				break;
			}
		}
		good[i] = f;
	}
	dp[0] = 0;
	for(int i=1;i<subsets;i++){
		dp[i] = 1e9;
	}
	for(int i=1;i<subsets;i++){
		if(good[i])
            dp[i] = 1;
        for(int j=i;j;j=(j-1)&i)
        {
            dp[i] = min(dp[i],dp[j]+dp[i^j]);
        }
	}
	cout<<dp[subsets-1]<<'\n';
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
