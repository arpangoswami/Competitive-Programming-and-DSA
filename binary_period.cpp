#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string change(string s){
	int n = s.size();
	string sol;
	int zero_cnt = 0,one_cnt = 0;
	for(int i=0;i<n;i++){
		if(s[i] == '0'){
			zero_cnt++;
		}else{
			one_cnt++;
		}
	}
	for(int i=0;i<(zero_cnt+one_cnt-1);i++){
		sol.push_back('1');
		sol.push_back('0');
	}
	sol.push_back('1');
	return sol;
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		string t;
		cin>>t;
		bool allSame = true;
		int minPeriod = 1;
		char c = t[0];
		for(int i=1;i<t.size();i++){
			if(t[i]!=c){
				allSame = false;
				minPeriod++;
			}
		}
		if(!allSame){
			string sol = change(t);
			cout<<sol<<"\n";
		}else
			cout<<t<<"\n";
	}
	return 0;
}