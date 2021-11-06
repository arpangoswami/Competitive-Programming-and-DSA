#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	int maxm = 0;
	for(int x:arr){
		maxm = max(maxm,x);
	}
	int ans = -1;
	for(int i=0;i<n;i++){
		int left = (i == 0) ? 1e9 + 1 : arr[i-1];
		int right = (i == n-1) ? 1e9 + 1: arr[i+1];
		if(arr[i] == maxm && (arr[i] > left || arr[i] > right)){
			ans = i+1;
			break;
		}
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