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
		ll n,k;
		cin>>n>>k;
		ll sum_all = (n*(n+1))/2;
		ll num_mul = n/k;
		ll sum_mul_k = ((num_mul)*(num_mul+1)*k)/2;
		ll ans = sum_all - sum_mul_k;
		vector<ll> powers_of_k;
		ll temp = k;
		while(temp<=n){
			powers_of_k.push_back(temp);
			temp*=k;
		}
		int N = powers_of_k.size();
		for(int i=0;i<N;i++){
			ll term = powers_of_k[i];
			ll num_terms = n/term;
			ll add = (num_terms*(num_terms+1))/2;
			ll to_subtract_num = num_terms/k;
			ll sub = (to_subtract_num*(k+to_subtract_num*k))/2;
			ans+=add;
			ans-=sub;
		}
		cout<<ans<<"\n";
	}
	return 0;
}