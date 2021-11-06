#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		int n;
		cin >> n;
		string s;
		cin >> s;
		unordered_map<char,int> mp;
		for(char c:s){
			mp[c]++;
		}
		bool flag = true;
		for(auto it:mp){
			if(it.second % 2!=0){
				flag = false;
				break;
			}
		}
		string ans = flag ? "YES" : "NO";
		cout<<ans<<"\n";
	}
	return 0;
}