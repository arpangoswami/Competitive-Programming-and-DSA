#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	vector<pii> arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i].first;
	}
	for(int i=0;i<n;i++){
		cin >> arr[i].second;
	}
	sort(arr.begin(),arr.end());
	vector<int> sums(n);
	sums[0] = arr[0].second;
	for(int i=1;i<n;i++){
		sums[i] = arr[i].second + sums[i-1];
	}
	int ans = arr[n-1].first;
	for(int i=0;i<n;i++){
		int courier = (i == 0) ? 0 : arr[i-1].first;
		int self = (i == 0) ? sums[n-1] : sums[n-1] - sums[i-1];
		ans = min(ans,max(courier,self));
	}
	cout<<ans<<"\n";
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}