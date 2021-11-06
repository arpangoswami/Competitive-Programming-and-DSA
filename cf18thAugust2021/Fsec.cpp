#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
#define ff first
#define ss second
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
bool recSolve(int idx,int N,const string &original,string &ans,int distinct,int k){
	if(distinct > k){
		return false;
	}
	if(idx > 0 && stol(original.substr(0,idx)) > stol(ans.substr(0,idx)) ){
		return false;
	}
	if(idx >= N){
		return true;
	}
	for(char c = '0';c <= '9';c++){
		ans.push_back(c);
		int found = 1;
		for(int j=0;j<idx;j++){
			if(ans[j] == c){
				found = 0;
				break;
			}
		}
		bool f = recSolve(idx+1,N,original,ans,distinct + found,k);
		if(f){
			return true;
		}
		ans.pop_back();
	}
	return false;
}
void solveQuestion(){
	int n,k;
	cin >> n >> k;
	string original = to_string(n);
	int N = original.size();
	string ans;
	recSolve(0,N,original,ans,0,k);
	cout << ans << "\n";
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	int tt = 1;
	cin >> tt;
	while(tt-- > 0){
		solveQuestion();
	}
	return 0;
}