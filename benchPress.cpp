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
	int n,wreq,wrod;
	cin >> n >> wreq >> wrod;
	vi arr(n);
	unordered_map<int,int> mp;
	for(int &i:arr){
		cin >> i;
		mp[i]++;
	}
	int sum = wrod;
	for(auto it:mp){
		if(it.second >= 2){
			if(it.second % 2 == 0){
				sum += (it.second) * (it.first);
			}else{
				sum += (it.second - 1) * (it.first);
			}
		}
	}
	string ans = sum >= wreq ? "YES" : "NO";
	cout << ans << '\n';
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