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
	vector<pii> arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i].first >> arr[i].second;
	}
	int i=0,j=n-1;
	sort(arr.begin(),arr.end(),[](pii &p1,pii &p2){
		if(p1.second == p2.second){
			return p1.first > p2.first;
		}
		return p1.second < p2.second;
	});
	int cost = 0,picked = 0;
	while(i <= j){
		if(picked >= arr[i].second){
			cost += arr[i].first;
			picked += arr[i].first;
			i++;
		}else{
			int diff = min(arr[j].first,arr[i].second-picked);
			cost += 2*diff;
			picked += diff;
			if(diff == arr[j].first){
				j--;
			}else{
				arr[j].first -= diff;
			}
		}
	}
	cout<<cost<<"\n";
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