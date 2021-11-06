/*
2
6 2 3
1 3
1 2 3
5 1 2
0
3 3
*/
#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
int stopsReq(int jumpSize,vector<bool> &state,int n){
	int pos = 0,fills = 0;
	while(pos < n){
		pos += jumpSize;
		fills++;
		if(pos < n && !state[pos]){
			fills++;
		}
	}
	return fills;
}
void solveQuestion(){
	int n,m,k;
	cin >> n >> m >> k;
	set<int> closed;
	for(int i=0;i<m;i++){
		int x;
		cin >> x;
		closed.insert(x);
	}
	vector<int> cost(k+1);
	for(int i=1;i<=k;i++){
		cin >> cost[i];
	}
	if(closed.count(0)){
		if(n == 0){
			cout<<"0\n";
			return;
		}
		cout<<"-1\n";
		return;
	}
	vector<bool> fuels(n+1,true);
	for(int x:closed){
		fuels[x] = false;
	}
	int maxGap = 0,currGap = 0;	
	for(int i=1;i<=n;i++){
		if(!fuels[i] && fuels[i-1]){
			currGap = 1;
			maxGap = max(maxGap,currGap);
		}else if(!fuels[i] && !fuels[i-1]){
			currGap++;
			maxGap = max(maxGap,currGap);
		}else if(fuels[i]){
			currGap = 0;
		}
	}
	maxGap++;
	//cout<<"maxGap: "<<maxGap<<"\n";
	int ans = 1e12;
	for(int i=k;i>=maxGap;i--){
		int stops = stopsReq(k,fuels,n);
		ans = min(ans,stops*cost[i]);
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