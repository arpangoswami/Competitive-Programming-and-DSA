#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[200005][3];
ll solve(int i,int n,int state,int rem,vector<int> &arr){
	if(i > n){
		return INT_MIN;
	}
	if(i == n){
		return 0;
	}
	ll ans1 = INT_MIN,ans2 = INT_MIN;
	ans1 = arr[i] + solve(i+2,n,state,rem,arr);
	if(rem > 0 || state == 1){
		if(rem > 0)
			ans2 = arr[i] + solve(i+1,n,state^1,rem-1,arr);
		else
			ans2 = arr[i] + solve(i+1,n,state^1,rem,arr);
	}
	return dp[i][rem] = max(ans1,ans2);
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		vector<int> arr(n);
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		if(n%2 == 1){
			arr.push_back(0);
			n++;
		}
		ll max_sum = solve(0,n,0,1,arr);
		cout<<max_sum<<endl;
	}
	return 0;
}