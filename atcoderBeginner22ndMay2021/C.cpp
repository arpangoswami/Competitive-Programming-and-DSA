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
	int n;
	cin >> n;
	vi Afreq(n+1),Bfreq(n+1);
	vi A(n+1),B(n+1),C(n+1);
	for(int i=1;i<=n;i++){
		cin >> A[i];
		Afreq[A[i]]++;
	}
	for(int i=1;i<=n;i++){
		cin >> B[i];
	}
	for(int i=1;i<=n;i++){
		cin >> C[i];
		Bfreq[B[C[i]]]++;
	}
	int ans = 0;
	for(int i=1;i<=n;i++){
		ans += Afreq[i]*Bfreq[i];
	}
	cout << ans;
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