#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pr;
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	cin>>s;
	int n = s.size();
	string toSearch = string(s[n-1]);
	int len = 1;
	for(int i=n-2;i>1;i--){
		if(s[i] == toSearch[0]){
			len++;
		}else{
			break;
		}
	}
	return 0;
}