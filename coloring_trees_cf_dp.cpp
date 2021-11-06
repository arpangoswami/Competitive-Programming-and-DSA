/*C. Coloring Trees
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
ZS the Coder and Chris the Baboon has arrived at Udayland! They walked in the park where n trees grow. They decided to be naughty and color the trees in the park. The trees are numbered with integers from 1 to n from left to right.

Initially, tree i has color ci. ZS the Coder and Chris the Baboon recognizes only m different colors, so 0 ≤ ci ≤ m, where ci = 0 means that tree i is uncolored.

ZS the Coder and Chris the Baboon decides to color only the uncolored trees, i.e. the trees with ci = 0. They can color each of them them in any of the m colors from 1 to m. Coloring the i-th tree with color j requires exactly pi, j litres of paint.

The two friends define the beauty of a coloring of the trees as the minimum number of contiguous groups (each group contains some subsegment of trees) you can split all the n trees into so that each group contains trees of the same color. For example, if the colors of the trees from left to right are 2, 1, 1, 1, 3, 2, 2, 3, 1, 3, the beauty of the coloring is 7, since we can partition the trees into 7 contiguous groups of the same color : {2}, {1, 1, 1}, {3}, {2, 2}, {3}, {1}, {3}.

ZS the Coder and Chris the Baboon wants to color all uncolored trees so that the beauty of the coloring is exactly k. They need your help to determine the minimum amount of paint (in litres) needed to finish the job.

Please note that the friends can't color the trees that are already colored.

Input
The first line contains three integers, n, m and k (1 ≤ k ≤ n ≤ 100, 1 ≤ m ≤ 100) — the number of trees, number of colors and beauty of the resulting coloring respectively.

The second line contains n integers c1, c2, ..., cn (0 ≤ ci ≤ m), the initial colors of the trees. ci equals to 0 if the tree number i is uncolored, otherwise the i-th tree has color ci.

Then n lines follow. Each of them contains m integers. The j-th number on the i-th of them line denotes pi, j (1 ≤ pi, j ≤ 109) — the amount of litres the friends need to color i-th tree with color j. pi, j's are specified even for the initially colored trees, but such trees still can't be colored.

Output
Print a single integer, the minimum amount of paint needed to color the trees. If there are no valid tree colorings of beauty k, print  - 1.

Examples
inputCopy
3 2 2
0 0 0
1 2
3 4
5 6
outputCopy
10
inputCopy
3 2 2
2 1 2
1 3
2 4
3 5
outputCopy
-1
inputCopy
3 2 2
2 0 0
1 3
2 4
3 5
outputCopy
5
inputCopy
3 2 3
2 1 2
1 3
2 4
3 5
outputCopy
0
Note
In the first sample case, coloring the trees with colors 2, 1, 1 minimizes the amount of paint used, which equals to 2 + 3 + 5 = 10. Note that 1, 1, 1 would not be valid because the beauty of such coloring equals to 1 ({1, 1, 1} is a way to group the trees into a single group of the same color).

In the second sample case, all the trees are colored, but the beauty of the coloring is 3, so there is no valid coloring, and the answer is  - 1.

In the last sample case, all the trees are colored and the beauty of the coloring matches k, so no paint is used and the answer is 0.*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const ll inf = 1e17;
ll dp[105][105][105];
ll paintKbeauty(ll n,ll m,ll k,vector<int>&colored,vector<vector<ll>> &cost,ll last){
	if(k < 0){
		return inf;
	}
	if(n == 0){
		if(k == 0){
			return 0;
		}
		return inf;
	}
	if(dp[n][k][last]!=-1){
		return dp[n][k][last];
	}
	if(colored[n-1]!=0){
		if(colored[n-1] == last){
			return dp[n][k][last] = paintKbeauty(n-1,m,k,colored,cost,last);
		}
		else
			return dp[n][k][last] = paintKbeauty(n-1,m,k-1,colored,cost,colored[n-1]);
	}
	ll ans = inf;
	for(int i=1;i<=m;i++){
		if(i!=last)
			ans = min(ans,cost[n-1][i-1] + paintKbeauty(n-1,m,k-1,colored,cost,i));
		else
			ans = min(ans,cost[n-1][i-1] + paintKbeauty(n-1,m,k,colored,cost,last));
	}
	return dp[n][k][last] = ans;
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	memset(dp,-1,sizeof(dp));
	int n,m,k;
	cin>>n>>m>>k;
	vector<int> colored(n);
	for(int i=0;i<n;i++){
		cin>>colored[i];
	} 
	vector<vector<ll>>paintRequired(n,vector<ll>(m));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>paintRequired[i][j];
		}
	}
	ll ans = paintKbeauty(n,m,k,colored,paintRequired,0);
	ans =  (ans == inf) ? -1 : ans;
	cout<<ans<<"\n";
	return 0;
}