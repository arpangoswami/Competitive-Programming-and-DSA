#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	cin >> s;
	string ans;
	int n = s.size();
	for(int i=0;i<n;){
		char ch = s[i];
		int cnt = 0;
		while(i<n && s[i] == ch){
			cnt++;
			i++;
		}
		ans.push_back(ch);
		ans+=to_string(cnt);
	}
	cout << ans << "\n";
	return 0;
}