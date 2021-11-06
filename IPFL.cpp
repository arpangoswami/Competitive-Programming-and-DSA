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
	string s;
	cin >> s;
	int q;
	cin >> q;
	int type2 = 0;
	while(q--){
		int t,u,v;
		cin >> t >> u >> v;
		u--;
		v--;
		if(t == 1){
			//int n1 = 
			swap(s[(u+type2*n)%(2*n)],s[(v+type2*n)%(2*n)]);
		}else{
			type2++;
		}
	}
	if(type2 & 1){
		for(int i=n;i<2*n;i++){
			cout<<s[i];
		}
		for(int i=0;i<n;i++){
			cout<<s[i];
		}
		return;
	}
	cout << s;
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