#include <bits/stdc++.h>
#define int long long
using namespace std;
void allPermutations(int idx,int n,string s,string cmp,vector<string> &st){
	if(idx == n){
		if(cmp.compare(s) > 0){
			st.push_back(s);
		}
		return;
	}
	for(int i=idx;i<n;i++){
		swap(s[i],s[idx]);
		allPermutations(idx+1,n,s,cmp,st);
		swap(s[i],s[idx]);
	}
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	cin >> s;
	int n = s.size();
	vector<string> st;
	allPermutations(0,n,s,s,st);
	//cout<<"yo"<<"\n";
	sort(st.begin(),st.end());
	for(string x:st){
		cout<<x<<"\n";
	}
	return 0;
}