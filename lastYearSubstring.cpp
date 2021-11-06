#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	if(s.size() < 4){
		cout<<"NO"<<'\n';
		return;
	}else{
		if(s[0] == '2' && s[1] == '0' && s[2] == '2' && s[3] == '0'){
			//cout<<"a"<<'\n';
			cout<<"YES"<<'\n';
		}else if(s[n-1] == '0' && s[n-2] == '2' && s[n-3] == '0' && s[n-4] == '2'){
				//cout<<"b"<<'\n';
			cout<<"YES"<<'\n';
		}else if(s[0] == '2' && s[1] == '0' && s[2] == '2' && s[n-1] == '0'){
			//cout<<"c"<<'\n';
			cout<<"YES"<<'\n';
		}else if(s[0] == '2' && s[n-1] == '0' && s[n-2] == '2' && s[n-3] == '0'){
			//cout<<"d"<<"\n";
			cout<<"YES"<<'\n';
		}else if(s[0] == '2' && s[1] == '0' && s[n-1] == '0' && s[n-2] == '2'){
			//cout<<'e'<<'\n';
			cout<<"YES"<<'\n';
		}else{
			cout<<"NO"<<'\n';
		}
	}
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