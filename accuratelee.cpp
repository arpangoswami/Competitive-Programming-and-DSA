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
		int n;
		cin>>n;
		string s;
		cin>>s;
		string a;
		string b;
		for(int i=0;i<n && s[i] == '0';i++){
			a.push_back(s[i]);
		}
		for(int i=n-1;i>=0 && s[i] == '1';i--){
			b.push_back(s[i]);
		}
		string c = "0";
		if(a.size() + b.size() == n){
			cout<<a+b<<endl;
		}else{
			cout<<a + c + b<<endl;
		}
	}
	return 0;
}