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
bool isPalindrome(const string &x){
	int n = x.size();
	int left = 0,right = n-1;
	while(left < right){
		if(x[left] != x[right]){
			return false;
		}
		left++;
		right--;
	} 
	return true;
}
int toDelete(const string &s,char c){
	int n = s.size();
	string pal;
	vector<int> palInd;
	for(int i=0;i<n;i++){
		if(s[i] != c){
			pal.push_back(s[i]);
			palInd.push_back(i);
		}
	}
	vector<int> pref(n);
	pref[0] = (s[0] == c);
	for(int i=1;i<n;i++){
		pref[i] = pref[i-1] + (s[i] == c);
	}

	auto calSum = [&](int l,int r){
		if(l > r){
			return 0LL;
		}
		int sol = pref[r];
		if(l > 0){
			sol -= pref[l-1];
		}
		return sol;
	};
	if(!isPalindrome(pal)){
		return (n+1);
	}
	int N = pal.size();
	int palLen = N;
	int low,high; 
	if(N % 2 == 0){
		low = (N-2)/2,high = N/2;
		palLen += calSum(palInd[low]+1,palInd[high]-1);
	}else{
		low = (N/2)-1,high = (N/2)+1;
		palLen += 2*min(calSum(palInd[low]+1,palInd[N/2]-1),calSum(palInd[N/2]+1,palInd[high]-1));
	}
	//cout<<"palLen1: "<<palLen<<"\n";
	while(low > 0 && high < (N-1)){
		palLen += 2*min(calSum(palInd[low-1]+1,palInd[low]-1),calSum(palInd[high]+1,palInd[high+1]-1));
		low--;
		high++;
	}
	palLen += 2*min(calSum(0,palInd[low]-1),calSum(palInd[high]+1,n-1));
	//cout<<"c: "<<c<<"\n";
	//cout<<"palLen: "<<palLen<<"\n";
	return (n-palLen);
}
void solveQuestion(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	if(isPalindrome(s)){
		cout<<"0\n";
		return;
	}
	int ans = (n+1);
	for(char c='a';c <= 'z';c++){
		ans = min(ans,toDelete(s,c));
	}
	if(ans >= n){
		ans = -1;
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