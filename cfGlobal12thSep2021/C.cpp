#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
#define ff first
#define ss second
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpi;
typedef long double ld;
void solveQuestion(){
	int n;
	cin >> n;
	vector<string> inp(2);
	cin >> inp[0];
	cin >> inp[1];
	int ans = 0;
	vector<vector<int>> grid(2,vector<int>(n));
	for(int i=0;i<n;i++){
		grid[0][i] = inp[0][i] - '0';
		grid[1][i] = inp[1][i] - '0';
	}
	for(int i=0;i<n;){
		if((grid[0][i] + grid[1][i]) == 1){
			ans += 2;
			i++;
		}else if(i < (n-1) && (grid[0][i] + grid[1][i] == 0) && (grid[0][i+1] + grid[1][i+1] == 2)){
			ans += 2;
			i+=2;
		}else if(i < (n-1) && (grid[0][i] + grid[1][i] == 2) && (grid[0][i+1] + grid[1][i+1] == 0)){
			ans += 2;
			i+=2;
		}else if((grid[0][i] + grid[1][i] == 0)){
			ans++;
			i++;
		}else{
			i++;
		}
		//cout<<"ans: "<<ans<<" i: "<<i<<"\n";
	}
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