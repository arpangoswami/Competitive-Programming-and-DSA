#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		int n;
		cin >> n;
		int cost[n];
		int litres[n];
		for(int i=0;i<n;i++){
			cin >> cost[i];
		}
		for(int i=0;i<n;i++){
			cin >> litres[i];
		}
		int min_encountered = 1e9;
		int ans = 0;
		for(int i=0;i<n;i++){
			if(cost[i] >= min_encountered){
				ans += (min_encountered * litres[i]);
			}else if(cost[i] < min_encountered){
				min_encountered = cost[i];
				ans += (min_encountered * litres[i]);
			}
		}
		cout << ans <<"\n";
	}
	return 0;
}