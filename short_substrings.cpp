#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pr;
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		string s;
		cin>>s;
		string a;
		a.push_back(s[0]);
		a.push_back(s[1]);
		for(int i=3;i<s.size();i+=2){
			a.push_back(s[i]);
		}
		cout<<a<<endl;
	}
	return 0;
}