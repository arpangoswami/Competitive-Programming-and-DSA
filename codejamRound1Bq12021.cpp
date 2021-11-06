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
int n,a,b;
vi arr;
bool check(int num){
	while(){
		
	}
}
void solveQuestion(){
	cin >> n >> a >> b;
	arr.clear();
	arr.resize(n+1);
	for(int i=1;i<=n;i++){
		cin >> arr[i];
	}
	int low = 1LL,high = 40LL,ans = high;
	for(int i=1;i<=40;i++){
		if(check(i)){
			cout << i << '\n';
			return;
		}
	}
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test;
	cin>>test;
	for(int t=1;t<=test;++t){
		cout<<"Case #"<<t<<": ";
		solveQuestion();
	}
	return 0;
}