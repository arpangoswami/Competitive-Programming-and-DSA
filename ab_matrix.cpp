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
		int n,m,a,b;
		cin>>n>>m>>a>>b;
		if((n*a)!=(m*b)){
			cout<<"NO"<<endl;
			continue;
		}
		vector<vector<int>>grid(n,vector<int>(m,0));
		int shift = 0;
		for(int i=1;i<m;i++){
			if((i * n) % m == 0){
				shift = i;
				break;
			}
		}
		int start = 0;
		for(int i=0;i<n;i++){
			for(int j=0;j<a;j++){
				grid[i][(start+j)%m] = 1;
			}
			start += shift;
			start %= m;
		}
		cout<<"YES"<<'\n';
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cout<<grid[i][j];
			}
			cout<<'\n';
		}
	}
	return 0;
}