#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int intersection(set<char> &st1,set<char> &st2){
	int ans = 0;
	for(char c:st1){
		if(st2.count(c) == 0){
			ans++;
		}
	}
	return ans;
}
void solveQuestion(){
	int n;
	cin >> n;
	map<string,set<char>> mp;
	for(int i=0;i<n;i++){
		string s;
		cin >> s;
		mp[s.substr(1)].insert(s[0]);
	}
	int ans = 0;
	for(auto it:mp){
		for(auto it2:mp){
			if(it == it2){
				continue;
			}
			ans += (intersection(it.second,it2.second) * intersection(it2.second,it.second));
		}
	}
	cout<<ans<<'\n';
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