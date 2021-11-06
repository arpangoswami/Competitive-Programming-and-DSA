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
		string s;
		cin >> s;
		int period = 0;
		vector<int> ones;
		for(char c:s){
			if(c == '1'){
				period++;
			}else{
				if(period > 0){
					ones.push_back(period);
					period = 0;
				}
			}
		}
		if(period > 0){
			ones.push_back(period);
		}
		sort(ones.begin(),ones.end(),greater<int>());
		int ans = 0;
		for(int i=0;i<ones.size();i+=2){
			ans += ones[i];
		}
		cout<<ans<<"\n";
	}
	return 0;
}