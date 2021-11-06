#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	vector<int> arr(n);
	int sum = 0,maxm = 0;
	for(int i=0;i<n;i++){
		cin >> arr[i];
		maxm = max(maxm,arr[i]);
		sum += arr[i];
	}
	int g = maxm - arr[0];
	for(int i=1;i<n;i++){
		g = __gcd(g,maxm - arr[i]);
	}
	int ans = (maxm*n - sum)/g;
	cout<<ans<<" "<<g;
	
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test = 1;
	//cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}