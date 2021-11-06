#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
ll power(ll a,ll b){
	if(b == 0){
		return 1;
	}
	ll smallAns = power(a,b/2);
	if(b&1){
		return smallAns*smallAns*a;
	}
	return smallAns*smallAns;
}
inline bool isSafe(int i,int j,vector<vector<int>> &matrix,vector<vector<bool>> &visited,int n){
	return ((i>=0) && (j>=0) && (i<n) && (j<n) && matrix[i][j] == 0 && !visited[i][j]);
}
ll dfs(vector<vector<int>> &matrix,vector<vector<bool>> &visited,int i,int j,int n){
	visited[i][j] = true;
	if(i == n-1 && j == n-1){
		visited[i][j] = false;
		return 1;
	}
	ll ans = 0;
	for(int x=0;x<4;x++){
		if(isSafe(i+dx[x],j+dy[x],matrix,visited,n)){
			ans+=dfs(matrix,visited,i+dx[x],j+dy[x],n);
		}
	}
	visited[i][j] = false;
	return ans;
}
void solve(){
	int n;
	cin>>n;
	vector<vector<int>> matrix(n,vector<int>(n));
	vector<vector<bool>> visited(n,vector<bool>(n,false));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>matrix[i][j];
		}
	}
	if(matrix[0][0] == 1 || matrix[n-1][n-1] == 1){
		cout<<0<<endl;
		return;
	}
	cout<<dfs(matrix,visited,0,0,n)<<endl;
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		solve();
	}
	return 0;
}