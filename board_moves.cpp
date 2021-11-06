#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		ll n;
		cin >> n;
		ll moves = 0;
		for(int i=1;i<=(n/2);i++){
			ll big_side = 2*i+1;
			ll small_side = 2*i-1;
			ll area = (big_side*big_side)-(small_side*small_side);
			moves+=(i*area);
		}
		cout<<moves<<endl;
	}
	return 0;
}