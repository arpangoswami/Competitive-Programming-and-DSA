#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	string ans = "satisfiable";
	set<string> sat,unsat;
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		string s;
		cin >> s;
		if(s[0] == '!'){
			unsat.insert(s);
		}else{
			sat.insert(s);
		}
	}
	for(string x:sat){
		string temp = "!" + x;
		if(unsat.count(temp)){
			cout<<x<<'\n';
			return;
		}
	}
	cout<<ans<<'\n';
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test = 1;
	//cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}