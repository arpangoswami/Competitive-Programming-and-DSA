#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin >> test;
	while(test--){
		int n;
		cin >> n;
		string s;
		cin >> s;
		int cnt = 0;
		while(!s.empty() && s[0] == s.back()){
			cnt++;
			s.pop_back();
		}
		if(s.empty()){
			if(cnt <= 2){
				cout<<0<<"\n";
			}else{
				cout<<(cnt+2)/3<<"\n";
			}
			continue;
		}
		int ans = 0;
		s.push_back('$');
		for(int i=0;(i+1)<(long long)s.size();i++){
			cnt++;
			if(s[i]!=s[i+1]){
				ans += cnt/3;
				cnt = 0;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}