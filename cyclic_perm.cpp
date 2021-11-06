#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int mod = 1e9 + 7;
int fact(int num){
	int ans = 1;
	for(int i=1;i<=num;i++){
		ans = ans * i;
		ans %= mod;
	}
	return ans;
}
int power(int a,int b){
	if(b == 0){
		return 1;
	}
	int smallProd = power(a,b/2);
	int ans = (smallProd*smallProd)%mod;
	if(b%2 == 0){
		return ans;
	}
	return (ans * a)%mod;
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	int ans = fact(n);
	int sub = power(2,n-1);
	ans = (ans - sub + mod)%mod;
	cout << ans << "\n";
	return 0;
}