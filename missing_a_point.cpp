#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1e10;
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		map<int,int> x_co;
		map<int,int> y_co;
		int total = 4*n - 1;
		for(int i=0;i<total;i++){
			int x,y;
			cin>>x>>y;
			x_co[x]++;
			y_co[y]++;
		}
		int ans_x = inf,ans_y = inf;
		for(auto it = x_co.begin();it!=x_co.end();++it){
			int item = it->first,freq = it->second;
			if(freq % 2 != 0){
				ans_x = item;
				break;
			}
		}
		for(auto it = y_co.begin();it!=y_co.end();++it){
			int item = it->first,freq = it->second;
			if(freq % 2 != 0){
				ans_y = item;
				break;
			}
		}
		cout<<ans_x<<" "<<ans_y<<"\n";
	}
	return 0;
}