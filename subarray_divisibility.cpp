#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	map<int,int> mp;
	mp[0]++;
	int arr[n];
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	int pref = 0;
	int ans = 0;
	for(int i=0;i<n;i++){
		pref += arr[i];
		pref = (pref % n + n)%n;
		ans += mp[pref];
		mp[pref]++;
	}
	cout<<ans<<"\n";
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