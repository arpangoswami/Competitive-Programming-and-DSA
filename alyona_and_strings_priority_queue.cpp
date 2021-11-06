#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
ll power(ll a,ll b){
	if(b == 0){
		return 1;
	}
	ll smallAns = power(a,b/2);
	if(b&1){
		return smallAns*smallAns*a;
	}
	return smallAns*smallAns;
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	return 0;
}