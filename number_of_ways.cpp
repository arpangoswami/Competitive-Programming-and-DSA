#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
string a,b,c;
int len1,len2,len3;
int dp[305][305][305];
int solve(int i,int j,int k){
	if(k == len3){
		return dp[i][j][k] = 1;
	}
	else if(i == len1 && j == len2){
		return dp[i][j][k] = 0;
	}
	if(dp[i][j][k]!=-1){
		return dp[i][j][k];
	}
	
	if(i == len1){
		int ans = 0;
		if(b[j] == c[k]){
			ans += solve(i,j+1,k+1);
		}
		ans += solve(i,j+1,k);
		dp[i][j][k] = ans;
	}else if(j == len2){
		int ans = 0;
		if(a[i] == c[k]){
			ans += solve(i+1,j,k+1);
		}
		ans += solve(i+1,j,k);
		dp[i][j][k] = ans;
	}else{
		int ans = 0;
		if(a[i] == b[j] && a[i] == c[k]){
			ans += solve(i+1,j,k+1);
			ans += solve(i+1,j+1,k+1);
			ans += solve(i,j+1,k+1);
		}else if(a[i] == c[k]){
			ans += solve(i+1,j+1,k+1);
			ans += solve(i+1,j,k+1);
		}else if(b[j] == c[k]){
			ans += solve(i+1,j+1,k+1);
			ans += solve(i,j+1,k+1);
		}
		ans += solve(i+1,j,k);
		ans += solve(i,j+1,k);
		ans += solve(i+1,j+1,k);
		dp[i][j][k] = ans;
	}
	return dp[i][j][k];
}
void solveQuestion(){
	cin >> a >> b >> c;
	len1 = a.size();
	len2 = b.size();
	len3 = c.size();
	memset(dp,-1,sizeof(dp));
	//int ans = solve(0,0,0);
	//cout<<ans<<"\n";
	cout<<a<<" "<<b<<" "<<c<<"\n";
	cout<<len1<<" "<<len2<<" "<<len3<<"\n";
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test = 1;
	//cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}