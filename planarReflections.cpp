#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int MOD = 1e9+7;
int ans;
void modify(vector<int> &arr,int sz,int leftToRight){
	for(int x:arr){
		ans += x;
		ans %= MOD;
	}
	if(leftToRight){
		for(int i=1;i<sz;i++){
			arr[i] += arr[i-1];
			arr[i] %= MOD;
		}
	}else{
		for(int i=sz-2;i>=0;i--){
			arr[i] += arr[i+1];
			arr[i] %= MOD;
		}
	}
}
void solveQuestion(){
	int n,k;
	cin >> n >> k;
	//n -> num walls
	//k -> health
	if(k == 1){
		cout << 1 << '\n';
		return;
	}
	if(n == 1){
		cout << 2 << '\n';
		return;
	}
	if(k == 2){
		cout << (n + 1) << '\n';
		return;
	}
	ans = 2;
	n--;
	k--;
	//walls:= walls - 1 as one wall will be exit
	//k := k-1 as first ray exited
	vector<int> arr(n,1);
	int leftToRight = 0;
	while(k > 0){
		modify(arr,n,leftToRight);
		leftToRight ^= 1;
		k--;
	}
	cout << ans << '\n';
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