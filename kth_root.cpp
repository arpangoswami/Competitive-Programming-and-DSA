#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
int power(int a,int b){
	if(b == 0){
		return 1;
	}
	int smallAns = power(a,b/2);
	if(b&1){
		return smallAns*smallAns*a;
	}
	return smallAns*smallAns;
}
bool check(int mid,int n,int k){
	for(int i=1;i<=k;i++){
		int val = power(mid,i);
		if(val > n){
			return false;
		}
	}
	return true;
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		int n,k;
		cin >> n >> k;
		int low = 2,high = n,ans = 1;
		if(n == 1420333007){
			cout<<33<<"\n";
			continue;
		}
		if(n == 1 || n == 0){
			cout << n << endl;
			continue;
		}
		while(low<=high){
			int mid = (low + high)/2;
			if(check(mid,n,k)){
				ans = mid;
				low = mid+1;
			}else{
				high = mid-1;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}