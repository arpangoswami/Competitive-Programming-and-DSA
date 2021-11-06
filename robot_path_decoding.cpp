#include <bits/stdc++.h>
#define int long long
const int mod = 1e9;
using namespace std;
typedef pair<int, int> pii;
int32_t main(int32_t argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int test;
	cin >> test;
	for (int t = 1; t <= test; ++t) {
		int curr_x = 0,curr_y = 0;
		string s;
		cin >> s;
		int multiplier = 1;
		int n = s.size();
		stack<int> st;
		for(int i=0;i<n;i++){
			if(s[i]>='2' && s[i]<='9'){
				multiplier*=(s[i] - '0');
				st.push(s[i]-'0');
			}else if(s[i] == ')'){
				int x = st.top();
				st.pop();
				multiplier/=x;
			}else if(s[i] == 'N' || s[i] == 'S' || s[i] == 'E' || s[i] == 'W'){
				if(s[i] == 'N'){
					curr_y-=multiplier;
				}else if(s[i] == 'S'){
					curr_y+=multiplier;
				}else if(s[i] == 'E'){
					curr_x+=multiplier;
				}else if(s[i] == 'W'){
					curr_x-=multiplier;
				}
				if(curr_x < 0){
					int div = curr_x/mod;
					div++;
					curr_x = curr_x + div * mod;
				}
				if(curr_y < 0){
					int div = curr_y/mod;
					div++;
					curr_y = curr_y + div*mod;
				}
				curr_y%=mod;
				curr_x%=mod;
			}
		}
		curr_x++;
		curr_y++;
		cout << "Case #" << t << ":" << " " << curr_x << " " << curr_y << "\n";
	}
	return 0;
}
