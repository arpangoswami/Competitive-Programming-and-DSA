#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		int n;
		cin >> n;
		vector<int> arr(n);
		for(int i=0;i<n;i++){
			cin >> arr[i];
		}
		sort(arr.begin(),arr.end());
		cout << arr.back()-arr[0]<<"\n";
	}
	return 0;
}