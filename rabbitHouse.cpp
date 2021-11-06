#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
int check(vector<vector<int>> &arr,int m,int n){
	int req = 0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(i > 0){
				if(arr[i][j] + 1 < arr[i-1][j]){
					req += arr[i-1][j] - arr[i][j] - 1;
					arr[i][j] = arr[i-1][j] - 1;
				}
			}
			if(j > 0){
				if(arr[i][j] + 1 < arr[i][j-1]){
					req += arr[i][j-1] - arr[i][j] - 1;
					arr[i][j] = arr[i][j-1] - 1;
				}
			}
		}
	}
	for(int i=m-1;i>=0;i--){
		for(int j=n-1;j>=0;j--){
			if(i < (m-1)){
				if(arr[i][j] + 1 < arr[i+1][j]){
					req += arr[i+1][j] - arr[i][j] - 1;
					arr[i][j] = arr[i+1][j] - 1;
				}
			}
			if(j < (n-1)){
				if(arr[i][j] + 1 < arr[i][j+1]){
					req += arr[i][j+1] - arr[i][j] - 1;
					arr[i][j] = arr[i][j+1] - 1;
				}
			}
		}
	}
	return req;
}
void solveQ(){
	int r,c;
	cin >> r >> c;
	vector<vector<int>> arr(r,vector<int>(c));
	//int maxm = 0;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cin >> arr[i][j];
			//maxm = max(maxm,arr[i][j]);
		}
	}
	cout << check(arr,r,c) << '\n';
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