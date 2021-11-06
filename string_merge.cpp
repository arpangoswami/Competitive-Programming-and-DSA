#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int max_size = 0;
int solve(string &s,int idx,map<vector<int>,int> &mp,int dp){
	if(idx == (long long)s.size()){
		for(auto it:mp){
			if(it.second > 0){
				return dp[idx] = 0;
			}
		}
		return dp[idx] = 1;
	}
	if(dp[idx]!=-1){
		return dp[idx];
	}
	int n = s.size();
	int length = min(max_size,n-idx);
	vector<int> freq(26,0);
	for(int i=1;i<=length;i++){
		freq[s[idx+i-1]-'a']++;
		int c = mp[freq];
		if(c > 0){
			//cout<<"sub: "<<s.substr(idx,i)<<"\n";
			mp[freq]--;
			int f = solve(s,idx+i,mp,dp);
			if(f == 1){
				return dp[idx] = 1;
			}
			mp[freq]++;
		}
	}
	return dp[idx] = 0;
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	string big;
	cin >> big;
	int n;
	cin >> n;
	int dp[big.size()+1];
	for(int i=0;i<=big.size();i++){
		dp[i] = -1;
	}
	map<vector<int>,int> mp;
	for(int i=0;i<n;i++){
		string s;
		cin >> s;
		max_size = max(max_size,(long long)s.size());
		vector<int> freq(26,0);
		for(char c:s){
			freq[c - 'a']++;
		}
		mp[freq]++;
	}
	int ans = solve(big,0,mp,dp);
	if(ans == 1){
		cout<<"YES";
	}else{
		cout<<"NO";
	}
}