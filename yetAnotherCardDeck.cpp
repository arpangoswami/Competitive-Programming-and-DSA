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
void modify(int color,map<int,int> &mp){
	int t1 = mp[color];
	for(auto it:mp){
		if(it.first != color && it.second < t1){
			int temp = it.second;
			mp[it.first] = temp+1;
		}
	}
	mp[color] = 1;
}
void solveQuestion(){
	int n,q;
	cin >> n >> q;
	vi arr(n+1);
	for(int i=1;i<=n;i++){
		cin >> arr[i];
	}
	vi queries(q);
	for(int &i:queries){
		cin >> i;
	}
	map<int,int> firstApp;
	for(int i=1;i<=n;i++){
		if(firstApp.count(arr[i]) == 0){
			firstApp[arr[i]] = i;
		}
	}

	for(int i=0;i<q;i++){
		int color = queries[i];
		cout<<firstApp[queries[i]]<<" ";
		modify(color,firstApp);
		// for(auto it:firstApp){
		// 	cout<<it.first<<" -> "<<it.second<<'\n';
		// }
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