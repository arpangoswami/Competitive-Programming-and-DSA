#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	vector<vector<int>> arr(n,vector<int>(n,100));
	int wins = (n-1)/2,loss = (n-1)/2,ties = (n % 2) ? 0 : 1;
	for(int i=0;i<n;i++){
		int ptr = (i+1)%n;
		for(int k=0;k<wins;k++){
			arr[i][ptr] = 1;
			ptr++;
			ptr %= n;
		}
		if(ties){
			arr[i][ptr] = 0;
			ptr++;
			ptr %= n;
		}
		for(int k=0;k<loss;k++){
			arr[i][ptr] = -1;
			ptr++;
			ptr %= n;
		}
	}
	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<n;j++){
	// 		cout<<arr[i][j]<<" ";
	// 	}
	// 	cout<<'\n';
	// }
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			cout<<arr[i][j]<<" ";
		}
	}
	cout<<'\n';
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