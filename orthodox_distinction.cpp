#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
int32_t main(int32_t argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin >> test;
	while (test--) {
		int n;
		cin >> n;
		vector<int> arr(n);
		for(int i=0;i<n;i++){
			cin >> arr[i];
		}
		if(n >= 63){
			cout << "NO" <<"\n";
		}else{
			set<int> st;
			bool f = true;
			for(int i=0;i<n && f;i++){
				int val = 0;
				for(int j=i;j<n && f;j++){
					val = val | arr[j];
					if(st.count(val)){
						f = false;
					}
					st.insert(val);
				}
			}
			string ans = f ? "YES" : "NO";
			cout << ans <<"\n";
		}
	}
}