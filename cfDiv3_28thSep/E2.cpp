#include <bits/stdc++.h>
#include <cstdlib>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
void solveQuestion(){
	int n;
	cin >> n;
	vi arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	deque<int> dq;
	dq.push_back(arr[0]);
	ordered_set oset;
	oset.insert(arr[0]);
	map<int,int> freq;
	freq[arr[0]]++;
	int ans = 0;
	for(int i=1;i<n;i++){
		int firstInc = oset.order_of_key(arr[i]);
		int lastInc = dq.size() - freq[arr[i]] - firstInc;
		if(firstInc < lastInc){
			dq.push_front(arr[i]);
			oset.insert(arr[i]);
		}else{
			dq.push_back(arr[i]);
			oset.insert(arr[i]);
		}
		freq[arr[i]]++;
		ans += min(firstInc,lastInc);
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