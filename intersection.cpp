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
	int minRange = 0,maxRange = 1e9;
	vi arr1(n);
	for(int &i:arr1){
		cin >> i;
		minRange = max(minRange,i);
	}
	vi arr2(n);
	for(int &i:arr2){
		cin >> i;
		maxRange = min(maxRange,i);
	}
	if(maxRange < minRange){
		cout << 0 << '\n';
	}else{
		cout << (maxRange - minRange + 1);
	}
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