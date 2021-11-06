#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
#define ff first
#define ss second
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpi;
typedef long double ld;
string kEqual(int n,int k,vector<string> arr){
	if(k > n){
		return "No";
	}
	int len = arr[0].size();
	vector<vector<int>> letters(len,vector<int>(26,0));
	for(int i=0;i<len;i++){
		for(string s:arr){
			letters[i][s[i]-'a']++;
		}
	}
	int cnt = 0;
	for(int i=0;i<len;i++){
		int maxFreq = *max_element(letters[i].begin(),letters[i].end());
		if(maxFreq >= k){
			cnt++;
		}
	}
	return cnt == len ? "Yes" : "No";
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	int tt;
	cin >> tt;
	while(tt-- > 0){
		int n,k;
		cin >> n >> k;
		vector<string> arr(n);
		for(string &s:arr){
			cin >> s;
		}
		cout << kEqual(n,k,arr) << "\n";
	}
	return 0;
}