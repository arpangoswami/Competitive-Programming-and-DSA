#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	string s;
	cin >> s;
	int n = s.size();
	int cons1 = -1;
	for(int i=0;i<(n-1);i++){
		if(s[i] == '1' && s[i+1] == '1'){
			cons1 = i;
			break;
		}
	}
	if(cons1 == -1){
		cout<<"YES"<<'\n';
		return;
	}
	bool f = false;
	for(int i=cons1;i<(n-1);i++){
		if(s[i] == '0' && s[i+1] == '0'){
			f = true;
			break;
		}
	}
	if(f){
		cout<<"NO"<<'\n';
		return;
	}
	cout<<"YES"<<'\n';
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