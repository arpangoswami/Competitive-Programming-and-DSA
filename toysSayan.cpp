/*
6 10
aabcda
5 4 4 5 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
*/
#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
int windowCost(vector<int> &freq,vector<int> &costs){
	int ans = 0,maxCost = 0;
	for(int i=0;i<26;i++){
		ans += (freq[i]*costs[i]);
		maxCost = max(maxCost,freq[i]*costs[i]);
	}
	return (ans - maxCost);
}
bool check(int windowSize,string &s,int n,vector<int> &costs,int money){
	vector<int> freq(26);
	for(int i=0;i<windowSize;i++){
		freq[s[i]-'a']++;
	}
	for(int i=windowSize;i<n;i++){
		if(windowCost(freq,costs) <= money){
			return true;
		}
		freq[s[i]-'a']++;
		freq[s[i-windowSize]]--;
	}
	if(windowCost(freq,costs) <= money){
		return true;
	}
	return false;
}
void solveQuestion(){
	int n,money;
	cin >> n >> money;
	string s;
	cin >> s;
	vector<int> costs(26);
	for(int i=0;i<26;i++){
		cin >> costs[i];
	}
	int low = 0,high = n,ans = 0;
	while(low <= high){
		int mid = (low + high)/2;
		if(check(mid,s,n,costs,money)){
			ans = mid;
			low = mid+1;
		}else{
			high = mid-1;
		}
	}
	cout << ans << "\n";
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	int tt = 1;
	//cin >> tt;
	while(tt-- > 0){
		solveQuestion();
	}
	return 0;
}