/*
Given a string s,
find the sum of f(x) where f(x) is defined on each substring as the difference of the character that appears
 the highest number of times and the character that appears the lowest number of times.
 |s| <= 3000;
*/
#include <bits/stdc++.h>
using namespace std;
int prefix[26][3001];
int lowestFreq(int i,int j){
	int ans = (j-i+1);
	for(int idx=0;idx<26;idx++){
		int sub = (i == 0) ? 0 : prefix[idx][i-1];
		int add = prefix[idx][j];
		if(add-sub > 0 && (add-sub) < ans){
			ans = (add-sub);
		}
	}
	return ans;
}
int highestFreq(int i,int j){
	int ans = 0;
	for(int idx=0;idx<26;idx++){
		int sub = (i == 0) ? 0 : prefix[idx][i-1];
		int add = prefix[idx][j];
		if((add-sub) > ans){
			ans = (add-sub);
		}
	}
	return ans;
}
int32_t main(int argc,char *argv[]){
	string s;
	cin >> s;
	int n = s.size();
	for(int i=0;i<26;i++){
		prefix[i][0] = 0;
	}
	int ans = 0;
	int row = s[0] - 'a';
	prefix[row][0]++;
	for(int i=1;i<n;i++){
		for(int j=0;j<26;j++){
			prefix[j][i] = prefix[j][i-1];
		}
		row = s[i] - 'a';
		prefix[row][i] = 1 + prefix[row][i-1];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			int l1 = lowestFreq(i,j);
			int l2 = highestFreq(i,j);
			ans += (l2-l1);
		}
	}
	cout<<ans<<"\n";
}
