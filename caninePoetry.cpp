#include <bits/stdc++.h>
#define int long long
using namespace std;
void solveQuestion(){
	string s;
	cin >> s;
	int n = s.size();
	int ans = 0;
	for(int i=1;i<n;i++){
		if(s[i-1] != '*' && s[i] == s[i-1]){
			ans++;
			s[i] = '*';
		}
		if(i >= 2 && s[i-2] != '*' && s[i-2] == s[i]){
			s[i] = '*';
			ans++;
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