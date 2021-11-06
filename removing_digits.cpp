#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int removingDigits(int n,unordered_map<int,int> &mp){
	if(n<10){
		return mp[n] = 1;
	}
	if(mp.count(n)){
		return mp[n];
	}
	int ans = 1e9;
	int temp = n;
	while(temp>0){
		int dig = temp%10;
		if(dig!=0)
			ans = min(ans,1 + removingDigits(n - dig,mp));
		temp/=10;
	}
	return mp[n] = ans;
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	unordered_map<int,int> mp;
	int n;
	cin>>n;
	cout<<removingDigits(n,mp);
	return 0;
}