#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int arr[3001][3001];
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test = 1;
	//cin>>test;
	while(test--){
		int n,m;
		cin >> n >> m;
		vector<int> *adj_list = new vector<int>[n+1]();
		memset(arr,0,sizeof(arr));
		for(int i=0;i<m;i++){
			int u,v;
			cin >> u >> v;
			adj_list[u].push_back(v);
			arr[u][v] = 1;
		}

		int ans = 0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i == j){
					continue;
				}
				int common = 0;
				for(int x:adj_list[i]){
					if(arr[x][j]){
						common++;
					}
				}
				ans+=(common*(common-1))/2;
			}
		}
		cout << ans << "\n";
		delete []adj_list;	
	}
	return 0;
}