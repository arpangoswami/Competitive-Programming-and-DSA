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
	vi arr(n);
	int cumXor = 0;
	for(int &i:arr){
		cin >> i;
		cumXor ^= i;
	}
	if(cumXor == 0){
		cout << "YES" << '\n';
		return;
	}
	int curr = 0;
	int freq = 0;
	for(int x:arr){
		curr ^= x;
		if(curr == cumXor){
			freq++;
			curr = 0;
		}
	}
	if(freq > 1 && (freq & 1) == 1){
		cout<<"YES"<<'\n';
	}else{
		cout<<"NO"<<'\n';
	}
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