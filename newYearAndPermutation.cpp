#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int MOD = 998244353LL;
int sz = 250000+5,n;
vector<int> fact(sz);
void pre(){
	fact[0] = 1LL;
	for(int i=1LL;i<sz;i++){
		fact[i] = fact[i-1] * i;
		fact[i] %= MOD;
	}
}
void solveQuestion(){
	int ans = 0;
	for(int len=1;len<=n;len++){
		int possible = (n-len+1);
		possible *= possible;
		possible %= MOD;
		possible *= fact[n-len];
		possible %= MOD;
		possible *= fact[len];
		possible %= MOD;
		ans += possible;
		ans %= MOD;
	}
	cout<<ans<<'\n';
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test = 1;
	//cin>>test;
	while(test--){
		cin >> n >> MOD;
		pre();
		solveQuestion();
	}
	return 0;
}