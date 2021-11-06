#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
int dp[10005][4];
int solve(int idx,int last,vector<int> &arr,int note){
	if(idx == arr.size()){
		return 0;
	}
	if(dp[idx][note]!=-1){
		return dp[idx][note];
	}
	int ans = 1e5;
	for(int i=0;i<4;i++){
		int cd = solve(idx+1,arr[idx],arr,i);
		if(arr[idx] > last){
			if(i > note){
				ans = min(ans,cd);
			}else{
				ans = min(ans,1 + cd);
			}
		}else if(arr[idx] < last){
			if(i < note){
				ans = min(ans,cd);
			}else{
				ans = min(ans,1 + cd);
			}
		}else if(arr[idx] == last){
			if(i == note){
				ans = min(ans,cd);
			}else{
				ans = min(ans,1 + cd);
			}
		}
	}
	return dp[idx][note] = ans;
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int test;
	cin>>test;
	for(int t=1;t<=test;++t){
		int n;
		cin>>n;
		vector<int> arr(n);
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		int ans = n+1;

		//wlog A < B < C < D
		memset(dp,-1,sizeof(dp));
		for(int i=0;i<=3;i++){
			ans = min(ans,solve(1,arr[0],arr,i));
		}
		cout<<"Case #"<<t<<": "<<ans<<"\n";
	}
	return 0;
}