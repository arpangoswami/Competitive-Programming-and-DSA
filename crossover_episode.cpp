#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		int n;
		cin >> n;
		string s = "";
		for(int i=0;i<n;i++){
			s+='a';
		}
		for(int i=0;i<n;i++){
			s+='b';
		}
		cout << 2*n << "\n";
		cout << s << "\n";
	}
	return 0;
}