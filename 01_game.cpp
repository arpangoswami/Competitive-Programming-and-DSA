#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pr;
bool moveExist(string &s){
	int n = s.size();
	if(n<1){
		return false;
	}
	if(n == 2){
		if(s[0] == s[1]){
			return false;
		}else{
			s = "";
			return true;
		}
	}
	for(int i=0;i<(n-1);i++){
		if(s[i]!=s[i+1]){
			if(i!=0 && i!=n-2){
				string t = s.substr(0,i);
				string x = s.substr(i+2);
				s = t+x;
				return true;
			}else if(i == 0 && i!=n-2){
				string t = "";
				string x = s.substr(i+2);
				s = t+x;
				return true;
			}else if(i==n-2 && i!=0){
				string t = s.substr(0,i);
				string x = "";
				s = t+x;
				return true;
			}
		}
	}
	return false;
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		string s;
		cin>>s;
		int flag = 0;
		while(moveExist(s)){
			flag^=1;
		}
		if(flag){
			cout<<"DA"<<endl;
		}else{
			cout<<"NET"<<endl;
		}
	}
	return 0;
}