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
int leftMost(int ear,int low,int high,int val,vector<int> &arr){
	if(ear + arr[high] < val){
		return -1;
	}
	int ans = high;
	while(low <= high){
		int mid = (low + high)/2;
		if(ear + arr[mid] >= val){
			ans = mid;
			high = mid-1;
		}else{
			low = mid+1;
		}
	}
	return ans;
}
int rightMost(int ear,int low,int high,int val,vector<int> &arr){
	if(ear + arr[low] > val){
		return -1;
	}
	int ans = low;
	while(low <= high){
		int mid = (low + high)/2;
		if(ear + arr[mid] <= val){
			ans = mid;
			low = mid+1;
		}else{
			high = mid-1;
		}
	}
	return ans;
}
void solveQuestion(){
	int n,l,r;
	cin >> n >> l >> r;
	vi arr(n);
	for(int &i:arr){
		cin >> i;
	}
	sort(arr.begin(),arr.end());
	int ans = 0;
	for(int i=0;i<(n-1);i++){
		if(arr[i] + arr[i+1] > r){
			break;
		}
		int lIdx = leftMost(arr[i],i+1,n-1,l,arr);
		if(lIdx == -1){
			continue;
		}
		int rIdx = rightMost(arr[i],lIdx,n-1,r,arr);
		if(rIdx == -1){
			continue;
		}
		ans += (rIdx - lIdx + 1);
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