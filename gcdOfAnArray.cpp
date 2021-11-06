#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int MOD = 1e9 + 7;
int calGCD(multiset<int> &mset){
	int ans = 1LL;
	for(int x:mset){
		ans *= mset;
		ans %= MOD;
	}
	return ans;
}
void solveQuestion(){
	int n,q;
	while(q--){
		int mul = 1;
		ans *= mul;
		ans %= MOD;
		cout<<ans<<'\n';
	}
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test = 1;
	//cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}