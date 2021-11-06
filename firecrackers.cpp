#include <bits/stdc++.h>
#define int long long
using namespace std;
void solveQuestion(){
	int n,m,a,b;
	cin >> n >> m >> a >> b;
	vector<int> arr(m);
	for(int i=0;i<m;i++){
		cin >> arr[i];
	}
	sort(arr.begin(),arr.end());
	int ans = 0;
	int diff = abs(a-b) - 1;
	int totalTimeToCatch = ((a < b) ? (b-1) : (n-b)) - 1;
	int intital = totalTimeToCatch - diff;
	for(int i=0;i<m;i++){
		intital = max(intital + 1,arr[i]);
		if(intital > totalTimeToCatch){
			break;
		}
		ans++;
	}
	cout<<ans<<'\n';
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}