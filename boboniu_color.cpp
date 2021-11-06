#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
pii cnt(int r, int g, int b, int w) {
	int odd = 0,even = 0;
	if (r % 2 == 0) {
		even++;
	} else {
		odd++;
	}
	if (g % 2 == 0) {
		even++;
	} else {
		odd++;
	}
	if (b % 2 == 0) {
		even++;
	} else {
		odd++;
	}
	if (w % 2 == 0) {
		even++;
	} else {
		odd++;
	}
	return {even, odd};
}
int32_t main(int32_t argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin >> test;
	while (test--) {
		int r, b, g, w;
		cin >> r >> g >> b >> w;
		int sub = min({r, g, b});
		int even = 0, odd = 0;
		bool f = false;
		if (w % 2 == 0) {
			f = true;
		} 
		pii temp = cnt(r,g,b,w);
		if(temp.second <= 1 || temp.second == 4){
			cout<<"Yes"<<"\n";
		}
		if(temp.second == 2){
			cout<<"No"<<"\n";
		}else if(temp.second == 3){
			if(sub == 0){
				cout<<"No"<<"\n";
			}else{
				cout<<"Yes"<<"\n";
			}
		}
	}
	return 0;
}