#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int dp[201][201][201];
int solve(int r,int g,int b,vector<int> &red,vector<int> &green,vector<int> &blue){
	if(dp[r][g][b]!=-1){
		return dp[r][g][b];
	}
	int &ans = dp[r][g][b];
	ans = 0;
	if(r>0 && g>0){
		ans = max(ans,red[r-1]*green[g-1] + solve(r-1,g-1,b,red,green,blue));
	}
	if(r>0 && b >0){
		ans = max(ans,red[r-1]*blue[b-1] + solve(r-1,g,b-1,red,green,blue));
	}
	if(g>0 && b>0){
		ans = max(ans,green[g-1]*blue[b-1] + solve(r,g-1,b-1,red,green,blue));
	}
	return ans;
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int r,g,b;
	cin >> r >> g >> b;
	vector<int> red(r),green(g),blue(b);
	for(int i=0;i<r;i++){
		cin >> red[i];
	}
	for(int i=0;i<g;i++){
		cin >> green[i];
	}
	for(int i=0;i<b;i++){
		cin >> blue[i];
	}
	sort(red.begin(),red.end());
	sort(green.begin(),green.end());
	sort(blue.begin(),blue.end());
	memset(dp,-1,sizeof(dp));
	int ans = solve(r,g,b,red,green,blue);
	cout<<ans<<"\n";
	return 0;
}