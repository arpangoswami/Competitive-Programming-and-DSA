#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int test;
	cin>>test;
	for(int t=1;t<=test;++t){
		int ans = 0;
		int n;
		cin>>n;
		vector<int> arr(n);
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		int maxm = -1e14;
		for(int i=0;i<n;i++){
			if(arr[i] > maxm){
				if(i == n-1){
					ans++;
				}
				else if(arr[i] > arr[i+1]){
					ans++;
				}
				maxm = arr[i];
			}
		}
		cout<<"Case #"<<t<<":"<<" "<<ans<<"\n";
	}
	return 0;
}