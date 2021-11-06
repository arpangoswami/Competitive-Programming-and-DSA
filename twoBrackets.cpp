#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	string s;
	cin >> s;
	int curlBrack = 0,straightBrack = 0;
	int ans = 0;
	for(char c:s){
		if(c == ']'){
			if(straightBrack > 0){
				straightBrack--;
				ans++;
			}
		}else if(c == ')'){
			if(curlBrack > 0){
				curlBrack--;
				ans++;
			}
		}else if(c == '('){
			curlBrack++;
		}else if(c == '['){
			straightBrack++;
		}
	}
	cout<<ans<<'\n';
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}