#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
#define ff first
#define ss second
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;
int power(int a, int b){int res=1;a=a%MOD;while(b>0){if(b&1){res=(res*a)%MOD;}a=(a*a)%MOD;b>>=1;}return res;}
int fermat_inv(int y){return power(y,MOD-2);}
int gcd(int a, int b){return (b==0)?a:gcd(b,a%b);}
bool pattern(vector<int> &arr,int i,int j,int k){
	return ((arr[i] >= arr[j] && arr[j] >= arr[k]) || (arr[i] <= arr[j] && arr[j] <= arr[k]));
}
void solveQuestion(){
	int n;
	cin >> n;
	vi arr(n);
	for(int &i:arr){
		cin >> i;
	}
	int ans = 1;
	if(n >= 2){
		ans += 2;
	}
	if(n >= 3){
		if(!pattern(arr,0,1,2)){
			ans += 3;
		}else{
			ans += 2;
		}
	}
	for(int i=3;i<n;i++){
		if(!pattern(arr,i-3,i-2,i) && !pattern(arr,i-2,i-1,i) && !pattern(arr,i-3,i-2,i-1) && !pattern(arr,i-3,i-1,i)){
			ans += 4;
		}else if(!pattern(arr,i-2,i-1,i)){
			ans += 3;
		}else{
			ans += 2;
		}
	}
	cout<<ans<<"\n";
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