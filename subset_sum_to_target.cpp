#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pr;
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,sum;
	cin>>n>>sum;
	int *arr = new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	bool **dp = new bool *[n+1];
	for(int i=0;i<=n;i++){
		dp[i] = new bool[sum+1]();
		dp[i][0] = true;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=sum && !dp[i][j];j++){
			if(arr[i-1] > j){
				dp[i][j] = dp[i-1][j];
			}else{
				dp[i][j] = (dp[i-1][j] | dp[i][j-arr[i-1]]);
			}
		}
	}
	if(dp[n][sum]){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	for(int i=0;i<=n;i++){
		delete []dp[i];
	}
	delete []dp;
	delete []arr;
	return 0;
}