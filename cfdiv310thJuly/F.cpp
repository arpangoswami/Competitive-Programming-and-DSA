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

//CODE TAKEN FROM https://www.prepbytes.com/blog/segment-tree-competitive-coding/maximum-divisor/ for segment TREE
int *st; 
int findGcd(int ss, int se, int qs, int qe, int si) 
{ 
	if (ss>qe || se < qs) 
		return 0; 
	if (qs<=ss && qe>=se) 
		return st[si]; 
	int mid = ss+(se-ss)/2; 
	return gcd(findGcd(ss, mid, qs, qe, si*2+1),findGcd(mid+1, se, qs, qe, si*2+2)); 
} 
int findRangeGcd(int ss, int se, int arr[],int n) 
{ 
	if (ss<0 || se > n-1 || ss>se) 
	{ 
		return -1; 
	} 
	return findGcd(0, n-1, ss, se, 0); 
} 
int constructST(int arr[], int ss, int se, int si) 
{ 
	if (ss==se) 
	{ 
		st[si] = arr[ss]; 
		return st[si]; 
	} 
	int mid = ss+(se-ss)/2; 
	st[si] = gcd(constructST(arr, ss, mid, si*2+1),constructST(arr, mid+1, se, si*2+2)); 
	return st[si]; 
} 
int *constructSegmentTree(int arr[], int n) 
{ 
	int height = (int)(ceil(log2(n))); 
	int size = 2*(int)pow(2, height)-1; 
	st = new int[size]; 
	constructST(arr, 0, n-1, 0); 
	return st; 
}
bool check(int ops,int arr[],int n){
	vi sol(n);
	for(int i=0;i<n;i++){
		int lastEl = (i+ops)%n;
		int g = 1;
		if(lastEl < i){
			g = gcd(findRangeGcd(i,n-1,arr,n),findRangeGcd(0,lastEl,arr,n));
		}else{
			g = findRangeGcd(i,lastEl,arr,n);
		}
		sol[i] = g;
	}
	for(int i=1;i<n;i++){
		if(sol[i] != sol[i-1]){
			return false;
		}
	}
	return true;
}
void solveQuestion(){
	int n;
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	constructSegmentTree(arr, n);
	int ans = n,low = 0,high = n-1;
	while(low <= high){
		int mid = (low+high)/2;
		if(check(mid,arr,n)){
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