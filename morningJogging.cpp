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
void solveQuestion(){
	int n,m;
	cin >> n >> m;
	vector<vector<int>> paths(n,vector<int>(m));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> paths[i][j];
		}
	}
	vector<array<int,3>> arr;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			arr.push_back({paths[i][j],i,j});
		}
	}
	sort(arr.begin(),arr.end());
	map<int,pii> mp;
	for(int i=0;i<m;i++){
		array<int,3> ar = arr[i];
		mp[i] = {ar[1],ar[2]};
	}
	vector<vector<int>> matrix(n,vector<int>(m));
	set<int> picked[n];
	for(auto it:mp){
		int x = it.second.ff,y = it.second.ss;
		picked[x].insert(y);
		int val = it.first;
		matrix[x][val] = paths[x][y];
	}
	for(int i=0;i<n;i++){
		int ptr = 0;
		int j = 0;
		while(j < m && ptr < m){
			if(picked[i].count(ptr)){
				ptr++;
				continue;
			}
			if(matrix[i][j] != 0){
				j++;
				continue;
			}
			matrix[i][j] = paths[i][ptr];
			j++;
			ptr++;
		}
	}
	for(int i=0;i<n;i++){
		for(int x:matrix[i]){
			cout<<x<<" ";
		}
		cout<<'\n';
	}
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test = 1;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}