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
	bool f = true;
	vector<bool> app(26);
	app[s[0] - 'A'] = true;
	for(int i=1;i<n;i++){
		if(s[i] != s[i-1]){
			if(app[s[i] - 'A']){
				cout<<"NO"<<'\n';
				return;
			}
			app[s[i] - 'A'] = true;
		}
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