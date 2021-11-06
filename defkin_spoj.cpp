#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	int x_co[40005],y_co[40005];
	while(test--){
		int width,height,n;
		cin >> width >> height >> n;
		if(n == 0){
			cout << width * height <<"\n";
			continue;
		}
		for(int i=0;i<n;i++){
			cin >> x_co[i] >> y_co[i];
		}
		sort(x_co,x_co+n);
		sort(y_co,y_co+n);
		int maxLen = x_co[0]-1,maxHt = y_co[0]-1;
		for(int i=1;i<n;i++){
			maxLen = max(maxLen,x_co[i]-x_co[i-1]-1);
			maxHt = max(maxHt,y_co[i]-y_co[i-1]-1);
		}
		maxLen = max(maxLen,width-x_co[n-1]);
		maxHt = max(maxHt,height-y_co[n-1]);
		cout << (maxLen * maxHt) <<"\n";
	}
	return 0;
}