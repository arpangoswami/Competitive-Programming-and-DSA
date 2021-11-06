#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int MOD = 1e9+7;
int sz = 2e5+5;
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
	int n,k;
	cin >> n >> k;
	vi arr(n);
	unordered_map<int,int> mp;
	for(int &i:arr){
		cin >> i;
		mp[i]++;
	}
	sort(arr.begin(),arr.end(),greater<int>());
	int tot = mp[arr[k-1]];
	int cnt = 0;
	int ptr = k-1,val = arr[k-1];
	while(arr[ptr] == val){
		cnt++;
		ptr--;
	}
	cout<<nCr(tot,cnt) % MOD << '\n';
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	pre();
	int test;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}