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
//const int MOD = 998244353;
const int sz = 2e5+5;
vector<int> fact(sz);
int gcd(int a, int b){return (b==0)?a:gcd(b,a%b);}
int power(int x,int y){
	int ans = 1LL;
	//x %= MOD;
	while(y){
		if(y & 1){
			ans *= x;
			//ans %= MOD;
		}
		x *= x;
		//x %= MOD;
		y>>=1;
	}
	return ans;
}
void solveQuestion(){
	int a,b,c;
	cin >> a >> b >> c;
	int num1 = power(10LL,a-1);
	int num3 = power(10LL,c-1);
	int num2 = power(10LL,b-1) + num3;
	cout<<num1<<" "<<num2<<'\n';	
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