#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	vi arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	sort(arr.begin(),arr.end(),greater<int>());
	int ans = arr[0],pref = arr[0];
	for(int i=1;i<n;i++){
		int temp = pref & arr[i];
		ans += temp;
		pref &= arr[i];
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