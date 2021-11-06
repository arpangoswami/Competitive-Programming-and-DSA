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
/*
1
5
5 1 5 1 5
RBRRB
*/
void solveQuestion(){
	int n;
	cin >> n;
	vi arr(n);
	for(int &x:arr){
		cin >> x;
	}
	string s;
	cin >> s;
	vi reds;
	vi blues;
	for(int i=0;i<n;i++){
		if(s[i] == 'R'){
			if(arr[i] > n){
				cout<<"NO\n";
				return;
			}
			reds.push_back(arr[i]);
		}
		else{
			if(arr[i] <= 0){
				cout<<"NO\n";
				return;
			}
			blues.push_back(arr[i]);
		}
	}
	vector<bool> visited(n+1);
	sort(reds.begin(),reds.end(),greater<int>());
	sort(blues.begin(),blues.end());
	int high = n,low = 1;
	for(int i=0;i<reds.size();i++){
		int minReach = max(reds[i],1LL);
		while(high > minReach && visited[high]){
			high--;
		}
		if(high >= minReach){
			visited[high] = true;
		}else{
			cout<<"NO\n";
			return;
		}
		high--;
	}
	for(int i=0;i<blues.size();i++){
		int maxReach = min(blues[i],n);
		while(low < maxReach && visited[low]){
			low++;
		}
		if(low <= maxReach){
			visited[low] = true;
		}else{
			cout<<"NO\n";
			return;
		}
		low++;
	}
	for(int i=1;i<=n;i++){
		if(!visited[i]){
			cout<<"NO\n";
			return;
		}
	}
	cout<<"YES\n";
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