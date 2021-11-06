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
	int steps = 0;
	if(n == 1){
		cout<<0<<'\n';
	}else if(n == 2){
		cout<<1<<'\n';
	}else if(n % 2 == 0){
		cout<<2<<'\n';
	}else if(n == 3){
		cout<<2<<'\n';
	}
	else{
		cout<<3<<'\n';
	}
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