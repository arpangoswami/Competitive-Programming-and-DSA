#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test = 1;
	//cin>>test;
	while(test--){
		int m,n,sx,sy;
		cin >> m >> n >> sx >> sy;
		cout<<sx<<" "<<sy<<"\n";
		cout<<1<<" "<<sy<<"\n";
		for(int i=1;i<=m;){
			for(int j=1;j<=n;j++){
				if((i == 1 && j == sy) || (i == sx) && (j == sy)){
					continue;
				}
				cout<<i<<" "<<j<<"\n";
			}
			i++;
			if(i > m){
				break;
			}
			for(int j=n;j>=1;j--){
				if((i == 1 && j == sy) || (i == sx) && (j == sy)){
					continue;
				}
				cout<<i<<" "<<j<<"\n";
			}
			i++;
		}	
	}
	return 0;
}