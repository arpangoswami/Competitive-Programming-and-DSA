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
	if(n & 1){
		cout<<"NO"<<'\n';
		return;
	}
	int f1 = sqrt((double)(n/2)),f2 = sqrt((double)(n/4));
	if((double)(f1 * f1) == (n/2.0)){
		cout<<"YES"<<'\n';
		return;
	}
	if((double)(f2 * f2) == (n/4.0)){
		cout<<"YES"<<'\n';
		return;
	}
	cout<<"NO"<<'\n';
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