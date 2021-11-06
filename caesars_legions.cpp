/*
https://codeforces.com/problemset/problem/118/D
D. Caesar's Legions
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Gaius Julius Caesar, a famous general, loved to line up his soldiers. Overall the army had n1 footmen and n2 horsemen. Caesar thought that an arrangement is not beautiful if somewhere in the line there are strictly more that k1 footmen standing successively one after another, or there are strictly more than k2 horsemen standing successively one after another. Find the number of beautiful arrangements of the soldiers.

Note that all n1 + n2 warriors should be present at each arrangement. All footmen are considered indistinguishable among themselves. Similarly, all horsemen are considered indistinguishable among themselves.

Input
The only line contains four space-separated integers n1, n2, k1, k2 (1 ≤ n1, n2 ≤ 100, 1 ≤ k1, k2 ≤ 10) which represent how many footmen and horsemen there are and the largest acceptable number of footmen and horsemen standing in succession, correspondingly.

Output
Print the number of beautiful arrangements of the army modulo 100000000 (108). That is, print the number of such ways to line up the soldiers, that no more than k1 footmen stand successively, and no more than k2 horsemen stand successively.

Examples
inputCopy
2 1 1 10
outputCopy
1
inputCopy
2 3 1 2
outputCopy
5
inputCopy
2 4 1 1
outputCopy
0
Note
Let's mark a footman as 1, and a horseman as 2.

In the first sample the only beautiful line-up is: 121

In the second sample 5 beautiful line-ups exist: 12122, 12212, 21212, 21221, 22121
*/

//0 represents footmen
//1 represents horsemen
//run represents if there's a consecutive sequence of "run" footmen/horsemen,
//at any stage if lastPicked == 1 we make sure run<=k1 
//else if lastPicked == 0 we make sure run<=k2


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const ll mod = 1e8;
int dp[101][101][11][2];
int arrangement(int n1,int n2,int k1,int k2,int run,int lastPicked){
	if(dp[n1][n2][run][lastPicked]!=-1){
		return dp[n1][n2][run][lastPicked];
	}
	if(n1 == 0 && n2 == 0){
		return dp[n1][n2][run][lastPicked] =1;
	}
	if(n1 == 0){
		if(lastPicked == 0){
			return dp[n1][n2][run][lastPicked] = arrangement(n1,n2-1,k1,k2,1,1);
		}else{
			if(run >= k2){
				return dp[n1][n2][run][lastPicked] = 0;
			}else{
				return dp[n1][n2][run][lastPicked] = arrangement(n1,n2-1,k1,k2,1+run,1);
			}
		}
	}
	if(n2 == 0){
		if(lastPicked == 1){
			return dp[n1][n2][run][lastPicked] = arrangement(n1-1,n2,k1,k2,1,0);
		}else{
			if(run>=k1){
				return dp[n1][n2][run][lastPicked] = 0;
			}else{
				return dp[n1][n2][run][lastPicked] = arrangement(n1-1,n2,k1,k2,1+run,0);
			}
		}
	}
	if(lastPicked == 0){
		if(run<k1){
			return dp[n1][n2][run][lastPicked] = (arrangement(n1-1,n2,k1,k2,run+1,0)%mod + arrangement(n1,n2-1,k1,k2,1,1)%mod)%mod;
		}else{
			return dp[n1][n2][run][lastPicked] = arrangement(n1,n2-1,k1,k2,1,1);
		}
	}
	else{
		if(run<k2){
			return dp[n1][n2][run][lastPicked] = (arrangement(n1-1,n2,k1,k2,1,0)%mod + arrangement(n1,n2-1,k1,k2,1+run,1)%mod);
		}
		else
			return dp[n1][n2][run][lastPicked] = arrangement(n1-1,n2,k1,k2,1,0);
	}
}	
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n1,n2,k1,k2;
	cin>>n1>>n2>>k1>>k2;
	memset(dp,-1,sizeof(dp));
	int ans1 = arrangement(n1-1,n2,k1,k2,1,0)%mod,ans2 = arrangement(n1,n2-1,k1,k2,1,1);
	cout<<(ans1%mod + ans2%mod)%mod<<endl;
	return 0;
}