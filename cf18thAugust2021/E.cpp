#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
#define ff first
#define ss second
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	string s;
	cin >> s;
	int N = s.size();
	set<char> st;
	string app;
	for(int i=N-1;i>=0;i--){
		if(st.count(s[i]) == 0){
			app.push_back(s[i]);
			st.insert(s[i]);
		}
	}
	reverse(app.begin(),app.end());
	map<char,int> mp;
	for(int i=0;i<app.size();i++){
		mp[app[i]] = (i+1);
	}
	map<char,int> freq;
	for(int i=0;i<N;i++){
		freq[s[i]]++;
	}
	map<char,int> original;
	for(auto it:freq){
		char c = it.first;
		int fr = it.second;
		if(fr % mp[c] != 0){
			cout<<"-1\n";
			return;
		}
		original[c] = fr/mp[c];
	}
	int length = 0;
	for(auto it:original){
		length += it.ss;
	}
	string build = "";
	string add = s.substr(0,length),perm = add;
	int i=0;
	while(add.size() > 0 && i < app.size()){
		build += add;
		string newStr;
		for(char c:add){
			if(c != app[i]){
				newStr.push_back(c);
			}
		}
		add = newStr;
		i++;
	}
	if(build != s){
		cout<<"-1\n";
		return;
	}
	cout<<perm<<" "<<app<<"\n";
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	int tt = 1;
	cin >> tt;
	while(tt-- > 0){
		solveQuestion();
	}
	return 0;
}