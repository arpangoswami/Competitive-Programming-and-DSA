#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int dp[2005][2005];
int editDistance(string &a,string &b,int i,int j,int m,int n){
	if(dp[i][j]!=-1){
		return dp[i][j];
	}
	if(i == m || j == n){
		return max(m-i,n-j);
	}
	if(a[i] == b[j]){
		return dp[i][j] = editDistance(a,b,i+1,j+1,m,n);
	}
	return dp[i][j] = 1 + min({editDistance(a,b,i+1,j+1,m,n),editDistance(a,b,i+1,j,m,n),editDistance(a,b,i,j+1,m,n)});
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		string a,b;
		cin>>a>>b;
		int m = a.size(),n = b.size();
		memset(dp,-1,sizeof(dp));
		cout<<editDistance(a,b,0,0,m,n)<<endl;
	}
	return 0;
}