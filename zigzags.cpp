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
		arr[i]--;
	}
	vector<int> mp(n*n);
	int ans = 0;
	for(int j=n-1;j>=0;j--){
		int k = j+1;
		for(int l=k+1;l<n;l++){
			mp[arr[k]*n + arr[l]]++;
		}
		for(int i=0;i<j;i++){
			ans += mp[arr[i]*n + arr[j]];
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