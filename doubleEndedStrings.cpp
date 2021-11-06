#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
string s,t;
int dp[21][21][21][21];
int solve(int i1,int j1,int i2,int j2){
	//cout << "i1: "<<i1<<" j1: "<<j1<<" i2: "<<i2<<" j2: "<<j2<<'\n';
	if(i1 > j1){
		return (j2 - i2 + 1);
	}
	if(i2 > j2){
		return (j1 - i1 + 1);
	}
	if(dp[i1][j1][i2][j2] != -1){
		return dp[i1][j1][i2][j2];
	}
	int &ans = dp[i1][j1][i2][j2];
	if(s.substr(i1,j1-i1+1) == t.substr(i2,j2-i2+1)){
		return ans = 0;
	}
	return ans = 1 + min({solve(i1+1,j1,i2,j2),solve(i1,j1-1,i2,j2),solve(i1,j1,i2+1,j2),solve(i1,j1,i2,j2-1)});
}
void solveQuestion(){
	cin >> s >> t;
	int n1 = s.size(),n2 = t.size();
	for(int i=0;i<=n1;i++){
		for(int j=0;j<=n1;j++){
			for(int k=0;k<=n2;k++){
				for(int l=0;l<=n2;l++){
					dp[i][j][k][l] = -1;
				}
			}
		}
	}
	//cout << "s.substr(4,5): "<<s.substr(4,5-4+1)<<" t.substr()"
	cout << solve(0,n1-1,0,n2-1) << '\n';
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}