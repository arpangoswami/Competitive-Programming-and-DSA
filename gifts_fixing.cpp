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
		vector<int> candies(n);
		vector<int> orange(n);
		int ops = 0;
		int minCandy = 1e10,minOrange = 1e10;
		for(int i=0;i<n;i++){
			cin >> candies[i];
			minCandy = min(minCandy,candies[i]);
		}
		for(int i=0;i<n;i++){
			cin >> orange[i];
			minOrange = min(minOrange,orange[i]);
		}
		for(int i=0;i<n;i++){
			if(candies[i] > minCandy || orange[i] > minOrange){
				int common = min(candies[i]-minCandy,orange[i]-minOrange);
				ops += common;
				orange[i]-=common;
				candies[i]-=common;
				if(orange[i] == minOrange){
					ops+=(candies[i]-minCandy);
				}else{
					ops+=(orange[i]-minOrange);
				}
			}
		}
		cout << ops << "\n";
	}
	return 0;
}