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
		vector<int> arr(n);
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		sort(arr.begin(),arr.end());
		int ans = arr[1] - arr[0];
		for(int i=2;i<n;i++){
			ans = min(ans,arr[i]-arr[i-1]);
		}
		cout<<ans<<"\n";
	}
	return 0;
}