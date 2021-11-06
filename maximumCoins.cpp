#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
void solveQ(){
	int n;
	cin >> n;
	vector<vector<int>> mat(n,vector<int>(n));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> mat[i][j];
		}
	}
	int ans = 0;
	for(int len = n;len>=1;len--){
		int row = 0,col = n-len;
		int cd = 0;
		while(col<n){
			cd += mat[row][col];
			row++;
			col++;
		}
		ans = max(ans,cd);
	}
	for(int len = n-1;len>=1;len--){
		int col = 0,row = n-len;
		int cd = 0;
		while(row<n){
			cd += mat[row][col];
			row++;
			col++;
		}
		ans = max(ans,cd);
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