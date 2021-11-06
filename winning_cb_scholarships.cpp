#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
bool check(int mid,int n,int m,int x,int y){
	int req = mid*x;
	int have = m + (n-mid)*y;
	return req <= have;
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m,x,y;
	cin >> n >> m >> x >> y;
	int low = 0,high = n;
	int ans = 0;
	while(low <= high){
		int mid = (low + high)/2;
		if(check(mid,n,m,x,y)){
			ans = mid;
			low = mid+1;
		}else{
			high = mid-1;
		}
	}
	cout << ans << "\n";
	return 0;
}