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
void solveQuestion(){
	int n;
	cin >> n;
	vi arr(n);
	int sum = 0;
	for(int &i:arr){
		cin >> i;
		sum += i;
	}
	sort(arr.begin(),arr.end());
	int q;
	cin >> q;
	while(q--){
		int power,atk;
		cin >> power >> atk;
		int ans = 5e18;
		int pos = upper_bound(arr.begin(),arr.end(),power) - arr.begin();
		if(pos < n){
			int justMore = arr[pos];
			int rest = sum - justMore;
			ans = min(ans,max(0LL,atk - rest));
		}
		pos--;
		if(pos >= 0){
			int justLess = arr[pos];
			int rest = sum - justLess;
			ans = min(ans,max(0LL,power - justLess) + max(0LL,atk - rest));
		}
		cout << ans << "\n";
	}
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