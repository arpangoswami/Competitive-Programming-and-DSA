#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int dp[100005][2][2];
int solve(int idx,vector<int> &arr,int secondlast,int last){
	if(idx == arr.size()){
		return 0;
	}
	if(dp[idx][secondlast][last]!=-1){
		return dp[idx][secondlast][last];
	}
	int &ans = dp[idx][secondlast][last];
	ans = 1e12;
	if(secondlast == 0 && last == 0){
		ans = solve(idx+1,arr,last,1) + arr[idx];
	}
	else{
		ans = min(solve(idx+1,arr,last,1) + arr[idx],solve(idx+1,arr,last,0));
	}
	return ans;
}
void solveQuestion(){
	int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=1;j++){
            for(int k=0;k<=1;k++){
                dp[i][j][k] = -1;
            }
        }
    }
    if(n == 1){
    	cout<<arr[0]<<"\n";
    	return;
    }
    if(n == 2){
    	cout<<min(arr[0],arr[1])<<"\n";
    	return;
    }
    int ans = arr[0] + solve(2,arr,1,0);
    ans = min(ans,arr[1] + solve(2,arr,0,1));
    ans = min(ans,solve(2,arr,0,0));
    cout<<ans<<"\n";
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}