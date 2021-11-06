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
typedef array<int,5> ar;
bool isPossible(vector<ar> &arr,int n,int day1,int day2){
	vector<bool> picked(n,false);
	int cntFirst = 0,cntSecond = 0,cntBoth = 0;
	for(int i=0;i<n;i++){
		if(arr[i][day1] && arr[i][day2]){
			cntBoth++;
		}else if(arr[i][day1]){
			cntFirst++;
		}else if(arr[i][day2]){
			cntSecond++;
		}else{
			return false;
		}
	}
	return ((cntFirst + cntBoth) >= n/2 && (cntSecond + cntBoth) >= (n/2) && (cntFirst + cntSecond + cntBoth) == n);
}
void solveQuestion(){
	int n;
	cin >> n;
	vector<ar> arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3] >> arr[i][4];
	}
	for(int day1=0;day1<4;day1++){
		for(int day2=day1+1;day2<5;day2++){
			if(isPossible(arr,n,day1,day2)){
				cout<<"YES\n";
				return;
			}
		}
	}
	cout<<"NO\n";
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