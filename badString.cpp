#include <bits/stdc++.h>
#define int long long
using namespace std;
void solveQuestion(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int cnt = 0;
	for(int i=n-1;i>=0 && s[i] == ')';i--){
		cnt++;
	}
	int val = n-cnt;
	string ans = (cnt > val) ? "Yes" : "No";
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