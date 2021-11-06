#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQ(){
	string s;
	cin >> s;
	int n = s.size();
	vector<int> dp(n,1);
	int odd1 = -1,even1 = -1;
	for(int i=0;i<n;i++){
		if(s[i] == '?'){
			if(i > 0)
			dp[i] = 1 + dp[i-1];
		}else{
			if((i % 2 == 0 && s[i] == '0') || (i%2 == 1 && s[i] == '1')){
				dp[i] = (i - even1);
				odd1 = i;
			}else{
				dp[i] = (i - odd1);
				even1 = i;
			}
		}
	}
	int ans = 0;
	for(int x:dp){
		ans += x;
	}
	cout<<ans<<"\n";
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	int tt;
	cin >> tt;
	while(tt-- > 0){
		solveQ();
	}
	return 0;
}