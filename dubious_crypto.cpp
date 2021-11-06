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
		int l,r,m;
		cin >> l >> r >> m;
		int minm = max(0LL,m + l - r);
		int maxm = m + r - l;
		bool flag = false;
		for(int i=l;i<=r && !flag;i++){
			int lowest = ((minm)/i) * i;
			if(lowest < minm || lowest == 0){
				lowest+=i;
			}
			if(lowest > maxm){
				continue;
			}else{
				flag = true;
				cout << i<<" ";
				int diff = lowest - m;
				if(diff < 0){
					cout<<l-diff<<" "<<l<<"\n";
				}else{
					cout<<l<<" "<<l+diff<<"\n";
				}
				
			}
		}
	}
	return 0;
}