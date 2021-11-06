#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int MOD = 1e9 + 7;
const int MOD2 = 1e9 + 6;
int power(int x,int y,int mod = MOD){
	int ans = 1LL;
	x %= mod;
	while(y){
		if(y & 1){
			ans *= x;
			ans %= mod;
		}
		x *= x;
		x %= mod;
		y>>=1;
	}
	return ans;
}
int ferm_inv(int n){S
	return power(n,MOD-2);
}
void solveQuestion(){
	int a,b,c;
	cin >> a >> b >> c;
	int pow = power(b,c,MOD2);
	cout<<power(a,pow,MOD)<<'\n';
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}