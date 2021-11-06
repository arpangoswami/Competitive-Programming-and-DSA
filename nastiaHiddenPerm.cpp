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
vi arr;
map<pii,int> type1;
map<pii,int> type2;
int askQuery(int type,int i,int j,int val){
	if(type == 1){
		if(type1.count({i,j})){
			return type[{i,j}];
		}
	}
	if(type == 2){
		if(type2.count({i,j})){
			return type2[{i,j}];
		}
	}
	cout << "? "<<type<<" "<<i<<" "<<j<<" "<<val<<endl;
	int v;
	cin >> v;
	return v; 
}
void solveQuestion(){
	int n;
	cin >> n;
	arr.clear();
	arr.resize(n+1);
	type1.clear();
	type2.clear();
	queue<pii> q;
	int idx = -1;
	for(int i=1;i<n;i++){
		int v = askQuery(2,i,i+1,1);
		type2[{i,j}] = v;
		if(v == 1){
			arr[i] = 1;
			idx = i;
		}else if(i > 1 && askQuery(2,i-1,i,1) == v){
			arr[i] = v;
		}
	}
	if(idx == -1){
		idx = n;
		arr[n] = 1;
	}
	for(int i=idx-1;i>=1;i-=2){
		if(i == 1){
			arr[i] = 
		}
	}
	for(int i=idx+1;i<=n;i+=2){

	}
	cout<<"! ";
	for(int i=1;i<=n;i++){
		cout<<arr[i]<<" ";
	}
	cout << endl;
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