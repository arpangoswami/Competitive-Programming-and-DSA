#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int, int> pii;
int32_t main(int32_t argc, char const* argv[]) {
#ifndef ONLINE_JUDGE

	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int test;
	cin >> test;
	for (int t = 1; t <= test; ++t) {
		cout << "Case #" << t << ": ";
		int cntA = 0,cntB = 0;
		int n;
		cin >> n;
		string s;
		cin >> s;
		for(int i=0;i<n;i++){
			if(s[i] == 'A'){
				cntA++;
			}else{
				cntB++;
			}
		}
		if(abs(cntA - cntB) == 1){
			cout << "Y" << "\n";
		}else{
			cout << "N" << "\n";
		}
		
	}
	return 0;
}