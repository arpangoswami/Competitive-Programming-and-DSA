#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
bool check(unordered_map<char,int> &big,unordered_map<char,int> &small){
	for(auto it:small){
		if(it.second > big[it.first]){
			return false;
		}
	}
	return true;
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test = 1;
	//cin>>test;
	while(test--){
		string s,t;
		getline(cin, s);
		getline(cin, t);
		int n = t.size();
		unordered_map<char,int> small;
		for(int i=0;i<n;i++){
			small[t[i]]++;
		}
		unordered_map<char,int> big;
		n = s.size();
		int i = 0,j = 0;
		int minLeft = -1,minRight = -1,minLength = n+1;
		while(j < n){
			big[s[j]]++;
			while(check(big,small)){
				int length = j-i+1;
				if(length < minLength){
					minLeft = i;
					minRight = j;
					minLength = length;
				}
				big[s[i]]--;
				i++;
			}
			j++;
		}
		if(minLength == n+1){
			cout << "No String" << "\n";
		}else{
			cout << s.substr(minLeft,minLength) << "\n";
		}
	}
	return 0;
}