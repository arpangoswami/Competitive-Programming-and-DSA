#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int MOD = 998244353;
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
void solveQuestion(){
	int n;
	cin >> n;
	vector<int> fib(n+1);
	fib[0] = 0LL;
	fib[1] = 1LL;
	fib[2] = 1LL;
	for(int i=3;i<=n;i++){
		fib[i] = fib[i-2] + fib[i-1];
		fib[i] %= MOD;
	}
	int den = ferm_inv(power(2LL,n));
	cout << (fib[n] * den)%MOD << '\n';
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test = 1;
	//cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}