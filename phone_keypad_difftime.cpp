#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
vector<string> keyPad = {"","abc","def","ghi","jkl","mno","pqrs","tuv","wx","yz"};
void allPossibleCombinations(int idx,string s,int n,string tillNow,int &ct){
	if(idx == n){
		cout<<tillNow<<" ";
		ct++;
		return;
	}
	if(s[idx] == '0'){
		allPossibleCombinations(idx+1,s,n,tillNow,ct);
	}
	int key = s[idx] - '0';
	for(int i=0;i<keyPad[key].size();i++){
		allPossibleCombinations(idx+1,s,n,tillNow+keyPad[key][i],ct);
	}
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	cin>>s;
	int ct = 0;
	allPossibleCombinations(0,s,s.size(),"",ct);
	cout<<"\n";
	cout<<ct;
	return 0;
}