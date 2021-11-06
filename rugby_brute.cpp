#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
int dp[10][1024];
int dist(int x_co,int y_co,int sx,int sy){
	return abs(x_co - sx) + abs(y_co - sy);
}
int solveDp(int x,int y,int idx,int state,int n,vector<pii> &arr){
	if(idx == n){
		return 0;
	}
	if(dp[idx][state]!=-1){
		return dp[idx][state];
	}
	int ans = 1e10;
	for(int i=0;i<n;i++){
		if(state & (1 << i)){
			continue;
		}
		ans = min(ans,dist(x,y,arr[idx].first,arr[idx].second) + solveDp(x+1,y,idx+1,state | (1 << i),n,arr));
	}
	return dp[idx][state] = ans;
}
void solveQ(){
	int n;
	cin >> n;
	vector<pii> arr(n);
	int maxX = -500,minX = 500,sum = 0;
	for(int i=0;i<n;i++){
		cin >> arr[i].first >> arr[i].second;
		maxX = max(maxX,arr[i].first);
		minX = min(minX,arr[i].first);
		sum += arr[i].second;
	}
	int minY = (sum)/n;
	int maxY = (sum + (n-1))/n;
	int ans = 1e10;
	for(int y=minY;y<=maxY;y++){
		for(int x=minX-n;x<=maxX+n;x++){
			for(int i=0;i<n;i++){
				for(int j=0;j<(1<<n);j++){
					dp[i][j] = -1;
				}
			}
			int cost = solveDp(x,y,0,0,n,arr);
			ans = min(ans,cost);
		}
	}
	cout<<ans<<"\n";
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int test;
	cin>>test;
	for(int t=1;t<=test;++t){
		cout<<"Case #"<<t<<": ";
		solveQ();
	}
	return 0;
}