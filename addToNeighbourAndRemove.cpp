#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
bool possible(int sum,int n,vector<int> &arr){
	int curr = 0;
	for(int i=0;i<n;i++){
		curr += arr[i];
		if(curr > sum){
			return false;
		}else if(curr == sum){
			curr = 0;
		}
	}
	return curr == 0;
}

void solveQuestion(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	vector<int> prefix(n);
	prefix[0] = arr[0];
	for(int i=1;i<n;i++){
		prefix[i] = arr[i] + prefix[i-1];
	}
	int ans = (n-1);
	for(int i=0;i<n;i++){
		bool f = possible(prefix[i],n,arr);
		if(f){
			int sz = (prefix.back() / prefix[i]);
			ans = min(ans,n - sz);
		}
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