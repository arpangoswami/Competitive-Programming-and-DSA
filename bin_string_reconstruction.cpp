#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	string s;
	cin >> s;
	int x;
	cin >> x;
	vector<int> ans(s.size(),-1);
	int n = s.size();
	for(int i=0;i<n;i++){
		if(s[i] == '0'){
			int lidx = i-x;
			if(lidx >= 0){
				ans[lidx] = 0;
			}
			int ridx = i+x;
			if(ridx < n){
				ans[ridx] = 0;
			}
		}
	}
	bool f = true;
	for(int i=0;i<n;i++){
		if(s[i] == '1'){
			int lidx = i-x;
			int two = 0;
			if(lidx < 0 || (lidx >= 0 && ans[lidx]!=-1)){
				two++;
			}
			int ridx = i+x;
			if(ridx >=n || (ridx < n && ans[ridx]!=-1)){
				two++;
			}
			if(two == 2){
				f = false;
				break;
			}
		}
	}
	if(!f){
		cout<<-1<<"\n";
		return;
	}
	for(int i=0;i<n;i++){
		if(ans[i] == -1){
			ans[i] = 1;
		}
	}
	for(int x:ans){
		cout<<x;
	}
	cout<<"\n";
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