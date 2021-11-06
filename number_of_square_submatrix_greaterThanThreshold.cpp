#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(int argc,char const* argv[]){
	int n,m;
	ll thresh;
	cin>>n>>m>>thresh;
	vector<vector<ll>> input(n+1,vector<ll>(m+1,0));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>input[i][j];
		}
	}
	vector<vector<ll>> prefix(n+1,vector<ll>(m+1,0));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			ll add1 = prefix[i-1][j],add2 = prefix[i][j-1],add3 = input[i-1][j-1];
			ll sub1 = prefix[i-1][j-1];
			prefix[i][j] = add1 + add2 + add3 - sub1;
		}
	}
	ll ans = 0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int max_d = min(i,j);
			for(int k=1;k<=max_d;k++){
				ll sub1 = prefix[i][j-k],sub2 = prefix[i-k][j],add1 = prefix[i-k][j-k],add2 = prefix[i][j];
				ll sum = add1 + add2 - sub1 - sub2;
				if(sum>=thresh){
					ans+=(max_d - k + 1);
					break;				
				}
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}