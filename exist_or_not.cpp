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
		unordered_set<int> st;
		for(int i=0;i<n;i++){
			int x;
			cin >> x;
			st.insert(x);
		}
		int q;
		cin >> q;
		while(q--){
			int x;
			cin >> x;
			string ans = st.count(x) ? "Yes" : "No";
			cout << ans << "\n";
		}
	}
	return 0;
}