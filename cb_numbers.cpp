#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
unordered_set<int> st = {2,3,5,7,11,13,17,19,23,29};
bool isCBnum(int n){
	if(n == 0 || n == 1){
		return false;
	}
	if(st.count(n)){
		return true;
	}
	bool f = true;
	for(int x:st){
		if(n % x == 0){
			return false;
		}
	}
	return true;
}
int solve(string &s,int idx,int n){
	if(idx >= n){
		return 0;
	}
	int i;
	int ans1 = 0,ans2 = 0;
	for(i = idx;i<n;i++){
		int num = stoi(s.substr(idx,i-idx+1));
		if(isCBnum(num)){
			ans1 = max(ans1,1+solve(s,i+1,n));
			break;
		}
	}
	ans2 = solve(s,idx+1,n);
	return max(ans1,ans2);
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int max_num = solve(s,0,n);
	cout << max_num << "\n";
	return 0;
}