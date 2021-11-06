#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
vector<char> key = {'\0','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
void mappedStrings(vector<string>&solution,string &s,int idx,int n,string t){
	if(idx == n){
		solution.push_back(t);
		return;
	}
	if(s[idx] == '0'){
		return;
	}
	if(idx<(n-1)){
		if(s[idx+1] == '0'){
			int digit1 = s[idx] - '0',digit2 = s[idx+1] - '0';
			int id = (digit1*10 + digit2);
			mappedStrings(solution,s,idx+2,n,t+key[id]);
		}
		else{
			int digit1 = s[idx] - '0',digit2 = s[idx+1] - '0';
			int id = (digit1*10 + digit2);
			if(id>26){
				mappedStrings(solution,s,idx+1,n,t+key[digit1]);
			}
			else{
				mappedStrings(solution,s,idx+1,n,t+key[digit1]);
				mappedStrings(solution,s,idx+2,n,t+key[id]);
			}
		}
	}
	else if(idx == (n-1)){
		int digit1 = s[idx] - '0';
		mappedStrings(solution,s,idx+1,n,t+key[digit1]);
	}
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	cin>>s;
	bool flag = true;
	if(s[0] == '0'){
		flag = false;
	}
	if(flag){
		for(int i=0;i<s.size()-1;i++){
			if(s[i] == s[i+1] && s[i] == 48){
				flag = false;
				break;
			}
		}
	}
	if(flag){
		for(int i=s.size()-1;i>0;i--){
			if(s[i] == '0' && (s[i-1]!='1' && s[i-1]!='2')){
				flag = false;
				break;
			}
		}
	}
	if(flag){
		string t = "";
		vector<string> solution;
		mappedStrings(solution,s,0,s.size(),t);
		sort(solution.begin(),solution.end());
		for(int i=0;i<solution.size();++i){
			cout<<solution[i]<<"\n";
		}
	}
	return 0;
}