#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int test;
	cin>>test;
	for(int t=1;t<=test;++t){
		int n,d;
		cin >> n >> d;
		vector<int> arr(n);
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		for(int i=n-1;i>=0;i--){
			d = (d/arr[i])*arr[i];
		}
		cout<<"Case #"<<t<<":"<<" "<<d<<"\n";
	}
	return 0;
}