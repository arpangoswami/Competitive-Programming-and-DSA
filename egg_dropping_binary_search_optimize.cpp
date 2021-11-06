/*Egg Dropping Puzzle 
Suppose you have N eggs and you want to determine from which floor in a K-floor building you can drop an egg such that it doesn't break. You have to determine the minimum number of attempts you need in order find the critical floor in the worst case while using the best strategy.There are few rules given below. 

An egg that survives a fall can be used again.
A broken egg must be discarded.
The effect of a fall is the same for all eggs.
If the egg doesn't break at a certain floor, it will not break at any floor below.
If the eggs breaks at a certain floor, it will break at any floor above.
For more description on this problem see wiki page

Example 1:

Input:
N = 2, K = 10
Output: 4
Example 2:

Input:
N = 3, K = 5
Output: 3
Your Task:
Complete the function eggDrop() which takes two positive integer N and K as input parameters and returns the minimum number of attempts you need in order to find the critical floor.

Expected Time Complexity : O(N*K)
Expected Auxiliary Space: O(N*K)

Constraints:
1<=N<=10
1<=K<=50*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int solve(int K,int N,vector<vector<int>> &dp){
    if(N <= 1 || K == 1){
        return N;
    }
    if(dp[K][N]!=-1){
        return dp[K][N];
    }
    int &ans = dp[K][N];
    ans = N;
    int low = 1,high = N;
    while(low <= high){
        int mid = low + (high - low)/2;
        int left = solve(K-1,mid-1,dp);
        int right = solve(K,N-mid,dp);
        ans = min(ans,1 + max(left,right));
        if(left < right){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return ans;
}
void solveQuestion(){
	int floors,eggs;
	cin >> floors >> eggs;
	vector<vector<int>> dp(eggs+1,vector<int>(floors+1,-1));
	cout<<solve(eggs,floors,dp)<<"\n";
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}