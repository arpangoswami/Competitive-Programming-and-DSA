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
	int m,n,k;
	cin >> m >> n >> k;
	int minm = (n-1) + (m-1)*n;
	int maxm = (m-1) + (n-1)*m;
	if(m >= n){
		swap(minm,maxm);
	}
	if(k < minm || k > maxm){
		cout<<"NO"<<'\n';
		return;
	}
	cout<<"YES"<<'\n';
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