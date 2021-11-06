#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int findParent(int x, vector<int> &parent) {
	if (x == parent[x]) {
		return x;
	}
	int p = findParent(parent[x], parent);
	parent[x] = p;
	return p;
}
void unionRank(int x, int y, vector<int> &parent, vector<int> &rank) {
	int x_rep = findParent(x, parent), y_rep = findParent(y, parent);
	if (x_rep == y_rep) {
		return;
	}
	if (rank[x_rep] < rank[y_rep]) {
		parent[x_rep] = y_rep;
	}
	else if (rank[x_rep] > rank[y_rep]) {
		parent[y_rep] = x_rep;
	}
	else {
		parent[x_rep] = y_rep;
		rank[y_rep]++;
	}
}
struct node {
	int a1, a2, val;
};
int main(int argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin >> test;
	while (test--) {
		int n, q;
		cin >> n >> q;
		vector<int> parent(n + 1);
		vector<int> rank(n + 1, 0);
		vector<node> temp(q);
		vector<node> queries(q);
		vector<int> color(n + 1);
		for (int i = 0; i <= n; ++i) {
			parent[i] = i;
			color[i] = 0;
		}
		int zero_cnt = 0;
		bool flag = true;
		for (int i = 0; i < q; i++) {
			cin >> temp[i].a1 >> temp[i].a2 >> temp[i].val;
			if (temp[i].val == 0) {
				zero_cnt++;
			}
		}
		// 0->grey, 1->white, 2->black
		int idx = 0;
		for (int i = 0; i < q; i++) {
			if (temp[i].val == 0) {
				queries[idx++] = temp[i];
			}
		}
		for (int i = 0; i < q; i++) {
			if (temp[i].val == 1) {
				queries[idx++] = temp[i];
			}
		}
		for (int i = 0; i < zero_cnt; i++) {
			unionRank(queries[i].a1, queries[i].a2, parent, rank);
		}
		for (int i = zero_cnt; i < q; i++) {
			int x_rep = findParent(queries[i].a1, parent), y_rep = findParent(queries[i].a2, parent), x = queries[i].a1, y = queries[i].a2;
			if (x_rep == y_rep) {
				flag = false;
				break;
			}
			if (color[x_rep] == 0 && color[y_rep] != 0) {
				if (color[y_rep] == 1)
					color[x_rep] = 2;
				else {
					color[x_rep] = 1;
				}
			}
			else if (color[y_rep] == 0 && color[x_rep] != 0) {
				if (color[x_rep] == 1)
					color[y_rep] = 2;
				else {
					color[y_rep] = 1;
				}
			}
			else if (color[x_rep] == 0 && color[y_rep] == 0) {
				color[x_rep] = 2;
				color[y_rep] = 1;
			}
			else if (color[x_rep] != 0 && color[y_rep] != 0) {
				if (color[x_rep] == color[y_rep]) {
					flag = false;
					break;
				}
			}
		}
		if (flag) {
			cout << "yes" << "\n";
		}
		else {
			cout << "no" << "\n";
		}
	}
	return 0;
}