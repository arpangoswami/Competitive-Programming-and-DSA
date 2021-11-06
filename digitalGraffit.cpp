#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
void solveQuestion(){
	int h,w;
	cin >> h >> w;
	vector<string> grid(h);
	for(string &x:grid){
		cin >> x;
	}
	vector<vector<int>> mp(h,vector<int>(w));
	for(int i=1;i<(h-1);i++){
		for(int j=1;j<(w-1);j++){
			for(int k=0;k<4;k++){
				if(grid[i+dx[k]][j+dy[k]] == '.'){
					mp[i][j]++;
				}
			}
		}
	}
	int maxm = 0;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			maxm = max(maxm,mp[i][j]);
		}
	}
	int ans = 0;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(mp[i][j] == maxm){
				ans++;
			}
		}
	}
	cout<<ans;
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test = 1;
	//cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}