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
	int n,k;
	cin >> n >> k;
	vector<int> next(k,0);
	for(int i=0;i<k;i++){
		next[i] = i;
	}
	vector<int> ans(n);
	int prev = ans[0];
	for(int i=1;i<n;i++){
		ans[i] = next[prev];
		next[prev] = (next[prev]+1)%k;
		prev = ans[i];
	}
	for(int i=0;i<n;i++){
		cout<<(char)(ans[i] + 'a');
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