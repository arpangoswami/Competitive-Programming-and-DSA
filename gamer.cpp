#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int MOD = 998244353;
void solveQuestion(){
	int ans = 0;
	int n,k;
	cin >> n >> k;
	vector<array<int,3>> arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}
	if(n <= 20){
		int sub = (1LL << n);
		for(int i=1;i<sub;i++){
			int picked = i;
			int val = 0;
			int minm = 1e9+1,maxm = -(1e9+1);
			for(int j=0;j<n;j++){
				if((picked >> j) & 1){
					val += arr[j][2];
					maxm = max(maxm,arr[j][1]);
					minm = min(minm,arr[j][0]);
				}
			}
			ans = max(ans,val - k*(maxm - minm));
		}
		cout << ans << '\n';
	}else if(n <= 1000){
		for(int i=0;i<n;i++){
			int startTime = arr[i][0];
			for(int j=0;j<n;j++){
				int endTime = arr[j][1];
				
			}
		}
	}else{
		cout << 0 << '\n';
	}
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test = 1;
	//cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}