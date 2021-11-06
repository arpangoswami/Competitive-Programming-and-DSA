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
void solveQuestion(){
	int n,k,x;
	cin >> n >> k >> x;
	vi arr(n);
	for(int &i:arr){
		cin >> i;
	}
	sort(arr.begin(),arr.end());
	vector<int> spaces;
	for(int i=1;i<n;i++){
		if((arr[i] - arr[i-1]) > x){
			int num = (arr[i] - arr[i-1] + (x-1))/x - 1; 
			spaces.push_back(num);
		}
	}
	sort(spaces.begin(),spaces.end(),greater<int>());
	int N = spaces.size(),i = N-1;
	for(int i=N-1;i>=0 && k > 0;i--){
		if(k >= spaces[i]){
			k -= spaces[i];
			spaces.pop_back();
		}else{
			break;
		}
	}
	cout <<  (spaces.size() + 1);
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	int tt = 1;
	//cin >> tt;
	while(tt-- > 0){
		solveQuestion();
	}
	return 0;
}