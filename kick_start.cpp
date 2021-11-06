#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
void solveProblem(){
	string s;
	cin >> s;
	int n = s.size();
	if(n<9){
		cout<<0<<"\n";
		return;
	}
	int cntStart = 0;
	int ans = 0;
	for(int i=0;i<=(n-5);i++){
		if(s.substr(i,5) == "START"){
			cntStart++;
		}
	}
	for(int i=0;i<=(n-5);i++){
		if(s.substr(i,4) == "KICK"){
			ans += cntStart;
		}
		else if(s.substr(i,5) == "START"){
			cntStart--;
		}
	}
	cout<<ans<<"\n";
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int test;
	cin>>test;
	for(int t=1;t<=test;++t){
		cout<<"Case #"<<t<<": ";
		solveProblem();
	}
	return 0;
}