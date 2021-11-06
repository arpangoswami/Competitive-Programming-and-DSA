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
int root(int n){
	return sqrt((double)(n));
}
void solveQuestion(){
	int n;
	cin >> n;
	vi arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	for(int i=0;i<n;i++){
		int rt = root(arr[i]);
		//cout<<"rt: "<<rt<<'\n';
		if(rt * rt != arr[i]){
			cout<<"YES"<<'\n';
			return;
		}
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