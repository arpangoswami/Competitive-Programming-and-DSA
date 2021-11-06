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
	int n,x;
	cin >> n >> x;
	vi arr(n);
	int s = 0;
	for(int &i:arr){
		cin >> i;
		s += i;
	}
	if(s == x){
		cout<<"NO"<<'\n';
		return;
	}
	cout<<"YES"<<"\n";
	if(arr[0] == x){
		swap(arr[0],arr[1]);
	}
	int sum = 0;
	for(int i=0;i<n;i++){
		sum += arr[i];
		if(sum == x){
			swap(arr[i],arr[i+1]);
		}
	}
	for(int x:arr){
		cout<<x<<" ";
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