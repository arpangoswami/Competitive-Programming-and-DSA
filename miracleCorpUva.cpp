#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int n,all;
vector<int> dp,neighbours,value;
int DP(int sum){
	if(value[sum] != all){
		return 0;
	}
	if(dp[sum] != -1){
		return dp[sum];
	}
	int ans = 0;
	for(int i=sum;i;i = (i-1)&sum){
		if(value[i] == all){
			ans = max(ans,1 + DP(sum - i));
		}
	}
	return dp[sum] = ans;
}
void solveQuestion(){
	neighbours.resize(n+1);
	dp.resize(all+1);
	value.resize(all+1);
	for(int i=0;i<n;i++){
		int nb;
		cin >> nb;
		neighbours[i] = 0;
		neighbours[i] |= (1 << i);
		for(int j=0;j<nb;j++){
			int x;
			cin >> x;
			neighbours[i] |= (1 << x);
		}
	}
	for(int i=0;i<=all;i++){
		value[i] = 0;
		dp[i] = -1;
		for(int j=0;j<n;j++){
			if((i >> j) & 1){
				value[i] |= neighbours[j];
			}
		}
	}
	cout<<DP(all)<<'\n';
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr);
	//pre();
	int t = 1;
	while(cin >> n){
		if(n == 0){
			break;
		}
		all = (1 << n) - 1;
		cout<<"Case "<<t<<": ";
		solveQuestion();
		t++;
	}
	return 0;
}