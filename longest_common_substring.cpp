#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		int m,n;
		cin>>m>>n;
		string a,b;
		cin>>a>>b;
		int **dp = new int[m+1];
		for(int i=0;i<=m;i++){
			dp[i] = new int[n+1]();
		}
		int maxm = 0;
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				if(a[i-1] == b[j-1]){
					dp[i][j] = dp[i-1][j-1] + 1;
					maxm = max(dp[i][j],maxm);
				}
			}
		}
		cout<<maxm<<endl;
		for(int i=0;i<=m;i++){
			delete []dp[i];
		}
		delete []dp;
	}
	return 0;
}