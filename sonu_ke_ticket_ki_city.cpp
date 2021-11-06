#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int diff(string s,string t){
	int len = s.size();
	int cnt = 0;
	for(int i=0;i<len;i++){
		if(s[i]!=t[i]){
			cnt++;
		}
	}
	return cnt;
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<string> allPossible = {"HBN","HNB","BHN","BNH","NHB","NBH"};
	int len = allPossible.size();
	int minChange = n;
	int i;
	for(int k=0;k<len;k++){
		int change = 0;
		for(i=0;i<=n-3;i+=3){
			change += diff(s.substr(i,3),allPossible[k]);
		}
		change += diff(s.substr(i),allPossible[k]);
		minChange = min(minChange,change);
	}
	cout << minChange << "\n";
	return 0;
}