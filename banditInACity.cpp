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
int n;
vector<vector<int>> adj_list;
vector<int> subChild;
vector<int> subLeaves;
vector<int> peopleResiding;
void dfs(int v,int par){
	bool isLeaf = true;
	for(int x:adj_list[v]){
		if(x == par){
			continue;
		}
		isLeaf = false;
		dfs(x,v);
		subChild[v] += subChild[x];
		subLeaves[v] += subLeaves[x];
	}
	if(isLeaf){
		subLeaves[v]++;
	}
	subChild[v] += peopleResiding[v];
}
bool check(int maxRange){
	for(int i=1;i<=n;i++){
		if(maxRange < (subChild[i]+subLeaves[i]-1)/subLeaves[i]){
			return false;
		}
	}
	return true;
}
void solveQuestion(){
	cin >> n;
	adj_list.resize(n+1);
	subChild.resize(n+1);
	subLeaves.resize(n+1);
	peopleResiding.resize(n+1);
	for(int i=1;i<=n;i++){
		adj_list[i].clear();
	}
	for(int i=2;i<=n;i++){
		int u;
		cin >> u;
		adj_list[i].push_back(u);
		adj_list[u].push_back(i);
	}
	for(int i=1;i<=n;i++){
		subChild[i] = 0;
		subLeaves[i] = 0;
		peopleResiding[i] = 0;
		cin >> peopleResiding[i];
	}
	dfs(1,0);
	int low = 0,high = subChild[1],ans = high;
	while(low <= high){
		int mid = (low + high)/2;
		if(check(mid)){
			ans = mid;
			// if(ans == 0){
			// 	break;
			// }
			high = mid-1;
		}else{
			low = mid+1;
		}
	}
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