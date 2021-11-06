#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,k;
	cin >> n >> k;
	int rem = n % (k+1);
	int ans = (rem == 0) ? -1 : rem;
	cout << ans <<"\n"; 
	return 0;
}