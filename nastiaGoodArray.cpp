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
vi prime;
int num1 = 1000000007LL;
int num2 = 1000000009LL;
void solveQuestion(){
	int n;
	cin >> n;
	vi arr(n+1);
	for(int i=1;i<=n;i++){
		cin >> arr[i];
	}
	vector<array<int,4>> v;
	for(int i=2;i<=n;i+=2){
		v.push_back({i-1,i,min(arr[i-1],arr[i]),num1});
	}
	cout << v.size() << '\n';
	for(auto x:v){
		cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<" "<<x[3]<<'\n';
	}
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