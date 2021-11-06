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
	int n,m,x;
	cin >> n >> m >> x;
	vi arr(n+1);
	for(int i=1;i<=n;i++){
		cin >> arr[i];
	}
	priority_queue<pii,vector<pii>,greater<pii>> pq;
	vector<int> sol(n+1);
	for(int i=1;i<=m;i++){
		pq.push({arr[i],i});
		sol[i] = i;
	}
	for(int i=m+1;i<=n;i++){
		pii temp = pq.top();
		pq.pop();
		int ht = temp.first,building = temp.second;
		sol[i] = building;
		pq.push({ht+arr[i],building});
	}
	cout<<"YES"<<'\n';
	for(int i=1;i<=n;i++){
		cout<<sol[i]<<" ";
	}
	cout<<"\n";
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