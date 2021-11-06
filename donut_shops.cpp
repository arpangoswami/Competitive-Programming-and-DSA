#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pr;
int main(int argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin >> test;
	while (test--) {
		ll a, b, c;
		cin >> a >> b >> c;
		ll per_cost = c / b;
		if (b == 1) {
			if(a < c){
				cout<<1<<" "<<-1<<endl;
			}else if(c > a){
				cout<<-1<<" "<<1<<endl;
			}else{
				cout<<-1<<" "<<-1<<endl;
			}
		} else {
			if(a >= c){
				cout<<-1<<" "<<b<<endl;
			}else if(a < c && a > per_cost){
				cout<<1<<" "<<b<<endl;
			}else if(a < c && a <= per_cost){
				cout<<1<<" "<<-1<<endl;
			}
		}
	}
	return 0;
}