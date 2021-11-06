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
		int x = (ceil)((double)n/4.0);
		int rem = n-x;
		string ans;
		for(int i=0;i<rem;i++){
			ans.push_back('9');
		}
		for(int i=0;i<x;i++){
			ans.push_back('8');
		}
		cout<<ans<<"\n";
	}
	return 0;
}