#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
int findLength(string &s,int n,int k,char ch){
	int maxLen = 0,left = 0,right = 0,cnt = 0;
	while(right < n){
		if(s[right]!=ch){
			cnt++;
		}
		while(cnt > k){
			if(s[left]!=ch){
				cnt--;
			}
			left++;
		}
		maxLen = max(maxLen,right-left+1);
		right++;
	}
	return maxLen;
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int k;
	cin >> k;
	string s;
	cin >> s;
	int n;
	n = s.size();
	int maxLen = findLength(s,n,k,'a');
	maxLen = max(maxLen,findLength(s,n,k,'b'));
	cout << maxLen << "\n";
	return 0;
}