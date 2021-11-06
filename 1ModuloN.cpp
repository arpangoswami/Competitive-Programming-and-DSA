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
int gcd(int a, int b){return (b==0)?a:gcd(b,a%b);}
void solveQuestion(){
	int n;
	cin >> n;
	vi arr;
	int md = 1;
	for(int i=1;i<n;i++){
		if(gcd(i,n) == 1){
			arr.push_back(i);
			md = (md * i)%n;
		}
	}
	if(md > 1){
		cout << arr.size() - 1 << '\n';
	}else{
		cout << arr.size() << '\n';
	}
	for(int x:arr){
		if(x == md && md > 1){
			continue;
		}
		cout << x << ' ';
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