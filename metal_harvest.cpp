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
		int n,dur;
		cin >> n >> dur;
		vector<pii> arr(n);
		for(int i=0;i<n;i++){
			cin >> arr[i].first >> arr[i].second;
		}		
		sort(arr.begin(),arr.end());
		int ans = (ceil)((double)(arr[0].second - arr[0].first)/(double)dur);
		int fin = arr[0].first + ans * dur;
		for(int i=0;i<n;i++){
			if(arr[i].second <= fin){
				continue;
			}else if(arr[i].first < fin){
				arr[i].first = fin;
			}
			int req = (ceil)((double)(arr[i].second - arr[i].first)/(double)dur);
			fin = arr[i].first + req * dur;
			ans += req;
		}
		cout<<ans<<"\n";
	}
	return 0;
}