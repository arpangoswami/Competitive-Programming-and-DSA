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
		vector<int> arr(n);
		for(int i=0;i<n;i++){
			cin >> arr[i];
		}
		sort(arr.begin(),arr.end());
		int minm = 0;
		for(int i=0;i<n;i+=2){
			minm += abs(arr[i+1] - arr[i]);
		}
		int maxm = 0;
		for(int i=0;i<(n/2);i++){
			maxm += abs(arr[n-i-1] - arr[i]);
		}
		cout << minm <<" "<<maxm<<"\n";
	}
	return 0;
}