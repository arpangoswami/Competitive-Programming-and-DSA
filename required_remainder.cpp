#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pr;
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		ll x,y,n;
		cin>>x>>y>>n;
		ll prod = (n/x)*x;
		ll ans = prod + y;
		if(ans > n){
			ans-=x;
		}
		cout<<ans<<'\n';
	}
	return 0;
}