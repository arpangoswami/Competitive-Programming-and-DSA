#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pr;
const ll mod = 1e9+7;
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,x;
	cin>>n>>x;
	vector<int> coins(n);
	for(int i=0;i<n;i++){
		cin>>coins[i];
	}
	vector<vector<ll>> arr(2,vector<ll>(x+1,0));
	arr[0][0] = 1; 
	for(int i=0;i<n;i++){
		int curr_row = 1 - i%2;
		int prev_row = 1 - curr_row;
		arr[curr_row][0] = 1;
		for(int j=1;j<=x;j++){
			arr[curr_row][j] = arr[prev_row][j];
			if(j >= coins[i]){
				arr[curr_row][j] += arr[curr_row][j - coins[i]];
				arr[curr_row][j]%=mod;
			}
		}
	}
	cout<<arr[n%2][x]<<endl;
	return 0;
}