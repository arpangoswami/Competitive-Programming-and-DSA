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
bool check(int add,vector<int> arr1,vector<int> arr2,int sz){
	sz += add;
	for(int i=0;i<add;i++){
		arr1.push_back(100);
	}
	for(int i=0;i<add;i++){
		arr2.push_back(0);
	}
	sort(arr1.begin(),arr1.end());
	sort(arr2.begin(),arr2.end());
	int sIdx = sz/4;
	int s1 = 0,s2 = 0;
	for(int i=sIdx;i<sz;i++){
		s1 += arr1[i];
		s2 += arr2[i];
	}
	return s1 >= s2;
}
void solveQuestion(){
	int n;
	cin >> n;
	vi arr1(n);
	vi arr2(n);
	int s1 = 0,s2 = 0;
	for(int &i:arr1){
		cin >> i;
		s1 += i;
	}
	for(int &i:arr2){
		cin >> i;
		s2 += i;
	}
	int low = 0,high = 4*n,ans = high;
	while(low <= high){
		int mid = (low+high)/2;
		if(check(mid,arr1,arr2,n)){
			ans = mid;
			high = mid-1;
		}else{
			low = mid+1;
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