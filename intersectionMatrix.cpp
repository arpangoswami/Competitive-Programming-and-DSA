#pragma GCC optimize(2)
#pragma GCC optimize(3)   
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#include<cstdlib>
#define int long long
#define ff first
#define ss second
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n,m,b;
	cin >> n >> m >> b;
	int ans = 0;
	vector<vector<int>> mat(n,vector<int>(m));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> mat[i][j];
		}
	}
	for(int i=1;i<(1<<n);i++){
		for(int j=1;j<(1<<m);j++){
			vector<int> rows;
			vector<int> cols;
			for(int k=0;k<n;k++){
				if((i>>k)&1){
					rows.push_back(k);
				}
			}
			for(int k=0;k<m;k++){
				if((j>>k)&1){
					cols.push_back(k);
				}
			}
			int sum = 0;
			
			// cout<<"i: "<<i<<" j: "<<j<<" rows: ";
			// for(int x:rows){
			// 	cout<<x<<" ";
			// }
			// cout<<"cols: ";
			// for(int x:cols){
			// 	cout<<x<<" ";
			// }
			for(int k=0;k<rows.size();k++){
				for(int l=0;l<cols.size();l++){
					sum += mat[rows[k]][cols[l]];
					//cout<<" k: "<<k<<" l: "<<l<<" mat[k][l]:"<<mat[k][l]<<" ";
				}
			}
			// cout<<" sum: "<<sum<<" ";
			// cout<<'\n';

			if(sum == b){
				ans++;
				
			}
		}
	}
	cout << ans << '\n';
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test = 1;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}