#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int calSum(vector<int> &pref,int l,int r){
	int ans = pref[r];
	if(l > 0){
		ans -= pref[l-1];
	}
	return ans;
}
void solveQuestion(){
	int n,q,k;
	cin >> n >> q >> k;
	vi arr(n);
	for(int &i:arr){
		cin >> i;
	}
	vi prefLeft(n);
	vi prefRight(n);
	for(int i=1;i<n;i++){
		prefLeft[i] = (arr[i] - arr[i-1] - 1);
	}
	for(int i=1;i<n;i++){
		prefLeft[i] += prefLeft[i-1];
	}
	for(int i=0;i<(n-1);i++){
		prefRight[i] += (arr[i+1] - arr[i] - 1);
	}
	for(int i=1;i<n;i++){
		prefRight[i] += prefRight[i-1];
	}
	while(q--){
		int left,right;
		cin >> left >> right;
		if(left == right){
			cout<<(k-1)<<'\n';
			continue;
		}
		left--;
		right--;
		int ans = calSum(prefLeft,left+1,right);
		ans += calSum(prefRight,left,right-1);
		ans += (arr[left]-1);
		ans += (k - arr[right]);
		cout<<ans<<'\n';
	}
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test = 1;
	//cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}