#include<bits/stdc++.h>
using namespace std;
void funkyPermute(string &s,int index,int n,set<string>&ans){
	if(index==n){
		ans.insert(s);
		return;
	}
	for(int i=index;i<n;i++){
		if(i==index || s[i]!=s[index]){
			swap(s[i],s[index]);
			funkyPermute(s,index+1,n,ans);
			swap(s[i],s[index]);
		}
	}
}
int main() {
	string s;
	set<string>ans;
	cin>>s;
	sort(s.begin(),s.end());
	funkyPermute(s,0,s.length(),ans);
	for(auto i =ans.begin();i!=ans.end();i++){
        cout<<*i<<endl;
	}
	return 0;
}
