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
		int idx = 0;
		vector<int> arr(n);
		for(int i=0;i<n;i++){
			cin >> arr[i];
		}
		vector<int> rmax(n);
		rmax[n-1] = -1;
		for(int i=n-2;i>=0;i--){
			rmax[i] = max(rmax[i+1],arr[i+1]);
		}
		for(int i=1;i<n;i++){
			if(arr[i] < arr[i-1] && arr[i] < rmax[i]){
				idx = i;
			}
		}
		cout << idx <<"\n";
	}
	return 0;
}