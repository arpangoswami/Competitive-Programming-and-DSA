#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pr;
int rows[4] = {-1,0,0,1};
int cols[4] = {0,-1,1,0};
inline bool isSafe(int i,int j,int m,int n){
	return ((i>=0) && (j>=0) && (i<m) && (j<n));
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		int m,n;
		cin>>m>>n;
		vector<vector<int>> arr(m,vector<int>(n));
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				cin>>arr[i][j];
			}
		}
		bool flag = true;
		for(int i=0;i<m && flag;i++){
			for(int j=0;j<n && flag;j++){
				if(arr[i][j]!=0){
					int req = arr[i][j];
					int cnt = 0;
					for(int k=0;k<4;k++){
						if(isSafe(i+rows[k],j+cols[k],m,n)){
							cnt++;
						}
					}
					if(req > cnt){
						flag = false;
					}
				}
			}
		}
		if(!flag){
			cout<<"NO"<<"\n";
		}else{
			if(m == 1 || n == 1){
				if(m == 1 && n == 1){
					arr[0][0] = 1;
				}else if(n == 1){
					arr[0][0] = 1;
					for(int i=1;i<(m-1);i++){
						arr[i][0] = 2;
					}
					arr[m-1][0] = 1;
				}else if(m == 1){
					arr[0][0] = 1;
					for(int j=1;j<(n-1);j++){
						arr[0][j] = 2;
					}
					arr[0][n-1] = 1;
				}
			}else{
				arr[0][0] = 2;
				arr[0][n-1] = 2;
				arr[m-1][0] = 2;
				arr[m-1][n-1] = 2;
				for(int i=1;i<(m-1);i++){
					for(int j=1;j<(n-1);j++){
						arr[i][j] = 4;
					}
				}
				for(int j=1;j<(n-1);j++){
					arr[0][j] = 3;
					arr[m-1][j] = 3;
				}
				for(int i=1;i<(m-1);i++){
					arr[i][0] = 3;
					arr[i][n-1] = 3;
				}
			}
			cout<<"YES"<<"\n";
			for(int i=0;i<m;i++){
				for(int j=0;j<n;j++){
					cout<<arr[i][j]<<" ";
				}
				cout<<"\n";
			}
		}
	}
	return 0;
}