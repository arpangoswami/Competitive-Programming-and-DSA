#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int m,n;
	cin >> m >> n;
	int x,y;
	cin >> x >> y;
	x--;
	y--;
	vector<string> grid(m);
	for(int i=0;i<m;i++){
		cin >> grid[i];
	}
	int ans = 1;
	int i=x-1;
	while(i >= 0 && grid[i][y] != '#'){
		ans++;
		i--;
	}
	i = x+1;
	while(i < m && grid[i][y] != '#'){
		ans++;
		i++;
	}
	int j = y-1;
	while(j >= 0 && grid[x][j] != '#'){
		ans++;
		j--;
	}
	j = y+1;
	while(j < n && grid[x][j] != '#'){
		ans++;
		j++;
	}
	if(grid[x][y] == '#'){
		cout << 0;
		return;
	}
	cout << ans;
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