#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
#define ff first
#define ss second
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpi;
typedef long double ld;
const int INF = 1e12;
void solveQuestion(){
	int N,K;
	cin >> N >> K;
	vector<vi> grid(N,vi(N));
	vector<vi> coins(N,vi(N));
	vector<vvi> dp(N,vvi(N,vi(K+1,-INF)));

	for(int i=0;i<N;i++){
		string s;
		cin >> s;
		for(int j=0;j<N;j++){
			grid[i][j] = (s[j] == '.');
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin >> coins[i][j];
		}
	}
	dp[0][0][0] = coins[0][0];
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			
			for(int k=0;i > 0 && k <= K;k++){
				if(k > 0){
					dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k-1] + coins[i][j]);
				}
				if((k == 0 || k == K) && grid[i][j]){
					dp[i][j][k] = max(dp[i][j][k],dp[i-1][j][k] + coins[i][j]);
				}
			}

			for(int k=0;j > 0 && k<=K;k++){
				if(k > 0){
					dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k-1] + coins[i][j]);
				}
				if((k == 0 || k == K) && grid[i][j]){
					dp[i][j][k] = max(dp[i][j][k],dp[i][j-1][k] + coins[i][j]);
				}
			}
		}
	}
	int ans = -INF;
	ans = max(ans,*max_element(dp[N-1][N-1].begin(),dp[N-1][N-1].end()));
	if(ans < 0){
		cout<<"-1\n";
	}else{
		cout<<ans<<"\n";
	}
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