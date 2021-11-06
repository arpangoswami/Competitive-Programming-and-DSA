#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int MOD = 998244353;
int sz = 1e5+5;
vector<int> fact(sz);
void pre(){
	fact[0] = 1;
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
	int ans = 0;
	ans += power(2LL,29LL);
	ans %= MOD;
	ans += power(2LL,39LL);
	ans %= MOD;
	ans += power(2LL,29LL);
	ans %= MOD;
	ans += power(2LL,49LL);
	ans %= MOD;
	cout<<ans<<'\n';
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	pre();
	int test = 1;
	//cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}