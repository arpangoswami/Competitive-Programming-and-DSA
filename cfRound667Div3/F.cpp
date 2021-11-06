#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int dp[201][201][201];
int n,k;
string s;
char first,second;
int solve(int idx,int ops,int firstCharCount){
	if(idx >= n){
		return 0;
	}
	int &ans = dp[idx][ops][firstCharCount];
	if(ans != -1){
		return ans;
	}
	ans = 0;
	if(first == second){
		if(s[idx] == first){
			ans = max(ans,solve(idx+1,ops,firstCharCount+1)+firstCharCount);
		}else{
			ans = max(ans,solve(idx+1,ops,firstCharCount));
			if(ops < k){
				ans = max(ans,solve(idx+1,ops+1,firstCharCount+1)+firstCharCount);
			}
		}
		return ans;
	}
	//character stays same
	if(s[idx] == first){
		ans = max(ans,solve(idx+1,ops,firstCharCount+1));
	}else if(s[idx] == second){
		ans = max(ans,solve(idx+1,ops,firstCharCount) + firstCharCount);
	}else{
		ans = max(ans,solve(idx+1,ops,firstCharCount));
	}

	if(ops < k){
		//change to first
		if(s[idx] != first){
			ans = max(ans,solve(idx+1,ops+1,firstCharCount+1));
		}
		//change to second
		if(s[idx] != second){
			ans = max(ans,solve(idx+1,ops+1,firstCharCount) + firstCharCount);
		}
	}
	return ans;
}
void solveQuestion(){	
	cin >> n >> k;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			for(int k=0;k<=n;k++){
				dp[i][j][k] = -1;
			}
		}
	}
	cin >> s;
	string temp;
	cin >> temp;
	first = temp[0];
	second = temp[1];
	cout<<solve(0,0,0);
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	int tt = 1;
	//cin >> tt;
	while(tt-- > 0){
		solveQuestion();
	}
	return 0;
}