#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int n;
	cin>>n;
	vector<ll> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	unordered_map<ll,int> mp;
	for(int i=0;i<n;i++){
		if(arr[i]%10 == 0){
			mp[10]++;
		}else if(arr[i]%5 == 0){
			mp[5]++;
		}else if(arr[i]%2 == 0){
			mp[2]++;
		}else{
			mp[1]++;
		}
	}
	ll ans = 0;
	for(int i=0;i<n;i++){
		if(arr[i]%10 == 0){
			ans+=(mp[1] + mp[10] - 1 + mp[5] + mp[2]);
			mp[10]--;
		}else if(arr[i]%5 == 0){
			ans+=(mp[2] + mp[10]);
			mp[5]--;
		}else if(arr[i]%2 == 0){
			ans+=(mp[5] + mp[10]);
			mp[2]--;
		}else{
			ans+=(mp[10]);
			mp[1]--;
		}
	}
	cout<<ans<<"\n";
	return 0;
}