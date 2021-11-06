#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	string s;
	cin >> s;
	n = s.size();
	int cnt = 1,ans = 1;
	char prev = s[0];
	for(int i=1;i<n;i++){
		if(s[i] == prev){
			cnt++;
			ans = max(cnt,ans);
		}else{
			cnt = 1;
			prev = s[i];
		}
	}
	cout<<ans<<"\n";
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test = 1;
	//cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}