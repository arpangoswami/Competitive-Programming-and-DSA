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
		string s;
		cin>>s;
		n = s.size();
		int cnt0 = 0,cnt1 = 0;
		vector<int> prefix0(n,0);
		vector<int> prefix1(n,0);
		for(int i=0;i<n;i++){
			if(s[i] == '0'){
				prefix0[i]++;
			}else{
				prefix1[i]++;
			}
		}
		for(int i=1;i<n;i++){
			prefix1[i]+=prefix1[i-1];
			prefix0[i]+=prefix0[i-1];
		}
		int ans = n;
		for(int i=0;i<n;i++){
			int one_later;
			int one_first;
			int zero_later;
			int zero_first;
			if(i == 0){
				one_later = prefix1.back();
				zero_later = prefix0.back();
				one_first = 0;
				zero_first = 0;
			}else{
				one_later = prefix1.back()-prefix1[i-1];
				one_first = prefix1[i-1];
				zero_later = prefix0.back()-prefix0[i-1];
				zero_first = prefix0[i-1];
			}
			//000.....1111....
			ans = min(ans,one_first + zero_later);
			//111.....0000....
			ans = min(ans,zero_first + one_later);
		}
		cout<<ans<<"\n";
	}
	return 0;
}