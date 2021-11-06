#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	while(true){
		int n;
		cin>>n;
		if(n == 0){
			break;
		}
		vector<ll> arr(n);
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		sort(arr.begin(),arr.end());
		int ans = 0;
		for(int i=0;i<(n-2);i++){
			for(int j=n-1;j>(i+1);j--){
				int min_req = arr[j]-arr[i];
				int pos = lower_bound(arr.begin(),arr.end(),min_req) - arr.begin();
				//cout<<"min_req: "<<min_req<<" pos: "<<pos<<endl;
				int r = pos-1;
				int l = i+1;
				if((r-l+1)>0){
					ans+=(r-l+1);
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}