#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int MOD = 998244353;
void solveQuestion(){
	int n,q;
	cin >> n >> q;
	string s;
	cin >> s;
	n = s.size();
	while(q--){
		int l,r;
		cin >> l >> r;
		l--;
		r--;
		if(l < 0 || r>=n){
			return;
		}
		bool f1 = false,f2 = false;
		char c1 = s[l];
		char c2 = s[r];
		for(int i=r+1;i<n;i++){
			if(s[i] == c2){
				f2 = true;
				break;
			}
		}
		if(f2){
			cout<<"YES"<<'\n';
			continue;
		}
		for(int i=0;i<l;i++){
			if(s[i] == c1){
				f1 = true;
			}
		}
		if(f1){
			cout<<"YES"<<'\n';
			continue;
		}
		cout<<"NO"<<'\n';
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