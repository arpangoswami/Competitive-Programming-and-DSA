#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	vector<int> arr(n+1);
	for(int i=1;i<=n;i++){
		cin >> arr[i];
	}
	int ans = 0;
	for(int i=2;i<=n;i++){
		ans += abs(arr[i] - arr[i-1]);
	}
	int mx = max(abs(arr[1]-arr[2]),abs(arr[n] - arr[n-1]));
	for(int i=2;i<n;i++){
		mx = max(mx,abs(arr[i] - arr[i-1]) + abs(arr[i+1] - arr[i]) - abs(arr[i+1] - arr[i-1]));
	}
	cout<<ans - mx<<'\n';
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