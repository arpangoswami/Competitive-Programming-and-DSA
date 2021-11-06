#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
#define ff first
#define ss second
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void print(vector<int> &arr){
	int n = arr.size();
	for(int i=0;i<(n-1);i++){
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
}
void solveQuestion(){
	int n,k,s;
	cin >> n >> k >> s;
	vi arr(n+1);
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	vi pref(n+1);
	vector<int> kSteps(n+1);
	pref[0] = arr[0];
	kSteps[0] = 0;
	for(int i=1;i<=n;i++){
		pref[i] = pref[i-1] + arr[i];
		kSteps[i] = i;
	}
	vector<int> rightMost(n+1);
	for(int i=0;i<=n;i++){
		rightMost[i] = upper_bound(pref.begin(),pref.end(),pref[i]+s-arr[i]) - pref.begin();
		if(rightMost[i] > n){
			rightMost[i]--;
		}
	}
	int ans = 1;
	//print(rightMost);
	for(int bit=0;bit<20;bit++){
		if((1 << bit) > k){
			break;
		}
		if((k >> bit) & 1){
			for(int i=0;i<n;i++){
				kSteps[i] = rightMost[kSteps[i]];
			}
		}
		for(int i=0;i<n;i++){
			rightMost[i] = rightMost[rightMost[i]];
		}
		//print(rightMost);
	}
	for(int i=0;i<n;i++){
		ans = max(ans,kSteps[i]-i);
	}
	cout<<ans<<"\n";
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	int tt = 1;
	cin >> tt;
	while(tt-- > 0){
		solveQuestion();
	}
	return 0;
}