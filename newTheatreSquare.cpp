#include <bits/stdc++.h>
#define int long long
using namespace std;
void solveQuestion(){
	int n,m,x,y;
	cin >> n >> m >> x >> y;
	vector<vector<char>> grid(n,vector<char>(m));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> grid[i][j];
		}
	}
	if(2 * x <= y){
		int single = 0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(grid[i][j] != '*'){
					single++;
				}
			}
		}
		cout<<single*x<<'\n';
	}else{
		int single = 0,doub = 0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;){
				if(grid[i][j] == '.'){
					if(j < (m-1) && grid[i][j+1] == '.'){
						doub++;
						j+=2;
					}else{
						single++;
						j++;
					}
				}else{
					j++;
				}
			}
		}
		cout<<single*x + doub*y<<'\n';
	}
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