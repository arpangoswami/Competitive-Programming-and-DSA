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
char dx[4] = {1,0,0,-1};
char dy[4] = {0,-1,1,0};
vector<int> region;
vi input;
int n;
vector<vector<bool>> visited;
vector<vector<int>> matrix;
void dfs(int i,int j,int num){
	if(region[num] == num){
		return;
	}
	matrix[i][j] = num;
	visited[i][j] = true;
	region[num]++;
	auto isSafe = [&](int x,int y){
		return (x >= 0 && y >= 0 && x < n && y < n && !visited[x][y]);
	};
	for(int k=0;k<4;k++){
		if(isSafe(i+dx[k],j+dy[k])){
			dfs(i+dx[k],j+dy[k],num);
		}
	}
}
void solveQuestion(){
	cin >> n;
	region.clear();
	input.clear();
	region.resize(n+1);
	for(int i=1;i<=n;i++){
		region[i] = 0;
	}
	input.resize(n);
	for(int &i:input){
		cin >> i;
	}
	matrix.clear();
	matrix.resize(n);
	visited.clear();
	visited.resize(n);
	for(int i=0;i<n;i++){
		visited[i].clear();
		visited[i].resize(n);
		matrix[i].clear();
		matrix[i].resize(n);
		matrix[i][i] = input[i];
		for(int j=0;j<=i;j++){
			visited[i][j] = false;
		}
	}
	for(int i=n-1;i>=0;i--){
		dfs(i,i,matrix[i][i]);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			cout<<matrix[i][j]<<" ";
		}
		cout<<'\n';
	}
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