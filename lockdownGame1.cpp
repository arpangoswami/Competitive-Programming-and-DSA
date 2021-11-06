/*
Alice and Bob are bored in the lockdown and decide to come up with a game.
Bob proposes the following game.
Given N coins initially. Players alternate turns. Alice goes first.
In each turn, the player can remove

1 or 2 coins if N is divisible by 3
1 or 3 coins if N−1 is divisible by 3
1 or 2 or 3 coins if N−2 is divisible by 3
N refers to the number of coins and decreases each turn.
The player who cannot move loses the game.
Bob wants you to make sure the game favors him. Help him verify it.
Given N, find the player who wins if the game is played optimally.
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int recSolve(int n,vector<int> &dp){
	if(dp[n] != -1){
		return dp[n];
	}
	if(n == 0){
		return 0;
	}
	if(n % 3 == 0){
		if(!recSolve(n-1,dp)){
			return dp[n] = 1;
		}
		else if(!recSolve(n-2,dp)){
			return dp[n] = 1;
		}
	}else if(n % 3 == 1){
		if(!recSolve(n-1,dp)){
			return dp[n] = 1;
		}
		else if(n >= 4 && !recSolve(n-3,dp)){
			return dp[n] = 1;
		}
	}else{
		if(!recSolve(n-1,dp)){
			return dp[n] = 1;
		}
		else if(!recSolve(n-2,dp)){
			return dp[n] = 1;
		}
		else if(n >= 5 && !recSolve(n-3,dp)){
			return dp[n] = 1;
		}
	}
	return dp[n] = 0;
}
void solveQuestion(){
	int n;
	cin >> n;
	vector<int> dp(n+1,-1);
	dp[0] = 0;
	if(n % 3 == 0){
		if(!recSolve(n-1,dp)){
			cout<<"Alice"<<'\n';
			return;
		}
		else if(!recSolve(n-2,dp)){
			cout<<"Alice"<<'\n';
			return;
		}
	}else if(n % 3 == 1){
		if(!recSolve(n-1,dp)){
			cout<<"Alice"<<'\n';
			return;
		}
		else if(n >= 4 && !recSolve(n-3,dp)){
			cout<<"Alice"<<'\n';
			return;
		}
	}else{
		if(!recSolve(n-1,dp)){
			cout<<"Alice"<<'\n';
			return;
		}
		else if(!recSolve(n-2,dp)){
			cout<<"Alice"<<'\n';
			return;
		}else if(n >= 5 && !recSolve(n-3,dp)){
			cout<<"Alice"<<'\n';
			return;
		}
	}
	cout<<"Bob"<<'\n';
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}