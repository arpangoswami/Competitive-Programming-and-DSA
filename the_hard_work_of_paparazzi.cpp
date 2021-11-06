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
struct event{
	int time;
	int x_co;
	int y_co;
	event(){
		time = 0;
		x_co = 0;
		y_co = 0;
	}
	event(int t,int x,int y):time(t),x_co(x),y_co(y){

	}
};
void solveQuestion(){
	int r,n;
	cin >> r >> n;
	vector<event> pap(n+1);
	pap[0].time = 0;
	pap[0].x_co = 1;
	pap[0].y_co = 1;
	for(int i=1;i<=n;i++){
		cin >> pap[i].time >> pap[i].x_co >> pap[i].y_co;
	}
	vector<int> dp(n+1,-1e9);
	dp[0] = 0;
	for(int i=1;i<=n;i++){
		int lastIdx = max(0LL,i-4*r-1);
		for(int j=lastIdx;j<i;j++){
			if(abs(pap[j].x_co-pap[i].x_co) + abs(pap[j].y_co - pap[i].y_co) <= pap[i].time - pap[j].time){
				dp[i] = max(dp[i],1 + dp[j]);
			}
		}
	}
	int ans = 0;
	for(int x:dp){
		//cout<<x<<" ";
		ans = max(x,ans);
	}
	cout<<ans<<'\n';
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