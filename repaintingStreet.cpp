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
int solve(vector<int> &arr,int n,int sz,int col){
	int days = 0;
	for(int i=0;i<n;){
		if(arr[i] == col){
			i++;
		}else{
			i += sz;
			days++;
		}
	}
	return days;
}
void solveQuestion(){
	int n,k;
	cin >> n >> k;
	vi arr(n);
	vector<bool> colors(101);
	for(int &i:arr){
		cin >> i;
		colors[i] = true;
	}
	int days = n;
	for(int i=1;i<=100;i++){
		if(!colors[i]){
			continue;
		}
		days = min(days,solve(arr,n,k,i));
	}
	cout<<days<<"\n";
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