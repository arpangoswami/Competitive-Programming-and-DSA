#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int test;
	cin>>test;
	for(int t=1;t<=test;++t){
		cout<<"Case #"<<t<<": ";
		int n,amt;
		cin >> n >> amt;
		vector<pii> arr(n);
		for(int i=0;i<n;i++){
			cin >> arr[i].first;
			arr[i].first = (ceil)((double)arr[i].first / (double)amt);
			arr[i].second = i+1;
		}
		sort(arr.begin(),arr.end());
		for(pii x:arr){
			cout<<x.second<<" ";
		}
		cout<<"\n";
	}
	return 0;
}