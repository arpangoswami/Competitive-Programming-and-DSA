#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		string s;
		cin>>s;
		string ans;
		int n = s.size();
		int rock = 0,scissor = 0,paper = 0;
		for(int i=0;i<n;i++){
			if(s[i] == 'R'){
				rock++;
			}else if(s[i] == 'P'){
				paper++;
			}else{
				scissor++;
			}
		}
		char maxm = 'R';
		if(rock >= scissor && rock >= paper){
			maxm = 'P';
		}else if(paper >= rock && paper >= scissor){
			maxm = 'S';
		}else {
			maxm = 'R';
		}
		for(int i=0;i<n;i++){
			ans.push_back(maxm);
		}
		cout<<ans<<"\n";
	}
	return 0;
}