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
	int n,p;
	cin >> n >> p;
	vector<pii> weights;
	vi arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i];
		if(arr[i] < p){
			weights.push_back({arr[i],i});
		}
	}
	sort(weights.begin(), weights.end());
	vector<bool> connected(n-1);
	int ans = 0;
	for(pii x:weights){
		int value = x.first,index = x.second;
		for(int i=index;i>0 && arr[i-1] % value == 0 && connected[i-1] == false;i--){
			ans += value;
			connected[i-1] = true;
		}
		for(int i=index;i<(n-1) && arr[i+1] % value == 0 && connected[i] == false;i++){
			ans += value;
			connected[i] = true;
		}
	}
	for(bool x:connected){
		if(!x){
			ans += p;
		}
	}
	cout<<ans<<'\n';
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