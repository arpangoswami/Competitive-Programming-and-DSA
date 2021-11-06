#include <bits/stdc++.h>
#define int long long
using namespace std;
bool check(string &s){
	stack<char> st;
	for(char ch:s){
		if(ch == ')'){
			bool f = true;
			char topCh = st.top();
			st.pop();
			while(!st.empty() && topCh!='('){
				if(topCh!='(')
					f = false;
				topCh = st.top();
				st.pop();
			}
			if(f) return true;
		}else{
			st.push(ch);
		}
	}
	return false;
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		string str;
		cin >> str;
		string ans = check(str) ? "Duplicate" : "Not Duplicates";
		cout << ans << "\n";
	}
	return 0;
}