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
	int m = 0,t = 0;
	for(char c:s){
		if(c == 'T'){
			t++;
		}else{
			m++;
			if(m > t){
				cout<<"NO"<<'\n';
				return;
			}
		}
	}
	if(3 * t != 2 * n){
		cout<<"NO"<<'\n';
		return;
	}
	t = 0,m = 0;
	for(int i=n-1;i>=0;i--){
		if(s[i] == 'T'){
			t++;
		}else{
			m++;
			if(m > t){
				cout<<"NO"<<'\n';
				return;
			}
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