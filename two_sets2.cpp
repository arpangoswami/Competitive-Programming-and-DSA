/*https://cses.fi/problemset/task/1093/
CSES Problem Set
Two Sets II
TASK SUBMIT RESULTS STATISTICS HACKING
Time limit: 1.00 s Memory limit: 512 MB
Your task is to count the number of ways numbers 1,2,…,n can be divided into two sets of equal sum.

For example, if n=7, there are four solutions:
{1,3,4,6} and {2,5,7}
{1,2,5,6} and {3,4,7}
{1,2,4,7} and {3,5,6}
{1,6,7} and {2,3,4,5}
Input

The only input line contains an integer n.

Output

Print the answer modulo 10^9+7.

Constraints
1≤n≤500
Example

Input:
7

Output:
4
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pr;
ll dp[255*255][501];
const ll mod = 1e9+7;
ll solve(ll sum,int pick,const int &req){
	if(sum > req || pick == 0){
		return 0;
	}
	if(sum == req){
		return 1;
	}
	if(dp[sum][pick]!=-1){
		return dp[sum][pick];
	}
	ll ans1 = solve(sum+pick,pick-1,req);
	ll ans2 = solve(sum,pick-1,req);
	return dp[sum][pick] = (ans1%mod + ans2%mod)%mod;
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	ll sum = (n*(n+1))/2;
	if(sum % 2 != 0){
		cout<<0<<endl;
	}else{
		memset(dp,-1,sizeof(dp));
		ll ans = solve(0,n,sum/2);
		cout<<ans<<endl;
	}
	return 0;
}