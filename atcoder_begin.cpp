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
	int r1,c1;
	int r2,c2;
	cin >> r1 >> c1;
	cin >> r2 >> c2;
	if(r1 == r2 && c1 == c2){
		cout<<0;
		return;
	}
	if(r1 + c1 == r2 + c2){
		cout<<1;
		return;
	}else if(r1 - c1 == r2 - c2){
		cout<<1;
		return;
	}else if(abs(r1-r2) + abs(c1-c2) <= 3){
		cout<<1;
		return;
	}
	int diff1 = (r1-c1),diff2 = (r2-c2);
	//cout<<diff1<<" "<<diff2<<'\n';
	if(abs(diff1 - diff2) <= 3){
		cout<<2;
		return;
	}
	int mod1 = ((r1 + c1)%2 + 2)%2,mod2 = ((r2 + c2)%2 + 2)%2;
	if(mod1 == mod2){
		cout<<2;
		return;
	}else{
		cout<<3;
		return;
	}
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