#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
ll power(ll a, ll b) {
	if (b == 0) {
		return 1;
	}
	ll smallAns = power(a, b / 2);
	if (b & 1) {
		return smallAns * smallAns * a;
	}
	return smallAns * smallAns;
}
int main(int argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin >> test;
	while (test--) {
		int n;
		cin >> n;
		string a, b;
		cin >> a >> b;
		char lowestPossible = 'z';
		for (int x = 0; x < n; x++) {
			if (a[x] < lowestPossible) {
				lowestPossible = a[x];
			}
		}
		bool flag = true;
		for (int i = 0; i < n; i++) {
			if (b[i] < lowestPossible) {
				flag = false;
				break;
			}
			if (a[i] < b[i]) {
				flag = false;
				break;
			}
		}
		set<char, greater<int>> s1, s2;
		for (int i = 0; i < n; i++) {
			s1.insert(a[i]);
			s2.insert(b[i]);
		}
		for (char c : s2) {
			if (s1.count(c) == 0) {
				flag = false;
				break;
			}
		}
		if (!flag) {
			cout << -1 << endl;
		}else{
			int steps = 2;
			vector<int> temp1;
			for(int i=0;i<n;i++){
				if(a[i]>='b'){
					temp1.push_back(i);
				}
			}
			vector<int> temp2;
			for(int i=0;i<n;i++){
				if(b[i] == 'a'){
					temp2.push_back(i);
				}
			}
			cout<<steps<<endl;
			cout<<temp1.size()<<" ";
			for(int x:temp1){
				cout<<x<<" ";
			}	
			cout<<endl;
			cout<<temp2.size()<<" ";
			for(int x:temp2){
				cout<<x<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}