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
	int n,q;
	cin >> n >> q;
	vi arr(n);
	for(int &i:arr){
		cin >> i;
	}
	sort(arr.begin(),arr.end());
	while(q--){
		int x,y; 
		cin >> x >> y;
		int idx1 = lower_bound(arr.begin(),arr.end(),x) - arr.begin();
		int idx2 = upper_bound(arr.begin(),arr.end(),y) - arr.begin();
		cout << (idx2 - idx1) << "\n";
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