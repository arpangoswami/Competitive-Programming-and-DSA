#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
//const int MOD = 998244353;
unordered_map<int,int> primeFactor(int n){
	unordered_map<int,int> mp;
	while(n % 2 == 0){
		mp[2]++;
		n/=2;
	}
	for(int i=3;i*i<=n;i+=2){
		while(n % i == 0){
			mp[i]++;
			n/=i;
		}
	}
	if(n > 2){
		mp[n]++;
	}
	return mp;
}
int power(int x,int y){
	int ans = 1LL;
	//x %= MOD;
	while(y){
		if(y & 1){
			ans *= x;
			//ans %= MOD;
		}
		x *= x;
		//x %= MOD;
		y>>=1;
	}
	return ans;
}
void solveQuestion(){
	int n;
	cin >> n;
	unordered_map<int,int> mp = primeFactor(n);
	int maxNum = -1,maxPower = -1;
	for(auto it:mp){
		if(it.second > maxPower){
			maxPower = it.second;
			maxNum = it.first;
		}
	}
	cout<<maxPower<<'\n';
	for(int i=0;i<(maxPower-1);i++){
		cout<<maxNum<<" ";
	}
	cout<<(n/power(maxNum,maxPower-1))<<'\n';
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