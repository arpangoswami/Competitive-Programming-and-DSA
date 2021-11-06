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
	int zero = count(s.begin(),s.end(),'0');
		if(zero == 0){
			cout << "DRAW" << "\n";
			return;
		}
	if((n & 1) && s[n/2] == '0'){
		if(zero == 1){
			cout<<"BOB"<<"\n";
			return;
		}else{
			cout<<"ALICE\n";
			return;
		}
	}
	cout<<"BOB\n";
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