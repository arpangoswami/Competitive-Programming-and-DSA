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
		int n = s.size();
		if(s.substr(n-2) == "po"){
			cout<<"FILIPINO"<<"\n";
		}else if(s.substr(n-4) == "desu" || s.substr(n-4) == "masu"){
			cout<<"JAPANESE"<<"\n";
		}else if(s.substr(n-5) == "mnida"){
			cout<<"KOREAN"<<"\n";
		}
	}
	return 0;
}