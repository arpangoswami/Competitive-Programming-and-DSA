#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int power(int x,int n){
	if(n == 0){
		return 1;
	}
	int sm = power(x,n/2);
	if(n%2 == 0){
		return sm*sm;
	}
	return sm*sm*x;
}
int check(int x,vector<int> &arr,int minmTillNow){
	int curr = 0;
	int n = arr.size();
	for(int i=0;i<n;i++){
		int add = abs(power(x,i) - arr[i]);
		curr += add;
		if(curr > minmTillNow){
			return curr;
		}
	}
	return curr;
}
void solveQuestion(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	sort(arr.begin(),arr.end());
	if(n >= 35){
		int ans = 0;
		for(int i=0;i<n;i++){
			ans += (arr[i] - 1);
		}
		cout<<ans<<"\n";
	}else{
		int ans = 1e12;
		for(int i=1;i<=100000;i++){
			int cd = check(i,arr,ans);
			if(cd >= ans){
				break;
			}else{
				ans = cd;
			}
		}
		cout<<ans<<"\n";
	}
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