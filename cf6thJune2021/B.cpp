#include <bits/stdc++.h>
#define int long long 
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
vector<string> ones,twos,threes;
void pre(){
	for(int i=0;i<26;i++){
		string s;
		s.push_back('a' + i);
		ones.push_back(s);
	}
	for(int i=0;i<26;i++){
		string s;
		s.push_back('a'+i);
		for(int j=0;j<26;j++){
			s.push_back('a'+j);
			twos.push_back(s);
			s.pop_back();
		}
	}
	for(int i=0;i<26 && threes.size() < 298;i++){
		string s;
		s.push_back('a'+i);
		for(int j=0;j<26 && threes.size() < 298;j++){
			s.push_back('a'+j);
			for(int k=0;k<26 && threes.size() < 298;k++){
				s.push_back('a'+k);
				threes.push_back(s);
				s.pop_back();
			}
			s.pop_back();
		}
	}
}
void solveQuestion(){
	int n;
	string s;
	cin >> n >> s;
	for(auto x:ones){
		if(s.find(x) == string::npos){
			cout<<x<<"\n";
			return;
		}
	}
	for(auto x:twos){
		if(s.find(x) == string::npos){
			cout<<x<<"\n";
			return;
		}
	}
	for(auto x:threes){
		if(s.find(x) == string::npos){
			cout<<x<<"\n";
			return;
		}
	}
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	pre();
	int tt;
	cin >> tt;
	while(tt-- > 0){
		solveQuestion();
	}
	return 0;
}