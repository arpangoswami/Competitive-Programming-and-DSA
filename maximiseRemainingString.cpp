#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,char> pii;
void solveQuestion(){
	map<char,vector<int>> mp;
	set<pii> st;
	string s;
	for(int i=0;i<n;i++){
		mp[s[i]].push_back(i);
	}
	vector<int> ptr(26);
	string ans;
	for(auto it:mp){
		if(it.second.size() == 1){
			st.insert({it.second[0],it.first});
		}
	}
	auto it = st.begin()
	for(char c:s){
		if(c)
	}
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}