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
		int m,n;
		cin >> m >> n;
		vector<string> belt(m);
		for(int i=0;i<m;i++){
			cin >> belt[i];
		}
		int ans = 0;
		for(int i=0;i<(m-1);i++){
			if(belt[i][n-1] == 'R'){
				ans++;
			}
		}
		for(int j=0;j<(n-1);j++){
			if(belt[m-1][j] == 'D'){
				ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}