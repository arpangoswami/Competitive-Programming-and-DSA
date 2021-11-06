/*O - Matching / 
Time Limit: 2 sec / Memory Limit: 1024 MB

Score : 
100
 points

Problem Statement
There are 
N
 men and 
N
 women, both numbered 
1
,
2
,
…
,
N
.

For each 
i
,
j
 (
1
≤
i
,
j
≤
N
), the compatibility of Man 
i
 and Woman 
j
 is given as an integer 
a
i
,
j
. If 
a
i
,
j
=
1
, Man 
i
 and Woman 
j
 are compatible; if 
a
i
,
j
=
0
, they are not.

Taro is trying to make 
N
 pairs, each consisting of a man and a woman who are compatible. Here, each man and each woman must belong to exactly one pair.

Find the number of ways in which Taro can make 
N
 pairs, modulo 
10
9
+
7
.

Constraints
All values in input are integers.
1
≤
N
≤
21
a
i
,
j
 is 
0
 or 
1
.
Input
Input is given from Standard Input in the following format:

N

a
1
,
1
 
…
 
a
1
,
N

:

a
N
,
1
 
…
 
a
N
,
N

Output
Print the number of ways in which Taro can make 
N
 pairs, modulo 
10
9
+
7
.

Sample Input 1 
Copy
3
0 1 1
1 0 1
1 1 1
Sample Output 1 
Copy
3
There are three ways to make pairs, as follows (
(
i
,
j
)
 denotes a pair of Man 
i
 and Woman 
j
):

(
1
,
2
)
,
(
2
,
1
)
,
(
3
,
3
)
(
1
,
2
)
,
(
2
,
3
)
,
(
3
,
1
)
(
1
,
3
)
,
(
2
,
1
)
,
(
3
,
2
)
Sample Input 2 
Copy
4
0 1 0 0
0 0 0 1
1 0 0 0
0 0 1 0
Sample Output 2 
Copy
1
There is one way to make pairs, as follows:

(
1
,
2
)
,
(
2
,
4
)
,
(
3
,
1
)
,
(
4
,
3
)
Sample Input 3 
Copy
1
0
Sample Output 3 
Copy
0
Sample Input 4 
Copy
21
0 0 0 0 0 0 0 1 1 0 1 1 1 1 0 0 0 1 0 0 1
1 1 1 0 0 1 0 0 0 1 0 0 0 0 1 1 1 0 1 1 0
0 0 1 1 1 1 0 1 1 0 0 1 0 0 1 1 0 0 0 1 1
0 1 1 0 1 1 0 1 0 1 0 0 1 0 0 0 0 0 1 1 0
1 1 0 0 1 0 1 0 0 1 1 1 1 0 0 0 0 0 0 0 0
0 1 1 0 1 1 1 0 1 1 1 0 0 0 1 1 1 1 0 0 1
0 1 0 0 0 1 0 1 0 0 0 1 1 1 0 0 1 1 0 1 0
0 0 0 0 1 1 0 0 1 1 0 0 0 0 0 1 1 1 1 1 1
0 0 1 0 0 1 0 0 1 0 1 1 0 0 1 0 1 0 1 1 1
0 0 0 0 1 1 0 0 1 1 1 0 0 0 0 1 1 0 0 0 1
0 1 1 0 1 1 0 0 1 1 0 0 0 1 1 1 1 0 1 1 0
0 0 1 0 0 1 1 1 1 0 1 1 0 1 1 1 0 0 0 0 1
0 1 1 0 0 1 1 1 1 0 0 0 1 0 1 1 0 1 0 1 1
1 1 1 1 1 0 0 0 0 1 0 0 1 1 0 1 1 1 0 0 1
0 0 0 1 1 0 1 1 1 1 0 0 0 0 0 0 1 1 1 1 1
1 0 1 1 0 1 0 1 0 0 1 0 0 1 1 0 1 0 1 1 0
0 0 1 1 0 0 1 1 0 0 1 1 0 0 1 1 1 1 0 0 1
0 0 0 1 0 0 1 1 0 1 0 1 0 1 1 0 0 1 1 0 1
0 0 0 0 1 1 1 0 1 0 1 1 1 0 1 1 0 0 1 1 0
1 1 0 1 1 0 0 1 1 0 1 1 0 1 1 1 1 1 0 1 0
1 0 0 1 1 0 1 1 1 1 1 0 1 0 1 1 0 0 0 0 0
Sample Output 4 
Copy
102515160
Be sure to print the number modulo 
10
9
+
7
.*/
#include <bits/stdc++.h>
#define int long long
const int mod = 1e9 + 7;
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int solve(vector<vector<int>> &compatibility,int n){
	int max_size = 1LL << n;
	vector<int> dp(max_size,0);
	dp[max_size-1] = 1;
	for(int mask=max_size-2;mask>=0;mask--){
		int setBits = __builtin_popcount(mask);
		for(int i=0;i<n;i++){
			if(compatibility[setBits][i] == 1 && ((mask >> i) & 1) == 0){
				dp[mask] += dp[(mask | (1<<i))];
				dp[mask] %= mod;
			}
		}
	}
	return dp[0];
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test = 1;
	cin>>test;
	while(test--){
		int n;
		cin >> n;
		vector<vector<int>> compatibility(n,vector<int>(n));
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin >> compatibility[i][j];
			}
		}
		if(n == 1){
			if(compatibility[0][0] == 0){
				cout << 0 <<"\n";
			}else{
				cout << 1 << "\n";
			}
			continue;
		}	
		int ans = solve(compatibility,n);
		cout << ans << "\n";
	}
	return 0;
}