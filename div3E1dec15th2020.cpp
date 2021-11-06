#include <bits/stdc++.h>
#define int long long
using namespace std;
void solveQuestion(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	int ans = 0;
	sort(arr.begin(),arr.end());
	for(int i=0;i<=(n-3);i++){
		auto it = lower_bound(arr.begin()+i+2,arr.end(),arr[i]+3);
		--it;
		int idx = it - arr.begin();
		int numBetween = idx - i - 1;
		int add = ((numBetween) * (numBetween+1))/2;
		ans += add;
	}
	cout<<ans<<'\n';
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