/*
3
3 3
.*.
**.
...
2 4
.**.
**..
4 5
.**..
*...*
*.*..
..**.
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int m,n;
	cin >> m >> n;
	vector<string> grid(m);
	for(int i=0;i<m;i++){
		cin >> grid[i];
	}
	vector<vector<char>> first(m,vector<char>(n,'.'));
	
	for(int i=0;i<m;i++){
		if(i % 2 == 0){
			for(int j=0;j<n;j+=2){
				first[i][j] = '*';
			}
		}else{
			for(int j=1;j<n;j+=2){
				first[i][j] = '*';
			}
		}
	}
	int ans = 0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(first[i][j] != grid[i][j]){
				ans++;
			}
			//cout<<first[i][j];
		}
		//cout<<'\n';
	}
	if((m*n) % 2){
		cout<<ans<<'\n';
		return;
	}
	vector<vector<char>> second(m,vector<char>(n,'.'));
	for(int i=0;i<m;i++){
		if(i % 2){
			for(int j=0;j<n;j+=2){
				second[i][j] = '*';
			}
		}else{
			for(int j=1;j<n;j+=2){
				second[i][j] = '*';
			}
		}
	}
	
	
	int curr = 0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(second[i][j] != grid[i][j]){
				curr++;
			}
			//cout<<second[i][j];
		}
		//cout<<'\n';
	}
	cout<<min(ans,curr)<<'\n';
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