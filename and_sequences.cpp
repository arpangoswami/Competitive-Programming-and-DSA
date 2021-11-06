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
const int MOD = 1e9+7;
const int sz = 2e5+5;
vector<int> fact(sz);
int gcd(int a, int b){return (b==0)?a:gcd(b,a%b);}
void pre(){
	fact[0] = 1LL;
	for(int i=1;i<sz;i++){
		fact[i] = fact[i-1] * i;
		fact[i] %= MOD;
	}
}
int power(int x,int y){
	int ans = 1LL;
	x %= MOD;
	while(y){
		if(y & 1){
			ans *= x;
			ans %= MOD;
		}
		x *= x;
		x %= MOD;
		y>>=1;
	}
	return ans;
}
int ferm_inv(int n){
	return power(n,MOD-2);
}
int nCr(int x,int y){
	if(x < 0 || y > x){
		return 0;
	}
	int val = fact[x];
	int div = fact[y] * fact[x-y];
	div %= MOD;
	return (val * ferm_inv(div))%MOD;
}
void solveQuestion(){
	int n;
	cin >> n;
	vi arr(n);
	for(int &i:arr){
		cin >> i;
	}
	int common = 0;
	vector<int> bits(30);
	for(int i=0;i<n;i++){
		for(int j=0;j<30;j++){
			if((arr[i] >> j) & 1){
				bits[j]++;
			}
		}
	}
	for(int i=0;i<30;i++){
		if(bits[i] == n){
			common += (1LL << i);
		}
	}
	int freq = 0;
	for(int i=0;i<n;i++){
		if(arr[i] == common){
			freq++;
		}
	}
	if(freq < 2){
		cout<<0<<'\n';
	}else{
		int ans = (nCr(freq,2LL) * 2LL)%MOD;
		ans *= fact[n-2];
		ans %= MOD;
		cout<<ans<<'\n';
	}
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	pre();
	int test = 1;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}