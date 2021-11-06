#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		vector<string> grid(n);
		for(int i=0;i<n;i++){
			cin>>grid[i];
		}
		bool flag = true;
		for(int i=0;i<(n-1);i++){
			for(int j=0;j<(n-1);j++){
				if(grid[i][j] == '1'){
					if(grid[i+1][j] == '0' && grid[i][j+1] == '0'){
						flag = false;
						break;
					}
				}
			}
			if(!flag){
				break;
			}
		}
		if(flag){
			cout<<"YES"<<"\n";
		}
		else{
			cout<<"NO"<<"\n";
		}
	}
	return 0;
}