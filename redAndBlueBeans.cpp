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
	int n,m,d;
	cin >> n >> m >> d;
	if(d == 0){
		if(n == m){
			cout<<"YES"<<"\n";
		}else{
			cout<<"NO\n";
		}
		return;
	}
	int packets = (abs(m-n) + (d-1))/d;
	if(packets > min(m,n)){
		cout<<"NO\n";
		return;
	}
	cout<<"YES\n";
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