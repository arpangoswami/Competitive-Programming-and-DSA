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
		int n;
		cin >> n;
		vector<int> arr(n);
		for(int i=0;i<n;i++){
			cin >> arr[i];
		}
		int maxAns = 2,currAns = 2,currDiff = arr[1] - arr[0];
		for(int i=2;i<n;i++){
			if((arr[i]-arr[i-1])!=currDiff){
				currAns = 2;
				currDiff = arr[i]-arr[i-1];
			}else{
				currAns++;
				maxAns = max(maxAns,currAns);
			}
		}
		cout<<maxAns<<"\n";
	}
	return 0;
}