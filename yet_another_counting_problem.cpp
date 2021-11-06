#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		ll a,b;
		cin>>a>>b;
		ll q;
		cin>>q;
		if(a > b){
			swap(a,b);
		}
		ll lcm = (a*b)/__gcd(a,b);
		ll each_period = lcm - b;//consider a = 7,b = 10,left = 100,right = 200,lcm's multiples will cause equality.
		//Here LCM = 70 so we subtract (1,2...9)[9 elements],(70,71...79),(140,141,....149)[everything else 10 elements];
		//Hence each_period contributes LCM - max(a,b) elements
		while(q--){
			ll left,right;
			cin>>left>>right;
			// we will count total elements in 1....left-1 and subtract it from total elements of 1....right to get the answer
			ll x1 = ((left-1)/lcm) * each_period;
			ll excl1 = (left-1)%lcm;
			x1+=max(0LL,excl1-b+1);//subtract 1.....b-1
			ll x2 = ((right)/lcm) * each_period;
			ll excl2 = (right)%lcm;
			x2+=max(0LL,excl2-b+1);//subtract 1.....b-1
			cout<<(x2-x1)<<" ";
		}
		cout<<"\n";
	}
	return 0;
}