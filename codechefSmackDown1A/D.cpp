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
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;
int power(int a, int b){int res=1;a=a%MOD;while(b>0){if(b&1){res=(res*a)%MOD;}a=(a*a)%MOD;b>>=1;}return res;}
int fermat_inv(int y){return power(y,MOD-2);}
int gcd(int a, int b){return (b==0)?a:gcd(b,a%b);}
void solveQuestion(){
	int n;
	cin >> n;
	int lAns = 0,rAns = 0;
	vi arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	sort(arr.begin(),arr.end());
	if(n == 2){
		cout<<0<<"\n";
		return;
	}
	if(n == 3){
		cout << min(arr[1] - arr[0],arr[2] - arr[1]) << "\n";
		return;
	}
	for(int i=0;i<(n-1);i++){
		int last = (n-1)/2LL;
		lAns += abs(arr[i] - arr[last]);
	}
	for(int i=1;i<n;i++){
		int last = 1 + ((n-1)/2LL);
		rAns += abs(arr[i] - arr[last]);
	}
	int sol = min(lAns,rAns);
	int left = 1,right = n-2;
	while(left < right){
		int leftPart = arr[n-1] - arr[left];
		int rightPart = arr[right] - arr[0];
		sol = min(sol,abs(leftPart - rightPart));
		if(leftPart > rightPart){
			left++;
		}else{
			right--;
		}
	}
	cout << sol << "\n";
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