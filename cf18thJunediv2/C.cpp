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
	int n;
	cin >> n;
	vi arr(n);
	vi copy(n);
	for(int i=0;i<n;i++){
		cin >> arr[i];
		copy[i] = arr[i];
	}
	sort(copy.begin(),copy.end());
	int minDiff = 1e9,pick1=-1,pick2=-1;
	for(int i=1;i<n;i++){
		if(copy[i] - copy[i-1] < minDiff){
			minDiff = copy[i] - copy[i-1];
			pick1 = i;
			pick2 = i-1;
		}
	}
	vi sol(n);
	sol[0] = copy[pick2];
	sol[n-1] = copy[pick1];
	int idx = 1;
	for(int i=pick1+1;i<n;i++){
		sol[idx++] = copy[i];
	}
	for(int i=0;i<pick2;i++){
		sol[idx++] = copy[i];
	}
	for(int x:sol){
		cout<<x<<" ";
	}
	cout<<"\n";

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