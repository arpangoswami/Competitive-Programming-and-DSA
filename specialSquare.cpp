#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
void solveQuestion(){
	int m,n;
	cin >> m >> n;
	vector<vector<int>> arr(m,vector<int>(n));
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin >> arr[i][j];
		}
	}
	bool f = false;
	for(int i=0;i<(m-1);i++){
		for(int j=0;j<(n-1);j++){
			int val = arr[i][j];
			if(arr[i+1][j] == val && arr[i][j+1] == val && arr[i+1][j+1] == val){
				cout<<"YES"<<'\n';
				return;
			}
		}
	}
	cout<<"NO"<<'\n';
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