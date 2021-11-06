#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	while(true){
		string s;
		cin>>s;
		int n = s.size();
		if(s == "0"){
			break;
		}
		bool flag = true;
		if(s[0] == '0'){
			flag = false;
		}
		if(flag){
			for(int i=s.size()-1;i>0;i--){
				if(s[i] == '0' && (s[i-1]!='1' && s[i-1]!='2')){
					flag = false;
					break;
				}
			}
		}
		if(!flag){
			cout<<0<<endl;
		}
		else{
			ll *dp = new ll[n+1]();
			dp[0] = 1;
			dp[1] = 1;
			for(int i=2;i<=n;++i){
				int digit1 = s[i-2] - '0',digit2 = s[i-1] - '0';
				int id = digit1*10 + digit2;
				if(digit2 == 0){
					dp[i] = dp[i-2];
				}
				else if(id>9 && id<=26){
					dp[i] = dp[i-1] + dp[i-2];
				}
				else{
					dp[i] = dp[i-1];
				}
			}
			cout<<dp[n]<<endl;
			delete []dp;
		}
	}
	return 0;
}