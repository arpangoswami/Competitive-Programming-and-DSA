#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main(int argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin >> test;
	while (test--) {
		bool flag = true;
		unordered_set<int> s1;
		unordered_set<int> s2;
		int n, q;
		cin >> n >> q;
		for (int i = 0; i < q; i++) {
			int a1, a2, val;
			cin >> a1 >> a2 >> val;
			if (flag) {
				if (val == 0) {
					if ((s1.count(a1) == 0 && s1.count(a2) == 0)  && (s2.count(a1) == 0 && s2.count(a2) == 0)) {
						//cout<<"hello"<<"\n";
						s1.insert(a1);
						s1.insert(a2);
					}
					else if ((s1.count(a1) && s1.count(a2)) || (s2.count(a1) && s2.count(a2))) {
						continue;
					}
					else if ((s1.count(a1) && s2.count(a2)) || (s1.count(a2) && s2.count(a1))) {
						//cout<<"yoo"<<"\n";
						flag = false;
					}
					else if (s1.count(a1) && !s2.count(a2)) {
						//cout<<"hi"<<"\n";
						s1.insert(a2);
					}
					else if (s1.count(a2) && !s2.count(a1)) {
						s1.insert(a1);
					}
					else if (s2.count(a1) && !s1.count(a2)) {
						s2.insert(a2);
					}
					else if (s2.count(a2) && !s1.count(a1)) {
						s2.insert(a1);
					}
				}
				else {
					if ((s1.count(a1) == 0 && s2.count(a2) == 0) && (s1.count(a2) == 0 && s2.count(a1) == 0)) {
						s1.insert(a1);
						s2.insert(a2);
					}
					else if ((s1.count(a1) && s2.count(a2)) || (s1.count(a2) && s2.count(a1))) {
						continue;
					}
					else if ((s1.count(a1) && s1.count(a2)) || (s2.count(a1) && s2.count(a2))) {
						flag = false;
					}
					else if (s1.count(a1) && !s2.count(a2)) {
						//cout<<"yajur"<<endl;
						s2.insert(a2);
					}
					else if (s1.count(a2) && !s2.count(a1)) {
						s2.insert(a1);
					}
					else if (s2.count(a1) && !s1.count(a2)) {
						s1.insert(a2);
					}
					else if (s2.count(a2) && !s1.count(a1)) {
						s1.insert(a1);
					}
				}
			}
		}
		// for(int x: s1){
		// 	cout<<x<<" ";
		// }
		// cout<<endl;
		// for(int x: s2){
		// 	cout<<x<<" ";
		// }
		// cout<<endl;
		if (flag) {
			cout << "yes" << "\n";
		}
		else {
			cout << "no" << "\n";
		}
	}
	return 0;
}